#ifndef _ZSYSDEFSH_
#define _ZSYSDEFSH_

#pragma option push -b
//#include <sdl.h>
#pragma option pop


#ifndef PACKAGE
#define PACKAGE __declspec(package)
#endif

typedef unsigned __int64 qword;
typedef unsigned long dword;
typedef unsigned short word;
typedef unsigned char byte;
typedef long double extended;
typedef dword zclass;
typedef int size;

#ifndef NULL
#define NULL		     (void *)0
#endif

#define INVALID_INDEX_VALUE	     -1

#ifndef INVALID_HANDLE_VALUE
#define INVALID_HANDLE_VALUE (void *)-1
#endif

#endif
