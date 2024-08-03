/* SPDX-License-Identifier: BSD-3-Clause */

#include <abyss/cstddef>

#if !defined(NULL)
#	error "NULL not defined"
#endif

#if !defined(offsetof)
#	error "offsetof not defined"
#endif

namespace details {
	/* NOTE(aki): This is a mangled version of the type_traits `bool_constant` */
	template<bool B>
	struct bool_constant {
		static constexpr bool value = B;
		using value_type = bool;
		using type = bool;
		[[nodiscard]]
		constexpr operator bool() const noexcept { return value; }
		[[nodiscard]]
		constexpr value_type operator()() const noexcept { return value; }
	};

	using true_type  = bool_constant<true>;
	using false_type = bool_constant<false>;

	template<typename _Tl, typename _Tr>
	struct is_same : false_type {};
	template<typename _Ty>
	struct is_same<_Ty, _Ty> : true_type {};
	template<typename _Tl, typename _Tr>
	inline constexpr bool is_same_v = is_same<_Tl, _Tr>::value;

}


struct A{
	int a;
	char b;
};

static_assert(NULL == nullptr);
// BUG(aki): I'm being a bad girl and assuming a lot here
static_assert(offsetof(A, b) == alignof(int));

static_assert(details::is_same_v<std::nullptr_t, decltype(NULL)>);
static_assert(details::is_same_v<std::size_t, decltype(sizeof(0))>);
static_assert(details::is_same_v<
	std::ptrdiff_t,
	decltype(static_cast<char*>(nullptr) - static_cast<char*>(nullptr))
>);


// NOLINTNEXTLINE(readability-named-parameter)
int main(int, char**) {

	// TODO(aki): std::byte tests

	return 0;
}
