#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <future>

template<typename T>
class safe_queue
{
private:
    std::queue<T> q;
    mutable std::mutex m;
    std::condition_variable cv;

public:
    void push(T value)
    {
        std::lock_guard<std::mutex> lock(m);
        q.push(std::move(value));
        cv.notify_one();
    }

    T pop()
    {
        std::unique_lock<std::mutex> lock(m);
        cv.wait(lock, [this] {return !this->q.empty(); });

        T val = std::move(this->q.front());
        q.pop();
        return val;
    }

    bool empty() const
    {
        std::lock_guard<std::mutex> lock(m);
        return q.empty();
    }
};

class thread_pool
{
private:
    std::vector<std::thread> workers;
    safe_queue<std::function<void()>> tasks;
    bool stop = false;
    std::mutex m;
    std::condition_variable cv;

public:
    thread_pool(unsigned int n = std::thread::hardware_concurrency())
    {
        for (unsigned int i = 0; i < n; ++i)
        {
            workers.emplace_back([this] {
                while (true)
                {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(this->m);
                        this->cv.wait(lock, [this] { return this->stop || !this->tasks.empty(); });
                        if (this->stop && this->tasks.empty())
                            return;
                        task = this->tasks.pop();
                    }
                    task();
                }
                });
        }
    }

    template<class F>
    auto submit(F f) -> std::future<decltype(f())>
    {
        auto task = std::make_shared<std::packaged_task<decltype(f())()>>(std::move(f));
        auto res = task->get_future();
        {
            std::lock_guard<std::mutex> lock(this->m);
            if (stop)
                throw std::runtime_error("submit on stopped thread_pool");
            tasks.push([task]() {(*task)(); });
        }
        cv.notify_one();
        return res;
    }

    ~thread_pool()
    {
        {
            std::lock_guard<std::mutex> lock(m);
            stop = true;
        }
        cv.notify_all();
        for (auto& thread : workers)
        {
            thread.join();
        }
    }
};

int main()
{
    thread_pool pool;

    auto task1 = [] { std::cout << "Task 1 executed\n"; return 1; };
    auto task2 = [] { std::cout << "Task 2 executed\n"; return 2; };

    while (true)
    {
        auto res1 = pool.submit(task1);
        auto res2 = pool.submit(task2);

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
