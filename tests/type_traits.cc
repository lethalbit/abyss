/* SPDX-License-Identifier: BSD-3-Clause */

#include <abyss/cstddef>
#include <abyss/type_traits>


namespace test {
	class A {};
	enum B : int {};
	enum struct C : char {};
	union D { int a; float b; };
	struct E { D c; };
	class F : A {};
	enum class G {};

	struct H {
		int foo() const &;
	};

	class I : A {};
	class J final : I {};
	class K {};
	class L : public A {};

	struct M {
		A a;
		operator A() { return a; }
	};

	struct N {
		N() = default;
		N(const N &) = delete;
		N(N &&) = delete;
		virtual ~N() = 0;
		N &operator =(const N &) = delete;
		N &operator =(N &&) = delete;
	};

	struct O {
		O() = default;
		O(const O &) = delete;
		O(O &&) = delete;
		virtual ~O() = default;
		O &operator =(const O &) = delete;
		O &operator =(O &&) = delete;

		virtual void baz();
	};

	struct P {
		P() = default;
		P(const P &) = default;
		P(P &&) = default;
		~P() noexcept = default;
		P &operator =(const P &) = default;
		P &operator =(P &&) = default;
	};

	struct R {
		R() = default;
		R(const R &) = default;
		R(R &&) = default;
		~R() noexcept = default;
		R &operator =(const R &) { return *this; } // NOLINT(cert-oop54-cpp,modernize-use-equals-default)
		R &operator =(R &&) { return *this; } // NOLINT(performance-noexcept-move-constructor)
	};

	struct S { int foo; };

	struct U {
		int bar{};

		U(int baz) {
			if (!baz)
				throw baz;
		}
	};

	struct V { U qux; };

	struct W {
		// W() { throw std::exception{}; }
		// W(const W &) { throw std::exception{}; } // NOLINT(cert-err09-cpp)
		// W(W &&) { throw std::exception{}; } // NOLINT(cert-err09-cpp,bugprone-exception-escape,performance-noexcept-move-constructor)
		~W() noexcept = default;
		W &operator =(const W &) = default;
		W &operator =(W &&) = default;
	};

	struct X { W qux; };

	class Y {
		int foo;
		double bar;

	public:
		Y(int baz) : foo{baz}, bar{} { }
		Y(int qux, double fwibble) noexcept : foo{qux}, bar{fwibble} { }
	};

	struct Z {
		int bar;
	private:
		int baz; // NOLINT(clang-diagnostic-unused-private-field)
	};

	struct AA {
		int foo;

		AA() = default;
		AA(const AA &) = default;
		AA(AA &&) = delete;
		~AA() = default;
		AA &operator =(const AA &) = default;
		AA &operator =(AA &&) = delete;
	};

	struct AB {
		AB() = default;
		AB(const AB &) = delete;
		AB(AB &&) = delete;
		virtual ~AB() = default;
		AB &operator =(const AB &) = delete;
		AB &operator =(AB &&) = delete;

		virtual void baz() = 0;
	};

	struct AC : AB {};
	struct AD : O {};
	struct AE {};
	union AF {};

	struct AG {
		AG() = default;
		AG(const AG &) = delete;
		AG(AG &&) = delete;
		virtual ~AG() = default;
		AG &operator =(const AG &) = delete;
		AG &operator =(AG &&) = delete;
	};

	struct AH {
		int foo;

		AH() = default;
		AH(int qux) : foo{qux + 1} { }
		AH(const AH &) = default;
		AH(AH &&) = default;
		~AH() = default;
		AH &operator =(const AH &) = default;
		AH &operator =(AH &&) = default;
	};

	struct AI { void foo() { } };

	struct AJ {
		AJ() = delete;
		AJ(const AJ &) = default;
		AJ(AJ &&) = default;
		~AJ() = default;
		AJ &operator =(const AJ &) = default;
		AJ &operator =(AJ &&) = default;
	};


	struct AK {
	private:
		int foo;
		int bar;
	public:
		constexpr AK(std::nullptr_t) noexcept :
			foo{}, bar{} { }
	};

	struct AL {
		virtual void nya() = 0;
	};

	struct AM {
		int foo;
		float bar;
	};

	struct AN {
		int baz;
		float qux;
	};

	struct AO: AM, AN { };

	struct AP {
		int foo;
		AP(const AP&) {
			throw foo;
		}
	};

	struct AQ {
		AQ(const AQ&&) {
			throw false;
		}
	};

	int bar();

	template<typename> struct SU_traits {};
	template<class T, class U> struct SU_traits<U T::*>
		{ using member_type = U; };

	struct SU_is_empty_v { static int bar; };


	template<typename T, typename... Ts>
	constexpr bool same_types = std::conjunction_v<std::is_same<T, Ts>...>;
}


constexpr bool is_void() noexcept {

	static_assert(std::is_void_v<void>);
	static_assert(std::is_void_v<const void>);
	static_assert(std::is_void_v<volatile void>);
	static_assert(std::is_void_v<const volatile void>);

	static_assert(!std::is_void_v<void*>);
	static_assert(!std::is_void_v<decltype(is_void)>);
	static_assert(!std::is_void_v<std::is_void<void>>);
	static_assert(!std::is_void_v<int>);

	return true;
}

constexpr bool is_null_pointer() noexcept {

	static_assert(std::is_null_pointer_v<decltype(nullptr)>);
	static_assert(std::is_null_pointer_v<std::nullptr_t>);

	static_assert(!std::is_null_pointer_v<void*>);
	static_assert(!std::is_null_pointer_v<int* const>);

	return true;
}

