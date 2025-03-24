#include "Window.h"
#include <SDL3/SDL_video.h>
#include <cstdlib>
#include <iostream>
using namespace std;
using namespace WindowUtils;
SDL_Window *Window::createWindow(const char *title) {
  SDL_Window *window = SDL_CreateWindow(
      title, 256, 240, SDL_WINDOW_RESIZABLE | SDL_WINDOW_INPUT_FOCUS);
  if (window == nullptr) {
    cout << "Failed to create window";
    return nullptr;
  }
  return window;
}
