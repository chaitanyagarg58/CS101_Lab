#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long int X[n], Y[n];
    // We are calculating some expressions while taking the input only. This reduce redundant looping
    long int sum_x = 0, sum_y = 0;
    long int sum_of_square_x = 0, sum_of_square_y = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
        sum_x += X[i];
        sum_of_square_x += X[i] * X[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> Y[i];
        sum_y += Y[i];
        sum_of_square_y += Y[i] * Y[i];
    }
    long int square_of_sum_x = 0, square_of_sum_y = 0;
    square_of_sum_x = sum_x * sum_x;
    square_of_sum_y = sum_y * sum_y;

    // Calculating denominator
    // cout << "sum_x: " << sum_x << ", sum_y: " << sum_y << endl;
    // cout << "sum_of_square_x: " << sum_of_square_x << ", sum_of_square_y: " << sum_of_square_y << endl;
    // cout << "square_of_sum_x: " << square_of_sum_x << ", square_of_sum_y: " << square_of_sum_y << endl;
    double Dn; // Denominator of correlation
    Dn = sqrt((n * sum_of_square_x - square_of_sum_x) * (n * sum_of_square_y - square_of_sum_y));
    // cout << "Dn: " << Dn << endl;
    if (Dn == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        double Nu;           // Numerator of correlation
        long int dot_product = 0; // expression similar to dot product
        for (int i = 0; i < n; i++)
        {
            dot_product += X[i] * Y[i];
        }
        Nu = n * dot_product - sum_x * sum_y;
        // cout << "Nu: " << Nu << endl;
        cout << fixed;     // uses fixed floating point representation
        cout.precision(2); // print two digits after the decimal point
        cout << Nu / Dn << endl;
    }
}