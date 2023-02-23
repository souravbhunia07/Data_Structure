#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    double y = -(x * x) + 4 * x;
    return y;
}

int main()
{
    double left = -100, right = 100;
    while(right - left > 0.00001)
    {
        double mid1 = (2 * left + right) / 3;
        double mid2 = (left + 2 * right) / 3;

        if(f(mid1) < f(mid2))
        {
            left = mid1;
        }
        else
        {
            right = mid2;
        }
    }
    cout << left << " " << right << endl;
    return 0;
}
