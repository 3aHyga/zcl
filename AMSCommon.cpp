
#include <math.h>
#include <complex>

#include "AMSCommon.h"
#include "Libmat.h"



/////////////////////////////////////////////////////////////
void DecomLU_PV_C(int n,CValue *a, int *ip, int &emptyLineNumber)
//  -----  LU-decomposition of non-sparse matrix.
//    n - dimension of system
//    a - square matrix stored by rows (i.e 1st row, 2nd row and so on)
//    ip - array of row exchanges
//    emptyLineNumber - < 0 for case OK,
//          otherwise - number of "bad" line in the system
// Warnings:
//  1. indices of matrix and arrays are zero-based,
//     i.e. each index varies in range [0...n-1].
//  2. memory for "a" and "ip" must be allocated beyond this module.
{
    CValue zero(0.,0.);
    emptyLineNumber = -1;
    if (n > 0) ip[n-1] = 1;
    if (n > 1)
    {  for (int k = 0; k < n - 1; k++) // k - the column number
       {  int kp1 = k + 1;
          int m = k;
// Find a maximum value in the column
          for (int i = kp1; i < n; i ++)
            if (CMod(a[i*n+k]) > CMod(a[m*n+k])) m = i;
          ip[k] = m;
          CValue t = a[m*n+k];
          if (m != k) a[m*n+k] = a[k*n+k];
          if (t == zero)
          { emptyLineNumber = k;
            return;
          }
//   Put the maximum value in diagonal
          a[k*n+k] = t;
          t = CValue(1.,0.) / t;
          for (int i1 = kp1; i1 < n; i1++)
               a[i1*n+k] *= t;
//   Exchanging rows
          for (int j = kp1; j < n; j++)
          { t = a[m*n+j];
            a[m*n+j] = a[k*n+j];
            a[k*n+j] = t;
            if (t == zero) continue;
            for(int i = kp1; i < n; i++)
                a[i*n+j] -= (a[i*n+k]*t);
          }
        } // end of for (k = ...
    }
    if (a[(n-1)*n+n-1] == zero) emptyLineNumber = (n - 1);
}

void SolveLU_PV_C(int n,CValue *a,CValue *b, int *ip)
//   -----  Solving the LU-decomposed non-sparse equation system with complex coeefficients
//    n - dimension of system
//    a - square matrix stored by rows (i.e 1st row, 2nd row and so on)
//    b - at input: vector of unknowns,
//     at output: solution of system
//    ip - array of row exchanges (already formed in 'decom')
// Warnings:
//  1. indices of matrix and arrays are zero-based,
//     i.e. each index varies in range [0...n-1].
//  2. memory for "a", "b" and "ip" must be already
//     allocated beyond this module.
{
    if (n > 1)
    { for (int k = 0; k < n - 1; k++)
      { int m = ip[k];
        CValue t = b[m];
        b[m] = b[k];
        b[k] = t;
        for (int i = k + 1; i < n; i++)
            b[i] -= (a[i*n+k] * t);
      } // for (k = ...
      for (int kb = 0; kb < n - 1; kb++)
      {  int km1 = n - kb - 2;
         int k = km1 + 1;
         b[k] = b[k] / a[k*n+k];
         CValue t = -b[k];
         for (int i = 0; i < k; i++)
            b[i] += (a[i*n+k]*t);
      }
    }
    if (n >= 1) b[0] /= a[0*n+0];
}

void CMatrixMult(CValue *A,CValue *B,CValue *C,int Na,int Nb,int Nab)
{
    // C[Na*Nb] = A[Na*Nab] * B[Nab*Nb]
    for(int i=0; i < Na; i++)
    {
       for(int j=0; j < Nb; j++)
       {  CValue a(0.,0.);
          for(int k=0; k < Nab; k++)
            a += A[k + i*Nab]*B[j + k*Nb];
          C[j + i*Nb] += a;
       }
    } 
}

void CMatrixDump(const CString name,CValue *A,int Nr,int Nc)
{
    printf("\tMATRIX %s[%d*%d]\n",name,Nr,Nc);
    for(int i=0; i < Nr; i++)
    {   printf("%d.",i);
        for(int j=0; j < Nc; j++)
        { int index = j + i*Nc;
          printf("\t%d.(%g + j*%g)",index,A[index].real(),A[index].imag());
        }
        printf("\n");
    }
}

double CMod(CValue a)
{
    double x = a.real();
    double y = a.imag();
    return(sqrt(x*x + y*y));
}

double CArg(CValue a_c)
{
	double pi_2 = 1.570796326795;
	double b    = 180/(2*pi_2);
    double x = a_c.real();
    double y = a_c.imag();
	double a;
	double s_x = (x != 0.0) ? x/fabs(x) : 1.0;
	double s_y = (y != 0.0) ? y/fabs(y) : 1.0;
    if(x != 0.0)
    {  a = atan(fabs(y)/fabs(x));
	   if(s_x < 0 && s_y > 0)
	      a = 2*pi_2 - a;
	   if(s_x < 0 && s_y < 0)
	      a = a - 2*pi_2;
	   if(s_x > 0 && s_y < 0)
	      a = -a;
	   return(a*b);
	}
    else
    {  if(y == 0)
	      return(0.);
       if(s_y > 0)
		  a = pi_2;
	   else
		  a = -pi_2;
	   return(a*b);
    }
}
