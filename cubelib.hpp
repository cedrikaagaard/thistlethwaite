#ifndef THISTLETHWAITE_CUBELIB_HPP
#define THISTLETHWAITE_CUBELIB_HPP

#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

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
	aaside aside_to_aaside(const aside &s);

	char cside_to_a(const cside &s);
	char aside_to_a(const aside &s);
	char aaside_to_a(const aaside &s);
	char rotation_to_a(const rotation &s);

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
		boost::multiprecision::uint256_t chash();
		boost::multiprecision::uint256_t ahash();
		boost::multiprecision::uint256_t aahash();

		uint16_t g0hash();
		uint32_t g1hash();
		boost::multiprecision::uint128_t g2hash();
		uint64_t g3hash();

		bool is_g(int stage);

		// Operators
		bool operator==(cube& other);
	};
}

#endif
