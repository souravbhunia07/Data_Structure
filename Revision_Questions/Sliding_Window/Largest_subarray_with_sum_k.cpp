// Works in case of positive integer only
int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        int i = 0, j = 0, mx = 0;
        long long sum = 0;
        
        while(j < N)
        {
            sum += A[j];  // Calculation
            if(sum < K)  // Adjust Window
            {
                j++;
            }
            else if(sum == K)
            {
                mx = max(mx, j - i + 1); // Finding length
                j++;
            }
            else if(sum > K)
            {
                while(sum > K)
                {
                    sum -= A[i];
                    i++;
                }
                if(sum == K)
                {
                    mx = max(mx, j - i + 1); // Finding length
                }
                j++;
            }
        }
        return mx;
    } 
