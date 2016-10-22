project(NBIS)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -w -ansi -Wall")

include_directories(commonnbis/include)

add_definitions(-D__MSYS__ -DOPJ_STATIC -D_POSIX_SOURCE -DNO_FORK_AND_EXECL)
add_definitions(-D__NBISLE__) #unset if small endian

add_subdirectory(commonnbis)
add_subdirectory(ijg)
add_subdirectory(imgtools)
add_subdirectory(mindtct)
add_subdirectory(bozorth3)