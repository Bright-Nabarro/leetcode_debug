#include "../cvn.hpp"

class Solution {
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> result;
        array<int, 26> cnt_p;
        array<int, 26> cnt_s;
        for (char c : p)
            ++cnt_p[c - 'a'];
        
        for (int right = 0; right < s.length(); ++right)
        {
            cnt_s[s[right] - 'a']++;
            int left = right - p.length() + 1;
            if (left < 0)
                continue;

            if (cnt_s == cnt_p)
                result.push_back(left);
            --cnt_s[s[left]-'a'];
        }

        return result;
    }
};

int main()
{
	Ss;
	auto ret = s.findAnagrams("cbaebabacd", "abc");
	P1D(ret);
}
