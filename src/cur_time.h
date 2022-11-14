#ifndef _CUR_TIME_H_
#define _CUR_TIME_H_

#include <string>
#include <ctime>

namespace bar {

class CurTime {
private:
  time_t now;
  tm *lt;
  std::string t;
  std::string format();

public:
  CurTime();
  ~CurTime();
  std::string get();
};

} // namespace bar

#endif
