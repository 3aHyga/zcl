#include "zpointer.h"
#include <mem.h>
#include <alloc.h>


__fastcall ZPointer::ZPointer()
{
  FData = NULL;
  FBufferLength = 0;
  FSize = 0;
  FCount = 0;
}
__fastcall ZPointer::ZPointer(int Size, int Count)
{
  ForceSetSize(*this,Size,Count);
}
__fastcall ZPointer::~ZPointer()
{
  delete[] FData;
}
__fastcall ZPointer::ZPointer(const ZPointer &Src)
{
  ForceSetSize(*this,Src.FSize,Src.FCount);
}
void __fastcall ForceSetSize(ZPointer &Class, int Size, int Count)
{
  Class.FBufferLength = (Size * Count) * 1.5;
//  int len = Class.FBufferLength;
//  void *ptr = calloc(len,1);
//  Class.FData = ptr;
  Class.FData = calloc(Class.FBufferLength,1);
  Class.FSize = Size;
  Class.FCount = Count;
}
void __fastcall ZPointer::SetSize(int Size, int Count)
{
  if(FData)
    if(FBufferLength >= Size * Count)
    {
      FSize = Size;
      FCount = Count;
      return;
    }
    else
      delete[] FData;
  ForceSetSize(*this,Size,Count);
}
void *__fastcall ZPointer::operator [](int Index)
{
  if(Index < 0 && Index >= FCount)
    return NULL;
  return (char *)FData + FSize * Index;
}
ZPointer &__fastcall ZPointer::operator =(const ZPointer &rhs)
{
  ForceSetSize(*this,rhs.FSize,rhs.FCount);
  memcpy(FData,rhs.Data,FBufferLength);
  return *this;
}

