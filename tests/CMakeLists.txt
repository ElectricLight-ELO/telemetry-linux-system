find_package(Boost REQUIRED COMPONENTS unit_test_framework)

add_executable(cr_tests
  core_tests.cpp
)

target_link_libraries(cr_tests
  PRIVATE core Boost::unit_test_framework
)

target_compile_definitions(cr_tests
  PRIVATE BOOST_TEST_DYN_LINK
)

add_test(NAME cr_tests COMMAND cr_tests)