/* SPDX-License-Identifier: BSD-3-Clause */

#include <abyss/limits>

template<typename _Ty>
constexpr bool is_specialized() noexcept {
	return (
		std::numeric_limits<_Ty>::is_specialized &&
		std::numeric_limits<const _Ty>::is_specialized &&
		std::numeric_limits<volatile _Ty>::is_specialized &&
		std::numeric_limits<const volatile _Ty>::is_specialized
	);
}

template<typename _Ty>
constexpr bool is_signed() noexcept {
	return (
		std::numeric_limits<_Ty>::is_signed &&
		std::numeric_limits<const _Ty>::is_signed &&
		std::numeric_limits<volatile _Ty>::is_signed &&
		std::numeric_limits<const volatile _Ty>::is_signed
	);
}

template<typename _Ty>
constexpr bool is_integer() noexcept {
	return (
		std::numeric_limits<_Ty>::is_integer &&
		std::numeric_limits<const _Ty>::is_integer &&
		std::numeric_limits<volatile _Ty>::is_integer &&
		std::numeric_limits<const volatile _Ty>::is_integer
	);
}

template<typename _Ty>
constexpr bool is_exact() noexcept {
	return (
		std::numeric_limits<_Ty>::is_exact &&
		std::numeric_limits<const _Ty>::is_exact &&
		std::numeric_limits<volatile _Ty>::is_exact &&
		std::numeric_limits<const volatile _Ty>::is_exact
	);
}

template<typename _Ty>
constexpr bool is_iec559() noexcept {
	return (
		std::numeric_limits<_Ty>::is_iec559 &&
		std::numeric_limits<const _Ty>::is_iec559 &&
		std::numeric_limits<volatile _Ty>::is_iec559 &&
		std::numeric_limits<const volatile _Ty>::is_iec559
	);
}

template<typename _Ty>
constexpr bool is_bounded() noexcept {
	return (
		std::numeric_limits<_Ty>::is_bounded &&
		std::numeric_limits<const _Ty>::is_bounded &&
		std::numeric_limits<volatile _Ty>::is_bounded &&
		std::numeric_limits<const volatile _Ty>::is_bounded
	);
}

template<typename _Ty>
constexpr bool is_modulo() noexcept {
	return (
		std::numeric_limits<_Ty>::is_modulo &&
		std::numeric_limits<const _Ty>::is_modulo &&
		std::numeric_limits<volatile _Ty>::is_modulo &&
		std::numeric_limits<const volatile _Ty>::is_modulo
	);
}

template<typename _Ty>
constexpr bool has_infinity() noexcept {
	return (
		std::numeric_limits<_Ty>::has_infinity &&
		std::numeric_limits<const _Ty>::has_infinity &&
		std::numeric_limits<volatile _Ty>::has_infinity &&
		std::numeric_limits<const volatile _Ty>::has_infinity
	);
}

template<typename _Ty>
constexpr bool has_quiet_NaN() noexcept {
	return (
		std::numeric_limits<_Ty>::has_quiet_NaN &&
		std::numeric_limits<const _Ty>::has_quiet_NaN &&
		std::numeric_limits<volatile _Ty>::has_quiet_NaN &&
		std::numeric_limits<const volatile _Ty>::has_quiet_NaN
	);
}

template<typename _Ty>
constexpr bool has_signaling_NaN() noexcept {
	return (
		std::numeric_limits<_Ty>::has_signaling_NaN &&
		std::numeric_limits<const _Ty>::has_signaling_NaN &&
		std::numeric_limits<volatile _Ty>::has_signaling_NaN &&
		std::numeric_limits<const volatile _Ty>::has_signaling_NaN
	);
}

template<typename _Ty>
constexpr bool has_denorm_loss() noexcept {
	return (
		std::numeric_limits<_Ty>::has_denorm_loss &&
		std::numeric_limits<const _Ty>::has_denorm_loss &&
		std::numeric_limits<volatile _Ty>::has_denorm_loss &&
		std::numeric_limits<const volatile _Ty>::has_denorm_loss
	);
}

template<typename _Ty>
constexpr bool traps() noexcept {
	return (
		std::numeric_limits<_Ty>::traps &&
		std::numeric_limits<const _Ty>::traps &&
		std::numeric_limits<volatile _Ty>::traps &&
		std::numeric_limits<const volatile _Ty>::traps
	);
}

template<typename _Ty>
constexpr bool tinyness_before() noexcept {
	return (
		std::numeric_limits<_Ty>::tinyness_before &&
		std::numeric_limits<const _Ty>::tinyness_before &&
		std::numeric_limits<volatile _Ty>::tinyness_before &&
		std::numeric_limits<const volatile _Ty>::tinyness_before
	);
}

template<typename _Ty>
constexpr std::float_round_style round_style() noexcept {
	constexpr auto raw_ty{std::numeric_limits<_Ty>::round_style};
	constexpr auto c_ty{std::numeric_limits<const _Ty>::round_style};
	constexpr auto v_ty{std::numeric_limits<volatile _Ty>::round_style};
	constexpr auto cv_ty{std::numeric_limits<const volatile _Ty>::round_style};
	constexpr bool same_val{(raw_ty == c_ty) && (c_ty == v_ty) && (raw_ty == cv_ty)};
	static_assert(same_val);
	return raw_ty;
}

template<typename _Ty>
constexpr std::float_denorm_style has_denorm() noexcept {
	constexpr auto raw_ty{std::numeric_limits<_Ty>::has_denorm};
	constexpr auto c_ty{std::numeric_limits<const _Ty>::has_denorm};
	constexpr auto v_ty{std::numeric_limits<volatile _Ty>::has_denorm};
	constexpr auto cv_ty{std::numeric_limits<const volatile _Ty>::has_denorm};
	constexpr bool same_val{(raw_ty == c_ty) && (c_ty == v_ty) && (raw_ty == cv_ty)};
	static_assert(same_val);
	return raw_ty;
}

template<typename _Ty>
constexpr int digits() noexcept {
	constexpr auto raw_ty{std::numeric_limits<_Ty>::digits};
	constexpr auto c_ty{std::numeric_limits<const _Ty>::digits};
	constexpr auto v_ty{std::numeric_limits<volatile _Ty>::digits};
	constexpr auto cv_ty{std::numeric_limits<const volatile _Ty>::digits};
	constexpr bool same_val{(raw_ty == c_ty) && (c_ty == v_ty) && (raw_ty == cv_ty)};
	static_assert(same_val);
	return raw_ty;
}

template<typename _Ty>
constexpr int digits10() noexcept {
	constexpr auto raw_ty{std::numeric_limits<_Ty>::digits10};
	constexpr auto c_ty{std::numeric_limits<const _Ty>::digits10};
	constexpr auto v_ty{std::numeric_limits<volatile _Ty>::digits10};
	constexpr auto cv_ty{std::numeric_limits<const volatile _Ty>::digits10};
	constexpr bool same_val{(raw_ty == c_ty) && (c_ty == v_ty) && (raw_ty == cv_ty)};
	static_assert(same_val);
	return raw_ty;
}

