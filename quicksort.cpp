#include <iostream>
using namespace std;

// pivot point is the end point
void quicksort(int a[], int start, int end)
{
    if (start >= end)
        return;
    else
    {
        int smaller[end - start], greater[end - start];
        int k1 = 0, k2 = 0;
        for (int i = start; i < end; i++)
        {
            if (a[i] <= a[end])
            {
                smaller[k1] = a[i];
                k1++;
            }
            else
            {
                greater[k2] = a[i];
                k2++;
            }
        }
        quicksort(smaller, 0, k1 - 1);
        quicksort(greater, 0, k2 - 1);
        int temp = a[end];
        for (int i = 0; i < k1; i++)
            a[i] = smaller[i];
        a[k1] = temp;
        for (int i = 0; i < k2; i++)
            a[k1 + i + 1] = greater[i];
        return;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quicksort(arr, 0, n - 1);
    cout << arr[0];
    for (int i = 1; i < n; i++)
        cout << " " << arr[i];
    cout << endl;
}