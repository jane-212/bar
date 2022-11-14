#ifndef _VERSION_H_
#define _VERSION_H_

#include <string>
#include <vector>
#include "file.h"

namespace bar {

class Version {
private:
  File file;
  std::vector<std::string> output;

public:
  Version();
  ~Version();
  std::string get();
};

} // namespace bar

#endif
