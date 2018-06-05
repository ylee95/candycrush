#include <iostream>
#include <sdlwrapper.h>

// SDL2 requires main function to be in the following form.
// int main(int argc, char *argv[])
// Because, SDL2 does some macro magic during its initialization for main.
int main(int argc, char *argv[]) {
	std::clog << "Hello, World!" << std::endl;
	return 0;
}
