# SPDX-License-Identifier: BSD-3-Clause


library_config_header = configure_file(
	configuration: library_config,
	input: 'library_config.hh.in',
	output: 'library_config.hh'
)

# These are internal only headers full of spooky implementation details
abyss_cosmogony_headers = files([
	'compiler_support.hh',
	'fundamental.hh',
])


if not meson.is_subproject()
	install_headers(abyss_cosmogony_headers, subdir: 'abyss/cosmogony')
	install_headers(library_config_header,   subdir: 'abyss/cosmogony')
endif
