d3d12_dll = shared_library('d3d12', files('d3d12_main.c'), com_headers,
  name_prefix: '',
  dependencies: [lib_dxgi, vkd3d_dep],
  include_directories: vkd3d_include,
  install: true
  #vs_module_defs: 'd3d12'
)
