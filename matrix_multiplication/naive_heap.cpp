#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

const int N = 2048;

float* naive_matrix_multiply(float* A, float* B) {
    auto C = new float[N*N];
    for (int i=0; i<N;i++) {
        for (int j=0; j<N;j++) {
            C[i*N + j] = 0;
            for (int k=0; k<N;k++) {
                C[i*N + j] += (A[i * N + k] * B[j + k*N]);
            }
        }
    }
    return C;
}

void populate_matrix(float* X) {
    for (int i=0; i<N*N;i++) {
        X[i] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

    }
}

void print_matrix(float* X)
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
    auto A = new float[N*N];
    auto B = new float[N*N];


    populate_matrix(A);
    populate_matrix(B);
    // std::cout<<" Matrix A:\n";
    // print_matrix(A);
    // std::cout<<" Matrix B:\n";
    // print_matrix(B);



    auto start = std::chrono::high_resolution_clock::now();
    auto C = naive_matrix_multiply(A,B);
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    // std::cout<<" Matrix C:\n";

    // print_matrix(C);


    std::cout << "The duration of naive implementation lasted: " << duration.count() << " Miliseconds" << std::endl;
    delete C;
    // TODO discuss different implementations
    return 0;
}

