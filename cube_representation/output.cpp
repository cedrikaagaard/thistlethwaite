#include "../cubelib.hpp"

using namespace cl;

void cl::cube::printc() {
	std::cout << "        |-------|" << std::endl
			  << "        | " << cside_to_a(getc("U1"))
			  << ' ' << cside_to_a(getc("U2"))
			  << ' ' << cside_to_a(getc("U3")) << " |" << std::endl

			  << "        | " << cside_to_a(getc("U4"))
			  << ' ' << cside_to_a(getc("U5"))
			  << ' ' << cside_to_a(getc("U6")) << " |" << std::endl

			  << "        | " << cside_to_a(getc("U7"))
			  << ' ' << cside_to_a(getc("U8"))
			  << ' ' << cside_to_a(getc("U9")) << " |" << std::endl

			  << "|-------|-------|-------|-------|" << std::endl

			  << "| " << cside_to_a(getc("L1"))
			  << ' ' << cside_to_a(getc("L2"))
			  << ' ' << cside_to_a(getc("L3")) << " "

			  << "| " << cside_to_a(getc("F1"))
			  << ' ' << cside_to_a(getc("F2"))
			  << ' ' << cside_to_a(getc("F3")) << " "

			  << "| " << cside_to_a(getc("R1"))
			  << ' ' << cside_to_a(getc("R2"))
			  << ' ' << cside_to_a(getc("R3")) << " "

			  << "| " << cside_to_a(getc("B1"))
			  << ' ' << cside_to_a(getc("B2"))
			  << ' ' << cside_to_a(getc("B3")) << " |" << std::endl

			  << "| " << cside_to_a(getc("L4"))
			  << ' ' << cside_to_a(getc("L5"))
			  << ' ' << cside_to_a(getc("L6")) << " "

			  << "| " << cside_to_a(getc("F4"))
			  << ' ' << cside_to_a(getc("F5"))
			  << ' ' << cside_to_a(getc("F6")) << " "

			  << "| " << cside_to_a(getc("R4"))
			  << ' ' << cside_to_a(getc("R5"))
			  << ' ' << cside_to_a(getc("R6")) << " "

			  << "| " << cside_to_a(getc("B4"))
			  << ' ' << cside_to_a(getc("B5"))
			  << ' ' << cside_to_a(getc("B6")) << " |" << std::endl

			  << "| " << cside_to_a(getc("L7"))
			  << ' ' << cside_to_a(getc("L8"))
			  << ' ' << cside_to_a(getc("L9")) << " "

			  << "| " << cside_to_a(getc("F7"))
			  << ' ' << cside_to_a(getc("F8"))
			  << ' ' << cside_to_a(getc("F9")) << " "

			  << "| " << cside_to_a(getc("R7"))
			  << ' ' << cside_to_a(getc("R8"))
			  << ' ' << cside_to_a(getc("R9")) << " "

			  << "| " << cside_to_a(getc("B7"))
			  << ' ' << cside_to_a(getc("B8"))
			  << ' ' << cside_to_a(getc("B9")) << " |" << std::endl

			  << "|-------|-------|-------|-------|" << std::endl

			  << "        | " << cside_to_a(getc("D1"))
			  << ' ' << cside_to_a(getc("D2"))
			  << ' ' << cside_to_a(getc("D3")) << " |" << std::endl

			  << "        | " << cside_to_a(getc("D4"))
			  << ' ' << cside_to_a(getc("D5"))
			  << ' ' << cside_to_a(getc("D6")) << " |" << std::endl

			  << "        | " << cside_to_a(getc("D7"))
			  << ' ' << cside_to_a(getc("D8"))
			  << ' ' << cside_to_a(getc("D9")) << " |" << std::endl
			  << "        |-------|" << std::endl;
}









void cl::cube::printa() {
	std::cout << "        |-------|" << std::endl
			  << "        | " << aside_to_a(geta("U1"))
			  << ' ' << aside_to_a(geta("U2"))
			  << ' ' << aside_to_a(geta("U3")) << " |" << std::endl

			  << "        | " << aside_to_a(geta("U4"))
			  << ' ' << aside_to_a(geta("U5"))
			  << ' ' << aside_to_a(geta("U6")) << " |" << std::endl

			  << "        | " << aside_to_a(geta("U7"))
			  << ' ' << aside_to_a(geta("U8"))
			  << ' ' << aside_to_a(geta("U9")) << " |" << std::endl

			  << "|-------|-------|-------|-------|" << std::endl

			  << "| " << aside_to_a(geta("L1"))
			  << ' ' << aside_to_a(geta("L2"))
			  << ' ' << aside_to_a(geta("L3")) << " "

			  << "| " << aside_to_a(geta("F1"))
			  << ' ' << aside_to_a(geta("F2"))
			  << ' ' << aside_to_a(geta("F3")) << " "

			  << "| " << aside_to_a(geta("R1"))
			  << ' ' << aside_to_a(geta("R2"))
			  << ' ' << aside_to_a(geta("R3")) << " "

			  << "| " << aside_to_a(geta("B1"))
			  << ' ' << aside_to_a(geta("B2"))
			  << ' ' << aside_to_a(geta("B3")) << " |" << std::endl

			  << "| " << aside_to_a(geta("L4"))
			  << ' ' << aside_to_a(geta("L5"))
			  << ' ' << aside_to_a(geta("L6")) << " "

			  << "| " << aside_to_a(geta("F4"))
			  << ' ' << aside_to_a(geta("F5"))
			  << ' ' << aside_to_a(geta("F6")) << " "

			  << "| " << aside_to_a(geta("R4"))
			  << ' ' << aside_to_a(geta("R5"))
			  << ' ' << aside_to_a(geta("R6")) << " "

			  << "| " << aside_to_a(geta("B4"))
			  << ' ' << aside_to_a(geta("B5"))
			  << ' ' << aside_to_a(geta("B6")) << " |" << std::endl

			  << "| " << aside_to_a(geta("L7"))
			  << ' ' << aside_to_a(geta("L8"))
			  << ' ' << aside_to_a(geta("L9")) << " "

			  << "| " << aside_to_a(geta("F7"))
			  << ' ' << aside_to_a(geta("F8"))
			  << ' ' << aside_to_a(geta("F9")) << " "

			  << "| " << aside_to_a(geta("R7"))
			  << ' ' << aside_to_a(geta("R8"))
			  << ' ' << aside_to_a(geta("R9")) << " "

			  << "| " << aside_to_a(geta("B7"))
			  << ' ' << aside_to_a(geta("B8"))
			  << ' ' << aside_to_a(geta("B9")) << " |" << std::endl

			  << "|-------|-------|-------|-------|" << std::endl

			  << "        | " << aside_to_a(geta("D1"))
			  << ' ' << aside_to_a(geta("D2"))
			  << ' ' << aside_to_a(geta("D3")) << " |" << std::endl

			  << "        | " << aside_to_a(geta("D4"))
			  << ' ' << aside_to_a(geta("D5"))
			  << ' ' << aside_to_a(geta("D6")) << " |" << std::endl

			  << "        | " << aside_to_a(geta("D7"))
			  << ' ' << aside_to_a(geta("D8"))
			  << ' ' << aside_to_a(geta("D9")) << " |" << std::endl
			  << "        |-------|" << std::endl;
}

