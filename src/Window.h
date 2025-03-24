#ifndef WINDOW_H_
#define WINDOW_H_
#include <SDL3/SDL_video.h>
namespace WindowUtils {
class Window {
public:
  SDL_Window *createWindow(const char *title);
};
} // namespace WindowUtils
#endif
