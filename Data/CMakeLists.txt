add_library(data
            STATIC
            include/data/GameObject.hpp
            temporary.cpp
            include/data/Components.hpp
            include/data/Galaxy.hpp
)

target_include_directories(data
                           PUBLIC include
                           PRIVATE include
)

target_link_libraries(data
                      PUBLIC
                      cpt::cpt_lib
                      tl::optional
                      raylib
                      attacking_project_options
)
