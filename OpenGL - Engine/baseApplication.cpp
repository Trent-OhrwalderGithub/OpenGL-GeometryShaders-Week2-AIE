#include "baseApplication.h"

#include <gl_core_4_4.h>

#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include <iostream>

baseApplication::baseApplication(std::string windowTitle, int width, int height)
	:	m_windowName(windowTitle)
	,	m_windowWidth(width)
	,	m_windowHeight(height)
{

}

baseApplication::~baseApplication()
{
}

bool baseApplication::run()
{
	bool successful = createWindow();

	if (!successful) return false;

	successful = setupOpenGL();

	if (!successful)
	{
		destroyWindow();
		return false;
	}

	setup();

	while (glfwWindowShouldClose(m_window) == false)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		update();
		render();

		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}

	shutdown();
	destroyWindow();
	return true;
}

void baseApplication::printOpenGLVersion()
{
	int major = ogl_GetMajorVersion();
	int minor = ogl_GetMinorVersion();

	std::cout << "GL Version is " << major << "." << minor << '\n';
}

bool baseApplication::createWindow()
{
	if (glfwInit() == false) return false;

	m_window = 
		glfwCreateWindow(m_windowWidth, m_windowHeight, m_windowName.c_str(), nullptr, nullptr);

	if (m_window == nullptr) return false;

	glfwMakeContextCurrent(m_window);

	return true;
}

void baseApplication::destroyWindow()
{
	if (m_window != nullptr) glfwDestroyWindow(m_window);
	
	glfwTerminate();
}

bool baseApplication::setupOpenGL()
{
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED) return false;

	return true;
}