constexpr bool is_integral() noexcept {

	static_assert(std::is_integral_v<bool>);
	static_assert(std::is_integral_v<const bool>);
	static_assert(std::is_integral_v<volatile bool>);
	static_assert(std::is_integral_v<const volatile bool>);

	static_assert(std::is_integral_v<char>);
	static_assert(std::is_integral_v<const char>);
	static_assert(std::is_integral_v<volatile char>);
	static_assert(std::is_integral_v<const volatile char>);

	static_assert(std::is_integral_v<short>);
	static_assert(std::is_integral_v<const short>);
	static_assert(std::is_integral_v<volatile short>);
	static_assert(std::is_integral_v<const volatile short>);

	static_assert(std::is_integral_v<int>);
	static_assert(std::is_integral_v<const int>);
	static_assert(std::is_integral_v<volatile int>);
	static_assert(std::is_integral_v<const volatile int>);

	static_assert(std::is_integral_v<long>);
	static_assert(std::is_integral_v<const long>);
	static_assert(std::is_integral_v<volatile long>);
	static_assert(std::is_integral_v<const volatile long>);

	static_assert(std::is_integral_v<long long>);
	static_assert(std::is_integral_v<const long long>);
	static_assert(std::is_integral_v<volatile long long>);
	static_assert(std::is_integral_v<const volatile long long>);

	static_assert(std::is_integral_v<unsigned char>);
	static_assert(std::is_integral_v<const unsigned char>);
	static_assert(std::is_integral_v<volatile unsigned char>);
	static_assert(std::is_integral_v<const volatile unsigned char>);

	static_assert(std::is_integral_v<unsigned short>);
	static_assert(std::is_integral_v<const unsigned short>);
	static_assert(std::is_integral_v<volatile unsigned short>);
	static_assert(std::is_integral_v<const volatile unsigned short>);

	static_assert(std::is_integral_v<unsigned int>);
	static_assert(std::is_integral_v<const unsigned int>);
	static_assert(std::is_integral_v<volatile unsigned int>);
	static_assert(std::is_integral_v<const volatile unsigned int>);

	static_assert(std::is_integral_v<unsigned long>);
	static_assert(std::is_integral_v<const unsigned long>);
	static_assert(std::is_integral_v<volatile unsigned long>);
	static_assert(std::is_integral_v<const volatile unsigned long>);

	static_assert(std::is_integral_v<unsigned long long>);
	static_assert(std::is_integral_v<const unsigned long long>);
	static_assert(std::is_integral_v<volatile unsigned long long>);
	static_assert(std::is_integral_v<const volatile unsigned long long>);

	static_assert(!std::is_integral_v<float>);
	static_assert(!std::is_integral_v<double>);
	static_assert(!std::is_integral_v<int*>);

	static_assert(!std::is_integral_v<test::A>);
	static_assert(!std::is_integral_v<test::G>);

	return true;
}

constexpr bool is_floating_point() noexcept {

	static_assert(std::is_floating_point_v<float>);
	static_assert(std::is_floating_point_v<const float>);
	static_assert(std::is_floating_point_v<volatile float>);
	static_assert(std::is_floating_point_v<const volatile float>);

	static_assert(std::is_floating_point_v<double>);
	static_assert(std::is_floating_point_v<const double>);
	static_assert(std::is_floating_point_v<volatile double>);
	static_assert(std::is_floating_point_v<const volatile double>);

	static_assert(std::is_floating_point_v<long double>);
	static_assert(std::is_floating_point_v<const long double>);
	static_assert(std::is_floating_point_v<volatile long double>);
	static_assert(std::is_floating_point_v<const volatile long double>);

	static_assert(!std::is_floating_point_v<int>);
	static_assert(!std::is_floating_point_v<bool>);
	static_assert(!std::is_floating_point_v<unsigned int>);
	static_assert(!std::is_floating_point_v<unsigned char>);

	static_assert(!std::is_floating_point_v<test::A>);
	static_assert(!std::is_floating_point_v<test::B>);

	return true;
}

constexpr bool is_array() noexcept {
	// NOLINTBEGIN(modernize-avoid-c-arrays,cppcoreguidelines-avoid-c-arrays)

	static_assert(std::is_array_v<int[]>);
	static_assert(std::is_array_v<const int[]>);
	static_assert(std::is_array_v<volatile int[]>);
	static_assert(std::is_array_v<const volatile int[]>);

	static_assert(std::is_array_v<int[2]>);
	static_assert(std::is_array_v<const int[4]>);
	static_assert(std::is_array_v<volatile int[6]>);
	static_assert(std::is_array_v<const volatile int[8]>);

	static_assert(std::is_array_v<bool[]>);
	static_assert(std::is_array_v<const bool[]>);
	static_assert(std::is_array_v<volatile bool[]>);
	static_assert(std::is_array_v<const volatile bool[]>);

	static_assert(std::is_array_v<float[]>);
	static_assert(std::is_array_v<const float[]>);
	static_assert(std::is_array_v<volatile float[]>);
	static_assert(std::is_array_v<const volatile float[]>);

	static_assert(std::is_array_v<test::A[]>);
	static_assert(std::is_array_v<test::A[2]>);
	static_assert(std::is_array_v<test::B[]>);
	static_assert(std::is_array_v<test::B[2]>);

	static_assert(!std::is_array_v<test::A>);
	static_assert(!std::is_array_v<test::B>);
	static_assert(!std::is_array_v<test::G>);

	static_assert(!std::is_array_v<int>);
	static_assert(!std::is_array_v<bool>);
	static_assert(!std::is_array_v<float>);

	return true;
	// NOLINTEND(modernize-avoid-c-arrays,cppcoreguidelines-avoid-c-arrays)
}

constexpr bool is_enum() noexcept {

	static_assert(std::is_enum_v<test::B>);
	static_assert(std::is_enum_v<test::C>);
	static_assert(std::is_enum_v<test::G>);

	static_assert(!std::is_enum_v<test::A>);
	static_assert(!std::is_enum_v<test::D>);
	static_assert(!std::is_enum_v<int>);
	static_assert(!std::is_enum_v<bool>);
	static_assert(!std::is_enum_v<float>);

	return true;
}

constexpr bool is_union() noexcept {

	static_assert(std::is_union_v<test::D>);

	static_assert(!std::is_union_v<test::A>);
	static_assert(!std::is_union_v<test::B>);
	static_assert(!std::is_union_v<test::E>);
	static_assert(!std::is_union_v<test::G>);
	static_assert(!std::is_union_v<int>);
	static_assert(!std::is_union_v<void>);
	static_assert(!std::is_union_v<bool>);

	return true;
}

constexpr bool is_class() noexcept {

	static_assert(std::is_class_v<test::A>);
	static_assert(std::is_class_v<test::E>);
	static_assert(std::is_class_v<test::F>);

	static_assert(!std::is_class_v<test::B>);
	static_assert(!std::is_class_v<test::D>);
	static_assert(!std::is_class_v<test::G>);

	static_assert(!std::is_class_v<double>);
	static_assert(!std::is_class_v<bool>);
	static_assert(!std::is_class_v<int>);
	static_assert(!std::is_class_v<void>);

	return true;
}

constexpr bool is_function() noexcept {

	static_assert(std::is_function_v<int(void)>);
	static_assert(std::is_function_v<void(int)>);
	static_assert(std::is_function_v<decltype(test::bar)>);
	static_assert(std::is_function_v<test::SU_traits<decltype(&test::H::foo)>::member_type>);
	static_assert(std::is_function_v<int(void*)>);
	static_assert(std::is_function_v<void*(int)>);

	static_assert(!std::is_function_v<test::A>);
	static_assert(!std::is_function_v<test::B>);
	static_assert(!std::is_function_v<test::H>);

	static_assert(!std::is_function_v<int>);
	static_assert(!std::is_function_v<bool>);
	static_assert(!std::is_function_v<void>);
	static_assert(!std::is_function_v<float>);

	return true;
}

