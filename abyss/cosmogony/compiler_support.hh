/* SPDX-License-Identifier: BSD-3-Clause */
#pragma once
#if !defined(ABYSS_COSMOGONY_COMPILER_SUPPORT)
#define ABYSS_COSMOGONY_COMPILER_SUPPORT

/* /!\ ACHTUNG /!\ ACHTUNG /!\ ACHTUNG /!\ ACHTUNG /!\ ACHTUNG /!\ */
/*      THIS IS AN INTERNAL HEADER, DON'T INCLUDE IT DIRECTLY      */

// NOLINTBEGIN(cppcoreguidelines-macro-usage)

#if defined(__GNUG__) || defined(__clang__)
#	pragma GCC system_header
#endif

/* This allows us to run tests on any fallback implementations we have as well */
#if !defined(__ABYSS_DEBUG_FALLBACK_IMPLS)
#	define __ABYSS_DEBUG_FALLBACK_IMPLS 0
#endif
#define __ABYSS_HAS_BUILTIN(b) (!__ABYSS_DEBUG_FALLBACK_IMPLS && __has_builtin(b))

/* Allows us to defined pragmas via a macro */
#if defined(__GNUC__) || defined(__clang__)
#	define __ABYSS_PRAGMA_(p) _Pragma(#p)
#	define __ABYSS_PRAGMA(p) __ABYSS_PRAGMA_(p)
#else
# 	define __ABYSS_PRAGMA(p)
#endif

#if defined(__GNUG__) && !defined(__clang__)
#	define __ABYSS_DIAGNOSTICS_PUSH() __ABYSS_PRAGMA(GCC diagnostic push)
#	define __ABYSS_DIAGNOSTICS_POP()  __ABYSS_PRAGMA(GCC diagnostic pop)
#	define __ABYSS_DIAGNOSTICS_IGNORE(DIAG_NAME) __ABYSS_PRAGMA(GCC diagnostic ignored DIAG_NAME)
#	define __ABYSS_POISON(IDENT) __ABYSS_PRAGMA(GCC poison IDENT)
#elif defined(__clang__)
#	define __ABYSS_DIAGNOSTICS_PUSH()     \
	__ABYSS_PRAGMA(clang diagnostic push) \
	__ABYSS_DIAGNOSTICS_IGNORE("-Wunknown-warning-option")
#	define __ABYSS_DIAGNOSTICS_POP()  __ABYSS_PRAGMA(clang diagnostic pop)
#	define __ABYSS_DIAGNOSTICS_IGNORE(DIAG_NAME) __ABYSS_PRAGMA(clang diagnostic ignored DIAG_NAME)
#	define __ABYSS_POISON(IDENT) __ABYSS_PRAGMA(clang poison IDENT)
#else
#	define __ABYSS_DIAGNOSTICS_PUSH()
#	define __ABYSS_DIAGNOSTICS_POP()
#	define __ABYSS_DIAGNOSTICS_IGNORE(DIAG_NAME)
#	define __ABYSS_POISON(IDENT)
#endif

/* Shorthand for a single diagnostic push/ignore */
#define __ABYSS_DIAGNOSTICS_IGNORE_ONE(DIAG_NAME) 	\
	__ABYSS_DIAGNOSTICS_PUSH()						\
	__ABYSS_DIAGNOSTICS_IGNORE(DIAG_NAME)


/* NOTE(aki): We don't enable this for now, we want to see compiler diagnostics */
#if !defined(__ABYSS_ENABLE_SYSTEM_HEADERS)
#	define __ABYSS_ENABLE_SYSTEM_HEADERS 0
#endif

#if (defined(__GNUG__) || defined(__clang__)) && __ABYSS_ENABLE_SYSTEM_HEADERS
#	define __ABYSS_SYSTEM_HEADER() __ABYSS_PRAGMA(GCC system_header)
#else
#	define __ABYSS_SYSTEM_HEADER()
#endif

// NOLINTEND(cppcoreguidelines-macro-usage)

#endif /* ABYSS_COSMOGONY_COMPILER_SUPPORT */
/* vim: set ft=cpp ts=4 sw=4 noexpandtab: */
