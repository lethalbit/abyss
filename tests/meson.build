# SPDX-License-Identifier: BSD-3-Clause

doctest = dependency('doctest', required: false, version: '>=2.4.11')
if not doctest.found()
	message('Did not find local doctest install, bundling')
	doctest_wrap = subproject('doctest', default_options: [])
	doctest = dependency('doctest')
endif


headers = [
	'cfloat',
	'climits',
	'cstddef',
	'cstdint',
	'limits',
	'source_location',
]

foreach hdr : headers
	foreach mode : ['debug', 'debugoptimized', 'release']
		test(
			'header-@0@-@1@'.format(hdr, mode),
			executable(
				'header-@0@-@1@-test'.format(hdr, mode),
				'@0@.cc'.format(hdr),
				include_directories: _lib_include,
				dependencies: [ doctest ],
				override_options: {
					'buildtype': mode,
					'b_sanitize': 'address,undefined',
					'debug': mode.startswith('debug')
				}
			),
			is_parallel: true,
		)
	endforeach
endforeach
