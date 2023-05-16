#include <iostream>
#include <thread>

import set_color; // ����������� ������, ��� �� ���������������� � ��������� �������� �� �����

constexpr int max_clients = 8;
int numClients = 0;

void customerThread() {

	while (true) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		++numClients;
		if (numClients <= 8) {
			consol_color::SetColor(15, 0);
			std::cout << "� ������� ��������� ����� �����. ����� ���-�� � �������: "
				<< numClients << std::endl;
		}
		else {
			break;
		}
	}
}

void operatorThread() {

	while (true) {
		std::this_thread::sleep_for(std::chrono::seconds(2));
		if (numClients > 0) {
			consol_color::SetColor(10, 0);
			--numClients;
			std::cout << "������ ��������. ����� ���-�� � �������: "
				<< numClients << std::endl;
		}
		else {
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Ru");
	
	std::thread t1(customerThread);
	std::thread t2(operatorThread);

	t1.join();
	t2.join();
	std::cout << "��� ������� ���������!" << std::endl;

	return 0;
}