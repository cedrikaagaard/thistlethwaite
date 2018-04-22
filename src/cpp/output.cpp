#include <iostream>
#include "cube.hpp"

void thistlethwaite::cube::print() {
	std::cout << "        |-------|" << std::endl
			  << "        | " << get("U1")
			  << ' ' << get("U2")
			  << ' ' << get("U3") << " |" << std::endl

			  << "        | " << get("U4")
			  << ' ' << get("U5")
			  << ' ' << get("U6") << " |" << std::endl

			  << "        | " << get("U7")
			  << ' ' << get("U8")
			  << ' ' << get("U9") << " |" << std::endl

			  << "|-------|-------|-------|-------|" << std::endl

			  << "| " << get("L1")
			  << ' ' << get("L2")
			  << ' ' << get("L3") << " "

			  << "| " << get("F1")
			  << ' ' << get("F2")
			  << ' ' << get("F3") << " "

			  << "| " << get("R1")
			  << ' ' << get("R2")
			  << ' ' << get("R3") << " "

			  << "| " << get("B1")
			  << ' ' << get("B2")
			  << ' ' << get("B3") << " |" << std::endl

			  << "| " << get("L4")
			  << ' ' << get("L5")
			  << ' ' << get("L6") << " "

			  << "| " << get("F4")
			  << ' ' << get("F5")
			  << ' ' << get("F6") << " "

			  << "| " << get("R4")
			  << ' ' << get("R5")
			  << ' ' << get("R6") << " "

			  << "| " << get("B4")
			  << ' ' << get("B5")
			  << ' ' << get("B6") << " |" << std::endl

			  << "| " << get("L7")
			  << ' ' << get("L8")
			  << ' ' << get("L9") << " "

			  << "| " << get("F7")
			  << ' ' << get("F8")
			  << ' ' << get("F9") << " "

			  << "| " << get("R7")
			  << ' ' << get("R8")
			  << ' ' << get("R9") << " "

			  << "| " << get("B7")
			  << ' ' << get("B8")
			  << ' ' << get("B9") << " |" << std::endl

			  << "|-------|-------|-------|-------|" << std::endl

			  << "        | " << get("D1")
			  << ' ' << get("D2")
			  << ' ' << get("D3") << " |" << std::endl

			  << "        | " << get("D4")
			  << ' ' << get("D5")
			  << ' ' << get("D6") << " |" << std::endl

			  << "        | " << get("D7")
			  << ' ' << get("D8")
			  << ' ' << get("D9") << " |" << std::endl
			  << "        |-------|" << std::endl;
}