idl_src = [
  'vkd3d_d3d12.idl',
  'vkd3d_d3d12sdklayers.idl',
  'vkd3d_d3dcommon.idl',
  'vkd3d_dxgi.idl',
  'vkd3d_dxgi1_2.idl',
  'vkd3d_dxgi1_3.idl',
  'vkd3d_dxgi1_4.idl',
  'vkd3d_dxgi1_5.idl',
  'vkd3d_dxgi1_6.idl',
  'vkd3d_dxgibase.idl',
  'vkd3d_dxgiformat.idl',
  'vkd3d_dxgitype.idl',
  'vkd3d_unknown.idl',
  'vkd3d_wine_dxgi.idl'
]

idl_compiler = find_program('widl')

com_header_generator = generator(idl_compiler,
    output    : [ '@BASENAME@.h' ],
    arguments : [ '-h', '-o', '@OUTPUT@', '@INPUT@' ])

com_headers = com_header_generator.process(idl_src)
