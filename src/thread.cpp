#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

int global_counter = 0;

int main()
{
    auto lambda = [](int x){
        std::cout << "Hello from thread!" << std::this_thread::get_id() << std::endl;
        std::cout << "Argument passed in: " << x << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        global_counter++;
    };

    std::vector<std::thread> threads;
    for (int i = 0; i < 10; i++)
    {
        threads.push_back(std::thread(lambda,i));
    }

    for (int i = 0; i < 10; i++)
    {
        threads[i].join();
    }
    
    std::cout << "Hello from my main thread" << std::endl;
    return 0;
}