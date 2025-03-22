#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        vector<int> max_len;
        int max_w = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            int w = bit_width((unsigned)nums[i]);
            if (w > max_w)
            {
                max_len.clear();
                max_len.push_back(i);
                max_w = w;
            }
            else if (w == max_w)
            {
                max_len.push_back(i);
            }
        }

        long long result = 0;
        for (int i = 0; i < max_len.size(); ++i)
        {
            long long sum = 0;
            for (int j = 0; j < nums.size(); ++j)
            {
                if (i == j)
                {
                    sum |= ((long long)nums[i] << k);
                }
                else
                {
                    sum |= nums[i];
                }
            }
            result = std::max(sum, result);
        }

        return result;
    }
};

int main()
{
	Solution s{};
	vector list {12, 9};
	println("{}", s.maximumOr(list, 1));
}
