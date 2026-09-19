#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

const int N = 128;

// int* naive_matrix_multiply(int* A, int* B) {
//     auto C = new int[N*N];
//     for (int i=0; i<N;i++) {
//         for (int j=0; j<N;j++) {
//             C[i*N + j] = 0;
//             for (int k=0; k<N;k++) {
//                 C[i*N + j] += (A[i * N + k] * B[j + k*N]);
//             }
//         }
//     }
//     return C;
// }

void naive_matrix_multiply(int* A, int* B, int* C) {
    for (int i=0; i<N;i++) {
        for (int j=0; j<N;j++) {
            C[i*N + j] = 0;
            for (int k=0; k<N;k++) {
                C[i*N + j] += (A[i * N + k] * B[j + k*N]);
            }
        }
    }
}

void populate_matrix(int* X) {
    for (int i=0; i<N*N;i++) {
        X[i] = rand()%10;
    }
}

void print_matrix(int* X)
{
    for(int i=0; i<N*N; i++)
    {
        if(i%N==0)
            std::cout<< std::endl;
        std::cout<<X[i] << " ";
    }
}

int main(int argc, const char* argv[]) {
    srand((unsigned)time(NULL));
    int A[N*N];
    int B[N*N];


    populate_matrix(A);
    populate_matrix(B);
    // std::cout<<" Matrix A:\n";
    // print_matrix(A);
    // std::cout<<" Matrix B:\n";
    // print_matrix(B);

    int C[N*N];


    auto start = std::chrono::high_resolution_clock::now();
    naive_matrix_multiply(A,B,C);
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    // std::cout<<" Matrix C:\n";

    // print_matrix(C);


    std::cout << "The duration of naive implementation lasted: " << duration.count() << " Miliseconds" << std::endl;
    // delete C;
    // TODO discuss different implementations
    return 0;
}

