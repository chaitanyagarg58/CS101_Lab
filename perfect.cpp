#include <simplecpp>

int perfect(int m)
{
    int sum = 0;
    for (int j = 1; j < m; j++)
    {
        if (m % j == 0)
            sum += j;
    }
    if (sum == m)
        return 1;
    else
        return 0;
}