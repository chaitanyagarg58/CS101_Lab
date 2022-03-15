#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 1)
        cout << 0 << endl;
    else
    {
        int prime[n];
        int prime_count = 0;
        for (int i = 2; i <= n; i++)
        {
            bool is_prime = true;
            for (int j = 0; j < prime_count; j++)
            {
                if (i % prime[j] == 0)
                {
                    is_prime = false;
                    break;
                }
            }
            if (is_prime)
            {
                prime[prime_count] = i;
                prime_count++;
            }
        }
        cout << prime_count << endl;
    }
}