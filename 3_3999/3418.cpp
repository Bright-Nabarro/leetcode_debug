#include <bits/stdc++.h>
using namespace std;

void print_lists(auto& listsk)
{
	println("dp:");
	for (auto& lists : listsk)
	{
		for (auto& list : lists)
		{
		
			print("[");
			for (int x : list)
			{
				if (x == INT_MIN)
				{
					print("M ");
				}
				else
				{
					print("{} ", x);
				}
			}
			print("], ");
		}
		println("");
	}
}

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(3, INT_MIN)));
        dp[0][1][2] = dp[0][1][1] = dp[0][1][0] = 0;
        for (int i = 1; i <= m; ++i)
        {
			print_lists(dp);
            for (int j = 1; j <= n; ++j)
            {
                int value = coins[i-1][j-1];
                if (coins[i-1][j-1] >= 0)
                {
                    for (int t = 0; t < 3; ++t)
                    {
                        dp[i][j][t] = std::max(dp[i-1][j][t], dp[i][j-1][t]) + value;
                    }
                }
                else
                {
                    int max = std::max(dp[i-1][j][2], dp[i][j-1][2]);
                    dp[i][j][2] = max + value;
                    for (int t = 1; t >= 0; --t)
                    {
                        int tmax = std::max(dp[i-1][j][t], dp[i][j-1][t]);
                        dp[i][j][t] =  tmax+ value;
                        dp[i][j][t] = std::max(dp[i][j][t], max);
                        max = tmax;
                    }
                }
            }
        }

		print_lists(dp);
        return std::max({dp[m][n][0], dp[m][n][1], dp[m][n][2]});
    }
};

int main()
{
	Solution s{};
	std::vector<std::vector<int>> matrix = {
    	{10, 10, 10},
    	{10, 10, 10}
	};

	println("{}", s.maximumAmount(matrix));
}
