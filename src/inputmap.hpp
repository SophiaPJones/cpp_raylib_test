#ifndef _INPUTMAP_HPP
#define _INPUTMAP_HPP

#include <functional>
#include <iostream>
#include <map>
#include <vector>

typedef enum { CONTEXT_GAME = 0, CONTEXT_MENU = 1, CONTEXT_PAUSE = 2 } Context;

class inputmap {
  std::map<int, std::vector<std::pair<Context, std::function<void(void)>>>>
      input_map;

public:
  void map_key_binding(int key, Context context,
                       std::function<void(void)> func);
  void call_key_binding(int key, Context context);
};

void inputmap::map_key_binding(int key, Context context,
                               std::function<void(void)> func) {
  auto mapit = this->input_map.find(key);
  if (mapit == this->input_map.end()) {
    this->input_map.insert(
        std::pair<int,
                  std::vector<std::pair<Context, std::function<void(void)>>>>(
            key,
            *(new std::vector<std::pair<Context, std::function<void(void)>>>)));
    this->input_map.at(key).push_back(
        std::pair<Context, std::function<void(void)>>(context, func));
  } else {
    auto context_function_pair_vector = mapit->second;
    context_function_pair_vector.push_back(
        std::pair<Context, std::function<void(void)>>(context, func));
  }
};

void inputmap::call_key_binding(int key, Context context) {
  std::cout << context << std::endl;
  auto context_function_pair_vector = this->input_map.find(key)->second;
  auto it = context_function_pair_vector.begin();
  while (it != (context_function_pair_vector.end())) {
    if (it->first == context) {
      std::cout << "Found a bound function" << std::endl;
      (it->second)();
    }
    it++;
  }
  return;
}
#endif
