string minWindow(string s, string t) {
       unordered_map<char, int> mp;
       int minLen = INT_MAX, start = 0;
       int i = 0, j = 0;
       for(int i = 0; i < t.length(); i++)
       {
           mp[t[i]]++;
       } 
       int count = mp.size();
       while(j < s.length())
       {
           if(mp.find(s[j]) != mp.end())
           {
               mp[s[j]]--;
               if(mp[s[j]] == 0)
                {
                    count--;
                }
           }
           
           if(count == 0)
           {
               while(count == 0)
               {
                   if(mp.find(s[i]) != mp.end())
                   {
                       mp[s[i]]++;
                       if(mp[s[i]] == 1)
                        {
                            count++;
                            if(j - i + 1 < minLen)
                            {
                                minLen = j - i + 1;
                                start = i;
                            }
                        }
                   }
                   i++;
               }
           }
           j++;
       }
       return minLen == INT_MAX ? "" : s.substr(start, minLen);
}
