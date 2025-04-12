#include "../cvn.hpp"

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear)
    {
        // from -> to : cost
        vector<vector<pair<int, int>>> adj(n);
        for (auto& triple : edges)
        {
            adj[triple[0]].emplace_back(triple[1], triple[2]);
            adj[triple[1]].emplace_back(triple[0], triple[2]);
        }

        vector<int> dist(n, -1);

        // node, cost
        vector<uint8_t> visited(n, false);
        dist[0] = 0;
        
        for (int i = 0; i < n; ++i)
        {
            int min = INT_MAX;
            int min_idx = -1;
            for (int node = 0; node < n; ++node)
            {
                if (!visited[node] && dist[node] >= 0 && dist[node] < min)
                {
                    min_idx = node;
                    min = dist[node];
                }
            }
            std::println("min_idx {}", min_idx);
            for (int j = 0; j < n; ++j)
            {
                std::print("[{}]:{} ", j, dist[j]);
            }
            std::println("");

            if (min_idx < 0)
                break;

            visited[min_idx] = true;
            if (min >= disappear[min_idx])
			{
                dist[min_idx] = -1;
				continue;
			}
            for (auto [to, weight] : adj[min_idx])
            {
                if (!visited[to])
                {
                    int value = dist[min_idx] + weight;
                    if (dist[to] >= 0)
                        value = std::min(value, dist[to]);
                    dist[to] = value;
                }
            }
        }
        return dist;
    }
};

int main()
{
	Ss;
	VV edges {{0,1,2}, {1,2,1}, {0,2,4}};
	V disapper {1,1,5};
	auto v = s.minimumTime(3, edges, disapper);
	P1D(v);
}
