vkd3d_shader_src = [
	'checksum.c',
	'dxbc.c',
	'spirv.c',
	'trace.c',
	'vkd3d_shader_main.c',
	#'vkd3d_shader.map',
]

vkd3d_shader_lib = both_libraries('vkd3d-shader', vkd3d_shader_src, config_h,
  dependencies: [vkd3d_common_dep, spirv_tools_dep],
  include_directories: vkd3d_include,
  install: true
)

vkd3d_shader_dep = declare_dependency(
  link_with: vkd3d_shader_lib.get_shared_lib()
)