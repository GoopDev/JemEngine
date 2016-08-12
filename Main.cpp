#include <iostream>
#include <Windows.h>
#include <glew.h>
#include <glfw3.h>
#include <string>
#include "Window.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreviousInstance, LPSTR lpCmdLine, int nCmdShow) { // LEFT OFF AT INPUTS, [S]PARKY 4 NEXT
	using namespace jem;
	std::vector<int> glfwWindowHintsParam = std::vector<int>();
	std::vector<int> glfwWindowHintsValue = std::vector<int>();
	glfwWindowHintsParam.push_back(GLFW_DECORATED);
	glfwWindowHintsValue.push_back(GLFW_FALSE);
	glfwWindowHintsParam.push_back(GLFW_MAXIMIZED);
	glfwWindowHintsValue.push_back(GLFW_TRUE);
	Window window("Game", 800, 600, true, glfwWindowHintsParam, glfwWindowHintsValue);

	Vector2 testPos;

	// Update loop
	while (glfwWindowShouldClose(window.m_Window) != GLFW_TRUE) {
		window.update();

		if (window.isKeyPressed(GLFW_KEY_C)) {
			window.dispose();
		}
	}

	return 0;
}