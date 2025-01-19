#pragma once

#include <cstdint>

#include <raylib.h>

namespace icuray {

	class Window
	{
		public:
			Window();

			Window(int32_t width, int32_t height);

			~Window();

			/**
			 * Creates a raylib window and initializes it
			 */
			void initialize();

			/**
			 * Starts the process and waits for quit
			 */
			void draw();

			/**
			 * Resets the window to it's defaults
			 */
			void reset();
			
			/**
			 * Resizes the window to given values
			 *
			 * @param width the desired window width
			 * @param height the desired window height
			 */
			void resize(int32_t width, int32_t height);

		private:
			const int32_t m_defaultWidth { 640 };
			const int32_t m_defaultHeight { 480 };

			int32_t m_width;
			int32_t m_height;

	}; // class Window

} // namespace icuray
