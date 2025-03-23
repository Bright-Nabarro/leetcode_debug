
#include "../cvn.hpp"

class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        using ll = long long;
        ll result = 0;
        for (auto& pair : queries){
			ll l = pair[0];
            ll r = pair[1];
            ll base = l/4 + 1;

			if ( l/4 == r/4)
			{
				result += ((r-l+1) * base + 1) / 2;
				continue;
			}
            ll l_start = 4 - l % 4;
			
            ll r_end = r % 4 + 1;
            ll diff = (r - l +1) - l_start - r_end;

            ll beg = l_start * base;
            ll n = diff / 4;
            ll mid = n * (base+1 + n - 1);
            ll end = n * (base+1) * r_end;
            ll sum = beg + mid + end;
            sum = (sum + 1) / 2;
            result += sum;
        }
        return result;
    }
};

int main()
{
	VV list {{1,2}, {2,4}};
	Ss;
	println("{}", s.minOperations(list));
}
