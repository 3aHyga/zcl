#include "zobject.h"
#include "zcomponent.h"


//public
__fastcall ZObject::ZObject()
{
}
__fastcall ZObject::~ZObject()
{
}
void __fastcall ZObject::MessageHandler(ZCommand *Command)
{
}

//public
__fastcall ZComplexObject::ZComplexObject(ZComponent *Owner)
{
  FOwner = Owner;
}
__fastcall ZComplexObject::~ZComplexObject()
{
}


