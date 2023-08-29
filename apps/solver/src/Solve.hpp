//
// Created by tybl on 1/5/23.
//

#ifndef SOLVE_SOLVE_HPP
#define SOLVE_SOLVE_HPP

#include <string>

class solve {
  bool m_had_error = false;

public:
  void error(int p_line, std::string const& p_message);

  void report(int p_line, std::string const& p_where, std::string const& p_message);

  void run_file(std::string const& p_path) const;

  void run_prompt();

private:
  static void run(std::string const& p_input);
};

#endif // SOLVE_SOLVE_HPP
