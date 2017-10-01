Import('env')

l_env = env.Clone()

#l_env.Use(["boost"])

l_env.Append(CPPPATH=["."])

src = l_env.Glob("*.cpp")
lib = l_env.Program(l_env.DkName("main"),src)

Return("lib")
