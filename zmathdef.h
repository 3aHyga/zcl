#ifndef _ZMATHDEFSH_
#define _ZMATHDEFSH_

#include "zsysdefs.h"

#pragma warn -pch
extern const extended NaN;
extern const extended Inf;
extern const extended NegInf;
extern const extended MinSingle;
extern const extended MaxSingle;
extern const extended MinDouble;
extern const extended MaxDouble;
extern const extended MinExtended;
extern const extended MaxExtended;
extern const extended MinComp;
extern const extended MaxComp;
/*static const extended NaN = 0.0 / 0.0;
static const extended Inf = 1.0 / 0.0;
static const extended NegInf = -1.0 / 0.0;
static const extended MinSingle = 1.500000E-45;
static const extended MaxSingle = 3.400000E+38;
static const extended MinDouble = 5.000000E-324;
static const extended MaxDouble = 1.700000E+308;
static const extended MinExtended = 3.400000E-4932;
static const extended MaxExtended = 1.100000E+4932;
static const extended MinComp = -9.223372E+18;
static const extended MaxComp = 9.223372E+18;*/
//static const int NegativeValue = 0xffffffff;
//static const int ZeroValue = 0x0;
//static const int PositiveValue = 0x1;
#pragma option -w+pch

#define MaxNegVal = 0x80000000;
#define NegVal = 0xffffffff;
#define ZeroVal = 0x0;
#define PosVal = 0x1;

#define expc      2.71828182845904523536
#define log2e     1.44269504088896340736
#define lge       0.434294481903251827651
#define ln2       0.693147180559945309417
#define ln10      2.30258509299404568402
#define pi        3.14159265358979323846
#define pi_2      1.57079632679489661923
#define pi_4      0.785398163397448309616
#define sqrt2     1.41421356237309504880

#endif
