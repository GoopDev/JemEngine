#pragma once

#include <glew.h>
#include <glfw3.h>
#include <vector>
#include <iostream>
#include <string>
#include "Vector2.h"

namespace jem {

	class Window {
	private:
		int m_Width, m_Height;
		const char * m_Title;
		std::vector<int> m_WindowHints;
		std::vector<int> m_WindowHintsSet;
		static bool m_KeyOptions[1024];
		static bool m_MouseOptions[64];
		// Methods
		void init();
		friend static void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods);
		friend static void mouse_button_callback(GLFWwindow * window, int button, int action, int mods);
		friend static void cursor_callback(GLFWwindow * window, double x, double y);
	public:
		static Vector2 m_MousePos;
		friend struct GLFWwindow;
		GLFWwindow* m_Window;
		Window(const char * title, int width, int height, bool doUpdate, std::vector<int> windowHintsElements, std::vector<int> windowHintsValues);
		~Window();
		GLFWvidmode* m_VidMode;
		static bool isKeyPressed(unsigned int keycode);
		static bool isMouseButtonPressed(unsigned int buttoncode);
		static void getMouseVector(Vector2& ref);
		void update();
		void dispose();
	};

}