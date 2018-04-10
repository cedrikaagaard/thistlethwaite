#include "../cubelib.hpp"

using namespace cl;

cside cl::cube::getc(const std::string &s) {
	aside as = a_to_aside(s[0]);
	int row = (s[1] - '1') / 3;
	int col = (s[1] - '1') % 3;

	return crepr[as][row][col];
}

aside cl::cube::geta(const std::string &s) {
	aside as = a_to_aside(s[0]);
	int row = (s[1] - '1') / 3;
	int col = (s[1] - '1') % 3;

	return arepr[as][row][col];
}

aaside cl::cube::getaa(const std::string &s) {
	aside as = a_to_aside(s[0]);
	int row = (s[1] - '1') / 3;
	int col = (s[1] - '1') % 3;

	return aarepr[as][row][col];
}