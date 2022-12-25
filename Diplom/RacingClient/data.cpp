#include "data.h"



int get_data()
{
	int data{};
	std::cin >> data;
	std::cin.clear();
	return data;
}

int get_distance_game() {
	std::cout << "������� ����� ��������� (������ ���� ������������): ";
	int distance = get_data();
	if (distance < 0) {
		std::cout << "�� ����� ������������� ���������, �� �������� ��� ������ ������. ���� ����� ��������!\n";
		exit(-1);
	}
	return distance;
}

void sort_ts(std::vector<Transport*>& ts) {

	for (int i = 0; i < ts.size(); i++)
	{
		for (int j = 0; j < ts.size(); j++) {
			
			if (ts[i]->get_time() > ts[j]->get_time()) {
				Transport* object = ts[i];
				ts[i] = ts[j];
				ts[j] = object;
			}

		}
	}
}

void start_game()
{
	std::cout << "1. ����� ��� ��������� ����������" << std::endl;
	std::cout << "2. ����� ��� ���������� ����������" << std::endl;
	std::cout << "3. ����� ��� ��������� � ���������� ����������" << std::endl;

	enum action_choice
	{
		registration = 1,
		strart_racing
	};
	std::vector<Transport*> ts;
	int distance{};
	
	std::cout << "�������� ��� �����: ";
	int choice_racing = get_data();

	int user_choise{};

	bool new_race = false;

	while (true) {

		if (new_race) {
			system("cls");
			new_race = false;
			std::cout << "1. ����� ��� ��������� ����������" << std::endl;
			std::cout << "2. ����� ��� ���������� ����������" << std::endl;
			std::cout << "3. ����� ��� ��������� � ���������� ����������" << std::endl;
			std::cout << "�������� ��� �����: ";
			choice_racing = get_data();
			distance = get_distance_game();
		}


		if (ts.empty() || ts.size() < 2) {
			system("cls");
			std::cout << "������ ���� ���������������� ���� �� 2 ������������ ��������" << std::endl;
			std::cout << "1. ���������������� ������������ ��������" << std::endl;;
		}
		else {
			system("cls");
			std::cout << "1. ���������������� ������������ ��������" << std::endl;
			std::cout << "2. ������ �����" << std::endl;
		}

		std::cout << "�������� ��������: ";
		std::cin >> user_choise;

		if (!distance) {
			system("cls");
			distance = get_distance_game();
		}


		if (user_choise == action_choice::registration) {
			if (choice_racing == 1) {
				std::cout << "����� ��� ��������� ����������. ����������: " << distance << std::endl;
				show_transports();
				std::cout << "0. ��������� �����������" << std::endl;
				vehicle_registration(ts, choice_racing, distance);
			}
			else if (choice_racing == 2) {
				std::cout << "����� ��� ���������� ����������. ����������: " << distance << std::endl;
				show_transports();
				std::cout << "0. ��������� �����������" << std::endl;
				vehicle_registration(ts, choice_racing, distance);
			}
			else if (choice_racing == 3) {
				std::cout << "����� ��� ��������� � ���������� ����������. ����������: " << distance << std::endl;
				show_transports();
				std::cout << "0. ��������� �����������" << std::endl;
				vehicle_registration(ts, choice_racing, distance);
			}
		}
		else if (user_choise == action_choice::strart_racing) {
			system("cls");
			for (auto vh : ts) {
				vh->count_time_racing(distance);
			}

			std::cout << "���������: " << std::endl;
			sort_ts(ts);
			for (int i = 0; i < ts.size(); i++) {
				std::cout  << i + 1 << ". " << ts[i]->get_name_ts() << " �����: " << ts[i]->get_time() << std::endl;
			}

			std::cout << "-----------------------------------\n";
			std::cout << "1. �������� ��� ���� �����\n";
			std::cout << "2. �����\n";
			std::cout << "�������� ��������: ";
			user_choise = get_data();
			if (user_choise == 1) {
				ts.clear();
				distance = 0;
				new_race = true;
			}
			else if (user_choise == 2) {
				exit(0);
			}
		}

	}
}



result_checked check_ts_for_availability(std::vector<Transport*>& ts, Transport* object, int type_game, std::string& repeat_name)
{
	if (((static_cast<int>(object->get_type_racing()) != type_game) && type_game != 3))
	{
		delete object;
		object = nullptr;
		return result_checked::wrong_type;
	}
	for (auto vh : ts)
	{
		if (vh->get_name_ts() == object->get_name_ts()) {
			repeat_name = object->get_name_ts();
			delete object;
			object = nullptr;
			return result_checked::repeat;
		}
	}
	ts.push_back(object);
	return result_checked::succes;
}

void ts_in_stock(std::vector<Transport*>& ts) {
	std::cout << "����������������� ������������ ��������: ";
	for (auto vh : ts)
	{
		std::cout << vh->get_name_ts() << ", ";
	}
	std::cout << std::endl;
}

void vehicle_registration(std::vector<Transport*>& ts, int type_game, int distance) {
	
	result_checked rhs{};
	std::string rp_name;
	while (true) {
		system("cls");
		switch (rhs)
		{
		case result_checked::succes:
			std::cout << ts[ts.size() - 1]->get_name_ts() << " ������� ���������������." << std::endl;
			break;
		case result_checked::repeat:
			std::cout << rp_name << " ��� ���������������." << std::endl;
			break;
		case result_checked::wrong_type:
			std::cout << "������� ���������������� ������������ ��� ������������� ��������!" << std::endl;
			break;
		default:
			break;
		}

		if(type_game == 1)
			std::cout << "����� ��� ��������� ����������. ����������: " << distance << std::endl;
		else if(type_game == 2)
			std::cout << "����� ��� ���������� ����������. ����������: " << distance << std::endl;
		else
			std::cout << "����� ��� ��������� � ���������� ����������. ����������: " << distance << std::endl;

		ts_in_stock(ts);
		show_transports();
		std::cout << "�������� ��������� ��� 0 ��� ��������� �������� �����������: ";
		int user_ch = get_data();
		switch (user_ch)
		{
		case 1: {
			rhs = check_ts_for_availability(ts, new SpeedBoots, type_game, rp_name);
			break;
		}
		case 2: {
			rhs = check_ts_for_availability(ts, new Broom, type_game, rp_name);
			break;
		}
		case 3: {
			rhs = check_ts_for_availability(ts, new Camel, type_game, rp_name);
			break;
		}
		case 4: {
			rhs = check_ts_for_availability(ts, new Kentavr, type_game, rp_name);
			break;
		}
		case 5: {
			rhs = check_ts_for_availability(ts, new Eagle, type_game, rp_name);
			break;
		}
		case 6: {
			rhs = check_ts_for_availability(ts, new CamelSpeed, type_game, rp_name);
			break;
		}
		case 7: {
			rhs = check_ts_for_availability(ts, new CaretPlane, type_game, rp_name);
			break;
		}
		case 0:
			return;
		default:
			std::cout << "������ ����������� �������� ���" << std::endl;
			break;
		}
	}
}
