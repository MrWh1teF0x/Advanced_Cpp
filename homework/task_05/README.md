# Задание 5: Паттерн `Singleton`

Используя паттерн `Singleton`, разработайте систему протоколирования событий в системе. Система должна: - поддерживать 3 уровня важности событий (нормальный, замечание, ошибка); - обеспечить фиксацию события (с событием фиксируются время, важность, текстовое сообщение); - выводить на печать 10 последних событий.

Пример использования:
```cpp
#include "log.h"

void main(void) {
  Log *log = Log::Instance();
  log->message(LOG_NORMAL, "program loaded");

  // ...

  log->message(LOG_ERROR, "error happens! help me!");
  log->print();
}
```