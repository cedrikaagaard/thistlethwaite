#include "../cubelib.hpp"

using namespace cl;

uint64_t cl::cube::g3hash() {
	uint64_t res = 0;
	uint64_t ONE = 1;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (arepr[i][j][k] == i) {
					int index = (i * 9 + j * 3 + k);
					res |= ONE << (index);
				}
			}
		}
	}

	return res;
}