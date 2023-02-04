#include "tictactoe.hpp"

#include <iostream>

char mat[3][3], p1, p2;

void init() {
  int i = 0;
  int j = 0;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      mat[i][j] = '-';
    }
  }
}

void display() {

  int i = 0;
  int j = 0;
  system("clear");
  std::cout << "\nWelcome to the Tic-Tac-Toe Game!\n\nGrid Co-ordinates : " << std::endl << std::endl;

  for (i = 0; i < 3; i++) {
    std::cout << "\t";
    for (j = 0; j < 3; j++) {
      std::cout << i << " " << j << "    ";
    }
    std::cout << std::endl;
  }

  std::cout << "\nThe Tic-Tac-Toe board : " << std::endl << std::endl;
  for (i = 0; i < 3; i++) {
    std::cout << "\t";
    for (j = 0; j < 3; j++) {
      std::cout << " " << mat[i][j] << "     ";
    }
    std::cout << std::endl;
  }
}

auto input(char p_choice, int p_x, int p_y) -> int {
  if (p_x >= 0 && p_x <= 2 && p_y >= 0 && p_y <= 2) {
    if (mat[p_x][p_y] == '-') {
      mat[p_x][p_y] = p_choice;
      return 0;
    }
    std::cout << std::endl
              << "Co-ordinates " << p_x << " " << p_y << " are already used!" << std::endl
              << "Press ENTER to continue..." << std::endl;
    do {
    } while (std::cin.get() != '\n');
    return 1;

  } else {
    std::cout << "\nInvalid Co-ordinates!" << std::endl << "Press ENTER to continue..." << std::endl;
    do {
    } while (std::cin.get() != '\n');
    return 1;
  }
}

auto check() -> char {
  int i = 0;
  int j = 0;
  char temp = 0;

  for (j = 0; j < 3; j++) {
    if (mat[0][j] != '-') {
      temp = mat[0][j];
      if (j == 0) {
        if (mat[0][1] == temp) {
          if (mat[0][2] == temp) {
            return temp;
          }
        }
        if (mat[1][0] == temp) {
          if (mat[2][0] == temp) {
            return temp;
          }
        }
        if (mat[1][1] == temp) {
          if (mat[2][2] == temp) {
            return temp;
          }
        }
      } else if (j == 1) {
        if (mat[1][1] == temp) {
          if (mat[2][1] == temp) {
            return temp;
          }
        }
      } else {
        if (mat[1][2] == temp) {
          if (mat[2][2] == temp) {
            return temp;
          }
        }
      }
    }
  }
  for (i = 1; i < 3; i++) {
    if (mat[i][0] != '-') {
      temp = mat[i][0];
      if (i == 1) {
        if (mat[1][1] == temp) {
          if (mat[1][2] == temp) {
            return temp;
          }
        }
      } else {
        if (mat[2][1] == temp) {
          if (mat[2][2] == temp) {
            return temp;
          }
        }
        if (mat[1][1] == temp) {
          if (mat[0][2] == temp) {
            return temp;
          }
        }
      }
    }
  }

  return 'f';
}
