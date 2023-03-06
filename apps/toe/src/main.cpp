#include "udp_socket.hpp"

#include <nlohmann/json.hpp>

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

auto main() -> int {
  // Open socket, listen for game requests
  // switch (request)
  //  - Game
  //      Respond w/ game_id, 
  //  - Move
}

// vim: ts=2 sts=2 sw=2 et
