import argparse

parser = argparse.ArgumentParser(description='Generate a list header with definitions (config.h)')
parser.add_argument('defines', nargs='+', action='store', metavar='define',
                    help='A define with the format <key>=<value>, =<value> is optional')
parser.add_argument('--output', dest='output', type=argparse.FileType('w'))

args = parser.parse_args()

def get_c_define(key, value = None):
  return "#define " + key + (" " + value if value else "")

for define in args.defines:
  pair = define.split('=', 1)
  args.output.write(get_c_define(pair[0], pair[1] if len(pair) > 1 else None) + "\n\n")
