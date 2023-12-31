// License: The Unlicense (https://unlicense.org)
#pragma once
#ifndef TYBL_STACKSOLVER_BOARD_HPP
#define TYBL_STACKSOLVER_BOARD_HPP

#include "edge.hpp"
#include "i_node.hpp"

#include <memory>
#include <set>
#include <string>
#include <vector>

struct Board;

struct shared_stats {
  shared_stats()
    : m_boards()
    , m_max_stack_height() {}

  std::set<Board> m_boards;
  size_t m_max_stack_height = 0;
}; // struct shared_stats

struct Board : public i_node {
  std::vector<std::string> m_contents;
  size_t m_priority = 0;
  std::shared_ptr<shared_stats> m_stats;
  size_t m_id;
  mutable Board const* m_parent;
  mutable size_t m_distance;

  explicit Board(std::istream& p_input);

  Board(Board const& p_other);

  auto operator=(Board p_other) -> Board&;

  Board(Board const& p_o, edge const& p_e);

  ~Board() override;

  [[gnu::pure]] auto is_solved() const -> bool override;

  auto generate_steps() const -> std::vector<edge> override;

  auto operator+(edge const& p_e) const -> i_node const* override;

  void print() const override;

  void print_steps() const override;

  [[gnu::pure]] auto priority() const -> size_t override;

  [[gnu::pure]] auto distance() const -> size_t override;

  [[gnu::pure]] auto operator<(Board const& p_o) const -> bool;

  [[gnu::pure]] auto num_found() const -> size_t override;

  void apply(edge const& p_e);
  [[gnu::pure]] static auto count_suffix_matching(std::string_view p_s, char p_c) -> size_t;
  [[gnu::pure]] auto calc_priority() const -> size_t;
  [[gnu::pure]] auto is_full(std::string_view p_s) const -> bool;
  [[gnu::pure]] auto is_full_and_homogeneous(std::string const& p_s) const -> bool;
  [[gnu::pure]] static auto is_homogeneous(std::string const& p_s) -> bool;
  auto is_valid(edge const& p_e) const -> bool;
};

#endif // TYBL_STACKSOLVER_BOARD_HPP
