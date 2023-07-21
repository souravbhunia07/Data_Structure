int search(string p, string s) {
	   // int i = 0, j = 0, k = pat.size(), count, n = txt.size(), ans = 0;
	   // unordered_map<char, int> mp;
	   // for(int i = 0; i < k; i++)
	   // {
	   //     mp[txt[i]]++;
	   // }
	   // count = mp.size();
	   // while(j < n)
	   // {
	   //     // Calculations
	   //     if(mp.find(txt[j]) != mp.end())
	   //     {
	   //         mp[txt[j]]--;
	   //         if(mp[txt[j]] == 0)
	   //         {
	   //             count--;
	   //         }
	   //     }
	        
	   //     // Increasing Window Length
	   //     if(j - i + 1 < k)
	   //     {
	   //         j++;
	   //     }
	        
	   //     else if(j - i + 1 == k)
	   //     {
	   //         if(count == 0)
	   //         {
	   //             ans++;
	   //         }
	   //         if(mp.find(txt[i]) != mp.end())
	   //         {
	   //             mp[txt[i]]++;
	   //             if(mp[txt[i]] == 1)
	   //             {
	   //                 count++;
	   //             }
	   //         }
	   //         // Slide the window
	   //         i++;
	   //         j++;
	   //     }
	   // }
	   // return ans;
	   
	unordered_map<char, int> mp;
    int ans = 0;
    
    //storing the occ. of string p in the map
    for (auto &x : p){
        mp[x]++;
    }

    int count = mp.size();
    int k = p.size();
    int i=0, j=0;

    while (j < s.size()){
        //calculation part
        if (mp.find(s[j]) != mp.end()){
            mp[s[j]]--;
            if (mp[s[j]] == 0){
                count--;
            }
        }

        //window length not achived yet
        if (j-i+1 < k){
            j++;
        }

        //window length achived, find ans and slide the window
        else if (j-i+1 == k){
            //finding the ans
            if (count == 0){
                ans++;
            }
            if (mp.find(s[i]) != mp.end()){
                mp[s[i]]++;
                if (mp[s[i]] == 1){
                    count++;
                }
            }

            //slide the window
            i++;
            j++;
        }
    }
    return ans;
	}
