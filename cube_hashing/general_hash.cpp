#include "../cubelib.hpp"

using namespace cl;

boost::multiprecision::uint256_t cl::cube::chash() {
	boost::multiprecision::uint256_t res = 0;
	boost::multiprecision::uint256_t ONE = 1;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				int index = (i * 9 + j * 3 + k) * 3;
				cside current = crepr[i][j][k];

				if (current & (1 << 0)) {
					res |= ONE << index;
				}

				if (current & (1 << 0)) {
					res |= ONE << (index + 1);
				}

				if (current & (1 << 0)) {
					res |= ONE << (index + 2);
				}
			}
		}
	}

	return res;
}