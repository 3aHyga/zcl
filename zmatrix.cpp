#include "zmatrix.h"
#include <mem.h>
#include <alloc.h>

bool __fastcall SolveLU(const ZComplexMatrix &A, ZComplexMatrix &X, const ZComplexMatrix &B)
{
  ZComplexNumber zero;
  ZComplexMatrix L(A);
  X = B;
  //external (copyrighted) program block begin
  int k, i, i1, j, kp1, m, kb, km1, n = A.FSize.X;
  if(!n)
    return false;
  if(n == 1)
    X.Value[0][0] = B.Value[0][0] / A.Value[0][0];
  ZComplexNumber t;
  int *ip = (int *)calloc(n,sizeof(int));
  ip[n-1] = 1;
  for (k = 0; k < n - 1; k++) // k - the column number
  {
    kp1 = k + 1;
    m = k;
// Find a maximum value in the column
    for (i = kp1; i < n; i ++)
      if (L.Value[i][k].Module > L.Value[m][k].Module)
//        if (L.Value[i*n+k].Module > L.Value[m*n+k].Module)
        m = i;
    ip[k] = m;
    t = L.Value[m][k];
    if (m != k)
      L.Value[m][k] = L.Value[k][k];
//    if (!(t.Real || t.Virtual))
    if (t == zero)
      return false;
//   Put the maximum value in diagonal
    L.Value[k][k] = t;
    t = ZComplexNumber(1.,0.) / t;
    for (i1 = kp1; i1 < n; i1++)
      L.Value[i1][k] *= t;
//   Exchanging rows
    for (j = kp1; j < n; j++)
    {
      t = L.Value[m][j];
      L.Value[m][j] = L.Value[k][j];
      L.Value[k][j] = t;
//      if (!(t.Real || t.Virtual))
      if (t == zero)
        continue;
      for(i = kp1; i < n; i++)
        L.Value[i][j] -= (L.Value[i][k] * t);
    }
  }
  if (L.Value[n - 1][n - 1] == zero)
//  if (!(L.Value[n - 1][n - 1].Real || L.Value[n - 1][n - 1].Virtual))
    return false;
//   -----  Solving the LU-decomposed non-sparse equation system with complex coeefficients
//    n - dimension of system
//    a - square matrix stored by rows (i.e 1st row, 2nd row and so on)
//    b - at input: vector of unknowns,
//     at output: solution of system
//    ip - array of row exchanges (already formed in 'decom')
  for (j = 0; j < n; j++)
  {
    for (k = 0; k < n - 1; k++)
    {
      m = ip[k];
      t = X.Value[m][j];
      X.Value[m][j] = X.Value[k][j];
      X.Value[k][j] = t;
      for (i = k + 1; i < n; i++)
        X.Value[i][j] -= (L.Value[i][k] * t);
    }
    for (kb = 0; kb < n - 1; kb++)
    {
      km1 = n - kb - 2;
      k = km1 + 1;
//      X.Value[k][j] = X.Value[k][j] / L.Value[k][k];
      X.Value[k][j] /= L.Value[k][k];
      t = -X.Value[k][j];
      for (i = 0; i < k; i++)
        X.Value[i][j] += (L.Value[i][k] * t);
    }
    X.Value[0][j] /= L.Value[0][0];
  }
  delete[] ip;
  return true;
}



