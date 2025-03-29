#include "../cvn.hpp"

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        ranges::sort(nums);
        int size = nums.size();
        vector<unsigned long long> list(size+1, 0);
        for (int i = 1; i <= size; ++i)
        {
            list[i] = list[i-1] + nums[i-1];
        }

        int i;
        for (i = size-1; i >= 0; --i)
        {
            if (nums[i] < list[i])
                break;
        }
        if (i < 0)
            return -1;

        return list[i+1];
    }
};

int main()
{
	Ss;
	V list {5,5,5};
	PT(s.largestPerimeter(list));
}
