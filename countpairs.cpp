#include <iostream>
using namespace std;

// returns index of samllest element greater than or equal to k
int search(int arr[], int start, int end, int k)
{
    if (start == end)
        return start;
    else
    {
        int mid = (start + end) / 2;
        if (arr[mid] >= k)
            return search(arr, start, mid, k);
        else
            return search(arr, mid + 1, end, k);
    }
}

// no. of second indices
int number(int arr[], int n, int l, int r, int i)
{
    int first, last;
    first = search(arr, i + 1, n - 1, l);
    if (r + 1 <= arr[n - 1])
        last = search(arr, i + 1, n - 1, r + 1) - 1;
    else
        last = n - 1;
    if (first != last)
        return last - first + 1;
    else if (arr[first] >= l && arr[first] <= r)
        return 1;
    else
        return 0;
}

int main()
{
    int n, l, r;
    cin >> n >> l >> r;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int lval = l - a[i];
        int rval = r - a[i];                  // max and min val of second no.
        count += number(a, n, lval, rval, i); // passing i as well as we don't want second index to be s well, so will check in function
    }
    cout << count << endl;
}