dxgi_src = [
  'adapter.c',
  'device.c',
  'dxgi_main.c',
  'factory.c',
  'output.c',
  'surface.c',
  'utils.c'
]

dxgi_dll = shared_library('dxgi', dxgi_src, com_headers,
  name_prefix: '',
  dependencies: vkd3d_dep,
  include_directories: vkd3d_include,
  install: true
  #vs_module_defs: 'dxgi'
)
