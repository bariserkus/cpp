#include <iostream>
#include <chrono>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
#include <execution>

#include "utils.h"
#include "matrix.h"

const size_t testSize = 1'000;

using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::milli;

void print_results(const char *const tag,
                   high_resolution_clock::time_point startTime,
                   high_resolution_clock::time_point endTime) {
    printf("%s: Time: %fms\n", tag, duration_cast<duration<double, milli>>(endTime - startTime).count());
}

const int MS = 500;

void performance_test_multiply()
{
    const int matrix_size = MS;

    Matrix A(matrix_size, matrix_size);
    Matrix B(matrix_size, matrix_size);
    Matrix C(matrix_size, matrix_size);
    Matrix D(matrix_size, matrix_size);


    A.set_all(1);
    B.set_all(1);

    auto startTime = high_resolution_clock::now();
    Matrix::multiply(&A, &B, &C);
    auto endTime = high_resolution_clock::now();
    print_results("sequential matrix multiplication", startTime, endTime);

    startTime = high_resolution_clock::now();
    Matrix::parallel_multiply(&A, &B, &D);
    endTime = high_resolution_clock::now();
    print_results("parallel  matrix multiplication", startTime, endTime);

}

void performance_test_transpose()
{
    //Matrix A(5, 8);
    //A.set_all(1);
    //A.set_value(3, 4, 5);
    //A.print();

    //Matrix B(8, 5);
    //Matrix::transpose(&A, &B);
    //B.print();

    const int matrix_size = MS;

    Matrix A(matrix_size, matrix_size);
    Matrix B(matrix_size, matrix_size);

    A.set_all(1);

    auto startTime = high_resolution_clock::now();
    Matrix::transpose(&A, &B);
    auto endTime = high_resolution_clock::now();
    print_results("sequential matrix transpose", startTime, endTime);

    startTime = high_resolution_clock::now();
    Matrix::parallel_transpose(&A, &B);
    endTime = high_resolution_clock::now();
    print_results("parallel  matrix transpose", startTime, endTime);
}

int main()
{
    //performance_test_transpose();
    performance_test_multiply();
    return 0;
}