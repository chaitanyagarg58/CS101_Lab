#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    char A[n], B[m];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < m; i++)
        cin >> B[i];
    char C[n + m + 1]; // n+m is maximum length, in case no common element, then we need 1 extra cause we will store '\0' at our end.

    int i = 0, j = 0;
    for (int k = 0; k < n + m + 1; k++)
    {
        if (i < n && j < m)
        {
            if (A[i] < B[j])
            {
                C[k] = A[i];
                i++;
            }
            else if (A[i] >= B[j])
            {
                C[k] = B[j];
                j++;
            }
            while (C[k] == A[i])
            {
                i++;
            }
            while (C[k] == B[j])
            {
                j++;
            }
        }
        else if (i < n)
        {
            C[k] = A[i];
            i++;
            while (C[k] == A[i])
            {
                i++;
            }
        }
        else if (j < m)
        {
            C[k] = B[j];
            j++;
            while (C[k] == B[j])
            {
                j++;
            }
        }
        else
        {
            C[k] = '\0';
            break;
        }
    }
    cout << C[0];
    for (int l = 1; C[l] != '\0'; l++)
    {
        cout << " " << C[l];
    }
    cout << endl;
}