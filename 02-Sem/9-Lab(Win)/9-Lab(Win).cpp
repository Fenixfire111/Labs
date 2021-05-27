
#include "pch.h"
#include "framework.h"
#include <vector>
#include <exception>
#include "resource.h"
#include <windowsx.h>
#define MAX_LOADSTRING 100

POINT mouse;
RECT rect;
bool timer = true;

class State
{
    bool _isAlive;

public:
    State(bool isAlive)
    {
        _isAlive = isAlive;
    }

    bool IsAlive()
    {
        return _isAlive;
    }

    void SetIsAlive(bool isAlive)
    {
        _isAlive = isAlive;
    }
};

class Cell
{
    State _state = State(false);

public:
    Cell(State state)
    {
        _state = state;
    }

    Cell()
    {

    }

    bool IsAlive()
    {
        return _state.IsAlive();
    }

    void SetIsAlive(bool isAlive)
    {
        _state.SetIsAlive(isAlive);
    }
};

class Grid
{
    std::vector<std::vector<Cell>> _cells;
    int _width;
    int _height;

public:
    Grid(int width, int height) : _width(width), _height(height)
    {
        _cells.resize(height);

        for (auto rowIndex = 0; rowIndex < height; ++rowIndex)
        {
            _cells[rowIndex].resize(width);
        }
    }

    int GetWidth()
    {
        return _width;
    }

    int GetHeight()
    {
        return _height;
    }

    Cell& GetCell(int rowIndex, int columnIndex)
    {
        if (rowIndex < 0 || rowIndex >= _height) throw std::exception("Wrong rowIndex");
        if (columnIndex < 0 || columnIndex >= _width) throw std::exception("Wrong columnIndex");

        return _cells[rowIndex][columnIndex];
    }
};

class LifeEngine
{
public:
    Grid CalculateNext(Grid currentGrid)
    {
        auto newGrid = Grid(currentGrid.GetWidth(), currentGrid.GetHeight());

        auto distance = 1;

        for (auto rowIndex = 0; rowIndex < currentGrid.GetHeight(); ++rowIndex)
        {
            for (auto columnIndex = 0; columnIndex < currentGrid.GetWidth(); ++columnIndex)
            {
                auto aliveCellCount = CalculateAliveNeighbour(rowIndex, columnIndex, currentGrid, distance);

                if (aliveCellCount == 3 && !currentGrid.GetCell(rowIndex, columnIndex).IsAlive())
                {
                    newGrid.GetCell(rowIndex, columnIndex).SetIsAlive(true);
                }
                else if ((aliveCellCount == 2 || aliveCellCount == 3) && currentGrid.GetCell(rowIndex, columnIndex).IsAlive())
                {
                    newGrid.GetCell(rowIndex, columnIndex).SetIsAlive(true);
                }
                else
                {
                    newGrid.GetCell(rowIndex, columnIndex).SetIsAlive(false);
                }
            }
        }

        return newGrid;
    }

    Grid SizeGrid(Grid grid, int xs, int ys) {
        Grid newGrid = Grid(xs, ys);
        for (int j = 0; j < xs; ++j) {
            for (int i = 0; i < ys; ++i) {
                if (j < grid.GetWidth() && i < grid.GetHeight()) {
                    newGrid.GetCell(i, j).SetIsAlive(grid.GetCell(i, j).IsAlive());
                }
                else {
                    newGrid.GetCell(i, j).SetIsAlive(false);
                }
            }
        }
        return newGrid;
    }

private:
    int GetLeftStartIndex(int columnIndex, int distance)
    {
        return max(columnIndex - distance, 0);
    }

    int GetTopStartIndex(int rowIndex, int distance)
    {
        return max(rowIndex - distance, 0);
    }

    int GetRightStartIndex(int columnIndex, int gridWidth, int distance)
    {
        return min(columnIndex + distance, gridWidth - 1);
    }

    int GetBottomStartIndex(int rowIndex, int gridHeight, int distance)
    {
        return min(rowIndex + distance, gridHeight - 1);
    }

    int CalculateAliveNeighbour(int rowIndex, int columnIndex, Grid currentGrid, int distance)
    {
        auto aliveCellCount = 0;

        auto leftStartIndex = GetLeftStartIndex(columnIndex, distance);
        auto rightStartIndex = GetRightStartIndex(columnIndex, currentGrid.GetWidth(), distance);
        auto topStartIndex = GetTopStartIndex(rowIndex, distance);
        auto bottomStartIndex = GetBottomStartIndex(rowIndex, currentGrid.GetHeight(), distance);

        for (auto neighbourColumnIndex = leftStartIndex; neighbourColumnIndex <= rightStartIndex; ++neighbourColumnIndex)
        {
            for (auto neighbourRowIndex = topStartIndex; neighbourRowIndex <= bottomStartIndex; ++neighbourRowIndex)
            {
                if (rowIndex == neighbourRowIndex && columnIndex == neighbourColumnIndex) continue;

                if (currentGrid.GetCell(neighbourRowIndex, neighbourColumnIndex).IsAlive())
                {
                    ++aliveCellCount;
                }
            }
        }

        return aliveCellCount;
    }
};

Grid grid = Grid(10, 10);
LifeEngine lifeEngine;

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
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

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY9LABWIN, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY9LABWIN));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY9LABWIN));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_MY9LABWIN);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // Store instance handle in our global variable

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

