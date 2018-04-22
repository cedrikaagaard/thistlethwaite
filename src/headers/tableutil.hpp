#pragma once

#include <vector>
#include "enums.hpp"

/**
 * Converts a vector of rotation enums to its inverse string representation.
 * @param rv a vector of rotation enums to be converted.
 * @return the inverse string representation.
 */
std::string rotvectoar(const std::vector<rotation> &rv);

/**
 * Converts a vector of rotation enum to it string representation.
 * @param rv a vector of rotation enums to be converted.
 * @return the string representation.
 */
std::string rotvectoa(const std::vector<rotation> &rv);

/**
 * Returns the full path to the specified subgroups table file.
 * @param g a subgroup.
 * @return A full path to a .dat file.
 */
std::string get_table_path(int g);

/**
 * Converts a string representing rotations to its vector representation.
 * If an invalid rotation is passed an exception is thrown.
 * @param s a string representing rotations.
 * @return the vector representation.
 */
std::vector<rotation> atorotvec(const std::string &s);