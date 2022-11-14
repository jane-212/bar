#include "bar.h"

namespace bar {

Bar::Bar() {
}

Bar::~Bar() {

}

void Bar::set_root(std::string bar) {
  std::string cmd = "xsetroot -name \"" + bar + "\"";
  fp = popen(cmd.data(), "r");
  if (fp == NULL) {
    return;
  }

  pclose(fp);
  fp = NULL;
}

}

