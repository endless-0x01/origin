#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>
#include <mutex>

constexpr int COUNT_THREADS = 8; // кол-во потоков
constexpr int TIME = 1; // Время задеркжи
std::mutex consoleMutex;

void progress_bar(const int n_thread)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	
	std::thread::id id = std::this_thread::get_id();

	auto start = std::chrono::steady_clock::now();
	for (int i = 0; i <= 100; i += 10) {
		std::this_thread::sleep_for(std::chrono::seconds(TIME));

		std::lock_guard<std::mutex> lock(consoleMutex);
		std::cout << "Thread: " << n_thread << " id: " << id << " [";
		std::cout << std::string(i / 10, '|') << std::string(10 - i / 10, ' ') << "]";
		std::cout << " " << i << "%\r" << std::flush;
	}
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> result_time = end - start;
	std::lock_guard<std::mutex> lock(consoleMutex);
	std::cout << "\nThread# " << n_thread << " Id: " << id << " time: " << result_time.count() << " ms." << std::endl;
}

int main()
{
	std::vector<std::thread> threads;
	for (int n_thread = 0; n_thread < COUNT_THREADS; n_thread++) {
		threads.emplace_back(progress_bar, n_thread + 1);
	}
	for (auto& t : threads) {
		t.join();
	}
	return 0;
}