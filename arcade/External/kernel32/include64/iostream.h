/*------------------------------------------------------------------------
 Module:        D:\LCC\IOSTREAM\iostream.h
 Author:        Jacob
 Project:       iostream library
 State:
 Creation Date: May 2000
 Description:   Implementation of iostreams for output
                only. Input should be here but is not yet
                done.
                Note that this builds upon stdio.h, so
                all synchronization with stdio is not
                necessary.
------------------------------------------------------------------------*/
#ifndef __iostream_h__
#define __iostream_h__
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#pragma once

typedef union _sink {
    FILE *f;
    char *string;
} iostream_outputSink;

typedef struct tagiostream {
    iostream_outputSink f;
    unsigned int pos;
    int capacity;
    unsigned stringp; // String based
    unsigned extensible; // Can be extended with malloc
    unsigned skipws:1;
    unsigned left:1; // Left-align values
    unsigned right:1; //  Right-align values; pad on the left with the fill character (default alignment).
    unsigned dec:1; // Format numeric values in decimal
    unsigned oct:1; // Format numeric values in base 8
    unsigned hex:1; //Format numeric values as base 16 (hexadecimal).
    unsigned showpoint:1; // Show decimal point and trailing zeros for floating-point values.
    unsigned uppercase:1; //Display uppercase A through F for hexadecimal values and E for scientific values.
    unsigned showpos:1; // Show plus signs (+) for positive values.
    unsigned scientific:1; // Display floating-point numbers in scientific format.
    unsigned unitbuf:1; //Cause flush the stream after each insertion. Not implemented
    unsigned showbase:1; // Show the output base
    unsigned thousands:1; // Puts a blank after a group of three chars
    unsigned char fill; //Sets or reads the streams fill character.
    unsigned char precision;
    unsigned char width;
} iostream;

typedef enum {eflush,edec,eoct,ehex,ewidth,ethousands} controlsequences;
typedef struct _control {
    controlsequences val;
} Control;

extern Control flush;
extern Control dec;
extern Control oct;
extern Control hex;
extern Control thousands ;


#define nl "\n"

extern iostream *cout;

// Sets a new field width. Returns the old value. Zero means default width
int iostream_set_width(iostream *i,int w);
/*------------------------------------------------------------------------
 Procedure:     iostream operator << with char string
 Purpose:       Actually stuffs the given (zero terminated) character
                string into the iostream.If the iostream is NOT a
                string based one, it will just call fprintf and exit.
                With string based iostreams, it will test for enough
                place in the string, and reallocate if necessary.
 Input:         the iostream and the string to put in it.
 Output:        Returns the number of characters written.
 Errors:        None. infinite loops in string based iostream will
                provoke memory exhaustion and SeztChars will return
                0.
------------------------------------------------------------------------*/
iostream * operator <<(iostream *i,char *p);

/*------------------------------------------------------------------------
 Procedure:     iostream operator << with int ID:1
 Purpose:       Outputs an int, using the current base, the width and the
                thousands flag.
 Input:         the iostream and the int to put in it.
 Output:        Returns the iostream
 Errors:
------------------------------------------------------------------------*/
iostream * operator <<(iostream *f,int i);

/*------------------------------------------------------------------------
 Procedure:     iostream operator << with int
 Purpose:       Outputs an int, using the current base, the width and
                ignoring the thousands flag.
 Input:         the iostream and the unsigned int to put in it.
 Output:        Returns the iostream
 Errors:
------------------------------------------------------------------------*/
iostream * operator <<(iostream *f,unsigned int u);


/*------------------------------------------------------------------------
 Procedure:     iostream operator << with double
 Purpose:       Outputs a double, using the current width and the
                precision flag.
 Input:         the iostream and the double to put in it.
 Output:        Returns the iostream
 Errors:
------------------------------------------------------------------------*/
iostream * operator <<(iostream *f,double d);

/*------------------------------------------------------------------------
 Procedure:     iostream operator << with control
 Purpose:       Sets the value of the base, or the thounsands flag, or
                flushes the stream.
 Input:         the iostream and the control. Example
                cout << hex << 123456 nl;
                The controls are:
                hex,dec,oct          Base manipulation
                flush                Flushes the output stream
                thousands            Separates the integer values in groups
                                     of three digits
 Output:        Returns the iostream
 Errors:
------------------------------------------------------------------------*/
iostream * operator <<(iostream *f,Control e);

