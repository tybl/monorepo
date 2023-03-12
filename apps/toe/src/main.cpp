#include "ttt/cell.hpp"

#include "ttt/board.hpp"

//#include <boost/asio.hpp>
#include <boost/asio/ip/udp.hpp>
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

class server {
  using socket = boost::asio::ip::udp::socket;
  using endpoint = boost::asio::ip::udp::endpoint;
  using io_context = boost::asio::io_context;

  socket m_socket;
  endpoint m_endpoint;
  static constexpr size_t MAX_LEN = 1024;
  std::array<char, MAX_LEN> m_data = {};
public:

  server(io_context& p_context, uint16_t p_port)
    : m_socket(p_context, endpoint(boost::asio::ip::udp::v4(), p_port))
  {
    do_receive();
  }

  void do_receive() {
    m_socket.async_receive_from(boost::asio::buffer(m_data, MAX_LEN), m_endpoint,
                                [this](std::error_code p_ec, size_t p_num_bytes_rcvd) {
                                  if (!p_ec && p_num_bytes_rcvd > 0) {
                                    do_send(p_num_bytes_rcvd);
                                  } else {
                                    do_receive();
                                  }
                                });
  }

  void do_send(size_t p_len) {
    m_socket.async_send_to(boost::asio::buffer(m_data, p_len), m_endpoint,
                           [this](std::error_code /*ec*/, size_t /*num_bytes_rcvd*/) {
                             do_receive();
                           });
  }
}; // class server

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
