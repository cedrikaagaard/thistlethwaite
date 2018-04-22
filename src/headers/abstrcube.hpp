#pragma once

#include <boost/multiprecision/cpp_int.hpp>
#include <vector>
#include "cube.hpp"
#include "enums.hpp"

using boost::multiprecision::uint128_t;

/**
 * Abstract representation of a Rubik's cube.
 * This representation does not store any information about
 * the actual stickers, but rather their abstract equivalence.
 */
class abstrcube {
	// Abstract representation of the cube
	side repr[6][3][3];

	// Abstract representation of the cube with regard to symmetry.
	// e.g. white and yellow - up and down, are represented by the same value.
	aside arepr[6][3][3];

public:
	/**
	 * Creates a new instance of a solved abstract cube.
	 */
	abstrcube();

	/**
	 * Creates a new instance of a specified cube.
	 * @param c a cube object representation of a cube.
	 */
	abstrcube(thistlethwaite::cube c);

	/**
	 * Creates a copy instance of a specified cube.
	 * @param copy the cube object that should be copied.
	 */
	abstrcube(const abstrcube &copy);

	/**
	 * Rotates the cube according to the specified rotation.
	 * @param r the rotation that will be applied to the cube.
	 */
	void rotate(const rotation &r);

	/**
	 * Rotates the cube according to the specified rotations.
	 * @param r the rotations that will be applied to the cube.
	 */
	void rotate(const std::vector<rotation> &r);

	/**
	 * returns the side object representation of a specified sticker.
	 * If an invalid cube accessor is passed, an exception is thrown.
	 * @param s sticker specification on the form SI, ex: <U5> (UP:5).
	 * @return side representation of a sticker on the cube.
	 */
	side get(const std::string &s);

	/**
	 * returns the aside object representation of a specified sticker.
	 * If an invalid cube accessor is passed, an exception is thrown.
	 * @param s sticker specification on the form SI, ex: <U5> (UP:5).
	 * @return aside representation of a sticker on the cube.
	 */
	aside aget(const std::string &s);

	/**
	 * Calculates the state of the cube with regards to subgroup g0.
	 * @return an 16 bit integer representation of the g0 state of the cube.
	 */
	uint16_t g0();

	/**
	 * Calculates the state of the cube with regards to subgroup g1.
	 * @return an 32 bit integer representation of the g0 state of the cube.
	 */
	uint32_t g1();

	/**
	 * Calculates the state of the cube with regards to subgroup g2.
	 * This function may throw an exception if the cube is not valid.
	 * @return an 128 bit integer representation of the g0 state of the cube.
	 */
	uint128_t g2();

	/**
	 * Calculates the state of the cube with regards to subgroup g3.
	 * @return an 64 bit integer representation of the g0 state of the cube.
	 */
	uint64_t g3();

	/**
	 * template function wrapper for g0(), g1(), g2(), g().
	 * @tparam g the requested stage.
	 * @tparam T the id variable type.
	 * @return an integer representation fo the g<g> state of the cube.
	 */
	template <int g, typename T> T gid();

	/**
	 * Checks if the cube is currently in a specified stage.,
	 * @param g the specified stage.
	 * @return true if the cube is currently in the stage, else false.
	 */
	bool isg(const short &g);
};