#include "Game.h"

namespace Core {

    Game::Game(const GameConfig& cfg)
        : m_config(cfg)
        , m_sceneManager(std::make_unique<Scene::SceneManager>())
        , m_isRunning(false)
    {
		s_config = cfg;
        initWindow();
    }

    Game::~Game() noexcept
    {
        shutdown();
    }

    void Game::stop() noexcept
    {
        m_isRunning = false;
    }

    void Game::Run()
    {
        m_isRunning = true;

        while (m_isRunning) {

            if (WindowShouldClose()) {
                stop();
                break;
            }

            BeginDrawing();
            ClearBackground(RAYWHITE);

            if (m_sceneManager) {
                m_sceneManager->update(GetFrameTime());
                m_sceneManager->render();
            }

            EndDrawing();
        }
    }

    void Game::initWindow()
    {
        SetConfigFlags(FLAG_WINDOW_RESIZABLE);
        InitWindow(m_config.screenWidth, m_config.screenHeight, m_config.windowTitle.c_str());
        SetTargetFPS(m_config.fps);
    }

    void Game::shutdown() noexcept
    {
        if (m_sceneManager) {
            m_sceneManager.reset();
        }
        if (!m_isRunning) {
            CloseWindow();
        }
    }

} 
