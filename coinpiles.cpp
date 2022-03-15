#include <simplecpp>

// lets call taking 1 from left pile and 2 from right as "event1"
// lets call taking 2 from left pile and 1 from right as "event2"
// lets say event1 occurs n1 times and event2 occurs n2 times.
//  then check for values of n1, n2

int coin_piles(int a, int b)
{
    int count = 0;                                    // To record if solution is found
    for (int n1 = 0; n1 <= min(a, (b + 1) / 2); n1++) // If n1 > a, then aFinal is definitely negative, so no need to check
    {                                                 // If n1 > (b+1)/2, then bFinal is definitely negative, so no need to check
        for (int n2 = 0; n2 <= max(a, b); n2++)       // Optimisation here is done by if-break statements in loop
        {
            int aFinal, bFinal;
            aFinal = a - n1 - 2 * n2;
            bFinal = b - n2 - 2 * n1;

            cout << "n1: " << n1 << ", n2: " << n2 << ", aFinal: " << aFinal << ", bFinal: " << bFinal << endl;

            if (aFinal == 0 && bFinal == 0) // n1, n2 gives a solution
            {
                count++;
                break; // Any more checking is redundant
            }
            else if (aFinal <= 0 || bFinal <= 0) // both can not be 0 due to else
            {
                break; // Any more increment in n2 will yield negative values only
            }

            // To speed up for large no.
            // if (aFinal > 2 * (n2 + 1000) && bFinal > (n2 + 1000))
            // {
            //     n2 = n2 + 998;
            // }
        }
        if (count != 0)
        {
            break; // break in line 21 only breaks out of inner for loop
        }
    }
    if (count != 0)
    {
        return 1;
    }
    else
        return 0;
}
