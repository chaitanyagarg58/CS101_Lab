#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (A[j] > A[i])
            {
                count++;
            }
        }
        if (count == A[i])
        {
            found = true;
            break;
        }
    }
    cout << found << endl;
}