template<typename _Ty>
constexpr int max_digits10() noexcept {
	constexpr auto raw_ty{std::numeric_limits<_Ty>::max_digits10};
	constexpr auto c_ty{std::numeric_limits<const _Ty>::max_digits10};
	constexpr auto v_ty{std::numeric_limits<volatile _Ty>::max_digits10};
	constexpr auto cv_ty{std::numeric_limits<const volatile _Ty>::max_digits10};
	constexpr bool same_val{(raw_ty == c_ty) && (c_ty == v_ty) && (raw_ty == cv_ty)};
	static_assert(same_val);
	return raw_ty;
}

template<typename _Ty>
constexpr int radix() noexcept {
	constexpr auto raw_ty{std::numeric_limits<_Ty>::radix};
	constexpr auto c_ty{std::numeric_limits<const _Ty>::radix};
	constexpr auto v_ty{std::numeric_limits<volatile _Ty>::radix};
	constexpr auto cv_ty{std::numeric_limits<const volatile _Ty>::radix};
	constexpr bool same_val{(raw_ty == c_ty) && (c_ty == v_ty) && (raw_ty == cv_ty)};
	static_assert(same_val);
	return raw_ty;
}

template<typename _Ty>
constexpr int min_exponent() noexcept {
	constexpr auto raw_ty{std::numeric_limits<_Ty>::min_exponent};
	constexpr auto c_ty{std::numeric_limits<const _Ty>::min_exponent};
	constexpr auto v_ty{std::numeric_limits<volatile _Ty>::min_exponent};
	constexpr auto cv_ty{std::numeric_limits<const volatile _Ty>::min_exponent};
	constexpr bool same_val{(raw_ty == c_ty) && (c_ty == v_ty) && (raw_ty == cv_ty)};
	static_assert(same_val);
	return raw_ty;
}

template<typename _Ty>
constexpr int max_exponent() noexcept {
	constexpr auto raw_ty{std::numeric_limits<_Ty>::max_exponent};
	constexpr auto c_ty{std::numeric_limits<const _Ty>::max_exponent};
	constexpr auto v_ty{std::numeric_limits<volatile _Ty>::max_exponent};
	constexpr auto cv_ty{std::numeric_limits<const volatile _Ty>::max_exponent};
	constexpr bool same_val{(raw_ty == c_ty) && (c_ty == v_ty) && (raw_ty == cv_ty)};
	static_assert(same_val);
	return raw_ty;
}

template<typename _Ty>
constexpr int min_exponent10() noexcept {
	constexpr auto raw_ty{std::numeric_limits<_Ty>::min_exponent10};
	constexpr auto c_ty{std::numeric_limits<const _Ty>::min_exponent10};
	constexpr auto v_ty{std::numeric_limits<volatile _Ty>::min_exponent10};
	constexpr auto cv_ty{std::numeric_limits<const volatile _Ty>::min_exponent10};
	constexpr bool same_val{(raw_ty == c_ty) && (c_ty == v_ty) && (raw_ty == cv_ty)};
	static_assert(same_val);
	return raw_ty;
}

template<typename _Ty>
constexpr int max_exponent10() noexcept {
	constexpr auto raw_ty{std::numeric_limits<_Ty>::max_exponent10};
	constexpr auto c_ty{std::numeric_limits<const _Ty>::max_exponent10};
	constexpr auto v_ty{std::numeric_limits<volatile _Ty>::max_exponent10};
	constexpr auto cv_ty{std::numeric_limits<const volatile _Ty>::max_exponent10};
	constexpr bool same_val{(raw_ty == c_ty) && (c_ty == v_ty) && (raw_ty == cv_ty)};
	static_assert(same_val);
	return raw_ty;
}

template<typename _Ty>
constexpr _Ty min() noexcept {
	constexpr auto raw_ty{std::numeric_limits<_Ty>::min()};
	constexpr auto c_ty{std::numeric_limits<const _Ty>::min()};
	constexpr auto v_ty{std::numeric_limits<volatile _Ty>::min()};
	constexpr auto cv_ty{std::numeric_limits<const volatile _Ty>::min()};
	constexpr bool same_val{(raw_ty == c_ty) && (c_ty == v_ty) && (raw_ty == cv_ty)};
	static_assert(same_val);
	return raw_ty;
}

template<typename _Ty>
constexpr _Ty lowest() noexcept {
	constexpr auto raw_ty{std::numeric_limits<_Ty>::lowest()};
	constexpr auto c_ty{std::numeric_limits<const _Ty>::lowest()};
	constexpr auto v_ty{std::numeric_limits<volatile _Ty>::lowest()};
	constexpr auto cv_ty{std::numeric_limits<const volatile _Ty>::lowest()};
	constexpr bool same_val{(raw_ty == c_ty) && (c_ty == v_ty) && (raw_ty == cv_ty)};
	static_assert(same_val);
	return raw_ty;
}

template<typename _Ty>
constexpr _Ty max() noexcept {
	constexpr auto raw_ty{std::numeric_limits<_Ty>::max()};
	constexpr auto c_ty{std::numeric_limits<const _Ty>::max()};
	constexpr auto v_ty{std::numeric_limits<volatile _Ty>::max()};
	constexpr auto cv_ty{std::numeric_limits<const volatile _Ty>::max()};
	constexpr bool same_val{(raw_ty == c_ty) && (c_ty == v_ty) && (raw_ty == cv_ty)};
	static_assert(same_val);
	return raw_ty;
}

template<typename _Ty>
constexpr _Ty epsilon() noexcept {
	constexpr auto raw_ty{std::numeric_limits<_Ty>::epsilon()};
	constexpr auto c_ty{std::numeric_limits<const _Ty>::epsilon()};
	constexpr auto v_ty{std::numeric_limits<volatile _Ty>::epsilon()};
	constexpr auto cv_ty{std::numeric_limits<const volatile _Ty>::epsilon()};
	constexpr bool same_val{(raw_ty == c_ty) && (c_ty == v_ty) && (raw_ty == cv_ty)};
	static_assert(same_val);
	return raw_ty;
}

template<typename _Ty>
constexpr _Ty round_error() noexcept {
	constexpr auto raw_ty{std::numeric_limits<_Ty>::round_error()};
	constexpr auto c_ty{std::numeric_limits<const _Ty>::round_error()};
	constexpr auto v_ty{std::numeric_limits<volatile _Ty>::round_error()};
	constexpr auto cv_ty{std::numeric_limits<const volatile _Ty>::round_error()};
	constexpr bool same_val{(raw_ty == c_ty) && (c_ty == v_ty) && (raw_ty == cv_ty)};
	static_assert(same_val);
	return raw_ty;
}

