#include <chrono>
#include <thread>

#include "src/log.hpp"

int main(void) {
  Log* log = Log::Instance();

  log->message(LOG_NORMAL, "Program loaded!");
  log->message(LOG_WARNING, "This is a warning");
  log->message(LOG_ERROR, "Error happens! Help me!");
  std::this_thread::sleep_for(std::chrono::seconds(2));

  log->message(LOG_WARNING, "Another warning");
  log->message(LOG_NORMAL, "Program continues...");
  log->message(LOG_ERROR, "Error happens twice! Just help me already!");
  std::this_thread::sleep_for(std::chrono::seconds(3));

  log->message(LOG_ERROR, "Error again! How much longer do I have to wait?!");
  log->message(LOG_WARNING, "I hope you care about me!");
  log->message(LOG_NORMAL, "Program is still going on...");
  std::this_thread::sleep_for(std::chrono::seconds(1));

  log->message(LOG_NORMAL, "Program ends!");
  log->message(LOG_WARNING, "Who's even looking at them?");
  log->message(LOG_ERROR,
               "Last error! I'm not going to repeat myself, I'm just going to "
               "finish!!!");
  std::this_thread::sleep_for(std::chrono::seconds(4));

  log->print();

  return 0;
}