constexpr bool is_pointer() noexcept {

	static_assert(std::is_pointer_v<test::A*>);
	static_assert(std::is_pointer_v<test::B*>);
	static_assert(std::is_pointer_v<test::D*>);
	static_assert(std::is_pointer_v<int*>);
	static_assert(std::is_pointer_v<float*>);
	static_assert(std::is_pointer_v<void*>);
	static_assert(std::is_pointer_v<int**>);

	static_assert(!std::is_pointer_v<test::A>);
	static_assert(!std::is_pointer_v<test::B>);
	static_assert(!std::is_pointer_v<test::D>);
	static_assert(!std::is_pointer_v<int>);
	static_assert(!std::is_pointer_v<void>);
	// NOLINTNEXTLINE(modernize-avoid-c-arrays,cppcoreguidelines-avoid-c-arrays)
	static_assert(!std::is_pointer_v<char[]>);
	// NOLINTNEXTLINE(modernize-avoid-c-arrays,cppcoreguidelines-avoid-c-arrays)
	static_assert(!std::is_pointer_v<bool[2]>);
	static_assert(!std::is_pointer_v<std::nullptr_t>);

	return true;
}

constexpr bool is_lvalue_reference() noexcept {

	static_assert(std::is_lvalue_reference_v<test::A&>);
	static_assert(std::is_lvalue_reference_v<test::B&>);
	static_assert(std::is_lvalue_reference_v<test::D&>);
	static_assert(std::is_lvalue_reference_v<int&>);
	static_assert(std::is_lvalue_reference_v<const int&>);
	static_assert(std::is_lvalue_reference_v<volatile int&>);
	static_assert(std::is_lvalue_reference_v<const volatile int&>);

	static_assert(!std::is_lvalue_reference_v<test::A>);
	static_assert(!std::is_lvalue_reference_v<test::A&&>);
	static_assert(!std::is_lvalue_reference_v<int>);
	static_assert(!std::is_lvalue_reference_v<int&&>);

	return true;
}

constexpr bool is_rvalue_reference() noexcept {

	static_assert(std::is_rvalue_reference_v<test::A&&>);
	static_assert(std::is_rvalue_reference_v<test::B&&>);
	static_assert(std::is_rvalue_reference_v<test::D&&>);
	static_assert(std::is_rvalue_reference_v<int&&>);
	static_assert(std::is_rvalue_reference_v<const int&&>);
	static_assert(std::is_rvalue_reference_v<volatile int&&>);
	static_assert(std::is_rvalue_reference_v<const volatile int&&>);

	static_assert(!std::is_rvalue_reference_v<test::A>);
	static_assert(!std::is_rvalue_reference_v<test::A&>);
	static_assert(!std::is_rvalue_reference_v<int>);
	static_assert(!std::is_rvalue_reference_v<int&>);

	return true;
}

constexpr bool is_member_object_pointer() noexcept {

	static_assert(std::is_member_object_pointer_v<int(test::A::*)>);

	static_assert(!std::is_member_object_pointer_v<int(test::A::*)()>);

	return true;
}

constexpr bool is_member_function_pointer() noexcept {

	static_assert(std::is_member_function_pointer_v<decltype(&test::AI::foo)>);

	static_assert(!std::is_member_function_pointer_v<decltype(test::bar)>);

	return true;
}

constexpr bool is_fundamental() noexcept {

	static_assert(std::is_fundamental_v<int>);
	static_assert(std::is_fundamental_v<const int>);
	static_assert(std::is_fundamental_v<volatile int>);
	static_assert(std::is_fundamental_v<const volatile int>);

	static_assert(std::is_fundamental_v<bool>);
	static_assert(std::is_fundamental_v<const bool>);
	static_assert(std::is_fundamental_v<volatile bool>);
	static_assert(std::is_fundamental_v<const volatile bool>);

	static_assert(std::is_fundamental_v<float>);
	static_assert(std::is_fundamental_v<const float>);
	static_assert(std::is_fundamental_v<volatile float>);
	static_assert(std::is_fundamental_v<const volatile float>);

	static_assert(!std::is_fundamental_v<int*>);
	static_assert(!std::is_fundamental_v<int&>);
	static_assert(!std::is_fundamental_v<int&&>);

	static_assert(!std::is_fundamental_v<test::A>);
	static_assert(!std::is_fundamental_v<test::A*>);
	static_assert(!std::is_fundamental_v<test::A&>);
	static_assert(!std::is_fundamental_v<test::A&&>);

	static_assert(!std::is_fundamental_v<decltype(test::bar)>);

	return true;
}

constexpr bool is_arithmetic() noexcept {

	static_assert(std::is_arithmetic_v<int>);
	static_assert(std::is_arithmetic_v<const int>);
	static_assert(std::is_arithmetic_v<volatile int>);
	static_assert(std::is_arithmetic_v<const volatile int>);

	static_assert(std::is_arithmetic_v<bool>);
	static_assert(std::is_arithmetic_v<const bool>);
	static_assert(std::is_arithmetic_v<volatile bool>);
	static_assert(std::is_arithmetic_v<const volatile bool>);

	static_assert(std::is_arithmetic_v<float>);
	static_assert(std::is_arithmetic_v<const float>);
	static_assert(std::is_arithmetic_v<volatile float>);
	static_assert(std::is_arithmetic_v<const volatile float>);

	static_assert(std::is_arithmetic_v<char>);
	static_assert(std::is_arithmetic_v<const char>);
	static_assert(std::is_arithmetic_v<volatile char>);
	static_assert(std::is_arithmetic_v<const volatile char>);

	static_assert(std::is_arithmetic_v<unsigned int>);
	static_assert(std::is_arithmetic_v<const unsigned int>);
	static_assert(std::is_arithmetic_v<volatile unsigned int>);
	static_assert(std::is_arithmetic_v<const volatile unsigned int>);

	static_assert(!std::is_arithmetic_v<test::A>);
	static_assert(!std::is_arithmetic_v<test::B>);
	static_assert(!std::is_arithmetic_v<test::D>);

	static_assert(!std::is_arithmetic_v<int*>);
	static_assert(!std::is_arithmetic_v<int&>);
	static_assert(!std::is_arithmetic_v<int&&>);

	return true;
}

constexpr bool is_scalar() noexcept {

	static_assert(std::is_scalar_v<int>);
	static_assert(std::is_scalar_v<const int>);
	static_assert(std::is_scalar_v<volatile int>);
	static_assert(std::is_scalar_v<const volatile int>);

	static_assert(std::is_scalar_v<bool>);
	static_assert(std::is_scalar_v<const bool>);
	static_assert(std::is_scalar_v<volatile bool>);
	static_assert(std::is_scalar_v<const volatile bool>);

	static_assert(std::is_scalar_v<float>);
	static_assert(std::is_scalar_v<const float>);
	static_assert(std::is_scalar_v<volatile float>);
	static_assert(std::is_scalar_v<const volatile float>);

	static_assert(std::is_scalar_v<char>);
	static_assert(std::is_scalar_v<const char>);
	static_assert(std::is_scalar_v<volatile char>);
	static_assert(std::is_scalar_v<const volatile char>);

	static_assert(std::is_scalar_v<unsigned int>);
	static_assert(std::is_scalar_v<const unsigned int>);
	static_assert(std::is_scalar_v<volatile unsigned int>);
	static_assert(std::is_scalar_v<const volatile unsigned int>);

	static_assert(std::is_scalar_v<int*>);
	static_assert(std::is_scalar_v<bool*>);
	static_assert(std::is_scalar_v<char*>);
	static_assert(std::is_scalar_v<test::G>);
	static_assert(std::is_scalar_v<decltype(nullptr)>);

	static_assert(!std::is_scalar_v<test::A>);
	static_assert(!std::is_scalar_v<test::D>);
	static_assert(!std::is_scalar_v<decltype(test::bar)>);

	static_assert(!std::is_scalar_v<int&>);
	static_assert(!std::is_scalar_v<int&&>);
	static_assert(!std::is_scalar_v<bool&>);
	static_assert(!std::is_scalar_v<bool&&>);

	return true;
}

