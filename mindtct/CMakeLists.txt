project(mindtct)

set(LIB_SOURCE_FILES
        src/lib/mindtct/binar.c
        src/lib/mindtct/block.c
        src/lib/mindtct/chaincod.c
        src/lib/mindtct/contour.c
        src/lib/mindtct/detect.c
        src/lib/mindtct/dft.c
        src/lib/mindtct/free.c
        src/lib/mindtct/getmin.c
        src/lib/mindtct/globals.c
        src/lib/mindtct/imgutil.c
        src/lib/mindtct/init.c
        src/lib/mindtct/isempty.c
        src/lib/mindtct/line.c
        src/lib/mindtct/link.c
        src/lib/mindtct/log.c
        src/lib/mindtct/loop.c
        src/lib/mindtct/maps.c
        src/lib/mindtct/matchpat.c
        src/lib/mindtct/minutia.c
        src/lib/mindtct/morph.c
        src/lib/mindtct/mytime.c
        src/lib/mindtct/quality.c
        src/lib/mindtct/remove.c
        src/lib/mindtct/results.c
        src/lib/mindtct/ridges.c
        src/lib/mindtct/shape.c
        src/lib/mindtct/sort.c
        src/lib/mindtct/util.c
        src/lib/mindtct/xytreps.c)

add_library(libmindtct ${LIB_SOURCE_FILES})
target_include_directories(libmindtct PRIVATE
        include)

add_executable(mindtct src/bin/mindtct/mindtct.c)
target_include_directories(mindtct PRIVATE
        include)
target_link_libraries(mindtct
        PRIVATE
        libmindtct
        libimage)