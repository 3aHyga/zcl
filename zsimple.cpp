#include "zsimple.h"



__fastcall ZSmallPoint::ZSmallPoint() : ZObject()
{
  FX = 0;
  FY = 0;
}
__fastcall ZSmallPoint::ZSmallPoint(int X, int Y) : ZObject()
{
  FX = X;
  FY = Y;
}
__fastcall ZSmallPoint::ZSmallPoint(ZSmallPoint &Point) : ZObject()
{
  FX = Point.X;
  FY = Point.Y;
}
ZSmallPoint &__fastcall ZSmallPoint::operator =(const short size)
{
  FX = size;
  FY = size;
  return *this;
}
ZSmallPoint &__fastcall ZSmallPoint::operator =(const ZSmallPoint &size)
{
  FX = size.X;
  FY = size.Y;
  return *this;
}
bool __fastcall ZSmallPoint::operator ==(const ZSmallPoint &rhs)
{
  return FX == rhs.X && FY == rhs.Y;
}
bool __fastcall ZSmallPoint::operator !=(const ZSmallPoint &rhs)
{
  return FX != rhs.X || FY != rhs.Y;
}
