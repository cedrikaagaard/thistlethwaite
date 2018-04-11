#include "../cubelib.hpp"

using namespace cl;

uint32_t cl::cube::g1hash() {
	uint8_t cornerv[8];

	if (getaa("R1") == right_left) cornerv[0] = 2;
	else if (getaa("F3") == right_left) cornerv[0] = 1;
	else cornerv[0] = 0;

	if (getaa("R3") == right_left) cornerv[1] = 2;
	else if (getaa("B1") == right_left) cornerv[1] = 1;
	else cornerv[1] = 0;

	if (getaa("L3") == right_left) cornerv[2] = 2;
	else if (getaa("F1") == right_left) cornerv[2] = 1;
	else cornerv[2] = 0;

	if (getaa("R1") == right_left) cornerv[3] = 2;
	else if (getaa("F3") == right_left) cornerv[3] = 1;
	else cornerv[3] = 0;

	if (getaa("R7") == right_left) cornerv[4] = 2;
	else if (getaa("F9") == right_left) cornerv[4] = 1;
	else cornerv[4] = 0;

	if (getaa("R9") == right_left) cornerv[5] = 2;
	else if (getaa("B7") == right_left) cornerv[5] = 1;
	else cornerv[5] = 0;

	if (getaa("L9") == right_left) cornerv[6] = 2;
	else if (getaa("F7") == right_left) cornerv[6] = 1;
	else cornerv[6] = 0;

	if (getaa("L7") == right_left) cornerv[7] = 2;
	else if (getaa("B9") == right_left) cornerv[7] = 1;
	else cornerv[7] = 0;

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
	uint32_t ONE = 1;

	for (int i = 0; i < 8; i++) {
		if (cornerv[i] == 2) {
			res |= ONE << (i * 2 + 1);
		}

		else if (cornerv[i] == 1) {
			res |= ONE << (i * 2);
		}
	}

	for (int i = 0; i < 12; i++) {
		if (edgev[i]) {
			res |= ONE << (i + 16);
		}
	}

	return res;
}