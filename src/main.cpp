#include <iostream>
#include <unistd.h>
#include "cur_time.h"
#include "memory.h"
#include "net.h"
#include "version.h"
#include "bar.h"

#define INTERVAL 1

void set_root(std::string);

int main() {
  std::string b;
  bar::Version version;
  bar::Net net;
  bar::Memory memory;
  bar::CurTime curTime;
  bar::Bar bar;

  while (1) {
    b = "";
    b += version.get();
    b += net.get();
    b += memory.get();
    b += curTime.get();

    bar.set_root(b);
    sleep(INTERVAL);
  }

  return 0;
}

void set_root(std::string bar) {
  FILE *fp;
}

