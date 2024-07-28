/* SPDX-License-Identifier: BSD-3-Clause */

#include <abyss/cstdint>
#include <abyss/climits>

namespace details {
	/* NOTE(aki): This is a mangled version of the type_traits `bool_constant` */
	template<bool B>
	struct bool_const {
		static constexpr bool value = B;
		using value_type = bool;
		using type = bool;
		[[nodiscard]]
		constexpr operator bool() const noexcept { return value; }
		[[nodiscard]]
		constexpr value_type operator()() const noexcept { return value; }
	};

	/* NOTE(aki): We need to implement these so we don't drag type_traits in */
	template<typename T>
	struct is_signed : bool_const<T(-1) < T(0)> {};
	template<typename T>
	struct is_unsigned : bool_const<T(0) < T(-1)> {};

	template<typename T>
	inline constexpr bool is_signed_v = is_signed<T>::value;
	template<typename T>
	inline constexpr bool is_unsigned_v = is_unsigned<T>::value;
}

using details::is_signed_v;
using details::is_unsigned_v;

#if !defined(INT8_C)
#	error "INT8_C not defined"
#endif

#if !defined(UINT8_C)
#	error "UINT8_C not defined"
#endif

#if !defined(INT16_C)
#	error "INT16_C not defined"
#endif

#if !defined(UINT16_C)
#	error "UINT16_C not defined"
#endif

#if !defined(INT32_C)
#	error "INT32_C not defined"
#endif

#if !defined(UINT32_C)
#	error "UINT32_C not defined"
#endif

#if !defined(INT64_C)
#	error "INT64_C not defined"
#endif

#if !defined(UINT64_C)
#	error "UINT64_C not defined"
#endif

#if !defined(INTMAX_C)
#	error "INTMAX_C not defined"
#endif

#if !defined(UINTMAX_C)
#	error "UINTMAX_C not defined"
#endif

