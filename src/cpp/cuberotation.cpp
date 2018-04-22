/*
 * This file is rather complicated. The functions in this file implements
 * generic rotation simulation logic that can then be applied to all
 * the different cube class implementations. *
 */

#include "cube.hpp"
#include "abstrcube.hpp"

template <typename T>
void rotate_side(T side_repr[3][3]) {
	T corner_temp = side_repr[0][0];
	T edge_temp = side_repr[0][1];

	side_repr[0][0] = side_repr[2][0];
	side_repr[2][0] = side_repr[2][2];
	side_repr[2][2] = side_repr[0][2];
	side_repr[0][2] = corner_temp;

	side_repr[0][1] = side_repr[1][0];
	side_repr[1][0] = side_repr[2][1];
	side_repr[2][1] = side_repr[1][2];
	side_repr[1][2] = edge_temp;
}

template <typename T>
void side_to_pointers(T side_repr[3][3], side_segment sp, T *res[3]) {
	switch (sp) {
		case side_segment::top:
			res[0] = &side_repr[0][2];
			res[1] = &side_repr[0][1];
			res[2] = &side_repr[0][0];
			break;

		case side_segment::right:
			res[0] = &side_repr[2][2];
			res[1] = &side_repr[1][2];
			res[2] = &side_repr[0][2];
			break;

		case side_segment::bottom:
			res[0] = &side_repr[2][0];
			res[1] = &side_repr[2][1];
			res[2] = &side_repr[2][2];
			break;

		case side_segment::left:
			res[0] = &side_repr[0][0];
			res[1] = &side_repr[1][0];
			res[2] = &side_repr[2][0];
			break;
	}
}

template <typename T>
void rotate_sides(
		T sr1[3][3], side_segment sp1, T sr2[3][3], side_segment sp2,
		T sr3[3][3], side_segment sp3, T sr4[3][3], side_segment sp4)
{
	T *stickers[4][3];
	side_to_pointers(sr1, sp1, stickers[0]);
	side_to_pointers(sr2, sp2, stickers[1]);
	side_to_pointers(sr3, sp3, stickers[2]);
	side_to_pointers(sr4, sp4, stickers[3]);

	T tmp[3] = {*stickers[0][0], *stickers[0][1], *stickers[0][2]};

	*stickers[0][0] = *stickers[1][0];
	*stickers[1][0] = *stickers[2][0];
	*stickers[2][0] = *stickers[3][0];
	*stickers[3][0] = tmp[0];

	*stickers[0][1] = *stickers[1][1];
	*stickers[1][1] = *stickers[2][1];
	*stickers[2][1] = *stickers[3][1];
	*stickers[3][1] = tmp[1];

	*stickers[0][2] = *stickers[1][2];
	*stickers[1][2] = *stickers[2][2];
	*stickers[2][2] = *stickers[3][2];
	*stickers[3][2] = tmp[2];
}

template <typename T>
void rotate_u(T r[6][3][3]) {
	rotate_side(r[side::up]);
	rotate_sides(
			r[side::front], side_segment::top,
			r[side::right], side_segment::top,
			r[side::back], side_segment::top,
			r[side::left], side_segment::top
	);
}

template <typename T>
void rotate_r(T r[6][3][3]) {
	rotate_side(r[side::right]);
	rotate_sides(
			r[side::up], side_segment::right,
			r[side::front], side_segment::right,
			r[side::down], side_segment::right,
			r[side::back], side_segment::left
	);
}

template <typename T>
void rotate_f(T r[6][3][3]) {
	rotate_side(r[side::front]);
	rotate_sides(
			r[side::up], side_segment::bottom,
			r[side::left], side_segment::right,
			r[side::down], side_segment::top,
			r[side::right], side_segment::left
	);
}

template <typename T>
void rotate_d(T r[6][3][3]) {
	rotate_side(r[side::down]);
	rotate_sides(
			r[side::front], side_segment::bottom,
			r[side::left], side_segment::bottom,
			r[side::back], side_segment::bottom,
			r[side::right], side_segment::bottom
	);
}

template <typename T>
void rotate_l(T r[6][3][3]) {
	rotate_side(r[side::left]);
	rotate_sides(
			r[side::front], side_segment::left,
			r[side::up], side_segment::left,
			r[side::back], side_segment::right,
			r[side::down], side_segment::left
	);
}

template <typename T>
void rotate_b(T r[6][3][3]) {
	rotate_side(r[side::back]);
	rotate_sides(
			r[side::up], side_segment::top,
			r[side::right], side_segment::right,
			r[side::down], side_segment::bottom,
			r[side::left], side_segment::left
	);
}

void thistlethwaite::cube::rotate(const std::string &s) {
	for (const char &c : s) {
		switch (c) {
			case 'U': rotate_u(repr); break;
			case 'R': rotate_r(repr); break;
			case 'F': rotate_f(repr); break;
			case 'D': rotate_d(repr); break;
			case 'L': rotate_l(repr); break;
			case 'B': rotate_b(repr); break;

			case 'u': for (int i = 0; i < 3; i++) rotate_u(repr); break;
			case 'r': for (int i = 0; i < 3; i++) rotate_r(repr); break;
			case 'f': for (int i = 0; i < 3; i++) rotate_f(repr); break;
			case 'd': for (int i = 0; i < 3; i++) rotate_d(repr); break;
			case 'l': for (int i = 0; i < 3; i++) rotate_l(repr); break;
			case 'b': for (int i = 0; i < 3; i++) rotate_b(repr); break;

			default:
				std::stringstream error_ss;
				error_ss << "Unknown rotation \"" << c << "\"";
				throw std::runtime_error(error_ss.str());
		}
	}
}

void abstrcube::rotate(const rotation &r) {
	switch (r) {
		case rotation::U: rotate_u(repr); rotate_u(arepr); break;
		case rotation::R: rotate_r(repr); rotate_r(arepr); break;
		case rotation::F: rotate_f(repr); rotate_f(arepr); break;
		case rotation::D: rotate_d(repr); rotate_d(arepr); break;
		case rotation::L: rotate_l(repr); rotate_l(arepr); break;
		case rotation::B: rotate_b(repr); rotate_b(arepr); break;

		case rotation::u:
			for(int i = 0; i < 3; i++){rotate_u(repr); rotate_u(arepr);} break;

		case rotation::r:
			for(int i = 0; i < 3; i++){rotate_r(repr); rotate_r(arepr);} break;

		case rotation::f:
			for(int i = 0; i < 3; i++){rotate_f(repr); rotate_f(arepr);} break;

		case rotation::d:
			for(int i = 0; i < 3; i++){rotate_d(repr); rotate_d(arepr);} break;

		case rotation::l:
			for(int i = 0; i < 3; i++){rotate_l(repr); rotate_l(arepr);} break;

		case rotation::b:
			for(int i = 0; i < 3; i++){rotate_b(repr); rotate_b(arepr);} break;
	}
}

void abstrcube::rotate(const std::vector<rotation> &r) {
	for (const rotation &rot : r) {
		rotate(rot);
	}
}