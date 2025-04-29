#include "../cvn.hpp"
class Solution {
public:
    inline static constexpr array<pair<int, int>, 4> offsets{
        pair {-1, 0},
        pair {0, -1},
        pair {0, 1},
        pair {1, 0},
    };

    int islandPerimeter(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        auto dfs = [&](this auto&& dfs, int x, int y) -> int {
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0)
            {
                std::println("{} {}", x, y);
                return 1;
            }
            if (grid[x][y] == -1)
                return 0;

            grid[x][y] = -1;

            int ret = 0;
            for (auto [offx, offy] : offsets)
            {
                std::println("off {} {}", offx, offy);
                ret += dfs(x+offx, y+offx);
            }
            return ret;
        };

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    return dfs(i, j);
                }
            }
        }
        return 0;
    }
};

int main()
{
	Ss;
	VV v {{1}};
	auto n = s.islandPerimeter(v);
	PT(n);
}

