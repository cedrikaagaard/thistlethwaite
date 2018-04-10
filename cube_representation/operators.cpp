#include "../cubelib.hpp"

using namespace cl;

bool cl::cube::operator==(cl::cube &other) {
	return this->chash() == other.chash();
}