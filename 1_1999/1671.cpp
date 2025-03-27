#include "../cvn.hpp"

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int size = nums.size();
        vector pre (size, 1);
        vector post (size, 1);
        for (int i = 1; i < size; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                    pre[i] = std::max(pre[i], pre[j]+1);
            }
        }
		P1D(pre);

        for (int i = size-2; i >= 0; --i)
        {
            for (int j = size-1; j > i; --j)
            {
                if (nums[j] < nums[i])
                    post[i] = std::max(post[i], post[j]+1);
            }
        }
		P1D(post);

        int result = size;
        for (int i = 0; i < size; ++i)
        {
			if (pre[i] == 1 || post[i] == 1)
				continue;
            result = std::min(result, size + 1 - post[i] - pre[i]);
        }

        return result;
    }
};

int main()
{
	Ss;
	vector list {100,92,89,77,74,66,64,66,6};
	PT(s.minimumMountainRemovals(list));
}
