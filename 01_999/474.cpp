#include "../cvn.hpp"
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
		int len = strs.size();

		vector<vector<vector<int>>> dp(len+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));

		for (int i = 1; i <= len; ++i)
		{
			int zero = 0, one = 0;
			for (char c : strs[i-1])
			{
				if (c == '0')
					++zero;
				else
					++one;
			}
			
			for (int j = 0; j <= m; ++j)
			{
				for (int k = 0; k <= n; ++k)
				{
					if (j < zero || k < one)
						dp[i][j][k] = dp[i-1][j][k];
					else
						dp[i][j][k] = std::max(dp[i-1][j][k], dp[i-1][j-zero][k-one]+1);
				}
			}
		}
		return dp[len][m][n];
    }
};

int main()
{
	Ss;
	vector<string> list {"10", "0001", "111001", "1", "0"};
	int m = 5;
	int n = 3;
	println("{}", s.findMaxForm(list, m, n));
}
