#ifndef _POINTERH_
#define _POINTERH_

#include "zobject.h"

class PACKAGE ZPointer;


typedef ZPointer pointer;

#pragma pack (push,1)

class ZPointer : ZObject
{
private:
  void *FData;
  size FSize;
  int FCount;
  int FBufferLength;
  friend class ZPointer;
  friend void __fastcall ForceSetSize(ZPointer &Class, int Size, int Count);
public:
  __fastcall ZPointer();
  __fastcall ZPointer(int Size, int Count);
  __fastcall ZPointer(const ZPointer &Src);
  __fastcall ~ZPointer();
//  void __fastcall SetSize(int Size, int Count, void *DefaultConstructor);
  void __fastcall SetSize(int Size, int Count);
//  void *__fastcall operator new[](size_t Size);
  void *__fastcall operator [](int Index);
  ZPointer &__fastcall operator =(const ZPointer &rhs);
  __property void *Data = {read=FData};
  __property size Size = {read=FSize};
//  ZComplexNumber &__fastcall operator =(const ZComplexNumber& rhs);
};


#pragma pack (pop)

#endif
