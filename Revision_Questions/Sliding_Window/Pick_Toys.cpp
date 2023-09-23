class Solution {
public:

    unordered_map<int, int> mp;

    int totalFruit(vector<int>& fruits) {
        int i = 0, j = 0, res = 0;
        while(j < fruits.size())
        {
            mp[fruits[j]]++;
            if(mp.size() <= 2)
            {
                res = max(res, j - i + 1);
            }
            else
            {
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0)
                {
                    mp.erase(fruits[i]);
                }
                i++;
            }
            j++;
        }
        return res;
    }
};
