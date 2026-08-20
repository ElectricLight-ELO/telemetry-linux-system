#include "logger.h"

int main() {
    Logger::log(LogLevel::Info, "Watchdog started");
    return 0;
}