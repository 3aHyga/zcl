#ifndef _AMS_COMMON_H
#define _AMS_COMMON_H

#include <complex>




#define CValue std::complex<double>

void   DecomLU_PV_C(int n, CValue *A, int *ip, int &emptyLineNumber);
void   SolveLU_PV_C(int n, CValue *A, CValue *b, int *ip);
void   CMatrixMult(CValue* A,CValue* B,CValue* C,int Na,int Nb,int Nab);
void   CMatrixDump(const CString name,CValue* A,int Nr,int Nc);
double CMod(CValue a);
double CArg(CValue a);


#endif