add_executable(attacking
               include/ta/temporary.hpp
               temporary.cpp
               main.cpp
)

target_include_directories(attacking
                           PUBLIC include
                           PRIVATE include
)

target_link_libraries(attacking
                      PRIVATE
                      cpt::cpt_lib
                      spdlog::spdlog
                      PUBLIC
                      attacking_project_options
)
