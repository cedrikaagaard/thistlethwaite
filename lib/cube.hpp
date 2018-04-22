#pragma once

#include <string>

namespace thistlethwaite {
	// Concrete representation of the Rubik's cube.
	class cube {
		char repr[6][3][3];

	public:
		/**
		 * Creates a new instance of a solved cube.
		 */
		cube();

		/**
		 * Creates a new instance of a specified cube.
		 * If an invalid cube representation is passed, an exception is thrown.
		 * @param s the specified representation of the cube in the form:
		 * UUUUUUUUURRRRRRRRRFFFFFFFFFDDDDDDDDDLLLLLLLLLBBBBBBBBB.
		 */
		cube(const std::string &s);

		/**
		 * Returns the char representation of the specified sticker.
		 * If an invalid cube accessor is passed, an exception is thrown.
		 * @param a sticker specification on the form SI, ex: <U5> (UP:5).
		 * @return a char representation of a sticker on the cube.
		 */
		char get(const std::string &s);

		/**
		 * Returns the char representation of a specified sticker.
		 * If an invalid side, row or column is passed, an exception is thrown.
		 * @param s side of the specified sticker.
		 * @param r row of the specified sticker.
		 * @param c column of the specified sticker.
		 * @return a char representation of a sticker on the cube.
		 */
		char get(int s, int r, int c);

		/**
		 * Rotates the cube according to the specified rotations.
		 * Rotations specified accordingly: U, R, F, D, L, B.
		 * upper case letters for clockwise and lower case for counter cc.
		 * If an invalid rotation is passed, an exception is thrown.
		 * @param s a string representation of rotations.
		 */
		void rotate(const std::string &s);

		/**
		 * Prints a nicely formatted representation of the cube.
		 */
		void print();
	};
}