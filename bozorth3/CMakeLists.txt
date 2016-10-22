project(bozorth3)

include_directories(include)

set(LIB_SOURCE_FILES
        src/lib/bozorth3/bozorth3.c
        src/lib/bozorth3/bz_alloc.c
        src/lib/bozorth3/bz_drvrs.c
        src/lib/bozorth3/bz_gbls.c
        src/lib/bozorth3/bz_io.c
        src/lib/bozorth3/bz_sort.c)

set(BIN_SOURCE_FILEs
        src/bin/bozorth3/bozorth3.c
        src/bin/bozorth3/usage.c)


add_library(libbozorth3 STATIC ${LIB_SOURCE_FILES})

add_executable(bozorth3 ${BIN_SOURCE_FILEs})
target_link_libraries(bozorth3 libbozorth3)