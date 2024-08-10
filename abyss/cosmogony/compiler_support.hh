/* SPDX-License-Identifier: BSD-3-Clause */
#pragma once
#if !defined(ABYSS_COSMOGONY_COMPILER_SUPPORT)
#define ABYSS_COSMOGONY_COMPILER_SUPPORT

/* /!\ ACHTUNG /!\ ACHTUNG /!\ ACHTUNG /!\ ACHTUNG /!\ ACHTUNG /!\ */
/*      THIS IS AN INTERNAL HEADER, DON'T INCLUDE IT DIRECTLY      */

/* This allows us to run tests on any fallback implementations we have as well */
// NOLINTNEXTLINE(cppcoreguidelines-macro-usage)
#define __ABYSS_HAS_BUILTIN(b) (__has_builtin(b) && !defined(__ABYSS_DEBUG_FALLBACK_IMPLS))

#endif /* ABYSS_COSMOGONY_COMPILER_SUPPORT */
/* vim: set ft=cpp ts=4 sw=4 noexpandtab: */
