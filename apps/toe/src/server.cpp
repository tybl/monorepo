#include "server.hpp"

server::server(io_context& p_context, uint16_t p_port)
  : m_socket(p_context, endpoint(boost::asio::ip::udp::v4(), p_port)) {
  do_receive();
}

void server::do_receive() {
  m_socket.async_receive_from(boost::asio::buffer(m_data, MAX_LEN), m_endpoint,
                              [this](std::error_code p_ec, size_t p_num_bytes_rcvd) {
                                if (!p_ec && p_num_bytes_rcvd > 0) {
                                  do_send(p_num_bytes_rcvd);
                                } else {
                                  do_receive();
                                }
                              });
}

void server::do_send(size_t p_len) {
  m_socket.async_send_to(boost::asio::buffer(m_data, p_len), m_endpoint,
                         [this](std::error_code /*ec*/, size_t /*num_bytes_rcvd*/) { do_receive(); });
}
