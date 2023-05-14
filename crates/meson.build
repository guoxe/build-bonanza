cargo = find_program('cargo')
cbindgen = find_program('cbindgen')

outfile = 'librslib.so'
h_file = 'rslib.h'

rs_h = custom_target(
    'rs_h',
    input: 'rslib/src/lib.rs',
    output: h_file,
    command: [cbindgen, '--lang=C', '--output=@OUTPUT@', '@INPUT@'],
)

cargo_cmd = [cargo, 'build',
             '-Z', 'unstable-options',
             '--target-dir', meson.project_build_root(),
             '--out-dir', '@OUTDIR@',
             '--manifest-path', meson.project_source_root() / 'crates' / 'Cargo.toml',
]

if meson.is_cross_build()
  # Add more targets as required
  if host_machine.cpu_family() == 'aarch64'
    cargo_cmd += ['--target', 'aarch64-unknown-linux-gnu',
      '--config', 'target.aarch64-unknown-linux-gnu.linker="aarch64-linux-gnu-gcc"',
    ]
  else
    assert(false, 'Only aarch64 is currently supported for cross compilation')
  endif
endif

# We only have one crate atm, if there we more one would wrap them in different
# dependencies. The target should only build one crate to maintain some sort of
# sanity (and proper rebuild tracking)
rslib = custom_target('rslib',
                      input: ['rslib/src/lib.rs'],
                      output: outfile,
                      command: cargo_cmd,
                     )

rslib_dep = declare_dependency(sources: [rslib, rs_h], include_directories: '.')
