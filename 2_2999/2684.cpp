#include <bits/stdc++.h>
using namespace std;

void print_blists(auto& lists)
{
	println("dp");
	for (auto& list : lists)
	{
		for (auto& n : list)
		{
			if (n) 	print("true  ");
			else 	print("false ");
		}
		println("");
	}
}

class Solution
{
public:
	int maxMoves(vector<vector<int>>& grid)
	{
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<uint8_t>> dp(m, vector<uint8_t>(n, false));
		int result = 0;
		for (int i = 0; i < m; ++i)
			dp[i][0] = true;
		for (int y = 0; y < n - 1; ++y)
		{
			print_blists(dp);
			for (int x = 0; x < m; ++x)
			{
				if (!dp[x][y])
					continue;

				int value = grid[x][y];
				if (x > 0 && value < grid[x - 1][y + 1])
				{
					dp[x - 1][y + 1] = true;
				}
				if (value < grid[x][y + 1])
				{
					dp[x][y + 1] = true;
				}
				if (x < m - 1 && value < grid[x + 1][y + 1])
				{
					dp[x + 1][y + 1] = true;
				}

				result = y + 1;
			}
		}
		print_blists(dp);

		return result;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> list {{1000000,92910,1021},{1069,1070,1071}};
	println("{}", s.maxMoves(list));
}
