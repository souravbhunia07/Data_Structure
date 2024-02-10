#include <bits/stdc++.h>
using namespace std;

long Reverse(int x)
{
    long result = 0, x_remaining = abs(x);
    while(x_remaining)
    {
        result = result * 10 + x_remaining % 10;
        x_remaining /= 10;
    }
    return x < 0 ? -result : result;
}

int main()
{
    int x;
    cin >> x;

    cout << Reverse(x) << endl;
    
    return 0;
}
