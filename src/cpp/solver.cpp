#include <unordered_map>
#include <boost/multiprecision/integer.hpp>
#include <fstream>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include "solver.hpp"
#include "enums.hpp"
#include "tableutil.hpp"
#include "abstrcube.hpp"

using boost::multiprecision::uint128_t;
typedef std::vector<rotation> rot_vector;

// Cache tables.
std::unordered_map<uint16_t, rot_vector> g0c;
std::unordered_map<uint32_t, rot_vector> g1c;
std::unordered_map<uint128_t, rot_vector> g2c;
std::unordered_map<uint64_t , rot_vector> g3c;

template <typename T>
T hstoi(const std::string &s);

template<> uint16_t hstoi<uint16_t>(const std::string &s) {
	return (uint16_t) std::stoi(s);
}

template<> uint32_t hstoi<uint32_t >(const std::string &s) {
	return (uint32_t) std::stoi(s);
}

template<> uint64_t hstoi<uint64_t >(const std::string &s) {
	return (uint64_t) std::stoull(s);
}

template<> uint128_t hstoi<uint128_t>(const std::string &s) {
	return uint128_t(s);
}

template <typename T>
void init_table(std::string fp, std::unordered_map<T, rot_vector> &cache) {
	std::ifstream table(fp);

	if (!table.is_open()) {
		std::stringstream errss;
		errss << "Table: " << fp << " could not be found. "
			  << "Note that tables need to be generated.";
		throw std::runtime_error(errss.str());
	}

	std::string line;
	while (std::getline(table, line)) {
		std::vector<std::string> res;
		boost::split(res, line, boost::is_any_of(" "));
		T hash = hstoi<T>(res[0]);
		rot_vector rotations = atorotvec(res[1]);

		cache[hash] = rotations;
	}
}

rotation get_counter(const rotation &r) {
	if ((int) r >= 6) return (rotation) ((int) r - 6);
	else return (rotation) ((int) r + 6);
}

// Removes cycle of rotations i.e. 4 of the same rotation in a row.
bool remove_cycle_rotvector(rot_vector &rv) {
	rot_vector::iterator it = rv.begin();
	bool changed = false;

	while (it < rv.end() - 3) {

		if (*it == *std::next(it, 1)
			&& *it == *std::next(it, 2)
			&& *it == *std::next(it, 3)) {
			changed = true;
			for (int i = 0; i < 4; i++) {
				it = rv.erase(it);
			}
		}

		else {
			it++;
		}
	}

	return changed;
}

// Replaces 3 of the same rotation in a row with its counter.
bool replace_tripe(rot_vector &rv) {
	rot_vector::iterator it = rv.begin();
	bool changed = false;

	while (it < rv.end() - 2) {
		if (*it == *std::next(it, 1) && *it == *std::next(it, 2)) {
			rotation replacement = get_counter(*it);
			changed = true;

			for (int i = 0; i < 3; i++) {
				it = rv.erase(it);
			}

			it = rv.insert(it, replacement);
		}

		else {
			it++;
		}
	}

	return changed;
}

// Removes rotations that are directly followed by its counter.
bool remove_inverses(rot_vector &rv) {
	rot_vector::iterator it = rv.begin();
	bool changed = false;

	while (it < rv.end() - 1) {
		if (get_counter(*it) == *std::next(it, 1)) {
			it = rv.erase(it);
			it = rv.erase(it);

			changed = true;
		}

		else {
			it++;
		}
	}

	return changed;
}

// Compresses a rotation vector by removing unecessary rotations.
void compress_rotvecor(rot_vector &rv) {
	if (rv.empty()) return;
	while (remove_cycle_rotvector(rv) || replace_tripe(rv) || remove_inverses(rv)) {}
}

void throw_unsolvable_cube() {
	throw std::invalid_argument("Unsolvable cube passed to solve function.");
}

// To improve speed of the solve function, the lookup tables
// are loaded into memory before usage.
void thistlethwaite::init_tables() {
	init_table(get_table_path(0), g0c);
	init_table(get_table_path(1), g1c);
	init_table(get_table_path(2), g2c);
	init_table(get_table_path(3), g3c);
}

void thistlethwaite::deallocate_tables() {
	g0c.clear();
	g1c.clear();
	g2c.clear();
	g3c.clear();
}

std::string thistlethwaite::solve(const cube &c) {
	// The sizes of the table should be like this.
	// If the id functions are changed/Optimized, these values will change.
	if (g0c.size() != 2048
		|| g1c.size() != 1082565
		|| g2c.size() != 2822400
		|| g3c.size() != 663552)
	{
		throw std::runtime_error(
				"Tables must be initialized before executing solve algorithm."
		);
	}

	rot_vector res;
	abstrcube abstrc(c);

	// g0 -> g1
	uint16_t g0id = abstrc.g0();
	if (g0c.find(g0id) == g0c.end()) throw_unsolvable_cube();

	rot_vector g0tog1 = g0c[g0id];
	abstrc.rotate(g0tog1);
	if (!abstrc.isg(1)) throw_unsolvable_cube();

	// g1 -> g2
	uint32_t g1id = abstrc.g1();
	if (g1c.find(g1id) == g1c.end()) throw_unsolvable_cube();

	rot_vector g1tog2 = g1c[g1id];
	abstrc.rotate(g1tog2);
	if (!abstrc.isg(2)) throw_unsolvable_cube();

	// g2 -> g3
	uint128_t g2id = abstrc.g2();
	if (g2c.find(g2id) == g2c.end()) throw_unsolvable_cube();

	rot_vector g2tog3 = g2c[g2id];
	abstrc.rotate(g2tog3);
	if (!abstrc.isg(3)) throw_unsolvable_cube();

	// g3 -> g4
	uint64_t g3id = abstrc.g3();
	if (g3c.find(g3id) == g3c.end()) throw_unsolvable_cube();

	rot_vector g3tog4 = g3c[g3id];
	abstrc.rotate(g3tog4);
	if (!abstrc.isg(4)) throw_unsolvable_cube();

	res.insert(res.end(), g0tog1.begin(), g0tog1.end());
	res.insert(res.end(), g1tog2.begin(), g1tog2.end());
	res.insert(res.end(), g2tog3.begin(), g2tog3.end());
	res.insert(res.end(), g3tog4.begin(), g3tog4.end());

	compress_rotvecor(res);
	return rotvectoa(res);
}

std::string thistlethwaite::solve(const std::string &s) {
	return solve(cube(s));
}