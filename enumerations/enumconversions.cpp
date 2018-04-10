#include "../cubelib.hpp"

using namespace cl;

aaside cl::a_to_aaside(const char &c) {
	switch (tolower(c)) {
		case 'u': return aaside::up_down;
		case 'r': return aaside::right_left;
		case 'f': return aaside::front_back;
		case 'd': return aaside::up_down;
		case 'l': return aaside::right_left;
		case 'b': return aaside::front_back;
		default: throw std::invalid_argument("Illegal sticker: ");
	}
}

aside cl::a_to_aside(const char &c) {
	switch (tolower(c)) {
		case 'u': return aside::up;
		case 'r': return aside::right;
		case 'f': return aside::front;
		case 'd': return aside::down;
		case 'l': return aside::left;
		case 'b': return aside::back;

		default: throw std::invalid_argument("illegal sticker: ");
	}
}

cside cl::a_to_cside(const char &c) {
	switch (tolower(c)) {
		case 'y': return cside::yellow;
		case 'g': return cside::green;
		case 'r': return cside::red;
		case 'w': return cside::white;
		case 'b': return cside::blue;
		case 'o': return cside::orange;

		default: throw std::invalid_argument("illegal sticker: ");
	}
}

aaside cl::aside_to_aaside(const aside &s) {
	switch (s) {
		case aside::up: return aaside::up_down;
		case aside::right: return aaside::right_left;
		case aside::front: return aaside::front_back;
		case aside::down: return aaside::up_down;
		case aside::left: return aaside::right_left;
		case aside::back: return aaside::front_back;

		default: throw std::invalid_argument("illegal aside: ");
	}
}

char cl::cside_to_a(const cl::cside &s) {
	switch (s) {
		case cside::yellow: return 'Y';
		case cside::green: return 'G';
		case cside::red: return 'R';
		case cside::white: return 'W';
		case cside::blue: return 'B';
		case cside::orange: return 'O';
	}
}

char cl::aside_to_a(const cl::aside &s) {
	switch (s) {
		case aside::up: return 'U';
		case aside::right: return 'R';
		case aside::front: return 'F';
		case aside::down: return 'D';
		case aside::left: return 'L';
		case aside::back: return 'B';
	}
}

char cl::aaside_to_a(const cl::aaside &s) {
	switch (s) {
		case aaside::up_down: return 'u';
		case aaside::right_left: return 'r';
		case aaside::front_back: return 'f';
	}
}