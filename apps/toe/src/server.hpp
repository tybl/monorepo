// License: The Unlicense (https://unlicense.org)
#pragma once
#ifndef TYBL_TICTACTOE_TOE_SERVER_HPP
#define TYBL_TICTACTOE_TOE_SERVER_HPP

#include <boost/asio/ip/udp.hpp>

class server {
  using socket = boost::asio::ip::udp::socket;
  using endpoint = boost::asio::ip::udp::endpoint;
  using io_context = boost::asio::io_context;

  socket m_socket;
  endpoint m_endpoint;
  static constexpr size_t MAX_LEN = 1024;
  std::array<char, MAX_LEN> m_data = {};
public:

  server(io_context& p_context, uint16_t p_port);

  void do_receive();

  void do_send(size_t p_len);

}; // class server
#endif // TYBL_TICTACTOE_TOE_SERVER_HPP