constexpr bool is_object() noexcept {

	static_assert(std::is_object_v<int>);
	static_assert(std::is_object_v<const int>);
	static_assert(std::is_object_v<volatile int>);
	static_assert(std::is_object_v<const volatile int>);

	static_assert(std::is_object_v<test::A>);
	static_assert(std::is_object_v<test::B>);
	static_assert(std::is_object_v<test::C>);

	static_assert(!std::is_object_v<int&>);
	static_assert(!std::is_object_v<int&&>);
	static_assert(!std::is_object_v<void>);

	static_assert(!std::is_object_v<test::A&>);
	static_assert(!std::is_object_v<test::B&>);
	static_assert(!std::is_object_v<test::C&>);

	return true;
}

constexpr bool is_compound() noexcept {

	static_assert(std::is_compound_v<test::A>);
	static_assert(std::is_compound_v<test::B>);
	static_assert(std::is_compound_v<test::C>);
	static_assert(std::is_compound_v<test::D>);

	static_assert(!std::is_compound_v<int>);
	static_assert(!std::is_compound_v<void>);
	static_assert(!std::is_compound_v<bool>);

	return true;
}

constexpr bool is_reference() noexcept {

	static_assert(std::is_reference_v<int&>);
	static_assert(std::is_reference_v<int&&>);
	static_assert(std::is_reference_v<const int&>);
	static_assert(std::is_reference_v<const int&&>);
	static_assert(std::is_reference_v<volatile int&>);
	static_assert(std::is_reference_v<volatile int&&>);
	static_assert(std::is_reference_v<const volatile int&>);
	static_assert(std::is_reference_v<const volatile int&&>);

	static_assert(std::is_reference_v<test::A&>);
	static_assert(std::is_reference_v<test::A&&>);
	static_assert(std::is_reference_v<test::B&>);
	static_assert(std::is_reference_v<test::B&&>);
	static_assert(std::is_reference_v<test::C&>);
	static_assert(std::is_reference_v<test::C&&>);

	static_assert(!std::is_reference_v<test::A>);
	static_assert(!std::is_reference_v<void>);

	return true;
}

constexpr bool is_member_pointer() noexcept {

	static_assert(std::is_member_pointer_v<int(test::A::*)>);

	static_assert(!std::is_member_pointer_v<test::A>);
	static_assert(!std::is_member_pointer_v<int*>);
	static_assert(!std::is_member_pointer_v<void>);

	return true;
}

constexpr bool is_const() noexcept {

	static_assert(std::is_const_v<const int>);
	static_assert(std::is_const_v<int* const>);
	static_assert(std::is_const_v<const volatile int>);

	static_assert(!std::is_const_v<int*>);
	static_assert(!std::is_const_v<const int*>);
	static_assert(!std::is_const_v<const int&>);
	static_assert(!std::is_const_v<bool>);
	static_assert(!std::is_const_v<test::A>);

	return true;
}

constexpr bool is_volatile() noexcept {

	static_assert(std::is_volatile_v<volatile int>);
	static_assert(std::is_volatile_v<int* volatile>);
	static_assert(std::is_volatile_v<const volatile int>);

	static_assert(!std::is_volatile_v<int*>);
	static_assert(!std::is_volatile_v<volatile int*>);
	static_assert(!std::is_volatile_v<volatile int&>);
	static_assert(!std::is_volatile_v<bool>);
	static_assert(!std::is_volatile_v<test::A>);

	return true;
}

constexpr bool is_trivial() noexcept {

	static_assert(std::is_trivial_v<int>);
	static_assert(std::is_trivial_v<test::A>);
	static_assert(std::is_trivial_v<test::B>);
	static_assert(std::is_trivial_v<test::C>);

	static_assert(!std::is_trivial_v<test::U>);

	return true;
}

constexpr bool is_trivially_copyable() noexcept {
	static_assert(std::is_trivially_copyable_v<int>);
	static_assert(std::is_trivially_copyable_v<test::A>);
	static_assert(std::is_trivially_copyable_v<test::B>);
	static_assert(std::is_trivially_copyable_v<test::C>);
	static_assert(std::is_trivially_copyable_v<test::S>);

	static_assert(!std::is_trivially_copyable_v<test::N>);
	static_assert(!std::is_trivially_copyable_v<test::O>);

	return true;
}

constexpr bool is_standard_layout() noexcept {

	static_assert(std::is_standard_layout_v<int>);
	static_assert(std::is_standard_layout_v<test::A>);
	static_assert(std::is_standard_layout_v<test::B>);
	static_assert(std::is_standard_layout_v<test::C>);
	static_assert(std::is_standard_layout_v<test::S>);

	static_assert(!std::is_standard_layout_v<test::N>);
	static_assert(!std::is_standard_layout_v<test::O>);


	return true;
}

constexpr bool is_pod() noexcept {

	static_assert(std::is_pod_v<int>);
	static_assert(std::is_pod_v<test::A>);
	static_assert(std::is_pod_v<test::B>);
	static_assert(std::is_pod_v<test::C>);
	static_assert(std::is_pod_v<test::S>);

	static_assert(!std::is_pod_v<test::N>);
	static_assert(!std::is_pod_v<test::O>);
	static_assert(!std::is_pod_v<test::U>);


	return true;
}

constexpr bool has_unique_object_representations() noexcept {

	static_assert(std::has_unique_object_representations_v<char>);
	static_assert(std::has_unique_object_representations_v<int>);
	static_assert(std::has_unique_object_representations_v<test::B>);

	static_assert(!std::has_unique_object_representations_v<float>);
	static_assert(!std::has_unique_object_representations_v<test::A>);

	return true;
}

constexpr bool is_empty() noexcept {

	static_assert(std::is_empty_v<test::A>);
	static_assert(std::is_empty_v<test::I>);

	static_assert(!std::is_empty_v<test::B>);
	static_assert(!std::is_empty_v<test::M>);
	static_assert(!std::is_empty_v<test::O>);

	return true;
}

