#include "config.h"
#include "logger.h"

int main() {
    Config cfg;
    Logger::log(LogLevel::Info, "Exporter starting on port " + std::to_string(cfg.port()));
    return 0;
}