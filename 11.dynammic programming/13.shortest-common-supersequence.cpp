class Solution {
    public:
        string shortestCommonSupersequence(string str1, string str2) {
    
            int n = str1.size();
            int m = str2.size();
    
            vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN));
    
            for (int i = 0; i <= n; i++) {
                dp[i][0] = 0;
            }
    
            for (int j = 0; j <= m; j++) 
            {
                dp[0][j] = 0;
            }
    
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (str1[i - 1] == str2[j - 1]) {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
    
            int i = n;
            int j = m;
            int len = dp[i][j];
            string lcs(len, '\0');
            while (i > 0 && j > 0) {
                if (str1[i - 1] == str2[j - 1]) {
                    lcs[len - 1] = str1[i - 1];
                    len--;
                    i--;
                    j--;
                }
                else {
                    if (dp[i - 1][j] > dp[i][j - 1]) {
                        i--;
                    } else {
                        j--;
                    }
                }
            }
    
           
            len = dp[n][m];
            string output((n + m) - len, '\0');
            i = 0;
            j = 0;
            int k = 0;
            int lcsLn=0;
            while (i < n && j < m && lcsLn < len) {
                if (lcs[lcsLn] == str1[i] && lcs[lcsLn] == str2[j]) {
                    output[k] = str1[i];
                    i++;
                    j++;
                    k++;
                    lcsLn++;
                } else if (lcs[lcsLn] == str1[i]) {
                    output[k] = str2[j];
                    j++;
                    k++;
                } else {
                    output[k] = str1[i];
                    i++;
                    k++;
                }
            }
    
    
            while (i < n) {
                output[k] = str1[i];
                i++;
                k++;
            }
    
            while (j < m) {
                output[k] = str2[j];
                j++;
                k++;
            }
    
            return output;
        }
    };