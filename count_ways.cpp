#include <iostream>

int count_ways(int n)
{
    // the last dice can be 1,2,3,4,5 or 6
    // for example if the last dice is 3, then the rest of the sequence can all possible ways to get n-3
    // hence we get the recursion ways(n) = ways(n-1) + .... + ways(n-6)
    // base cases ways(0) = 1, ways(1) = 1, ways(-ve) = 0
    if (n < 0)
        return 0;
    else if (n == 0 || n == 1)
        return 1;
    else
        return count_ways(n - 1) + count_ways(n - 2) + count_ways(n - 3) + count_ways(n - 4) + count_ways(n - 5) + count_ways(n - 6);
}