# SPDX-License-Identifier: BSD-3-Clause

# This will be filled out as they're implemented
abyss_headers = files([
	'bit',
	'cfloat',
	'climits',
	'cstddef',
	'cstdint',
	'cxxabi.hh',
	'limits',
	'source_location',
	'type_traits',
	'version'
])

abyss_headers_runtime = files([
	'cinttypes',
])

abyss_headers_runtime_threads = files([

])

abyss_headers_rtti = files([
])

abyss_headers_exceptions = files([
])

abyss_headers_23_supplemental = files([
])

abyss_headers_extra = files([

])


library_config = configuration_data()

if not meson.is_subproject() and (not install_only_runtime)
	install_headers(abyss_headers, subdir: 'abyss')
endif


if runtime_enabled.allowed()
	warning('Runtime support is experimental and/or completely broken!')
	library_config.set('ABYSS_RUNTIME_SUPPORT', true)
	if not meson.is_subproject() and (not install_only_runtime)
		install_headers(abyss_headers_runtime, subdir: 'abyss')
	endif
endif

if threading_enabled.allowed()
	warning('Thread support is experimental and/or completely broken!')
	library_config.set('ABYSS_THREADING_SUPPORT', true)
	if not meson.is_subproject() and (not install_only_runtime)
		install_headers(abyss_headers_runtime_threads, subdir: 'abyss')
	endif
endif

if rtti_enabled.allowed()
	warning('RTTI support is experimental and/or completely broken!')
	library_config.set('ABYSS_RTTI_SUPPORT', true)
	if not meson.is_subproject() and (not install_only_runtime)
		install_headers(abyss_headers_rtti, subdir: 'abyss')
	endif
endif

if exceptions_enabled.allowed()
	warning('Exception support is experimental and/or completely broken!')
	library_config.set('ABYSS_EXCEPTION_SUPPORT', true)
	if not meson.is_subproject() and (not install_only_runtime)
		install_headers(abyss_headers_exceptions, subdir: 'abyss')
	endif
endif

if virtual_enabled.allowed()
	warning('Virtual support is experimental and/or completely broken!')
	library_config.set('ABYSS_VIRTUAL_SUPPORT', true)
endif

if cxx23_enabled.allowed()
	library_config.set('ABYSS_STD23_SUPPLEMENTAL', true)
	if not meson.is_subproject() and (not install_only_runtime)
		install_headers(abyss_headers_23_supplemental, subdir: 'abyss')
	endif
endif

if extra_enabled.allowed()
	library_config.set('ABYSS_EXTRA', true)
	if not meson.is_subproject() and (not install_only_runtime)
		install_headers(abyss_headers_extra, subdir: 'abyss')
	endif
endif

subdir('cosmogony')

stdlib_include = include_directories('.')

if runtime_enabled.allowed()
	subdir('runtime')
endif

if platform_library.allowed()
	subdir('pal')
endif
