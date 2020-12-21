#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
int main()
{
	//初始化GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//MacOS环境中应该添加的代码
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//检测当前使用的GLWF版本号
	int Major, Minor, Rev;
	glfwGetVersion(&Major, &Minor, &Rev);
	printf("GLFW %d.%d.%d initialized\n", Major, Minor, Rev);

	//创建一个窗口对象，存放了所有和窗口相关的数据，并且会被GLFW的其他函数频繁用到
	GLFWwindow* window = glfwCreateWindow(800, 600, "window", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	//GLAD是用来管理OpenGL的函数指针，初始化GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	//渲染窗口的尺寸大小，视口Viewport
	glViewport(0, 0, 800, 600);

	//调整窗口大小的时候改变视口的大小
	void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//渲染循环
	while (!glfwWindowShouldClose(window))
	{
		//输入
		//背景色变成蓝色
		glClearColor(0.0f, 0.34f, 0.57f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//渲染指令


		//检查并调用事件，交换缓冲
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	//渲染循环结束后正确释放/删除之前的分配的所有资源
	glfwTerminate();
	return 0;
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