constexpr bool is_polymorphic() noexcept {

	static_assert(std::is_polymorphic_v<test::N>);
	static_assert(std::is_polymorphic_v<test::O>);

	static_assert(!std::is_polymorphic_v<test::A>);
	static_assert(!std::is_polymorphic_v<test::B>);
	static_assert(!std::is_polymorphic_v<test::C>);


	return true;
}

constexpr bool is_abstract() noexcept {

	static_assert(std::is_abstract_v<test::AL>);

	static_assert(!std::is_abstract_v<test::A>);

	return true;
}

constexpr bool is_final() noexcept {

	static_assert(std::is_final_v<test::J>);

	static_assert(!std::is_final_v<test::A>);

	return true;
}

constexpr bool is_aggregate() noexcept {

	// TODO(aki): Slightly problematic to test at the moment, oops

	return true;
}


constexpr bool is_signed() noexcept {

	static_assert(std::is_signed_v<signed char>);
	static_assert(std::is_signed_v<const volatile signed char>);
	static_assert(std::is_signed_v<volatile signed char>);
	static_assert(std::is_signed_v<const volatile signed char>);

	static_assert(std::is_signed_v<short>);
	static_assert(std::is_signed_v<const volatile short>);
	static_assert(std::is_signed_v<volatile short>);
	static_assert(std::is_signed_v<const volatile short>);

	static_assert(std::is_signed_v<int>);
	static_assert(std::is_signed_v<const volatile int>);
	static_assert(std::is_signed_v<volatile int>);
	static_assert(std::is_signed_v<const volatile int>);

	static_assert(std::is_signed_v<long>);
	static_assert(std::is_signed_v<const volatile long>);
	static_assert(std::is_signed_v<volatile long>);
	static_assert(std::is_signed_v<const volatile long>);

	static_assert(std::is_signed_v<long long>);
	static_assert(std::is_signed_v<const volatile long long>);
	static_assert(std::is_signed_v<volatile long long>);
	static_assert(std::is_signed_v<const volatile long long>);

	static_assert(std::is_signed_v<float>);
	static_assert(std::is_signed_v<const volatile float>);
	static_assert(std::is_signed_v<volatile float>);
	static_assert(std::is_signed_v<const volatile float>);

	static_assert(std::is_signed_v<double>);
	static_assert(std::is_signed_v<const volatile double>);
	static_assert(std::is_signed_v<volatile double>);
	static_assert(std::is_signed_v<const volatile double>);

	static_assert(std::is_signed_v<long double>);
	static_assert(std::is_signed_v<const volatile long double>);
	static_assert(std::is_signed_v<volatile long double>);
	static_assert(std::is_signed_v<const volatile long double>);


	static_assert(!std::is_signed_v<unsigned char>);
	static_assert(!std::is_signed_v<const volatile unsigned char>);
	static_assert(!std::is_signed_v<volatile unsigned char>);
	static_assert(!std::is_signed_v<const volatile unsigned char>);

	static_assert(!std::is_signed_v<unsigned short>);
	static_assert(!std::is_signed_v<const volatile unsigned short>);
	static_assert(!std::is_signed_v<volatile unsigned short>);
	static_assert(!std::is_signed_v<const volatile unsigned short>);

	static_assert(!std::is_signed_v<unsigned int>);
	static_assert(!std::is_signed_v<const volatile unsigned int>);
	static_assert(!std::is_signed_v<volatile unsigned int>);
	static_assert(!std::is_signed_v<const volatile unsigned int>);

	static_assert(!std::is_signed_v<unsigned long>);
	static_assert(!std::is_signed_v<const volatile unsigned long>);
	static_assert(!std::is_signed_v<volatile unsigned long>);
	static_assert(!std::is_signed_v<const volatile unsigned long>);

	static_assert(!std::is_signed_v<unsigned long long>);
	static_assert(!std::is_signed_v<const volatile unsigned long long>);
	static_assert(!std::is_signed_v<volatile unsigned long long>);
	static_assert(!std::is_signed_v<const volatile unsigned long long>);

	static_assert(!std::is_signed_v<test::A>);
	static_assert(!std::is_signed_v<test::B>);
	static_assert(!std::is_signed_v<test::C>);
	static_assert(!std::is_signed_v<test::D>);
	static_assert(!std::is_signed_v<test::G>);

	return true;
}

constexpr bool is_unsigned() noexcept {

	static_assert(std::is_unsigned_v<unsigned char>);
	static_assert(std::is_unsigned_v<const volatile unsigned char>);
	static_assert(std::is_unsigned_v<volatile unsigned char>);
	static_assert(std::is_unsigned_v<const volatile unsigned char>);

	static_assert(std::is_unsigned_v<unsigned short>);
	static_assert(std::is_unsigned_v<const volatile unsigned short>);
	static_assert(std::is_unsigned_v<volatile unsigned short>);
	static_assert(std::is_unsigned_v<const volatile unsigned short>);

	static_assert(std::is_unsigned_v<unsigned int>);
	static_assert(std::is_unsigned_v<const volatile unsigned int>);
	static_assert(std::is_unsigned_v<volatile unsigned int>);
	static_assert(std::is_unsigned_v<const volatile unsigned int>);

	static_assert(std::is_unsigned_v<unsigned long>);
	static_assert(std::is_unsigned_v<const volatile unsigned long>);
	static_assert(std::is_unsigned_v<volatile unsigned long>);
	static_assert(std::is_unsigned_v<const volatile unsigned long>);

	static_assert(std::is_unsigned_v<unsigned long long>);
	static_assert(std::is_unsigned_v<const volatile unsigned long long>);
	static_assert(std::is_unsigned_v<volatile unsigned long long>);
	static_assert(std::is_unsigned_v<const volatile unsigned long long>);

	static_assert(!std::is_unsigned_v<signed char>);
	static_assert(!std::is_unsigned_v<const volatile signed char>);
	static_assert(!std::is_unsigned_v<volatile signed char>);
	static_assert(!std::is_unsigned_v<const volatile signed char>);

	static_assert(!std::is_unsigned_v<short>);
	static_assert(!std::is_unsigned_v<const volatile short>);
	static_assert(!std::is_unsigned_v<volatile short>);
	static_assert(!std::is_unsigned_v<const volatile short>);

	static_assert(!std::is_unsigned_v<int>);
	static_assert(!std::is_unsigned_v<const volatile int>);
	static_assert(!std::is_unsigned_v<volatile int>);
	static_assert(!std::is_unsigned_v<const volatile int>);

	static_assert(!std::is_unsigned_v<long>);
	static_assert(!std::is_unsigned_v<const volatile long>);
	static_assert(!std::is_unsigned_v<volatile long>);
	static_assert(!std::is_unsigned_v<const volatile long>);

	static_assert(!std::is_unsigned_v<long long>);
	static_assert(!std::is_unsigned_v<const volatile long long>);
	static_assert(!std::is_unsigned_v<volatile long long>);
	static_assert(!std::is_unsigned_v<const volatile long long>);

	static_assert(!std::is_unsigned_v<float>);
	static_assert(!std::is_unsigned_v<const volatile float>);
	static_assert(!std::is_unsigned_v<volatile float>);
	static_assert(!std::is_unsigned_v<const volatile float>);

	static_assert(!std::is_unsigned_v<double>);
	static_assert(!std::is_unsigned_v<const volatile double>);
	static_assert(!std::is_unsigned_v<volatile double>);
	static_assert(!std::is_unsigned_v<const volatile double>);

	static_assert(!std::is_unsigned_v<long double>);
	static_assert(!std::is_unsigned_v<const volatile long double>);
	static_assert(!std::is_unsigned_v<volatile long double>);
	static_assert(!std::is_unsigned_v<const volatile long double>);

	static_assert(!std::is_unsigned_v<test::A>);
	static_assert(!std::is_unsigned_v<test::B>);
	static_assert(!std::is_unsigned_v<test::C>);
	static_assert(!std::is_unsigned_v<test::D>);
	static_assert(!std::is_unsigned_v<test::G>);

	return true;
}

