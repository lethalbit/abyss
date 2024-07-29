/* SPDX-License-Identifier: BSD-3-Clause */

#include <abyss/source_location>

// NOLINTNEXTLINE(readability-named-parameter)
int main(int, char**) {
	/*                                               ↓ Col 50 (tab is 1 char, not 4)*/
	constexpr auto loc{std::source_location::current()};

	static_assert(loc.line() == 8);
	static_assert(loc.column() == 50);
	/* There should be more tests, but  */

	return 0;
}
