# SPDX-License-Identifier: BSD-3-Clause
project(
	'Abyss',
	'cpp',
	default_options: [
		'buildtype=debugoptimized',
		'cpp_std=c++23',
		'warning_level=3',
		'b_ndebug=if-release',
		'b_lto=true',
		'strip=false'
	],
	license: 'BSD-3-Clause',
	version: '0.1.0',
	meson_version: '>= 1.4.0',
	subproject_dir: 'deps'
)

cxx = meson.get_compiler('cpp')

if get_option('cpp_std') not in ['c++20', 'c++23', 'gnu++20', 'gnu++23']
	error('Unsupported C++ Version @0@, must be c++20/gnu++20 or newer'.format(get_option('cpp_std')))
endif

extended_warnings = [
	'-Wdouble-promotion',
	'-Wformat=2',
	'-Wformat-overflow=2',
	'-Wformat-signedness',
	'-Wformat-truncation',
	'-Wnull-dereference',
	'-Wmissing-attributes',
	'-Wmissing-braces',
	'-Wsequence-point',
	'-Werror=return-type',
	'-Wunused',
	'-Wunused-local-typedefs',
	'-Wunused-const-variable=2',
	'-Wmaybe-uninitialized',
	'-Wunknown-pragmas',
	'-Wstrict-aliasing',
	'-Wstrict-overflow=3',
	'-Wstring-compare',
	'-Wstringop-overflow',
	'-Warith-conversion',
	'-Wvla-parameter',
	'-Wduplicated-branches',
	'-Wshadow=local',
	'-Wunsafe-loop-optimizations',
	'-Wbad-function-cast',
	'-Wcast-qual',
	'-Wcast-align=strict',
	'-Wcast-function-type',
	'-Wconversion',
	'-Wdangling-else',
	'-Wsign-conversion',
	'-Wfloat-conversion',
	'-Wredundant-decls',
	'-Wvla',
	'-Wstack-protector',
	'-Wunsuffixed-float-constant',
	'-Wimplicit-fallthrough',
	'-Wxor-used-as-pow',
	'-Wself-move',
	'-Wdangling-reference',
	'-Werror=switch',
]

extra_flags = [ ]

add_project_arguments(
	cxx.get_supported_arguments(extended_warnings),
	language: 'cpp'
)


pkgconfig = import('pkgconfig')


build_tests = get_option('build_tests')

pfx_dir  = get_option('prefix')
bin_dir  = pfx_dir / get_option('bindir')
lib_dir  = pfx_dir / get_option('libdir')
data_dir = pfx_dir / get_option('datadir')

runtime_enabled    = get_option('runtime_components')
rtti_enabled       = get_option('rtti_support')
exceptions_enabled = get_option('exception_support')
virtual_enabled    = get_option('virtual_support')
cxx23_enabled      = get_option('cxx23_supplemental')
extra_enabled      = get_option('extra')

subdir('abyss')

if build_tests
	_lib_include = include_directories('.')
	subdir('tests')
endif


if not meson.is_subproject()
	pkgconfig.generate(
		subdirs: '.',
		name: 'abyss',
		filebase: 'abyss',
		version: meson.project_version(),
		extra_cflags: [ feature_defs ],
		url: 'https://github.com/lethalbit/abyss',
		description: 'Deeply Embeddable bare-metal C++ standard library'
	)
endif

abyss_dep = declare_dependency(
	include_directories: [ stdlib_include ],
	compile_args: [ feature_defs ],
	version: meson.project_version()
)
