#ifndef _SIMPLEH_
#define _SIMPLEH_

#include "zobject.h"


class PACKAGE ZSmallPoint;
class PACKAGE ZPoint;


typedef ZSmallPoint spoint;
typedef ZPoint point;

#pragma pack (push,1)


class ZSmallPoint : ZObject
{
private:
  short FX;
  short FY;
public:
  __fastcall ZSmallPoint();
  __fastcall ZSmallPoint(int X, int Y);
  __fastcall ZSmallPoint(ZSmallPoint &Point);
  ZSmallPoint &__fastcall operator =(const short size);
  ZSmallPoint &__fastcall operator =(const ZSmallPoint &size);
  bool __fastcall operator ==(const ZSmallPoint &rhs);
  bool __fastcall operator !=(const ZSmallPoint &rhs);
  __property short X = {read=FX,write=FY};
  __property short Y = {read=FY,write=FY};
};


#pragma pack (pop)

#endif
