#ifndef _WINCONTROLH_

#include "zcomponent.hpp"

class package ZWinControl;
class ZWinControl : ZComponent
{
  typedef inherited ZComponent;
private:
protected:
DYNAMIC void __fastcall AdjustSize(void); //autosize resizing
virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
DYNAMIC void __fastcall BeginAutoDrag(void);
virtual bool __fastcall CanAutoSize(int &NewWidth, int &NewHeight);
virtual bool __fastcall CanResize(int &NewWidth, int &NewHeight);
void __fastcall Changed(void);
DYNAMIC void __fastcall ChangeScale(int M, int D);
DYNAMIC void __fastcall Click(void);
virtual void __fastcall ConstrainedResize(int &MinWidth, int &MinHeight, int &MaxWidth, int &MaxHeight);
DYNAMIC void __fastcall DblClick(void);
DYNAMIC void __fastcall DefaultDockImage(TDragDockObject* DragDockObject, bool Erase);
DYNAMIC void __fastcall DockTrackNoTarget(TDragDockObject* Source, int X, int Y);
DYNAMIC void __fastcall DoContextPopup(const Types::TPoint &MousePos, bool &Handled);
DYNAMIC void __fastcall DoDock(TWinControl* NewDockSite, Types::TRect &ARect);
DYNAMIC void __fastcall DoEndDock(System::TObject* Target, int X, int Y);
DYNAMIC void __fastcall DoEndDrag(System::TObject* Target, int X, int Y);
DYNAMIC bool __fastcall DoMouseWheel(Classes::TShiftState Shift, int WheelDelta, const Types::TPoint &MousePos);
DYNAMIC bool __fastcall DoMouseWheelDown(Classes::TShiftState Shift, const Types::TPoint &MousePos);
DYNAMIC bool __fastcall DoMouseWheelUp(Classes::TShiftState Shift, const Types::TPoint &MousePos);
DYNAMIC void __fastcall DoStartDock(TDragObject* &DragObject);
DYNAMIC void __fastcall DoStartDock(TDragObject* &DragObject);
DYNAMIC void __fastcall DragCanceled(void);
DYNAMIC void __fastcall DragOver(System::TObject* Source, int X, int Y, TDragState State, bool &Accept);
DYNAMIC void __fastcall DrawDragDockImage(TDragDockObject* DragDockObject);
DYNAMIC void __fastcall EraseDragDockImage(TDragDockObject* DragDockObject);
virtual Types::TPoint __fastcall GetClientOrigin(void);
virtual Types::TRect __fastcall GetClientRect(void);
DYNAMIC TAlign __fastcall GetDockEdge(const Types::TPoint &MousePos);
virtual TDragImageList* __fastcall GetDragImages(void);
virtual bool __fastcall GetEnabled(void);
virtual bool __fastcall GetFloating(void);
virtual TMetaClass* __fastcall GetFloatingDockSiteClass(void);
DYNAMIC HPALETTE __fastcall GetPalette(void);
DYNAMIC Menus::TPopupMenu* __fastcall GetPopupMenu(void);
DYNAMIC void __fastcall MouseDown(TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
DYNAMIC void __fastcall MouseUp(TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
DYNAMIC bool __fastcall PaletteChanged(bool Foreground);
DYNAMIC void __fastcall PositionDockRect(TDragDockObject* DragDockObject);
DYNAMIC void __fastcall RequestAlign(void);
DYNAMIC void __fastcall Resize(void);
void __fastcall SendCancelMode(TControl* Sender);
virtual void __fastcall SetBiDiMode(Classes::TBiDiMode Value);
virtual void __fastcall SetDragMode(TDragMode Value);
virtual void __fastcall SetEnabled(bool Value);
virtual void __fastcall SetParent(TWinControl* AParent);
virtual void __fastcall SetParentBiDiMode(bool Value);
DYNAMIC void __fastcall SetParentComponent(Classes::TComponent* Value);
DYNAMIC void __fastcall SetZOrder(bool TopMost);
void __fastcall UpdateBoundsRect(const Types::TRect &R);
DYNAMIC void __fastcall VisibleChanging(void);

public:
  __fastcall ZWinControl(ZComponent *Owner);
  virtual __fastcall ~ZWinControl();
  virtual void __fastcall Assign(ZComponent* Source);
  __property bool AutoScroll = {read=FAutoScroll, write=SetAutoScroll, default=1};
//  __property TControlScrollBar* HorzScrollBar = {read=FHorzScrollBar, write=SetHorzScrollBar};
//  __property TControlScrollBar* VertScrollBar = {read=FVertScrollBar, write=SetVertScrollBar};
__property bool AlignDisabled = {read=GetAlignDisabled, nodefault};
__property Graphics::TBrush* Brush = {read=FBrush};
__property Types::TPoint ClientOrigin = {read=GetClientOrigin};
__property Types::TRect ClientRect = {read=GetClientRect};
__property int ControlCount = {read=GetControlCount, nodefault};
__property TControl* Controls[int Index] = {read=GetControl};
__property int DockClientCount = {read=GetDockClientCount, nodefault};
__property TControl* DockClients[int Index] = {read=GetDockClients};
__property bool DoubleBuffered = {read=FDoubleBuffered, write=FDoubleBuffered, nodefault};
__property HWND Handle = {read=GetHandle, nodefault};
__property HWND ParentWindow = {read=FParentWindow, write=SetParentWindow, nodefault};
__property bool Showing = {read=FShowing, nodefault};
typedef short TTabOrder;
__property TTabOrder TabOrder = {read=GetTabOrder, write=SetTabOrder, default=-1};
__property bool TabStop = {read=FTabStop, write=SetTabStop, default=0};
__property int VisibleDockClientCount = {read=GetVisibleDockClientCount};

__property TAlign Align = {read=FAlign, write=SetAlign, default=0};
__property TAnchors Anchors = {read=FAnchors, write=SetAnchors, stored=IsAnchorsStored, default=3};
__property Classes::TBiDiMode BiDiMode = {read=FBiDiMode, write=SetBiDiMode, stored=IsBiDiModeStored, nodefault};
__property Types::TRect BoundsRect = {read=GetBoundsRect, write=SetBoundsRect};
__property int ClientHeight = {read=GetClientHeight, write=SetClientHeight, stored=false, nodefault};
__property int ClientWidth = {read=GetClientWidth, write=SetClientWidth, stored=false, nodefault};
__property TSizeConstraints* Constraints = {read=FConstraints, write=SetConstraints};
enum Controls__01 { csLButtonDown, csClicked, csPalette, csReadingState, csAlignmentNeeded, csFocusing, csCreating, csPaintCopy, csCustomPaint, csDestroyingHandle, csDocking };
typedef Set<Controls__01, csLButtonDown, csDocking>  TControlState;
__property TControlState ControlState = {read=FControlState, write=FControlState, nodefault
enum Controls__11 { csAcceptsControls, csCaptureMouse, csDesignInteractive, csClickEvents, csFramed, csSetCaption, csOpaque, csDoubleClicks, csFixedWidth, csFixedHeight, csNoDesignVisible, csReplicatable, csNoStdEvents, csDisplayDragImage, csReflector, csActionClient, csMenuEvents };
typedef Set<Controls__11, csAcceptsControls, csMenuEvents> TControlStyle;
__property TControlStyle ControlStyle = {read=FControlStyle, write=FControlStyle, nodefault};
__property TCursor Cursor = {read=FCursor, write=SetCursor, default=0};
__property TDockOrientation DockOrientation = {read=FDockOrientation, write
=FDockOrientation, nodefault };
__property bool Enabled = {read=GetEnabled, write=SetEnabled, stored=IsEnabledStored, default=1};
__property bool Floating = {read=GetFloating, nodefault};
__property TMetaClass* FloatingDockSiteClass = {read=GetFloatingDockSiteClass, write
=FFloatingDockSiteClass};
__property int Height = {read=FHeight, write=SetHeight, nodefault};
__property Classes::THelpContext HelpContext = {read=FHelpContext, write=SetHelpContext, stored=IsHelpContextStored, default=0};
__property AnsiString HelpKeyword = {read=FHelpKeyword, write=SetHelpKeyword, stored
=IsHelpContextStored};
__property Classes::THelpType HelpType = {read=FHelpType, write=FHelpType, default=1};
__property AnsiString Hint = {read=FHint, write=FHint, stored=IsHintStored};
__property TWinControl* HostDockSite = {read=FHostDockSite, write=SetHostDockSite};
__property int Left = {read=FLeft, write=SetLeft, nodefault};
__property int LRDockWidth = {read=GetLRDockWidth, write=FLRDockWidth, nodefault};
__property TWinControl* Parent = {read=FParent, write=SetParent};
__property TWinControl* Parent = {read=FParent, write=SetParent};
__property bool ShowHint = {read=FShowHint, write=SetShowHint, stored=IsShowHintStored, nodefault};
__property int TBDockHeight = {read=GetTBDockHeight, write=FTBDockHeight, nodefault};
__property int Top = {read=FTop, write=SetTop, nodefault};
__property int UndockHeight = {read=GetUndockHeight, write=FUndockHeight, nodefault};
__property int UndockWidth = {read=GetUndockWidth, write=FUndockWidth, nodefault};
__property bool Visible = {read=FVisible, write=SetVisible, stored=IsVisibleStored };
__property int Width = {read=FWidth, write=SetWidth, nodefault};
//__property Classes::TWndMethod WindowProc = {read=FWindowProc, write=FWindowProc};

void __fastcall BeginDrag(bool Immediate, int Threshold = -1);
void __fastcall BringToFront(void);
TPoint __fastcall ClientToParent(const TPoint Point, TWinControl *AParent = (TWinControl*) NULL);
Types::TPoint __fastcall ClientToScreen(const Types::TPoint &Point);
__fastcall virtual TControl(Classes::TComponent* AOwner);
__fastcall virtual ~TControl(void);
DYNAMIC void __fastcall Dock(TWinControl* NewDockSite, const Types::TRect &ARect);
DYNAMIC void __fastcall DragDrop(System::TObject* Source, int X, int Y);
bool __fastcall Dragging(void);
int __fastcall DrawTextBiDiModeFlags(int Flags);
int __fastcall DrawTextBiDiModeFlagsReadingOnly(void);
void __fastcall EndDrag(bool Drop);
DYNAMIC Classes::TAlignment __fastcall GetControlsAlignment(void);
DYNAMIC Classes::TComponent* __fastcall GetParentComponent(void);
DYNAMIC bool __fastcall HasParent(void);
void __fastcall Hide(void);
virtual void __fastcall InitiateAction(void);
virtual void __fastcall Invalidate(void);
bool __fastcall IsRightToLeft(void);
bool __fastcall ManualDock(TWinControl* NewDockSite, TControl* DropControl = (TControl*) NULL, TAlign ControlSide = alNone);
bool __fastcall ManualFloat(const Types::TRect &ScreenPos);
Types::TPoint __fastcall ParentToClient(const Types::TPoint &Point, TWinControl* AParent = (TWinControl*) NULL);
int __fastcall Perform(unsigned Msg, int WParam, int LParam);
void __fastcall Refresh(void);
virtual void __fastcall Repaint(void);
bool __fastcall ReplaceDockedControl(TControl* Control, TWinControl* NewDockSite, TControl* DropControl, TAlign ControlSide);
Types::TPoint __fastcall ScreenToClient(const Types::TPoint &Point);
void __fastcall SendToBack(void);
virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
void __fastcall Show(void);
virtual void __fastcall Update(void);
DYNAMIC bool __fastcall UseRightToLeftAlignment(void);
bool __fastcall UseRightToLeftReading(void);
bool __fastcall UseRightToLeftScrollBar(void);

};

#endif
