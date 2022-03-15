#include <simplecpp>

void print_coordinates(int n)
{
    int x = 0, y = 0;
    int dir = 0; // dir records orientation of turtle
    // dir: 0 = east; 1 = north; 2 = west; 3 = south;
    // we will take dir % 4 so that dir can only be 0, 1, 2 or 3
    for (int i = 0; i < n; i++)
    {
        char cmd; // cmd = command
        cin >> cmd;
        if (cmd == 'L')
        {
            dir++;
            dir = dir % 4;
        }
        else if (cmd == 'F') // It can be assumed that command is F or L only, but still, why not check
        {
            if (dir == 0)
                x++;
            else if (dir == 1)
                y++;
            else if (dir == 2)
                x--;
            else if (dir == 3)
                y--;
        }
    }
    cout << x << " " << y << endl;
}