#include "../cvn.hpp"

class Solution {
public:
    void print2d(auto&& lists)
    {
        for (auto& list: lists)
        {
            for (auto n : list)
            {
				int min = n.first;
				if (min == INT_MAX)
				{
					min = -1;
				}
                print("{}:{} ", min, n.second);
            }
            println("");
        }
        println("");
    }

    inline static const array<pair<int, int>, 4> offsets {
        pair {-1, 0},
        pair {1, 0},
        pair {0, -1},
        pair {0, 1},
    };

    int minimumEffortPath(vector<vector<int>>& heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        vector<vector<pair<int, int>>> minmax(m, vector<pair<int, int>>(n, {INT_MAX, 0}));
        // cost, x, y
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> que;
        que.emplace(0, 0, 0);
        dist[0][0] = 0;
        minmax[0][0] = {heights[0][0], heights[0][0]};
        while(!que.empty())
        {
            auto[cost, x, y] = que.top();
            que.pop();

            for (auto [offx, offy] : offsets)
            {
                int xto = x+offx, yto = y+offy;
                if (0 <= xto && xto < n && 0 <= yto && yto < m)
                {
                    auto [minh, maxh] = minmax[x][y];
                    minh = std::min(minh, heights[xto][yto]);
                    maxh = std::max(maxh, heights[xto][yto]);
                    int spent = maxh - minh;
                    if (spent < dist[xto][yto])
                    {
						minmax[xto][yto] = {minh, maxh};
                        dist[xto][yto] = spent;
                        que.emplace(spent, xto, yto);
                    }
                }
            }
			print2d(minmax);
        }

        return dist[m-1][n-1];
    }
};

int main()
{
	Ss;
	VV v {{1,2,2},{3,8,2},{5,3,5}};
	PT(s.minimumEffortPath(v));
}
