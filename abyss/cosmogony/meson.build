# SPDX-License-Identifier: BSD-3-Clause

# These are internal only headers full of spooky implementation details
abyss_cosmogony_headers = files([
	'fundamental.hh'
])


if not meson.is_subproject()
	install_headers(abyss_cosmogony_headers, subdir: 'abyss/cosmogony')
endif
