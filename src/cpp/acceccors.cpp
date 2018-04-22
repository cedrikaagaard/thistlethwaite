#include "cube.hpp"
#include "abstrcube.hpp"

struct repr_coord {
	side as;
	int row;
	int col;

	/**
	 * Parses the string repr of the cube accessor. format <SN> ex: <U5>.
	 * An exception will be thrown if it fails.
	 */
	repr_coord(const std::string &s) {
		try {
			if (s.length() > 2)
				throw std::exception();

			as = atoside(s[0]);
			int index = s[1] - '1';

			if (index < 0 || index > 8)
				throw std::exception();

			row = index / 3;
			col = index % 3;
		}

		catch (const std::exception &e) {
			std::stringstream errss;
			errss << "Invalid cube accessor \"" << s << "\".";
			throw std::invalid_argument(errss.str());
		}
	}
};

char thistlethwaite::cube::get(const std::string &s) {
	repr_coord rc(s);
	return repr[rc.as][rc.row][rc.col];
}

char thistlethwaite::cube::get(int s, int r, int c) {
	// Range check.
	if (s < 0 || r < 0 || c < 0 || s > 5 || r > 2 || c > 2) {
		std::stringstream errss;
		errss << "Invalid cube accessor "
		   << "[" << s << "][" << r << "]["<< c << "].";
		throw std::invalid_argument(errss.str());
	}

	return repr[s][r][c];
}

side abstrcube::get(const std::string &s) {
	repr_coord rc(s);
	return repr[rc.as][rc.row][rc.col];
}

aside abstrcube::aget(const std::string &s) {
	repr_coord rc(s);
	return arepr[rc.as][rc.row][rc.col];
}