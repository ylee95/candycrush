#include <director.h>

// SDL2 requires main function to be in the following form.
// int main(int argc, char *argv[])
// Because, SDL2 does some macro magic during its initialization for main.
int main(int argc, char *argv[]) {
	Director director;
	director.mainLoop();
	return 0;
}
