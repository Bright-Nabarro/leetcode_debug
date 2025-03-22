#include "../cvn.hpp"

class Solution
{
public:
	int lengthOfLongestSubsequence(vector<int>& nums, int target)
	{
		int len = nums.size();
		vector<vector<int>> dp(len + 1, vector<int>(target + 1, -1));
		dp[0][0] = 0;
		for (int i = 1; i <= len; ++i)
		{
			int value = nums[i - 1];
			for (int j = 0; j <= target; ++j)
			{
				if (j < value || dp[i-1][j - value] < 0)
				{
					dp[i][j] = dp[i-1][j];
					continue;
				}

				dp[i][j] = std::max(dp[i-1][j], dp[i-1][j - value] + 1);
			}
			print_2d(dp, "dp");
		}

		return dp[len][target];
	}
};

int main()
{
	Solution s;
	vector list {1,2,3,4,5};
	s.lengthOfLongestSubsequence(list, 9);
}
