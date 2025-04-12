#include "../cvn.hpp"

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions)
    {
        int size = questions.size();
        vector dp(size+1, 0);
        for (int i = size-1; i >= 0; --i)
        {
            dp[i] = questions[i][0];
            int n = i + questions[i][1] + 1;
            if (n < size)
                dp[i] += dp[n];
            dp[i] = std::max(dp[i+1], dp[i]);
			P1D(dp);
        }

        return dp[0];
    }
};

int main()
{
	Ss;
	VV vec{{3,2},{4,3},{4,4},{2,5}};
	PT(s.mostPoints(vec));
}
