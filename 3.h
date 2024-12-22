#pragma once

#include <iostream>
#include <algorithm>
#include <string_view>
#include <ranges>
#include <deque>
#include <charconv>
#include <cassert>
#include <random>

#include <optional>

struct res_
{
	int c = NULL;
	bool right = true;
};

/*std::optional<int>*/ res_ genRand(std::string_view lim);