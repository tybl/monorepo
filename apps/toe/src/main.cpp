#include "server.hpp"
#include "ttt/board.hpp"
#include "ttt/cell.hpp"

#include <exception>
#include <nlohmann/json.hpp>

#include <iostream>
#include <optional>

//  {
//    "request": "abcdef1234",
//    "locations": [ {
//        "ip": "192.168.86.80",
//        "port": 5432
//      }
//    ],
//    "board": 12345 // decimal value of 9 digit base 3 number representing the board
//  }
//  {
//    "response": "abcdef1234",
//    "row": 0,
//    "col": 2,
//    "locations": [ {
//        "ip": "192.168.86.68",
//        "port": 5432
//      }
//    ]
//  }

auto search_optimal_move(ttt::board const& p_board, ttt::cell::value /*p_turn*/) -> std::optional<ttt::cell::position> {
  if (p_board.has_winner()) { return std::nullopt; }
  for (uint16_t row = 0; row < 3; ++row) {
    for (uint16_t col = 0; col < 3; ++col) {
    }
  }
  return std::nullopt;
}

auto determine_response(nlohmann::json const& p_request) -> nlohmann::json {
  auto board_value = p_request["board"].get<uint16_t>();
  auto brd = ttt::board::decode(ttt::cell::value::EX, board_value);
  brd.display();
  auto pos = search_optimal_move(brd, ttt::cell::value::EX);
  std::cout << board_value << std::endl;
  return p_request;
}

auto main() -> int {
  // Get port no from argv
  // Player value is only needed for human interaction...
  // Create server and listen for connections
  const std::string input = R"({ "board": 12345 })";
  determine_response(nlohmann::json::parse(input));

  try {
    boost::asio::io_context context;
    const uint16_t port_no = 1234;
    server serve(context, port_no);
    context.run();
    } catch (std::exception& p_ex) {
      std::cerr << "Exception: " << p_ex.what() << "\n";
    }


  // Open socket, listen for game requests
  // switch (request)
  //  - Game
  //      Respond w/ game_id, 
  //  - Move
}

// vim: ts=2 sts=2 sw=2 et