template<typename _Ty>
constexpr _Ty infinity() noexcept {
	constexpr auto raw_ty{std::numeric_limits<_Ty>::infinity()};
	constexpr auto c_ty{std::numeric_limits<const _Ty>::infinity()};
	constexpr auto v_ty{std::numeric_limits<volatile _Ty>::infinity()};
	constexpr auto cv_ty{std::numeric_limits<const volatile _Ty>::infinity()};
	constexpr bool same_val{(raw_ty == c_ty) && (c_ty == v_ty) && (raw_ty == cv_ty)};
	static_assert(same_val);
	return raw_ty;
}

template<typename _Ty>
constexpr _Ty quiet_NaN() noexcept {
	constexpr auto raw_ty{std::numeric_limits<_Ty>::quiet_NaN()};
	constexpr auto c_ty{std::numeric_limits<const _Ty>::quiet_NaN()};
	constexpr auto v_ty{std::numeric_limits<volatile _Ty>::quiet_NaN()};
	constexpr auto cv_ty{std::numeric_limits<const volatile _Ty>::quiet_NaN()};
	constexpr bool same_val{(raw_ty == c_ty) && (c_ty == v_ty) && (raw_ty == cv_ty)};
	static_assert(same_val);
	return raw_ty;
}

template<>
constexpr float quiet_NaN<float>() noexcept {
	constexpr auto raw_ty{std::numeric_limits<float>::quiet_NaN()};
	constexpr auto c_ty{std::numeric_limits<const float>::quiet_NaN()};
	constexpr auto v_ty{std::numeric_limits<volatile float>::quiet_NaN()};
	constexpr auto cv_ty{std::numeric_limits<const volatile float>::quiet_NaN()};
	constexpr bool same_val{(raw_ty != c_ty) && (c_ty != v_ty) && (raw_ty != cv_ty)};
	static_assert(same_val);
	return raw_ty;
}

template<>
constexpr double quiet_NaN<double>() noexcept {
	constexpr auto raw_ty{std::numeric_limits<double>::quiet_NaN()};
	constexpr auto c_ty{std::numeric_limits<const double>::quiet_NaN()};
	constexpr auto v_ty{std::numeric_limits<volatile double>::quiet_NaN()};
	constexpr auto cv_ty{std::numeric_limits<const volatile double>::quiet_NaN()};
	constexpr bool same_val{(raw_ty != c_ty) && (c_ty != v_ty) && (raw_ty != cv_ty)};
	static_assert(same_val);
	return raw_ty;
}

template<>
constexpr long double quiet_NaN<long double>() noexcept {
	constexpr auto raw_ty{std::numeric_limits<long double>::quiet_NaN()};
	constexpr auto c_ty{std::numeric_limits<const long double>::quiet_NaN()};
	constexpr auto v_ty{std::numeric_limits<volatile long double>::quiet_NaN()};
	constexpr auto cv_ty{std::numeric_limits<const volatile long double>::quiet_NaN()};
	constexpr bool same_val{(raw_ty != c_ty) && (c_ty != v_ty) && (raw_ty != cv_ty)};
	static_assert(same_val);
	return raw_ty;
}

template<typename _Ty>
constexpr _Ty signaling_NaN() noexcept {
	constexpr auto raw_ty{std::numeric_limits<_Ty>::signaling_NaN()};
	constexpr auto c_ty{std::numeric_limits<const _Ty>::signaling_NaN()};
	constexpr auto v_ty{std::numeric_limits<volatile _Ty>::signaling_NaN()};
	constexpr auto cv_ty{std::numeric_limits<const volatile _Ty>::signaling_NaN()};
	constexpr bool same_val{(raw_ty == c_ty) && (c_ty == v_ty) && (raw_ty == cv_ty)};
	static_assert(same_val);
	return raw_ty;
}

template<>
constexpr float signaling_NaN<float>() noexcept {
	constexpr auto raw_ty{std::numeric_limits<float>::signaling_NaN()};
	constexpr auto c_ty{std::numeric_limits<const float>::signaling_NaN()};
	constexpr auto v_ty{std::numeric_limits<volatile float>::signaling_NaN()};
	constexpr auto cv_ty{std::numeric_limits<const volatile float>::signaling_NaN()};
	constexpr bool same_val{(raw_ty != c_ty) && (c_ty != v_ty) && (raw_ty != cv_ty)};
	static_assert(same_val);
	return raw_ty;
}

template<>
constexpr double signaling_NaN<double>() noexcept {
	constexpr auto raw_ty{std::numeric_limits<double>::signaling_NaN()};
	constexpr auto c_ty{std::numeric_limits<const double>::signaling_NaN()};
	constexpr auto v_ty{std::numeric_limits<volatile double>::signaling_NaN()};
	constexpr auto cv_ty{std::numeric_limits<const volatile double>::signaling_NaN()};
	constexpr bool same_val{(raw_ty != c_ty) && (c_ty != v_ty) && (raw_ty != cv_ty)};
	static_assert(same_val);
	return raw_ty;
}


template<>
constexpr long double signaling_NaN<long double>() noexcept {
	constexpr auto raw_ty{std::numeric_limits<long double>::signaling_NaN()};
	constexpr auto c_ty{std::numeric_limits<const long double>::signaling_NaN()};
	constexpr auto v_ty{std::numeric_limits<volatile long double>::signaling_NaN()};
	constexpr auto cv_ty{std::numeric_limits<const volatile long double>::signaling_NaN()};
	constexpr bool same_val{(raw_ty != c_ty) && (c_ty != v_ty) && (raw_ty != cv_ty)};
	static_assert(same_val);
	return raw_ty;
}


template<typename _Ty>
constexpr _Ty denorm_min() noexcept {
	constexpr auto raw_ty{std::numeric_limits<_Ty>::denorm_min()};
	constexpr auto c_ty{std::numeric_limits<const _Ty>::denorm_min()};
	constexpr auto v_ty{std::numeric_limits<volatile _Ty>::denorm_min()};
	constexpr auto cv_ty{std::numeric_limits<const volatile _Ty>::denorm_min()};
	constexpr bool same_val{(raw_ty == c_ty) && (c_ty == v_ty) && (raw_ty == cv_ty)};
	static_assert(same_val);
	return raw_ty;
}

