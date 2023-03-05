#include "udp_socket.hpp"

#include <cstring>

#include <unistd.h>

#include <sys/socket.h>

udp_socket::udp_socket(std::string const& p_address, std::string const& p_service)
  : m_socket(find_server(p_address, p_service)) {}

udp_socket::~udp_socket() { ::close(m_socket); }

auto udp_socket::send(const void* p_msg, size_t p_len) -> ssize_t {
  return ::send(m_socket, p_msg, p_len, 0);
}

auto udp_socket::recv(void* p_buf, size_t p_len) -> ssize_t { return ::recv(m_socket, p_buf, p_len, 0); }
