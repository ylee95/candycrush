#ifndef TAMAGOTCHI_SDLWRAPPER_H
#define TAMAGOTCHI_SDLWRAPPER_H
extern "C" {
#include <SDL2/SDL.h>
}
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

struct KeyboardHandler {
	virtual void handleKeyboard(const SDL_KeyboardEvent &e) = 0;
};

struct QuitHandler {
	virtual void handleQuit(const SDL_QuitEvent &e) = 0;
};

class SdlWrapper {
public:
	// Singleton instance.
	static SdlWrapper instance;

	~SdlWrapper();

	// Disable copy constructor.
	SdlWrapper(const SdlWrapper &) = delete;
	// Allow move constructor.
	SdlWrapper(SdlWrapper &&) = default;

	// SDL wrapper instance should be initialized before using.
	// There is no need for cleanup code, because it is handled automatically on destruction.
	// Initialization is not included inside the constructor to allow control over window creation.
	bool initialize(const std::string &title, int width, int height);

	// Clear rendering target.
	void clear(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
	// Update the screen.
	void present();
	// Draw a rectangle.
	void drawRect(int x, int y, int w, int h, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
	// Fill a rectangle.
	void fillRect(int x, int y, int w, int h, uint8_t r, uint8_t g, uint8_t b, uint8_t a);

	// Add a KeyboardHandler.
	void addKeyboardHandler(const std::weak_ptr<KeyboardHandler> &h);
	// Add a QuitHandler.
	void addQuitHandler(const std::weak_ptr<QuitHandler> &h);

	// Poll events and pass them to appropriate handlers.
	void pollEvent();

private:
	bool initialized;

	// Private constructor.
	SdlWrapper();

	// Object holding SDL window and renderer.
	// SDL_Window and SDL_Renderer needs to reside inside a member object of SdlWrapper class, because they need to be initialized after SDL_Init and
	// destroyed before SDL_Quit.
	struct {
		// Initialize window and renderer with nullptr.
		std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window = std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>(nullptr, SDL_DestroyWindow);
		std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer = std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>(nullptr, SDL_DestroyRenderer);
	} graphics;

	// Vector of KeyboardHandler instances.
	std::vector<std::weak_ptr<KeyboardHandler>> keyboardHandlers;
	// Vector of QuitHandler instances.
	std::vector<std::weak_ptr<QuitHandler>> quitHandlers;
};
#endif // TAMAGOTCHI_SDLWRAPPER_H