constexpr bool limits_bool() {
	static_assert(is_specialized<bool>());
	static_assert(!is_signed<bool>());
	static_assert(is_integer<bool>());
	static_assert(is_exact<bool>());
	static_assert(!is_iec559<bool>());
	static_assert(is_bounded<bool>());
	static_assert(!is_modulo<bool>());
	static_assert(!has_infinity<bool>());
	static_assert(!has_quiet_NaN<bool>());
	static_assert(!has_signaling_NaN<bool>());
	static_assert(has_denorm<bool>() == std::denorm_absent);
	static_assert(!has_denorm_loss<bool>());
	static_assert(digits<bool>() == 1);
	static_assert(digits10<bool>() == 0);
	static_assert(max_digits10<bool>() == 0);
	static_assert(radix<bool>() == 2);
	static_assert(max_exponent<bool>() == 0);
	static_assert(min_exponent<bool>() == 0);
	static_assert(max_exponent10<bool>() == 0);
	static_assert(min_exponent10<bool>() == 0);
	static_assert(!traps<bool>());
	static_assert(!tinyness_before<bool>());
	static_assert(!min<bool>());
	static_assert(!lowest<bool>());
	static_assert(max<bool>());
	static_assert(!epsilon<bool>());
	static_assert(!round_error<bool>());
	static_assert(!infinity<bool>());
	static_assert(!quiet_NaN<bool>());
	static_assert(!signaling_NaN<bool>());
	static_assert(!denorm_min<bool>());

	return true;
}

constexpr bool limits_char() {
	static_assert(is_specialized<char>());
	static_assert(is_signed<char>() == (char(-1) < 0));
	static_assert(is_integer<char>());
	static_assert(is_exact<char>());
	static_assert(!is_iec559<char>());
	static_assert(is_bounded<char>());
	static_assert(!is_modulo<char>());
	static_assert(!has_infinity<char>());
	static_assert(!has_quiet_NaN<char>());
	static_assert(!has_signaling_NaN<char>());
	static_assert(has_denorm<char>() == std::denorm_absent);
	static_assert(!has_denorm_loss<char>());
	static_assert(digits<char>() == (__CHAR_BIT__ - 1));
	static_assert(digits10<char>() == 0);
	static_assert(max_digits10<char>() == 0);
	static_assert(radix<char>() == 2);
	static_assert(max_exponent<char>() == 0);
	static_assert(min_exponent<char>() == 0);
	static_assert(max_exponent10<char>() == 0);
	static_assert(min_exponent10<char>() == 0);
	static_assert(traps<char>());
	static_assert(!tinyness_before<char>());
	static_assert(min<char>() == (-__SCHAR_MAX__ - 1));
	static_assert(lowest<char>() == (-__SCHAR_MAX__ - 1));
	static_assert(max<char>() == __SCHAR_MAX__);
	static_assert(epsilon<char>() == 0);
	static_assert(round_error<char>() == 0);
	static_assert(infinity<char>() == 0);
	static_assert(quiet_NaN<char>() == 0);
	static_assert(signaling_NaN<char>() == 0);
	static_assert(denorm_min<char>() == 0);

	return true;
}

constexpr bool limits_signed_char() {
	static_assert(is_specialized<signed char>());
	static_assert(is_signed<signed char>());
	static_assert(is_integer<signed char>());
	static_assert(is_exact<signed char>());
	static_assert(!is_iec559<signed char>());
	static_assert(is_bounded<signed char>());
	static_assert(!is_modulo<signed char>());
	static_assert(!has_infinity<signed char>());
	static_assert(!has_quiet_NaN<signed char>());
	static_assert(!has_signaling_NaN<signed char>());
	static_assert(has_denorm<signed char>() == std::denorm_absent);
	static_assert(!has_denorm_loss<signed char>());
	static_assert(digits<signed char>() == (__CHAR_BIT__ - 1));
	static_assert(digits10<signed char>() == 0);
	static_assert(max_digits10<signed char>() == 0);
	static_assert(radix<signed char>() == 2);
	static_assert(max_exponent<signed char>() == 0);
	static_assert(min_exponent<signed char>() == 0);
	static_assert(max_exponent10<signed char>() == 0);
	static_assert(min_exponent10<signed char>() == 0);
	static_assert(traps<signed char>());
	static_assert(!tinyness_before<signed char>());
	static_assert(min<signed char>() == (-__SCHAR_MAX__ - 1));
	static_assert(lowest<signed char>() == (-__SCHAR_MAX__ - 1));
	static_assert(max<signed char>() == __SCHAR_MAX__);
	static_assert(epsilon<signed char>() == 0);
	static_assert(round_error<signed char>() == 0);
	static_assert(infinity<signed char>() == 0);
	static_assert(quiet_NaN<signed char>() == 0);
	static_assert(signaling_NaN<signed char>() == 0);
	static_assert(denorm_min<signed char>() == 0);

	return true;
}

constexpr bool limits_unsigned_char() {
	static_assert(is_specialized<unsigned char>());
	static_assert(!is_signed<unsigned char>());
	static_assert(is_integer<unsigned char>());
	static_assert(is_exact<unsigned char>());
	static_assert(!is_iec559<unsigned char>());
	static_assert(is_bounded<unsigned char>());
	static_assert(is_modulo<unsigned char>());
	static_assert(!has_infinity<unsigned char>());
	static_assert(!has_quiet_NaN<unsigned char>());
	static_assert(!has_signaling_NaN<unsigned char>());
	static_assert(has_denorm<unsigned char>() == std::denorm_absent);
	static_assert(!has_denorm_loss<unsigned char>());
	static_assert(digits<unsigned char>() == __CHAR_BIT__);
	static_assert(digits10<unsigned char>() == 0);
	static_assert(max_digits10<unsigned char>() == 0);
	static_assert(radix<unsigned char>() == 2);
	static_assert(max_exponent<unsigned char>() == 0);
	static_assert(min_exponent<unsigned char>() == 0);
	static_assert(max_exponent10<unsigned char>() == 0);
	static_assert(min_exponent10<unsigned char>() == 0);
	static_assert(traps<unsigned char>());
	static_assert(!tinyness_before<unsigned char>());
	static_assert(min<unsigned char>() == 0);
	static_assert(lowest<unsigned char>() == 0);
	static_assert(max<unsigned char>() == (((unsigned char)__SCHAR_MAX__ << 1) + 1));
	static_assert(epsilon<unsigned char>() == 0);
	static_assert(round_error<unsigned char>() == 0);
	static_assert(infinity<unsigned char>() == 0);
	static_assert(quiet_NaN<unsigned char>() == 0);
	static_assert(signaling_NaN<unsigned char>() == 0);
	static_assert(denorm_min<unsigned char>() == 0);

	return true;
}

