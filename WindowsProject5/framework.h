// header.h : include file for standard system include files,
// or project specific include files
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// Project using libraries
#include <olectl.h>
#include <gdiplus.h>
#include <gdiplusenums.h>
#include <CommCtrl.h>
#include <mshtmhst.h>
#include <commdlg.h>
#include <filesystem>
#include <fstream>
#pragma comment (lib, "comctl32.lib")
#pragma comment (lib, "Gdiplus.lib") 