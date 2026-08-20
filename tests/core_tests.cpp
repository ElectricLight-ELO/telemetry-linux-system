#define BOOST_TEST_MODULE CoreTests
#include <boost/test/unit_test.hpp>
#include "config.h"
#include <cstdlib>

// первые тесты на проверку конфигурации портов
BOOST_AUTO_TEST_CASE(config_default_port) {
    
    unsetenv("EXPORTER_PORT");

    Config cfg;
    BOOST_CHECK_EQUAL(cfg.port(), 9100);
}

BOOST_AUTO_TEST_CASE(config_reads_port_from_env) {
    setenv("EXPORTER_PORT", "8080", 1);

    Config cfg;
    BOOST_CHECK_EQUAL(cfg.port(), 8080);

    unsetenv("EXPORTER_PORT"); 
}