constexpr bool limits_wchar_t() {
	static_assert(is_specialized<wchar_t>());
	static_assert(is_signed<wchar_t>() == (wchar_t(-1) < 0));
	static_assert(is_integer<wchar_t>());
	static_assert(is_exact<wchar_t>());
	static_assert(!is_iec559<wchar_t>());
	static_assert(is_bounded<wchar_t>());
	static_assert(is_modulo<wchar_t>() == !(wchar_t(-1) < 0));
	static_assert(!has_infinity<wchar_t>());
	static_assert(!has_quiet_NaN<wchar_t>());
	static_assert(!has_signaling_NaN<wchar_t>());
	static_assert(has_denorm<wchar_t>() == std::denorm_absent);
	static_assert(!has_denorm_loss<wchar_t>());
	static_assert(digits<wchar_t>() == (__CHAR_BIT__ * sizeof(wchar_t)) - int(wchar_t(-1) < 0));
	static_assert(digits10<wchar_t>() == 0);
	static_assert(max_digits10<wchar_t>() == 0);
	static_assert(radix<wchar_t>() == 2);
	static_assert(max_exponent<wchar_t>() == 0);
	static_assert(min_exponent<wchar_t>() == 0);
	static_assert(max_exponent10<wchar_t>() == 0);
	static_assert(min_exponent10<wchar_t>() == 0);
	static_assert(traps<wchar_t>());
	static_assert(!tinyness_before<wchar_t>());
	constexpr auto _wchar_min{(wchar_t(-1) < 0) ?  (-__WCHAR_MAX__ - 1): wchar_t(0)};
	static_assert(min<wchar_t>() == _wchar_min);
	static_assert(lowest<wchar_t>() == _wchar_min);
	static_assert(max<wchar_t>() == __WCHAR_MAX__);
	static_assert(epsilon<wchar_t>() == 0);
	static_assert(round_error<wchar_t>() == 0);
	static_assert(infinity<wchar_t>() == 0);
	static_assert(quiet_NaN<wchar_t>() == 0);
	static_assert(signaling_NaN<wchar_t>() == 0);
	static_assert(denorm_min<wchar_t>() == 0);

	return true;
}

constexpr bool limits_char8_t() {
	static_assert(is_specialized<char8_t>());
	static_assert(!is_signed<char8_t>());
	static_assert(is_integer<char8_t>());
	static_assert(is_exact<char8_t>());
	static_assert(!is_iec559<char8_t>());
	static_assert(is_bounded<char8_t>());
	static_assert(!is_modulo<char8_t>());
	static_assert(!has_infinity<char8_t>());
	static_assert(!has_quiet_NaN<char8_t>());
	static_assert(!has_signaling_NaN<char8_t>());
	static_assert(has_denorm<char8_t>() == std::denorm_absent);
	static_assert(!has_denorm_loss<char8_t>());
	static_assert(digits<char8_t>() == (sizeof(char8_t) * __CHAR_BIT__));
	static_assert(digits10<char8_t>() == 0);
	static_assert(max_digits10<char8_t>() == 0);
	static_assert(radix<char8_t>() == 2);
	static_assert(max_exponent<char8_t>() == 0);
	static_assert(min_exponent<char8_t>() == 0);
	static_assert(max_exponent10<char8_t>() == 0);
	static_assert(min_exponent10<char8_t>() == 0);
	static_assert(traps<char8_t>());
	static_assert(!tinyness_before<char8_t>());
	static_assert(min<char8_t>() == char8_t(0));
	static_assert(lowest<char8_t>() == char8_t(0));
	static_assert(max<char8_t>() == char8_t(-1));
	static_assert(epsilon<char8_t>() == 0);
	static_assert(round_error<char8_t>() == 0);
	static_assert(infinity<char8_t>() == 0);
	static_assert(quiet_NaN<char8_t>() == 0);
	static_assert(signaling_NaN<char8_t>() == 0);
	static_assert(denorm_min<char8_t>() == 0);

	return true;
}

constexpr bool limits_char16_t() {
	static_assert(is_specialized<char16_t>());
	static_assert(!is_signed<char16_t>());
	static_assert(is_integer<char16_t>());
	static_assert(is_exact<char16_t>());
	static_assert(!is_iec559<char16_t>());
	static_assert(is_bounded<char16_t>());
	static_assert(!is_modulo<char16_t>());
	static_assert(!has_infinity<char16_t>());
	static_assert(!has_quiet_NaN<char16_t>());
	static_assert(!has_signaling_NaN<char16_t>());
	static_assert(has_denorm<char16_t>() == std::denorm_absent);
	static_assert(!has_denorm_loss<char16_t>());
	static_assert(digits<char16_t>() == (sizeof(char16_t) * __CHAR_BIT__));
	static_assert(digits10<char16_t>() == 0);
	static_assert(max_digits10<char16_t>() == 0);
	static_assert(radix<char16_t>() == 2);
	static_assert(max_exponent<char16_t>() == 0);
	static_assert(min_exponent<char16_t>() == 0);
	static_assert(max_exponent10<char16_t>() == 0);
	static_assert(min_exponent10<char16_t>() == 0);
	static_assert(traps<char16_t>());
	static_assert(!tinyness_before<char16_t>());
	static_assert(min<char16_t>() == char16_t(0));
	static_assert(lowest<char16_t>() == char16_t(0));
	static_assert(max<char16_t>() == char16_t(-1));
	static_assert(epsilon<char16_t>() == 0);
	static_assert(round_error<char16_t>() == 0);
	static_assert(infinity<char16_t>() == 0);
	static_assert(quiet_NaN<char16_t>() == 0);
	static_assert(signaling_NaN<char16_t>() == 0);
	static_assert(denorm_min<char16_t>() == 0);

	return true;
}

constexpr bool limits_char32_t() {
	static_assert(is_specialized<char32_t>());
	static_assert(!is_signed<char32_t>());
	static_assert(is_integer<char32_t>());
	static_assert(is_exact<char32_t>());
	static_assert(!is_iec559<char32_t>());
	static_assert(is_bounded<char32_t>());
	static_assert(!is_modulo<char32_t>());
	static_assert(!has_infinity<char32_t>());
	static_assert(!has_quiet_NaN<char32_t>());
	static_assert(!has_signaling_NaN<char32_t>());
	static_assert(has_denorm<char32_t>() == std::denorm_absent);
	static_assert(!has_denorm_loss<char32_t>());
	static_assert(digits<char32_t>() == (sizeof(char32_t) * __CHAR_BIT__));
	static_assert(digits10<char32_t>() == 0);
	static_assert(max_digits10<char32_t>() == 0);
	static_assert(radix<char32_t>() == 2);
	static_assert(max_exponent<char32_t>() == 0);
	static_assert(min_exponent<char32_t>() == 0);
	static_assert(max_exponent10<char32_t>() == 0);
	static_assert(min_exponent10<char32_t>() == 0);
	static_assert(traps<char32_t>());
	static_assert(!tinyness_before<char32_t>());
	static_assert(min<char32_t>() == char32_t(0));
	static_assert(lowest<char32_t>() == char32_t(0));
	static_assert(max<char32_t>() == char32_t(-1));
	static_assert(epsilon<char32_t>() == 0);
	static_assert(round_error<char32_t>() == 0);
	static_assert(infinity<char32_t>() == 0);
	static_assert(quiet_NaN<char32_t>() == 0);
	static_assert(signaling_NaN<char32_t>() == 0);
	static_assert(denorm_min<char32_t>() == 0);

	return true;
}

