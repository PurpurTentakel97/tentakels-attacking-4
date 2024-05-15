add_executable(tests
               Test_Temporary.cpp
)

target_link_libraries(tests
                      PRIVATE
                      tentakels-attacking
                      GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)