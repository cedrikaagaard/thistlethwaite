#include "../cubelib.hpp"

using namespace cl;

std::vector<cl::rotation> cl::random_rotations(const int &n) {
	std::vector<cl::rotation> res;

	for (int i = 0; i < n; i++) {
		res.emplace_back((cl::rotation) (rand() % 12));
	}

	return res;
}