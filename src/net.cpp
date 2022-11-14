#include "net.h"

namespace bar {

Net::Net() : file("/proc/net/dev"), bytes(0) {}

Net::~Net() {}

std::string Net::get() {
  output.clear();
  size_t length;
  int i;
  long long total;
  double diff;

  output = this->file.get();
  length = output.size();
  if (length <= 2) {
    return "  0Kb/s |";
  }

  total = 0;
  for (i = 2; i < (int)length; i++) {
    total += this->get_bytes(output.at(i));
  }

  diff = (total - this->bytes) / 1024.0;

  this->bytes = total;

  if (diff < 1024) {
    return "  " + this->cut_point(diff) + "Kb/s |";
  } else {
    return "  " + this->cut_point(diff / 1024) + "Mb/s |";
  }
}

std::string Net::cut_point(double speed) {
  std::string speed_str = std::to_string(speed);
  size_t index;

  index = speed_str.find_first_of('.');

  return speed_str.substr(0, index + 2);
}

long long Net::get_bytes(std::string line) {
  size_t start, end, index;
  index = line.find_first_of(':');
  index = line.find_first_not_of(' ', index + 1);
  start = index;
  index = line.find_first_of(' ', index);
  end = index;

  return strtoll(line.substr(start, end - start).data(), NULL, 10);
}

} // namespace bar
