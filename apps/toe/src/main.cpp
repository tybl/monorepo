#include "udp_socket.hpp"

#include <nlohmann/json.hpp>

//  {
//    "request": "abcdef1234",
//    "player": "X",
//    "board": [
//      [
//        " ",
//        " ",
//        " "
//      ], [
//        " ",
//        "O",
//        " "
//      ], [
//        "X",
//        " ",
//        "O"
//      ]
//    ]
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
