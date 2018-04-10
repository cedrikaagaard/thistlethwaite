#include "../cubelib.hpp"

using namespace cl;

uint16_t cl::cube::g0hash() {
	// Good list
	bool gl[12];
	uint16_t res = 0;

	gl[0] = getaa("U6") != right_left && getaa("R2") != front_back;
	gl[1] = getaa("U8") != front_back && getaa("F2") != right_left;

	gl[2] = getaa("U4") != right_left && getaa("L2") != front_back;
	gl[3] = getaa("U2") != front_back && getaa("B2") != right_left;

	gl[4] = getaa("F6") != right_left && getaa("R4") != front_back;
	gl[5] = getaa("R6") != front_back && getaa("B4") != right_left;

	gl[6] = getaa("F4") != right_left && getaa("L6") != front_back;
	gl[7] = getaa("L4") != front_back && getaa("B6") != right_left;

	gl[8] = getaa("D6") != right_left && getaa("R8") != front_back;
	gl[9] = getaa("D2") != front_back && getaa("F8") != right_left;

	gl[10] = getaa("D4") != right_left && getaa("L8") != front_back;
	gl[11] = getaa("D8") != front_back && getaa("B8") != right_left;

	for (int i = 0; i < 12; i++) {
		if (gl[i]) {
			res |= 1 << i;
		}
	}

	return res;
}