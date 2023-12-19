// WindowsProject5.cpp : Defines the entry point for the application.
//

#include "Implementation.h"


_Use_decl_annotations_ int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR  lpCmdLine, int nCmdShow) {
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    WNDCLASSEX  wndclass{};
    ULONG_PTR   gdiplusToken;

    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT5, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance(hInstance, nCmdShow))
        return FALSE;
    
    // Defining an Accelerator Table
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT5));

    MSG msg;
    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0)) {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}



////
////  FUNCTION: MyRegisterClass()
////
////  PURPOSE: Registers the window class.
////
//ATOM MyRegisterClass(HINSTANCE hInstance) {
//    WNDCLASSEXW wcex{};
//
//    wcex.cbSize = sizeof(WNDCLASSEX);
//
//    wcex.style = CS_HREDRAW | CS_VREDRAW;
//    wcex.lpfnWndProc = WndProc;
//    wcex.cbClsExtra = 0;
//    wcex.cbWndExtra = 0;
//    wcex.hInstance = hInstance;
//    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT5));
//    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
//    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT5);
//    wcex.lpszClassName = szWindowClass;
//    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
//
//    return RegisterClassExW(&wcex);
//}
//
////
////   FUNCTION: InitInstance(HINSTANCE, int)
////
////   PURPOSE: Saves instance handle and creates main window
////
////   COMMENTS:
////
////        In this function, we save the instance handle in a global variable and
////        create and display the main program window.
////
//BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) {
//    hInst = hInstance; // Store instance handle in our global variable
//
//    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
//        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
//
//    if (!hWnd)
//        return FALSE;
//
//    ShowWindow(hWnd, nCmdShow);
//    UpdateWindow(hWnd);
//
//    return TRUE;
//}
//
////
////  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
////
////  PURPOSE: Processes messages for the main window.
////
////  WM_COMMAND  - process the application menu
////  WM_PAINT    - Paint the main window
////  WM_DESTROY  - post a quit message and return
////
////
//LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
//    static int   cxClient, cyClient;
//    HDC          hdc;
//    PAINTSTRUCT  ps;
//
//    constexpr int xpos = 100;            // Horizontal position of the window.
//    constexpr int ypos = 100;            // Vertical position of the window.
//    constexpr int nwidth = 200;          // Width of the window
//    constexpr int nheight = 200;         // Height of the window
//
//    switch (message) {
//    case WM_CREATE: {
//        break;
//    }
//    case WM_COMMAND: {
//        int wmId = LOWORD(wParam);
//        g_hSubMenuWindow = CreateWindowW(_T("STATIC"), L"Default Menu",
//            WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 400, 300,
//            nullptr, nullptr, nullptr, nullptr);
//        // Parse the menu selections:
//        switch (wmId) {
//        case IDM_ABOUT: {
//            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
//            break;
//        }
//        case IDM_H1: {
//            PostMessage(hWnd, WM_SYSCOMMAND, SC_MAXIMIZE, 0);
//            break;
//        }
//        case IDM_H2: {
//            PostMessage(hWnd, WM_SYSCOMMAND, SC_MINIMIZE, 0);
//
//            break;
//        }
//        case IDM_H3: {
//            PostMessage(hWnd, WM_SYSCOMMAND, SC_RESTORE, 0);
//            break;
//        }
//
//                   /*completed*/
//        case IDM_11: {
//            CHOOSEFONT cf;
//            LOGFONT lf;
//
//            ZeroMemory(&cf, sizeof(cf));
//            ZeroMemory(&lf, sizeof(lf));
//
//            cf.lStructSize = sizeof(cf);
//            cf.hwndOwner = hWnd;
//            cf.lpLogFont = &lf;
//            cf.Flags = CF_SCREENFONTS | CF_EFFECTS;
//
//            if (ChooseFont(&cf)) {
//                // User selected a new font, so update the global font variable
//                if (g_hFont) {
//                    DeleteObject(g_hFont);
//                }
//                g_hFont = CreateFontIndirect(&lf);
//
//                // Invalidate the window to trigger a repaint
//                InvalidateRect(hWnd, nullptr, TRUE);
//            }
//
//            break;
//        }
//        case IDM_22: {
//            //DialogBox(hInst, MAKEINTRESOURCE(), hWnd, ...);
//            g_textColor = RGB(255, 0, 0);
//
//            // Repaint the window
//            InvalidateRect(hWnd, nullptr, TRUE);
//            break;
//        }
//        case IDM_33: {
//            //DialogBox(hInst, MAKEINTRESOURCE(), hWnd, ...);
//            InvalidateRect(hWnd, nullptr, TRUE);
//
//            break;
//        }
//        case IDM_44: {
//            // Toggle visibility of the photo window
//            g_isPhotoVisible = !g_isPhotoVisible;
//
//            // Trigger a repaint to apply the visibility change
//            InvalidateRect(hWnd, nullptr, TRUE);
//            break;
//        }
//
//                   /*      completed       */
//        case IDM_1: {
//            DialogBox(hInst, MAKEINTRESOURCE(IDD_FILE), hWnd, File);
//            HWND chckBox = CreateWindowW(_T("BUTTON"), _T("Checkbox"), WS_OVERLAPPEDWINDOW | BS_AUTOCHECKBOX, CW_USEDEFAULT, CW_USEDEFAULT, 80, 50, g_hSubMenuWindow, nullptr, nullptr, nullptr);
//            ShowWindow(chckBox, SW_SHOWNORMAL);
//            break;
//        }
//        case IDM_2: {
//            DialogBox(hInst, MAKEINTRESOURCE(IDD_FILE), hWnd, File);
//            HWND hWndComboBox = CreateWindowW(WC_COMBOBOX, TEXT(""),
//                CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_VISIBLE,
//                xpos, ypos, nwidth, nheight, g_hSubMenuWindow, nullptr, nullptr,
//                nullptr);
//            case_2(hWndComboBox);
//            ShowWindow(g_hSubMenuWindow, SW_SHOWNORMAL);
//            break;
//        }
//        case IDM_3: {
//            DialogBox(hInst, MAKEINTRESOURCE(IDD3_FILE), hWnd, File);
//            case_3(g_hSubMenuWindow);
//            ShowWindow(g_hSubMenuWindow, SW_SHOWNORMAL);
//            break;
//        }
//        case IDM_4: {
//            DialogBox(hInst, MAKEINTRESOURCE(IDD4_FILE), hWnd, File);
//            case_4(g_hSubMenuWindow);
//            ShowWindow(g_hSubMenuWindow, SW_SHOWNORMAL);
//            break;
//        }
//                  
//
//        case IDM_EXIT: {
//            DestroyWindow(hWnd);
//            break;
//        }
//        case IDM_OPEN: {
//            // Use the common file dialog to let the user choose a file
//            OPENFILENAME ofn;
//            wchar_t szFileName[MAX_PATH] = L"";
//
//            ZeroMemory(&ofn, sizeof(ofn));
//            ofn.lStructSize = sizeof(ofn);
//            ofn.hwndOwner = hWnd;
//            ofn.lpstrFile = szFileName;
//            ofn.nMaxFile = sizeof(szFileName) / sizeof(*szFileName);
//            ofn.lpstrFilter = L"All Files\0*.*\0";
//            ofn.nFilterIndex = 1;
//            ofn.lpstrFileTitle = nullptr;
//            ofn.nMaxFileTitle = 0;
//            ofn.lpstrInitialDir = nullptr;
//            ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
//
//            if (GetOpenFileName(&ofn)) {
//                // User selected a file, attempt to open and read its content
//                std::filesystem::path filePath(szFileName);
//
//                try {
//                    // Open the file using std::wifstream (wide string stream)
//                    std::wifstream fileStream(filePath);
//
//                    if (fileStream.is_open()) {
//                        // Read the file content
//                        std::wstring fileContent((std::istreambuf_iterator<wchar_t>(fileStream)),
//                            std::istreambuf_iterator<wchar_t>());
//
//                        // Now you have the file content in the 'fileContent' wstring.
//                        // You can use it as needed, for example, display it in a MessageBox.
//                        MessageBox(hWnd, fileContent.c_str(), L"File Content", MB_OK | MB_ICONINFORMATION);
//
//                        // Close the file stream
//                        fileStream.close();
//                    }
//                    else {
//                        MessageBox(hWnd, L"Unable to open the file.", L"Error", MB_OK | MB_ICONERROR);
//                    }
//                }
//                catch (const std::exception& e) {
//                    MessageBoxA(hWnd, e.what(), "Exception", MB_OK | MB_ICONERROR);
//                }
//            }
//
//            break;
//        }
//        case IDM_OPT1: {
//            //DialogBox(hInst, MAKEINTRESOURCE(), hWnd, ...);
//            PostMessage(hWnd, WM_MOUSEWHEEL, SC_MOVE, 0);
//
//            break;
//        }
//        case IDM_OPT2: {
//            //DialogBox(hInst, MAKEINTRESOURCE(), hWnd, ...);
//            break;
//        }
//        default:
//            return DefWindowProc(hWnd, message, wParam, lParam);
//        }
//        break;
//    }
//
//    case WM_PAINT: {
//        hdc = BeginPaint(hWnd, &ps);
//
//        // Select the font into the device context
//        HFONT hOldFont = (HFONT)SelectObject(hdc, g_hFont);
//        
//        // Draw text above the image
//        SetTextColor(hdc, g_textColor);
//        SetBkMode(hdc, TRANSPARENT);
//
//
//        // Specify the position and text you want to display
//        RECT textRect = { 10, 10, 300, 30 }; // Adjust the coordinates and dimensions as needed
//        LPCWSTR labelText = L"It's me"; // Replace with the desired text
//
//        // Draw the text
//        DrawText(hdc, labelText, -1, &textRect, DT_SINGLELINE | DT_LEFT);
//
//        if (g_isPhotoVisible) {
//            Gdiplus::Graphics graphic1(hdc);
//            Gdiplus::Image image1(L"C:/Users/windows11/source/repos/WindowsProject5/pfp2.png");
//            graphic1.DrawImage(&image1, 500, 80, 800, 600); // Adjust the coordinates as needed
//
//        }
//
//
//        // Clean up: Select the old font back into the device context
//        SelectObject(hdc, hOldFont);
//
//        EndPaint(hWnd, &ps);
//        break;
//    }
//
//    case WM_DESTROY: {
//        PostQuitMessage(0);
//        break;
//    }
//    default:
//        return DefWindowProc(hWnd, message, wParam, lParam);
//    }
//    return 0;
//}
//
//// Message handler for about box.
//INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
//    UNREFERENCED_PARAMETER(lParam);
//    switch (message) {
//    case WM_INITDIALOG:
//        return (INT_PTR)TRUE;
//
//    case WM_COMMAND:
//        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
//            EndDialog(hDlg, LOWORD(wParam));
//            return (INT_PTR)TRUE;
//        }
//        break;
//    }
//    return (INT_PTR)FALSE;
//}
//
//INT_PTR CALLBACK File(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
//    UNREFERENCED_PARAMETER(lParam);
//    switch (message) {
//    case WM_INITDIALOG:
//        return (INT_PTR)TRUE;
//    case WM_COMMAND:
//        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
//            EndDialog(hDlg, LOWORD(wParam));
//            return (INT_PTR)TRUE;
//        }
//        break;
//    }
//    return (INT_PTR)FALSE;
//}
//
//void case_2(HWND& hWndComboBox) {
//    // load the combobox with item list.
//    TCHAR Planets[9][10] = {
//        TEXT("Mercury"), TEXT("Venus"), TEXT("Earth"), TEXT("Mars"),
//        TEXT("Jupiter"), TEXT("Saturn"), TEXT("Uranus"), TEXT("Neptune"),
//        TEXT("Pluto")
//    };
//
//    TCHAR A[16] = {};
//    for (int k{}; k <= 8; ++k) {
//        wcscpy_s(A, sizeof(A) / sizeof(TCHAR), (TCHAR*)Planets[k]);
//        // Add string to combobox.
//        SendMessage(hWndComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)A);
//    }
//
//    // Send the CB_SETCURSEL message to display an initial item in the selection field
//    SendMessage(hWndComboBox, CB_SETCURSEL, (WPARAM)2, (LPARAM)0);
//}
//
//void case_3(HWND& g_hSubMenuWindow) {
//    HWND hList = CreateWindowW(_T("ListBox"), _T(""), WS_CHILD | WS_VISIBLE | LBS_NOTIFY | WS_BORDER | WS_VSCROLL, 40, 40, 250, 60, g_hSubMenuWindow, (HMENU)ID_LISTBOX, nullptr, nullptr);
//
//    SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)"1");
//    SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)"2");
//    SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)"3");
//    SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)"4");
//    SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)"5");
//}
//
//void case_4(HWND& g_hSubMenuWindow) {
//    HWND editCtlHandle = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 100, 100, 200, 20, g_hSubMenuWindow, nullptr, nullptr, nullptr);
//}