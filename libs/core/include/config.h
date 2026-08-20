#pragma once
#include <string>
#include <cstdlib>

class Config {
public:
    Config() {
        if (const char* p = std::getenv("EXPORTER_PORT")) {
            port_ = std::atoi(p);
        }
    }

    int port() const { return port_; }

private:
    int port_ = 9100;
};