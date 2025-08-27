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
      m_window.properties.flags,
      &window,
      &renderer
   );

   if (!successful_init) {
      std::println(stderr, "Could not create window and renderer! {}", SDL_GetError());
      return false;
   }

   m_window.set_window(window);
   m_renderer.set_renderer(renderer);

   m_running = true;
   m_last_frame_time = SDL_GetTicks();

   return true;
}

auto Game::run() -> void {
   while (m_running) {
      m_input_system.handle_events();

      if (m_input_system.should_quit()) {
         m_running = false;
         break;
      };

      update();
      m_renderer.clear_background();
      m_renderer.present();

      wait_remaining_frame_time();
   }
}

auto Game::shutdown() -> void {
   m_renderer.destroy();
   m_window.destroy();
   SDL_Quit();
}

auto Game::elapsed_time_since_last_frame() const -> uint64_t {
   return SDL_GetTicks() - m_last_frame_time;
}

auto Game::update() -> void {
   m_last_frame_time = SDL_GetTicks();
}

auto Game::wait_remaining_frame_time() const -> void {
   const auto elapsed_time = elapsed_time_since_last_frame();
   if (elapsed_time < TARGET_FRAME_TIME) {
      SDL_Delay(TARGET_FRAME_TIME - elapsed_time);
   }
}
