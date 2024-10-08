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
	'-Wnrvo'
]

extra_flags = [ ]

add_project_arguments(
	cxx.get_supported_arguments(extended_warnings),
	language: 'cpp'
)

host_arch = '@0@-@1@'.format(host_machine.cpu_family(), host_machine.kernel())

pkgconfig = import('pkgconfig')

is_windows = (host_machine.system() == 'windows')

build_tests      = get_option('build_tests')
build_benchmarks = get_option('build_benchmarks')

pfx_dir  = get_option('prefix')
bin_dir  = pfx_dir / get_option('bindir')
lib_dir  = pfx_dir / get_option('libdir')
data_dir = pfx_dir / get_option('datadir')

runtime_install_dir = lib_dir / 'abyss' / host_arch

runtime_enabled      = get_option('runtime_components')
threading_enabled    = get_option('threading_support').disable_if(not runtime_enabled.allowed())
rtti_enabled         = get_option('rtti_support').disable_if(not runtime_enabled.allowed())
exceptions_enabled   = get_option('exception_support').disable_if(not runtime_enabled.allowed()).disable_if(not rtti_enabled.allowed())
virtual_enabled      = get_option('virtual_support').disable_if(not runtime_enabled.allowed()).disable_if(not rtti_enabled.allowed())
cxx23_enabled        = get_option('cxx23_supplemental')
extra_enabled        = get_option('extra')
runtime_symlinks     = get_option('runtime_symlinks')
install_only_runtime = get_option('only_runtime').disable_if(not runtime_enabled.allowed()).allowed()

platform_library     = get_option('platform_library').disable_if(not runtime_enabled.allowed()).disable_if(is_windows)

stdlib_include = include_directories('.')

subdir('abyss')

if build_tests
	subdir('tests')
endif

if build_benchmarks
	subdir('benchmarks')
endif


if not meson.is_subproject() and (not install_only_runtime)
	pkgconfig.generate(
		subdirs: '.',
		name: 'abyss',
		filebase: 'abyss',
		version: meson.project_version(),
		url: 'https://github.com/lethalbit/abyss',
		description: 'Deeply Embeddable bare-metal C++ standard library'
	)
endif

abyss_dep = declare_dependency(
	include_directories: [ stdlib_include ],
	version: meson.project_version()
)
