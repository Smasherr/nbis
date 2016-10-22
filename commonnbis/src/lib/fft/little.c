    /*******************************************************************************

License: 
This software and/or related materials was developed at the National Institute
of Standards and Technology (NIST) by employees of the Federal Government
in the course of their official duties. Pursuant to title 17 Section 105
of the United States Code, this software is not subject to copyright
protection and is in the public domain. 

This software and/or related materials have been determined to be not subject
to the EAR (see Part 734.3 of the EAR for exact details) because it is
a publicly available technology and software, and is freely distributed
to any interested party with no licensing requirements.  Therefore, it is 
permissible to distribute this software as a free download from the internet.

Disclaimer: 
This software and/or related materials was developed to promote biometric
standards and biometric technology testing for the Federal Government
in accordance with the USA PATRIOT Act and the Enhanced Border Security
and Visa Entry Reform Act. Specific hardware and software products identified
in this software were used in order to perform the software development.
In no case does such identification imply recommendation or endorsement
by the National Institute of Standards and Technology, nor does it imply that
the products and equipment identified are necessarily the best available
for the purpose.

This software and/or related materials are provided "AS-IS" without warranty
of any kind including NO WARRANTY OF PERFORMANCE, MERCHANTABILITY,
NO WARRANTY OF NON-INFRINGEMENT OF ANY 3RD PARTY INTELLECTUAL PROPERTY
or FITNESS FOR A PARTICULAR PURPOSE or for any purpose whatsoever, for the
licensed product, however used. In no event shall NIST be liable for any
damages and/or costs, including but not limited to incidental or consequential
damages of any kind, including economic damage or injury to property and lost
profits, regardless of whether NIST shall be advised, have reason to know,
or in fact shall know of the possibility.

By using this software, you agree to bear all risk relating to quality,
use and performance of the software and/or related materials.  You agree
to hold the Government harmless from any claim arising from your use
of the software.

*******************************************************************************/


/***********************************************************************
      LIBRARY: PCASYS_UTILS - Pattern Classification System Utils

      FILE:    LITTLE.C
      AUTHORS: Craig Watson
               G. T. Candela
      DATE:    1995
      UPDATED: 04/20/2005 by MDG
               03/02/2007 by Kenneth Ko

      Utility routines for PCASYS.

      ROUTINES:
#cat: creat_ch - tries to creat a file
#cat: dptr2ptr_uchar - converts [][] into *
#cat: erode - erodes a raster
#cat: exists - finds out whether a file exists
#cat: fopen_ch - tries to fopen a file
#cat: fopen_noclobber - tries to fopen a file for writing, unless it exists
#cat: get_datadir - tries to find the pcasys data directory
#cat: isverbose - finds out whether the verbosity is on
#cat: lastcomp - finds last component of a pathname
#cat: linecount - counts the lines in a file
#cat: linreg - linear regression
#cat: malloc_ch - tries to malloc a buffer
#cat: open_read_ch - tries to open a file for reading
#cat: rcfill - fills holes in the rows and cols of a raster
#cat: rsblobs - removes small blobs from a raster
#cat: setverbose - sets the verbosity
#cat: sleepity - sleep, or wait for user to hit return key
#cat: summary - computes and writes summary info for a test run
#cat: tilde_filename - changes ~/string to home-dir/string
#cat: usage_func - for use by the "usage" macro
#cat: Usage_func - for use by the "Usage" macro
#cat: write_ihdr_std - writes ihdr file with many "standard" fields

***********************************************************************/

#include <stdio.h>
/*#include <time.h>
#include <unistd.h>*/
#include <stdlib.h>
/*#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>*/
#include "little.h"
/*#include <findblob.h>
#include <ihead.h>*/
#include <img_io.h>
#include <memalloc.h>
#include <util.h>
/*#include <fixup.h>*/
#ifndef __MSYS__
#include <libgen.h>
#endif

/*******************************************************************/

/* Tries a malloc; calls fatalerr in case of failure */

char *malloc_ch(const int nbytes)
{
  char *p, str[100];

  if(!(p = malloc(nbytes))) {
    sprintf(str, "malloc of %d bytes failed", nbytes);
    fatalerr("malloc_ch", str, NULL);
  }
  return p;
}
