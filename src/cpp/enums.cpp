#include <string>
#include <sstream>
#include <stdexcept>
#include "enums.hpp"

side atoside(const char &c) {
	switch (tolower(c)) {
		case 'u': return side::up;
		case 'r': return side::right;
		case 'f': return side::front;
		case 'd': return side::down;
		case 'l': return side::left;
		case 'b': return side::back;

		default:
			std::stringstream error_ss;
			error_ss << "Not possible to convert \"" << c << "\" to rotation.";
			throw std::invalid_argument(error_ss.str());
	}
}

rotation atorot(const char &c) {
	switch (c) {
		case 'U': return rotation::U;
		case 'R': return rotation::R;
		case 'F': return rotation::F;
		case 'D': return rotation::D;
		case 'L': return rotation::L;
		case 'B': return rotation::B;
		case 'u': return rotation::u;
		case 'r': return rotation::r;
		case 'f': return rotation::f;
		case 'd': return rotation::d;
		case 'l': return rotation::l;
		case 'b': return rotation::b;

		default:
			std::stringstream error_ss;
			error_ss << "Not possible to convert \"" << c << "\" to rotation.";
			throw std::invalid_argument(error_ss.str());
	}
}

aside sidetoaside(const side &s) {
	switch (s) {
		case side::up: return aside::up_down;
		case side::right: return aside::right_left;
		case side::front: return aside::front_back;
		case side::down: return aside::up_down;
		case side::left: return aside::right_left;
		case side::back: return aside::front_back;

		default:
			std::stringstream error_ss;
			error_ss << "Not possible to convert \"" << s << "\" to aside.";
			throw std::invalid_argument(error_ss.str());
	}
}

char sidetoreala(const side &s) {
	switch (s) {
		case side::up: return 'y';
		case side::right: return 'r';
		case side::front: return 'b';
		case side::down: return 'w';
		case side::left: return 'o';
		case side::back: return 'g';

		default:
			std::stringstream error_ss;
			error_ss << "Not possible to convert \"" << s << "\" to ascii.";
			throw std::invalid_argument(error_ss.str());
	}
}

char rottoa(const rotation &r) {
	switch (r) {
		case rotation::U: return 'U';
		case rotation::F: return 'F';
		case rotation::R: return 'R';
		case rotation::D: return 'D';
		case rotation::B: return 'B';
		case rotation::L: return 'L';

		case rotation::u: return 'u';
		case rotation::f: return 'f';
		case rotation::r: return 'r';
		case rotation::d: return 'd';
		case rotation::b: return 'b';
		case rotation::l: return 'l';
	}
}

char rottoia(const rotation &r) {
	switch (r) {
		case rotation::U: return 'u';
		case rotation::F: return 'f';
		case rotation::R: return 'r';
		case rotation::D: return 'd';
		case rotation::B: return 'b';
		case rotation::L: return 'l';

		case rotation::u: return 'L';
		case rotation::f: return 'F';
		case rotation::r: return 'R';
		case rotation::d: return 'D';
		case rotation::b: return 'B';
		case rotation::l: return 'L';
	}
}