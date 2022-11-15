#include "memory.h"

namespace bar {

Memory::Memory() : file("/proc/meminfo") {}

Memory::~Memory() {}

std::string Memory::get() {
  output.clear();
  size_t length;
  double totalMem, availableMem;

  output = file.get();
  length = output.size();
  if (length < 3) {
    return "  0.0Gb/0.0Gb |";
  }

  totalMem = get_bytes(output.at(0)) / (1024.0 * 1024.0);
  availableMem = get_bytes(output.at(2)) / (1024.0 * 1024.0);

  return "  " + cut_point(totalMem - availableMem) + "Gb/" + cut_point(totalMem) + "Gb |";
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
