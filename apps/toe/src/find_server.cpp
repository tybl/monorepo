#include "find_server.hpp"

#include <fmt/core.h>

#include <unistd.h>

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

auto find_server(std::string const& p_address, std::string const& p_service) -> int {
  addrinfo hints{};
  hints.ai_family = AF_INET; // IPv4
  hints.ai_socktype = SOCK_DGRAM; // UDP
  hints.ai_flags = AI_PASSIVE;

  addrinfo* servinfo_p = nullptr;
  const int result = getaddrinfo(p_address.c_str(), p_service.c_str(), &hints, &servinfo_p);
  if (0 != result) {

    fmt::print(stderr, "getaddrinfo: %s\n", gai_strerror(result));
    abort();
  }

  // loop through all the results and connect to the first we can
  addrinfo* addr_p = nullptr;
  int sockfd = 0;
  for (addr_p = servinfo_p; addr_p != nullptr; addr_p = addr_p->ai_next) {

    sockfd = socket(addr_p->ai_family, addr_p->ai_socktype, addr_p->ai_protocol);

    if (-1 == sockfd) {
      perror("find_server: socket");
      continue;
    }

    break;
  }

  if (nullptr == addr_p) {
    fmt::print(stderr, "client: failed to connect\n");
    abort();
  }

  freeaddrinfo(servinfo_p); // all done with this structure
  return sockfd;
}
