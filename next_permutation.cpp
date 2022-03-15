#include <iostream>
#include <cmath>
using namespace std;

void swap(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}
// following makes any arr/part of it as given, in increasing order
// we use the fact that we know, this function will only be called if all the elements are in decreasing order
void increasing(int *array, int n) // (starting point of part of arr, no. of elements)
{
    for (int i = 0; i < n / 2; i++)
    {
        swap(array[i], array[n - 1 - i]);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    for (k = n - 2; k >= 0; k--)
    {
        if (arr[k] < arr[k + 1])
            break;
    }
    // after this we will get k such that after a[k], no. are in decreasing order

    // if this is the last permuatation, then k = -1.
    //  in that case we need to switch to increasing order
    if (k < 0)
    {
        increasing(arr, n);
    }
    else // else k >= 0
    {
        // next permutation needs to be greater than this one
        // hence we must swap a[k] with the least significant digit greater than a[k]
        int p;
        for (p = n - 1; p > k; p--)
        {
            if (arr[p] > arr[k])
            {
                swap(arr[k], arr[p]);
                increasing(&arr[k + 1], n - 1 - k);
                break;
            }
        }
    }
    cout << arr[0];
    for (int i = 1; i < n; i++)
        cout << " " << arr[i];
    cout << endl;
}