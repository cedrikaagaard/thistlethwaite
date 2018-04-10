#include "../cubelib.hpp"

using namespace cl;

/**
 * Util functions used by the cube class
 */
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
	rotate_side(r[aside::up]);
	rotate_sides(
			r[aside::front], side_segment::top,
			r[aside::right], side_segment::top,
			r[aside::back], side_segment::top,
			r[aside::left], side_segment::top
	);
}

template <typename T>
void rotate_r(T r[6][3][3]) {
	rotate_side(r[aside::right]);
	rotate_sides(
			r[aside::up], side_segment::right,
			r[aside::front], side_segment::right,
			r[aside::down], side_segment::right,
			r[aside::back], side_segment::left
	);
}

template <typename T>
void rotate_f(T r[6][3][3]) {
	rotate_side(r[aside::front]);
	rotate_sides(
			r[aside::up], side_segment::bottom,
			r[aside::left], side_segment::right,
			r[aside::down], side_segment::top,
			r[aside::right], side_segment::left
	);
}




template <typename T>
void rotate_d(T r[6][3][3]) {
	rotate_side(r[aside::down]);
	rotate_sides(
			r[aside::front], side_segment::bottom,
			r[aside::left], side_segment::bottom,
			r[aside::back], side_segment::bottom,
			r[aside::right], side_segment::bottom
	);
}

template <typename T>
void rotate_l(T r[6][3][3]) {
	rotate_side(r[aside::left]);
	rotate_sides(
			r[aside::front], side_segment::left,
			r[aside::up], side_segment::left,
			r[aside::back], side_segment::right,
			r[aside::down], side_segment::left
	);
}

template <typename T>
void rotate_b(T r[6][3][3]) {
	rotate_side(r[aside::back]);
	rotate_sides(
			r[aside::up], side_segment::top,
			r[aside::right], side_segment::right,
			r[aside::down], side_segment::bottom,
			r[aside::left], side_segment::left
	);
}

void cl::cube::rotate(const cl::rotation &r) {
	switch (r) {
		case rotation::U:
			rotate_u(crepr);
			rotate_u(arepr);
			rotate_u(aarepr);
			break;

		case rotation::R:
			rotate_r(crepr);
			rotate_r(arepr);
			rotate_r(aarepr);
			break;

		case rotation::F:
			rotate_f(crepr);
			rotate_f(arepr);
			rotate_f(aarepr);
			break;

		case rotation::D:
			rotate_d(crepr);
			rotate_d(arepr);
			rotate_d(aarepr);
			break;

		case rotation::L:
			rotate_l(crepr);
			rotate_l(arepr);
			rotate_l(aarepr);
			break;

		case rotation::B:
			rotate_b(crepr);
			rotate_b(arepr);
			rotate_b(aarepr);
			break;

		case rotation::u:
			for (int i = 0; i < 3; i++) {
				rotate_u(crepr);
				rotate_u(arepr);
				rotate_u(aarepr);
			}
			break;

		case rotation::r:
			for (int i = 0; i < 3; i++) {
				rotate_r(crepr);
				rotate_r(arepr);
				rotate_r(aarepr);
			}
			break;

		case rotation::f:
			for (int i = 0; i < 3; i++) {
				rotate_f(crepr);
				rotate_f(arepr);
				rotate_f(aarepr);
			}
			break;

		case rotation::d:
			for (int i = 0; i < 3; i++) {
				rotate_d(crepr);
				rotate_d(arepr);
				rotate_d(aarepr);
			}
			break;

		case rotation::l:
			for (int i = 0; i < 3; i++) {
				rotate_l(crepr);
				rotate_l(arepr);
				rotate_l(aarepr);
			}
			break;

		case rotation::b:
			for (int i = 0; i < 3; i++) {
				rotate_b(crepr);
				rotate_b(arepr);
				rotate_b(aarepr);
			}
			break;
	}
}