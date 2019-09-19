vkd3d_common_src = [
  'debug.c',
  'memory.c',
  'utf8.c'
]

vkd3d_common_lib = static_library('vkd3d-common', vkd3d_common_src, config_h,
  include_directories: vkd3d_include
)

vkd3d_common_dep = declare_dependency(
  link_with: vkd3d_common_lib
)