#include "../cvn.hpp"
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        vector dp(len1+1, vector(len2+1, 0));
        for (int i = 1; i <= len1; ++i)
        {
            dp[i][0] = (int)s1[i-1];
        }
        for (int i = 1; i <= len2; ++i)
        {
            dp[0][i] = (int)s2[i-1];
        }

        for (int i = 1; i <= len1; ++i)
        {
            for (int j = 1; j <= len2; ++j)
            {
                int c1 = s1[i-1];
                int c2 = s2[j-1];
                if (c1 == c2)
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = std::min(dp[i-1][j]+c1, dp[i][j-1]+c2);
                }
            }
			P2D(dp);
        }

        return dp[len1][len2];
    }
};

int main()
{
	Ss;
	s.minimumDeleteSum("delete", "leet");
}

