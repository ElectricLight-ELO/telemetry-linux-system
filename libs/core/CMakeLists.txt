add_library(core STATIC
  src/config.cpp
  src/logger.cpp
)
target_include_directories(core
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(core PUBLIC Boost::boost)