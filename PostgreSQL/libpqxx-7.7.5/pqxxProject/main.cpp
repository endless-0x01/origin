#include <iostream>
#include <pqxx/pqxx>
#include <exception>

class ClientDataBase
{
private:
	pqxx::connection conn;

	bool checkClientId(const int id) {
		pqxx::nontransaction thx(conn);
		pqxx::result r = thx.exec_params("SELECT ClientId FROM Clients WHERE ClientId = $1", id);
		return !r.empty();
	}

public:
	ClientDataBase(const std::string options) :conn{ options }
	{
		if (conn.is_open()) {
			std::cout << "Вы успешно подключились к базе данных!" << std::endl;
		}
		else
		{
			throw std::runtime_error("Ошибка подключения к базе данных.");
		}
	}

	void exec(const std::string_view& sql)
	{
		pqxx::work txn(conn);
		txn.exec(sql);
		txn.commit();
	}
	void createTable()
	{
		exec("CREATE TABLE IF NOT EXISTS Clients("
			"ClientId SERIAL PRIMARY KEY,"
			"FirstName TEXT,"
			"SureName TEXT,"
			"email TEXT )");

		exec("CREATE TABLE IF NOT EXISTS Phones("
			"PhoneID SERIAL PRIMARY KEY,"
			"PhoneNumber TEXT NOT NULL,"
			"ClientId INTEGER REFERENCES Clients(ClientId) )"
		);
	}

	void addNewClients(const std::string& f_name, const std::string& s_name,
		const std::string& email)
	{
		pqxx::work txn(conn);
		txn.exec_params(
			"INSERT INTO Clients(FirstName, SureName, email) VALUES ($1, $2, $3)",
			f_name, s_name, email);
		txn.commit();
	}
	void addNumberPhone()
	{
		int id_client;
		std::cout << "Введите ID клиента: ";
		if (std::cin >> id_client && checkClientId(id_client)) {
			std::string phone;
			std::cout << "Введите номер телефона: ";
			std::cin >> phone;
			pqxx::work txn(conn);
			txn.exec_params(
				"INSERT INTO Phones(PhoneNumber, ClientId) VALUES($1, $2)",
				phone, id_client);
			txn.commit();
		}
		else {
			std::cerr << "Пользователя с таким идентификатором нет, попробуйте другой." << std::endl;
		}
	}

	void updateClient(const std::string& name, const std::string& surname, const std::string& email) {
		int id_client;
		std::cout << "Введите ID клиента: ";
		if (std::cin >> id_client && checkClientId(id_client)) {
			pqxx::work txn(conn);
			txn.exec_params(
				"UPDATE Clients SET FirstName = $1, SureName = $2, "
				"email = $3 WHERE ClientId = $4",
				name, surname, email, id_client);
			txn.commit();
		}
		else
		{
			std::cout << "Пользователя с таким id не сущетсвует" << std::endl;
		}
	}

	void removePhone() {

		int id_client;
		std::cout << "Введите ID клиента: ";
		if (std::cin >> id_client && checkClientId(id_client)) {
			std::string phone;
			std::cout << "Введите номер телефона: ";
			std::cin >> phone;
			pqxx::work txn(conn);
			txn.exec_params(
				"DELETE FROM Phones WHERE PhoneNumber = $1 AND ClientId = $2",
				phone, id_client);
			txn.commit();
		}
		else
		{
			std::cout << "Пользователя с таким id не сущетсвует" << std::endl;
		}
	}

	void removeClient() {
		int id_client;
		std::cout << "Введите ID клиента: ";
		if (std::cin >> id_client && checkClientId(id_client)) {
			pqxx::work txn(conn);
			txn.exec_params(
				"DELETE FROM Clients WHERE ClientId = $1",
				id_client);
			txn.exec_params(
				"DELETE FROM Phones WHERE ClientId = $1",
				id_client);
			txn.commit();
		}
		else {
			std::cerr << "Пользователя с таким идентификатором нет, попробуйте другой." << std::endl;
		}
	}

	void findClient() {
		std::string searchQuery;
		std::cout << "Введите имя, фамилию, email или номер телефона клиента: ";
		std::getline(std::cin, searchQuery);
		pqxx::nontransaction txn(conn);
		pqxx::result r = txn.exec_params(
			"SELECT * FROM Clients "
			"LEFT JOIN Phones ON Clients.ClientId = Phones.ClientId "
			"WHERE FirstName = $1 OR SureName = $1 OR email = $1 OR PhoneNumber = $1",
			searchQuery);

		for (auto& row : r) {
			std::cout << "ClientId: " << row[0].as<int>() << ", FirstName: " << row[1].c_str() << ", SureName: " << row[2].c_str() << ", Email: " << row[3].c_str() << ", Phone: " << row[5].c_str() << std::endl;
		}
	}
};

void infoForUser()
{
	std::cout << "Выберите действие: " << std::endl;
	std::cout << "1 - Создать таблицы данных\n";
	std::cout << "2 - Добавить новых клиентов\n";
	std::cout << "3 - Добавить номер телефона клиента\n";
	std::cout << "4 - Изменить данные клиента\n";
	std::cout << "5 - Удалить номер клиента\n";
	std::cout << "6 - Удалить клиента\n";
	std::cout << "7 - Найти клиента по его данным (имени, фамилии, email-у или телефону)\n";
	std::cout << "8 - Выйти и закрыть соединение с базой данных\n";
}


void fillingDataClient(const std::string_view& info, std::string& data) {
	std::cout << "Введите " << info << " клиента: ";
	std::getline(std::cin, data);
}

void getDataClient(std::string& name, std::string& surname, std::string& mail)
{
	fillingDataClient("Имя", name);
	fillingDataClient("Фамилию", surname);
	fillingDataClient("Почту", mail);
}

void workWithBd(ClientDataBase& db)
{
	while (true)
	{
		infoForUser();
		std::cout << "Ваш выбор: ";
		int u_choise{};
		std::cin >> u_choise;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

		switch (u_choise)
		{
		case 1:
			db.createTable();
			break;
		case 2: {
			std::string name, surname, mail;
			getDataClient(name, surname, mail);
			db.addNewClients(name, surname, mail);
			break;
		}
		case 3:
			db.addNumberPhone();
			break;
		case 4: {
			std::string name, surname, mail;
			getDataClient(name, surname, mail);
			db.updateClient(name, surname, mail);
			break;
		}
		case 5:
			db.removePhone();
			break;
		case 6:
			db.removeClient();
			break;
		case 7:
			db.findClient();
			break;
		case 8:
			return;
		default:
			std::cout << "Такого варианта нет" << std::endl;
			break;
		}

		system("cls");
	}
}

int main()
{
	setlocale(LC_ALL, "Ru");
	try
	{
		ClientDataBase db{ "host=localhost port=5432 dbname=my_database user=postgres password=admin" };
		workWithBd(db);

	}
	catch (pqxx::sql_error& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
