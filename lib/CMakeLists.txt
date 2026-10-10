add_library(MyDialectDefs
    MyDialect.cpp
    MyOps.cpp
    MyDialectToArith.cpp
)

# .inc files will get generated only after hitting this line
add_dependencies(MyDialectDefs MyDialectIncGen)

target_link_libraries(MyDialectDefs PRIVATE
    MLIRIR
    MLIRSupport
)