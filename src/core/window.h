#pragma once

#include <memory>
#include <string>
#include <SDL3/SDL.h>

namespace meat::core {
   struct WindowProperties {
      std::string title;
      int width;
      int height;
      SDL_WindowFlags flags;
   };

   class Window {
   public:
      WindowProperties properties{};

      Window();
      ~Window() = default;

      auto destroy() -> void;
      auto set_window(SDL_Window* window) -> void;

   private:
      struct SDL_WindowDeleter {
         auto operator()(SDL_Window* window) const -> void {
            if (window) SDL_DestroyWindow(window);
         }
      };

      std::unique_ptr<SDL_Window, SDL_WindowDeleter> m_window{};
   };
}
