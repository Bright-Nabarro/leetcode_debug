#include "../cvn.hpp"

class Solution {
public:
    int minimumSum(int n, int k) {
        vector<uint8_t> list(1276, false);

        int num = 1;
        int result = 0;
        for (int i = 0; i < n; ++i)
        {
            while (k - num >= 1 && list[k - num])
            {
                ++num;
            }
            for (int j = 1; j <= std::min(num, k); ++j)
            {
                if (list[j])
                    list[j+num] = true;
            }
			println("num: {}", num);
			list[num] = true;
            result += num;
			++num;

			println("list");
			for (int j = 1; j <= n; ++j)
			{
				print("{} ", list[j]);
			}
			println("");
        }

        return result;
    }
};

int main()
{
	Ss;
	PT(s.minimumSum(6, 6));
}
