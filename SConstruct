import os
import platform

MODE = 'D'
TARGET_ARCH = 'x86_64'

#env = Environment(tools=["default","msvc"], ENV=os.environ, MODE=MODE, TARGET_ARCH=TARGET_ARCH,RUNTIME="S")
env = Environment(tools=["mingw"], ENV=os.environ, MODE=MODE, TARGET_ARCH=TARGET_ARCH)
env.Tags2Opt()
lib = env.SCsc(".")
# taglib = env.inst_lib_dir()

# inst = env.Install(taglib, lib)
# env.Alias('install', taglib)
