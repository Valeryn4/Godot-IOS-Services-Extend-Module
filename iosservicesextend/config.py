def can_build(plat):
	return plat=="iphone"

def configure(env):
	if env['platform'] == "iphone":
		env.Append(LINKFLAGS=['-ObjC',])
