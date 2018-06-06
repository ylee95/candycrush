#include <sdlwrapper.h>

SdlWrapper SdlWrapper::instance = SdlWrapper();

SdlWrapper::SdlWrapper() : initialized(false) {}

SdlWrapper::~SdlWrapper() {
	// Shutdown every SDL subsystems.
	SDL_Quit();
}

bool SdlWrapper::initialize(const std::string &title, int width, int height) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		// Initialize failed.
		return false;
	}
	else {
		// Initialize success.
		// Create a window.
		graphics.window = std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>(SDL_CreateWindow(title.data(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0), SDL_DestroyWindow);
		// Create a renderer.
		graphics.renderer = std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>(SDL_CreateRenderer(graphics.window.get(), -1, SDL_RENDERER_ACCELERATED), SDL_DestroyRenderer);

		if (graphics.window.get() == nullptr || graphics.renderer.get() == nullptr) {
			return false;
		}
		else {
			return true;
		}
	}
}

void SdlWrapper::clear(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	SDL_SetRenderDrawColor(graphics.renderer.get(), r, g, b, a);
	SDL_RenderClear(graphics.renderer.get());
}

void SdlWrapper::present()
{
	SDL_RenderPresent(graphics.renderer.get());
}

void SdlWrapper::drawRect(int x, int y, int w, int h, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	SDL_SetRenderDrawColor(graphics.renderer.get(), r, g, b, a);
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	SDL_RenderDrawRect(graphics.renderer.get(), &rect);
}

void SdlWrapper::fillRect(int x, int y, int w, int h, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	SDL_SetRenderDrawColor(graphics.renderer.get(), r, g, b, a);
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	SDL_RenderFillRect(graphics.renderer.get(), &rect);
}

void SdlWrapper::addKeyboardHandler(const std::weak_ptr<KeyboardHandler>& h)
{
	keyboardHandlers.emplace_back(h);
}

void SdlWrapper::addQuitHandler(const std::weak_ptr<QuitHandler>& h)
{
	quitHandlers.emplace_back(h);
}

void SdlWrapper::pollEvent()
{
	SDL_Event e;
	// For all handler collections, erase expired pointers and pass corresponding event to the unexpired ones.
	while (SDL_PollEvent(&e)) {
		switch (e.type) {
		case SDL_KEYDOWN: case SDL_KEYUP:
			for (auto it = keyboardHandlers.begin(); it != keyboardHandlers.end();) {
				if (it->expired()) {
					keyboardHandlers.erase(it);
				}
				else {
					it->lock()->handleKeyboard(e.key);
					it++;
				}
			}
			break;
		case SDL_QUIT:
			for (auto it = quitHandlers.begin(); it != quitHandlers.end();) {
				if (it->expired()) {
					quitHandlers.erase(it);
				}
				else {
					it->lock()->handleQuit(e.quit);
					it++;
				}
			}
			break;
		default:
			break;
		}
	}
}
