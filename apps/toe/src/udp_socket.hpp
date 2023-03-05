// License: The Unlicense (https://unlicense.org)
#pragma once
#ifndef TYBL_TICTACTOE_UDPSOCKET_HPP
#define TYBL_TICTACTOE_UDPSOCKET_HPP

#include <string>

class udp_socket {
  int m_socket;

public:
  udp_socket(std::string const& p_address, std::string const& p_service);
  udp_socket(udp_socket&&) = delete;
  udp_socket(udp_socket const&) = delete;
  ~udp_socket();
  auto operator=(udp_socket &&) -> udp_socket& = delete;
  auto operator=(udp_socket const&) -> udp_socket& = delete;

  auto send(const void* p_msg, size_t p_len) -> ssize_t;

  auto recv(void* p_buf, size_t p_len) -> ssize_t;

private:
  static auto find_server(std::string const& p_address, std::string const& p_service) -> int;
};

#endif // TYBL_TICTACTOE_GAME_HPP
