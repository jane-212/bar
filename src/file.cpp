#include "file.h"

namespace bar {

File::File(std::string file) { this->file = file; }

File::~File() {}

std::vector<std::string> File::get() {
  output.clear();
  line.clear();

  fp = fopen(file.data(), "r");
  if (NULL == fp) {
    return output;
  }

  while ((c = fgetc(fp)) != EOF) {
    if ('\n' == c) {
      output.emplace_back(line);
      line.clear();
      continue;
    }

    line += c;
  }

  fclose(fp);
  fp = NULL;

  return output;
}

} // namespace bar
