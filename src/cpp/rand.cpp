#include <vector>
#include <sstream>
#include "rand.hpp"
#include "enums.hpp"

rotation get_random_rotation() {
	return (rotation) (rand() % 12);
}

std::string thistlethwaite::get_random_rotations(const int &n) {
	std::stringstream ss;

	for (int i = 0; i < n; i++) {
		ss << rottoa(get_random_rotation());
	}

	return ss.str();
}