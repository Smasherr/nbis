project(imgtools)

set(IHEAD_SOURCE_FILES
        src/lib/ihead/getcomp.c
        src/lib/ihead/getnset.c
        src/lib/ihead/nullihdr.c
        src/lib/ihead/parsihdr.c
        src/lib/ihead/prntihdr.c
        src/lib/ihead/readihdr.c
        src/lib/ihead/valdcomp.c
        src/lib/ihead/writihdr.c)

set(IMAGE_SOURCE_FILES
        src/lib/image/bincopy.c
        src/lib/image/binfill.c
        src/lib/image/binpad.c
        src/lib/image/bitmasks.c
        src/lib/image/dilate.c
        src/lib/image/findblob.c
        src/lib/image/grp4comp.c
        src/lib/image/grp4deco.c
        src/lib/image/imageops.c
        src/lib/image/img_io.c
        src/lib/image/imgavg.c
        src/lib/image/imgboost.c
        src/lib/image/imgdecod.c
        src/lib/image/imgsnip.c
        src/lib/image/imgtype.c
        src/lib/image/imgutil.c
        src/lib/image/intrlv.c
        src/lib/image/masks.c
        src/lib/image/parsargs.c
        src/lib/image/readihdr.c
        src/lib/image/rgb_ycc.c
        src/lib/image/rl.c
        src/lib/image/sunrast.c
        src/lib/image/thresh.c
        src/lib/image/writihdr.c)

set(JPEGL_SOURCE_FILES
        src/lib/jpegl/decoder.c
        src/lib/jpegl/encoder.c
        src/lib/jpegl/huff.c
        src/lib/jpegl/huftable.c
        src/lib/jpegl/imgdat.c
        src/lib/jpegl/ppi.c
        src/lib/jpegl/sd4util.c
        src/lib/jpegl/tableio.c
        src/lib/jpegl/util.c)

set(WSQ_SOURCE_FILES
        src/lib/wsq/cropcoeff.c
        src/lib/wsq/decoder.c
        src/lib/wsq/encoder.c
        src/lib/wsq/globals.c
        src/lib/wsq/huff.c
        src/lib/wsq/ppi.c
        src/lib/wsq/sd14util.c
        src/lib/wsq/tableio.c
        src/lib/wsq/tree.c
        src/lib/wsq/util.c)

add_library(libihead ${IHEAD_SOURCE_FILES})
target_include_directories(libihead PRIVATE
        include)
target_link_libraries(libihead PRIVATE
        libcommonnbis)

add_library(libjpegl ${JPEGL_SOURCE_FILES})
target_include_directories(libjpegl PRIVATE
        include)
target_link_libraries(libjpegl PRIVATE
        libcommonnbis)

add_library(libwsq ${WSQ_SOURCE_FILES})
target_include_directories(libwsq PRIVATE
        include)
target_link_libraries(libwsq PRIVATE
        libcommonnbis
        libjpegl)

#[[need to build libimage static because of
missing implementation of the function

/* provided by application */
extern void print_usage(char *);

defined in include/parsargs.h]]
add_library(libimage STATIC ${IMAGE_SOURCE_FILES})
target_include_directories(libimage PUBLIC
        include)
target_link_libraries(libimage
        PRIVATE
        libcommonnbis
        libihead
        libwsq
        libjpegl
        PUBLIC
        libijg)