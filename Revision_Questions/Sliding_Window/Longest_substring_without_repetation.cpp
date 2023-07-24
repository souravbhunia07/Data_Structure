int lengthOfLongestSubstring(string S) {
        // vector<int> mp(256, -1);
        // int left = 0, right = 0, len = 0, n = s.length();
        // while(right < n)
        // {
        //     if(mp[s[right]] != -1)
        //     {
        //         left = max(mp[s[right]] + 1, left);
        //     }
        //     mp[s[right]] = right;
        //     len = max(len, right - left + 1);
        //     right++;
        // }
        // return len;

        int i = 0, j = 0, mx = 0;
        unordered_map<char, int> mp;
        while(j < S.size())
        {
            mp[S[j]]++;
            if(mp.size() == j - i + 1)
            {
                mx = max(mx, j - i + 1);
                j++;
            }
            else if(mp.size() < j - i + 1)
            {
                mp[S[i]]--;
                if(mp[S[i]] == 0)
                {
                    mp.erase(S[i]);
                }
                i++;
            }
            j++;
        }
        return mx >= 0 ? mx : -1;
    }
