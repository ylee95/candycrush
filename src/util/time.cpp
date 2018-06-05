#include <util/time.h>
int sysclockToHourOfDay(const std::chrono::time_point<std::chrono::system_clock> &sysclockTime) {
	std::time_t t = std::chrono::system_clock::to_time_t(sysclockTime);
	std::tm *t_tm = std::localtime(&t);
	return t_tm->tm_hour;
}
