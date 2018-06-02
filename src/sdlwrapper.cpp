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
