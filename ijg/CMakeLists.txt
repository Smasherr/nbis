project(ijg)

set(LIB_SOURCE_FILES
        #[[src/lib/jpegb/ansi2knr.c]]
        src/lib/jpegb/cdjpeg.c
        #[[src/lib/jpegb/cjpeg.c]]
        #[[src/lib/jpegb/ckconfig.c]]
        src/lib/jpegb/decoder.c
        #[[src/lib/jpegb/djpeg.c]]
        src/lib/jpegb/encoder.c
        #[[src/lib/jpegb/example.c]]
        src/lib/jpegb/jcapimin.c
        src/lib/jpegb/jcapistd.c
        src/lib/jpegb/jccoefct.c
        src/lib/jpegb/jccolor.c
        src/lib/jpegb/jcdctmgr.c
        src/lib/jpegb/jchuff.c
        src/lib/jpegb/jcinit.c
        src/lib/jpegb/jcmainct.c
        src/lib/jpegb/jcmarker.c
        src/lib/jpegb/jcmaster.c
        src/lib/jpegb/jcomapi.c
        src/lib/jpegb/jcparam.c
        src/lib/jpegb/jcphuff.c
        src/lib/jpegb/jcprepct.c
        src/lib/jpegb/jcsample.c
        src/lib/jpegb/jctrans.c
        src/lib/jpegb/jdapimin.c
        src/lib/jpegb/jdapistd.c
        src/lib/jpegb/jdatadst.c
        src/lib/jpegb/jdatasrc.c
        src/lib/jpegb/jdcoefct.c
        src/lib/jpegb/jdcolor.c
        src/lib/jpegb/jddctmgr.c
        src/lib/jpegb/jdhuff.c
        src/lib/jpegb/jdinput.c
        src/lib/jpegb/jdmainct.c
        src/lib/jpegb/jdmarker.c
        src/lib/jpegb/jdmaster.c
        src/lib/jpegb/jdmerge.c
        src/lib/jpegb/jdphuff.c
        src/lib/jpegb/jdpostct.c
        src/lib/jpegb/jdsample.c
        src/lib/jpegb/jdtrans.c
        src/lib/jpegb/jerror.c
        src/lib/jpegb/jfdctflt.c
        src/lib/jpegb/jfdctfst.c
        src/lib/jpegb/jfdctint.c
        src/lib/jpegb/jidctflt.c
        src/lib/jpegb/jidctfst.c
        src/lib/jpegb/jidctint.c
        src/lib/jpegb/jidctred.c
        #[[src/lib/jpegb/jmemansi.c     only one
        src/lib/jpegb/jmemdos.c         memory manager
        src/lib/jpegb/jmemmac.c         should be
        src/lib/jpegb/jmemname.c        included]]
        src/lib/jpegb/jmemnobs.c        #we choose jmemnobs here for compatibility reasons
        src/lib/jpegb/jmemmgr.c
        #[[src/lib/jpegb/jpegtran.c]]
        src/lib/jpegb/jquant1.c
        src/lib/jpegb/jquant2.c
        src/lib/jpegb/jutils.c
        src/lib/jpegb/marker.c
        src/lib/jpegb/membuf.c
        src/lib/jpegb/ppi.c
        src/lib/jpegb/rdbmp.c
        src/lib/jpegb/rdcolmap.c
        src/lib/jpegb/rdgif.c
        src/lib/jpegb/rdjpgcom.c
        src/lib/jpegb/rdppm.c
        src/lib/jpegb/rdrle.c
        src/lib/jpegb/rdswitch.c
        src/lib/jpegb/rdtarga.c
        src/lib/jpegb/transupp.c
        src/lib/jpegb/wrbmp.c
        src/lib/jpegb/wrgif.c
        #[[src/lib/jpegb/wrjpgcom.c]]
        src/lib/jpegb/wrppm.c
        src/lib/jpegb/wrrle.c
        src/lib/jpegb/wrtarga.c)

add_library(libijg ${LIB_SOURCE_FILES})
target_include_directories(libijg
        PRIVATE
        ${imgtools_SOURCE_DIR}/include
        PUBLIC
        src/lib/jpegb)
target_link_libraries(libijg PRIVATE
        libcommonnbis
        libjpegl)
