#ifndef _COMPONENTH_
#define _COMPONENTH_

#include "zobject.h"

class ZComponent : ZComplexObject
{
private:
  ZComponent *FOwner;
  int FComponentCount;
  int FMaxComponentCount;
  int FComponentIndex;
  ZComponent **FComponents;
//  ComponentState;
//  ComponentStyle;
//  int DesignInfo;
//  AnsiString Name;
  int FTag;

  int __fastcall GetComponentIndex();
  void __fastcall SetComponentIndex(int Index);
  ZComponent *__fastcall GetComponent(int Index);

protected:

//  virtual void __fastcall BeforeDestruction(void);
//  virtual void __fastcall DefineProperties(TFiler* Filer);
//  virtual TComponent* __fastcall GetChildOwner(void);
//  virtual Component* __fastcall GetChildParent(void);
//  virtual void __fastcall GetChildren(TGetChildProc &Proc, TComponent* Root);
//  virtual TPersistent* __fastcall GetOwner(void);
//  virtual TComponent* __fastcall GetParentComponent(void);
//  virtual void __fastcall ReadState(TReader* Reader);
//  void __fastcall SetAncestor(bool Value);
//  virtual void __fastcall SetChildOrder(TComponent* Child, int Order);
//  void __fastcall SetDesigning(bool Value, bool SetChildren = true);
//  void __fastcall SetDesignInstance(bool Value);
//  void __fastcall SetInline(bool Value1);
//  virtual void __fastcall SetName(const AnsiString &NewName);
//  virtual void __fastcall SetParentComponent(TComponent* Value);
//  virtual void __fastcall Updating(void);
  virtual bool __fastcall ValidateInsert(ZComponent* AComponent);
//  virtual void __fastcall ValidateRename(TComponent* AComponent, const AnsiString CurName, const AnsiString NewName);
//  virtual void __fastcall WriteState(TWriter* Writer);

  virtual void __fastcall AssignTo(ZComponent* Dest);
  virtual ZComponent* __fastcall GetOwner(void);

public:
  __fastcall ZComponent(ZComponent *Owner);
  virtual __fastcall ~ZComponent();
  void __fastcall DestroyComponents(void);
//  void __fastcall Destroying(void);
//  TComponent* __fastcall FindComponent(const AnsiString AName);
//  void __fastcall FreeNotification(TComponent* AComponent);
//  virtual AnsiString __fastcall GetNamePath(void);
//  virtual bool __fastcall HasParent(void);
//  virtual void __fastcall PaletteCreated(void);
  void __fastcall InsertComponent(ZComponent* AComponent);
  void __fastcall RemoveComponent(ZComponent* AComponent);
  void __fastcall ChangeIndex(ZComponent *Component, int Index);
  int __fastcall IndexOf(ZComponent *Component);
  virtual void __fastcall Assign(ZComponent* Source);

  __property int ComponentCount = {read=FComponentCount};
  __property int ComponentIndex = {read=GetComponentIndex, write=SetComponentIndex};
  __property ZComponent* Components[int Index] = {read=GetComponent};
};

#endif
