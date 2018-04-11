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
			if (z == right) {
				return 0;
			}

			else if (z == left) {
				return 1;
			}
		}

		else if (y == back) {
			if (z == right) {
				return 2;
			}

			else if (z == left) {
				return 3;
			}
		}
	}

	if (x == down) {
		if (y == front) {
			if (z == right) {
				return 4;
			}

			else if (z == left) {
				return 5;
			}
		}

		else if (y == back) {
			if (z == right) {
				return 6;
			}

			else if (z == left) {
				return 7;
			}
		}
	}
}



boost::multiprecision::uint128_t cl::cube::g2hash() {
	boost::multiprecision::uint128_t ONE = 1;
	boost::multiprecision::uint128_t res = 0;

	bool good_edges[8];
	bool good_corners[8];

	int corner_groups[8];
	bool group_0_mask[8];
	bool group_1_mask[8];
	bool group_2_mask[8];
	bool group_3_mask[8];

	bool group_4_mask[8];
	bool group_5_mask[8];
	bool group_6_mask[8];
	bool group_7_mask[8];

	corner_groups[0] = tg(geta("U9"), geta("F3"), geta("R1"));
	corner_groups[1] = tg(geta("U1"), geta("B3"), geta("L1"));
	corner_groups[2] = tg(geta("D1"), geta("F7"), geta("L9"));
	corner_groups[3] = tg(geta("D9"), geta("B7"), geta("R9"));

	corner_groups[4] = tg(geta("U7"), geta("F1"), geta("L3"));
	corner_groups[5] = tg(geta("U3"), geta("B1"), geta("R3"));
	corner_groups[6] = tg(geta("D3"), geta("F9"), geta("R7"));
	corner_groups[7] = tg(geta("D7"), geta("B9"), geta("L7"));

	for (int i = 0; i < 8; i++) {
		if (corner_groups[i] == 0) {
			group_0_mask[i] = true;
			group_1_mask[i] = false;
			group_2_mask[i] = false;
			group_3_mask[i] = false;
			group_4_mask[i] = false;
			group_5_mask[i] = false;
			group_6_mask[i] = false;
			group_7_mask[i] = false;
		}

		if (corner_groups[i] == 1) {
			group_0_mask[i] = false;
			group_1_mask[i] = true;
			group_2_mask[i] = false;
			group_3_mask[i] = false;
			group_4_mask[i] = false;
			group_5_mask[i] = false;
			group_6_mask[i] = false;
			group_7_mask[i] = false;
		}

		if (corner_groups[i] == 2) {
			group_0_mask[i] = false;
			group_1_mask[i] = false;
			group_2_mask[i] = true;
			group_3_mask[i] = false;
			group_4_mask[i] = false;
			group_5_mask[i] = false;
			group_6_mask[i] = false;
			group_7_mask[i] = false;
		}

		if (corner_groups[i] == 3) {
			group_0_mask[i] = false;
			group_1_mask[i] = false;
			group_2_mask[i] = false;
			group_3_mask[i] = true;
			group_4_mask[i] = false;
			group_5_mask[i] = false;
			group_6_mask[i] = false;
			group_7_mask[i] = false;
		}

		if (corner_groups[i] == 4) {
			group_0_mask[i] = false;
			group_1_mask[i] = false;
			group_2_mask[i] = false;
			group_3_mask[i] = false;
			group_4_mask[i] = true;
			group_5_mask[i] = false;
			group_6_mask[i] = false;
			group_7_mask[i] = false;
		}

		if (corner_groups[i] == 5) {
			group_0_mask[i] = false;
			group_1_mask[i] = false;
			group_2_mask[i] = false;
			group_3_mask[i] = false;
			group_4_mask[i] = false;
			group_5_mask[i] = true;
			group_6_mask[i] = false;
			group_7_mask[i] = false;
		}

		if (corner_groups[i] == 6) {
			group_0_mask[i] = false;
			group_1_mask[i] = false;
			group_2_mask[i] = false;
			group_3_mask[i] = false;
			group_4_mask[i] = false;
			group_5_mask[i] = false;
			group_6_mask[i] = true;
			group_7_mask[i] = false;
		}

		if (corner_groups[i] == 7) {
			group_0_mask[i] = false;
			group_1_mask[i] = false;
			group_2_mask[i] = false;
			group_3_mask[i] = false;
			group_4_mask[i] = false;
			group_5_mask[i] = false;
			group_6_mask[i] = false;
			group_7_mask[i] = true;
		}
	}



	/*good_corners[0] = getaa("U9") == up_down && getaa("F3") == front_back;
	good_corners[1] = getaa("U3") == up_down && getaa("B1") == front_back;
	good_corners[2] = getaa("U7") == up_down && getaa("F1") == front_back;
	good_corners[3] = getaa("U1") == up_down && getaa("B3") == front_back;

	good_corners[4] = getaa("D3") == up_down && getaa("F9") == front_back;
	good_corners[5] = getaa("D9") == up_down && getaa("B7") == front_back;
	good_corners[6] = getaa("D1") == up_down && getaa("F7") == front_back;
	good_corners[7] = getaa("D7") == up_down && getaa("B9") == front_back;

	good_edges[0] = geta("U6") == up_down;
	good_edges[1] = geta("U4") == up_down;

	good_edges[2] = geta("F6") == front_back;
	good_edges[3] = geta("B4") == front_back;
	good_edges[4] = geta("F4") == front_back;
	good_edges[5] = geta("B6") == front_back;

	good_edges[6] = geta("D6") == up_down;
	good_edges[7] = geta("D4") == up_down;*/

	for (int i = 0; i < 8; i++) {
		if (group_0_mask[i]) {
			res |= 1UL << i;
		}

		if (group_1_mask[i]) {
			res |= 1UL << (i + 8);
		}

		if (group_2_mask[i]) {
			res |= 1UL << (i + 16);
		}

		if (group_3_mask[i]) {
			res |= 1UL << (i + 24);
		}

		if (group_4_mask[i]) {
			res |= 1UL << (i + 24);
		}

		if (group_5_mask[i]) {
			res |= 1UL << (i + 32);
		}

		if (group_6_mask[i]) {
			res |= 1UL << (i + 40);
		}

		if (group_7_mask[i]) {
			res |= 1UL << (i + 48);
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