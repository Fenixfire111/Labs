// 08-Lab(Win).cpp : Определяет точку входа для приложения.
//

#include "pch.h"
#include "framework.h"
#include "08-Lab(Win).h"
#include "string"
#include "map"
#include "windows.h"
#include "cmath"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.




    // 222TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY08LABWIN, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY08LABWIN));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY08LABWIN));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY08LABWIN);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
#define _USE_MATH_DEFINES
const int R = 100;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

    PAINTSTRUCT ps;
    HDC hdc;
    static int sx, sy, NUM = 25;
    int a, b;		//Экранные координаты
    double angle;
    static int x, y;
    static double time = 0.0;
    static double r, i;
    static HPEN hpenr = CreatePen(PS_DOT, 2, RGB(0, 0, 0));
    static HPEN hpen2 = CreatePen(PS_SOLID, 5, RGB(50, 100, 150));
    static HPEN hpen3 = CreatePen(PS_SOLID, 2, RGB(10, 100, 50));
    static HBRUSH brush = CreateSolidBrush(RGB(10, 100, 50));
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Разобрать выбор в меню:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;

    case WM_SIZE:
        sx = LOWORD(lParam); 	//Ширина окна
        sy = HIWORD(lParam);	//Высота окна
        break;

    case WM_CREATE:
        SetTimer(hWnd, 1, 100, NULL);

    case WM_TIMER:
        time += 0.1;
        if (time >= 2 * 3.14) {
            KillTimer(hWnd, 1);
        }
        InvalidateRect(hWnd, NULL, TRUE);
    case WM_PAINT:
    {
        hdc = BeginPaint(hWnd, &ps);
        a = sx / 2;     b = sy / 2;
        MoveToEx(hdc, 0, b, NULL);
        LineTo(hdc, sx, b);
        MoveToEx(hdc, a, 0, NULL);
        LineTo(hdc, a, sy);
        MoveToEx(hdc, a, b, NULL);

        MoveToEx(hdc, sx, b, NULL);
        LineTo(hdc, sx - 20, b + 20);
        MoveToEx(hdc, sx, b, NULL);
        LineTo(hdc, sx - 20, b - 20);

        MoveToEx(hdc, a, 0, NULL);
        LineTo(hdc, a + 20, 20);
        MoveToEx(hdc, a, 0, NULL);
        LineTo(hdc, a - 20, 20);

        for (int i = 0; i < NUM; i++)
        {
            SelectObject(hdc, hpenr);
            MoveToEx(hdc, i * sx / NUM, b + 10, NULL);
            LineTo(hdc, i * sx / NUM, b - 10);
            MoveToEx(hdc, a + 10, sy - i * sy / NUM, NULL);
            LineTo(hdc, a - 10, sy - i * sy / NUM);

        }
        
        SelectObject(hdc, hpen2);

        MoveToEx(hdc, a, b, NULL);

        for (i = 0.0; i < time; i += 0.05) {
            r = sin(3 * i / 7);
            x = (int)(r * cos(i) * 100);
            y = (int)(r * sin(i) * 100);
            LineTo(hdc, a + x, b - y);
        }
        
        SelectObject(hdc, hpen3);
        SelectObject(hdc, brush);
        Ellipse(hdc, a + x - 10, b - y - 10, a + x + 10, b - y + 10);


        double X = x;
        double Y = y;
        auto text = std::to_string(X) + ", " + std::to_string(Y);
        auto rect = RECT{ 10, 10, 200, 100 };
        std::wstring stemp = std::wstring(text.begin(), text.end());
        LPCWSTR sw = stemp.c_str();
        static LOGFONT lf;
        HFONT hFont = CreateFontIndirect(&lf);
        SetTextColor(hdc, RGB(50, 150, 50));
        DrawText(hdc, sw, -1, &rect, DT_BOTTOM);

 /*       DeleteObject(hpenr);
        DeleteObject(hpen2);
        DeleteObject(hpen3);
        DeleteObject(brush);*/
        EndPaint(hWnd, &ps);
    }
        break;

    case WM_DESTROY:
        KillTimer(hWnd, 1);
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;
    }
    return 0;
}


// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
