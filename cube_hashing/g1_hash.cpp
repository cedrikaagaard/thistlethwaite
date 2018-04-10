#include "../cubelib.hpp"

using namespace cl;

uint32_t cl::cube::g1hash() {
	uint8_t cornerv[8];
	uint8_t corner_mapping[3];

	corner_mapping[aaside::right_left] = 2;
	corner_mapping[aaside::front_back] = 1;
	corner_mapping[aaside::up_down] = 0;

	cornerv[0] = corner_mapping[getaa("R1")];
	cornerv[1] = corner_mapping[getaa("R3")];
	cornerv[2] = corner_mapping[getaa("L3")];
	cornerv[3] = corner_mapping[getaa("L1")];
	cornerv[4] = corner_mapping[getaa("R7")];
	cornerv[5] = corner_mapping[getaa("R9")];
	cornerv[6] = corner_mapping[getaa("L9")];
	cornerv[7] = corner_mapping[getaa("L7")];

	bool edgev[12];

	edgev[0] = (getaa("U6") != right_left && getaa("R2") != right_left);
	edgev[1] = (getaa("U8") != right_left && getaa("F2") != right_left);
	edgev[2] = (getaa("U4") != right_left && getaa("L2") != right_left);
	edgev[3] = (getaa("U2") != right_left && getaa("B2") != right_left);
	edgev[4] = (getaa("F6") != right_left && getaa("R4") != right_left);
	edgev[5] = (getaa("R6") != right_left && getaa("B4") != right_left);
	edgev[6] = (getaa("F4") != right_left && getaa("L6") != right_left);
	edgev[7] = (getaa("L4") != right_left && getaa("B6") != right_left);
	edgev[8] = (getaa("D6") != right_left && getaa("R8") != right_left);
	edgev[9] = (getaa("D2") != right_left && getaa("F8") != right_left);
	edgev[10] = (getaa("D4") != right_left && getaa("L8") != right_left);
	edgev[11] = (getaa("D8") != right_left && getaa("B8") != right_left);

	uint32_t res = 0;

	for (int i = 0; i < 8; i++) {
		if (cornerv[i] == 2) {
			res |= 1 << (i * 2 + 1);
		}

		else if (cornerv[i] == 1) {
			res |= 1 << (i * 2);
		}
	}

	for (int i = 0; i < 12; i++) {
		if (edgev[i]) {
			res |= 1 << (i + 16);
		}
	}

	return res;
}