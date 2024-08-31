# SPDX-License-Identifier: BSD-3-Clause

runtime_basename = 'abyss-cxx-runtime'

message('Building Abyss runtimes for @0@'.format(host_arch))

generic_runtime_srcs = files([
])

abyss_runtime_generic = static_library(
	f'@runtime_basename@-generic',
	generic_runtime_srcs,
	cpp_args: [
		'-D__ABYSS_CXX_RUNTIME_INTERNAL',
	],
	include_directories: [
		stdlib_include, include_directories('.'),
	],
	gnu_symbol_visibility: 'inlineshidden',
	implicit_include_directories: false,
	pic: true,
	install: (not meson.is_subproject()),
	install_dir: runtime_install_dir,
)

if not meson.is_subproject()
	_lib_name = f'lib@runtime_basename@-generic'

	pkgconfig.generate(
		subdirs: '.',
		name: 'abyss-runtime-generic',
		filebase: 'abyss-runtime-generic',
		version: meson.project_version(),
		libraries: abyss_runtime_generic,
		install_dir: runtime_install_dir / 'pkgconfig',
		url: 'https://github.com/lethalbit/abyss',
		description: 'Deeply Embeddable bare-metal C++ standard library: Generic runtime components'
	)

	if runtime_symlinks
		install_symlink(f'@_lib_name@-@host_arch@.a', install_dir: lib_dir, pointing_to: runtime_install_dir / f'@_lib_name@.a')
	endif
endif

abyss_runtime_generic_dep = declare_dependency(
	link_with: abyss_runtime_generic,
	version: meson.project_version()
)



full_runtime_deps = [
	abyss_runtime_generic_dep
]

full_runtime_libs = [
	abyss_runtime_generic
]

if threading_enabled.allowed()
	subdir('threading')
	full_runtime_deps += [ abyss_runtime_threading_dep ]
	full_runtime_libs += [ abyss_runtime_threading     ]
endif

if rtti_enabled.allowed()
	subdir('rtti')
	full_runtime_deps += [ abyss_runtime_rtti_dep ]
	full_runtime_libs += [ abyss_runtime_rtti     ]
endif

if exceptions_enabled.allowed()
	subdir('exceptions')
	full_runtime_deps += [ abyss_runtime_exceptions_dep ]
	full_runtime_libs += [ abyss_runtime_exceptions     ]
endif

if not meson.is_subproject()
	pkgconfig.generate(
		subdirs: '.',
		name: 'abyss-runtime-full',
		filebase: 'abyss-runtime-full',
		version: meson.project_version(),
		libraries: full_runtime_libs,
		install_dir: runtime_install_dir / 'pkgconfig',
		url: 'https://github.com/lethalbit/abyss',
		description: 'Deeply Embeddable bare-metal C++ standard library: All runtime components'
	)
endif

abyss_runtime_full_dep = declare_dependency(
	dependencies: full_runtime_deps,
	version: meson.project_version()
)
