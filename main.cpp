#include <iostream>
#include <queue>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include "cubelib.hpp"
#include <boost/multiprecision/cpp_int.hpp>
#include <set>
#include <fstream>
#include <map>
#include <vector>

int main() {
	std::cout << "initializing solver" << std::endl;
	cl::thistlethwaite_solver ts;
	std::cout << "solver initialized" << std::endl;

	cl::cube cube;
	uint64_t count = 0;

	for (int i = 0; i < 100000; i++) {
		cube.rotate(cl::random_rotations(50));

		if (cube.is_g(4))
			std::cout << "ALREADY SOLVED?" << std::endl;

		std::cout << cube.g0hash() << std::endl;

		std::vector<cl::rotation> solve_rots = ts.solve(cube);
		count += solve_rots.size();
		cube.rotate(solve_rots);

		if (!cube.is_g(4)) {
			std::cout << "FAIL" << std::endl;
		}
	}

	std::cout << "average solve: " << (count / 100000) << std::endl;


	return 0;
}