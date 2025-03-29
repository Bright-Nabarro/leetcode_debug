#include "../cvn.hpp"

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<uint8_t> traversed(n, false);
        if (source == destination) [[unlikely]]
            return true;
        auto dfs = [&](this auto& dfs, int x) -> bool
        {
            traversed[x] = true;
            for (auto& pair : edges)
            {
                if (pair[0] != x || traversed[pair[1]])
                    continue;
                if (pair[1] == destination)
                    return true;
                return dfs(pair[1]);
            }
            return false;
        };

        return dfs(source);
    }
};

int main()
{
	Ss;
	VV list {{0,7},{0,8},{6,1},{2,0},{0,4},{5,8},{4,7},{1,3},{3,5},{6,5}};
	PT(s.validPath(10, list, 7, 5));
}
