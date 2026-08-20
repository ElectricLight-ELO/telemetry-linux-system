add_executable(watchdog
  src/main.cpp
)

target_link_libraries(watchdog
  PRIVATE core
)