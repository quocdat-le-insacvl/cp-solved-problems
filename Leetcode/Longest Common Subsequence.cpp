class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        vector<vector<int>> dp(len1, vector<int>(len2));
        auto is_valid = [&](int ni, int nj){
            return ni>=0 && ni < len1 && nj >=0 && nj < len2;
        };
        for(int i=0; i<len1; i++) {
            for (int j=0; j<len2; j++) {

                if (text1[i] == text2[j]) {
                    if (!is_valid(i-1, j-1)) {
                        dp[i][j] = 1;
                    } else{
                        dp[i][j] = dp[i-1][j-1] + 1;
                    }
                } else {
                    if (is_valid(i-1, j)){
                        dp[i][j] = max(dp[i][j], dp[i-1][j]);
                    }
                    if (is_valid(i, j-1)) {
                        dp[i][j] = max(dp[i][j], dp[i][j-1]);
                    }
                }
            }
        }
        return dp[len1-1][len2-1];
    }
};