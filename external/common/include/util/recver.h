#ifndef RECVER_H_
#define RECVER_H_

#include <zmq.hpp>
#include <unistd.h>
#include <string>
#include <memory>
#include "struct/exchange_info.h"
#include "struct/market_snapshot.h"
#include "define.h"
#include "struct/order.h"

using namespace std;

class Recver {
 public:
  Recver(const std::string& name, const std::string& mode = "ipc", const std::string& bc = "connect");

  ~Recver();

  template <typename T>
  inline void Recv(T& t) {
    sock.get()->recv(&t, sizeof(T));
  }

 private:
  unique_ptr<zmq::context_t> con;
  unique_ptr<zmq::socket_t> sock;
};

#endif  //  RECVER_H_
