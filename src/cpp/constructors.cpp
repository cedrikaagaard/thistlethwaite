#include <map>
#include "cube.hpp"
#include "abstrcube.hpp"

bool is_valid_sticker(const char &c) {
	switch (tolower(c)) {
		case 'y': return true;
		case 'r': return true;
		case 'b': return true;
		case 'w': return true;
		case 'o': return true;
		case 'g': return true;
		default: return false;
	}
}

thistlethwaite::cube::cube() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				repr[i][j][k] = sidetoreala((side) i);
			}
		}
	}
}

thistlethwaite::cube::cube(const std::string &s) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				auto ccs = (char) tolower(s[i * 9 + j * 3 + k]);

				if (ccs == '\0' || !is_valid_sticker(ccs)) {
					std::stringstream errss;
					errss << "Invalid cube representation: " << s;
					throw std::invalid_argument(errss.str());
				}

				repr[i][j][k] = ccs;
			}
		}
	}
}

abstrcube::abstrcube() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				repr[i][j][k] = (side) i;
				arepr[i][j][k] = sidetoaside((side) i);
			}
		}
	}
}

abstrcube::abstrcube(thistlethwaite::cube c) {
	/**
	 * Which concrete sticker that corresponds to which abstract side
	 * needs to be determined. This is done by analyzing the center stickers.
	 */
	std::map<char, side> definitions;
	definitions[c.get("U5")] = side::up;
	definitions[c.get("R5")] = side::right;
	definitions[c.get("F5")] = side::front;
	definitions[c.get("D5")] = side::down;
	definitions[c.get("L5")] = side::left;
	definitions[c.get("B5")] = side::back;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				char ccs = c.get(i, j, k);
				repr[i][j][k] = definitions[ccs];
				arepr[i][j][k] = sidetoaside(definitions[ccs]);
			}
		}
	}
}

abstrcube::abstrcube(const abstrcube &copy) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				repr[i][j][k] = copy.repr[i][j][k];
				arepr[i][j][k] = copy.arepr[i][j][k];
			}
		}
	}
}