#include <iostream>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/write.hpp>
#include <Networking/Base.h>
#include <boost/asio.hpp>

int main() {

  using namespace boost::asio;
  using boost::asio::ip::tcp;
  using boost::asio::io_context;

  try {
    std::cout << "Accepting connections on port 1234...\n";
    io_context context;
    tcp::acceptor acceptor(context, tcp::endpoint(tcp::v4(), 1234));

    while(true) {
      tcp::socket socket(context);
      acceptor.accept(socket);

      std::cout << "Client connected! Sending message...\n";
      std::string msg = "Server is alive!\n";
      boost::system::error_code error;

      write(socket, buffer(msg), error);

    }

  } catch(std::exception &e) {
    std::cerr << e.what() << '\n';
  }
}
