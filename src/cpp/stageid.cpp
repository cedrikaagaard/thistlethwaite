/**
 * This file implements the functions that generate the "id"
 * for a cube stage and subgroup.
 *
 * This id will be used to write and read rotations from the lookup
 * table files.
 *
 * All of the functions follows the specification by Thistlethwaite except
 * for subgroup g2. Thistlethwaites specification of how to go from g2 -> g3
 * is rather complicated. Therefore, this implementation is unoptimized and do
 * not follow Thistlethwaites algorithm. Unfortunately, this leads to an
 * increase of g2's coset space to 2'822'400. This is something that could be
 * improved in the future.
 */

#include <bitset>
#include "abstrcube.hpp"

uint16_t abstrcube::g0() {
	std::bitset<12> good;

	good.set(0, aget("U6") != right_left && aget("R2") != front_back);
	good.set(1, aget("U8") != front_back && aget("F2") != right_left);
	good.set(2, aget("U4") != right_left && aget("L2") != front_back);
	good.set(3, aget("U2") != front_back && aget("B2") != right_left);
	good.set(4, aget("F6") != right_left && aget("R4") != front_back);
	good.set(5, aget("R6") != front_back && aget("B4") != right_left);
	good.set(6, aget("F4") != right_left && aget("L6") != front_back);
	good.set(7, aget("L4") != front_back && aget("B6") != right_left);
	good.set(8, aget("D6") != right_left && aget("R8") != front_back);
	good.set(9, aget("D2") != front_back && aget("F8") != right_left);
	good.set(10, aget("D4") != right_left && aget("L8") != front_back);
	good.set(11, aget("D8") != front_back && aget("B8") != right_left);

	return (uint16_t) good.to_ulong();
}

uint32_t abstrcube::g1() {
	std::bitset<28> res;

	if (aget("R1") == right_left) res.set(1, 1);
	else if (aget("F3") == right_left) res.set(0, 1);

	if (aget("R3") == right_left) res.set(3, 1);
	else if (aget("B1") == right_left) res.set(2, 1);

	if (aget("L3") == right_left) res.set(5, 1);
	else if (aget("F1") == right_left) res.set(4, 1);

	if (aget("R1") == right_left) res.set(7, 1);
	else if (aget("F3") == right_left) res.set(6, 1);

	if (aget("R7") == right_left) res.set(9, 1);
	else if (aget("F9") == right_left) res.set(8, 1);

	if (aget("R9") == right_left) res.set(11, 1);
	else if (aget("B7") == right_left) res.set(10, 1);

	if (aget("L9") == right_left) res.set(13, 1);
	else if (aget("F7") == right_left) res.set(12, 1);

	if (aget("L7") == right_left) res.set(15, 1);
	else if (aget("B9") == right_left) res.set(14, 1);

	res.set(16, aget("U6") != right_left && aget("R2") != right_left);
	res.set(17, aget("U8") != right_left && aget("F2") != right_left);
	res.set(18, aget("U4") != right_left && aget("L2") != right_left);
	res.set(19, aget("U2") != right_left && aget("B2") != right_left);
	res.set(20, aget("F6") != right_left && aget("R4") != right_left);
	res.set(21, aget("R6") != right_left && aget("B2") != right_left);

	res.set(22, aget("F4") != right_left && aget("L6") != right_left);
	res.set(23, aget("L4") != right_left && aget("B6") != right_left);
	res.set(24, aget("D6") != right_left && aget("R8") != right_left);
	res.set(25, aget("D2") != right_left && aget("F8") != right_left);
	res.set(26, aget("D4") != right_left && aget("L8") != right_left);
	res.set(27, aget("D8") != right_left && aget("B8") != right_left);

	return (uint32_t) res.to_ulong();
}

// Utility function for stage g2.
// Calculates which corner tetrad a given piece is in, z = LR
int8_t tg(side x, side y, side z) {
	// x should be up_down
	if (sidetoaside(x) == front_back) {
		side tmp = x;
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

	std::stringstream errss;
	errss << "Seriously invalid cube, can't deal with this shit, I'm out.";
	throw std::invalid_argument(errss.str());
}

uint128_t abstrcube::g2() {
	uint128_t ONE = 1;
	uint128_t res = 0;

	int corner_groups[8];
	bool group_mask[8][8];

	corner_groups[0] = tg(get("U9"), get("F3"), get("R1"));
	corner_groups[1] = tg(get("U1"), get("B3"), get("L1"));
	corner_groups[2] = tg(get("D1"), get("F7"), get("L9"));
	corner_groups[3] = tg(get("D9"), get("B7"), get("R9"));

	corner_groups[4] = tg(get("U7"), get("F1"), get("L3"));
	corner_groups[5] = tg(get("U3"), get("B1"), get("R3"));
	corner_groups[6] = tg(get("D3"), get("F9"), get("R7"));
	corner_groups[7] = tg(get("D7"), get("B9"), get("L7"));

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
				if (arepr[i][j][k] == sidetoaside((side) i)) {
					int index = (i * 9 + j * 3 + k) + 56;
					res |= ONE << (index);
				}
			}
		}
	}

	return res;
}

uint64_t abstrcube::g3() {
	std::bitset<54> res;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (repr[i][j][k] == i) {
					res.set((size_t) (i * 9 + j * 3 + k), 1);
				}
			}
		}
	}

	return (uint64_t) res.to_ullong();
}

template<> uint16_t abstrcube::gid<0, uint16_t>() {
	return g0();
}

template<> uint32_t abstrcube::gid<1, uint32_t>() {
	return g1();
}

template<> uint128_t abstrcube::gid<2, uint128_t>() {
	return g2();
}

template<> uint64_t abstrcube::gid<3, uint64_t >() {
	return g3();
}