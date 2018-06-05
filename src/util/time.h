#ifndef TAMAGOTCHI_UTIL_TIME_H
#define TAMAGOTCHI_UTIL_TIME_H
#include <chrono>
// Get time from system clock and extract the hour of day value from it.
int sysclockToHourOfDay(const std::chrono::time_point<std::chrono::system_clock> sysclockTime);
#endif // TAMAGOTCHI_UTIL_TIME_H