int main(int argc, char** argv) {
	/* XXX(aki): These tests assume CHAR_BIT is 8, which is fair but also bad */
	static_assert(CHAR_BIT == 8);

	/* Fixed width types */
	static_assert(sizeof(std::int8_t)  * CHAR_BIT ==  8);
	static_assert(sizeof(std::int16_t) * CHAR_BIT == 16);
	static_assert(sizeof(std::int32_t) * CHAR_BIT == 32);
	static_assert(sizeof(std::int64_t) * CHAR_BIT == 64);

	static_assert(is_signed_v<std::int8_t> );
	static_assert(is_signed_v<std::int16_t>);
	static_assert(is_signed_v<std::int32_t>);
	static_assert(is_signed_v<std::int64_t>);

	static_assert(sizeof(std::uint8_t)  * CHAR_BIT ==  8);
	static_assert(sizeof(std::uint16_t) * CHAR_BIT == 16);
	static_assert(sizeof(std::uint32_t) * CHAR_BIT == 32);
	static_assert(sizeof(std::uint64_t) * CHAR_BIT == 64);

	static_assert(is_unsigned_v<std::uint8_t> );
	static_assert(is_unsigned_v<std::uint16_t>);
	static_assert(is_unsigned_v<std::uint32_t>);
	static_assert(is_unsigned_v<std::uint64_t>);

	/* Smallest type capable of holding N-bits */
	static_assert(sizeof(std::int_least8_t)  * CHAR_BIT >=  8);
	static_assert(sizeof(std::int_least16_t) * CHAR_BIT >= 16);
	static_assert(sizeof(std::int_least32_t) * CHAR_BIT >= 32);
	static_assert(sizeof(std::int_least64_t) * CHAR_BIT >= 64);

	static_assert(is_signed_v<std::int_least8_t> );
	static_assert(is_signed_v<std::int_least16_t>);
	static_assert(is_signed_v<std::int_least32_t>);
	static_assert(is_signed_v<std::int_least64_t>);

	static_assert(sizeof(std::uint_least8_t)  * CHAR_BIT >=  8);
	static_assert(sizeof(std::uint_least16_t) * CHAR_BIT >= 16);
	static_assert(sizeof(std::uint_least32_t) * CHAR_BIT >= 32);
	static_assert(sizeof(std::uint_least64_t) * CHAR_BIT >= 64);

	static_assert(is_unsigned_v<std::uint_least8_t> );
	static_assert(is_unsigned_v<std::uint_least16_t>);
	static_assert(is_unsigned_v<std::uint_least32_t>);
	static_assert(is_unsigned_v<std::uint_least64_t>);

	/* Fastest type capable of holding N-bits */
	static_assert(sizeof(std::int_fast8_t)  * CHAR_BIT >=  8);
	static_assert(sizeof(std::int_fast16_t) * CHAR_BIT >= 16);
	static_assert(sizeof(std::int_fast32_t) * CHAR_BIT >= 32);
	static_assert(sizeof(std::int_fast64_t) * CHAR_BIT >= 64);

	static_assert(is_signed_v<std::int_fast8_t> );
	static_assert(is_signed_v<std::int_fast16_t>);
	static_assert(is_signed_v<std::int_fast32_t>);
	static_assert(is_signed_v<std::int_fast64_t>);

	static_assert(sizeof(std::uint_fast8_t)  * CHAR_BIT >=  8);
	static_assert(sizeof(std::uint_fast16_t) * CHAR_BIT >= 16);
	static_assert(sizeof(std::uint_fast32_t) * CHAR_BIT >= 32);
	static_assert(sizeof(std::uint_fast64_t) * CHAR_BIT >= 64);

	static_assert(is_unsigned_v<std::uint_fast8_t> );
	static_assert(is_unsigned_v<std::uint_fast16_t>);
	static_assert(is_unsigned_v<std::uint_fast32_t>);
	static_assert(is_unsigned_v<std::uint_fast64_t>);

	/* Types capable of holding at least platform pointer size */
	static_assert(sizeof(std::intptr_t)  >= sizeof(void*));
	static_assert(sizeof(std::uintptr_t) >= sizeof(void*));

	static_assert(is_signed_v<std::intptr_t>);
	static_assert(is_unsigned_v<std::uintptr_t>);

	/* Biggest integer types */

	static_assert(sizeof(std::intmax_t)  >= sizeof(long long));
	static_assert(sizeof(std::uintmax_t) >= sizeof(unsigned long long));

	static_assert(is_signed_v<std::intmax_t>);
	static_assert(is_unsigned_v<std::uintmax_t>);

	/* Max/Min values - Fixed-width */
	/* XXX(aki): These are also the same as our fallback values, so it's kinda cheating */

	static_assert(INT8_MAX  ==  127);
	static_assert(INT8_MIN  == -128);
	static_assert(UINT8_MAX ==  255);

	static_assert(INT16_MAX  ==  32767);
	static_assert(INT16_MIN  == -32768);
	static_assert(UINT16_MAX ==  65535);

	static_assert(INT32_MAX  ==  2147483647 );
	static_assert(INT32_MIN  == -2147483648 );
	static_assert(UINT32_MAX ==  4294967295U);

	static_assert(INT64_MAX  ==  9223372036854775807LL);
	static_assert(INT64_MIN  == -9223372036854775808LL);
	static_assert(UINT64_MAX ==  18446744073709551615ULL);

	/* Max/Min values - Smallest-width */

	static_assert(INT_LEAST8_MAX  >=  127);
	static_assert(INT_LEAST8_MIN  <= -128);
	static_assert(UINT_LEAST8_MAX >=  255);

	static_assert(INT_LEAST16_MAX  >=  32767);
	static_assert(INT_LEAST16_MIN  <= -32768);
	static_assert(UINT_LEAST16_MAX >=  65535);

	static_assert(INT_LEAST32_MAX  >=  2147483647 );
	static_assert(INT_LEAST32_MIN  <= -2147483648 );
	static_assert(UINT_LEAST32_MAX >=  4294967295U);

	static_assert(INT_LEAST64_MAX  >=  9223372036854775807LL);
	static_assert(INT_LEAST64_MIN  <= -9223372036854775808LL);
	static_assert(UINT_LEAST64_MAX >=  18446744073709551615ULL);

	/* Max/Min values - Fastest-type */

	static_assert(INT_FAST8_MAX  >=  127);
	static_assert(INT_FAST8_MIN  <= -128);
	static_assert(UINT_FAST8_MAX >=  255);

	static_assert(INT_FAST16_MAX  >=  32767);
	static_assert(INT_FAST16_MIN  <= -32768);
	static_assert(UINT_FAST16_MAX >=  65535);

	static_assert(INT_FAST32_MAX  >=  2147483647 );
	static_assert(INT_FAST32_MIN  <= -2147483648 );
	static_assert(UINT_FAST32_MAX >=  4294967295U);

	static_assert(INT_FAST64_MAX  >=   9223372036854775807L );
	static_assert(INT_FAST64_MIN  <=  -9223372036854775808L );
	static_assert(UINT_FAST64_MAX >=  18446744073709551615UL);

	/* TODO(aki): {,U}INTPTR_{MAX,MIN} PTRDIFF_{MAX,MIN}, SIZE_MAX, WCHAR_{MAX,MIN}, WINT_{MAX,MIN}, SIG_ATOMIC_{MAX,MIN} */

	return 0;
}
