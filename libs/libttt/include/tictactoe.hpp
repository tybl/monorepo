#ifndef TYBL_TICTACTOE
#define TYBL_TICTACTOE

#include <cstdlib>

extern char mat[3][3], p1, p2;
void init();
void display();
auto input(char /*choice*/, int /*x*/, int /*y*/) -> int;
auto check() -> char;

#endif // TYBL_TICTACTOE
