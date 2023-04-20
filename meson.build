project('bonanza', 'c', 'rust')

cjson_dep = subproject('cjson').get_variable('libcjson_dep')

executable('bonanza', 'src/main.c', dependencies: cjson_dep)
