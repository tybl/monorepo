#include <string>

class client_socket {
  int m_socket;

public:
  client_socket(std::string const& address, std::string const& service);

  ~client_socket();

  auto send(const void* msg, size_t len) -> ssize_t;

  auto recv(void* buf, size_t len) -> ssize_t;

private:
  static auto find_server(std::string const& address, std::string const& service) -> int;
};
