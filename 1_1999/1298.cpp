#include "../cvn.hpp"
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes, vector<int>& initialBoxes)
    {
        int n = status.size();
        vector<uint8_t> blocking(n, false);
        vector<uint8_t> storekeys(n, false);
        int result = 0;
        queue<int> que;
        for (int node : initialBoxes)
            que.push(node);

        while(!que.empty())
        {
            int node = que.front();
            que.pop();

            if (status[node] == 0 && !storekeys[node])
            {
                blocking[node] = true;
                continue;
            }
            result += candies[node];
            
            for (int child : containedBoxes[node])
            {
                que.push(child);
            }

            for (int key : keys[node])
            {
                std::println("key {}", key);
                storekeys[key] = true;
                if (blocking[node])
                {
                    std::println("node {} blocking", node);
                    blocking[node] = false;
                    que.push(node);
                }
            }
        }

        return result;
    }
};

int main()
{
	Ss;
	V status {1,0,1,0};
	V candies {7,5,4,100};
	VV keys {{},{},{1}, {}};
	VV cantain {{1,2},{3},{},{}};
	V init {0};
	PT(s.maxCandies(status, candies, keys, cantain, init));
}

