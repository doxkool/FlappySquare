#include "Window/Window.h"

#include "Core/Input.h"

namespace Engine
{
	WindowCallback::WindowCallback(Window& window)
	{
		glfwSetKeyCallback(window.m_Window, Input::Key_Callback);
		glfwSetKeyCallback(window.m_Window, Input::Key_Callback);
		glfwSetScrollCallback(window.m_Window, Input::Mouse_Scroll_Callback);
		glfwSetMouseButtonCallback(window.m_Window, Input::Mouse_Button_Callback);

		glfwSetMonitorCallback(MonitorCallback);
		glfwSetWindowSizeCallback(window.m_Window, WindowResizeCallback);
		glfwSetFramebufferSizeCallback(window.m_Window, FramebufferResizeCallback);
		glfwSetWindowPosCallback(window.m_Window, WindowPositionCallback);
		glfwSetWindowMaximizeCallback(window.m_Window, WindowMaximizeCallback);
	}

	void WindowCallback::GLFWErrorCallback(int error, const char* message)
	{
		LOG_ERROR("GLFW Error ({}): {}", error, message);
	}

	void WindowCallback::MonitorCallback(GLFWmonitor* monitor, int event)
	{
		if (event == GLFW_CONNECTED)
		{
			LOG_TRACE("A New monitor connected...");
		}
		else if (event == GLFW_DISCONNECTED)
		{
			LOG_TRACE("A monitor has been disconnected...");
		}
	}

	void WindowCallback::WindowResizeCallback(GLFWwindow* window, int Window_Width, int Window_Height)
	{

	};

	void WindowCallback::FramebufferResizeCallback(GLFWwindow* window, int FrameBuffer_Width, int FrameBuffer_Height)
	{
		OpenGL::SetViewport(FrameBuffer_Width, FrameBuffer_Height);

		LOG_DEBUG("FrameBuffer resolution changed to : {}x{}", FrameBuffer_Width, FrameBuffer_Height);
	};

	void WindowCallback::WindowPositionCallback(GLFWwindow* window, int xPos, int yPos)
	{
		WindowCallback* state = static_cast<WindowCallback*>(glfwGetWindowUserPointer(window));
	};

	void WindowCallback::WindowMaximizeCallback(GLFWwindow* window, int maximized)
	{
		if(maximized)
		{
			LOG_DEBUG("Window : maximized.");
		}
		else
		{
			LOG_DEBUG("Window : not maximized.");
		}
	};
}