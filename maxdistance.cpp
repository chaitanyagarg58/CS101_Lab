#include <iostream>
#include <cmath>
using namespace std;

// First occurance of a element j in arr is stored in first, similarly last
// If j is not present in arr, distance by default is zero.
int max_distance(int *array, int n, int j)
{
    int first = 0, last = 0;
    bool first_ = false, last_ = false;
    for (int i = 0; i < n; i++)
    {
        if (array[i] == j && !first_)
        {
            first = i;
            first_ = true;
        }
        if (array[n - 1 - i] == j && !last_)
        {
            last = n - 1 - i;
            last_ = true;
        }
        if (first_ && last_)
            break;
    }
    return last - first;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int max_dist = 0;
    for (int j = 0; j < n; j++)
    {
        max_dist = max(max_distance(arr, n, j), max_dist);
    }
    cout << max_dist << endl;
}