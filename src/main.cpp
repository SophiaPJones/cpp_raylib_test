#define DEBUG true

#include "camera_control.hpp"
#include "core.hpp"

void initialize_game_state(GameState *game_state) {
  game_state->window_size = raylib::Vector2{800, 450};
  game_state->player_cam.offset = raylib::Vector2{
      (game_state->window_size.x) / 2, (game_state->window_size.y) / 2};
  game_state->player_cam.target = raylib::Vector2{0, 0};
  game_state->player_cam.zoom = 1.0f;
  game_state->camera_speed = 5.0f;
  game_state->current_context = CONTEXT_GAME;
  game_state->input_map.map_key_binding(KEY_W, CONTEXT_GAME,
                                        camera_controls.move_camera_up);
  game_state->input_map.map_key_binding(KEY_S, CONTEXT_GAME,
                                        camera_controls.move_camera_down);
  game_state->input_map.map_key_binding(KEY_A, CONTEXT_GAME,
                                        camera_controls.move_camera_left);
  game_state->input_map.map_key_binding(KEY_D, CONTEXT_GAME,
                                        camera_controls.move_camera_right);
  game_state->environment.push_back(
      std::unique_ptr<Entity>(new Tile(raylib::Vector2(0, 0), RED)));
}

int main() {

  // Initialization
  int screen_width = 800;
  int screen_height = 450;

  raylib::Color text_color(LIGHTGRAY);
  raylib::Window w(screen_width, screen_height,
                   "Raylib C++ Starter Kit Example");
  SetTargetFPS(60);

  initialize_game_state(&game_state);
  // Main game loop
  while (!w.ShouldClose()) // Detect window close button or ESC key
  {
    // Update
    if (IsKeyDown(KEY_A))
      game_state.input_map.call_key_binding(KEY_A, game_state.current_context);
    if (IsKeyDown(KEY_W))
      game_state.input_map.call_key_binding(KEY_W, game_state.current_context);
    if (IsKeyDown(KEY_S))
      game_state.input_map.call_key_binding(KEY_S, game_state.current_context);
    if (IsKeyDown(KEY_D))
      game_state.input_map.call_key_binding(KEY_D, game_state.current_context);
    // TODO: Update your variables here
    // Draw

    BeginDrawing();
    auto it = game_state.environment.begin();

    ClearBackground(RAYWHITE);
    BeginMode2D(game_state.player_cam);
    text_color.DrawText("Congrats! You created your first window!", 100, 100,
                        20);
    while (it != game_state.environment.end()) {
      (*it)->draw();
      it++;
    }
    EndMode2D();
    EndDrawing();
  }

  return 0;
}
