#ifndef TAMAGOTCHI_UTIL_TIME_H
#define TAMAGOTCHI_UTIL_TIME_H
#include <chrono>
#include <ctime>
// Get time from system clock and extract the hour of day value from it.
int sysclockToHourOfDay(const std::chrono::time_point<std::chrono::system_clock> &sysclockTime);
std::chrono::seconds effectiveDuration(const std::chrono::time_point<std::chrono::system_clock> start, const std::chrono::time_point<std::chrono::system_clock> end, int sleepTime, int wakeTime);
#endif // TAMAGOTCHI_UTIL_TIME_H
