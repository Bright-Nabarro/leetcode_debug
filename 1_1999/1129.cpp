#include "../cvn.hpp"

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
        vector<vector<int>>& blueEdges)
    {
        vector<vector<int>> redadj(n);
        vector<vector<int>> blueadj(n);
        for (const auto& pair : redEdges)
        {
            redadj[pair[0]].push_back(pair[1]);
        }
        for (const auto& pair : blueEdges)
        {
            blueadj[pair[0]].push_back(pair[1]);
        }

        // node, dist, b/r
        queue<tuple<int, int, char>> que;
        vector<int> answer(n, -1);
        que.emplace(0, 0, 'r');
        que.emplace(0, 0, 'b');
        answer[0] = 0;

        auto loop = [&](const auto& list, char c, int dist) -> void
        {
            for (int to : list)
            {
                if (answer[to] < 0)
                {
                    answer[to] = dist+1;
                    que.emplace(to, dist+1, c);
                }
            }
        };

        while(!que.empty())
        {
            auto [node, dist, color] = que.front();
            que.pop();
            std::println("node {}, dist {}, color {}", node, dist, color);

            if (color == 'b')
            {
                loop(redadj[node], 'r', dist);
            }
            else
            {
                loop(blueadj[node], 'b', dist);
            }
        }

        return answer;
    }
};

int main()
{
	Ss;
	VV red {{0,1},{1,2},{2,3},{3,4}};
	VV blue {{1,2},{2,3},{3,1}};
	auto ret = s.shortestAlternatingPaths(5, red, blue);
	P1D(ret);
}
