project(bozorth3)

include_directories(include)

set(LIB_SOURCE_FILES
        src/lib/bozorth3/bozorth3.c
        src/lib/bozorth3/bz_alloc.c
        src/lib/bozorth3/bz_drvrs.c
        src/lib/bozorth3/bz_gbls.c
        src/lib/bozorth3/bz_io.c
        src/lib/bozorth3/bz_sort.c)


add_library(libbozorth3 ${LIB_SOURCE_FILES})

add_executable(bozorth3 src/bin/bozorth3/bozorth3.c)
target_link_libraries(bozorth3 libbozorth3)