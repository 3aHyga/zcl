#ifndef _MATRIXH_
#define _MATRIXH_

#include "zobject.h"
#include "zsimple.h"
#include "zpointer.h"
#include "zxfloat.h"

class PACKAGE ZComplexMatrix;
class PACKAGE ZMatrix;

typedef ZComplexMatrix xmatrix;
typedef ZMatrix matrix;

enum ZMatrixStyle {msZero, msSingle};

#pragma pack (push,1)


class ZComplexMatrix : public ZObject
{
  friend class ZComplexMatrix;
  friend bool __fastcall SolveLU(const ZComplexMatrix &A, ZComplexMatrix &X, const ZComplexMatrix &B);
private:
  spoint FSize;
  pointer FData;
  void __fastcall SetSize(spoint Size);
  void __fastcall SetX(short X);
  void __fastcall SetY(short Y);
  void __fastcall SetValue(short Y, short X, const ZComplexNumber &Value);
  ZComplexNumber &__fastcall GetValue(short Y, short X) const;
  pointer &__fastcall GetData();
  void __fastcall SetData(const pointer &Data);
public:
  __fastcall ZComplexMatrix();
  __fastcall ZComplexMatrix(const ZSmallPoint &Size);
  __fastcall ZComplexMatrix(const ZMatrixStyle style, const int Size);
  __fastcall ZComplexMatrix(const int y, const int x);
  __fastcall ZComplexMatrix(const ZComplexMatrix &Src);
  __fastcall ~ZComplexMatrix();
  void __fastcall Clear();
  ZComplexMatrix &__fastcall operator =(const ZComplexMatrix& rhs);
  ZComplexMatrix __fastcall operator +(const ZComplexMatrix& rhs);
  ZComplexMatrix __fastcall operator -(const ZComplexMatrix& rhs);
  ZComplexMatrix __fastcall operator *(const ZComplexMatrix& rhs);
  ZComplexMatrix __fastcall operator /(const ZComplexMatrix& rhs);
  ZComplexMatrix __fastcall operator ~(void);
  ZComplexMatrix __fastcall operator *(const ZComplexNumber& rhs);
  __property spoint Size = {read=FSize, write=SetSize};
  __property short X = {read=FSize.X, write=SetX};
  __property short Y = {read=FSize.Y, write=SetY};
  __property ZComplexNumber Value[short Y][short X] = {read=GetValue, write=SetValue};
  __property pointer Data = {read=GetData, write=SetData};
};

#pragma pack (pop)

#endif
