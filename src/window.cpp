#include "window.hpp"
#include "game.hpp"

using namespace icuray;

Window::Window() :

	m_width(m_defaultWidth),
	m_height(m_defaultHeight)
{
}

Window::Window(int32_t width, int32_t height) :

	m_width(width),
	m_height(height)
{
}

Window::~Window()
{}

void Window::initialize()
{
	InitWindow(m_width, m_height, "raylib basics");
}

void Window::draw()
{
	Game game;

	while (!WindowShouldClose())
	{
		BeginDrawing();
		
			ClearBackground(RAYWHITE);
			game.start();

		EndDrawing();
	}

	CloseWindow();
}

void Window::reset()
{
	m_width = m_defaultWidth;
	m_height = m_defaultHeight;
}

void Window::resize(int32_t width, int32_t height)
{
	m_width = width;
	m_height = height;
}
