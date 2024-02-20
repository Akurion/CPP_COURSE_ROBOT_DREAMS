#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <algorithm>

void quickSort(std::vector<int>& vec, int left, int right) {
    int i = left, j = right;
    int pivot = vec[(left + right) / 2];

    while (i <= j) {
        while (vec[i] < pivot) {
            i++;
        }
        while (vec[j] > pivot) {
            j--;
        }
        if (i <= j) {
            std::swap(vec[i], vec[j]);
            i++;
            j--;
        }
    }

    if (left < j) {
        std::thread t(quickSort, std::ref(vec), left, j);
        t.join();
    }
    if (i < right) {
        std::thread t(quickSort, std::ref(vec), i, right);
        t.join();
    }
}

int main() {
    std::vector<int> sizes = { 1000, 10000, 20000, 30000 };

    for (int size : sizes) {
        std::vector<int> vec(size);
        for (int i = 0; i < size; ++i) {
            vec[i] = i;
        }

        // 1 thread
        auto start = std::chrono::high_resolution_clock::now();
        quickSort(vec, 0, vec.size() - 1);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_1_thread = end - start;

        // 2 threads
        start = std::chrono::high_resolution_clock::now();
        std::thread t(quickSort, std::ref(vec), 0, vec.size() - 1);
        t.join();
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_2_threads = end - start;

        // HARDWARE_CONCURRENCY() 
        start = std::chrono::high_resolution_clock::now();
        std::vector<std::thread> threads;
        for (unsigned int i = 0; i < std::thread::hardware_concurrency(); ++i) {
            threads.emplace_back(quickSort, std::ref(vec), i * (size / std::thread::hardware_concurrency()), (i + 1) * (size / std::thread::hardware_concurrency()) - 1);
        }
        for (auto& thread : threads) {
            thread.join();
        }
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_hardware_concurrency = end - start;

        // HARDWARE_CONCURRENCY() * 2
        start = std::chrono::high_resolution_clock::now();
        std::vector<std::thread> threads_2x;
        for (unsigned int i = 0; i < std::thread::hardware_concurrency() * 2; ++i) {
            threads_2x.emplace_back(quickSort, std::ref(vec), i * (size / (std::thread::hardware_concurrency() * 2)), (i + 1) * (size / (std::thread::hardware_concurrency() * 2)) - 1);
        }
        for (auto& thread : threads_2x) {
            thread.join();
        }
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_2x_hardware_concurrency = end - start;

        std::cout << "Size: " << size << std::endl;
        std::cout << "Time for 1 thread: " << duration_1_thread.count() << " seconds" << std::endl;
        std::cout << "Time for 2 threads: " << duration_2_threads.count() << " seconds" << std::endl;
        std::cout << "Time for " << std::thread::hardware_concurrency() << " threads: " << duration_hardware_concurrency.count() << " seconds" << std::endl;
        std::cout << "Time for " << std::thread::hardware_concurrency() * 2 << " threads: " << duration_2x_hardware_concurrency.count() << " seconds" << std::endl;

        std::cout << "Boost for 2 threads: " << duration_1_thread.count() / duration_2_threads.count() << std::endl;
        std::cout << "Boost for " << std::thread::hardware_concurrency() << " threads: " << duration_1_thread.count() / duration_hardware_concurrency.count() << std::endl;
        std::cout << "Boost for " << std::thread::hardware_concurrency() * 2 << " threads: " << duration_1_thread.count() / duration_2x_hardware_concurrency.count() << std::endl;

        std::cout << "----------------------------------" << std::endl;
    }

    return 0;
}
