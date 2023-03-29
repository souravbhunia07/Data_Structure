#include <bits/stdc++.h>
using namespace std;

int main()
{
    string text = "abaabaaabbababbbbaaaaaba";
    string pat = "aba";
    int m = pat.size(), n = text.size();

    for(int i = 0; i + m < text.size(); i++)
    {
        if(text.substr(i, m) == pat)
        {
            cout << i << endl;
        }
    }
    return 0;
}
