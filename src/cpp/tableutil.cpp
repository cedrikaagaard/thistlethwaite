#include <vector>
#include <string>
#include <boost/filesystem/operations.hpp>
#include "tableutil.hpp"

std::string rotvectoar(const std::vector<rotation> &rv) {
	std::string sb;

	for (int i = (int) rv.size() - 1; i >= 0; i--) {
		sb += rottoia(rv[i]);
	}

	return sb;
}

std::string rotvectoa(const std::vector<rotation> &rv) {
	std::string sb;

	for (int i = 0; i < rv.size(); i++) {


		sb += rottoa(rv[i]);
	}

	return sb;
}

std::string get_table_path(int g) {
	std::string home = getenv("HOME");
	std::string table_dir = "/.thistlethwaite";

	boost::filesystem::path full_path(home + table_dir);
	boost::filesystem::create_directory(full_path);

	return full_path.string() + "/g" + std::to_string(g) + ".dat";
}

std::vector<rotation> atorotvec(const std::string &s) {
	std::vector<rotation> res;

	for (auto &r : s) {
		res.emplace_back(atorot(r));
	}

	return res;
}