constexpr bool limits_short() {
	static_assert(is_specialized<short>());
	static_assert(is_signed<short>());
	static_assert(is_integer<short>());
	static_assert(is_exact<short>());
	static_assert(!is_iec559<short>());
	static_assert(is_bounded<short>());
	static_assert(!is_modulo<short>());
	static_assert(!has_infinity<short>());
	static_assert(!has_quiet_NaN<short>());
	static_assert(!has_signaling_NaN<short>());
	static_assert(has_denorm<short>() == std::denorm_absent);
	static_assert(!has_denorm_loss<short>());
	static_assert(digits<short>() == (sizeof(short) * __CHAR_BIT__) - 1);
	static_assert(digits10<short>() == 0);
	static_assert(max_digits10<short>() == 0);
	static_assert(radix<short>() == 2);
	static_assert(max_exponent<short>() == 0);
	static_assert(min_exponent<short>() == 0);
	static_assert(max_exponent10<short>() == 0);
	static_assert(min_exponent10<short>() == 0);
	static_assert(traps<short>());
	static_assert(!tinyness_before<short>());
	static_assert(min<short>() == (-__SHRT_MAX__ - 1));
	static_assert(lowest<short>() == (-__SHRT_MAX__ - 1));
	static_assert(max<short>() == __SHRT_MAX__);
	static_assert(epsilon<short>() == 0);
	static_assert(round_error<short>() == 0);
	static_assert(infinity<short>() == 0);
	static_assert(quiet_NaN<short>() == 0);
	static_assert(signaling_NaN<short>() == 0);
	static_assert(denorm_min<short>() == 0);

	return true;
}

constexpr bool limits_unsigned_short() {
	static_assert(is_specialized<unsigned short>());
	static_assert(!is_signed<unsigned short>());
	static_assert(is_integer<unsigned short>());
	static_assert(is_exact<unsigned short>());
	static_assert(!is_iec559<unsigned short>());
	static_assert(is_bounded<unsigned short>());
	static_assert(is_modulo<unsigned short>());
	static_assert(!has_infinity<unsigned short>());
	static_assert(!has_quiet_NaN<unsigned short>());
	static_assert(!has_signaling_NaN<unsigned short>());
	static_assert(has_denorm<unsigned short>() == std::denorm_absent);
	static_assert(!has_denorm_loss<unsigned short>());
	static_assert(digits<unsigned short>() == (sizeof(short) * __CHAR_BIT__));
	static_assert(digits10<unsigned short>() == 0);
	static_assert(max_digits10<unsigned short>() == 0);
	static_assert(radix<unsigned short>() == 2);
	static_assert(max_exponent<unsigned short>() == 0);
	static_assert(min_exponent<unsigned short>() == 0);
	static_assert(max_exponent10<unsigned short>() == 0);
	static_assert(min_exponent10<unsigned short>() == 0);
	static_assert(traps<unsigned short>());
	static_assert(!tinyness_before<unsigned short>());
	static_assert(min<unsigned short>() == 0);
	static_assert(lowest<unsigned short>() == 0);
	static_assert(max<unsigned short>() == ((unsigned short)__SHRT_MAX__ << 1) + 1);
	static_assert(epsilon<unsigned short>() == 0);
	static_assert(round_error<unsigned short>() == 0);
	static_assert(infinity<unsigned short>() == 0);
	static_assert(quiet_NaN<unsigned short>() == 0);
	static_assert(signaling_NaN<unsigned short>() == 0);
	static_assert(denorm_min<unsigned short>() == 0);

	return true;
}

constexpr bool limits_int() {
	static_assert(is_specialized<int>());
	static_assert(is_signed<int>());
	static_assert(is_integer<int>());
	static_assert(is_exact<int>());
	static_assert(!is_iec559<int>());
	static_assert(is_bounded<int>());
	static_assert(!is_modulo<int>());
	static_assert(!has_infinity<int>());
	static_assert(!has_quiet_NaN<int>());
	static_assert(!has_signaling_NaN<int>());
	static_assert(has_denorm<int>() == std::denorm_absent);
	static_assert(!has_denorm_loss<int>());
	static_assert(digits<int>() == (sizeof(int) * __CHAR_BIT__) - 1);
	static_assert(digits10<int>() == 0);
	static_assert(max_digits10<int>() == 0);
	static_assert(radix<int>() == 2);
	static_assert(max_exponent<int>() == 0);
	static_assert(min_exponent<int>() == 0);
	static_assert(max_exponent10<int>() == 0);
	static_assert(min_exponent10<int>() == 0);
	static_assert(traps<int>());
	static_assert(!tinyness_before<int>());
	static_assert(min<int>() == (-__INT_MAX__ - 1));
	static_assert(lowest<int>() == (-__INT_MAX__ - 1));
	static_assert(max<int>() == __INT_MAX__);
	static_assert(epsilon<int>() == 0);
	static_assert(round_error<int>() == 0);
	static_assert(infinity<int>() == 0);
	static_assert(quiet_NaN<int>() == 0);
	static_assert(signaling_NaN<int>() == 0);
	static_assert(denorm_min<int>() == 0);

	return true;
}

constexpr bool limits_unsigned_int() {
	static_assert(is_specialized<unsigned int>());
	static_assert(!is_signed<unsigned int>());
	static_assert(is_integer<unsigned int>());
	static_assert(is_exact<unsigned int>());
	static_assert(!is_iec559<unsigned int>());
	static_assert(is_bounded<unsigned int>());
	static_assert(is_modulo<unsigned int>());
	static_assert(!has_infinity<unsigned int>());
	static_assert(!has_quiet_NaN<unsigned int>());
	static_assert(!has_signaling_NaN<unsigned int>());
	static_assert(has_denorm<unsigned int>() == std::denorm_absent);
	static_assert(!has_denorm_loss<unsigned int>());
	static_assert(digits<unsigned int>() == (sizeof(int) * __CHAR_BIT__));
	static_assert(digits10<unsigned int>() == 0);
	static_assert(max_digits10<unsigned int>() == 0);
	static_assert(radix<unsigned int>() == 2);
	static_assert(max_exponent<unsigned int>() == 0);
	static_assert(min_exponent<unsigned int>() == 0);
	static_assert(max_exponent10<unsigned int>() == 0);
	static_assert(min_exponent10<unsigned int>() == 0);
	static_assert(traps<unsigned int>());
	static_assert(!tinyness_before<unsigned int>());
	static_assert(min<unsigned int>() == 0);
	static_assert(lowest<unsigned int>() == 0);
	static_assert(max<unsigned int>() == ((unsigned int)__INT_MAX__ << 1U) + 1U);
	static_assert(epsilon<unsigned int>() == 0);
	static_assert(round_error<unsigned int>() == 0);
	static_assert(infinity<unsigned int>() == 0);
	static_assert(quiet_NaN<unsigned int>() == 0);
	static_assert(signaling_NaN<unsigned int>() == 0);
	static_assert(denorm_min<unsigned int>() == 0);

	return true;
}

