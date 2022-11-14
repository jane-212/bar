#include "memory.h"

namespace bar {

Memory::Memory() : file("/proc/meminfo") {}

Memory::~Memory() {}

std::string Memory::get() {
  output.clear();
  size_t length;
  double totalMem, availableMem;

  output = this->file.get();
  length = output.size();
  if (length < 3) {
    return "  0.0Gb/0.0Gb |";
  }

  totalMem = this->get_bytes(output.at(0)) / (1024.0 * 1024.0);
  availableMem = this->get_bytes(output.at(2)) / (1024.0 * 1024.0);

  return "  " + this->cut_point(totalMem - availableMem) + "Gb/" + this->cut_point(totalMem) + "Gb |";
}

std::string Memory::cut_point(double speed) {
  std::string speed_str = std::to_string(speed);
  size_t index;

  index = speed_str.find_first_of('.');

  return speed_str.substr(0, index + 2);
}

long long Memory::get_bytes(std::string line) {
  size_t start, end, index;
  index = line.find_first_of(':');
  index = line.find_first_not_of(' ', index + 1);
  start = index;
  index = line.find_first_of(' ', index);
  end = index;

  return strtoll(line.substr(start, end - start).data(), NULL, 10);
}

} // namespace bar
