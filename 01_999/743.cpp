#include "../cvn.hpp"

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        //from -> to, cost
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto triple : times)
        {
            adj[triple[0]].emplace_back(triple[1], triple[2]);
        }

        vector<int> table(n+1, INT_MAX);
        auto cpr = [](const auto& lhs, const auto& rhs) -> bool{
            return lhs.second < rhs.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cpr)> que;
        que.emplace(k, 0);

        while(!que.empty())
        {
            auto [node, dist] = que.top();
            que.pop();

			println("node {}, dist {}", node, dist);

            if (dist > table[node])
                continue;

            for (auto [to, weight] : adj[node])
            {
				println("to {}, weight {}", to, weight);
                if (dist+weight < table[to])
                {
					println("insert into table");
                    table[to] = weight+dist;
                    que.emplace(to, weight+dist);
                }
            }
        }

        int max = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (table[i] == INT_MAX)
                return -1;
            max = std::max(max, table[i]);
        }
        return max;
    }
};

int main()
{
	Ss;
	VV v {{1,2,1}};
	auto n = s.networkDelayTime(v, 2, 1);
	PT(n);
}