constexpr bool limits_long() {
	static_assert(is_specialized<long>());
	static_assert(is_signed<long>());
	static_assert(is_integer<long>());
	static_assert(is_exact<long>());
	static_assert(!is_iec559<long>());
	static_assert(is_bounded<long>());
	static_assert(!is_modulo<long>());
	static_assert(!has_infinity<long>());
	static_assert(!has_quiet_NaN<long>());
	static_assert(!has_signaling_NaN<long>());
	static_assert(has_denorm<long>() == std::denorm_absent);
	static_assert(!has_denorm_loss<long>());
	static_assert(digits<long>() == (sizeof(long) * __CHAR_BIT__) - 1);
	static_assert(digits10<long>() == 0);
	static_assert(max_digits10<long>() == 0);
	static_assert(radix<long>() == 2);
	static_assert(max_exponent<long>() == 0);
	static_assert(min_exponent<long>() == 0);
	static_assert(max_exponent10<long>() == 0);
	static_assert(min_exponent10<long>() == 0);
	static_assert(traps<long>());
	static_assert(!tinyness_before<long>());
	static_assert(min<long>() == (-__LONG_MAX__ - 1));
	static_assert(lowest<long>() == (-__LONG_MAX__ - 1));
	static_assert(max<long>() == __LONG_MAX__);
	static_assert(epsilon<long>() == 0);
	static_assert(round_error<long>() == 0);
	static_assert(infinity<long>() == 0);
	static_assert(quiet_NaN<long>() == 0);
	static_assert(signaling_NaN<long>() == 0);
	static_assert(denorm_min<long>() == 0);

	return true;
}

constexpr bool limits_unsigned_long() {
	static_assert(is_specialized<unsigned long>());
	static_assert(!is_signed<unsigned long>());
	static_assert(is_integer<unsigned long>());
	static_assert(is_exact<unsigned long>());
	static_assert(!is_iec559<unsigned long>());
	static_assert(is_bounded<unsigned long>());
	static_assert(is_modulo<unsigned long>());
	static_assert(!has_infinity<unsigned long>());
	static_assert(!has_quiet_NaN<unsigned long>());
	static_assert(!has_signaling_NaN<unsigned long>());
	static_assert(has_denorm<unsigned long>() == std::denorm_absent);
	static_assert(!has_denorm_loss<unsigned long>());
	static_assert(digits<unsigned long>() == (sizeof(long) * __CHAR_BIT__));
	static_assert(digits10<unsigned long>() == 0);
	static_assert(max_digits10<unsigned long>() == 0);
	static_assert(radix<unsigned long>() == 2);
	static_assert(max_exponent<unsigned long>() == 0);
	static_assert(min_exponent<unsigned long>() == 0);
	static_assert(max_exponent10<unsigned long>() == 0);
	static_assert(min_exponent10<unsigned long>() == 0);
	static_assert(traps<unsigned long>());
	static_assert(!tinyness_before<unsigned long>());
	static_assert(min<unsigned long>() == 0);
	static_assert(lowest<unsigned long>() == 0);
	static_assert(max<unsigned long>() == ((unsigned long)__LONG_MAX__ << 1UL) + 1UL);
	static_assert(epsilon<unsigned long>() == 0);
	static_assert(round_error<unsigned long>() == 0);
	static_assert(infinity<unsigned long>() == 0);
	static_assert(quiet_NaN<unsigned long>() == 0);
	static_assert(signaling_NaN<unsigned long>() == 0);
	static_assert(denorm_min<unsigned long>() == 0);

	return true;
}

constexpr bool limits_long_long() {
	static_assert(is_specialized<long long>());
	static_assert(is_signed<long long>());
	static_assert(is_integer<long long>());
	static_assert(is_exact<long long>());
	static_assert(!is_iec559<long long>());
	static_assert(is_bounded<long long>());
	static_assert(!is_modulo<long long>());
	static_assert(!has_infinity<long long>());
	static_assert(!has_quiet_NaN<long long>());
	static_assert(!has_signaling_NaN<long long>());
	static_assert(has_denorm<long long>() == std::denorm_absent);
	static_assert(!has_denorm_loss<long long>());
	static_assert(digits<long long>() == (sizeof(long long) * __CHAR_BIT__) - 1);
	static_assert(digits10<long long>() == 0);
	static_assert(max_digits10<long long>() == 0);
	static_assert(radix<long long>() == 2);
	static_assert(max_exponent<long long>() == 0);
	static_assert(min_exponent<long long>() == 0);
	static_assert(max_exponent10<long long>() == 0);
	static_assert(min_exponent10<long long>() == 0);
	static_assert(traps<long long>());
	static_assert(!tinyness_before<long long>());
	static_assert(min<long long>() == (-__LONG_LONG_MAX__ - 1));
	static_assert(lowest<long long>() == (-__LONG_LONG_MAX__ - 1));
	static_assert(max<long long>() == __LONG_LONG_MAX__);
	static_assert(epsilon<long long>() == 0);
	static_assert(round_error<long long>() == 0);
	static_assert(infinity<long long>() == 0);
	static_assert(quiet_NaN<long long>() == 0);
	static_assert(signaling_NaN<long long>() == 0);
	static_assert(denorm_min<long long>() == 0);

	return true;
}

constexpr bool limits_unsigned_long_long() {
	static_assert(is_specialized<unsigned long long>());
	static_assert(!is_signed<unsigned long long>());
	static_assert(is_integer<unsigned long long>());
	static_assert(is_exact<unsigned long long>());
	static_assert(!is_iec559<unsigned long long>());
	static_assert(is_bounded<unsigned long long>());
	static_assert(is_modulo<unsigned long long>());
	static_assert(!has_infinity<unsigned long long>());
	static_assert(!has_quiet_NaN<unsigned long long>());
	static_assert(!has_signaling_NaN<unsigned long long>());
	static_assert(has_denorm<unsigned long long>() == std::denorm_absent);
	static_assert(!has_denorm_loss<unsigned long long>());
	static_assert(digits<unsigned long long>() == (sizeof(long long) * __CHAR_BIT__));
	static_assert(digits10<unsigned long long>() == 0);
	static_assert(max_digits10<unsigned long long>() == 0);
	static_assert(radix<unsigned long long>() == 2);
	static_assert(max_exponent<unsigned long long>() == 0);
	static_assert(min_exponent<unsigned long long>() == 0);
	static_assert(max_exponent10<unsigned long long>() == 0);
	static_assert(min_exponent10<unsigned long long>() == 0);
	static_assert(traps<unsigned long long>());
	static_assert(!tinyness_before<unsigned long long>());
	static_assert(min<unsigned long long>() == 0);
	static_assert(lowest<unsigned long long>() == 0);
	static_assert(max<unsigned long long>() == ((unsigned long long)__LONG_LONG_MAX__ << 1ULL) + 1ULL);
	static_assert(epsilon<unsigned long long>() == 0);
	static_assert(round_error<unsigned long long>() == 0);
	static_assert(infinity<unsigned long long>() == 0);
	static_assert(quiet_NaN<unsigned long long>() == 0);
	static_assert(signaling_NaN<unsigned long long>() == 0);
	static_assert(denorm_min<unsigned long long>() == 0);

	return true;
}

