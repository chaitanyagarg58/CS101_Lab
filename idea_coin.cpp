#include <simplecpp>

// Since only 2 types of moves are possible, we will use binary no.
// WLOG 1 could mean 1 from left pile and 2 from right, and 0 would mean reverse
// The digits in the binary no. give respective moves
// If it does not work, we add 1 to the binary no. and try again

int coin_piles(int a, int b)
{
    int n = 0; // n is our binary no., but stored in decimal form only
    // We will convert it in binary where needed
    int count = 0; // just to count is there is a solution

    // If solution has only 0s, then it will be a problem, we will check it sepeartely
    if (a != 2 * b || b != 2 * a) // for trivial cases of 00... or 11...
    {
        for (int k = 0; k < 1000000; k++)
        {
            int i = n;
            while (i > 0)
            {
                if (i % 2 == 1)
                {
                    a = a - 1;
                    b = b - 2;
                }
                else
                {
                    a = a - 2;
                    b = b - 1;
                }
                i = i / 2;
            }
            n++;

            if (a == 0 && b == 0)
            {
                return 1;
                count++;
                break;
            }
        }
        if (count == 0)
        {
            return 0;
        }
    }
    else
        return 1; // control reachs
}