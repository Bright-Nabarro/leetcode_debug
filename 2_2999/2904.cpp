#include "../cvn.hpp"

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int min = INT_MAX;
        int rl, rlen;
        int cnt = 0, len = s.size();
        int left = 0, right = 0;
        for (; right < len; ++right)
        {
            if (s[right] == '1')
                ++cnt;
            
            while (cnt > k)
            {
                if (s[left] == '1')
                    --cnt;
                ++left;
            }

            if (cnt == k)
            {
                while(s[left] == '0' && left < right)
                    ++left;
                int n = right - left + 1;
                if (n < min)
                {
                    min = n;
                    rl = left;
                    rlen = n;
                }
            }
        }
        return s.substr(rl, rlen);
    }
};

int main()
{
	Ss;
	auto r = s.shortestBeautifulSubstring("000", 1);
	PT(r);
}
