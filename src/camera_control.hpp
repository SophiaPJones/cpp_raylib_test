#ifndef _CAMERA_CONTROL_HPP
#define _CAMERA_CONTROL_HPP

#include "core.hpp"
#include "inputmap.hpp"
struct CameraControls {
public:
  std::function<void(void)> move_camera_up = [&]() {
    game_state.player_cam.target.y -= game_state.camera_speed;
    std::cout << "move_camera_up" << std::endl;
  };
  std::function<void(void)> move_camera_down = [&]() {
    game_state.player_cam.target.y += game_state.camera_speed;
    std::cout << "move_camera_down" << std::endl;
  };
  std::function<void(void)> move_camera_left = [&]() {
    game_state.player_cam.target.x -= game_state.camera_speed;
    std::cout << "move_camera_left" << std::endl;
  };
  std::function<void(void)> move_camera_right = [&]() {
    game_state.player_cam.target.x += game_state.camera_speed;
    std::cout << "move_camera_right" << std::endl;
  };
} camera_controls;

#endif
