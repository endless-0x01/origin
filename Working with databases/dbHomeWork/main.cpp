#include <iostream>
#include <string>
#include <pqxx/pqxx>

int main()
{	
	try {
		pqxx::connection test_db(
			"host=localhost "
			"port=5432 "
			"dbname=Lesson5 "
			"user=postgres "
			"password=270897 ");

		pqxx::work tx{ test_db };
		for (auto [name_c, surname_c] : tx.query<std::string, std::string>("SELECT name_c, surname_c FROM clients"))
		{
			std::cout << name_c << " " << surname_c << std::endl;
		}
	}
	catch (pqxx::sql_error& e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}