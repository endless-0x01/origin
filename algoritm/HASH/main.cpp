#include <iostream>
#include <string>

void simple_string_hash()
{

	std::string str;

	while (true) {
		int hash{};
		std::cout << "Введите строку: ";
		std::cin >> str;
		for (int i = 0; i < str.size(); i++)
		{
			hash += str[i];
		}
		std::cout << "Наивный хэш строки " << str << " = " << hash << std::endl;
		if (str == "exit")
			return;
	}
}

int my_sqrt(int num, const int degree)
{
	int result = num;
	if (degree == 0)
		return 1;
	else if (degree == 1)
		return num;


	for (int i = 0; i < degree - 1; i++) {
		result = result * num;
	}
	return result;
}

void real_string_hash()
{

	int p{};
	std::cout << "Введите P: ";
	std::cin >> p;

	int n{};
	std::cout << "Введите N: ";
	std::cin >> n;


	while (true) {

		int hash{};

		std::string str;
		std::cout << "Введите строку: ";
		std::cin >> str;

		for (int i = 0; i < str.size(); i++)
		{
			hash = hash + my_sqrt(p, i) * str[i];
		}

		std::cout << "Хэш строки " << str << " = " << hash % n << std::endl;

		if (str == "exit")
			return;
	}

}


void find_substring_light_rabin_karp()
{
	std::cout << "Введите строку, в которой будет осуществляться поиск: ";
	std::string search_line;
	std::cin >> search_line;


	int index_s{};
	bool find_substr{};
	while (true)
	{
		std::cout << "Введите подстроку, которую нужно найти: ";
		std::string substring;
		std::cin >> substring;

		for (int i = 0; i < search_line.size(); i++)
		{
				find_substr = true;
				for (int j = 0; j < substring.size(); j++)
				{
					if (search_line[i + j] != substring[j]) {
						find_substr = false;
						break;
					}
				}

			if (find_substr) {
				index_s = i;
				break;
			}
		}

		find_substr ? std::cout << "Подстрока " << substring << " найдена по индексу: " << index_s << std::endl :
			std::cout << "Подстрока " << substring << " не найдена" << std::endl;

		if (substring == "exit")
			return;

	}

}


int main()
{
	setlocale(LC_ALL, "Ru");

	std::cout << "В данном задание реализованы 3 домашних работы" << std::endl;
	bool check_tasks = true;
	while (check_tasks) {

		std::cout << "Введите номер задачи, которую хотите протестировать(для выхода введите 4): ";
		int n_task;
		std::cin >> n_task;

		switch (n_task)
		{
		case 1:
			simple_string_hash();
			break;
		case 2:
			real_string_hash();
			break;
		case 3:
			find_substring_light_rabin_karp();
			break;

		case 4:
			check_tasks = false;
			break;
		default:
			std::cout << "Такого варианта нет, введите от 1 до 4 пожалуйста." << std::endl;
			break;
		}

	}

	std::cout << "Всего доброго =)" << std::endl;

	return 0;
}