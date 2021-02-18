#ifndef _CORE_HPP
#define _CORE_HPP
#include "contexts.hpp"
#include "entity.hpp"
#include "inputmap.hpp"
#include "raylib-cpp.hpp"
#include <memory>

struct GameState {
  Vector2 window_size;
  Camera2D player_cam;
  raylib::Vector2 camera_target;
  float camera_speed;
  Context current_context;
  inputmap input_map;
  std::vector<std::unique_ptr<Entity>> environment;
} game_state;

#endif
