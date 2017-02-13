#include <windows.h>

#ifndef LFC_IMPL_H_DEFINED
#define LFC_IMPL_H_DEFINED

#ifndef LFC_H_DEFINED
#include "lfc.h"
#endif

#define ST_COMMONFUNCTIONS \
	int (*Enable)(void *self,int bEnable);						\
	int (*GetWindowText)(void *self, char *outbuf, int NbMax);	\
	int (*GetWindowTextLength)(void *self);						\
	int (*InvalidateRect)(void *self, CONST RECT *Rect, int bErase);	\
	int (*IsWindowEnabled)(void *self);							\
	int (*IsWindowVisible)(void *self);							\
	int (*MoveWindow)(void *self, int X, int Y, int Width, int Height, int bRepaint); \
	void (*SetFont)(void *self, HFONT Font, int bRedraw);		\
	int (*SetWindowText)(void *self, char *text);				\
	int (*ShowWindow)(void *self, int bShow);					\
	int (*UpdateWindow)(void *self);							\
	int (*GetClientRect)(void *self, RECT *pRect);				\
	int (*GetWindowRect)(void *self, RECT *pRect);				\
	HWND (*SetFocus)(void *self);								\
	HWND (*GetHwnd)(void *self)

// Utilitaires
ST_DIALOGBOX * ST_InitDialogBox(HWND hDlg);
void ST_DestroyDialogBox(HWND hwnd);
ST_DIALOGBOX *GetSTControlFromHwnd(HWND hwnd);
void * GetControl(ST_DIALOGBOX *DialogBox, int IDControl);
void *XGC_malloc(size_t size);

// DIALOGBOX
ST_DIALOGBOX * NewST_dialogbox(HWND hDlg);

typedef struct ST_dialogbox_lpVtbl {
	ST_COMMONFUNCTIONS;
	char *(*StructCtrl)(ST_DIALOGBOX *self);
	char *Name;
} ST_dialogbox_vtable;

struct ST_dialogbox_private {
	int NbControls;
	void **ST_Controls;
	void *pDlgStruct;
};

// USERCONTROL
ST_USERCONTROL * NewST_usercontrol(HWND hwnd);

typedef struct ST_usercontrol_lpVtbl {
	// Standard
	ST_COMMONFUNCTIONS;
	char *(*StructCtrl)(ST_USERCONTROL *self);
	char *Name;
} ST_usercontrol_vtable;

struct ST_usercontrol_private {
	void *dummy;
};

// LISTBOX
ST_LISTBOX * NewST_listbox(HWND hwnd);

typedef struct ST_listbox_lpVtbl {
	// Standard
	ST_COMMONFUNCTIONS;

	// Spécifique
	int (*GetCurSel)(ST_LISTBOX *self);
	int (*SetCurSel)(ST_LISTBOX *self,int Selection);
	int (*GetAnchorIndex)(ST_LISTBOX *self);
	int (*GetCaretIndex)(ST_LISTBOX *self);
	int (*AddString)(ST_LISTBOX *self,char *line);
	int (*InsertString)(ST_LISTBOX *self,int Position,char *line);
	int (*GetCount)(ST_LISTBOX *self);
	int (*DeleteString)(ST_LISTBOX *self,int Position);
	void (*ResetContent)(ST_LISTBOX *self);
	int (*GetText)(ST_LISTBOX *self,int Position,char *outbuf);
	int (*GetTextLen)(ST_LISTBOX *self,int Position);
	int (*GetSelCount)(ST_LISTBOX *self);
	int (*GetSelItems)(ST_LISTBOX *self,int NbOfItems,int *ItemNumbers);
	int (*GetTopIndex)(ST_LISTBOX *self);
	int (*SetTopIndex)(ST_LISTBOX *self,int Position);
	int (*SelectString)(ST_LISTBOX *self,int StartAfter,char *line);
	int (*SelItemRange)(ST_LISTBOX *self,int bSelect,int FirstItem,int LastItem);
	int (*SetSel)(ST_LISTBOX *self,int Position,int bSelect);
	int (*FindString)(ST_LISTBOX *self,int StartAfter,char *line);
	int (*FindStringExact)(ST_LISTBOX *self,int StartAfter,char *line);
	int (*GetHorizontalExtent)(ST_LISTBOX *self);
	int (*GetItemHeight)(ST_LISTBOX *self, int Index); // Index=0 si pas ownerdraw
	int (*GetItemRect)(ST_LISTBOX *self, int Index, RECT *pRect);
	int (*GetSel)(ST_LISTBOX *self, int Index);
	int (*ItemFromPoint)(ST_LISTBOX *self, POINT pt, int *bOutside);
	int (*SetAnchorIndex)(ST_LISTBOX *self, int Index);
	int (*SetCaretIndex)(ST_LISTBOX *self, int Index, int bScroll);
	void (*SetColumnWidth)(ST_LISTBOX *self, int Width);
	void (*SetHorizontalExtent)(ST_LISTBOX *self, int CXExtent);
	int (*SetItemHeight)(ST_LISTBOX *self, int Index, int Height);
	int (*SetTabStops)(ST_LISTBOX *self, int nTabStops, int *TabArray);
	char *(*StructCtrl)(ST_LISTBOX *self);
	char *Name;
	// ajouter GetAllText par rapport à mfc avec \r\n
	// id pour SetText, XML pour tree
} ST_listbox_vtable;

