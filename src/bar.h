#ifndef _BAR_H_
#define _BAR_H_

#include <string>

namespace bar {

class Bar {
private:
  FILE *fp;

public:
  Bar();
  ~Bar();
  void set_root(std::string);
};

}

#endif
