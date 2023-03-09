#include "udp_socket.hpp"

#include <boost/asio.hpp>
#include <exception>
#include <nlohmann/json.hpp>

#include <iostream>

//  {
//    "request": "abcdef1234",
//    "player": "X",
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

class server {
  using socket = boost::asio::ip::udp::socket;
  using endpoint = boost::asio::ip::udp::endpoint;
  using io_context = boost::asio::io_context;

  socket m_socket;
  endpoint m_endpoint;
  static constexpr size_t MAX_LEN = 1024;
  std::array<char, MAX_LEN> m_data;
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
