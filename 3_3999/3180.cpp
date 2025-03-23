#include "../cvn.hpp"

class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues)
    {
        ranges::sort(rewardValues);
        int len = rewardValues.size();
        int limit = ranges::max(rewardValues) * 2;
        vector<vector<uint8_t>> dp(len+1, vector<uint8_t>(limit, false));
        dp[0][0] = true;
        for (int i = 0; i < len; ++i)
        {
            int value = rewardValues[i];
            for (int j = 0; j < limit; ++j)
            {
                if (!dp[i][j] || j >= value)
                {
                    dp[i+1][j] = dp[i+1][j] ? true : dp[i][j];
                    continue;
                }
                dp[i+1][j] = true;
                if (j + value < limit)
                    dp[i+1][j+value] = true;
            }
        }

        int result = 0;
        for (int i = 0; i < limit; ++i)
        {
            if (dp[len][i])
                result = i;
        }
        return result;
        
    }
};

int main()
{
	Solution s;
	vector<int> list { 1, 6, 4, 3, 2 };
	s.maxTotalReward(list);
}
