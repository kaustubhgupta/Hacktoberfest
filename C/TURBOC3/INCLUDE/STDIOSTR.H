/* stdiostream.h -- class stdiobuf and stdiostream declarations

    Copyright (c) 1990, 1991 by Borland International    
    All rights reserved

    NOTE: These are inefficient and obsolete.  Use the standard classes and
    functions in <fstream.h> instead.
*/

#ifndef __cplusplus
#error Must use C++ for the type stdiostream.
#endif

#ifndef __STDSTREAM_H
#define __STDSTREAM_H

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

#if !defined( __IOSTREAM_H )
#include <iostream.h>
#endif

#if !defined( __STDIO_H )
#include <stdio.h>
#endif

#pragma option -Vo-

_CLASSDEF(stdiobuf)
_CLASSDEF(stdiostream)

class _CLASSTYPE stdiobuf : public streambuf {
public:
    _Cdecl stdiobuf(FILE *);
    FILE * _Cdecl stdiofile();
    _Cdecl ~stdiobuf();

    virtual int _Cdecl overflow(int=EOF);
    virtual int _Cdecl pbackfail(int);
    virtual int _Cdecl sync();
    virtual streampos _Cdecl seekoff(streamoff, ios::seek_dir, int);
    virtual int _Cdecl underflow();

private:
    FILE * sio;            
    char    lahead[2];
};
inline  FILE * _Cdecl stdiobuf::stdiofile() { return sio; }


class _CLASSTYPE stdiostream : public ios {
public:
        _Cdecl stdiostream(FILE *);
        _Cdecl ~stdiostream();
    stdiobuf * _Cdecl rdbuf();

private:
    stdiobuf buf;
};
inline  stdiobuf * _Cdecl stdiostream::rdbuf() { return &buf; }

#pragma option -Vo.

#endif
