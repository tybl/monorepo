#include <string>

class client_socket {
  int m_socket;

public:
  client_socket(std::string const& p_address, std::string const& p_service);

  ~client_socket();

  auto send(const void* p_msg, size_t p_len) -> ssize_t;

  auto recv(void* p_buf, size_t p_len) -> ssize_t;

private:
  static auto find_server(std::string const& p_address, std::string const& p_service) -> int;
};
