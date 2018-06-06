#ifndef TAMAGOTCHI_DIRECTOR_H
#define TAMAGOTCHI_DIRECTOR_H
#include <sdlwrapper.h>
#include <string>
class Director : public QuitHandler {
public:
	void mainLoop();
	void handleQuit(const SDL_QuitEvent &e) override;
private:
	static const std::string windowTitle;
	static const int windowWidth;
	static const int windowHeight;
	bool quit = false;
};
#endif // TAMAGOTCHI_DIRECTOR_H
