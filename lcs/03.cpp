#include "../cvn.hpp"

class Solution {
public:
    inline static constexpr array<pair<int, int>, 4> offsets {
        pair {-1, 0},
        pair {0, -1},
        pair {0, 1},
        pair {1, 0}
    };
    int largestArea(vector<string>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        auto dfs = [&](this auto&& dfs, int x, int y, char value)-> int{
            if (grid[x][y] == '.' || grid[x][y] == '0' || grid[x][y] != value)
                return 0;
            grid[x][y] = '.';
            int ret = 1;
            for (auto [offx, offy] : offsets)
            {
                int nx = x+offx, ny = y+offy;
                if (0 <= nx && nx < m && 0 <= ny && ny < n)
                {
                    ret += dfs(nx, ny, value);
                }
            }
            return ret;
        };
        for (int i = 0; i < n; ++i)
        {
            if (grid[0][i] != '.' && grid[0][i] != '0')
                dfs(0, i, grid[0][i]);
            if (grid[m-1][i] != '.' && grid[m-1][i] != '0')
                dfs(0, i, grid[m-1][i]);
        }
		P2D(grid);
		println("--");

        for (int i = 1; i < m-1; ++i)
        {
            if (grid[i][0] != '.'&& grid[i][0] != '0')
                dfs(i, 0, grid[i][0]);
            if (grid[i][n-1] != '.' && grid[i][n-1] != '0')
                dfs(i, n-1, grid[i][n-1]);
        }
		P2D(grid);
        int result = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '0')
                {
                    for (auto [offx, offy] : offsets)
                    {
                        int nx = i+offx, ny = j+offy;
                        if (0 <= nx && nx < m && 0 <= ny && ny < n)
                        {
                            dfs(nx, ny, grid[nx][ny]);
                        }
                    }           
                }
                if (grid[i][j] != '.')
                {
                    result = std::max(result, dfs(i, j, grid[i][j]));
                }
            }
			P2D(grid);
        }

        return result;
    }
};

int main()
{
	Ss;
	vector<string> v {"111","222","333"};
	auto n = s.largestArea(v);
	PT(n);
}