struct ST_listbox_private {
	void *dummy;
};

// COMBOBOX
ST_COMBOBOX * NewST_combobox(HWND hwnd);

typedef struct ST_combobox_lpVtbl {
	// Standard
	ST_COMMONFUNCTIONS;

	// Spécifique
	int (*GetCurSel)(ST_COMBOBOX *self);
	int (*SetCurSel)(ST_COMBOBOX *self,int Selection);
	int (*AddString)(ST_COMBOBOX *self,char *line);
	int (*InsertString)(ST_COMBOBOX *self,int Position,char *line);
	int (*GetCount)(ST_COMBOBOX *self);
	int (*DeleteString)(ST_COMBOBOX *self,int Position);
	int (*ResetContent)(ST_COMBOBOX *self);
	int (*GetLBText)(ST_COMBOBOX *self,int Position,char *outbuf);
	int (*GetLBTextLen)(ST_COMBOBOX *self,int Position);
	int (*GetTopIndex)(ST_COMBOBOX *self);
	int (*SetTopIndex)(ST_COMBOBOX *self,int Position);
	int (*SelectString)(ST_COMBOBOX *self,int StartAfter,char *line);
	int (*FindString)(ST_COMBOBOX *self,int StartAfter,char *line);
	int (*FindStringExact)(ST_COMBOBOX *self,int StartAfter,char *line);
	void (*ClearSelection)(ST_COMBOBOX *self);
	int (*GetDroppedState)(ST_COMBOBOX *self);
	int (*ShowDropDown)(ST_COMBOBOX *self,int fShow);
	int (*LimitText)(ST_COMBOBOX *self,int Limit);
	int (*GetEditSel)(ST_COMBOBOX *self, int *pStart, int *pEnd);
	int (*SetEditSel)(ST_COMBOBOX *self,int Start,int End);
//	int (*GetMinVisible)(ST_COMBOBOX *self);
	int (*GetDroppedWidth)(ST_COMBOBOX *self);
	int (*SetDroppedWidth)(ST_COMBOBOX *self, int Width);
	int (*GetItemHeight)(ST_COMBOBOX *self, int Index);
	int (*SetItemHeight)(ST_COMBOBOX *self, int Index, int Height);
//	int (*SetMinVisible)(ST_COMBOBOX *self, int Min);
	char *(*StructCtrl)(ST_COMBOBOX *self);
	char *Name;
} ST_combobox_vtable;

struct ST_combobox_private {
	void *dummy;
};

// EDIT
ST_EDIT * NewST_edit(HWND hwnd);

typedef struct ST_edit_lpVtbl {
	// Standard
	ST_COMMONFUNCTIONS;

	// Spécifique
	void (*ClearSelection)(ST_EDIT *self);
	int (*GetLimitText)(ST_EDIT *self);
	int (*GetModify)(ST_EDIT *self);
	int (*GetSel)(ST_EDIT *self, int *pStart, int *pEnd);
	void (*SetLimitText)(ST_EDIT *self, int Limit);
	void (*SetModify)(ST_EDIT *self, int bModified);
	void (*SetPasswordChar)(ST_EDIT *self, char Char);
	int (*SetReadOnly)(ST_EDIT *self, int bReadOnly);
	void (*SetSel)(ST_EDIT *self, int Start, int End, int bNoScroll);
	int (*Undo)(ST_EDIT *self);
	int (*CanUndo)(ST_EDIT *self);
	int (*CharFromPos)(ST_EDIT *self, POINT pt);
	void (*EmptyUndoBuffer)(ST_EDIT *self);
	int (*GetMargins)(ST_EDIT *self, int *pLeft, int *pRight);
	char (*GetPasswordChar)(ST_EDIT *self);
	void (*GetRect)(ST_EDIT *self, RECT *pRect);
	POINT (*PosFromChar)(ST_EDIT *self, int Index);
	void (*ReplaceSel)(ST_EDIT *self, char *NewText, int bCanUndo);
//	int (*SetCueBanner)(ST_EDIT *self, char *Text);
	void (*SetMargins)(ST_EDIT *self, int Left, int Right);
	void (*ScrollCaret)(ST_EDIT *self);
	char *(*StructCtrl)(ST_EDIT *self);
	char *Name;
} ST_edit_vtable;

