#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int num_threads = omp_get_max_threads();
    std::cout << "Number of hardware cores: " << num_threads << std::endl;

    for (int num_elements : {1000, 10000, 100000, 1000000}) {
        std::vector<int> vec1(num_elements, 1);
        std::vector<int> vec2(num_elements, 2);
        std::vector<int> sum(num_elements, 0);

        std::cout << "Number of elements: " << num_elements << std::endl;
        for (int threads = 1; threads <= 16; threads *= 2) {
            double start_time = omp_get_wtime();
#pragma omp parallel for num_threads(threads)
            for (int i = 0; i < num_elements; i++) {
                sum[i] = vec1[i] + vec2[i];
            }
            double end_time = omp_get_wtime();
            std::cout << "Threads: " << threads << ", Time: " << end_time - start_time << "s" << std::endl;
        }
    }
    return 0;
}
