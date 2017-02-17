#pragma once

#include <string>

class GLFWwindow;

class baseApplication
{
public:


	baseApplication() = delete;

	baseApplication(std::string windowTitle, int width, int height);

	virtual			~baseApplication();

	/////
	bool			run();

	void			printOpenGLVersion();

protected:

	virtual bool	setup() = 0;
	virtual void	shutdown() = 0;
	virtual bool	update() = 0;
	virtual void	render() = 0;

	int getWindowWidth() const { return m_windowWidth; }
	int getWindowHeight() const { return m_windowHeight; }

private:

	bool			createWindow();
	void			destroyWindow();

	bool			setupOpenGL();

	std::string		m_windowName;
	int				m_windowWidth;
	int				m_windowHeight;

	GLFWwindow*		m_window;

};