struct ST_edit_private {
	void *dummy;
};

// MULEDIT
ST_MULEDIT * NewST_muledit(HWND hwnd);

typedef struct ST_muledit_lpVtbl {
	// Standard
	ST_COMMONFUNCTIONS;

	// Commun avec edit
	int (*Clear)(void *self);
	int (*GetLimitText)(void *self);
	int (*GetModify)(void *self);
	int (*GetSel)(void *self, int *pStart, int *pEnd);
	int (*SetLimitText)(void *self, int Limit);
	int (*SetModify)(void *self, int bModified);
	int (*SetPasswordChar)(void *self, char Char);
	int (*SetReadOnly)(void *self, int bReadOnly);
	int (*SetSel)(void *self, int Start, int End, int bNoScroll);
	int (*Undo)(void *self);
	int (*CanUndo)(void *self);
	int (*CharFromPos)(void *self, POINT pt);
	void (*EmptyUndoBuffer)(void *self);
	int (*GetMargins)(void *self, int *pLeft, int *pRight);
	char (*GetPasswordChar)(void *self);
	void (*GetRect)(void *self, RECT *pRect);
	POINT (*PosFromChar)(void *self, int Index);
	void (*ReplaceSel)(void *self, char *NewText, int bCanUndo);
//	int (*SetCueBanner)(void *self, char *Text);
	void (*SetMargins)(void *self, int Left, int Right);
	void (*ScrollCaret)(void *self);

	// Spécifique
	int (*FmtLines)(ST_MULEDIT *self, int bAddEOL);
	int (*GetFirstVisibleLine)(ST_MULEDIT *self);
	int (*GetLine)(ST_MULEDIT *self, int LineNr, char *outbuf, int NbMax);
	int (*GetLineCount)(ST_MULEDIT *self);
	int (*LineFromChar)(ST_MULEDIT *self, int Index);
	int (*LineIndex)(ST_MULEDIT *self, int Line);
	int (*LineLength)(ST_MULEDIT *self, int Line);
	int (*LineScroll)(ST_MULEDIT *self, int Lines, int Chars);
	int (*Scroll)(ST_MULEDIT *self, int Action);
	int (*SetTabStops)(ST_MULEDIT *self, int nTabs, int *TabArray);
	char *(*StructCtrl)(ST_MULEDIT *self);
	char *Name;
} ST_muledit_vtable;

struct ST_muledit_private {
	void *dummy;
};

// BUTTON
ST_BUTTON * NewST_button(HWND hwnd);

typedef struct ST_button_lpVtbl {
	// Standard
	ST_COMMONFUNCTIONS;

	// Spécifique
	HANDLE (*GetImage)(ST_BUTTON *self, int Type);
	HBITMAP (*GetBitmap)(ST_BUTTON *self);
	HICON (*GetIcon)(ST_BUTTON *self);
	int (*GetState)(ST_BUTTON *self);
	int (*Click)(ST_BUTTON *self);
	HANDLE (*SetImage)(ST_BUTTON *self, int Type, HANDLE Image);
	HBITMAP (*SetBitmap)(ST_BUTTON *self, HBITMAP Bitmap);
	HICON (*SetIcon)(ST_BUTTON *self, HICON Icon);
	int (*SetState)(ST_BUTTON *self, int State);
	char *(*StructCtrl)(ST_BUTTON *self);
	char *Name;
} ST_button_vtable;

struct ST_button_private {
	void *dummy;
};

// CHECKBOX
ST_CHECKBOX * NewST_checkbox(HWND hwnd);

typedef struct ST_checkbox_lpVtbl {
	// Standard
	ST_COMMONFUNCTIONS;

	// Spécifique
	int (*GetCheck)(ST_CHECKBOX *self);
	int (*GetState)(ST_CHECKBOX *self);
	int (*GetStyle)(ST_CHECKBOX *self);
	int (*SetCheck)(ST_CHECKBOX *self, int Check);
	int (*SetState)(ST_CHECKBOX *self, int State);
	int (*SetStyle)(ST_CHECKBOX *self, int Style);
	char *(*StructCtrl)(ST_CHECKBOX *self);
	char *Name;
} ST_checkbox_vtable;

struct ST_checkbox_private {
	void *dummy;
};

