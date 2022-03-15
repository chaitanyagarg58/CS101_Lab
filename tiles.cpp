#include <iostream>

int min_tiles(int w, int h)
{
    // We notice that if a side is odd, then it must have a 1*1 tile because all other tiles are of even side length

    // base cases
    // since sides remain positive, they will eventually reduce to 1, which would then turn to 0, hence this is the base case
    if (w == 0 || h == 0)
        return 0;

    // if both sides odd, 1st row and column 1*1, then even*even grid, for min tiles, 2*2 or higher tiles used
    // hence combine 2 length units into 1 to reduce to original.
    else if (w % 2 == 1 && h % 2 == 1)
        return w + h - 1 + min_tiles((w - 1) / 2, (h - 1) / 2);
    // if only one side is odd, then that side 1*1 tiles, then we get even*even grid,
    // hence combine 2 length units into 1 to reduce to original.
    else if (w % 2 == 1 && h % 2 == 0)
        return h + min_tiles((w - 1) / 2, h / 2);
    else if (w % 2 == 0 && h % 2 == 1)
        return w + min_tiles(w / 2, (h - 1) / 2);
    // if both are even, we don't need to use 1*1 tiles and can directly combine 2 unit in 1
    else if (w % 2 == 0 && h % 2 == 0)
        return min_tiles(w / 2, h / 2);

    // control should never reach here
    return -1;
}