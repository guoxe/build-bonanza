project('bonanza', 'c', 'rust')

cjson_dep = subproject('cjson').get_variable('libcjson_dep')

cbindgen = find_program('cbindgen')

rs_h = custom_target(
    'hellors.h',
    input: 'src/rslib/src/lib.rs',
    output: 'hellors.h',
    command: [cbindgen, '--lang=C', '--output=@OUTPUT@', '@INPUT@'],
)
rust_lib = static_library(
  'rslib',
  sources: ['src/rslib/src/lib.rs'],
  rust_crate_type: 'staticlib',
  install: true
)


executable('bonanza', ['src/main.c', rs_h], dependencies: cjson_dep, link_with: rust_lib)
