#include <iostream>
using namespace std;
//We are using cofactor function in det, and det in cofactor, hence we need to declare one before hand
int det(int arr[], int size);

int cofactor(int arr[], int size, int index)
{
    int cof[(size - 1) * (size - 1)];
    int j = size;
    for (int i = 0; i < (size - 1) * (size - 1); i++)
    {
        if (j % size == index)
            j++;
        cof[i] = arr[j];
        j++;
    }
    return det(cof, size - 1);
}

int det(int arr[], int size)
{
    if (size == 1)
        return arr[0];
    else
    {
        int det = 0;
        for (int j = size - 1; j >= 0; j--) // Expanding determinant by first row, i=0
        {
            det = -det;
            det += arr[j] * cofactor(arr, size, j);
        }
        return det;
    }
}

int main()
{
    int n;
    cin >> n;
    // We will store the matrix in 1D array, row by row, instead of 2D arrays, as it would be easier to pass it in functions.
    int A[n * n];
    for (int i = 0; i < n * n; i++)
        cin >> A[i];
    // Matrix[i][j] = A[k], means i = x / n, and j = x % n
    cout << det(A, n) << endl;
}