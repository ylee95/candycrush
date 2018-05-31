#include <sdlwrapper.h>

SdlWrapper SdlWrapper::instance = SdlWrapper();

SdlWrapper::SdlWrapper() : initialized(false) {}

SdlWrapper::~SdlWrapper() {
	// Shutdown every SDL subsystems.
	SDL_Quit();
}

bool SdlWrapper::initialize() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		// Initialize failed.
		return false;
	}
	else {
		// Initialize success.
	}
}