void cl::cube::printaa() {
	std::cout << "        |-------|" << std::endl
			  << "        | " << aaside_to_a(getaa("U1"))
			  << ' ' << aaside_to_a(getaa("U2"))
			  << ' ' << aaside_to_a(getaa("U3")) << " |" << std::endl

			  << "        | " << aaside_to_a(getaa("U4"))
			  << ' ' << aaside_to_a(getaa("U5"))
			  << ' ' << aaside_to_a(getaa("U6")) << " |" << std::endl

			  << "        | " << aaside_to_a(getaa("U7"))
			  << ' ' << aaside_to_a(getaa("U8"))
			  << ' ' << aaside_to_a(getaa("U9")) << " |" << std::endl

			  << "|-------|-------|-------|-------|" << std::endl

			  << "| " << aaside_to_a(getaa("L1"))
			  << ' ' << aaside_to_a(getaa("L2"))
			  << ' ' << aaside_to_a(getaa("L3")) << " "

			  << "| " << aaside_to_a(getaa("F1"))
			  << ' ' << aaside_to_a(getaa("F2"))
			  << ' ' << aaside_to_a(getaa("F3")) << " "

			  << "| " << aaside_to_a(getaa("R1"))
			  << ' ' << aaside_to_a(getaa("R2"))
			  << ' ' << aaside_to_a(getaa("R3")) << " "

			  << "| " << aaside_to_a(getaa("B1"))
			  << ' ' << aaside_to_a(getaa("B2"))
			  << ' ' << aaside_to_a(getaa("B3")) << " |" << std::endl

			  << "| " << aaside_to_a(getaa("L4"))
			  << ' ' << aaside_to_a(getaa("L5"))
			  << ' ' << aaside_to_a(getaa("L6")) << " "

			  << "| " << aaside_to_a(getaa("F4"))
			  << ' ' << aaside_to_a(getaa("F5"))
			  << ' ' << aaside_to_a(getaa("F6")) << " "

			  << "| " << aaside_to_a(getaa("R4"))
			  << ' ' << aaside_to_a(getaa("R5"))
			  << ' ' << aaside_to_a(getaa("R6")) << " "

			  << "| " << aaside_to_a(getaa("B4"))
			  << ' ' << aaside_to_a(getaa("B5"))
			  << ' ' << aaside_to_a(getaa("B6")) << " |" << std::endl

			  << "| " << aaside_to_a(getaa("L7"))
			  << ' ' << aaside_to_a(getaa("L8"))
			  << ' ' << aaside_to_a(getaa("L9")) << " "

			  << "| " << aaside_to_a(getaa("F7"))
			  << ' ' << aaside_to_a(getaa("F8"))
			  << ' ' << aaside_to_a(getaa("F9")) << " "

			  << "| " << aaside_to_a(getaa("R7"))
			  << ' ' << aaside_to_a(getaa("R8"))
			  << ' ' << aaside_to_a(getaa("R9")) << " "

			  << "| " << aaside_to_a(getaa("B7"))
			  << ' ' << aaside_to_a(getaa("B8"))
			  << ' ' << aaside_to_a(getaa("B9")) << " |" << std::endl

			  << "|-------|-------|-------|-------|" << std::endl

			  << "        | " << aaside_to_a(getaa("D1"))
			  << ' ' << aaside_to_a(getaa("D2"))
			  << ' ' << aaside_to_a(getaa("D3")) << " |" << std::endl

			  << "        | " << aaside_to_a(getaa("D4"))
			  << ' ' << aaside_to_a(getaa("D5"))
			  << ' ' << aaside_to_a(getaa("D6")) << " |" << std::endl

			  << "        | " << aaside_to_a(getaa("D7"))
			  << ' ' << aaside_to_a(getaa("D8"))
			  << ' ' << aaside_to_a(getaa("D9")) << " |" << std::endl
			  << "        |-------|" << std::endl;
}