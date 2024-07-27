/* SPDX-License-Identifier: BSD-3-Clause */

#include <abyss/climits>

/* This is silly but the only real way to test it to make sure the defines are there */

#if !defined(MB_LEN_MAX)
#	error "MB_LEN_MAX not defined"
#endif

#if !defined(INT_MAX)
#	error "INT_MAX not defined"
#endif

#if !defined(INT_MIN)
#	error "INT_MIN not defined"
#endif

#if !defined(UINT_MAX)
#	error "UINT_MAX not defined"
#endif

static_assert(INT_MAX > INT_MIN);
static_assert(UINT_MAX > INT_MAX);

#if !defined(SHRT_MAX)
#	error "SHRT_MAX not defined"
#endif

#if !defined(SHRT_MIN)
#	error "SHRT_MIN not defined"
#endif

#if !defined(USHRT_MAX)
#	error "USHRT_MAX not defined"
#endif

static_assert(SHRT_MAX > SHRT_MIN);
static_assert(USHRT_MAX > SHRT_MAX);

#if !defined(LONG_MAX)
#	error "LONG_MAX not defined"
#endif

#if !defined(LONG_MIN)
#	error "LONG_MIN not defined"
#endif

#if !defined(ULONG_MAX)
#	error "ULONG_MAX not defined"
#endif

static_assert(LONG_MAX > LONG_MIN);
static_assert(ULONG_MAX > LONG_MAX);

#if !defined(LLONG_MAX)
#	error "LLONG_MAX not defined"
#endif

#if !defined(LLONG_MIN)
#	error "LLONG_MIN not defined"
#endif

#if !defined(ULLONG_MAX)
#	error "ULLONG_MAX not defined"
#endif

static_assert(LLONG_MAX > LLONG_MIN);
static_assert(ULLONG_MAX > LLONG_MAX);

#if !defined(SCHAR_MIN)
#	error "SCHAR_MIN not defined"
#endif

#if !defined(SCHAR_MAX)
#	error "SCHAR_MAX not defined"
#endif

#if !defined(UCHAR_MAX)
#	error "UCHAR_MAX not defined"
#endif

static_assert(SCHAR_MAX > SCHAR_MIN);
static_assert(UCHAR_MAX > SCHAR_MAX);

#if !defined(CHAR_MIN)
#	error "CHAR_MIN not defined"
#endif

#if !defined(CHAR_MAX)
#	error "CHAR_MAX not defined"
#endif

static_assert(CHAR_MAX > CHAR_MIN);
static_assert(UCHAR_MAX > CHAR_MAX);

#if !defined(CHAR_BIT)
#	error "CHAR_BIT not defined"
#endif

int main(int argc, char** argv) {
	return 0;
}
