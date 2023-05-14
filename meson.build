project('bonanza', 'c')
subdir('crates')

# third party dependency
cjson_dep = dependency('libcjson')


# Compile some C code as a library
incdir = include_directories('src/include')
c_lib = library('clib', sources: ['src/lib.c'], include_directories: incdir)



executable('bonanza', ['src/main.c'], dependencies: [cjson_dep, rslib_dep], link_with: [c_lib], include_directories: incdir)

# Not sure if arch or meson is being weird but it finds the wrong dependency for cross build
if meson.is_cross_build()
  check_dep = subproject('check').get_variable('check_dep')
else
  check_dep = dependency('check')
endif

test_exe = executable('check', 'tests/check_lib.c', link_with: [c_lib], dependencies: [check_dep, rslib_dep], include_directories: incdir)

test('Core test', test_exe, suite: 'unit')

if meson.is_cross_build()
  test('Core test', test_exe, suite: 'cross-unit')
endif
