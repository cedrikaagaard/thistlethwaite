#include "../cubelib.hpp"

using namespace cl;

boost::multiprecision::uint128_t cl::cube::g2hash() {
	boost::multiprecision::uint128_t res = 0;
	boost::multiprecision::uint128_t ONE = 1;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				aaside current_side = aside_to_aaside((aside) i);
				aaside current_value = aarepr[i][j][k];

				uint8_t current_res;

				if (current_side == up_down) {
					switch (current_value) {
						case up_down: current_res = 2; break;
						case right_left: current_res = 1; break;
						case front_back: current_res = 0; break;
					}
				}

				else if (current_side == right_left) {
					switch (current_value) {
						case right_left: current_res = 2; break;
						case up_down: current_res = 1; break;
						case front_back: current_res = 0; break;
					}
				}

				else if (current_side == front_back) {
					switch (current_value) {
						case front_back: current_res = 2; break;
						case up_down: current_res = 1; break;
						case right_left: current_res = 0; break;
					}
				}

				int index = (i * 9 + j * 3 + k) * 2;

				if (current_res == 2) {
					res |= ONE << (index + 1);
				}

				else if (current_res == 1) {
					res |= ONE << (index);
				}
			}
		}
	}

	return res;
}