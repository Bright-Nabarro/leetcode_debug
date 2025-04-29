#include "../cvn.hpp"

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums)
    {
        int size = nums.size();
        vector<int> tail, ret;
        ret.reserve(size);
        for (int num : nums)
        {
            auto itr = ranges::upper_bound(tail, num);
            int len = std::distance(tail.begin(), itr) + 1;
            if (itr == tail.end())
                tail.push_back(num);
            else
                *itr = num;

            ret.push_back(len);
        }

        return ret;
    }
};

int main()
{
	Solution s;
	V v { 1, 2, 3, 2 };
	s.longestObstacleCourseAtEachPosition(v);
}
