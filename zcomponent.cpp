#include "zcomponent.h"
#include <mem.h>

#define DEFAULT_MAX_COMPONENTS	32

//__fastcall TGraph2D::TGraph2D(TComponent* Owner) : TCustomControl(Owner)
__fastcall ZComponent::ZComponent(ZComponent *Owner) : ZComplexObject(Owner)
{
  FComponentCount = 0;
  FMaxComponentCount = DEFAULT_MAX_COMPONENTS;
  FComponents = new ZComponent *[DEFAULT_MAX_COMPONENTS];
}
__fastcall ZComponent::~ZComponent()
{
  DestroyComponents();
  delete []FComponents;
}
//private
void __fastcall ZComponent::ChangeIndex(ZComponent *Component, int Index)
{
  if(Index < 0 || Index >= FComponentCount)
    return;
  int i = IndexOf(Component);
  if(i == Index)
    return;
  if(i > Index)
    memmove(&FComponents[Index + 1], &FComponents[Index], sizeof(ZComponent *) * (i - Index));
  else
    memmove(&FComponents[i], &FComponents[i + 1], sizeof(ZComponent *) * (Index - i));
  FComponents[Index] = Component;
}
int __fastcall ZComponent::IndexOf(ZComponent *Component)
{
  for(int i = 0; i < FComponentCount; i++)
    if(Component == FComponents[i])
      return i;
  return INVALID_INDEX_VALUE;
}
int __fastcall ZComponent::GetComponentIndex()
{
  if(FOwner)
    return FOwner->IndexOf(this);
  return INVALID_INDEX_VALUE;
}
void __fastcall ZComponent::SetComponentIndex(int Index)
{
  if(FOwner)
    FOwner->ChangeIndex(this, Index);
}
ZComponent *__fastcall ZComponent::GetComponent(int Index)
{
  if(Index < 0 || Index >= FComponentCount)
    return NULL;
  return FComponents[Index];
}
//protected
#pragma argsused
bool __fastcall ZComponent::ValidateInsert(ZComponent* AComponent)
{
  return true;
}
void __fastcall ZComponent::AssignTo(ZComponent* Dest)
{
  Dest->Assign(this);
}
ZComponent* __fastcall ZComponent::GetOwner(void)
{
  return FOwner;
}
//public
void __fastcall ZComponent::DestroyComponents(void)
{
  for(int i = 0; i < FComponentCount; i++)
  {
    delete FComponents[i];
    FComponents[i] = NULL;
  }
}
void __fastcall ZComponent::InsertComponent(ZComponent* AComponent)
{
  if(!ValidateInsert(AComponent) || IndexOf(AComponent) != INVALID_INDEX_VALUE)
    return;
  if(FComponentCount == FMaxComponentCount)
  {
    FMaxComponentCount <<= 1;
    ZComponent **p = new ZComponent *[FMaxComponentCount];
    memcpy(p, FComponents, sizeof(ZComponent *) * FComponentCount);
    delete []FComponents;
    FComponents = p;
  }
  FComponents[FComponentCount] = AComponent;
  FComponentCount++;
}
void __fastcall ZComponent::RemoveComponent(ZComponent* AComponent)
{
  int i = IndexOf(AComponent);
  if(i == INVALID_INDEX_VALUE)
    return;
  delete FComponents[i];
  memmove(&FComponents[i], &FComponents[i + 1], sizeof(ZComponent *) * (FComponentCount - i - 1));
  //TODO: change AComponent->Onwer property
}
void __fastcall ZComponent::Assign(ZComponent* Source)
{
  int count = Source->ComponentCount;
  if(count > FMaxComponentCount)
  {
    FMaxComponentCount = count << 1;
    //TODO: change AComponent->Onwer property of all components
    delete []FComponents;
    FComponents = new ZComponent *[FMaxComponentCount];
  }
  for(int i = 0; i < count; i++)
    FComponents[i] = Source->Components[i];
  //TODO: change AComponent->Onwer property of all new components
  FComponentCount = count;
}
