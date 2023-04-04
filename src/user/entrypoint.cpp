#include "../include.h"

namespace user {

};

/**
 * Handle configurations: 
 * 1. service database RPC endpoints/addresses
 * 2. coordination settings for testing
*/
int main(int argc, char* argv[]) {
  int r = 0;
  string db_address = "127.0.1.1:8090";  // target address & port to send grpc requests to.

  DatabaseRPCWrapperCall* c = new DatabaseRPCWrapperCall(grpc::CreateChannel(db_address, grpc::InsecureChannelCredentials()));


  c->set("1", "1");

  string message = c->get("1");

  std::cout << message << std::endl;

  return r;
}
