#include <windows.h>

#ifndef LFC_H_DEFINED
#define LFC_H_DEFINED



typedef struct WindowsParams {
	HWND hwnd;
	LPARAM lparam;
	WPARAM wparam;
	UINT msg;
} WINDOWSPARAMS;


// DIALOGBOX
typedef struct ST_dialogbox {
	struct ST_dialogbox_lpVtbl *lpVtbl;
	WINDOWSPARAMS *WindowsParams;
	struct ST_dialogbox_private *Data;
} ST_DIALOGBOX;

// Communs
typedef struct ST_control {
	void *lpVtbl;
	WINDOWSPARAMS *WindowsParams;
	void *Data;
} ST_CONTROL;

// USERCONTROL
typedef struct ST_usercontrol {
	struct ST_usercontrol_lpVtbl *lpVtbl;
	WINDOWSPARAMS *WindowsParams;
	struct ST_usercontrol_private *Data;
} ST_USERCONTROL;

// LISTBOX
typedef struct ST_listbox {
	struct ST_listbox_lpVtbl *lpVtbl;
	WINDOWSPARAMS *WindowsParams;
	struct ST_listbox_private *Data;
} ST_LISTBOX;

// COMBOBOX
typedef struct ST_combobox {
	struct ST_combobox_lpVtbl *lpVtbl;
	WINDOWSPARAMS *WindowsParams;
	struct ST_combobox_private *Data;
} ST_COMBOBOX;

// EDIT
typedef struct ST_edit {
	struct ST_edit_lpVtbl *lpVtbl;
	WINDOWSPARAMS *WindowsParams;
	struct ST_edit_private *Data;
} ST_EDIT;

// MULEDIT
typedef struct ST_muledit {
	struct ST_muledit_lpVtbl *lpVtbl;
	WINDOWSPARAMS *WindowsParams;
	struct ST_muledit_private *Data;
} ST_MULEDIT;

// BUTTON
typedef struct ST_button {
	struct ST_button_lpVtbl *lpVtbl;
	WINDOWSPARAMS *WindowsParams;
	struct ST_button_private *Data;
} ST_BUTTON;

// CHECKBOX
typedef struct ST_chechbox {
	struct ST_checkbox_lpVtbl *lpVtbl;
	WINDOWSPARAMS *WindowsParams;
	struct ST_checkbox_private *Data;
} ST_CHECKBOX;

// RADIOBUTTON
typedef struct ST_radiobutton {
	struct ST_radiobutton_lpVtbl *lpVtbl;
	WINDOWSPARAMS *WindowsParams;
	struct ST_radiobutton_private *Data;
} ST_RADIOBUTTON;

// SCROLLBAR
typedef struct ST_scrollbar {
	struct ST_scrollbar_lpVtbl *lpVtbl;
	WINDOWSPARAMS *WindowsParams;
	struct ST_scrollbar_private *Data;
} ST_SCROLLBAR;

// LISTVIEW
typedef struct ST_listview {
	struct ST_listview_lpVtbl *lpVtbl;
	WINDOWSPARAMS *WindowsParams;
	struct ST_listview_private *Data;
} ST_LISTVIEW;

// TABCTRL
typedef struct ST_tabctrl {
	struct ST_tabctrl_lpVtbl *lpVtbl;
	WINDOWSPARAMS *WindowsParams;
	struct ST_tabctrl_private *Data;
} ST_TABCTRL;

// TREECTRL
typedef struct ST_treectrl {
	struct ST_treectrl_lpVtbl *lpVtbl;
	WINDOWSPARAMS *WindowsParams;
	struct ST_treectrl_private *Data;
} ST_TREECTRL;

// MONTHCAL
typedef struct ST_monthcal {
	struct ST_monthcal_lpVtbl *lpVtbl;
	WINDOWSPARAMS *WindowsParams;
	struct ST_monthcal_private *Data;
} ST_MONTHCAL;

// DATE
typedef struct ST_date {
	struct ST_date_lpVtbl *lpVtbl;
	WINDOWSPARAMS *WindowsParams;
	struct ST_date_private *Data;
} ST_DATE;

// PROGRESS
typedef struct ST_progress {
	struct ST_progress_lpVtbl *lpVtbl;
	WINDOWSPARAMS *WindowsParams;
	struct ST_progress_private *Data;
} ST_PROGRESS;

// SPINBUTTON
typedef struct ST_spinbutton {
	struct ST_spinbutton_lpVtbl *lpVtbl;
	WINDOWSPARAMS *WindowsParams;
	struct ST_spinbutton_private *Data;
} ST_SPINBUTTON;

// SLIDER
typedef struct ST_slider {
	struct ST_slider_lpVtbl *lpVtbl;
	WINDOWSPARAMS *WindowsParams;
	struct ST_slider_private *Data;
} ST_SLIDER;

// STATIC
typedef struct ST_static {
	struct ST_static_lpVtbl *lpVtbl;
	WINDOWSPARAMS *WindowsParams;
	struct ST_static_private *Data;
} ST_STATIC;

#ifndef LFC_IMPL_H_DEFINED
#include <lfc_impl.h>
#endif

#endif

