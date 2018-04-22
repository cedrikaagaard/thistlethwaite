#pragma once

#include <string>
#include "cube.hpp"

namespace thistlethwaite {
	/**
	 * Loads the Thistlethwaite's algorithms tables.
	 * Before this function is called, the tables needs to be generated
	 * and exist under ~/.thistlethwaite/g<group>.dat.
	 * If the tables does not exist an exception will be thrown.
	 */
	void init_tables();

	/**
	 * Deallocates the the memory storing the tables.
	 */
	void deallocate_tables();

	/**
	 * Returns a string representation of the rotations
	 * necessary to solve a specified cube.
	 * @param s a string representation of the specified cube.
	 * @return a string representation of the solve rotations.
	 */
	std::string solve(const std::string &s);

	/**
	 * returns a string representation of the rotations
	 * necessary to solve a specified cube.
	 * @param c a cube object representation of the specified cube.
	 * @return a string representation of the solve rotations.
	 */
	std::string solve(const cube &c);
}