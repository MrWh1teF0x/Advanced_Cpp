#ifndef LOG_HPP
#define LOG_HPP

#include <ctime>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <string>
#include <vector>

#define LOG_NORMAL 0
#define LOG_WARNING 1
#define LOG_ERROR 2

class Log {
 public:
  Log(const Log&) = delete;
  Log& operator=(const Log&) = delete;

  static Log* Instance() {
    if (!instance_) instance_ = new Log();
    return instance_;
  }

  void message(int level, const std::string& msg) {
    if (events_.size() >= 10) events_.erase(events_.begin());

    Event event{level, msg, GetCurrentTime()};
    events_.push_back(event);
  }

  void print() {
    for (const auto& event : events_) {
      std::cout << event.time << " [" << LevelToString(event.level) << "] "
                << event.message << '\n';
    }
  }

 private:
  Log() {}

  struct Event {
    int level;
    std::string message;
    std::string time;
  };

  std::vector<Event> events_;
  static Log* instance_;

  std::string GetCurrentTime() {
    std::time_t t = std::time(nullptr);
    std::tm tm;
    localtime_s(&tm, &t);

    char buf[20];
    std::strftime(buf, sizeof(buf), "%d-%m-%Y %H:%M:%S", &tm);
    return std::string(buf);
  }

  std::string LevelToString(int level) {
    switch (level) {
      case LOG_NORMAL:
        return "NORMAL";
      case LOG_WARNING:
        return "WARNING";
      case LOG_ERROR:
        return "ERROR";
      default:
        return "UNKNOWN";
    }
  }
};

Log* Log::instance_ = nullptr;

#endif  // LOG_HPP