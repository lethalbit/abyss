# SPDX-License-Identifier: BSD-3-Clause

subdir('cosmogony')

# This will be filled out as they're implemented
abyss_headers = files([
	'cfloat',
	'climits',
	'cstddef',
	'cstdint',
	'cxxabi.hh',
	'limits',
	'source_location',
	'type_traits',
])

abyss_headers_runtime = files([

])

abyss_headers_rtti = files([
])

abyss_headers_exceptions = files([
])

abyss_headers_23_supplemental = files([
])

abyss_headers_extra = files([

])

feature_defs = []

if not meson.is_subproject()
	install_headers(abyss_headers, subdir: 'abyss')
endif

if virtual_enabled.allowed()
	warning('Virtual support is experimental and/or completely broken!')
	feature_defs += [ '-DABYSS_VIRTUAL_SUPPORT' ]
endif

if runtime_enabled.allowed()
	warning('Runtime support is experimental and/or completely broken!')
	feature_defs += [ '-DABYSS_RUNTIME_SUPPORT' ]
	if not meson.is_subproject()
		install_headers(abyss_headers_runtime, subdir: 'abyss')
	endif
endif

if rtti_enabled.allowed()
	warning('RTTI support is experimental and/or completely broken!')
	feature_defs += [ '-DABYSS_RTTI_SUPPORT' ]
	if not meson.is_subproject()
		install_headers(abyss_headers_rtti, subdir: 'abyss')
	endif
endif

if exceptions_enabled.allowed()
	warning('Exception support is experimental and/or completely broken!')
	feature_defs += [ '-DABYSS_EXCEPTION_SUPPORT' ]
	if not meson.is_subproject()
		install_headers(abyss_headers_exceptions, subdir: 'abyss')
	endif
endif


if cxx23_enabled.allowed()
	feature_defs += [ '-DABYSS_STD23_SUPPLEMENTAL' ]
	if not meson.is_subproject()
		install_headers(abyss_headers_23_supplemental, subdir: 'abyss')
	endif
endif

if extra_enabled.allowed()
	feature_defs += [ '-DABYSS_EXTRA' ]
	if not meson.is_subproject()
		install_headers(abyss_headers_extra, subdir: 'abyss')
	endif
endif

stdlib_include = include_directories('.')
