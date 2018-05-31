#ifndef CANDYCRUSH_SDLWRAPPER_H
#define CANDCANDYCRUSH_SDLWRAPPER_H
#include <SDL.h>

class SdlWrapper {
public:
  // Singleton instance.
  static SdlWrapper instance;

  ~SdlWrapper();

  // Disable copy constructor.
  SdlWrapper(const SdlWrapper &) = delete;
  // Allow move constructor.
  SdlWrapper(SdlWrapper &&) = default;

  bool initialize();

private:
  bool initialized;
  SdlWrapper();
};
#endif // CANDYCRUSH_SDLWRAPPER_H