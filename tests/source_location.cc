/* SPDX-License-Identifier: BSD-3-Clause */

#include <abyss/source_location>

// NOLINTNEXTLINE(readability-named-parameter)
int main(int, char**) {
	/*                                               ↓ Col 50 (tab is 1 char, not 4)*/
	constexpr auto loc{std::source_location::current()};

	static_assert(loc.line() == 8);
#if __ABYSS_DEBUG_FALLBACK_IMPLS
	/* NOTE(aki): We don't get column information in our fallback impl */
	static_assert(loc.column() == 0);
#elif defined(__clang__)
	/* Clang defines it from the identifier assignment, not the invocation point */
	static_assert(loc.column() == 21);
#elif defined(__GNUG__)
	static_assert(loc.column() == 50);
#endif
	/* There should be more tests, but  */

	return 0;
}
