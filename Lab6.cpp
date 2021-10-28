// Lab6Chan.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Lab6Chan.h"
#include "stdio.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна
int arr[10]{};
int n;
int brr[10]{};
int max, min, index_max = 0, index_min = 0, d = 0, ch = 0;

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

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB6CHAN, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB6CHAN));

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

    return (int)msg.wParam;
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

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB6CHAN));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_LAB6CHAN);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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
    FILE* f;
    fopen_s(&f, "D:\\Lab.txt", "rt");
    fscanf_s(f, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        fscanf_s(f, "%d ", &arr[i]);
    }
    fclose(f);


    for (int i = 0; i < n; i++)
    {
        brr[i] = arr[i];
    }
    
    max = arr[0];
    min = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            index_max = i;
        }
        if (arr[i] < min)
        {
            min = arr[i];
            index_min = i;
        }
    }



    switch (index_min > index_max)
    {
    case true:
        d = index_max + 1;
        while (d != n - 1) {
            if (arr[d] % 2 != 0)
            {
                arr[d - ch] = arr[d];
            }
            else {
                ch++;
            }
            d++;
            if (d == index_min) {
                arr[d - ch] = arr[d];
                break;
            }
        }
        for (int i = index_min + 1; i < n; i++) {
            arr[i - ch] = arr[i];
        }
        break;
    case false:
        d = index_min + 1;
        while (d != n - 1) {
            if (arr[d] % 2 != 0) {
                arr[d - ch] = arr[d];
            }
            else {
                ch++;
            }
            d++;
            if (d == index_max) {
                arr[d - ch] = arr[d];
                break;
            }
        }
        for (int i = index_max + 1; i < n; i++) {
            arr[i - ch] = arr[i];
        }
        break;
    }

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
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
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
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        HBRUSH Brush1, Brush2, Brush3;
        Brush1 = CreateHatchBrush(6, RGB(0, 0, 255));
        Brush2 = CreateHatchBrush(6, RGB(0, 255, 0));
        Brush3 = CreateHatchBrush(6, RGB(255, 0, 0));
        int x = 0;

        MoveToEx(hdc, 100, 100, NULL);
        LineTo(hdc, 110, 110);
        MoveToEx(hdc, 100, 100, NULL);
        LineTo(hdc, 90, 110);
        MoveToEx(hdc, 100, 100, NULL);
        LineTo(hdc, 100, 400);
        LineTo(hdc, 1000, 400);
        LineTo(hdc, 990, 410);
        MoveToEx(hdc, 1000, 400, NULL);
        LineTo(hdc, 990, 390);
        SelectObject(hdc, Brush1);
       
        MoveToEx(hdc, 100, 400, NULL);
        LineTo(hdc, 110, 410);
        MoveToEx(hdc, 100, 400, NULL);
        LineTo(hdc, 90, 410);
        MoveToEx(hdc, 100, 400, NULL);
        LineTo(hdc, 100, 700);
        LineTo(hdc, 1000, 700);
        LineTo(hdc, 990, 710);
        MoveToEx(hdc, 1000, 700, NULL);
        LineTo(hdc, 990, 690);

    

        for (int i = 0; i < n; i++)
        {
            if (brr[i] == max || brr[i] == min)
            {
                SelectObject(hdc, Brush3);
            }
            else
            {
                if (brr[i] % 2 == 0)
                {
                    SelectObject(hdc, Brush2);
                }
                else
                {
                    SelectObject(hdc, Brush1);
                }
            }
            Rectangle(hdc, 110 + x, 400 - brr[i] * 2, 140 + x, 400);
            x += 50;
        }
        x = 0;
        for (int i = 0; i < n - ch  ; i++)
        {
            if (arr[i] == max || arr[i] == min)
            {
                SelectObject(hdc, Brush3);
            }
            else
            {
                if (arr[i] % 2 == 0)
                {
                    SelectObject(hdc, Brush2);
                }
                else
                {
                    SelectObject(hdc, Brush1);
                }
            }
            Rectangle(hdc, 110 + x, 700 - arr[i] * 2, 140 + x, 700);
            x += 50;
        }
        DeleteObject(Brush1);
        DeleteObject(Brush2);
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
