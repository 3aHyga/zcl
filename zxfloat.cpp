#include "zxfloat.h"

//extern "C" extedned __fastcall Module$ggg();
//__asm
//{
//EXTRN @@Module$ggg;
//}




__fastcall ZComplexNumber::ZComplexNumber() : ZObject()
{
  FReal = 0;
  FVirtual = 0;
}

__fastcall ZComplexNumber::ZComplexNumber(extended rp, extended vp) : ZObject()
{
  FReal = rp;
  FVirtual = vp;
}

ZComplexNumber __fastcall ZComplexNumber::operator +(const ZComplexNumber& rhs) const
{
  return ZComplexNumber(rhs.Real + FReal, rhs.Virtual + FVirtual);
}
ZComplexNumber __fastcall ZComplexNumber::operator +(const extended lhs) const
{
  return ZComplexNumber(Real + lhs, Virtual);
}

ZComplexNumber __fastcall ZComplexNumber::operator -(const ZComplexNumber& rhs) const
{
  return ZComplexNumber(FReal - rhs.Real, FVirtual - rhs.Virtual);
}
ZComplexNumber __fastcall ZComplexNumber::operator -() const
{
  return ZComplexNumber(-FReal, -FVirtual);
}
ZComplexNumber __fastcall ZComplexNumber::operator -(const extended rhs) const
{
  return ZComplexNumber(FReal - rhs, FVirtual);
}
ZComplexNumber __fastcall ZComplexNumber::operator *(const ZComplexNumber& rhs) const
{
  return ZComplexNumber(FReal * rhs.Real - FVirtual * rhs.Virtual, FReal * rhs.Virtual + FVirtual * rhs.Real);
}
ZComplexNumber __fastcall ZComplexNumber::operator *(const extended rhs) const
{
  return ZComplexNumber(FReal * rhs, FVirtual * rhs);
}
ZComplexNumber __fastcall ZComplexNumber::operator /(const ZComplexNumber& rhs) const
{
  extended z = rhs.Virtual * rhs.Virtual + rhs.Real * rhs.Real;
  if(z)
    return ZComplexNumber((FReal * rhs.Real + FVirtual * rhs.Virtual)/z, (FVirtual * rhs.Real - FReal * rhs.Virtual)/z);
  return ZComplexNumber(Inf,Inf);
}
ZComplexNumber __fastcall ZComplexNumber::operator /(const extended rhs) const
{
  if(rhs)
    return ZComplexNumber(FReal / rhs, FVirtual / rhs);
  return ZComplexNumber(Inf, Inf);
}


ZComplexNumber &__fastcall ZComplexNumber::operator +=(const ZComplexNumber& rhs)
{
  FReal += rhs.Real, FVirtual += rhs.Virtual;
  return *this;
}
ZComplexNumber &__fastcall ZComplexNumber::operator -=(const ZComplexNumber& rhs)
{
  FReal -= rhs.Real, FVirtual -= rhs.Virtual;
  return *this;
}
ZComplexNumber &__fastcall ZComplexNumber::operator *=(const ZComplexNumber& rhs)
{
  extended real = FReal * rhs.Real - FVirtual * rhs.Virtual;
  FVirtual = FReal * rhs.Virtual + FVirtual * rhs.Real;
  FReal = real;
  return *this;
}
ZComplexNumber &__fastcall ZComplexNumber::operator /=(const ZComplexNumber& rhs)
{
  extended z = rhs.Virtual * rhs.Virtual + rhs.Real * rhs.Real, real;
  if(z)
  {
    real = (FReal * rhs.Real + FVirtual * rhs.Virtual)/z;
    FVirtual = (FVirtual * rhs.Real - FReal * rhs.Virtual)/z;
    FReal = real;
  }
  else
  {
    FReal = Inf;
    FVirtual = Inf;
  }
  return *this;
}

ZComplexNumber	&__fastcall ZComplexNumber::operator =(const ZComplexNumber& rhs)
{
  FReal = rhs.Real;
  FVirtual = rhs.Virtual;
  return *this;
}
ZComplexNumber	&__fastcall ZComplexNumber::operator =(const extended rhs)
{
  FReal = rhs;
  return *this;
}
ZComplexNumber	&__fastcall ZComplexNumber::operator =(const int rhs)
{
  FReal = rhs;
  return *this;
}
ZComplexNumber	&__fastcall ZComplexNumber::operator ^=(const extended rhs)
{
  FVirtual = rhs;
  return *this;
}
ZComplexNumber	&__fastcall ZComplexNumber::operator ^=(const int rhs)
{
  FVirtual = rhs;
  return *this;
}
bool __fastcall ZComplexNumber::operator ==(const ZComplexNumber& rhs) const
{
  return FReal == rhs.Real && FVirtual == rhs.Virtual;
}
bool __fastcall ZComplexNumber::operator !=(const ZComplexNumber& rhs) const
{
  return FReal != rhs.Real || FVirtual != rhs.Virtual;
}
bool __fastcall ZComplexNumber::operator >(const ZComplexNumber& rhs) const
{
  return FReal > rhs.Real && FVirtual > rhs.Virtual;
}
bool __fastcall ZComplexNumber::operator <(const ZComplexNumber& rhs) const
{
  return FReal < rhs.Real && FVirtual < rhs.Virtual;
}
bool __fastcall ZComplexNumber::operator >=(const ZComplexNumber& rhs) const
{
  return FReal >= rhs.Real && FVirtual >=rhs.Virtual;
}
bool __fastcall ZComplexNumber::operator <=(const ZComplexNumber& rhs) const
{
  return FReal <= rhs.Real && FVirtual <= rhs.Virtual;
}
