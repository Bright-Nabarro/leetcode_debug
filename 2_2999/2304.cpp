#include <bits/stdc++.h>
using namespace std;

void print2DArray(const std::vector<std::vector<int>>& arr) {
	println("dp:");
    for (const auto& row : arr) {  // 遍历每一行
        std::cout << "{";
        for (size_t i = 0; i < row.size(); ++i) {  // 遍历行中的每个元素
            std::cout << row[i];
            if (i < row.size() - 1) {  // 如果不是最后一个元素，加逗号
                std::cout << ", ";
            }
        }
        std::cout << "}" << std::endl;  // 每行结束打印大括号和换行
    }
}

class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
		for (int i = 0; i < n; ++i)
		{
			dp[0][i] = 0;
		}
		
		print2DArray(dp);
        for (int i = 0; i < m-1; ++i)
        {
			print2DArray(dp);
            for (int j = 0; j < n; ++j)
            {
                int value = grid[i][j];
                for (int k = 0; k < n; ++k)
                {
                    int cost = moveCost[value][k];
                    dp[i+1][k] = std::min(dp[i+1][k], cost + dp[i][j]);
                }
            }
        }
		print2DArray(dp);
        
        int result = INT_MAX;
        for (int i = 0; i < n; ++i)
        {
            result = std::min(dp[m-1][i], result);
        }

        return result;
    }
};

int main()
{
	Solution s;
	std::vector<std::vector<int>> arr1 = {{5, 3}, {4, 0}, {2, 1}};
	std::vector<std::vector<int>> arr2 = {{9, 8}, {1, 5}, {10, 12}, {18, 6}, {2, 4}, {14, 3}};
	println("{}", s.minPathCost(arr1, arr2));
}
