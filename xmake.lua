set_project('OmniMatrices')
set_version('0.0.1')


set_rules('mode.debug', 'mode.release')
set_languages('c++20')


target('omniMatrices')
	set_kind('static')
	set_policy('build.c++.modules', true)
	add_files('src/omniMatrices/*.cpp|src/omniMatrices/*.m.cpp')
	add_files('src/library/*.m.cpp', { install = true })

target('test')
	set_kind('binary')
	set_policy('build.c++.modules', true)
	add_files('src/main.cpp')
	add_deps('omniMatrices')
