#include <director.h>
const std::string Director::windowTitle = "Tamagotchi";
const int Director::windowWidth = 400;
const int Director::windowHeight = 300;

void Director::mainLoop()
{
	SdlWrapper::instance.initialize(windowTitle, windowWidth, windowHeight);

	// Make a shared_ptr of this without default deleter to make sure SdlWrapper does not delete Director.
	std::shared_ptr<QuitHandler> thispointer(this, [](QuitHandler *) {});
	SdlWrapper::instance.addQuitHandler(thispointer);
	while (!quit) {
		SdlWrapper::instance.pollEvent();
	}
}

void Director::handleQuit(const SDL_QuitEvent & e)
{
	quit = true;
}
