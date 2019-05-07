#pragma once

#if x32
#pragma comment (lib,"..\\deps\\glfw-3.2.1\\lib-vc2015\\glfw3.lib")
#else
#pragma comment (lib,"..\\deps\\glfw-3.2.1.bin.WIN64\\lib-vc2015\\glfw3.lib")
#endif
#pragma comment (lib,"..\\deps\\glew-2.1.0\\lib\\Release\\Win32\\glew32.lib")
#pragma comment (lib,"opengl32.lib")
#pragma comment (lib,"glu32.lib")
#pragma comment (lib,"..\\deps\\assimp\\lib\\assimp-vc140-mt.lib")