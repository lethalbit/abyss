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
	'cstdint',
	'limits',
	'source_location',
]

foreach hdr : headers
	test(
		hdr,
		executable(
			'@0@-test'.format(hdr),
			'@0@.cc'.format(hdr),
			include_directories: _lib_include,
			dependencies: [ doctest ]
		),
		is_parallel: true,
	)
endforeach