constexpr bool is_bounded_array() noexcept {
	// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays,modernize-avoid-c-arrays)
	static_assert(std::is_bounded_array_v<int[2]>);
	static_assert(std::is_bounded_array_v<const bool[4]>);
	static_assert(std::is_bounded_array_v<volatile char[8]>);
	static_assert(std::is_bounded_array_v<const volatile short[16]>);

	static_assert(!std::is_bounded_array_v<int[]>);
	static_assert(!std::is_bounded_array_v<test::A>);

	// NOLINTEND(cppcoreguidelines-avoid-c-arrays,modernize-avoid-c-arrays)
	return true;
}

constexpr bool is_unbounded_array() noexcept {

	// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays,modernize-avoid-c-arrays)
	static_assert(std::is_unbounded_array_v<int[]>);
	static_assert(std::is_unbounded_array_v<const bool[]>);
	static_assert(std::is_unbounded_array_v<volatile char[]>);
	static_assert(std::is_unbounded_array_v<const volatile short[]>);

	static_assert(!std::is_unbounded_array_v<int[2]>);
	static_assert(!std::is_unbounded_array_v<test::A>);

	// NOLINTEND(cppcoreguidelines-avoid-c-arrays,modernize-avoid-c-arrays)

	return true;
}


constexpr bool is_constructible() noexcept {

	/* BUG(aki): Needs more robust tests */

	static_assert(std::is_constructible_v<test::A>);
	static_assert(std::is_constructible_v<test::P, const test::P&>);
	static_assert(std::is_constructible_v<test::U, int>);

	static_assert(!std::is_constructible_v<test::A, test::N>);
	static_assert(!std::is_constructible_v<test::N, const test::N&>);

	return true;
}

constexpr bool is_trivially_constructible() noexcept {

	/* BUG(aki): Needs more robust tests */

	static_assert(std::is_trivially_constructible_v<test::A>);
	static_assert(std::is_trivially_constructible_v<test::P, const test::P&>);

	static_assert(!std::is_trivially_constructible_v<test::Y, int>);
	static_assert(!std::is_trivially_constructible_v<test::N, const test::N&>);

	return true;
}

constexpr bool is_nothrow_constructible() noexcept {

	/* BUG(aki): Needs more robust tests */

	static_assert(std::is_nothrow_constructible_v<test::A>);
	static_assert(std::is_nothrow_constructible_v<test::M>);
	static_assert(std::is_nothrow_constructible_v<test::P, const test::P&>);

	static_assert(!std::is_nothrow_constructible_v<test::U, int>);

	return true;
}

constexpr bool is_default_constructible() noexcept {

	/* BUG(aki): Needs more robust tests */

	static_assert(std::is_default_constructible_v<test::A>);
	static_assert(std::is_default_constructible_v<test::M>);
	static_assert(std::is_default_constructible_v<test::O>);
	static_assert(std::is_default_constructible_v<test::AA>);

	static_assert(!std::is_default_constructible_v<test::N>);
	static_assert(!std::is_default_constructible_v<test::U>);
	static_assert(!std::is_default_constructible_v<test::Y>);

	return true;
}

constexpr bool is_trivially_default_constructible() noexcept {

	/* BUG(aki): Needs more robust tests */

	static_assert(std::is_trivially_default_constructible_v<test::A>);
	static_assert(std::is_trivially_default_constructible_v<test::M>);
	static_assert(std::is_trivially_default_constructible_v<test::AA>);

	static_assert(!std::is_trivially_default_constructible_v<test::N>);
	static_assert(!std::is_trivially_default_constructible_v<test::O>);
	static_assert(!std::is_trivially_default_constructible_v<test::U>);
	static_assert(!std::is_trivially_default_constructible_v<test::Y>);

	return true;
}

constexpr bool is_nothrow_default_constructible() noexcept {

	/* BUG(aki): Needs more robust tests */

	static_assert(std::is_nothrow_default_constructible_v<test::A>);
	static_assert(std::is_nothrow_default_constructible_v<test::M>);
	static_assert(std::is_nothrow_default_constructible_v<test::O>);
	static_assert(std::is_nothrow_default_constructible_v<test::AA>);

	return true;
}

constexpr bool is_copy_constructible() noexcept {

	/* BUG(aki): Needs more robust tests */
	static_assert(std::is_copy_constructible_v<test::A>);
	static_assert(std::is_copy_constructible_v<test::P>);
	static_assert(std::is_copy_constructible_v<test::AA>);
	static_assert(std::is_copy_constructible_v<test::AP>);
	static_assert(!std::is_copy_constructible_v<test::N>);
	static_assert(!std::is_copy_constructible_v<test::O>);

	return true;
}

constexpr bool is_trivially_copy_constructible() noexcept {

	/* BUG(aki): Needs more robust tests */
	static_assert(std::is_trivially_copy_constructible_v<test::A>);
	static_assert(std::is_trivially_copy_constructible_v<test::P>);
	static_assert(std::is_trivially_copy_constructible_v<test::AA>);
	static_assert(!std::is_trivially_copy_constructible_v<test::N>);
	static_assert(!std::is_trivially_copy_constructible_v<test::O>);
	static_assert(!std::is_trivially_copy_constructible_v<test::AP>);

	return true;
}

constexpr bool is_nothrow_copy_constructible() noexcept {

	/* BUG(aki): Needs more robust tests */
	static_assert(std::is_nothrow_copy_constructible_v<test::A>);
	static_assert(std::is_nothrow_copy_constructible_v<test::P>);
	static_assert(std::is_nothrow_copy_constructible_v<test::AA>);
	static_assert(!std::is_nothrow_copy_constructible_v<test::O>);
	static_assert(!std::is_nothrow_copy_constructible_v<test::AP>);

	return true;
}

