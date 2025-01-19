#include "game.hpp"

using namespace icuray;

Game::Game()
{
	initialize();
}

Game::~Game()
{}

void Game::start()
{
    drawInitialScene();
    handleInput();
}

void Game::initialize()
{
	m_player = Rectangle(400, 280, 40, 40);

    // Setup random buildings
	for (int32_t idx = 0; idx < MAX_BUILDINGS; ++idx)
	{
        Rectangle currBuilding;

		currBuilding.width = GetRandomValue(50, 200);
        currBuilding.height = GetRandomValue(100, 800);
        currBuilding.y = 480 - 130.0 - currBuilding.height;
        currBuilding.x = -6000.0 + m_spacing;

        m_spacing += currBuilding.width;

        Color currColor = {
			static_cast<unsigned char>(GetRandomValue(200, 240)),
			static_cast<unsigned char>(GetRandomValue(200, 240)),
			static_cast<unsigned char>(GetRandomValue(200, 250)),
			255
		};

        m_buildings.push_back(currBuilding);
        m_buildColors.push_back(currColor);
	}

    m_camera.target = Vector2(m_player.x + 20.0, m_player.y + 20.0);
    m_camera.offset = Vector2(640 / 2.0, 480 / 2.0);
    m_camera.rotation = 0.0;
    m_camera.zoom = 1.0;
}

void Game::handleInput()
{
    if (IsKeyDown(KEY_RIGHT)) m_player.x += 2;

    else if (IsKeyDown(KEY_LEFT)) m_player.x -= 2;

    // Camera target follows m_player
    m_camera.target = Vector2(m_player.x + 20, m_player.y + 20);

    // Camera rotation controls
    if (IsKeyDown(KEY_A)) m_camera.rotation--;
    else if (IsKeyDown(KEY_S)) m_camera.rotation++;

    // Limit m_camera rotation to 80 degrees (-40 to 40)
    if (m_camera.rotation > 40) m_camera.rotation = 40;
    else if (m_camera.rotation < -40) m_camera.rotation = -40;

    // Camera zoom controls
    m_camera.zoom += GetMouseWheelMove() * 0.05;

    if (m_camera.zoom > 3.0) m_camera.zoom = 3.0;
    else if (m_camera.zoom < 0.1) m_camera.zoom = 0.1;

    // Camera reset (zoom and rotation)
    if (IsKeyPressed(KEY_R))
    {
        m_camera.zoom = 1.0;
        m_camera.rotation = 0.0;
    }
}

void Game::drawInitialScene()
{
    BeginMode2D(m_camera);

    int screenHeight = 480;
    int screenWidth = 640;

    DrawRectangle(-6000, 320, 13000, 8000, DARKGRAY);

    for (int i = 0; i < MAX_BUILDINGS; i++) {
        DrawRectangleRec(m_buildings[i], m_buildColors[i]);
    }

    DrawRectangleRec(m_player, RED);

    DrawLine(m_camera.target.x,
             screenHeight * -10,
             m_camera.target.x,
             screenHeight * 10,
             GREEN);

    DrawLine(screenWidth * -10,
             m_camera.target.y,
             screenWidth * 10,
             m_camera.target.y,
             GREEN);

    EndMode2D();

    DrawText("SCREEN AREA", 640, 10, 20, RED);

    DrawRectangle(0, 0, screenWidth, 5, RED);
    DrawRectangle(0, 5, 5, screenHeight - 10, RED);
    DrawRectangle(screenWidth - 5, 5, 5, screenHeight - 10, RED);
    DrawRectangle(0, screenHeight - 5, screenWidth, 5, RED);

    DrawRectangle( 10, 10, 250, 113, Fade(SKYBLUE, 0.5f));
    DrawRectangleLines( 10, 10, 250, 113, BLUE);

    DrawText("Free 2d camera controls:", 20, 20, 10, BLACK);
    DrawText("- Right/Left to move Offset", 40, 40, 10, DARKGRAY);
    DrawText("- Mouse Wheel to Zoom in-out", 40, 60, 10, DARKGRAY);
    DrawText("- A / S to Rotate", 40, 80, 10, DARKGRAY);
    DrawText("- R to reset Zoom and Rotation", 40, 100, 10, DARKGRAY);
}