// RADIOBUTTON
ST_RADIOBUTTON * NewST_radiobutton(HWND hwnd);

typedef struct ST_radiobutton_lpVtbl {
	// Standard
	ST_COMMONFUNCTIONS;

	// Spécifique
	int (*GetCheck)(ST_RADIOBUTTON *self);
	int (*GetState)(ST_RADIOBUTTON *self);
	int (*GetStyle)(ST_RADIOBUTTON *self);
	int (*SetCheck)(ST_RADIOBUTTON *self, int Check);
	int (*SetState)(ST_RADIOBUTTON *self, int State);
	int (*SetStyle)(ST_RADIOBUTTON *self, int Style);
	char *(*StructCtrl)(ST_RADIOBUTTON *self);
	char *Name;
} ST_radiobutton_vtable;

struct ST_radiobutton_private {
	void *dummy;
};

// SCROLLBAR
ST_SCROLLBAR * NewST_scrollbar(HWND hwnd);

typedef struct ST_scrollbar_lpVtbl {
	// Standard
	ST_COMMONFUNCTIONS;

	// Spécifique
	int (*EnableScrollbar)(ST_SCROLLBAR *self, int Arrows);
	int (*GetInfo)(ST_SCROLLBAR *self, SCROLLINFO *lpsi);
	int (*GetPos)(ST_SCROLLBAR *self);
	int (*GetRange)(ST_SCROLLBAR *self, int *pMin, int *pMax);
	int (*SetInfo)(ST_SCROLLBAR *self, SCROLLINFO *lpsi, int bRedraw);
	int (*SetPos)(ST_SCROLLBAR *self, int Pos, int bRedraw);
	int (*SetRange)(ST_SCROLLBAR *self, int Min, int Max, int bRedraw);
	int (*ShowScrollbar)(ST_SCROLLBAR *self, int bShow);
	int (*EnableArrows)(ST_SCROLLBAR *self, int Option);
	char *(*StructCtrl)(ST_SCROLLBAR *self);
	char *Name;
} ST_scrollbar_vtable;

struct ST_scrollbar_private {
	void *dummy;
};

// LISTVIEW
ST_LISTVIEW * NewST_listview(HWND hwnd);

typedef struct ST_listview_lpVtbl {
	// Standard
	ST_COMMONFUNCTIONS;

	// Spécifique
	int (*Arrange)(ST_LISTVIEW *self, int Code);
	int (*DeleteAllItems)(ST_LISTVIEW *self);
	int (*DeleteColumn)(ST_LISTVIEW *self, int iColumn);
	int (*DeleteItem)(ST_LISTVIEW *self, int iItem);
	HWND (*EditLabel)(ST_LISTVIEW *self, int iItem);
	int (*EnsureVisible)(ST_LISTVIEW *self, int iItem, int bPartialOK);
	int (*FindItem)(ST_LISTVIEW *self, int Start, LV_FINDINFO *lvfi);
	int (*GetBkColor)(ST_LISTVIEW *self);
	int (*GetCallbackMask)(ST_LISTVIEW *self);
	int (*GetColumn)(ST_LISTVIEW *self, int iCol, LV_COLUMN *pCol);
	int (*GetColumnWidth)(ST_LISTVIEW *self, int iCol);
	int (*GetCountPerPage)(ST_LISTVIEW *self);
	HWND (*GetEditControl)(ST_LISTVIEW *self);
	HIMAGELIST (*GetImageList)(ST_LISTVIEW *self, int Type);
	int (*GetItem)(ST_LISTVIEW *self, LV_ITEM *pItem);
	int (*GetItemCount)(ST_LISTVIEW *self);
	int (*GetItemPosition)(ST_LISTVIEW *self, int iItem, POINT *pt);
	int (*GetItemSpacing)(ST_LISTVIEW *self, int bSmall);
	int (*GetItemState)(ST_LISTVIEW *self, int iItem, int Mask);
	int (*GetItemText)(ST_LISTVIEW *self, int iItem, int iSubItem, char *outbuf, int NbChar);
	int (*GetNextItem)(ST_LISTVIEW *self, int Start, int Flags);
	int (*GetOrigin)(ST_LISTVIEW *self, POINT *pt);
	int (*GetSelectedCount)(ST_LISTVIEW *self);
	int (*GetStringWidth)(ST_LISTVIEW *self, char *Text);
	COLORREF (*GetTextBkColor)(ST_LISTVIEW *self);
	COLORREF (*GetTextColor)(ST_LISTVIEW *self);
	int (*GetTopIndex)(ST_LISTVIEW *self);
	int (*HitTest)(ST_LISTVIEW *self, LV_HITTESTINFO *pInfo);
	int (*InsertColumn)(ST_LISTVIEW *self, int iCol, LV_COLUMN *pCol);
	int (*InsertItem)(ST_LISTVIEW *self, LV_ITEM *Item);
	int (*RedrawItems)(ST_LISTVIEW *self, int First, int Last);
	int (*Scroll)(ST_LISTVIEW *self, int dx, int dy);
	int (*SetBkColor)(ST_LISTVIEW *self, COLORREF Color);
	int (*SetCallbackMask)(ST_LISTVIEW *self, int Mask);
	int (*SetColumn)(ST_LISTVIEW *self, int iCol, LV_COLUMN *pCol);
	int (*SetColumnWidth)(ST_LISTVIEW *self, int iCol, int cx);
	HIMAGELIST (*SetImageList)(ST_LISTVIEW *self, HIMAGELIST ImageList, int Type);
	int (*SetItem)(ST_LISTVIEW *self, LV_ITEM *Item);
	void (*SetItemCount)(ST_LISTVIEW *self, int Count);
	void (*SetItemPosition)(ST_LISTVIEW *self, int iItem, int x, int y);
	int (*SetItemState)(ST_LISTVIEW *self, int iItem, int State, int Mask);
	int (*SetItemText)(ST_LISTVIEW *self, int iItem, int iSubItem, char *Text);
	int (*SetTextBkColor)(ST_LISTVIEW *self, COLORREF Color);
	int (*SetTextColor)(ST_LISTVIEW *self, COLORREF Color);
	int (*SortItems)(ST_LISTVIEW *self, PFNLVCOMPARE pfnCompare, int ParamSort);
	int (*Update)(ST_LISTVIEW *self, int iItem);
	char *(*StructCtrl)(ST_LISTVIEW *self);
	char *Name;
} ST_listview_vtable;

