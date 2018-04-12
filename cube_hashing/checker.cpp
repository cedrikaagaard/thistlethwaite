#include "../cubelib.hpp"

using namespace cl;

bool cl::cube::is_g(int stage) {
	uint16_t g1_in_g0 = 4095;
	uint32_t g2_in_g1 = 168471210;
	boost::multiprecision::uint128_t g3_in_g2("1298074214633706835075032330539553");
	uint64_t g4_in_g3 = 18014398509481983;

	switch (stage) {
		case 0: return true;
		case 1: return g0hash() == g1_in_g0;
		case 2: return g1hash() == g2_in_g1;
		case 3: return g2hash() == g3_in_g2;
		case 4: return g3hash() == g4_in_g3;
		default: throw std::invalid_argument("Illegal stage.");
	}
}