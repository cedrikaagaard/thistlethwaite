#include "../cubelib.hpp"

using namespace cl;

// Calculates which corner tetrad a given piece is in, z = LR
int8_t tg(aside x, aside y, aside z) {
	// x should be up_down
	if (aside_to_aaside(x) == front_back) {
		aside tmp = x;
		x = y;
		y = tmp;
	}

	if (x == up) {
		if (y == front) {
			return (int8_t) (z == right ? 0 : 5);
		}

		else if (y == back) {
			return (int8_t) (z == right ? 4 : 1);
		}
	}

	if (x == down) {
		if (y == front) {
			return (int8_t) (z == right ? 6 : 2);
		}

		else if (y == back) {
			return (int8_t) (z == right ? 3 : 7);
		}
	}
}


boost::multiprecision::uint128_t cl::cube::g2hash() {
	boost::multiprecision::uint128_t ONE = 1;
	boost::multiprecision::uint128_t res = 0;

	int corner_groups[8];
	bool group_mask[8][8];

	corner_groups[0] = tg(geta("U9"), geta("F3"), geta("R1"));
	corner_groups[1] = tg(geta("U1"), geta("B3"), geta("L1"));
	corner_groups[2] = tg(geta("D1"), geta("F7"), geta("L9"));
	corner_groups[3] = tg(geta("D9"), geta("B7"), geta("R9"));

	corner_groups[4] = tg(geta("U7"), geta("F1"), geta("L3"));
	corner_groups[5] = tg(geta("U3"), geta("B1"), geta("R3"));
	corner_groups[6] = tg(geta("D3"), geta("F9"), geta("R7"));
	corner_groups[7] = tg(geta("D7"), geta("B9"), geta("L7"));

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			group_mask[j][i] = (j == corner_groups[i]);
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (group_mask[j][i]) {
				res |= 1 << (i + j * 8);
			}
		}
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (aarepr[i][j][k] == aside_to_aaside((aside) i)) {
					int index = (i * 9 + j * 3 + k) + 56;
					res |= ONE << (index);
				}
			}
		}
	}

	return res;
}

/*boost::multiprecision::uint128_t cl::cube::g2hash() {
	boost::multiprecision::uint128_t ONE = 1;
	boost::multiprecision::uint128_t res = 0;

	bool good_edges[8];
	bool good_corners[8];

	int corner_groups[8];

	corner_groups[0] = tg(geta("U9"), geta("F3"), geta("R1"));
	corner_groups[1] = tg(geta("U1"), geta("B3"), geta("L1"));
	corner_groups[2] = tg(geta("D1"), geta("F7"), geta("L9"));
	corner_groups[3] = tg(geta("D9"), geta("B7"), geta("R9"));

	corner_groups[4] = tg(geta("U7"), geta("F1"), geta("L3"));
	corner_groups[5] = tg(geta("U3"), geta("B1"), geta("R3"));
	corner_groups[6] = tg(geta("D3"), geta("F9"), geta("R7"));
	corner_groups[7] = tg(geta("D7"), geta("B9"), geta("L7"));


	for (int i = 0; i < 8; i++) {
		if (corner_groups[i] & (1 << 2)) {
			res |= 1UL << (i * 8 + 2);
		}

		if (corner_groups[i] & (1 << 1)) {
			res |= 1UL << (i * 8 + 1);
		}

		if (corner_groups[i] & (1 << 0)) {
			res |= 1UL << (i * 8);
		}
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (aarepr[i][j][k] == aside_to_aaside((aside) i)) {
					int index = (i * 9 + j * 3 + k) + 24;
					res |= ONE << (index);
				}
			}
		}
	}

	return res;
}*/