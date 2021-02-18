#ifndef __STATE_H_
#define __STATE_H_

#include "Camera2D.hpp"
#include "raylib-cpp.hpp"

struct GameState {
  raylib::Vector2 window_dimensions;
  raylib::Camera2D player_cam;

} state;

#endif // __STATE_H_