struct ST_listview_private {
	void *dummy;
};

// TABCTRL
ST_TABCTRL * NewST_tabctrl(HWND hwnd);

typedef struct ST_tabctrl_lpVtbl {
	// Standard
	ST_COMMONFUNCTIONS;

	// Spécifique
	void (*AdjustRect)(ST_TABCTRL *self, int bLargeur, RECT *Rect);
	int (*DeleteAllItems)(ST_TABCTRL *self);
	int (*DeleteItem)(ST_TABCTRL *self, int iItem);
	int (*GetCurFocus)(ST_TABCTRL *self);
	int (*GetCurSel)(ST_TABCTRL *self);
	HIMAGELIST (*GetImageList)(ST_TABCTRL *self);
	int (*GetItem)(ST_TABCTRL *self, int iItem, TC_ITEM *Item);
	int (*GetItemCount)(ST_TABCTRL *self);
	int (*GetItemRect)(ST_TABCTRL *self, int iItem, RECT *Rect);
	int (*GetRowCount)(ST_TABCTRL *self);
	HWND (*GetToolTips)(ST_TABCTRL *self);
	int (*HitTest)(ST_TABCTRL *self, TC_HITTESTINFO *pInfo);
	int (*InsertItem)(ST_TABCTRL *self, int iItem, TC_ITEM *pItem);
	void (*RemoveImage)(ST_TABCTRL *self, int iImage);
	void (*SetCurFocus)(ST_TABCTRL *self, int iItem);
	int (*SetCurSel)(ST_TABCTRL *self, int iItem);
	HIMAGELIST (*SetImageList)(ST_TABCTRL *self, HIMAGELIST himl);
	int (*SetItem)(ST_TABCTRL *self, int iItem, TC_ITEM *pItem);
	int (*SetItemExtra)(ST_TABCTRL *self, int nBytes);
	int (*SetItemSize)(ST_TABCTRL *self, int cx, int cy);
	void (*SetPadding)(ST_TABCTRL *self, int cx, int cy);
	void (*SetToolTips)(ST_TABCTRL *self, HWND hwndTT);
	char *(*StructCtrl)(ST_TABCTRL *self);
	char *Name;
} ST_tabctrl_vtable;

struct ST_tabctrl_private {
	void *dummy;
};

// TREECTRL
ST_TREECTRL * NewST_treectrl(HWND hwnd);

