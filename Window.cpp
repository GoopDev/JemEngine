#include "Window.h"

namespace jem {

	bool Window::m_KeyOptions[1024];
	bool Window::m_MouseOptions[64];

	Vector2 Window::m_MousePos = Vector2();

	void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods);

	void resize_window(GLFWwindow * window, int width, int height);

	Window::Window(const char * title, int width, int height, bool doUpdate = true, std::vector<int> windowHintsElements = std::vector<int>(), std::vector<int> windowHintsValues = std::vector<int>()) {
		m_Title = title;
		m_Width = width;
		m_Height = height;
		m_WindowHints = windowHintsElements;
		m_WindowHintsSet = windowHintsValues;
		for (int i = 0; i < 1024; i++)
		{
			m_KeyOptions[i] = false;
		}

		init();
	}
	

	void Window::init()
	{
		if (!glfwInit()) {
			std::cout << "ERROR: GLFW could not be initialized" << std::endl;
			return;
		}

		// GLFW Window hints
		glfwDefaultWindowHints();
		for (int i = 0; i < m_WindowHints.size(); i++) {
			glfwWindowHint(m_WindowHints[i], m_WindowHintsSet[i]);
		}

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
		if (!m_Window) {
			glfwTerminate();
			std::cout << "ERROR: GLFW Window could not be created" << std::endl;
			return;
		}

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, this);
		glfwSetKeyCallback(m_Window, key_callback);
		glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
		glfwSetCursorPosCallback(m_Window, cursor_callback);
		glfwSwapInterval(1);

		glClearColor(0,0,0,0); // Replace with your colours if wanted
		glfwSetFramebufferSizeCallback(m_Window, resize_window);

		glfwSetWindowUserPointer(m_Window, this);

		m_VidMode = (GLFWvidmode*) glfwGetVideoMode(glfwGetPrimaryMonitor());

		if (glewInit() != GLEW_OK) {
			std::cout << "ERROR: GLEW could not be initialized" << std::endl;
		}
	}

	void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
	{
		Window* wind = (Window*) glfwGetWindowUserPointer(window);
		if (action == GLFW_PRESS) {
			wind->m_KeyOptions[key] = true;
		}
		else if (action == GLFW_RELEASE) {
			wind->m_KeyOptions[key] = false;
		}
	}

	void mouse_button_callback(GLFWwindow * window, int button, int action, int mods)
	{
		Window* wind = (Window*)glfwGetWindowUserPointer(window);
		if (action == GLFW_PRESS) {
			wind->m_MouseOptions[button] = true;
		}
		else if (action == GLFW_RELEASE) {
			wind->m_MouseOptions[button] = false;
		}
	}

	void cursor_callback(GLFWwindow * window, double x, double y)
	{
		Window* wind = (Window*)glfwGetWindowUserPointer(window);
		wind->m_MousePos.x = x;
		wind->m_MousePos.y = y;
	}

	void Window::update() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		
		// GLFW Event handling and updating
		glfwWaitEvents();
		glfwSwapBuffers(m_Window);

	}

	void resize_window(GLFWwindow *window, int width, int height) {
		glViewport(0, 0, width, height);
	}

	void Window::dispose() {
		glfwSetWindowShouldClose(m_Window, GLFW_TRUE);
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

	Window::~Window() {
		dispose();
	}

	bool Window::isMouseButtonPressed(unsigned int buttoncode)
	{
		return m_MouseOptions[buttoncode];
	}

	void Window::getMouseVector(Vector2 & ref)
	{
		ref.x = m_MousePos.x;
		ref.y = m_MousePos.y;
	}

	bool Window::isKeyPressed(unsigned int keycode) // To test for tapping, save a variable holding the current and previous values of a button.
		// Then simply ask if the previous key was not down and the current one is.
	{
		return m_KeyOptions[keycode];
	}

}