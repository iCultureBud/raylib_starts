#pragma once

#include <cstdint>
#include <raylib.h>
#include <vector>

#define MAX_BUILDINGS 100

namespace icuray {

    class Game
    {
    public:
        Game();
        ~Game();

        /**
         * Initializes the main game
         */
        void initialize();

        /**
         * Initializes the main game
         */
        void handleInput();

        /**
         * Sets up the initial scene
         */
        void drawInitialScene();

        /**
         * Starts the main game
         */
        void start();

	private:
		int32_t m_spacing { 0 };

		Rectangle m_player;
        Camera2D m_camera { 0 };
		std::vector<Rectangle> m_buildings;
		std::vector<Color> m_buildColors;

    }; // class Game

} // namespace icuray
