#include "version.h"

namespace bar {

Version::Version() : file("/proc/version") {}

Version::~Version() {}

std::string Version::get() {
  output.clear();
  std::string version;
  size_t index;
  size_t start, end;

  output = this->file.get();
  if (1 != output.size()) {
    return "|  |";
  }

  version = output.at(0);

  index = version.find_first_of(' ');
  index = version.find_first_of(' ', index + 1);
  start = ++index;
  index = version.find_first_of(' ', index);
  end = index;

  return "|  " + version.substr(start, end - start) + " |";
}

} // namespace bar
