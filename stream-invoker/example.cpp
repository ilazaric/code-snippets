#include <vector>
#include <iostream>

#include "invoker.hpp"

int main() {

  std::vector<int> vec;
  ivl::StreamInvoker pusher{[&](int arg){vec.push_back(arg);}};
  pusher << 1 << 2 << 3;
  return vec.size();
  
}
