#include <string>

class udp_socket {
  int m_socket;

public:
  udp_socket(std::string const& p_address, std::string const& p_service);
  udp_socket(udp_socket&&) = delete;
  udp_socket(udp_socket const&) = delete;
  ~udp_socket();
  auto operator=(udp_socket &&) -> udp_socket& = delete;
  auto operator=(udp_socket const&) -> udp_socket& = delete;

  auto send(const void* p_msg, size_t p_len) -> ssize_t;

  auto recv(void* p_buf, size_t p_len) -> ssize_t;

private:
  static auto find_server(std::string const& p_address, std::string const& p_service) -> int;
};

auto main() -> int {
  // Open socket, listen for game requests
  // switch (request)
  //  - Game
  //      Respond w/ game_id, 
  //  - Move
}

#include <cstring>
#include <string>

#include <unistd.h>

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

udp_socket::udp_socket(std::string const& p_address, std::string const& p_service)
  : m_socket(find_server(p_address, p_service)) {}

udp_socket::~udp_socket() { ::close(m_socket); }

auto udp_socket::send(const void* p_msg, size_t p_len) -> ssize_t {
  return ::send(m_socket, p_msg, p_len, 0);
}

auto udp_socket::recv(void* p_buf, size_t p_len) -> ssize_t { return ::recv(m_socket, p_buf, p_len, 0); }

auto udp_socket::find_server(std::string const& p_address, std::string const& p_service) -> int {
  addrinfo hints{};
  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  addrinfo* servinfo_p = nullptr;
  const int result = getaddrinfo(p_address.c_str(), p_service.c_str(), &hints, &servinfo_p);
  if (0 != result) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(result));
    abort();
  }

  // loop through all the results and connect to the first we can
  addrinfo* addr_p = nullptr;
  int sockfd = 0;
  for (addr_p = servinfo_p; addr_p != nullptr; addr_p = addr_p->ai_next) {
    if ((sockfd = socket(addr_p->ai_family, addr_p->ai_socktype, addr_p->ai_protocol)) == -1) {
      perror("client: socket");
      continue;
    }

    if (connect(sockfd, addr_p->ai_addr, addr_p->ai_addrlen) == -1) {
      close(sockfd);
      perror("client: connect");
      continue;
    }

    break;
  }

  if (addr_p == nullptr) {
    fprintf(stderr, "client: failed to connect\n");
    abort();
  }

  freeaddrinfo(servinfo_p); // all done with this structure
  return sockfd;
}

// vim: ts=2 sts=2 sw=2 et