constexpr bool is_move_constructible() noexcept {

	/* BUG(aki): Needs more robust tests */
	static_assert(std::is_move_constructible_v<test::A>);
	static_assert(std::is_move_constructible_v<test::P>);
	static_assert(std::is_move_constructible_v<test::AQ>);
	static_assert(!std::is_move_constructible_v<test::AA>);
	static_assert(!std::is_move_constructible_v<test::AA>);

	return true;
}

constexpr bool is_trivially_move_constructible() noexcept {

	/* BUG(aki): Needs more robust tests */
	static_assert(std::is_nothrow_move_constructible_v<test::A>);
	static_assert(std::is_trivially_move_constructible_v<test::P>);
	static_assert(!std::is_trivially_move_constructible_v<test::AQ>);
	static_assert(!std::is_trivially_move_constructible_v<test::AA>);
	static_assert(!std::is_trivially_move_constructible_v<test::AA>);

	return true;
}

constexpr bool is_nothrow_move_constructible() noexcept {

	/* BUG(aki): Needs more robust tests */
	static_assert(std::is_nothrow_move_constructible_v<test::A>);
	static_assert(std::is_nothrow_move_constructible_v<test::P>);
	static_assert(!std::is_nothrow_move_constructible_v<test::AQ>);
	static_assert(!std::is_nothrow_move_constructible_v<test::AA>);
	static_assert(!std::is_nothrow_move_constructible_v<test::AA>);

	return true;
}

constexpr bool is_assignable() noexcept {

	return true;
}

constexpr bool is_trivially_assignable() noexcept {

	return true;
}

constexpr bool is_nothrow_assignable() noexcept {

	return true;
}

constexpr bool is_copy_assignable() noexcept {

	return true;
}

constexpr bool is_trivially_copy_assignable() noexcept {

	return true;
}

constexpr bool is_nothrow_copy_assignable() noexcept {

	return true;
}

constexpr bool is_move_assignable() noexcept {

	return true;
}

constexpr bool is_trivially_move_assignable() noexcept {

	return true;
}

constexpr bool is_nothrow_move_assignable() noexcept {

	return true;
}

constexpr bool is_destructible() noexcept {

	return true;
}

constexpr bool is_trivially_destructible() noexcept {

	return true;
}

constexpr bool is_nothrow_destructible() noexcept {

	return true;
}

constexpr bool has_virtual_destructor() noexcept {

	return true;
}

constexpr bool is_swappable_with() noexcept {

	return true;
}

constexpr bool is_swappable() noexcept {

	return true;
}

constexpr bool is_nothrow_swappable_with() noexcept {

	return true;
}

constexpr bool is_nothrow_swappable() noexcept {

	return true;
}

constexpr bool alignment_of() noexcept {

	return true;
}

constexpr bool rank() noexcept {

	return true;
}

constexpr bool extent() noexcept {

	return true;
}

constexpr bool is_same() noexcept {

	return true;
}

constexpr bool is_base_of() noexcept {

	return true;
}

constexpr bool is_convertible() noexcept {

	return true;
}

constexpr bool is_nothrow_convertible() noexcept {

	return true;
}

constexpr bool is_layout_compatable() noexcept {

	return true;
}

constexpr bool is_pointer_interconvertible_base_of() noexcept {

	return true;
}

constexpr bool is_invocable() noexcept {

	return true;
}

constexpr bool is_invocable_r() noexcept {

	return true;
}

constexpr bool is_nothrow_invocable() noexcept {

	return true;
}

constexpr bool is_nothrow_invocable_r() noexcept {

	return true;
}

constexpr bool remove_cv() noexcept {

	return true;
}

constexpr bool remove_const() noexcept {

	return true;
}

constexpr bool remove_volatile() noexcept {

	return true;
}

constexpr bool add_cv() noexcept {

	return true;
}

constexpr bool add_const() noexcept {

	return true;
}

constexpr bool add_volatile() noexcept {

	return true;
}

constexpr bool remove_reference() noexcept {

	return true;
}

constexpr bool add_lvalue_reference() noexcept {

	return true;
}

constexpr bool add_rvalue_reference() noexcept {

	return true;
}

constexpr bool remove_pointer() noexcept {

	return true;
}

constexpr bool add_pointer() noexcept {

	return true;
}

constexpr bool make_signed() noexcept {

	return true;
}

constexpr bool make_unsigned() noexcept {

	return true;
}

constexpr bool remove_extent() noexcept {

	return true;
}

constexpr bool remove_all_extents() noexcept {

	return true;
}

constexpr bool aligned_storage() noexcept {



	return true;
}

constexpr bool aligned_union() noexcept {


	return true;
}

constexpr bool decay() noexcept {

	static_assert(std::is_same_v<std::decay_t<int>, int>);
	static_assert(std::is_same_v<std::decay_t<const int>, int>);
	static_assert(std::is_same_v<std::decay_t<volatile int>, int>);
	static_assert(std::is_same_v<std::decay_t<const volatile int>, int>);
	static_assert(std::is_same_v<std::decay_t<int&>, int>);
	static_assert(std::is_same_v<std::decay_t<const int&>, int>);
	static_assert(std::is_same_v<std::decay_t<volatile int&>, int>);
	static_assert(std::is_same_v<std::decay_t<const volatile int&>, int>);

	// NOLINTBEGIN(modernize-avoid-c-arrays,cppcoreguidelines-avoid-c-arrays)

	static_assert(std::is_same_v<std::decay_t<int[]>, int*>);
	static_assert(std::is_same_v<std::decay_t<int[2]>, int*>);
	static_assert(!std::is_same_v<std::decay_t<int[2][4]>, int**>);
	static_assert(std::is_same_v<std::decay_t<int[2][4]>, int(*)[4]>);
	static_assert(std::is_same_v<std::decay_t<int(int)>, int(*)(int)>);

	// NOLINTEND(modernize-avoid-c-arrays,cppcoreguidelines-avoid-c-arrays)
	return true;
}

constexpr bool remove_cvref() noexcept {

	static_assert(std::is_same_v<std::remove_cvref_t<int>, int>);
	static_assert(std::is_same_v<std::remove_cvref_t<const int>, int>);
	static_assert(std::is_same_v<std::remove_cvref_t<volatile int>, int>);
	static_assert(std::is_same_v<std::remove_cvref_t<const volatile int>, int>);
	static_assert(std::is_same_v<std::remove_cvref_t<int&>, int>);
	static_assert(std::is_same_v<std::remove_cvref_t<const int&>, int>);
	static_assert(std::is_same_v<std::remove_cvref_t<volatile int&>, int>);
	static_assert(std::is_same_v<std::remove_cvref_t<const volatile int&>, int>);

	return true;
}

constexpr bool enable_if() noexcept {

	/* BUG(aki): Annoying to test  */

	return true;
}

constexpr bool conditional() noexcept {

	static_assert(std::is_same_v<std::conditional_t<true, int, float>, int>);
	static_assert(std::is_same_v<std::conditional_t<false, int, float>, float>);
	static_assert(std::is_same_v<std::conditional_t<sizeof(int) >= sizeof(float), int, float>, int>);

	return true;
}

