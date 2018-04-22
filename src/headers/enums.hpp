#pragma once

enum side { up, right, front, down, left, back };
enum aside { up_down, right_left, front_back };
enum class side_segment { top, right, left, bottom };
enum class rotation { U, R, F, D, L, B, u, r, f, d, l, b };

/**
 * Converts an ascii representation of a side to a side object representation.
 * If the specified ascii representation is invalid an exception is thrown.
 * @param c the ascii representation of a side.
 * @return a side enum representation of the side.
 */
side atoside(const char &c);

/**
 * Converts an ascii repr of a rotation to a rotation object repr.
 * If the specified ascii representation is invalid an exception is thrown.
 * @param c the ascii representation of a rotation.
 * @return a rotation enum representation of the side.
 */
rotation atorot(const char &c);

/**
 * Converts a side enum repr of a side to an aside enum repr.
 * If the specified side enum representation is invalid an exception is thrown.
 * @param s the side enum representation of a side.
 * @return aside enum representation of the side.
 */
aside sidetoaside(const side &s);

/**
 * Converts a side enum repr of a side to a concrete ascrii repr.
 * This function is kind of ambiguous,
 * since the conversion is implementation defined.
 * @param c the side enum representation of a side.
 * @return a concrete ascii representation of the side.
 */
char sidetoreala(const side &s);

/**
 * Converts a rotation enum repr of a rotation to an ascii repr.
 * @param c the rotation enum representation of a rotation.
 * @return an ascii representation of the rotation.
 */
char rottoa(const rotation &r);

/**
 * Converts a rotation enum repr of a rotation to the inverse ascii repr.
 * @param c the rotation enum representation of a rotation.
 * @return an ascii representation of the inverse rotation.
 */
char rottoia(const rotation &r);