#ifndef _CMD_H_
#define _CMD_H_

#include <string>
#include <vector>

namespace bar {

class File {
private:
  std::string file;
  FILE *fp;
  std::vector<std::string> output;
  std::string line;
  char c;

public:
  File(std::string);
  ~File();
  std::vector<std::string> get();
};

} // namespace bar

#endif
