project('vkd3d', ['c'], version: '1.1')

vkd3d_compiler = meson.get_compiler('c')
system_python = import('python').find_installation('python3')

vkd3d_include = include_directories(['./include', './include/private'])

if host_machine.system() == 'windows'
  vulkan_dep = vkd3d_compiler.find_library('vulkan-1')
  lib_dxgi = vkd3d_compiler.find_library('dxgi')
else
  vulkan_dep = vkd3d_compiler.find_library('vulkan')
  lib_dxgi = declare_dependency(link_args: [ '-ldxgi' ])
endif
spirv_tools_dep = dependency('SPIRV-Tools', required : false, version : '>= 2019.3')
thread_dep = dependency('threads')
lib_dl = vkd3d_compiler.find_library('dl', required : false)

vkd3d_version = vcs_tag(
  command: ['git', 'describe', '--dirty=+'],
  input:  'vkd3d_version.c.in',
  output: 'vkd3d_version.c')



#generate config.h because autotools 😩

defines = []

defines += 'PACKAGE_VERSION="'+meson.project_version()+'"'
defines += 'PACKAGE_NAME="'+meson.project_name()+'"'

defines += 'SONAME_LIBVULKAN="'+'libvulkan.so.1'+'"'

if lib_dl.found()
  defines += 'HAVE_DLFCN_H'
endif

if vkd3d_compiler.compiles('int leading_bits(unsigned int x) {return __builtin_clz(x);}')
  defines += 'HAVE_BUILTIN_CLZ=1'
endif

if vkd3d_compiler.compiles('int popcount(unsigned int x) {return __builtin_popcount(x);}')
  defines += 'HAVE_BUILTIN_POPCOUNT=1'
endif

if vkd3d_compiler.compiles('int add_and_fetch(int *atom, int inc) {return __sync_add_and_fetch(atom, inc);}')
  defines += 'HAVE_SYNC_ADD_AND_FETCH=1'
endif

if vkd3d_compiler.compiles('int sub_and_fetch(int *atom, int dec) {return __sync_sub_and_fetch(atom, dec);}')
  defines += 'HAVE_SYNC_SUB_AND_FETCH=1'
endif

unified_spirv = vkd3d_compiler.check_header('spirv/unified1/spirv.h')
unified_glsl = vkd3d_compiler.check_header('spirv/unified1/GLSL.std.450.h')

assert (unified_spirv or vkd3d_compiler.check_header('vulkan/spirv.h'), 'spirv.h not found.')
assert (unified_glsl or vkd3d_compiler.check_header('vulkan/GLSL.std.450.h'), 'GLSL.std.450.h not found.')

if (unified_spirv)
  defines += 'HAVE_SPIRV_UNIFIED1_SPIRV_H=1'
endif

if (unified_glsl)
  defines += 'HAVE_SPIRV_UNIFIED1_GLSL_STD_450_H=1'
endif

config_h = custom_target(
  'config_h',
  output: 'config.h',
  input: 'config_h_gen.py',
  command: [system_python, '@INPUT@', '--output', '@OUTPUT@', defines]
)



subdir('include')
subdir('libs')
subdir('programs')