constexpr bool common_type() noexcept {

	/* BUG(aki): Needs stdlib impl */

	return true;
}

constexpr bool common_reference() noexcept {

	/* BUG(aki): Needs stdlib impl */

	return true;
}

constexpr bool basic_common_reference() noexcept {

	/* BUG(aki): Needs stdlib impl */

	return true;
}

constexpr bool underlying_type() noexcept {

	/* BUG(aki): Needs more robust tests */
	static_assert(std::is_same_v<std::underlying_type_t<test::B>, int>);

	return true;
}

constexpr bool invoke_result() noexcept {

	/* BUG(aki): Needs stdlib impl */

	return true;
}

constexpr bool void_t() noexcept {

	/* BUG(aki): Needs more robust tests */
	static_assert(std::is_same_v<std::void_t<int, double>, void>);

	return true;
}

constexpr bool type_identity() noexcept {

	static_assert(std::is_same_v<std::type_identity_t<int>, int>);
	static_assert(std::is_same_v<std::type_identity_t<const int>, const int>);
	static_assert(std::is_same_v<std::type_identity_t<volatile int>, volatile int>);
	static_assert(std::is_same_v<std::type_identity_t<const volatile int>, const volatile int>);
	static_assert(std::is_same_v<std::type_identity_t<int&>, int&>);

	return true;
}

constexpr bool unwrap_reference() noexcept {

	/* BUG(aki): Needs stdlib impl */

	return true;
}

constexpr bool unwrap_ref_decay() noexcept {

	/* BUG(aki): Needs stdlib impl */

	return true;
}

constexpr bool conjunction() noexcept {

	/* BUG(aki): Needs more robust tests */
	static_assert(test::same_types<int, int, int>);
	static_assert(!test::same_types<int, int&, int>);
	static_assert(!test::same_types<int, float, void>);

	return true;
}

constexpr bool disjunction() noexcept {

	/* BUG(aki): Needs more robust tests */
	static_assert(std::disjunction_v<std::true_type, std::true_type, std::void_t<>>);
	static_assert(std::disjunction_v<std::false_type, std::true_type, std::void_t<>>);

	return true;
}

constexpr bool negation() noexcept {

	static_assert(std::is_same_v<std::true_type, typename std::negation<std::false_type>::type>);
	static_assert(std::is_same_v<std::false_type, typename std::negation<std::true_type>::type>);

	return true;
}

constexpr bool is_pointer_interconvertible_with_class() noexcept {

	/* NOTE(aki): Clang is lacking support for the compilers internals to support this */
#if !defined(__clang__)
	static_assert(std::is_pointer_interconvertible_with_class(&test::AM::foo));
#endif

	return true;
}

constexpr bool is_corresponding_member() noexcept {

	/* NOTE(aki): Clang is lacking support for the compilers internals to support this */
#if !defined(__clang__)
	static_assert(std::is_corresponding_member(&test::AM::foo, &test::AN::baz));
	static_assert(std::is_corresponding_member(&test::AM::bar, &test::AN::qux));
	static_assert(std::is_corresponding_member(&test::AO::foo, &test::AO::baz));
#endif

	return true;
}

constexpr bool is_constant_evaluated() noexcept {
	/* ¯\_(ツ)_/¯ */
	return std::is_constant_evaluated();
}


// NOLINTNEXTLINE(readability-named-parameter)
int main(int, char**) {

	constexpr bool res{
		is_void() &&
		is_null_pointer() &&
		is_integral() &&
		is_floating_point() &&
		is_array() &&
		is_enum() &&
		is_union() &&
		is_class() &&
		is_function() &&
		is_pointer() &&
		is_lvalue_reference() &&
		is_rvalue_reference() &&
		is_member_object_pointer() &&
		is_member_function_pointer() &&
		is_fundamental() &&
		is_arithmetic() &&
		is_scalar() &&
		is_object() &&
		is_compound() &&
		is_reference() &&
		is_member_pointer() &&
		is_const() &&
		is_volatile() &&
		is_trivial() &&
		is_trivially_copyable() &&
		is_standard_layout() &&
		is_pod() &&
		has_unique_object_representations() &&
		is_empty() &&
		is_polymorphic() &&
		is_abstract() &&
		is_final() &&
		is_aggregate() &&
		is_signed() &&
		is_unsigned() &&
		is_bounded_array() &&
		is_unbounded_array() &&
		is_constructible() &&
		is_trivially_constructible() &&
		is_nothrow_constructible() &&
		is_default_constructible() &&
		is_trivially_default_constructible() &&
		is_nothrow_default_constructible() &&
		is_copy_constructible() &&
		is_trivially_copy_constructible() &&
		is_nothrow_copy_constructible() &&
		is_move_constructible() &&
		is_trivially_move_constructible() &&
		is_nothrow_move_constructible() &&
		is_assignable() &&
		is_trivially_assignable() &&
		is_nothrow_assignable() &&
		is_copy_assignable() &&
		is_trivially_copy_assignable() &&
		is_nothrow_copy_assignable() &&
		is_move_assignable() &&
		is_trivially_move_assignable() &&
		is_nothrow_move_assignable() &&
		is_destructible() &&
		is_trivially_destructible() &&
		is_nothrow_destructible() &&
		has_virtual_destructor() &&
		is_swappable_with() &&
		is_swappable() &&
		is_nothrow_swappable_with() &&
		is_nothrow_swappable() &&
		alignment_of() &&
		rank() &&
		extent() &&
		is_same() &&
		is_base_of() &&
		is_convertible() &&
		is_nothrow_convertible() &&
		is_layout_compatable() &&
		is_pointer_interconvertible_base_of() &&
		is_invocable() &&
		is_invocable_r() &&
		is_nothrow_invocable() &&
		is_nothrow_invocable_r() &&
		remove_cv() &&
		remove_const() &&
		remove_volatile() &&
		add_cv() &&
		add_const() &&
		add_volatile() &&
		remove_reference() &&
		add_lvalue_reference() &&
		add_rvalue_reference() &&
		remove_pointer() &&
		add_pointer() &&
		make_signed() &&
		make_unsigned() &&
		remove_extent() &&
		remove_all_extents() &&
		aligned_storage() &&
		aligned_union() &&
		decay() &&
		remove_cvref() &&
		enable_if() &&
		conditional() &&
		common_type() &&
		common_reference() &&
		basic_common_reference() &&
		underlying_type() &&
		invoke_result() &&
		void_t() &&
		type_identity() &&
		unwrap_reference() &&
		unwrap_ref_decay() &&
		conjunction() &&
		disjunction() &&
		negation() &&
		is_pointer_interconvertible_with_class() &&
		is_corresponding_member() &&
		is_constant_evaluated()
	};

	if (!res) {
		return 1;
	}

	return 0;
}
