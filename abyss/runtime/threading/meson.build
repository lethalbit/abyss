# SPDX-License-Identifier: BSD-3-Clause

threading_runtime_srcs = files([
])

abyss_runtime_threading = static_library(
	f'@runtime_basename@-threading',
	threading_runtime_srcs,
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
	_lib_name = f'lib@runtime_basename@-threading'

	pkgconfig.generate(
		subdirs: '.',
		name: 'abyss-runtime-threading',
		filebase: 'abyss-runtime-threading',
		version: meson.project_version(),
		libraries: abyss_runtime_threading,
		install_dir: runtime_install_dir / 'pkgconfig',
		url: 'https://github.com/lethalbit/abyss',
		description: 'Deeply Embeddable bare-metal C++ standard library: Threading runtime components'
	)

	if runtime_symlinks
		install_symlink(f'@_lib_name@-@host_arch@.a', install_dir: lib_dir, pointing_to: runtime_install_dir / f'@_lib_name@.a')
	endif
endif

abyss_runtime_threading_dep = declare_dependency(
	link_with: abyss_runtime_threading,
	version: meson.project_version()
)
