# SPDX-License-Identifier: BSD-3-Clause
# Abyss Platform Abstraction Library

message('Building Abyss PAL for @0@'.format(host_arch))

pal_srcs = files([])

# TODO(aki): Think about `crt0.o` and other startup object files if we need them?


subdir(host_arch)


abyss_pal = static_library(
	f'abyss-cxx-pal',
	pal_srcs,
	cpp_args: [
		'-D__ABYSS_CXX_RUNTIME_INTERNAL',
	],
	include_directories: [
		stdlib_include, pal_include, include_directories('.'),
	],
	gnu_symbol_visibility: 'inlineshidden',
	implicit_include_directories: false,
	pic: true,
	install: (not meson.is_subproject()),
	install_dir: runtime_install_dir,
)

if not meson.is_subproject()
	_lib_name = f'libabyss-cxx-pal'

	pkgconfig.generate(
		subdirs: '.',
		name: 'abyss-cxx-pal',
		filebase: 'abyss-cxx-pal',
		version: meson.project_version(),
		libraries: [ abyss_pal ] + full_runtime_libs,
		install_dir: runtime_install_dir / 'pkgconfig',
		url: 'https://github.com/lethalbit/abyss',
		description: 'Deeply Embeddable bare-metal C++ standard library: Platform Abstraction Library'
	)

	if runtime_symlinks
		install_symlink(f'@_lib_name@-@host_arch@.a', install_dir: lib_dir, pointing_to: pal_install_dir / f'@_lib_name@.a')
	endif
endif

abyss_pal_dep = declare_dependency(
	link_with: [
		abyss_pal,
		full_runtime_libs,
	],
	version: meson.project_version()
)
