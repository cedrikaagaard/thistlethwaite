#include <boost/multiprecision/integer.hpp>
#include "abstrcube.hpp"

using boost::multiprecision::uint128_t;

bool abstrcube::isg(const short &g) {
	switch (g) {
		case 0:
			return true;
		case 1:
			return g0() == 4095;
		case 2:
			return g1() == 168471210;
		case 3:
			return g2() == uint128_t("1298074214633706835075032330539553");
		case 4:
			return g3() == 18014398509481983;
		default:
			std::stringstream errss;
			errss << "There exist no group " << g
				  << " in Thistlethwaite's algorithm.";
			throw std::invalid_argument(errss.str());
	}
}