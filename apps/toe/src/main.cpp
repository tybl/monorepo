#include "server.hpp"
#include "ttt/board.hpp"
#include "ttt/cell.hpp"
#include "ttt/get_best_move.hpp"

#include <exception>
#include <nlohmann/json.hpp>

#include <iostream>

auto determine_response(nlohmann::json const& p_request) -> nlohmann::json {
  auto board_value = p_request["board"].get<uint16_t>();
  auto brd = ttt::board::decode(ttt::cell::value::EX, board_value);
  brd.display();
  auto mov = ttt::get_best_move(brd, ttt::cell::value::EX);
  std::cout << board_value << std::endl;
  return p_request;
}

auto main() -> int {
  try {
    const std::string input = R"({ "board": 12345 })";
    determine_response(nlohmann::json::parse(input));

    boost::asio::io_context context;
    const uint16_t port_no = 1234;
    const server serve(context, port_no);
    context.run();
  } catch (std::exception& p_ex) {
    std::cerr << "Exception: " << p_ex.what() << "\n";
  }
}

// vim: ts=2 sts=2 sw=2 et