typedef struct ST_treectrl_lpVtbl {
	// Standard
	ST_COMMONFUNCTIONS;

	// Spécifique
	HIMAGELIST (*CreateDragImage)(ST_TREECTRL *self, HTREEITEM hItem);
	int (*DeleteAllItems)(ST_TREECTRL *self);
	int (*DeleteItem)(ST_TREECTRL *self, HTREEITEM hItem);
	HWND (*EditLabel)(ST_TREECTRL *self, HTREEITEM hItem);
	int (*EndEditLabelNow)(ST_TREECTRL *self, int bCancel);
	int (*EnsureVisible)(ST_TREECTRL *self, HTREEITEM hItem);
	int (*Expand)(ST_TREECTRL *self, HTREEITEM hItem, int Flag);
	HTREEITEM (*GetChild)(ST_TREECTRL *self, HTREEITEM hItem);
	int (*GetCount)(ST_TREECTRL *self);
	HTREEITEM (*GetDropHilite)(ST_TREECTRL *self);
	HWND (*GetEditControl)(ST_TREECTRL *self);
	HTREEITEM (*GetFirstVisibleItem)(ST_TREECTRL *self);
	int (*GetImageList)(ST_TREECTRL *self, int Type);
	int (*GetIndent)(ST_TREECTRL *self);
	int (*GetISearchString)(ST_TREECTRL *self, char *outbuf);
	int (*GetItem)(ST_TREECTRL *self, TV_ITEM *pItem);
	int (*GetItemRect)(ST_TREECTRL *self, HTREEITEM hItem, RECT *Rect, int bTextOnly);
	int (*GetItemState)(ST_TREECTRL *self, HTREEITEM hItem, int Mask);
	int (*GetItemText)(ST_TREECTRL *self, HTREEITEM hItem, char *outbuf, int NbChar);
	HTREEITEM (*GetNextItem)(ST_TREECTRL *self, HTREEITEM hItem, int Flag);
	HTREEITEM (*GetNextSibling)(ST_TREECTRL *self, HTREEITEM hItem);
	HTREEITEM (*GetNextVisible)(ST_TREECTRL *self, HTREEITEM hItem);
	HTREEITEM (*GetParent)(ST_TREECTRL *self, HTREEITEM hItem);
	HTREEITEM (*GetPrevSibling)(ST_TREECTRL *self, HTREEITEM hItem);
	HTREEITEM (*GetPrevVisible)(ST_TREECTRL *self, HTREEITEM hItem);
	HTREEITEM (*GetRoot)(ST_TREECTRL *self);
	HTREEITEM (*GetSelected)(ST_TREECTRL *self);
	int (*GetVisibleCount)(ST_TREECTRL *self);
	HTREEITEM (*HitTest)(ST_TREECTRL *self, TV_HITTESTINFO *pInfo);
	HTREEITEM (*InsertItem)(ST_TREECTRL *self, TV_INSERTSTRUCT *pInsItem);
	int (*HasChildren)(ST_TREECTRL *self, HTREEITEM hItem);
	int (*Select)(ST_TREECTRL *self, HTREEITEM hItem, int Flag);
	int (*SelectDropTarget)(ST_TREECTRL *self, HTREEITEM hItem);
	int (*SelectItem)(ST_TREECTRL *self, HTREEITEM hItem);
	int (*SelectSetFirstVisible)(ST_TREECTRL *self, HTREEITEM hItem);
	HIMAGELIST (*SetImageList)(ST_TREECTRL *self, HIMAGELIST Image, int Type);
	void (*SetIndent)(ST_TREECTRL *self, int Indent);
	int (*SetItem)(ST_TREECTRL *self, TV_ITEM *pItem);
	int (*SetItemState)(ST_TREECTRL *self, HTREEITEM hItem, int State, int Mask);
	int (*SetItemText)(ST_TREECTRL *self, HTREEITEM hItem, char *Text);
	int (*SortChildren)(ST_TREECTRL *self, HTREEITEM hItem, int bRecurse);
	int (*SortChildrenCB)(ST_TREECTRL *self, TV_SORTCB *pSort, int bRecurse);
	char *(*StructCtrl)(ST_TREECTRL *self);
	char *Name;
} ST_treectrl_vtable;

struct ST_treectrl_private {
	void *dummy;
};

// MONTHCAL
ST_MONTHCAL * NewST_monthcal(HWND hwnd);

