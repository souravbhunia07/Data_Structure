#include <bits/stdc++.h>
using namespace std;

int dp[20][2][20]; // index, tight, count

int solve(string &s, int idx, int tight, int cnt)
{
    if(idx == s.size())
    {
        return cnt;
    }

    if(dp[idx][tight][cnt] != -1)
    {
        return dp[idx][tight][cnt];
    }

    int limit = (tight == 1 ? s[idx] - '0' : 9);
    int ans = 0;

    for(int i = 0; i <= limit; i++)
    {
        int updateCnt = cnt + (i == 3 ? 1 : 0);
        ans += solve(s, idx + 1, (tight & (i == s[idx] - '0')), updateCnt);
    }

    return dp[idx][tight][cnt] = ans;
}

int main()
{
    int l, r;
    cin >> l >> r;
    memset(dp, -1, sizeof(dp));
    string ri = to_string(r);
    int rightAns = solve(ri, 0, 1, 0);
    memset(dp, -1, sizeof(dp));
    string le = to_string(l - 1);
    int leftAns = solve(le, 0, 1, 0);

    cout << rightAns - leftAns << endl;
    return 0;
}
