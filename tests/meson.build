# SPDX-License-Identifier: BSD-3-Clause

doctest = dependency('doctest', required: false, version: '>=2.4.11')
if not doctest.found()
	message('Did not find local doctest install, bundling')
	doctest_wrap = subproject('doctest', default_options: [])
	doctest = dependency('doctest')
endif


headers = [
	'bit',
	'cfloat',
	'climits',
	'cstddef',
	'cstdint',
	'limits',
	'source_location',
	'type_traits',
]


extra_args = cxx.get_supported_arguments([
	'-fconcepts-diagnostics-depth=4',
])

foreach hdr : headers
	foreach mode : ['debug', 'debugoptimized', 'release']
		foreach fallback_impl : [true, false]
			if fallback_impl
				fallback_mode = 'fallback'
				extra_args += '-D__ABYSS_DEBUG_FALLBACK_IMPLS'
			else
				fallback_mode = 'no-fallback'
			endif

			test(
				'header-@0@-@1@-@2@'.format(hdr, mode, fallback_mode),
				executable(
					'header-@0@-@1@-@2@-test'.format(hdr, mode, fallback_mode),
					'@0@.cc'.format(hdr),
					include_directories: _lib_include,
					dependencies: [ doctest ],
					cpp_args: extra_args,
					override_options: {
						'buildtype': mode,
						'b_sanitize': is_windows ? 'none' : 'address,undefined',
						'debug': mode.startswith('debug')
					}
				),
				is_parallel: true,
			)
		endforeach
	endforeach
endforeach
