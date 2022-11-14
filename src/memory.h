#ifndef _MEMORY_H_
#define _MEMORY_H_

#include <string>
#include <vector>
#include <stdlib.h>
#include "file.h"

namespace bar {

class Memory {
private:
  File file;
  std::vector<std::string> output;
  long long get_bytes(std::string);
  std::string cut_point(double);

public:
  Memory();
  ~Memory();
  std::string get();
};

} // namespace bar

#endif
