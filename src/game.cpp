#include <game.h>
#include <iostream>
#include <sstream>
#include <string>

Game::Game(Bird bird, std::chrono::time_point<std::chrono::system_clock> birthTime) : birthTime(birthTime), hunger(0), needPoop(0), trainNum(0), isTrained(false), isDead(false), bird(bird) {
	// Initialize poops array.
	for (bool &p : poops) {
		p = false;
	}
}

void Game::giveFood(Food foodType) {
	if (foodType == Food::RICE) {
		hunger -= 3;
	}
	else if (foodType == Food::ICECREAM) {
		hunger -= 1;
	}
	else {
		// error case
	}
	if (hunger < 0) hunger = 0;
}

void Game::cleanPoop() {
	for (bool &p : poops) {
		p = false;
	}
}

void Game::pottyTrain() {
	if (needPoop > 6) {
		needPoop = 0;
		trainNum++;
		if (trainNum > numPottyTraining) {
			isTrained = true;
		}
		std::cout << "Pooped!" << std::endl;
	}
	else {
		std::cout << "Cannot poop yet" << std::endl;
	}
}

bool Game::isGameOver() const {
	return isDead;
}

std::string Game::toString() {
	std::stringstream ss;
	ss << "hunger" << " " << hunger << std::endl;
	ss << "needPoop" << " " << needPoop << std::endl;
	ss << "poops";
	for (bool p : poops) {
		ss << p << " ";
	}
	ss << std::endl;
	ss << "trainNum" << " " << trainNum << std::endl;
	ss << "isTrained" << " " << isTrained << std::endl;
	ss << "isDead" << " " << std::endl;

	return ss.str();
}

void Game::fromString(std::string str) {
	std::stringstream ss(str);
	std::string line;
	while (std::getline(ss, line)) {
		if (line.find("hunger")!=std::string::npos) {
			hunger = std::stoi(line.substr(7));
		}
		else if (line.find("needPoop") != std::string::npos) {
			needPoop = std::stoi(line.substr(9));
		}
		else if (line.find("poops") != std::string::npos) {
			int pos = 6;
			for (bool& p : poops) {
				if (line.substr(pos) == "true") {
					p = true;
					pos += 5;
				}
				else {
					p = false;
					pos += 6;
				}
			}
		}
		else if (line.find("trainNum") != std::string::npos) {
			trainNum = std::stoi(line.substr(9));
		}
		else if (line.find("isTrained") != std::string::npos) {
			// cannot do ref? &isTrained?
			isTrained = line.substr(10) == "true" ? true : false;
		}
		else {
			//isDead
			isDead = line.substr(7) == "true" ? true : false;
		}
	}
}