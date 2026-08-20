add_executable(exporter
  src/main.cpp
)

target_link_libraries(exporter
  PRIVATE core
)