typedef struct ST_monthcal_lpVtbl {
	// Standard
	ST_COMMONFUNCTIONS;

	// Spécifique
	COLORREF (*GetColor)(ST_MONTHCAL *self, int Region);
	int (*GetCurSel)(ST_MONTHCAL *self, SYSTEMTIME *pDate);
	int (*GetFirstDayOfWeek)(ST_MONTHCAL *self);
	int (*GetMaxSelCount)(ST_MONTHCAL *self);
	int (*GetMaxTodayWidth)(ST_MONTHCAL *self);
	int (*GetMinReqRect)(ST_MONTHCAL *self, RECT *Rect);
	int (*GetMonthDelta)(ST_MONTHCAL *self);
	int (*GetMonthRange)(ST_MONTHCAL *self, int Flag, SYSTEMTIME *pDateArray);
	int (*GetRange)(ST_MONTHCAL *self, SYSTEMTIME *pDateArray);
	int (*GetSelRange)(ST_MONTHCAL *self, SYSTEMTIME *pDateArray);
	int (*GetToday)(ST_MONTHCAL *self, SYSTEMTIME *pDate);
	int (*HitTest)(ST_MONTHCAL *self, MCHITTESTINFO *pInfo);
	COLORREF (*SetColor)(ST_MONTHCAL *self, int Flag, COLORREF Color);
	int (*SetCurSel)(ST_MONTHCAL *self, SYSTEMTIME *pDate);
	int (*SetDayState)(ST_MONTHCAL *self, int NbMonths, MONTHDAYSTATE *pDayStateArray);
	int (*SetFirstDayOfWeek)(ST_MONTHCAL *self, int iDay);
	int (*SetMaxSelCount)(ST_MONTHCAL *self, int Max);
	int (*SetMonthDelta)(ST_MONTHCAL *self, int Delta);
	int (*SetRange)(ST_MONTHCAL *self, int WhichLimit, SYSTEMTIME *pDateArray);
	int (*SetSelRange)(ST_MONTHCAL *self, SYSTEMTIME *pDateArray);
	void (*SetToday)(ST_MONTHCAL *self, SYSTEMTIME *pDate);
	char *(*StructCtrl)(ST_MONTHCAL *self);
	char *Name;
} ST_monthcal_vtable;

struct ST_monthcal_private {
	void *dummy;
};

// DATE
ST_DATE * NewST_date(HWND hwnd);

typedef struct ST_date_lpVtbl {
	// Standard
	ST_COMMONFUNCTIONS;

	// Spécifique
	COLORREF (*GetColor)(ST_DATE *self, int Region);
	HFONT (*GetDateFont)(ST_DATE *self);
	HWND (*GetMonthCal)(ST_DATE *self);
	int (*GetRange)(ST_DATE *self, SYSTEMTIME *pDateArray);
	int (*GetSystemTime)(ST_DATE *self, SYSTEMTIME *pDate);
	int (*SetFormat)(ST_DATE *self, SYSTEMTIME *Format);
	COLORREF (*SetColor)(ST_DATE *self, int Region, COLORREF Color);
	void (*SetDateFont)(ST_DATE *self, HFONT Font, int Redraw);
	int (*SetRange)(ST_DATE *self, int Flags, SYSTEMTIME *pDateArray);
	int (*SetSystemTime)(ST_DATE *self, int Flag, SYSTEMTIME *pDate);
	char *(*StructCtrl)(ST_DATE *self);
	char *Name;
} ST_date_vtable;

struct ST_date_private {
	void *dummy;
};

// PROGRESS
ST_PROGRESS * NewST_progress(HWND hwnd);

typedef struct ST_progress_lpVtbl {
	// Standard
	ST_COMMONFUNCTIONS;

	// Spécifique
	int (*DeltaPos)(ST_PROGRESS *self, int Increment);
	int (*GetPos)(ST_PROGRESS *self);
	int (*GetRange)(ST_PROGRESS *self, int *Lower, int *Upper);
	COLORREF (*SetBarColor)(ST_PROGRESS *self, COLORREF Color);
	COLORREF (*SetBkColor)(ST_PROGRESS *self, COLORREF Color);
	int (*SetPos)(ST_PROGRESS *self, int NewPos);
	int (*SetRange)(ST_PROGRESS *self, int LowLim, int HighLim);
	int (*SetStep)(ST_PROGRESS *self, int Step);
	int (*StepIt)(ST_PROGRESS *self);
	char *(*StructCtrl)(ST_PROGRESS *self);
	char *Name;
} ST_progress_vtable;

struct ST_progress_private {
	void *dummy;
};

// SPINBUTTON
ST_SPINBUTTON * NewST_spinbutton(HWND hwnd);

typedef struct ST_spinbutton_lpVtbl {
	// Standard
	ST_COMMONFUNCTIONS;

	// Spécifique
	int (*GetAccel)(ST_SPINBUTTON *self, int nAccel, UDACCEL *pAccelArray);
	int (*GetBase)(ST_SPINBUTTON *self);
	HWND (*GetBuddy)(ST_SPINBUTTON *self);
	int (*GetPos)(ST_SPINBUTTON *self); // 0x8000 si erreur
	int (*GetRange)(ST_SPINBUTTON *self, int *pLow, int *pHigh);
	int (*SetAccel)(ST_SPINBUTTON *self, int nAccel, UDACCEL *pAccelArray);
	int (*SetBase)(ST_SPINBUTTON *self, int Base);
	HWND (*SetBuddy)(ST_SPINBUTTON *self, HWND Buddy);
	int (*SetPos)(ST_SPINBUTTON *self, int Pos);
	void (*SetRange)(ST_SPINBUTTON *self, int Low, int High);
	char *(*StructCtrl)(ST_SPINBUTTON *self);
	char *Name;
} ST_spinbutton_vtable;

