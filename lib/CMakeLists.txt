add_library(MyDialectDefs
    MyDialect.cpp
    MyOps.cpp
)

target_include_directories(MyDialectDefs PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
    ${CMAKE_CURRENT_BINARY_DIR}/../include
)

target_link_libraries(MyDialectDefs PRIVATE
    MLIRIR
    MLIRSupport
)