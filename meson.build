project('bonanza', 'c', 'rust')

# third party dependency
cjson_dep = subproject('cjson').get_variable('libcjson_dep')

# Generate C headers for Rust code, requires cbindgen installed
cbindgen = find_program('cbindgen')
rs_h = custom_target(
    'hellors.h',
    input: 'src/lib.rs',
    output: 'hellors.h',
    command: [cbindgen, '--lang=C', '--output=@OUTPUT@', '@INPUT@'],
)
rust_lib = static_library(
  'rslib',
  sources: ['src/lib.rs'],
  rust_crate_type: 'staticlib',
  install: true
)

# Compile some C code as a library
incdir = include_directories('src/include')
c_lib = library('clib', sources: ['src/lib.c'], include_directories: incdir)



executable('bonanza', ['src/main.c', rs_h], dependencies: cjson_dep, link_with: [rust_lib, c_lib], include_directories: incdir)

# unit test config
check_dep = dependency('check', required: true)
test_exe = executable('check', 'tests/check_lib.c', link_with: [c_lib], dependencies: check_dep, include_directories: incdir)
rs_test_exe = executable('rstest', ['src/lib.rs'], rust_args: ['--test', '-Cinstrument-coverage'])

test('Core test', test_exe, suite: 'unit')
test('Rs lib test', rs_test_exe, suite: 'unit')
