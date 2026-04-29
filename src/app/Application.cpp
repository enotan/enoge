#include "app/Application.hpp"
#include <SDL3/SDL.h>
#include <iostream>

namespace enoge::app {
    namespace {
        constexpr int kWindowWidth = 1280;
        constexpr int kWindowHeight = 720;
        constexpr const char* kWindowTitle = "enoge";

    }

    Application::~Application() {
        shutdown();
    }

    bool Application::initialize() {
        if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
            std::cerr << "Failed to intiaialize SDL: " << SDL_GetError() << '\n';
            return false;
        }
        sdlInitialized_ = true;

        window_ = SDL_CreateWindow(kWindowTitle, kWindowWidth, kWindowHeight, 0);
        if (window_ == nullptr) {
            std::cerr << "Failed to create window: " << SDL_GetError() << '\n';
            return false;
        }

        renderer_ = SDL_CreateRenderer(window_, nullptr);
        if (renderer_ == nullptr) {
            std::cerr << "Failed to create renderer: " << SDL_GetError() << '\n';
            return false;
        }

        return true;
    }

    int Application::run() {
        bool isRunning = true;
        
        while (isRunning) {
            handleEvents(isRunning);
            renderFrame();
        }

        return 0;
    }

    void Application::shutdown() {
        if (renderer_ != nullptr) {
            SDL_DestroyRenderer(renderer_);
            renderer_ = nullptr;
        }

        if (window_ != nullptr) {
            SDL_DestroyWindow(window_);
            window_ = nullptr;
        }

        if (sdlInitialized_) {
            SDL_Quit();
            sdlInitialized_ = false;
        }
    }

    void Application::handleEvents(bool& isRunning) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                isRunning = false;
            }
        }
    }

    void Application::renderFrame() {
        SDL_SetRenderDrawColor(renderer_, 18, 20, 26, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer_);
        SDL_RenderPresent(renderer_);
    }
 }