#ifndef THISTLETHWAITE_CUBELIB_HPP
#define THISTLETHWAITE_CUBELIB_HPP

#include <vector>
#include <boost/filesystem.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <unordered_map>

namespace mp = boost::multiprecision;

namespace cl {
	/**
	 * Enumerations
	 */
	// abstract sides
	enum aside { up, right, front, down, left, back };

	// abstract asymmetrical sides
	enum aaside { up_down, right_left, front_back };

	// Concrete sides
	enum cside { yellow, green, red, white, blue, orange };

	// Rotations, upper case for clockwise and lower case for counterclockwise
	enum class rotation { U, R, F, D, L, B, u, r, f, d, l, b };

	// Segment of a rubik's cube side, for example, [0,0], [0,1], [0, 2] = top
	enum class side_segment { top, right, left, bottom };

	/**
	 * Enumeration conversion functions
	 */
	aside a_to_aside(const char &c);
	aaside a_to_aaside(const char &c);
	cside a_to_cside(const char &c);
	rotation a_to_rotation(const char &c);
	aaside aside_to_aaside(const aside &s);

	char cside_to_a(const cside &s);
	char aside_to_a(const aside &s);
	char aaside_to_a(const aaside &s);
	char rotation_to_a(const rotation &s);

	// Generate random rotations
	std::vector<cl::rotation> random_rotations(const int &n);

	/**
	 * Main data structure for cube
	 */
	class cube {
		/**
		 * Representation of the cube
		 */
		cside crepr[6][3][3];
		aside arepr[6][3][3];
		aaside aarepr[6][3][3];



	public:
		cube();
		explicit cube(const std::string &s);
		cube(cube &copy);

		cside getc(const std::string &s);
		aside geta(const std::string &s);
		aaside getaa(const std::string &s);

		void printc();
		void printa();
		void printaa();

		void rotate(const rotation &r);
		void rotate(const std::vector<rotation> &r);

		// hash functions
		mp::uint256_t chash();

		uint16_t g0hash();
		uint32_t g1hash();
		mp::uint128_t g2hash();
		uint64_t g3hash();

		bool is_g(int stage);
	};

	/**
	 * Util functions
	 */

	// vector<cl::rotation> to reversed ascii
	std::string rv_to_a(std::vector<cl::rotation> rv);
	std::string rv_to_ra(std::vector<cl::rotation> rv);

	// ascii to vector<rotation>
	std::vector<cl::rotation> a_to_rv(std::string &s);

	// Creates table directory and returns it
	boost::filesystem::path get_table_dir();

	/**
	 * Rotation tables
	 */
	void generate_tables();
	std::vector<cl::rotation> solve(const std::string &def);

	// Reading from tables
	std::vector<cl::rotation> get_g0_rotations(uint16_t state);
	std::vector<cl::rotation> get_g1_rotations(uint32_t state);
	std::vector<cl::rotation> get_g2_rotations(mp::uint128_t state);
	std::vector<cl::rotation> get_g3_rotations(uint64_t state);

	// Solver, used for caching tables
	class thistlethwaite_solver {
		std::unordered_map<uint16_t, std::vector<cl::rotation>> g0_cache;
		std::unordered_map<uint32_t, std::vector<cl::rotation>> g1_cache;
		std::unordered_map<mp::uint128_t, std::vector<cl::rotation>> g2_cache;
		std::unordered_map<uint64_t , std::vector<cl::rotation>> g3_cache;


	public:
		thistlethwaite_solver();
		std::vector<cl::rotation> solve(cl::cube c);
	};
}

#endif
