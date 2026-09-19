#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <bits/stdc++.h>

const int N = 2048;
const int BLOCK = 128;

float* transposed_matrix_multiply(float* A, float* B) {
    auto C = new float[N*N]();
    memset(C,0,N*N);

    for(int i=0; i<N;i++)
    {
        for(int j=i+1; j<N; j++)
        {
            std::swap(B[i*N + j],B[j*N + i]);
        }
    }

    for(int ii=0; ii<N; ii+=BLOCK)
    {
        for(int jj=0; jj<N; jj+=BLOCK)
        {
            for(int kk=0; kk<N; kk+=BLOCK)
            {
                for(int i=ii; i<ii+BLOCK; ++i)
                {
                    for(int j=jj; j<jj+BLOCK; ++j)
                    {
                        for(int k=kk; k<kk+BLOCK; ++k) C[i*N + j] += A[i*N + k]*B[k + N*j];
                    }
                }               
            }
        }
    }

    // for (int i=0; i<N;i++) {
    //     for (int j=0; j<N;j++) {
    //         C[i*N + j] = 0;
    //         for (int k=0; k<N;k++) {
    //             C[i*N + j] += (A[i * N + k] * B[j * N + k]);
    //         }
    //     }
    // }
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
    auto C = transposed_matrix_multiply(A,B);
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    // std::cout<<" Matrix C:\n";

    // print_matrix(C);


    std::cout << "The duration of naive implementation lasted: " << duration.count() << " Miliseconds" << std::endl;
    delete[] C;
    delete[] A;
    delete[] B;
    return 0;
}