void DrawGrid(HWND hWnd, HDC hdc)
{
    
    GetClientRect(hWnd, &rect);

    auto cellWidth = rect.right / grid.GetWidth();

    for (auto j = 0; j < grid.GetWidth() + 1; ++j)
    {
        MoveToEx(hdc, cellWidth * j, 0, nullptr);
        LineTo(hdc, cellWidth * j, rect.bottom);
    }

    auto cellHeight = rect.bottom / grid.GetHeight();

    for (auto i = 0; i < grid.GetHeight() + 1; ++i)
    {
        MoveToEx(hdc, 0, cellHeight * i, nullptr);
        LineTo(hdc, rect.right, cellHeight * i);
    }
}

void DrawCells(HWND hWnd, HDC hdc)
{
    RECT clientRect;
    GetClientRect(hWnd, &clientRect);

    auto cellWidth = clientRect.right / grid.GetWidth();
    auto cellHeight = clientRect.bottom / grid.GetHeight();

    auto brush = CreateSolidBrush(RGB(0, 0, 0));
    auto oldBrush = SelectObject(hdc, brush);

    for (auto i = 0; i < grid.GetHeight(); ++i)
    {
        for (auto j = 0; j < grid.GetWidth(); ++j)
        {
            if (grid.GetCell(i, j).IsAlive())
            {
                Ellipse(hdc, j * cellWidth, i * cellHeight, (j + 1) * cellWidth, (i + 1) * cellHeight);
            }
        }
    }

    SelectObject(hdc, oldBrush);
    DeleteObject(brush);
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
#define MYKEY WM_USER+1
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

    switch (message)
    {
    case WM_CREATE:
        
        grid.GetCell(0, 1).SetIsAlive(true);
        grid.GetCell(1, 2).SetIsAlive(true);
        grid.GetCell(2, 0).SetIsAlive(true);
        grid.GetCell(2, 1).SetIsAlive(true);
        grid.GetCell(2, 2).SetIsAlive(true);

        SetTimer(hWnd, 0, 1000, nullptr);
        
        RegisterHotKey(hWnd, MYKEY, MOD_CONTROL, VK_F10);
        
        break;

    case WM_TIMER:
        grid = lifeEngine.CalculateNext(grid);
        InvalidateRect(hWnd, nullptr, true);
        break;

    case WM_RBUTTONDOWN:
        grid.GetCell(GET_Y_LPARAM(lParam) / (rect.bottom / grid.GetHeight()), GET_X_LPARAM(lParam) / (rect.right / grid.GetWidth())).SetIsAlive(false);
        InvalidateRect(hWnd, nullptr, true);
        break;

    case WM_LBUTTONDOWN:
        grid.GetCell(GET_Y_LPARAM(lParam) / (rect.bottom / grid.GetHeight()), GET_X_LPARAM(lParam) / (rect.right / grid.GetWidth())).SetIsAlive(true);
        InvalidateRect(hWnd, nullptr, true);
        break;

    case WM_KEYDOWN:
        if (wParam == VK_SPACE) {
            if (timer) {
                KillTimer(hWnd, 0);
                timer = false;
            }
            else {
                timer = true;
                SetTimer(hWnd, 0, 1000, nullptr);
            }
        }
        break;

    case WM_SYSKEYDOWN:
        if (wParam == VK_F10) {
            if (timer == false) {
                grid = lifeEngine.CalculateNext(grid);
                InvalidateRect(hWnd, nullptr, true);
            }
        }

    case WM_HOTKEY:
        if (MYKEY == (int)wParam)
            if (timer == false) {
                for (size_t i = 0; i < 5; i++)
                {
                    grid = lifeEngine.CalculateNext(grid);
                    InvalidateRect(hWnd, nullptr, true);
                }
            }
        break;

    case WM_MOUSEMOVE:
        mouse.x = GET_X_LPARAM(lParam);
        mouse.y = GET_Y_LPARAM(lParam);
        break;

    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Parse the menu selections:
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
    
    case WM_MOUSEWHEEL:
    {
        int pix120 = GET_WHEEL_DELTA_WPARAM(wParam);
        int pix = pix120 / 120;
        grid = lifeEngine.SizeGrid(grid, grid.GetWidth(), grid.GetHeight() + pix);
        InvalidateRect(hWnd, nullptr, 0);
    }
    break;

    case WM_PAINT:
    {
        GetClientRect(hWnd, &rect);
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        auto brush = CreateSolidBrush(RGB(255, 255, 0));
        SelectObject(hdc, brush);
        Rectangle(hdc,
            (mouse.x / (rect.right / grid.GetWidth())) * (rect.right / grid.GetWidth()),
            (mouse.y / (rect.bottom / grid.GetHeight())) * (rect.bottom / grid.GetHeight()),
            ((mouse.x / (rect.right / grid.GetWidth())) + 1) * (rect.right / grid.GetWidth()),
            ((mouse.y / (rect.bottom / grid.GetHeight())) + 1) * (rect.bottom / grid.GetHeight())
        );

        DrawGrid(hWnd, hdc);
        DrawCells(hWnd, hdc);
        DeleteObject(hdc);
        DeleteObject(brush);
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
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
