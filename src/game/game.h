#pragma once

#include "core/renderer.h"
#include "core/window.h"
#include "systems/input_system.h"

namespace meat {
   class Game {
   public:
      Game() = default;
      ~Game();

      auto init() -> bool;
      auto run() -> void;
      auto shutdown() -> void;

   private:
      core::Window m_window{};
      core::Renderer m_renderer{};
      systems::InputSystem m_input_system{};

      bool m_running{};

      static constexpr auto TARGET_FRAME_TIME{1000 / 60}; // 60 FPS
      uint64_t m_last_frame_time{};

      [[nodiscard]] auto elapsed_time_since_last_frame() const -> uint64_t;
      auto update() -> void;
      auto wait_remaining_frame_time() const -> void;
   };
}
