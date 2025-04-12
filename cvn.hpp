#pragma once
#include <bits/stdc++.h>
using namespace std;

void print_2d(auto& lists, string_view sv)
{
	println("{}", sv);
	for (auto& list : lists)
	{
		for (auto n : list)
		{
			if constexpr(std::is_integral_v<decltype(n)>)
			{
				if (n == INT_MAX)
				{
					print("{} ", "inf");
					continue;
				}
			}
			print("{} ", n);
		}
		println("");
	}
}

void print_1d(auto& lists, string_view sv)
{
	println("{}", sv);
	for(int i = 0; i < lists.size(); ++i)
	{
		if constexpr (std::is_integral_v<
						decay_t<decltype(lists[0])>
					  >)
		{
			if (lists[i] == INT_MAX)
			{
				print("[{}] inf ", i);
				continue;
			}
		}
		print("[{}]: {}, ", i, lists[i]);
	}
	println("");
}

using V = vector<int>;
using VV = vector<vector<int>>;

#define Ss Solution s{};

#define P2D(lists) print_2d(lists, #lists);
#define P1D(lists) print_1d(lists, #lists);

#define PT(ret) std::println("{}", (ret));
