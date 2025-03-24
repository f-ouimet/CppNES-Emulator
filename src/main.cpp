// main
#include "Window.h"
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_video.h>
#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
  WindowUtils::Window myWin;
  SDL_Window *window = myWin.createWindow("test");
  while (1) {
  }

  return EXIT_SUCCESS;
}
