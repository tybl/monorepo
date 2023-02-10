#include "game_connector.hpp"

#include <unistd.h>

class network_connector : public game_connector {
  int m_socket;

public:
  ~network_connector() override { close(m_socket); }

  void sendto(std::string const&) override {
    // ssize_t retval = sendto(m_socket, const void buf[.len], size_t len, int flags, const struct sockaddr *dest_addr,
    // socklen_t addrlen); if (-1 == retval) { perror("Error: Call to sendto() failed");
    // }
  }

  std::string recvfrom() override {
    // int recvfrom(m_socket, void *buf, int len, unsigned int flags, struct sockaddr *from, int *fromlen);
    return 0;
  }
};
