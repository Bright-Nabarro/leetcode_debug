#include "../cvn.hpp"

class Solution {
public:
    int minDistance(string word1, string word2)
    {
        int len1 = word1.size();
        int len2 = word2.size();
        vector dp(len1+1, vector(len2+1, 0));
        for (int i = 1; i <= len1; ++i)
            dp[i][0] = i;
        for (int i = 1; i <= len2; ++i)
            dp[0][i] = i;

        for (int i = 1; i <= len1; ++i)
        {
            for (int j = 1; j <= len2; ++j)
            {
                if (word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                    continue;
                }

                dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]);
                if (i != j)
                    dp[i][j] += 1;
            }
			P2D(dp);
        }

        return dp[len1][len2];
    }
};

int main()
{
	Ss;
	PT (s.minDistance("intention", "execution"));

}
