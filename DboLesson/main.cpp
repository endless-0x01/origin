#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include <vector>
#include <iostream>

class Publisher;
class Book;
class Stock;
class Shop;
class Sale;

typedef Wt::Dbo::collection<Wt::Dbo::ptr<Book>> Books;
typedef Wt::Dbo::collection<Wt::Dbo::ptr<Stock>>Stocks;
typedef Wt::Dbo::collection<Wt::Dbo::ptr<Shop>> Shops;
typedef Wt::Dbo::collection<Wt::Dbo::ptr<Sale>> Sales;


class Publisher
{
public:
	std::string name;
	Books books;

	template<class Action>
	void persist(Action& a)
	{
		Wt::Dbo::field(a, name, "name");
		Wt::Dbo::hasMany(a, books, Wt::Dbo::ManyToOne, "publisher");
	}

};

class Book
{
public:
	std::string tittle;
	Wt::Dbo::ptr<Publisher> publisher;
	Stocks stocks;

	template<class Action>
	void persist(Action& a)
	{
		Wt::Dbo::field(a, tittle, "tittle");
		Wt::Dbo::belongsTo(a, publisher, "publisher");
		Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "book");
	}
};

class Stock
{
public:
	int count;
	Wt::Dbo::ptr<Book> book;
	Wt::Dbo::ptr<Shop> shop;

	template<class Action>
	void persist(Action& a)
	{
		Wt::Dbo::field(a, count, "count");
		Wt::Dbo::belongsTo(a, book, "book");
		Wt::Dbo::belongsTo(a, shop, "stock");
	}
};

class Shop
{
public:
	std::string name;
	Stocks stocks;

	template<class Atcion>
	void persist(Atcion& a)
	{
		Wt::Dbo::field(a, name, "name");
		Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "stock");
	}
};

class Sale {
public:
	int quantity;
	Wt::Dbo::ptr<Book> book;
	Wt::Dbo::ptr<Shop> shop;

	template<class Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, quantity, "quantity");
		Wt::Dbo::belongsTo(a, book, "book");
		Wt::Dbo::belongsTo(a, shop, "shop");
	}
};

std::vector<std::string> getBooks()
{
	std::vector<std::string> names_books = {
		"Alice in Wonderland",
		"The Lord of the Rings",
		"The Hobbits",
		"The Translator",
		"Harry Potter and the Philosopher's Stone",
		"1984",
		"Murder on the Orient Express",
		"The Master and Margarita",
		"Crime and Punishment",
		"The Quiet Don",
		"War and Peace",
		"Anna Karenina",
		"Woe from Wit",
		"The Catcher in the Rye",
		"Three Comrades"
	};

	return names_books;
}

int main()
{
	setlocale(LC_ALL, "Ru");
	try
	{
		std::string connectionString = {
				"host=localhost "
				"port=5432 "
				"dbname=dboDataBase "
				"user=postgres "
				"password=admin"
		};

		auto postgres = std::make_unique<Wt::Dbo::backend::Postgres>(connectionString);
		Wt::Dbo::Session session;
		session.setConnection(std::move(postgres));

		//Классы
		session.mapClass<Publisher>("publisher");
		session.mapClass<Book>("book");
		session.mapClass<Stock>("stock");
		session.mapClass<Shop>("shop");
		session.mapClass<Sale>("sale");

		try {
			session.createTables();
		}
		catch (Wt::Dbo::Exception& e) {
			std::cerr << "Tables already exist, continuing..." << std::endl;
		}

		try {
			//издатель 
			Wt::Dbo::Transaction transaction(session);

			std::vector<std::string> names_publisher = { "HelloWorl", "WorldBooks", "CountryFantasy" };
			std::vector<Wt::Dbo::ptr<Publisher>> publisherPtr;

			for (auto& name_publisher : names_publisher)
			{
				std::unique_ptr<Publisher> publisher{new Publisher};
				publisher->name = name_publisher;
				publisherPtr.push_back(session.add(std::move(publisher)));
			}

			// Книги
			std::vector<Wt::Dbo::ptr<Book>> booksPtr;

			for (auto& name : getBooks())
			{
				std::unique_ptr<Book> book{new Book()};
				book->tittle = name;
				book->publisher = publisherPtr[rand() % publisherPtr.size()];
				booksPtr.push_back(session.add(std::move(book)));
			}

			//магазины
			std::vector<std::string> name_shops = { "WeThere", "LoveBooks", "AmazonBooks", "Ozon" };
			std::vector<Wt::Dbo::ptr<Shop>> shopsPtr;
			for (auto& name : name_shops)
			{
				std::unique_ptr<Shop> shop {new Shop};
				shop->name = name;
				shopsPtr.push_back(session.add(std::move(shop)));
			}


			//кол-во книг для каждого магазина
			for (auto& shop : shopsPtr)
			{
				auto books = session.find<Book>().resultList();
				for (auto& book : books)
				{
					Wt::Dbo::ptr<Stock> stock = session.add(std::make_unique<Stock>());
					stock.modify()->count = rand() % 100;
					stock.modify()->shop = shop;
					stock.modify()->book = book;
				}
			}


			//Продажи
			for (auto& shop : shopsPtr) {
				auto books = session.find<Book>().resultList();
				for (auto& book : books) {
					Wt::Dbo::ptr<Sale> sale = session.add(std::make_unique<Sale>());
					sale.modify()->quantity = rand() % 100;
					sale.modify()->book = book;
					sale.modify()->shop = shop;
				}
			}

			transaction.commit();

		}
		catch (Wt::Dbo::Exception& e){
			std::cerr << e.what() << std::endl;
		}

		std::string inputPublisher;
		std::cout << "Enter publisher name: ";
		std::cin >> inputPublisher;

		try {
			Wt::Dbo::Transaction transaction(session);

			auto publishers = session.find<Publisher>().where("name = ?").bind(inputPublisher).resultList();

			if (publishers.empty()) {
				std::cout << "Издатель не найден." << std::endl;
				return 0;
			}

			std::set<Wt::Dbo::ptr<Shop>> uniqueShops;

			for (auto& publisher : publishers) {
				auto books = publisher->books;

				for (auto& book : books) {
					auto stocks = book->stocks;

					for (auto& stock : stocks) {
						uniqueShops.insert(stock->shop);
					}
				}
			}

			std::cout << "Магазины которые продают книги издателя: " << inputPublisher << " are:\n";

			for (auto& shop : uniqueShops) {
				std::cout << shop->name << std::endl;
			}

			transaction.commit();
		}
		catch (Wt::Dbo::Exception& e) {
			std::cerr << e.what() << std::endl;
		}



	}
	catch (Wt::Dbo::Exception& e)
	{
		std::cerr << e.what() << std::endl;
	}



	return 0;
}