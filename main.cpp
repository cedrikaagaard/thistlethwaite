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


std::string vec_to_string(std::vector<cl::rotation> r) {
	std::string sb = "";

	for (int i = r.size() - 1; i >= 0; i--) {
		sb += cl::rotation_to_a(r[i]);
	}

	return sb;
}

void bfs_0() {
	std::ofstream file;
	file.open ("g0.rt");

	cl::cube cube;
	std::unordered_map<uint16_t, std::vector<cl::rotation>> rotation_tracker;

	std::queue<cl::cube> cube_q;
	std::queue<std::vector<cl::rotation>> rot_q;

	std::vector<cl::rotation> e;
	cube_q.emplace(cube);
	rot_q.emplace(e);


	while (!cube_q.empty()) {
		cl::cube current_cube = cube_q.front(); cube_q.pop();
		std::vector<cl::rotation> current_vec = rot_q.front(); rot_q.pop();

		if (rotation_tracker.find(current_cube.g0hash()) != rotation_tracker.end()) {
			continue;
		}

		rotation_tracker[current_cube.g0hash()] = current_vec;

		cl::cube ucube(current_cube);
		std::vector<cl::rotation> uvec(current_vec);

		cl::cube fcube(current_cube);
		std::vector<cl::rotation> fvec(current_vec);

		cl::cube rcube(current_cube);
		std::vector<cl::rotation> rvec(current_vec);

		cl::cube dcube(current_cube);
		std::vector<cl::rotation> dvec(current_vec);

		cl::cube bcube(current_cube);
		std::vector<cl::rotation> bvec(current_vec);

		cl::cube lcube(current_cube);
		std::vector<cl::rotation> lvec(current_vec);

		ucube.rotate(cl::rotation::U);
		uvec.emplace_back(cl::rotation::u);

		fcube.rotate(cl::rotation::F);
		fvec.emplace_back(cl::rotation::f);

		rcube.rotate(cl::rotation::R);
		rvec.emplace_back(cl::rotation::r);

		dcube.rotate(cl::rotation::D);
		dvec.emplace_back(cl::rotation::d);

		bcube.rotate(cl::rotation::B);
		bvec.emplace_back(cl::rotation::b);

		lcube.rotate(cl::rotation::L);
		lvec.emplace_back(cl::rotation::l);

		cube_q.emplace(ucube);
		rot_q.emplace(uvec);

		cube_q.emplace(fcube);
		rot_q.emplace(fvec);

		cube_q.emplace(rcube);
		rot_q.emplace(rvec);

		cube_q.emplace(dcube);
		rot_q.emplace(dvec);

		cube_q.emplace(bcube);
		rot_q.emplace(bvec);

		cube_q.emplace(lcube);
		rot_q.emplace(lvec);
	}

	for (auto const& x : rotation_tracker) {
		file << x.first << ' ' << vec_to_string(x.second) << std::endl;
	}

	file.close();
}

void bfs_1() {
	std::ofstream file;
	file.open ("g1.rt");

	cl::cube cube;
	std::unordered_map<uint32_t, std::vector<cl::rotation>> rotation_tracker;

	std::queue<cl::cube> cube_q;
	std::queue<std::vector<cl::rotation>> rot_q;

	std::vector<cl::rotation> e;
	cube_q.emplace(cube);
	rot_q.emplace(e);


	while (!cube_q.empty()) {
		cl::cube current_cube = cube_q.front(); cube_q.pop();
		std::vector<cl::rotation> current_vec = rot_q.front(); rot_q.pop();

		if (rotation_tracker.find(current_cube.g1hash()) != rotation_tracker.end()) {
			continue;
		}

		rotation_tracker[current_cube.g1hash()] = current_vec;

		cl::cube ucube(current_cube);
		std::vector<cl::rotation> uvec(current_vec);

		cl::cube fcube(current_cube);
		std::vector<cl::rotation> fvec(current_vec);

		cl::cube rcube(current_cube);
		std::vector<cl::rotation> rvec(current_vec);

		cl::cube dcube(current_cube);
		std::vector<cl::rotation> dvec(current_vec);

		cl::cube bcube(current_cube);
		std::vector<cl::rotation> bvec(current_vec);

		cl::cube lcube(current_cube);
		std::vector<cl::rotation> lvec(current_vec);

		ucube.rotate(cl::rotation::U);
		uvec.emplace_back(cl::rotation::u);
		ucube.rotate(cl::rotation::U);
		uvec.emplace_back(cl::rotation::u);

		fcube.rotate(cl::rotation::F);
		fvec.emplace_back(cl::rotation::f);

		rcube.rotate(cl::rotation::R);
		rvec.emplace_back(cl::rotation::r);

		dcube.rotate(cl::rotation::D);
		dvec.emplace_back(cl::rotation::d);
		dcube.rotate(cl::rotation::D);
		dvec.emplace_back(cl::rotation::d);

		bcube.rotate(cl::rotation::B);
		bvec.emplace_back(cl::rotation::b);

		lcube.rotate(cl::rotation::L);
		lvec.emplace_back(cl::rotation::l);

		cube_q.emplace(ucube);
		rot_q.emplace(uvec);

		cube_q.emplace(fcube);
		rot_q.emplace(fvec);

		cube_q.emplace(rcube);
		rot_q.emplace(rvec);

		cube_q.emplace(dcube);
		rot_q.emplace(dvec);

		cube_q.emplace(bcube);
		rot_q.emplace(bvec);

		cube_q.emplace(lcube);
		rot_q.emplace(lvec);
	}

	for (auto const& x : rotation_tracker) {
		file << x.first << ' ' << vec_to_string(x.second) << std::endl;
	}

	file.close();
}

