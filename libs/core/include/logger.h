#pragma once
#include <iostream>
#include <string>

enum class LogLevel { Info, Warn, Error };

class Logger {
public:
    static void log(LogLevel level, const std::string& msg) {
        const char* prefix = level == LogLevel::Info  ? "[INFO] "
                            : level == LogLevel::Warn  ? "[WARN] "
                                                        : "[ERROR] ";
        std::cout << prefix << msg << std::endl;
    }
};