class Solution
{
    public:
    
        void computeLPS(string &pat, vector<int> &LPS) 
        {
            int m = pat.size();
            LPS.resize(m); 
            LPS[0] = 0;
            int len = 0, i = 1;
            
            while(i < m) {
                if(pat[i] == pat[len]) {
                    len++;
                    LPS[i] = len;
                    i++;
                } else {
                    if(len != 0) {
                        len = LPS[len - 1];
                    } else {
                        LPS[i] = 0;
                        i++;
                    }
                }
            }
        }
    
        vector <int> search(string pat, string txt)
        {
            int n = txt.size(), m = pat.size();
            vector<int> result;
            if (m == 0 || n == 0) return result;
    
            vector<int> LPS;
            computeLPS(pat, LPS);
            
            int i = 0, j = 0;
            while (i < n) {
                if (txt[i] == pat[j]) {
                    i++;
                    j++;
                }
                if (j == m) { 
                    result.push_back(i - m + 1);
                    j = LPS[j - 1];
                } else if (i < n && txt[i] != pat[j]) {
                    if (j != 0)
                        j = LPS[j - 1];
                    else
                        i++;
                }
            }
            
            return result;
        }
     
};
