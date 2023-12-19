#pragma once
#include "framework.h"

// Global Variables:

inline constexpr int MAX_LOADSTRING = 100;

bool				g_isPhotoVisible	= true;			 // To check if photo is visible
COLORREF			g_textColor			= RGB(0, 0, 0);  // Text default color (black)
HFONT				g_hFont				= nullptr;		 // Text font

HWND				g_hSubMenuWindow;					      // sub window
HINSTANCE			hInst;                                    // current instance
WCHAR				szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR				szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
// Message handler for app
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
// Message handler for about box
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
// Message handler for about feature1
INT_PTR CALLBACK    File(HWND, UINT, WPARAM, LPARAM);

// Feature1 invoke functions
void				case_2(HWND& g_hSubMenuWindow);
void				case_3(HWND& g_hSubMenuWindow);
void				case_4(HWND& g_hSubMenuWindow);