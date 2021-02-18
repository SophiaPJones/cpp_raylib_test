#ifndef _ENTITY_HPP
#define _ENTITY_HPP

#include "raylib-cpp.hpp"
#include <iostream>

#define TILESIZE 64

class Entity {
protected:
  raylib::Vector2 position;

public:
  virtual void draw();
  void set_position(float, float);
  void set_position(Vector2);
  void offset_position(float, float);
  void offset_position(Vector2);
  Vector2 get_position() { return position; };
};

class Tile : public Entity {
  raylib::Texture sprite;
  raylib::Color color;

public:
  Tile(Vector2, Color);
  void draw();
};

void Entity::draw() {
  std::cout << "Drawing an Entity!" << std::endl;
  return;
}

void Entity::set_position(float x, float y) {
  this->position.x = x;
  this->position.y = y;
}
void Entity::set_position(Vector2 newPos) { this->position = newPos; }
void Entity::offset_position(float x, float y) {
  this->position.x += x;
  this->position.y += y;
}
void Entity::offset_position(Vector2 offset) { this->position += offset; }
Tile::Tile(Vector2 position, Color color) {
  this->position = position;
  this->color = color;
}
void Tile::draw() {
  std::cout << "Drawing a tile!" << std::endl;
  DrawRectangle(this->position.x, this->position.y, TILESIZE, TILESIZE,
                this->color);
  return;
}

class Grid : public Entity {
private:
  raylib::Color color{BLACK};
  raylib::Vector2 spacing{TILESIZE, TILESIZE};

public:
  void draw();
};

#endif
