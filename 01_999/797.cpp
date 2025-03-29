#include "../cvn.hpp"
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> list;
        vector<uint8_t> traversed(n, false);
        vector<vector<int>> result;
        auto dfs = [&](this auto& dfs, int x) -> void
        {
            traversed[x] = true;
            for (int y : graph[x])
            {
                if (traversed[y])
                    continue;

                list.push_back(y);   
                if (y == n-1)
                    result.push_back(list);
                else
                    dfs(y);
                list.pop_back();
            }
        };

        return result;
    }
};

int main()
{
	Ss ;
	VV list {{1,2},{3},{3},{}};
	auto n = s.allPathsSourceTarget(list);
	P2D(n);

}
