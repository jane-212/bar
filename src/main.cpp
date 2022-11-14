#include <iostream>
#include <unistd.h>
#include "cur_time.h"
#include "memory.h"
#include "net.h"
#include "version.h"

#define INTERVAL 1

void set_root(std::string);

int main() {
  std::string bar;
  bar::Version version;
  bar::Net net;
  bar::Memory memory;
  bar::CurTime curTime;

  while (1) {
    bar = "xsetroot -name \"";
    bar += version.get();
    bar += net.get();
    bar += memory.get();
    bar += curTime.get();
    bar += "\"";

    system(bar.data());
    sleep(INTERVAL);
  }

  return 0;
}

