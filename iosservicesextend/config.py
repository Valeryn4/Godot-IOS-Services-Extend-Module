def can_build(env, platform):
   return platform =="iphone"

def configure(env):
   pass
   #if env['platform'] == "iphone":
      #env.Append(LINKFLAGS=['-ObjC',])
