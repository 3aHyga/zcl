#ifndef _ZOBJECTH_
#define _ZOBJECTH_

#include "zsysdefs.h"

class PACKAGE Sysclass;
class PACKAGE ZObject;
class PACKAGE ZCommand;
class PACKAGE ZComponent;

#pragma pack (push,1)


class Sysclass
{
public:
  void __fastcall FreeInstance(zclass cls);
  ZObject* __fastcall NewInstance(zclass cls);
  long __fastcall InstanceSize(zclass cls);
};

class ZObject
{
private:
//  void __fastcall SetProperty(const AnsiString &Name, Variant &Value);
//  Variant __fastcall GetProperty(const AnsiString &Name);
//  AnsiString __fastcall GetName(void);
//  zclass __fastcall GetClassParent(void);
//  zclass __fastcall GetClassType(void);
//  void * __fastcall GetMethodAddress(const AnsiString &name);
public:
  __fastcall ZObject();
  virtual __fastcall ~ZObject();
  virtual void __fastcall MessageHandler(ZCommand *Command);
//__property Variant Property[const AnsiString Name] = {write=SetProperty,read=GetProperty};
//__property AnsiString Name = {read=GetName};
//__property zclass ClassParent = {read=GetClassParent};
//__property zclass ClassType = {read=GetClassType};
//__property void * MethodAddress[const AnsiString name] = {read=GetMethodAddress};
};

class ZComplexObject
{
private:
  ZComponent *FOwner;
public:
  __fastcall ZComplexObject(ZComponent *Owner);
  virtual __fastcall ~ZComplexObject();
};

#pragma pack (pop)

#endif