void bfs_2() {
	std::ofstream file;
	file.open ("g2.rt");

	cl::cube cube;
	std::map<boost::multiprecision::uint128_t, std::vector<cl::rotation>> rotation_tracker;

	std::queue<cl::cube> cube_q;
	std::queue<std::vector<cl::rotation>> rot_q;

	std::vector<cl::rotation> e;
	cube_q.emplace(cube);
	rot_q.emplace(e);


	while (!cube_q.empty()) {
		std::cout << "size: " << rotation_tracker.size() << std::endl;

		cl::cube current_cube = cube_q.front(); cube_q.pop();
		std::vector<cl::rotation> current_vec = rot_q.front(); rot_q.pop();


		if (rotation_tracker.find(current_cube.g2hash()) != rotation_tracker.end()) {
			continue;
		}

		rotation_tracker[current_cube.g2hash()] = current_vec;

		cl::cube ucube(current_cube);
		std::vector<cl::rotation> uvec(current_vec);

		cl::cube fcube(current_cube);
		std::vector<cl::rotation> fvec(current_vec);

		cl::cube rcube(current_cube);
		std::vector<cl::rotation> rvec(current_vec);

		cl::cube dcube(current_cube);
		std::vector<cl::rotation> dvec(current_vec);

		cl::cube bcube(current_cube);
		std::vector<cl::rotation> bvec(current_vec);

		cl::cube lcube(current_cube);
		std::vector<cl::rotation> lvec(current_vec);

		ucube.rotate(cl::rotation::U);
		uvec.emplace_back(cl::rotation::u);
		ucube.rotate(cl::rotation::U);
		uvec.emplace_back(cl::rotation::u);

		fcube.rotate(cl::rotation::F);
		fvec.emplace_back(cl::rotation::f);
		fcube.rotate(cl::rotation::F);
		fvec.emplace_back(cl::rotation::f);

		rcube.rotate(cl::rotation::R);
		rvec.emplace_back(cl::rotation::r);

		dcube.rotate(cl::rotation::D);
		dvec.emplace_back(cl::rotation::d);
		dcube.rotate(cl::rotation::D);
		dvec.emplace_back(cl::rotation::d);

		bcube.rotate(cl::rotation::B);
		bvec.emplace_back(cl::rotation::b);
		bcube.rotate(cl::rotation::B);
		bvec.emplace_back(cl::rotation::b);

		lcube.rotate(cl::rotation::L);
		lvec.emplace_back(cl::rotation::l);

		cube_q.emplace(ucube);
		rot_q.emplace(uvec);

		cube_q.emplace(fcube);
		rot_q.emplace(fvec);

		cube_q.emplace(rcube);
		rot_q.emplace(rvec);

		cube_q.emplace(dcube);
		rot_q.emplace(dvec);

		cube_q.emplace(bcube);
		rot_q.emplace(bvec);

		cube_q.emplace(lcube);
		rot_q.emplace(lvec);
	}

	std::cout << "g2 coset space: " << rotation_tracker.size() << std::endl;

	for (auto const& x : rotation_tracker) {
		file << x.first << ' ' << vec_to_string(x.second) << std::endl;
	}

	file.close();
}