/*------------------------------------------------------------------------
 Procedure:     iostream operator << with control
 Purpose:       Sets the value of the base, or the thounsands flag, or
                flushes the stream.
 Input:         the iostream and the control. Example
                cout << hex << 123456 nl;
                The controls are:
                hex,dec,oct          Base manipulation
                flush                Flushes the output stream
                thousands            Separates the integer values in groups
                                     of three digits
 Output:        Returns the iostream
 Errors:
------------------------------------------------------------------------*/
iostream * operator <<(controlsequences e,iostream *f);

// Same as double
iostream *operator <<(iostream *f,float l);

//Same as int
iostream *operator <<(iostream *f,short s);

/*------------------------------------------------------------------------
 Procedure:     iosstream_new_from_file. Initializes an iostream with the given
                file pointer
 Purpose:       The file must be open for writing. This is not verified
 Input:
 Output:        Returns the iostream with its setting with default values
 Errors:
------------------------------------------------------------------------*/
iostream *iostream_new_from_file(FILE *f);
/*------------------------------------------------------------------------
 Procedure:     iostream_new_from_string. Initializes an iostream with the
                given string pointer
 Purpose:       Several initializations are possible.
 Input:         The input arguments are:
                string pointer   length   Description
                NULL           | 0      | Initializes a resizable iostream
                               |        | and allocates a string buffer
                NULL           | length | Initializes a non resizable iostream
                               |        | and allocates a string buffer of the
                               |		| given length. Any writing when the
                               |		| string buffer is full will provoke
                               |		| no further input
                string         | 0      | Initializes a resizable iostream
                               |        | and copies the contents of the
                               |        | given string to it.
                string         | length | Initializes a non-resizable iostream
                               |        | of the given length.
 Output:        Returns the iostream with its setting with default values
 Errors:
------------------------------------------------------------------------*/
iostream *iostream_new_from_string(char *s,int len);


/*------------------------------------------------------------------------
 Procedure:     iostream_get_string
 Purpose:       Returns a pointer to the iostream buffer
 Input:         The iostream. Must have been created with
                new_ios_from_string
 Output:        Returns the string pointer.
 Errors:
------------------------------------------------------------------------*/
char *iostream_get_string(iostream * i);

/*------------------------------------------------------------------------
 Procedure:     iostream_set_thousands
 Purpose:       Sets/unsets the thousands flag.
 Input:
 Output:        Returns the old value of the thousands flag.
 Errors:
------------------------------------------------------------------------*/
int iostream_set_thousands(iostream *,int);
// Queries the thousands flag.
int iostream_get_thousands(iostream *);
/*------------------------------------------------------------------------
 Procedure:     iostream_set_precision
 Purpose:       Sets the precision. Values < 255 will be accepted, but
                only values < 16 are useful...
 Input:
 Output:        Returns the old value of the thousands flag.
 Errors:
------------------------------------------------------------------------*/
int iostream_set_precision(iostream *,int);
int iostream_get_precision(iostream *);

/*------------------------------------------------------------------------
 Procedure:     iostream_get_base Initializes an iostream with the given file
                pointer
 Purpose:       The file must be open for writing. This is not verified
 Input:
 Output:        Returns the iostream with its setting with default values
 Errors:
------------------------------------------------------------------------*/
int iostream_get_base(iostream *i);

int iostream_set_base(iostream *i,int base);

/*------------------------------------------------------------------------
 Procedure:     iostream_tell
 Purpose:       Returns the current position of the given iostream
 Input:         The iostream
 Output:        An unsigned long with the current position. This will not
                work with files longuer than 4GB.
 Errors:
------------------------------------------------------------------------*/
unsigned long iostream_tell(iostream *i);

FILE *iostream_set_file(iostream *f,FILE *newF);
FILE *iostream_get_file(iostream *f);
/*------------------------------------------------------------------------
 Procedure:     iostream_seek (iostream *,long,int)
 Purpose:       Manipulates the current position. For string based iostreams
                the string buffer will be resized as necessary.
 Input:
 Output:        Returns the iostream
 Errors:
------------------------------------------------------------------------*/
int iostream_seek(iostream *i,unsigned long pos,int how);

/*------------------------------------------------------------------------
 Procedure:     close_ios
 Purpose:       Close the file (if any) releases the string buffer (if any)
                and frees the memory associated with the iostream structure
 Input:         the iostream to close
 Output:        None
 Errors:
------------------------------------------------------------------------*/
void iostream_close(iostream *ios);
#endif
