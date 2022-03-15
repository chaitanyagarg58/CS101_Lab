#include <simplecpp>
// dot product of two vectors (a1,a2,a3) and (b1,b2,b3)
double dot_product(double a1, double a2, double a3, double b1, double b2, double b3)
{
    return a1 * b1 + a2 * b2 + a3 * b3;
}
// cross product of two vectors (a1,a2,a3) and (b1,b2,b3)
void cross_product(
    double a1, double a2, double a3, double b1, double b2, double b3,
    double &x, double &y, double &z)

{
    x = a2 * b3 - a3 * b2;
    y = a3 * b1 - a1 * b3;
    z = a1 * b2 - a2 * b1;
}

bool point_on_plane(
    double *p1_x, double *p1_y, double *p1_z,
    double *p2_x, double *p2_y, double *p2_z,
    double *p3_x, double *p3_y, double *p3_z,
    double *q_x, double *q_y, double *q_z,
    double *dist)

{
    // equation of plane ax + by + cz = n
    double a, b, c, n;
    cross_product(*p1_x - *p3_x, *p1_y - *p3_y, *p1_z - *p3_z,
                  *p2_x - *p3_x, *p2_y - *p3_y, *p2_z - *p3_z,
                  a, b, c);
    n = a * *p1_x + b * *p1_y + c * *p1_z;

    if (abs(a * *q_x + b * *q_y + c * *q_z - n) <= 0.00001) // should not check for exact equality in computer
    {
        *dist = 0;
        return true;
    }
    else
    {
        *dist = abs(dot_product(a, b, c, *p1_x - *q_x, *p1_y - *q_y, *p1_z - *q_z) / sqrt(a * a + b * b + c * c));
        return false;
    }

    // control never reaches here, but just to check
    return -1;
}