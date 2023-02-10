#include "socket.hpp"

#include <cstring>
#include <string>

#include <unistd.h>

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

client_socket::client_socket(std::string const& address, std::string const& service)
  : m_socket(find_server(address, service)) {}

client_socket::~client_socket() { ::close(m_socket); }

auto client_socket::send(const void* msg, size_t len) -> ssize_t { return ::send(m_socket, msg, len, 0); }

auto client_socket::recv(void* buf, size_t len) -> ssize_t { return ::recv(m_socket, buf, len, 0); }

auto client_socket::find_server(std::string const& address, std::string const& service) -> int {
  addrinfo hints{};
  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  int rv = 0;
  addrinfo* servinfo = nullptr;
  if ((rv = getaddrinfo(address.c_str(), service.c_str(), &hints, &servinfo)) != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
    exit(-1);
  }

  // loop through all the results and connect to the first we can
  addrinfo* p = nullptr;
  int sockfd = 0;
  for (p = servinfo; p != NULL; p = p->ai_next) {
    if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
      perror("client: socket");
      continue;
    }

    if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
      close(sockfd);
      perror("client: connect");
      continue;
    }

    break;
  }

  if (p == NULL) {
    fprintf(stderr, "client: failed to connect\n");
    exit(-1);
  }

  freeaddrinfo(servinfo); // all done with this structure
  return sockfd;
}
