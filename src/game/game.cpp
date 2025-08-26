#include "game.h"

#include <print>

using namespace meat;

Game::~Game() {
   shutdown();
}

auto Game::init() -> bool {
   if (!SDL_Init(SDL_INIT_VIDEO)) {
      std::println(stderr, "Could not initialize SDL3! {}", SDL_GetError());
      return false;
   }

   SDL_Window* window;
   SDL_Renderer* renderer;

   const auto successful_init = SDL_CreateWindowAndRenderer(
      m_window.properties.title.c_str(),
      m_window.properties.width,
      m_window.properties.height,
      SDL_WINDOW_RESIZABLE,
      &window,
      &renderer
   );

   if (!successful_init) {
      std::println(stderr, "Could not create window and renderer! {}", SDL_GetError());
      return false;
   }

   m_window.set_window(window);
   m_renderer.set_renderer(renderer);

   return true;
}

auto Game::run() -> void {
   while (m_running) {
      SDL_Event event;
      while (SDL_PollEvent(&event)) {
         if (event.type == SDL_EVENT_QUIT) {
            m_running = false;
            break;
         }
      }

      m_renderer.clear_background();
      m_renderer.present();

      SDL_Delay(1000 / 60);
   }
}

auto Game::shutdown() -> void {
   m_renderer.destroy();
   m_window.destroy();
   SDL_Quit();
}
