#include "../cvn.hpp"
class Solution {
public:
    inline static constexpr array<pair<int, int>, 4> offsets{
        pair {-1, 0},
        pair {0, -1},
        pair {0, 1},
        pair {1, 0},
    };

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size();
        int n = grid[0].size();
        vector visited(m, vector<uint8_t>(n, false));

        int value = grid[row][col];

        auto dfs = [&](this auto&& dfs, int x, int y) -> bool {
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != value)
                return true;
            if (visited[x][y])
                return false;

            visited[x][y] = true;
            for (auto [offx, offy] : offsets)
            {
                if (dfs(x+offx, y+offy))
                {
                    grid[x][y] = color;
                }
            }
			std::println("{} {}", x, y);
            return false;
        };

        dfs(row, col);
        return std::move(grid);
    }
};

int main()
{
	Solution s;
	VV v {{1,1,1},{1,1,1},{1,1,1}};
	auto n = s.colorBorder(v, 1, 1, 2);
	P2D(n);
}
