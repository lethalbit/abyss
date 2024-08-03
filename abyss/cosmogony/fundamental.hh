/* SPDX-License-Identifier: BSD-3-Clause */
#pragma once
#if !defined(ABYSS_COSMOGONY_FUNDAMENTAL)
#define ABYSS_COSMOGONY_FUNDAMENTAL

/* /!\ ACHTUNG /!\ ACHTUNG /!\ ACHTUNG /!\ ACHTUNG /!\ ACHTUNG /!\ */
/*      THIS IS AN INTERNAL HEADER, DON'T INCLUDE IT DIRECTLY      */

/* NOTE(aki): ptrdiff_t, size_t, and nullptr_t are defined here for common inclusion internally */

namespace std {
#if defined(__PTRDIFF_TYPE__)
	using ptrdiff_t = __PTRDIFF_TYPE__;
#else
	using ptrdiff_t = decltype(static_cast<long*>(nullptr) - static_cast<long*>(nullptr));
#endif

#if defined(__SIZE_TYPE__)
	using size_t = __SIZE_TYPE__;
#else
	using size_t = decltype(sizeof(0ULL));
#endif

	using nullptr_t = decltype(nullptr);
}

#endif /* ABYSS_COSMOGONY_FUNDAMENTAL */
/* vim: set ft=cpp ts=4 sw=4 noexpandtab: */
