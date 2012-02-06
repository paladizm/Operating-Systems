/* ::[[ @(#) flip.h 1.16 89/07/04 17:00:46 ]]:: */

/*
Copyright 1989 Rahul Dhesi, All rights reserved.

Checksum: 2652839101 (check or update with "brik")

ANSI-compatibility strategy:

1.   If ANSIPROTO is defined, function prototypes are used, ANSI-style.
     If it is not defined, regular function declarations (without a
     parameter list) are used.  This is achieved with the use of
     the PARMS macro.
2.   If STDINCLUDE is defined, ANSI-conformant header files are
     included.  Otherwise functions that would be declared in such
     header files are declared individually.
*/

#ifndef OK_NL

/* Define ANSIPROTO and/or STDINCLUDE here if needed */
#ifdef TURBOC
# define    ANSIPROTO
# define    STDINCLUDE
#endif /* TURBOC */



#include <stdio.h>

#ifndef PARMS
# ifdef ANSIPROTO
#  define   PARMS(x)    x
# else
#  define   PARMS(x)    ()
# endif
#endif

/************************************************************/
/*** change following definitions as needed for your system */
/************************************************************/
/*
BIGBUF      If defined, setvbuf() will be used to set input and
            output buffers to BIGBUF characters
BINCHAR     This must be a macro accepting a single character
            argument and returning nonzero if and only if that
            character is a binary character.  By default, BINCHAR
            is defined to look up a table, and the table is compiled
            in by defining USE_TABLE.
CHECK_BREAK If your operating system requires programs to check
            for user interrupts at intervals, define CHECK_BREAK to
            be a function or macro that checks for a user interrupt.
            Flip will call this at intervals.  If not needed,
            define CHECK_BREAK to be null.
DELFILE     Must be a function or macro that will accept one filenames
            and delete that file, returning zero on success, nonzero
            on failure.
GETFT       Must be a macro with usage GETFT(file,name,var) that will
            take an open file, a filename, and a variable name, and
            put in that variable the timestamp of the file.
INT_EXIT    If USE_SIG is defined, INT_EXIT must be defined to
            be the exit code returned by flip when its execution
            is aborted by a user interrupt.
MVFILE      Must be a function or macro that will take two filenames
            and rename the first file to the second file, returning
            zero on success, nonzero on failure.
NIX         If this symbol is defined, some things common to most
            implementations of **IX get defined and need not be
            individually defined.
PATHSIZE    size of buffer(s) to use to hold pathname(s)
PICKNAME    Do "#define PICKNAME" if you want the program to know its
            name and respond to it.  If PICKNAME is not defined, the
            program will assume that it is called "flip".
SETFT       Must be a function or macro with usage SETFT(file,name,var)
            that will take an open file, a filename, and a variable
            name, and set the timestamp of the file from the variable.
SIG_T       If USE_SIG is defined, then SIG_T must be defined
            (or typedef'd) to be the data type returned by
            (*signal).  Usually int or void.
SPEC_EXIT   Like SPEC_INIT, but is called just before flip exits.
SPEC_INIT   This is invoked to initialize flip.  Should be defined to
            be either a function call (with trailing semicolon) or
            null string.
SGFTIME     This must be a typedef for a data type suitable to store
            file times.
USE_TABLE   If this is defined, flip code will use a table look-up
            to decide which characters should be considered binary.
            See also BINCHAR.
ULTRIX_BUG  At least one version of Ultrix chokes on a trailing "b"
            in the mode string for fopen().  If ULTRIX_BUG is defined
            no trailing "b" will be used.
USE_SIG     If this is defined, then signal() will be used so flip
            may trap user interrupts and delete temporary files.
            If USE_SIG is defined, then SIG_T and INT_EXIT must also
            be defined (below).
WILDCARD    If this is defined, the function nextfile() will be called
            to expand wildcards.  If WILDCARD is not defined, no
            wildcard expansion will be done and nextfile() is not
            needed.  For a description of nextfile() see turboc.c.
*/

#ifdef TURBOC
# define PATHSIZE    200
# define PICKNAME
# define BIGBUF      16384
# define DELFILE     remove
extern int MVFILE PARMS ((char *src, char *dest));            /* Turbo C */
# define USE_SIG
# define SIG_T void     /* return type from (*signal) */
# define INT_EXIT 127   /* status when a signal causes exit */
# define CHECK_BREAK  brktst();
void brktst PARMS ((void));
# define SPEC_INIT   spec_init();
# define SPEC_EXIT   spec_exit();
void spec_init PARMS ((void));
void spec_exit PARMS ((void));
# define WILDCARD

/* date and time */
# include <io.h>
  typedef struct ftime        SGFTIME;
# define GETFT(f,name,var)    getftime(fileno(f), &var)
# define SETFT(f,name,var)    setftime(fileno(f), &var)
#endif /* TURBOC */

#ifdef SYS_V
# define NIX         /* see below */
# define PATHSIZE    200
# define BIGBUF      16384
# define  MVFILE(src,dest)    (!(!link(src,dest)&&!unlink(src)))
# define SIG_T int
#endif /* SYS_V */

#ifdef BSD
# define NIX         /* see below */
# define PATHSIZE    1027
# undef  BIGBUF
# define  MVFILE     rename
# define SIG_T int
#endif /* BSD */

#ifdef VMS
# define PATHSIZE    1024
# define PICKNAME
# define BIGBUF      16384
# define DELFILE     delete
# define  MVFILE     rename
# define USE_SIG
# define SIG_T int
# define INT_EXIT    127
# define SPEC_INIT
# define SPEC_EXIT
#endif /* VMS */

/************************************************************/
/*** remaining definitions should not need to be changed ****/
/************************************************************/

/* define ASCII character values for linefeed, carriage return, control Z */
#define  LF    10
#define  CR    13
#define  CTRLZ 26

/* error codes */
#define  ERRBINF  1  /* binary file */
#define  ERRSIG   2  /* interrupted by signal */

/* how to strip high bit */
#define  STRIP(c)    c &= 0x7f

/**** BINCHAR(c) returns nonzero if c is a binary char ****/
#ifndef BINCHAR
# define USE_TABLE      /* use internal table -- see flip.c */
# define BINCHAR(c)  bintab[c]
#endif

/**** mode strings for fopen() -- to work around Ultrix problem ****/
/**** (Thanks to Taso N. Devetzis for reporting this)           ****/
#ifdef ULTRIX_BUG
# define WB          "w"
# define RB          "r"
# define R_PL_B      "r+"
#else
# define WB          "wb"     /* write binary */
# define RB          "rb"     /* read binary */
# define R_PL_B      "r+b"    /* read + update binary */
#endif /* ULTRIX_BUG */

/* things common to most **IX systems */
#ifdef NIX
# define SPEC_INIT
# define SPEC_EXIT
# define CHECK_BREAK
# define PICKNAME
# define DELFILE     unlink
# define USE_SIG
# define INT_EXIT    127
# include <sys/types.h>          /* for file time */
# include <sys/stat.h>           /* for file time */
  typedef struct stat            SGFTIME;
# define GETFT(file,name,var)    fstat(fileno(file),&var)
# define SETFT(file,name,var)    do { time_t x[2]; x[0] = var.st_atime; \
                                      x[1] = var.st_mtime; utime (name, x); \
                                  } while (0)
#endif /* NIX */

#endif /* OK_NL */
