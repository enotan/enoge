#pragma once

#include <SDL3/SDL.h>

namespace enoge::app {

    class Application {
        public:
            Application() = default;
            ~Application();

            Application(const Application&) = delete;
            Application& operator=(const Application&) = delete;

            bool initialize();
            int run();

        private:
            void shutdown();
            void handleEvents(bool& isRunning);
            void renderFrame();

            SDL_Window* window_ = nullptr;
            SDL_Renderer* renderer_ = nullptr;
            bool sdlInitialized_ = false;
    };
}