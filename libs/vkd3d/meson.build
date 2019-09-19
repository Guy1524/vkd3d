vkd3d_src = [
	'command.c',
	'device.c',
	'resource.c',
	'state.c',
	'utils.c',
	'vkd3d_main.c'
]

thread_dep = dependency('threads')

lib_vkd3d = shared_library('vkd3d', vkd3d_src, com_headers, config_h, vkd3d_version,
  dependencies: [vkd3d_common_dep, vkd3d_shader_dep, vulkan_dep, lib_dl, thread_dep],
  include_directories: vkd3d_include,
  install: true
)

vkd3d_dep = declare_dependency(
  link_with: lib_vkd3d
)