constexpr bool limits_float() {
	static_assert(is_specialized<float>());
	static_assert(is_signed<float>());
	static_assert(!is_integer<float>());
	static_assert(!is_exact<float>());
	static_assert(is_iec559<float>());
	static_assert(is_bounded<float>());
	static_assert(!is_modulo<float>());
	static_assert(has_infinity<float>());
	static_assert(has_quiet_NaN<float>());
	static_assert(has_signaling_NaN<float>());
	static_assert(has_denorm<float>() == std::denorm_present);
	static_assert(!has_denorm_loss<float>());
	static_assert(digits<float>() == __FLT_MANT_DIG__);
	static_assert(digits10<float>() == __FLT_DIG__);
	static_assert(max_digits10<float>() == (2 + (__FLT_MANT_DIG__) * (643L / 2136)));
	static_assert(radix<float>() == __FLT_RADIX__);
	static_assert(max_exponent<float>() == __FLT_MAX_EXP__);
	static_assert(min_exponent<float>() == __FLT_MIN_EXP__);
	static_assert(max_exponent10<float>() == __FLT_MAX_10_EXP__);
	static_assert(min_exponent10<float>() == __FLT_MIN_10_EXP__);
	static_assert(!traps<float>());
	static_assert(!tinyness_before<float>());
	static_assert(min<float>() == __FLT_MIN__);
	static_assert(lowest<float>() == -__FLT_MAX__);
	static_assert(max<float>() == __FLT_MAX__);
	static_assert(epsilon<float>() == __FLT_EPSILON__);
	static_assert(round_error<float>() == 0.5F);
	static_assert(infinity<float>() == __builtin_huge_valf());
	static_assert(quiet_NaN<float>() != __builtin_nanf(""));
	static_assert(signaling_NaN<float>() != __builtin_nansf(""));
	static_assert(denorm_min<float>() == __FLT_DENORM_MIN__);

	return true;
}

constexpr bool limits_double() {
	static_assert(is_specialized<double>());
	static_assert(is_signed<double>());
	static_assert(!is_integer<double>());
	static_assert(!is_exact<double>());
	static_assert(is_iec559<double>());
	static_assert(is_bounded<double>());
	static_assert(!is_modulo<double>());
	static_assert(has_infinity<double>());
	static_assert(has_quiet_NaN<double>());
	static_assert(has_signaling_NaN<double>());
	static_assert(has_denorm<double>() == std::denorm_present);
	static_assert(!has_denorm_loss<double>());
	static_assert(digits<double>() == __DBL_MANT_DIG__);
	static_assert(digits10<double>() == __DBL_DIG__);
	static_assert(max_digits10<double>() == (2 + (__DBL_MANT_DIG__) * (643L / 2136)));
	static_assert(radix<double>() == __FLT_RADIX__);
	static_assert(max_exponent<double>() == __DBL_MAX_EXP__);
	static_assert(min_exponent<double>() == __DBL_MIN_EXP__);
	static_assert(max_exponent10<double>() == __DBL_MAX_10_EXP__);
	static_assert(min_exponent10<double>() == __DBL_MIN_10_EXP__);
	static_assert(!traps<double>());
	static_assert(!tinyness_before<double>());
	static_assert(min<double>() == __DBL_MIN__);
	static_assert(lowest<double>() == -__DBL_MAX__);
	static_assert(max<double>() == __DBL_MAX__);
	static_assert(epsilon<double>() == __DBL_EPSILON__);
	static_assert(round_error<double>() == 0.5);
	static_assert(infinity<double>() == __builtin_huge_val());
	static_assert(quiet_NaN<double>() != __builtin_nan(""));
	static_assert(signaling_NaN<double>() != __builtin_nans(""));
	static_assert(denorm_min<double>() == __DBL_DENORM_MIN__);

	return true;
}

constexpr bool limits_long_double() {
	static_assert(is_specialized<long double>());
	static_assert(is_signed<long double>());
	static_assert(!is_integer<long double>());
	static_assert(!is_exact<long double>());
	static_assert(is_iec559<long double>());
	static_assert(is_bounded<long double>());
	static_assert(!is_modulo<long double>());
	static_assert(has_infinity<long double>());
	static_assert(has_quiet_NaN<long double>());
	static_assert(has_signaling_NaN<long double>());
	static_assert(has_denorm<long double>() == std::denorm_present);
	static_assert(!has_denorm_loss<long double>());
	static_assert(digits<long double>() == __LDBL_MANT_DIG__);
	static_assert(digits10<long double>() == __LDBL_DIG__);
	static_assert(max_digits10<long double>() == (2 + (__LDBL_MANT_DIG__) * (643L / 2136)));
	static_assert(radix<long double>() == __FLT_RADIX__);
	static_assert(max_exponent<long double>() == __LDBL_MAX_EXP__);
	static_assert(min_exponent<long double>() == __LDBL_MIN_EXP__);
	static_assert(max_exponent10<long double>() == __LDBL_MAX_10_EXP__);
	static_assert(min_exponent10<long double>() == __LDBL_MIN_10_EXP__);
	static_assert(!traps<long double>());
	static_assert(!tinyness_before<long double>());
	static_assert(min<long double>() == __LDBL_MIN__);
	static_assert(lowest<long double>() == -__LDBL_MAX__);
	static_assert(max<long double>() == __LDBL_MAX__);
	static_assert(epsilon<long double>() == __LDBL_EPSILON__);
	static_assert(round_error<long double>() == 0.5L);
	static_assert(infinity<long double>() == __builtin_huge_vall());
	static_assert(quiet_NaN<long double>() != __builtin_nanl(""));
	static_assert(signaling_NaN<long double>() != __builtin_nansl(""));
	static_assert(denorm_min<long double>() == __LDBL_DENORM_MIN__);

	return true;
}

// NOLINTNEXTLINE(readability-named-parameter)
int main(int, char**) {

	static_assert(limits_bool());
	static_assert(limits_char());
	static_assert(limits_signed_char());
	static_assert(limits_unsigned_char());
	static_assert(limits_wchar_t());
	static_assert(limits_char8_t());
	static_assert(limits_char16_t());
	static_assert(limits_char32_t());
	static_assert(limits_short());
	static_assert(limits_unsigned_short());
	static_assert(limits_int());
	static_assert(limits_unsigned_int());
	static_assert(limits_long());
	static_assert(limits_unsigned_long());
	static_assert(limits_long_long());
	static_assert(limits_unsigned_long_long());
	static_assert(limits_float());
	static_assert(limits_double());
	static_assert(limits_long_double());

	return 0;
}
