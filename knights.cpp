#include <simplecpp>

// We will consider every possible position for the 2 knights and see if it works, basically brute force
// At last we will divide by 2 since order of knights doesn't matter

// nocap = not capture, checks if Knight(x1,y1) and Knight(x2,y2) not capture each other
bool nocap(int x1, int y1, int x2, int y2)
{
    // Condition based on L shaped move of knight, also removing cases where both are at same spot
    if ((abs(x1 - x2) == 1 && abs(y1 - y2) == 2) || (abs(x1 - x2) == 2 && abs(y1 - y2) == 1) || (x1 == x2 && y1 == y2))
    {
        return false;
    }
    else
        return true;
}

int knights(int n)
{
    int count = 0;
    for (int i1 = 1; i1 <= n; i1++) // i1 and j1 are coordinates of first knight
    {
        for (int j1 = 1; j1 <= n; j1++)
        {
            for (int i2 = 1; i2 <= n; i2++) // i1 and j1 are coordinates of first knight
            {
                for (int j2 = 1; j2 <= n; j2++)
                {
                    if (nocap(i1, j1, i2, j2))
                    {
                        count++;
                    }
                }
            }
        }
    }
    // divide by 2 because repetition
    count = count / 2;
    return count;
}