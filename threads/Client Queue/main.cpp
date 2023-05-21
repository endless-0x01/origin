#include <iostream>
#include <thread>
#include <atomic>
#include <condition_variable>
import set_color; // использовал модуль, что бы попрактиковаться и закрепить материал из книги

constexpr int max_clients = 8;
std::atomic<int> numClients{0};
std::condition_variable check_var;
std::mutex m;

void customerThread() {

	while (numClients.load(std::memory_order_acquire) < max_clients) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		numClients.fetch_add(1,std::memory_order_release);
		consol_color::SetColor(15, 0);
		std::cout << "В очередь добавился новый клиет. Общее кол-во в очереди: "
			<< numClients.load(std::memory_order_release) << std::endl;

		check_var.notify_one();
	}
}

void operatorThread() {
	std::unique_lock<std::mutex> ul{m};

	while (true) {

		check_var.wait(ul, []() { return numClients.load(std::memory_order_acquire) > 0; });

		std::this_thread::sleep_for(std::chrono::seconds(2));
		consol_color::SetColor(10, 0);
		numClients.fetch_sub(1, std::memory_order_release);
		std::cout << "Клиент обслужан. Общее кол-во в очереди: "
			<< numClients.load(std::memory_order_acquire) << std::endl;
		if (numClients.load(std::memory_order_acquire) <= 0) {
			std::cout << "Все клиенты обслужаны!" << std::endl;
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

	return 0;
}