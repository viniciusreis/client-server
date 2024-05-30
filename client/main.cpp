#include "boost/asio/connect.hpp"
#include "boost/asio/error.hpp"
#include <array>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio.hpp>
#include <exception>
#include <iostream>

int main() {

  using namespace boost::asio;
  using boost::asio::io_context;
  using boost::asio::ip::tcp;

  try {
    std::cout << "Connecting to local host...\n";
    io_context context;
    tcp::resolver resolver(context);
    tcp::resolver::results_type endpoints = resolver.resolve("127.0.0.1", "1234");

    tcp::socket socket(context);
    connect(socket, endpoints);

      std::cout << "Connected to server! Receiving message...\n";
    while(true) {
      std::array<char, 128> buf;
      boost::system::error_code error;
      size_t len = socket.read_some(buffer(buf), error);

      if (error == error::eof) {
        break;
      } else if (error) {
        throw boost::system::system_error(error);
      }

      std::cout.write(buf.data(), len);
    }

  } catch(std::exception &e) {
    std::cerr << e.what() << '\n';
  }

}
