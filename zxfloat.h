#ifndef _XFLOATH_
#define _XFLOATH_

#include "zmathdef.h"
#include "zobject.h"

class PACKAGE ZComplexNumber;


typedef ZComplexNumber xfloat;

#pragma pack (push,1)

ZComplexNumber __fastcall ZExp(const ZComplexNumber &value);

class ZComplexNumber : ZObject
{
private:
  extended FReal;
  extended FVirtual;
  extended __fastcall GetModule();
public:
  __fastcall ZComplexNumber();
  __fastcall ZComplexNumber(extended rp, extended vp);
  ZComplexNumber __fastcall operator +(const ZComplexNumber& rhs) const;
  ZComplexNumber __fastcall operator +(const extended rhs) const;
  ZComplexNumber __fastcall operator -(const ZComplexNumber& rhs) const;
  ZComplexNumber __fastcall operator -(const extended rhs) const;
  ZComplexNumber __fastcall operator -() const;
  ZComplexNumber __fastcall operator *(const ZComplexNumber& rhs) const;
  ZComplexNumber __fastcall operator *(const extended rhs) const;
  ZComplexNumber __fastcall operator /(const ZComplexNumber& rhs) const;
  ZComplexNumber __fastcall operator /(const extended rhs) const;
  ZComplexNumber &__fastcall operator =(const ZComplexNumber& rhs);
  ZComplexNumber &__fastcall operator =(const extended rhs);
  ZComplexNumber &__fastcall operator =(const int rhs);
  ZComplexNumber &__fastcall operator ^=(const extended rhs);
  ZComplexNumber &__fastcall operator ^=(const int rhs);
  ZComplexNumber &__fastcall operator +=(const ZComplexNumber& rhs);
  ZComplexNumber &__fastcall operator -=(const ZComplexNumber& rhs);
  ZComplexNumber &__fastcall operator *=(const ZComplexNumber& rhs);
  ZComplexNumber &__fastcall operator /=(const ZComplexNumber& rhs);
  bool __fastcall operator ==(const ZComplexNumber& rhs) const;
  bool __fastcall operator !=(const ZComplexNumber& rhs) const;
  bool __fastcall operator >(const ZComplexNumber& rhs) const;
  bool __fastcall operator <(const ZComplexNumber& rhs) const;
  bool __fastcall operator >=(const ZComplexNumber& rhs) const;
  bool __fastcall operator <=(const ZComplexNumber& rhs) const;
  __property extended Real = {read=FReal , write=FReal};
  __property extended Virtual = {read=FVirtual , write=FVirtual};
  __property extended Module = {read=GetModule};
};


#pragma pack (pop)

#endif
