#include "cur_time.h"

namespace bar {

CurTime::CurTime() {}

CurTime::~CurTime() {}

std::string CurTime::get() {
  now = time(NULL);

  lt = localtime(&now);

  return format();
}

std::string CurTime::format() {
  t = "  ";

  t += std::to_string(lt->tm_year + 1900);
  t += '-';
  if (lt->tm_mon < 9) {
    t += '0';
  }
  t += std::to_string(lt->tm_mon + 1);
  t += '-';
  if (lt->tm_mday < 10) {
    t += '0';
  }
  t += std::to_string(lt->tm_mday);
  t += " |  ";
  if (lt->tm_hour < 10) {
    t += '0';
  }
  t += std::to_string(lt->tm_hour);
  t += ':';
  if (lt->tm_min < 10) {
    t += '0';
  }
  t += std::to_string(lt->tm_min);
  t += ':';
  if (lt->tm_sec < 10) {
    t += '0';
  }
  t += std::to_string(lt->tm_sec);
  t += ' ';

  return t;
}

} // namespace bar
