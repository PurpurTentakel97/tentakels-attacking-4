add_executable(tests
               Test_Temporary.cpp
)

target_link_libraries(tests
                      PRIVATE
                      data
                      GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)