#include "../cvn.hpp"
class Solution {
public:
    inline static const array<pair<int, int>, 4> offsite {
        pair{-1, 0}, pair{1, 0}, pair{0, -1}, pair{0, 1}
    };

    int minTimeToReach(vector<vector<int>>& moveTime)
    {
        int n = moveTime.size();
        int m = moveTime[0].size();
        auto cpr = [](const tuple<int, int, int>& lhs, const tuple<int, int, int>& rhs) -> bool {
            return std::get<0>(lhs) > std::get<0>(rhs);
        };
    
        // x, y, time
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cpr)> que;
        vector table(n, vector(m, INT_MAX));
        table[0][0] = 0;
        que.emplace(0, 0, 0);
        while(!que.empty())
		{
			P2D(table);
			auto [x, y, time] = que.top();
			que.pop();
			if (time > table[x][y])
				continue;

			for (auto [xoff, yoff] : offsite)
			{
				int nx = x + xoff, ny = y + yoff;
				if (0 <= nx && nx < n && 0 <= ny && ny < m)
				{
					int value = std::max(time + 1, moveTime[nx][ny] + 1);
					if (value < table[nx][ny])
					{
						table[nx][ny] = value;
						que.emplace(nx, ny, value);
					}
				}
			}
		}
		P2D(table);

        return table[n-1][m-1];
    }
};

int main()
{
	Ss;
	VV v{{27, 85},{22, 53}};
	auto n = s.minTimeToReach(v);
	PT(n);
}
