add_executable(tests
               Test_Components.cpp
)

target_link_libraries(tests
                      PRIVATE
                      data
                      GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)