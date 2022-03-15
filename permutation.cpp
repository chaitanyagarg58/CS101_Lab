#include <simplecpp>
// Swaps 2 no.
void swap(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

void permutation(int &a, int &b, int &c, int n)
{
    if (n == 1)
        return;
    else if (n == 2)
    {
        swap(b, c);
        return;
    }
    else if (n == 3)
    {
        swap(a, b);
        return;
    }
    else if (n == 4)
    {
        swap(b, c);
        swap(a, c);
        return;
    }
    else if (n == 5)
    {
        swap(b, c);
        swap(a, b);
        return;
    }
    else if (n == 6)
    {
        swap(a, c);
        return;
    }
}