#pragma once

#include "core/renderer.h"
#include "core/window.h"

namespace meat {
   class Game {
   public:
      Game() = default;
      ~Game();

      auto init() -> bool;
      auto run() -> void;
      auto shutdown() -> void;

   private:
      Window m_window{};
      Renderer m_renderer{};
      bool m_running{true};
   };
} // meat
