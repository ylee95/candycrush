#include <util/time.h>
#include <iostream>
int sysclockToHourOfDay(const std::chrono::time_point<std::chrono::system_clock> &sysclockTime) {
	std::time_t t = std::chrono::system_clock::to_time_t(sysclockTime);
	std::tm *t_tm = std::localtime(&t);
	return t_tm->tm_hour;
}

std::chrono::seconds effectiveDuration(const std::chrono::time_point<std::chrono::system_clock> start, const std::chrono::time_point<std::chrono::system_clock> end, int sleepTime, int wakeTime) {
	if (start > end || sleepTime < wakeTime) {
		// Invalid parameters.
		std::cerr << "Invalid time parameter(s)." << std::endl;
		return std::chrono::seconds(0);
	}
	else {
		// Initialize return value to 0 seconds.
		std::chrono::seconds ret(0);
		// Set marker at start.
		std::chrono::time_point<std::chrono::system_clock> marker(start);
		while (marker < end) {
			// Check if sleeping.
			std::time_t marker_time = std::chrono::system_clock::to_time_t(marker);
			std::tm *marker_tm = std::localtime(&marker_time);
			if (marker_tm->tm_hour < wakeTime || marker_tm->tm_hour >= sleepTime) {
				// Sleeping.
				// Move marker forward to nearest wakeTime in the future.
				std::tm next_tm(*marker_tm);
				next_tm.tm_hour = wakeTime;
				next_tm.tm_min = 0;
				next_tm.tm_sec = 0;
				std::time_t next_time = std::mktime(&next_tm);
				std::chrono::time_point<std::chrono::system_clock> next = std::chrono::system_clock::from_time_t(next_time);
				// We don't know if next_tm is before or after midnight.
				// If marker was before midnight, next_tm is pointing to wakeTime in the past.
				// In that case, add 24 hours to next, because we want wakeTime in the future.
				if (next < marker) {
					marker = next + std::chrono::hours(24);
				}
				else {
					marker = next;
				}
			}
			else {
				// Not sleeping.
				// Find nearest sleepTime in the future.
				std::tm next_tm(*marker_tm);
				next_tm.tm_hour = sleepTime;
				next_tm.tm_min = 0;
				next_tm.tm_sec = 0;
				std::time_t next_time = std::mktime(&next_tm);
				std::chrono::time_point<std::chrono::system_clock> next = std::chrono::system_clock::from_time_t(next_time);

				if (end < next) {
					ret += std::chrono::duration_cast<std::chrono::seconds>(end - marker);
					marker = end;
				}
				else {
					ret += std::chrono::duration_cast<std::chrono::seconds>(next - marker);
					marker = next;
				}
			}
		}

		return ret;
	}
}
