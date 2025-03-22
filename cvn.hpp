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
			print("{} ", n);
		}
		println("");
	}
}
