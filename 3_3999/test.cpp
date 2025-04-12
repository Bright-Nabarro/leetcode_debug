#include <set>
#include <print>

int main()
{
	std::set s{1};
	auto start = s.lower_bound(1);
}