__fastcall ZComplexMatrix::ZComplexMatrix()
{
  FSize = spoint(1,1);
  FData.SetSize(sizeof(ZComplexNumber),1);
}
__fastcall ZComplexMatrix::ZComplexMatrix(const ZSmallPoint &Size)
{
  FSize = Size;
  FData.SetSize(sizeof(ZComplexNumber),Size.X * Size.Y);
}
__fastcall ZComplexMatrix::ZComplexMatrix(ZMatrixStyle style, int Size)
{
  FSize = spoint(Size,Size);
  FData.SetSize(sizeof(ZComplexNumber),Size*Size);
  if(style == msSingle)
    for(int i = 0; i < Size; i++)
      Value[i][i] = ZComplexNumber(1,0);
}
__fastcall ZComplexMatrix::~ZComplexMatrix()
{
//  int i, j;
//  for(i = 0; i < FSize.Y; i++)
//    for(j = 0; j < FSize.X; j++)
//	((ZComplexNumber *)FData[j + i * FSize.X])->~ZComplexNumber();
}
__fastcall ZComplexMatrix::ZComplexMatrix(int y, int x)
{
  FSize = spoint(x,y);
  FData.SetSize(sizeof(ZComplexNumber),x * y);
  int i, j;
//  for(i = 0; i < y; i++)
//    for(j = 0; j < x; j++)
//      Value[i][j] = ZComplexNumber();
}
__fastcall ZComplexMatrix::ZComplexMatrix(const ZComplexMatrix &Src)
{
  FSize = Src.FSize;
  FData = Src.FData;
}
void __fastcall ZComplexMatrix::Clear()
{
  memset(FData.Data,0,FData.Size*sizeof(ZComplexNumber));
}
void __fastcall ZComplexMatrix::SetSize(spoint Size)
{
  FSize = Size;
  FData.SetSize(sizeof(ZComplexNumber), Size.X * Size.Y);
}
void __fastcall ZComplexMatrix::SetX(short X)
{
  FSize.X = X;
}
void __fastcall ZComplexMatrix::SetY(short Y)
{
  FSize.Y = Y;
}
void __fastcall ZComplexMatrix::SetValue(short Y, short X, const ZComplexNumber &Value)
{
  *(ZComplexNumber *)FData[X + Y * FSize.X] = Value;
}
ZComplexNumber &__fastcall ZComplexMatrix::GetValue(short Y, short X) const
{
//  return *(ZComplexNumber *)(const_cast<ZPointer>FData)[X + Y * FSize.X];
  ZPointer *ptr = (ZPointer *)&FData;
  return *(ZComplexNumber *)(*ptr)[X + Y * FSize.X];
}
pointer &__fastcall ZComplexMatrix::GetData()
{
  return FData;
}
void __fastcall ZComplexMatrix::SetData(const pointer &Data)
{
  FData = Data;
}
ZComplexMatrix &__fastcall ZComplexMatrix::operator =(const ZComplexMatrix& rhs)
{
#pragma option -w-ncf
  FSize = rhs.Size;
  FData = rhs.Data;
  return *this;
#pragma option -w+ncf
}
ZComplexMatrix __fastcall ZComplexMatrix::operator +(const ZComplexMatrix& rhs)
{
  int i, j;
  ZComplexMatrix w;
  if(FSize == rhs.Size)
  {
    w.Size = spoint(FSize);
    ZComplexNumber *ptr1 = (ZComplexNumber *)FData.Data, *ptr2 = (ZComplexNumber *)rhs.FData.Data, *ptr3 = (ZComplexNumber *)w.FData.Data;
    for(i = 0; i < w.Size.Y; i++)
      for(j = 0; j < w.Size.X; j++)
	ptr3[i,j] = ptr1[i,j] + ptr2[i,j];
  }
  return w;
}
ZComplexMatrix __fastcall ZComplexMatrix::operator -(const ZComplexMatrix& rhs)
{
  int i, j;
  ZComplexMatrix w;
  if(FSize == rhs.Size)
  {
    w.Size = spoint(FSize);
    ZComplexNumber *ptr1 = (ZComplexNumber *)FData.Data, *ptr2 = (ZComplexNumber *)rhs.FData.Data, *ptr3 = (ZComplexNumber *)w.FData.Data;
    for(i = 0; i < w.Size.Y; i++)
      for(j = 0; j < w.Size.X; j++)
	ptr3[i,j] = ptr1[i,j] - ptr2[i,j];
  }
  return w;
}
ZComplexMatrix __fastcall ZComplexMatrix::operator *(const ZComplexMatrix& rhs)
{
  int i, j, k;
  ZComplexMatrix w;
  if(FSize.X == rhs.Size.Y)
  {
    w.Size = spoint(rhs.Size.X, FSize.Y);
    ZComplexNumber *ptr1 = (ZComplexNumber *)FData.Data, *ptr2 = (ZComplexNumber *)rhs.FData.Data, *ptr3 = (ZComplexNumber *)w.FData.Data;
    for(i = 0; i < w.Size.Y; i++)
      for(j = 0; j < w.Size.X; j++)
      {
				ptr3[i * w.Size.X + j] = ZComplexNumber();
				for(k = 0; k < FSize.X; k++)
					ptr3[i * w.Size.X + j] += ptr1[i * FSize.X + k] * ptr2[k * w.Size.X + j];
      }
  }
  return w;
}
ZComplexMatrix __fastcall ZComplexMatrix::operator /(const ZComplexMatrix& rhs)
{
/*  ZComplexMatrix x(FSize.X,rhs.Size.X);
  SolveLU(*this, x, rhs);
  return x;*/
//  ZComplexMatrix x = (&rhs)->ZComplexMatrix::~();
  ZComplexMatrix x = ~const_cast<ZComplexMatrix &>(rhs);
  return x * *this;
}
ZComplexMatrix __fastcall ZComplexMatrix::operator ~(void)
{
  ZComplexMatrix x(FSize.X,FSize.Y);
  if(SolveLU(*this, x, ZComplexMatrix(msSingle, FSize.Y)))
    return x;
  return ZComplexMatrix();
}
ZComplexMatrix __fastcall ZComplexMatrix::operator *(const ZComplexNumber& rhs)
{
  int i, j;
  ZComplexMatrix w(*this);
//  w.Size = spoint(FSize);
//  ZComplexNumber *ptr1 = (ZComplexNumber *)FData.Data, *ptr2 = (ZComplexNumber *)rhs.FData.Data, *ptr3 = (ZComplexNumber *)w.FData.Data;
  ZComplexNumber *ptr = (ZComplexNumber *)w.Data.Data;
  for(i = 0; i < w.Size.Y; i++)
    for(j = 0; j < w.Size.X; j++)
      ptr[i * w.Size.X + j] *= rhs;
  return w;
}

