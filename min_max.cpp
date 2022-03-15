#include <iostream>
#include <cmath>
using namespace std;

int count = 0; // We need to change ridge_point only once.
// ridge function calculates the ridge value of any array.
// array's starting pointer is passed a parameter 1
// no. of elements in that array is passed as second parameter, not needed here as it will always be n, but better to be safe.
int ridge(int *a, int n, bool *ridge_point)
{
    int ridge = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (count == 0)
            ridge_point[i] = false;
        if ((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1]))
        {
            ridge++;
            if (count == 0)
            {
                ridge_point[i] = true;
            }
        }
    }
    count++;
    return ridge;
}

// We change a[i] and check to get minimum
int ridge_check(int *a, int n, int i, bool *ridge_point)
{
    int temp = a[i];
    // By simple observation, lesser ridge can be in only 2 cases
    // Both will make atleast both a[i] and (one of a[i-1] or a[i+1]) non ridge_point
    a[i] = a[i - 1];
    int ridge1 = ridge(a, n, ridge_point);
    a[i] = a[i + 1];
    int ridge2 = ridge(a, n, ridge_point);
    a[i] = temp;
    return min(ridge1, ridge2);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // Array to keep track if a[i] is a ridge point. Here ridge_point[0]or[n-1] remain undefined, and we never check/use them
    bool ridge_point[n];
    int ridge_min = ridge(a, n, ridge_point);
    // If ridge_min here is zero, we can change end points to still keep it zero, so the rest code does nothing and original ridge value = 0 is reported.
    for (int i = 1; i < n - 1; i++)
    {
        if (ridge_point[i])
        {
            ridge_min = min(ridge_check(a, n, i, ridge_point), ridge_min);
        }
    }
    cout << ridge_min << endl;
}