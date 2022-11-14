#ifndef _NET_H_
#define _NET_H_

#include <string>
#include <vector>
#include <stdlib.h>
#include "file.h"

namespace bar {

class Net {
private:
  File file;
  std::vector<std::string> output;
  long long bytes;
  long long get_bytes(std::string);
  std::string cut_point(double);

public:
  Net();
  ~Net();
  std::string get();
};

} // namespace bar

#endif
