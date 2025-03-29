#include "../cvn.hpp"

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2 != 0)
            return {};
        
        double dn = (sqrt(4.*finalSum + 1.) - 1.)/2.;
        long long n = ceil(dn);

        vector<long long> result;
        long long bias = 2;
        long long remove = n*n + n - finalSum;
        for (int i = 0; i < n; ++i, bias += 2)
        {
            if (bias == remove)
                continue;
            result.push_back(bias);
            bias += 2;
        }

        return result;
    }
};

int main()
{
	Ss;
	auto n = s.maximumEvenSplit(28);
	P1D(n);
}
