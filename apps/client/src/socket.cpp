#include "socket.hpp"

#include <cstring>
#include <string>

#include <unistd.h>

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

client_socket::client_socket(std::string const& p_address, std::string const& p_service)
  : m_socket(find_server(p_address, p_service)) {}

client_socket::~client_socket() { ::close(m_socket); }

auto client_socket::send(const void* p_msg, size_t p_len) -> ssize_t { return ::send(m_socket, p_msg, p_len, 0); }

auto client_socket::recv(void* p_buf, size_t p_len) -> ssize_t { return ::recv(m_socket, p_buf, p_len, 0); }

auto client_socket::find_server(std::string const& p_address, std::string const& p_service) -> int {
  addrinfo hints{};
  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  addrinfo* servinfo_p = nullptr;
  const int result = getaddrinfo(p_address.c_str(), p_service.c_str(), &hints, &servinfo_p);
  if (0 != result) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(result));
    exit(-1);
  }

  // loop through all the results and connect to the first we can
  addrinfo* p = nullptr;
  int sockfd = 0;
  for (p = servinfo_p; p != nullptr; p = p->ai_next) {
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

  if (p == nullptr) {
    fprintf(stderr, "client: failed to connect\n");
    exit(-1);
  }

  freeaddrinfo(servinfo_p); // all done with this structure
  return sockfd;
}
