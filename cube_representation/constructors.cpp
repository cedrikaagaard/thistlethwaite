#include "../cubelib.hpp"

using namespace cl;

cl::cube::cube() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 6; k++) {
				crepr[k][i][j] = (cside) k;
				arepr[k][i][j] = (aside) k;
				aarepr[k][i][j] = aside_to_aaside((aside) k);
			}
		}
	}
}

cl::cube::cube(const std::string &s) {
	aside adefinitions[6];
	aaside aadefinitions[6];

	adefinitions[a_to_cside(s[4])] = aside::up;
	adefinitions[a_to_cside(s[13])] = aside::right;
	adefinitions[a_to_cside(s[22])] = aside::front;
	adefinitions[a_to_cside(s[31])] = aside::down;
	adefinitions[a_to_cside(s[40])] = aside::left;
	adefinitions[a_to_cside(s[49])] = aside::back;

	aadefinitions[a_to_cside(s[4])] = aaside::up_down;
	aadefinitions[a_to_cside(s[13])] = aaside::right_left;
	aadefinitions[a_to_cside(s[22])] = aaside::front_back;
	aadefinitions[a_to_cside(s[31])] = aaside::up_down;
	aadefinitions[a_to_cside(s[40])] = aaside::right_left;
	aadefinitions[a_to_cside(s[49])] = aaside::front_back;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				auto ccs = (char) tolower(s[i * 9 + j * 3 + k]);

				crepr[i][j][k] = a_to_cside(ccs);
				arepr[i][j][k] = adefinitions[a_to_cside(ccs)];
				aarepr[i][j][k] = aadefinitions[a_to_cside(ccs)];
			}
		}
	}
}

cl::cube::cube(cl::cube &copy) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				crepr[i][j][k] = copy.crepr[i][j][k];
				arepr[i][j][k] = copy.arepr[i][j][k];
				aarepr[i][j][k] = copy.aarepr[i][j][k];
			}
		}
	}
}