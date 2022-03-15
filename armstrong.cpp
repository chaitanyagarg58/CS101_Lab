#include <simplecpp>
// order is the no. of digits
int order(int n)
{
    int order = 0;
    while (n > 0)
    {
        order++;
        n = n / 10;
    }
    return order;
}

int armstrong(int n)
{
    int count = 0; // keeps track of how many armstrong's no. have been found, so that nth can be printed
    for (int i = 1; true; i++)
    {
        int sum = 0;
        int check = i; // We store i in check because i is iteration variable, and we don't want to change it in each iteration except adding 1 to by i++ in update of for loop

        while (check > 0)
        {
            sum += floor(pow(check % 10, order(i)) + 0.01);
            check = check / 10;
        }

        if (sum == i) // basically check if i is armstrong no. or not.
        {
            count++;
        }

        if (count == n) // waits till n-1 armstrong no., then on nth one, count becomes n and nth one gets printed
        {
            return i;
            break;
        }
    }
}