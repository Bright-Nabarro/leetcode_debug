#include <print>
#include <numeric>

int main()
{
	std::println("{{");
	for (int i = 0; i < 10; ++i)
	{
		std::print("  array{{");
		for (int j = 0; j < 10; ++j)
		{
			std::print("{}, ", std::gcd(i, j));
		}
		std::println("}}");
	}
	std::println("}}");
}
