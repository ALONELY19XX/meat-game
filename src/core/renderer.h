#pragma once

#include <memory>
#include <SDL3/SDL.h>

namespace meat::core {
   class Renderer {
   public:
      Renderer() = default;
      ~Renderer() = default;

      auto destroy() -> void;
      auto set_renderer(SDL_Renderer* renderer) -> void;
      auto clear_background() const -> void;
      auto present() const -> void;

   private:
      struct SDL_RendererDeleter {
         auto operator()(SDL_Renderer* renderer) const -> void {
            if (renderer) SDL_DestroyRenderer(renderer);
         }
      };

      std::unique_ptr<SDL_Renderer, SDL_RendererDeleter> m_renderer{};
   };
}