void bfs_3() {
	std::ofstream file;
	file.open ("g3.rt");

	cl::cube cube;
	std::unordered_map<uint64_t, std::vector<cl::rotation>> rotation_tracker;

	std::queue<cl::cube> cube_q;
	std::queue<std::vector<cl::rotation>> rot_q;

	std::vector<cl::rotation> e;
	cube_q.emplace(cube);
	rot_q.emplace(e);


	while (!cube_q.empty()) {
		cl::cube current_cube = cube_q.front(); cube_q.pop();
		std::vector<cl::rotation> current_vec = rot_q.front(); rot_q.pop();

		if (rotation_tracker.find(current_cube.g3hash()) != rotation_tracker.end()) {
			continue;
		}

		rotation_tracker[current_cube.g3hash()] = current_vec;

		cl::cube ucube(current_cube);
		std::vector<cl::rotation> uvec(current_vec);

		cl::cube fcube(current_cube);
		std::vector<cl::rotation> fvec(current_vec);

		cl::cube rcube(current_cube);
		std::vector<cl::rotation> rvec(current_vec);

		cl::cube dcube(current_cube);
		std::vector<cl::rotation> dvec(current_vec);

		cl::cube bcube(current_cube);
		std::vector<cl::rotation> bvec(current_vec);

		cl::cube lcube(current_cube);
		std::vector<cl::rotation> lvec(current_vec);

		ucube.rotate(cl::rotation::U);
		uvec.emplace_back(cl::rotation::u);
		ucube.rotate(cl::rotation::U);
		uvec.emplace_back(cl::rotation::u);

		fcube.rotate(cl::rotation::F);
		fvec.emplace_back(cl::rotation::f);
		fcube.rotate(cl::rotation::F);
		fvec.emplace_back(cl::rotation::f);

		rcube.rotate(cl::rotation::R);
		rvec.emplace_back(cl::rotation::r);
		rcube.rotate(cl::rotation::R);
		rvec.emplace_back(cl::rotation::r);

		dcube.rotate(cl::rotation::D);
		dvec.emplace_back(cl::rotation::d);
		dcube.rotate(cl::rotation::D);
		dvec.emplace_back(cl::rotation::d);

		bcube.rotate(cl::rotation::B);
		bvec.emplace_back(cl::rotation::b);
		bcube.rotate(cl::rotation::B);
		bvec.emplace_back(cl::rotation::b);

		lcube.rotate(cl::rotation::L);
		lvec.emplace_back(cl::rotation::l);
		lcube.rotate(cl::rotation::L);
		lvec.emplace_back(cl::rotation::l);

		cube_q.emplace(ucube);
		rot_q.emplace(uvec);

		cube_q.emplace(fcube);
		rot_q.emplace(fvec);

		cube_q.emplace(rcube);
		rot_q.emplace(rvec);

		cube_q.emplace(dcube);
		rot_q.emplace(dvec);

		cube_q.emplace(bcube);
		rot_q.emplace(bvec);

		cube_q.emplace(lcube);
		rot_q.emplace(lvec);
	}

	for (auto const& x : rotation_tracker) {
		file << x.first << ' ' << vec_to_string(x.second) << std::endl;
	}

	file.close();
}


int main() {
	//bfs_0();
	//bfs_1();
	//bfs_2();
	//bfs_3();

	cl::cube c;
	std::cout << c.g2hash() << std::endl;


	std::cout << c.g0hash() << std::endl;
	std::cout << c.g1hash() << std::endl;
	std::cout << c.g2hash() << std::endl;
	std::cout << c.g3hash() << std::endl;

	std::cout << "* start *" << std::endl;


	c.rotate(cl::rotation::U);
	c.rotate(cl::rotation::R);
	c.rotate(cl::rotation::U);
	c.rotate(cl::rotation::L);
	c.rotate(cl::rotation::D);

	std::cout << c.g0hash() << std::endl;

	c.rotate(cl::rotation::d);
	c.rotate(cl::rotation::u);
	c.rotate(cl::rotation::r);
	c.rotate(cl::rotation::u);

	std::cout << c.g1hash() << std::endl;

	c.rotate(cl::rotation::f);
	c.rotate(cl::rotation::d);
	c.rotate(cl::rotation::d);
	c.rotate(cl::rotation::b);
	c.rotate(cl::rotation::u);
	c.rotate(cl::rotation::u);
	c.rotate(cl::rotation::b);
	c.rotate(cl::rotation::f);
	c.rotate(cl::rotation::f);
	c.rotate(cl::rotation::u);
	c.rotate(cl::rotation::u);
	c.rotate(cl::rotation::f);

	std::cout << c.g2hash() << std::endl;

	// lrd dbb rbb rrr ffr bbu u
	c.rotate(cl::rotation::l);
	c.rotate(cl::rotation::r);
	c.rotate(cl::rotation::d);

	c.rotate(cl::rotation::d);
	c.rotate(cl::rotation::b);
	c.rotate(cl::rotation::b);

	c.rotate(cl::rotation::r);
	c.rotate(cl::rotation::b);
	c.rotate(cl::rotation::b);

	c.rotate(cl::rotation::r);
	c.rotate(cl::rotation::r);
	c.rotate(cl::rotation::r);

	c.rotate(cl::rotation::f);
	c.rotate(cl::rotation::f);
	c.rotate(cl::rotation::r);

	c.rotate(cl::rotation::b);
	c.rotate(cl::rotation::b);
	c.rotate(cl::rotation::u);

	c.rotate(cl::rotation::u);



	// rrd dbb lld drr ffu u
	c.rotate(cl::rotation::r);
	c.rotate(cl::rotation::r);
	c.rotate(cl::rotation::d);

	c.rotate(cl::rotation::d);
	c.rotate(cl::rotation::b);
	c.rotate(cl::rotation::b);

	c.rotate(cl::rotation::l);
	c.rotate(cl::rotation::l);
	c.rotate(cl::rotation::d);

	c.rotate(cl::rotation::d);
	c.rotate(cl::rotation::r);
	c.rotate(cl::rotation::r);

	c.rotate(cl::rotation::f);
	c.rotate(cl::rotation::f);
	c.rotate(cl::rotation::u);

	c.rotate(cl::rotation::u);

	c.printc();






	return 0;
}