struct ST_spinbutton_private {
	void *dummy;
};

// SLIDER
ST_SLIDER * NewST_slider(HWND hwnd);

typedef struct ST_slider_lpVtbl {
	// Standard
	ST_COMMONFUNCTIONS;

	// Spécifique
	void (*ClearSel)(ST_SLIDER *self, int bRedraw);
	void (*ClearTics)(ST_SLIDER *self, int bRedraw);
//	HWND (*GetBuddy)(ST_SLIDER *self, int bLocation);
	void (*GetChannelRect)(ST_SLIDER *self, RECT *pRect);
	int (*GetLineSize)(ST_SLIDER *self);
	int (*GetNumTics)(ST_SLIDER *self);
	int (*GetPageSize)(ST_SLIDER *self);
	int (*GetPos)(ST_SLIDER *self);
	int (*GetRange)(ST_SLIDER *self, int *pMin, int *pMax);
	int (*GetRangeMax)(ST_SLIDER *self);
	int (*GetRangeMin)(ST_SLIDER *self);
	int (*GetSelection)(ST_SLIDER *self, int *pStart, int *pEnd);
	int (*GetSelEnd)(ST_SLIDER *self);
	int (*GetSelStart)(ST_SLIDER *self);
	int (*GetThumbLength)(ST_SLIDER *self);
	void (*GetThumbRect)(ST_SLIDER *self, RECT *pRect);
	int (*GetTic)(ST_SLIDER *self, int iTic);
	int *(*GetTicArray)(ST_SLIDER *self);
	int (*GetTicPos)(ST_SLIDER *self, int iTic);
//	HWND (*GetToolTips)(ST_SLIDER *self);
//	int (*SetBuddy)(ST_SLIDER *self, HWND Buddy, int bLocation);
	int (*SetLineSize)(ST_SLIDER *self, int Size);
	int (*SetPageSize)(ST_SLIDER *self, int Size);
	void (*SetPos)(ST_SLIDER *self, int Pos, int bRedraw);
	void (*SetRange)(ST_SLIDER *self, int Min, int Max, int bRedraw);
	void (*SetRangeMax)(ST_SLIDER *self, int Max, int bRedraw);
	void (*SetRangeMin)(ST_SLIDER *self, int Min, int bRedraw);
	void (*SetSelection)(ST_SLIDER *self, int Min, int Max, int bRedraw);
	void (*SetThumbLength)(ST_SLIDER *self, int Length);
	int (*SetTic)(ST_SLIDER *self, int Position);
	void (*SetTicFreq)(ST_SLIDER *self, int Freq);
//	int (*SetTipSide)(ST_SLIDER *self, int Location);
//	void (*SetToolTips)(ST_SLIDER *self, HWND hToolTips);
	char *(*StructCtrl)(ST_SLIDER *self);
	char *Name;
} ST_slider_vtable;

struct ST_slider_private {
	void *dummy;
};

// STATIC
ST_STATIC * NewST_static(HWND hwnd);

typedef struct ST_static_lpVtbl {
	// Standard
	ST_COMMONFUNCTIONS;

	// Spécifique
	HICON (*GetIcon)(ST_STATIC *self);
	HANDLE (*GetImage)(ST_STATIC *self, int Type);
	HBITMAP (*GetBitmap)(ST_STATIC *self);
	HCURSOR (*GetCursor)(ST_STATIC *self);
	HENHMETAFILE (*GetEnhMetaFile)(ST_STATIC *self);
	HICON (*SetIcon)(ST_STATIC *self, HICON Icon);
	HANDLE (*SetImage)(ST_STATIC *self, int Type, HANDLE Image);
	HBITMAP (*SetBitmap)(ST_STATIC *self, HBITMAP Bitmap);
	HCURSOR (*SetCursor)(ST_STATIC *self, HCURSOR Cursor);
	HENHMETAFILE (*SetEnhMetaFile)(ST_STATIC *self, HENHMETAFILE MetaFile);
	char *(*StructCtrl)(ST_STATIC *self);
	char *Name;
} ST_static_vtable;

struct ST_static_private {
	void *dummy;
};

#endif

