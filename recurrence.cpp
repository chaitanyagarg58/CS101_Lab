#include <iostream>

int W(int n)
{
    int w0 = 1, w1 = 1, w2 = 1;
    int w = 0;
    for (int i = 0; i < n - 2; i++)
    {
        w = w0 + w1 + w2;
        w0 = w1;
        w1 = w2;
        w2 = w;
    }
    return w;

    /*This works but time consuming for large n
    if (n >= 0 && n <= 2)
        return 1;
    else
        return W(n - 1) + W(n - 2) + W(n - 3);
    */
}