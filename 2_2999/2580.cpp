#include "../cvn.hpp"
class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        ranges::sort(ranges, [](const auto& lhs, const auto& rhs){
            return lhs[0] < rhs[0];
        });

        int end = -1;
        int cnt = 0;
        for (auto& pair : ranges)
        {
            if (pair[0] <= end)
            {
                end = std::max(pair[1], end);
            }
            else
            {
                ++cnt;
            }
        }
        std::cout << "cnt: " << cnt << std::endl;
        long long  result = 1;
        constexpr int MOD = 1'000'000'007;
        for (int i = 0; i < cnt; ++i)
            result = result * 2 % MOD;
        return result;
    }
};

int main()
{
	Ss;
	VV list{{6,10}, {5,15}};
	PT(s.countWays(list));
}

