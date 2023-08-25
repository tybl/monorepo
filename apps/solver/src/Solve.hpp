//
// Created by tybl on 1/5/23.
//

#ifndef SOLVE_SOLVE_HPP
#define SOLVE_SOLVE_HPP

#include <string>

class Solve {
  bool m_had_error = false;

public:
  void error(int line, std::string const& message);

  void report(int line, std::string const& where, std::string const& message);

  void run_file(std::string const& path) const;

  void run_prompt();

private:
  static void run(std::string const& input);
};

#endif // SOLVE_SOLVE_HPP
