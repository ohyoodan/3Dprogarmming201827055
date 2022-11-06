#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int A[3][3] = { {3,3,1},
                   {0,0,0},
                   {0,0,0} };
    int B[3][3] = { {1,0,2},
                   {0,1,3},
                   {0,0,1} };
    int C[3][3] = { 0 };

    //3X3 행렬곱 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << C[i][j];
            if (j < 2) cout << " ";
        }
        cout << endl;
    }

    int a[3][1]{ 0,
        0,
        0 };
    

    return 0;
}