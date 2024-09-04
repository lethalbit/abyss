/* SPDX-License-Identifier: BSD-3-Clause */
#pragma once
#if !defined(ABYSS_CXXABI)
#define ABYSS_CXXABI

/*
	This file contains stubs and types for implementing the ABI portion of a C++ runtime for use in
	an embedded or bare-metal context.

	The implementation of these stubs is mostly optional depending on what language features you want
	or need.

	For reference:
		Itanium C++ ABI - Base: https://itanium-cxx-abi.github.io/cxx-abi/abi.html
		Itanium C++ ABI - Exceptions: https://itanium-cxx-abi.github.io/cxx-abi/abi-eh.html

	A note on exceptions and casting support:

		In general RTTI is not supported, and therefore these features are not supported,
		this may change in the future.
*/

#include <abyss/cstddef>
#include <abyss/cstdint>


namespace __cxxabiv1 {
	/* These types are not explicitly defined by the ABI standard but are generally useful */
	using __cxa_cdtor = void (*)(void* /* this */);
	using __cxa_cdtor_t    = void  (*)(void* /* this */);
	using __cxa_cdtor2_t   = void  (*)(void* /* dest */, void* /* src */);
	using __cxa_alloc_t    = void* (*)(std::size_t /* size */);
	using __cxa_dealloc_t  = void  (*)(void* /* obj */);
	using __cxa_dealloc2_t = void  (*)(void* /* obj */, std::size_t /* size */);

#if defined(ABYSS_RTTI_SUPPORT)
	/* WARN(aki): RTTI-based components not implemented (dynamic_cast, std::type_id, exceptions) */
#endif
	/* Itanium C++ ABI - Base § 3.2.6 & 3.2.7 (Virtual Calls) */
	/* TODO(aki): This is woefully incomplete an might have some RTTI based dependance */
	extern "C" void __cxa_pure_virtual();
	extern "C" void __cxa_deleted_virtual();

	/* Itanium C++ ABI - Base § 3.3.1 & 3.3.2 (Sub-object Construction & Construction by Inherited Constructor) */
	/* NOTE(aki): See TODO above */

	/* Itanium C++ ABI - Base § 3.3.3 (One-time Construction) */
	extern "C" int __cxa_guard_acquire(std::int64_t* guard_object);
	extern "C" void __cxa_guard_release(std::int64_t* guard_object) noexcept;
	extern "C" void __cxa_guard_abort(std::int64_t* guard_object) noexcept;

	/* Itanium C++ ABI - Base § 3.3.4 (Array Construction and Destruction) */
	extern "C" void* __cxa_vec_new(
		std::size_t element_count, std::size_t element_size, std::size_t padding_size,
		__cxa_cdtor_t ctor, __cxa_cdtor_t dtor
	);
	extern "C" void* __cxa_vec_new2(
		std::size_t element_count, std::size_t element_size, std::size_t padding_size,
		__cxa_cdtor_t ctor, __cxa_cdtor_t dtor,
		__cxa_alloc_t alloc, __cxa_dealloc_t dealloc
	);
	extern "C" void* __cxa_vec_new3(
		std::size_t element_count, std::size_t element_size, std::size_t padding_size,
		__cxa_cdtor_t ctor, __cxa_cdtor_t dtor,
		__cxa_alloc_t alloc, __cxa_dealloc2_t dealloc
	);
	extern "C" void __cxa_throw_bad_array_new_length(void);
	extern "C" void __cxa_vec_ctor(
		void* array_addr, std::size_t element_count, std::size_t element_size,
		__cxa_cdtor_t ctor, __cxa_cdtor_t dtor
	);
	extern "C" void __cxa_vec_dtor(
		void* array_addr, std::size_t element_count, std::size_t element_size, __cxa_cdtor_t dtor
	);
	extern "C" void __cxa_vec_cleanup(
		void* array_addr, std::size_t element_count, std::size_t element_size, __cxa_cdtor_t dtor
	) noexcept;
	extern "C" void __cxa_vec_delete(
		void* array_addr, std::size_t element_count, std::size_t element_size, std::size_t padding_size,
		__cxa_cdtor_t dtor
	);
	extern "C" void __cxa_vec_delete2(
		void* array_addr, std::size_t element_count, std::size_t element_size,
		__cxa_cdtor_t dtor, __cxa_dealloc_t dealloc
	);
	extern "C" void __cxa_vec_delete3(
		void* array_addr, std::size_t element_count, std::size_t element_size, std::size_t padding_size,
		__cxa_cdtor_t dtor, __cxa_dealloc2_t dealloc
	);

	/* Itanium C++ ABI - Base § 3.3.5 (Controlling Object Construction Order) */
	/* TODO(aki): Not Implemented */

	/* Itanium C++ ABI - Base § 3.3.6 (DSO Object Destruction) */
	struct __cxa_atexit_func_entry_t {
		__cxa_cdtor_t dtor;
		void* obj_ptr;
		void* dso_hndl;
	};

	extern "C" int __cxa_atexit(__cxa_cdtor_t func, void* obj, void* dso) noexcept;
	extern "C" void __cxa_finalize(void* dso);

	/* Itanium C++ ABI - Base § 3.4 (Name Demangling) */
	extern "C" char* __cxa_demangle(const char* mangled, char* buff, std::size_t* len, int* status);
}

/* Itanium C++ ABI - Base § 1.3 */
namespace abi = __cxxabiv1;

#endif /* ABYSS_CXXABI */
/* vim: set ft=cpp ts=4 sw=4 noexpandtab: */
