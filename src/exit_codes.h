// exit_codes.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: define numeric exit codes (e.g. success=0)
// Dependencies: None
// Changes: Initial version created for smart home automation project

#ifndef EXIT_CODES_H
#define EXIT_CODES_H

constexpr int success = 0;
constexpr int generic_error = 1;
constexpr int user_error = 2;
constexpr int runtime_error = 3;
constexpr int unknown_error = 10;

#endif
