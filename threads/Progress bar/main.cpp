#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>
#include <mutex>
#include <algorithm>
#include <sstream>
#include <random>

constexpr int COUNT_THREADS = 8; // кол-во потоков
std::mutex consoleMutex;

std::vector<std::string> progress(COUNT_THREADS, "");


std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> distr(1, 3);

std::string threadIdToString(const std::thread::id& id) {
    std::ostringstream oss;
    oss << id;
    return oss.str();
}

void updateProgress() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        std::lock_guard<std::mutex> lock(consoleMutex);

        // Очистка экрана
        std::cout << "\033[2J\033[1;1H";

        for (int i = 0; i < COUNT_THREADS; ++i) {
            std::cout << progress[i] << std::endl;
        }

        // Проверка, завершены ли все потоки
        bool done = std::all_of(progress.begin(), progress.end(), [](const std::string& str) { return str.find("100%") != std::string::npos; });
        if (done) break;
    }
}

void progress_bar(const int n_thread)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::thread::id id = std::this_thread::get_id();

    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i <= 100; i += 10) {
        std::this_thread::sleep_for(std::chrono::seconds(distr(gen)));
        std::lock_guard<std::mutex> lock(consoleMutex);
        progress[n_thread - 1] = "Thread: " + std::to_string(n_thread) + " id: " + threadIdToString(id) + " [" +
            std::string(i / 10, '|') + std::string(10 - i / 10, ' ') + "]" +
            " " + std::to_string(i) + "%";
        if (i == 100) {
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> result_time = end - start;
            progress[n_thread - 1] += " time: " + std::to_string(result_time.count()) + " ms.";
        }
    }
}

int main()
{
    std::vector<std::thread> threads;
    for (int n_thread = 0; n_thread < COUNT_THREADS; n_thread++) {
        threads.emplace_back(progress_bar, n_thread + 1);
    }
    std::thread consoleThread(updateProgress);
    for (auto& t : threads) {
        t.join();
    }
    consoleThread.join();

    return 0;
}
