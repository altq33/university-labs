// Lab10.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Lab10.h"
#include <stdio.h>
#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна
int arr[25][25]{};
int h = 0, w = 0,  px = 0, py = 0, lvl = 0;
bool key = false; 
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
    LoadStringW(hInstance, IDC_LAB10, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB10));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB10));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB10);
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
void Level()
{
    FILE* Level;
    fopen_s(&Level, "D:\\Game.txt", "rt");
    fscanf_s(Level, "%d%d%d%d", &h, &w, &px, &py);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            fscanf_s(Level, "%d", &arr[i][j]);
        }
    }
    fclose(Level);

}
void Level2()
{
    FILE* Level;
    fopen_s(&Level, "D:\\Game2.txt", "rt");
    fscanf_s(Level, "%d%d%d%d", &h, &w, &px, &py);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            fscanf_s(Level, "%d", &arr[i][j]);
        }
    }
    fclose(Level);

}

void Level3()
{
    FILE* Level;
    fopen_s(&Level, "D:\\Game3.txt", "rt");
    fscanf_s(Level, "%d%d%d%d", &h, &w, &px, &py);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            fscanf_s(Level, "%d", &arr[i][j]);
        }
    }
    fclose(Level);

}
void Level4()
{
    FILE* Level;
    fopen_s(&Level, "D:\\Game4.txt", "rt");
    fscanf_s(Level, "%d%d%d%d", &h, &w, &px, &py);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            fscanf_s(Level, "%d", &arr[i][j]);
        }
    }
    fclose(Level);
}



BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной
   Level();
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, SW_SHOWMAXIMIZED);
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
    case WM_KEYDOWN:
        {
            switch (wParam)
            {
                case VK_DOWN:
                    if (arr[py + 1][px] != 1)
                    {
                        py++;
                        InvalidateRect(hWnd, NULL, true);
                        if (arr[py][px] == 4)
                        {
                            key = true; 
                            InvalidateRect(hWnd, NULL, true);
                        }
                        if (arr[py][px] == 3)
                        {
                            MessageBoxA(hWnd, "RESTART LEVEL?", "YOU LOSE :(", MB_OK);
                            switch (lvl)
                            {
                            case 0:
                                Level();
                                break;
                            case 1:
                                Level2();
                                break;
                            case 2:
                                Level3();
                                key = false; 
                                break;
                            case 3:
                                Level4();
                                key = false;
                                break;
                            }
                            InvalidateRect(hWnd, NULL, true);
                        }
                        if (arr[py][px] == 2 && lvl < 2)
                        {
                            lvl++;
                            MessageBoxA(hWnd, "YOU WIN!", "OH YEAH!!!", MB_OK);
                            switch (lvl)
                            {
                           
                            case 1:
                                Level2();
                                break;
                            case 2:
                                Level3();
                                break;
                            case 3:
                                Level4();
                                break;
                            default:
                                Level();
                                lvl = 0;
                                break;
                            }
                    }
                        if (arr[py][px] == 2 && key == true)
                        {
                            lvl++;
                            MessageBoxA(hWnd, "GO TO NEXT LEVEL?", "YOU WIN! :)", MB_OK);
                            switch (lvl)
                            {

                            case 1:
                                Level2();
                                break;
                            case 2:
                                Level3();
                                key = false;
                                break;
                            case 3:
                                Level4();
                                key = false;
                                break;
                            default:
                                Level();
                                lvl = 0;
                                break;
                            }
                            InvalidateRect(hWnd, NULL, true);
                        }
                   
                       
                        InvalidateRect(hWnd, NULL, true);
                    }
                    
                    break;
                case VK_UP:
                    if (arr[py - 1][px] != 1)
                    {
                        py--;
                        InvalidateRect(hWnd, NULL, true);
                        if (arr[py][px] == 4)
                        {
                            key = true;
                            InvalidateRect(hWnd, NULL, true);
                        }
                        if (arr[py][px] == 3)
                        {
                            MessageBoxA(hWnd, "RESTART LEVEL?", "YOU LOSE :(", MB_OK);
                            switch (lvl)
                            {
                            case 0:
                                Level();
                                break;
                            case 1:
                                Level2();
                                break;
                            case 2:
                                Level3();
                                key = false;
                                break;
                            case 3:
                                Level4();
                                key = false;
                                break;
                            }
                            InvalidateRect(hWnd, NULL, true);
                        }
                        if (arr[py][px] == 2 && lvl < 2)
                        {
                            lvl++;
                            MessageBoxA(hWnd, "YOU WIN!", "OH YEAH!!!", MB_OK);
                            switch (lvl)
                            {
                            case 1:
                                Level2();
                                break;
                            case 2:
                                Level3();
                                break;
                            case 3:
                                Level4();
                                break;
                            default:
                                Level();
                                lvl = 0;
                                break;
                            }
                            
                            InvalidateRect(hWnd, NULL, true);
                        }
                        if (arr[py][px] == 2 && key == true)
                        {
                            lvl++;
                            MessageBoxA(hWnd, "GO TO NEXT LEVEL?", "YOU WIN! :)", MB_OK);
                            switch (lvl)
                            {

                            case 1:
                                Level2();
                                break;
                            case 2:
                                Level3();
                                key = false;
                                break;
                            case 3:
                                Level4();
                                key = false;
                                break;
                            default:
                                Level();
                                lvl = 0;
                                break;
                            }
                            InvalidateRect(hWnd, NULL, true);
                        }
                        
                    }
                    break;
                case VK_LEFT:
                    if (arr[py][px - 1] != 1)
                    {
                        px--;
                        InvalidateRect(hWnd, NULL, true);

                        if (arr[py][px] == 4)
                        {
                            key = true;
                            InvalidateRect(hWnd, NULL, true);
                        }
                        if (arr[py][px] == 3)
                        {
                            MessageBoxA(hWnd, "RESTART LEVEL?", "YOU LOSE :(", MB_OK);
                            switch (lvl)
                            {
                            case 0:
                                Level();
                                break;
                            case 1:
                                Level2();
                                break;
                            case 2:
                                Level3();
                                key = false;
                                break;
                            case 3:
                                Level4();
                                key = false;
                                break;
                            }
                            InvalidateRect(hWnd, NULL, true);
                        }
                        if (arr[py][px] == 2 && lvl < 2)
                        {
                            lvl++;
                            MessageBoxA(hWnd, "YOU WIN!", "OH YEAH!!!", MB_OK);

                            switch (lvl)
                            {
                            
                            case 1:
                                Level2();
                                break;
                            case 2:
                                Level3();                            
                                break;
                            case 3:
                                Level4();     
                                break;
                            default:
                                Level();
                                lvl = 0;
                                break;
                            }
                            InvalidateRect(hWnd, NULL, true);
                        }
                        if (arr[py][px] == 2 && key == true)
                        {
                            lvl++;
                            MessageBoxA(hWnd, "GO TO NEXT LEVEL?", "YOU WIN! :)", MB_OK);
                            switch (lvl)
                            {

                            case 1:
                                Level2();
                                break;
                            case 2:
                                Level3();
                                key = false;
                                break;
                            case 3:
                                Level4();
                                key = false;
                                break;
                            default:
                                Level();
                                lvl = 0;
                                break;
                            }
                            InvalidateRect(hWnd, NULL, true);
                        }
         
                    }
                    break;
                case VK_RIGHT:
                    if (arr[py][px + 1] != 1)
                    {
                        px++;
                        InvalidateRect(hWnd, NULL, true);
                        if (arr[py][px] == 4)
                        {
                            key = true;
                            InvalidateRect(hWnd, NULL, true);
                        }
                        if (arr[py][px] == 3)
                        {
                            MessageBoxA(hWnd, "RESTART LEVEL?", "YOU LOSE :(", MB_OK);
                            switch (lvl)
                            {
                            case 0:
                                Level();
                                break;
                            case 1:
                                Level2();
                                break;
                            case 2:
                                Level3();
                                key = false;
                                break;  
                            case 3:
                                Level4();
                                key = false;
                                break;
                            }
                            InvalidateRect(hWnd, NULL, true);
                        }
                        if (arr[py][px] == 2 && lvl < 2)
                        {                         
                            lvl++;
                            MessageBoxA(hWnd, "GO TO NEXT LEVEL?", "YOU WIN! :)", MB_OK);
                            switch (lvl)
                            {

                            case 1:
                                Level2();
                                break;
                            case 2:
                                Level3();
                                break;
                            case 3:
                                Level4();
                                break;
                            default:
                                Level();
                                lvl = 0;
                                break;
                            }               
                            InvalidateRect(hWnd, NULL, true);
                        }

                        if (arr[py][px] == 2 && key == true)
                        {
                            lvl++;
                            MessageBoxA(hWnd, "GO TO NEXT LEVEL?", "YOU WIN! :)", MB_OK);
                            switch (lvl)
                            {

                            case 1:
                                Level2();
                                break;
                            case 2:
                                Level3();
                                key = false;
                                break;
                            case 3:
                                Level4();
                                key = false;
                                break;
                            default:
                                Level();
                                lvl = 0;
                                break;
                            }
                            InvalidateRect(hWnd, NULL, true);
                        }
                        
                    }
                    break;
            }

        }
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            HBRUSH Wall, Way, Player, Exit, Monster, Eye, BG, Key, ExitC; 
            HPEN Default;
            // Brushes
            Default = CreatePen(PS_NULL,NULL,NULL);
            Wall = CreateSolidBrush(RGB(0, 0, 0));
            Way = CreateSolidBrush(RGB(47, 140, 222));
            Player = CreateSolidBrush(RGB(235, 47, 231));
            Exit = CreateSolidBrush(RGB(78, 230, 81));
            Eye = CreateSolidBrush(RGB(255, 255, 255));
            Monster = CreateSolidBrush(RGB(255, 149, 0));
            BG = CreateSolidBrush(RGB(250, 128, 114));
            Key = CreateSolidBrush(RGB(255, 255, 0));
            ExitC = CreateSolidBrush(RGB(255, 0, 0));
            // Main part 
            // BG
            SelectObject(hdc, BG);
            Rectangle(hdc, 0, 0, 2000, 2000);
            // Какой сейчас уровень?
            switch (lvl)
            {
            case 0:
                TextOutW(hdc, 150, 130, L"Lvl 1", lstrlen(L"Lvl 1"));
                break;
            case 1:
                TextOutW(hdc, 150, 130, L"Lvl 2", lstrlen(L"Lvl 2"));
                break;
            case 2:
                TextOutW(hdc, 150, 130, L"Lvl 3", lstrlen(L"Lvl 3"));
                break;
            case 3:
                TextOutW(hdc, 150, 130, L"Lvl 4", lstrlen(L"Lvl 4"));
                break;
            }
            // Отрисовка всех объектов на карте 
            SelectObject(hdc, Default);
          
                for (int i = 0; i < h; i++)
                {
                    for (int j = 0; j < w; j++)
                    {
                        if (arr[i][j] == 1)
                        {
                            SelectObject(hdc, Wall);
                            Rectangle(hdc, 150 + j * 39, 150 + i * 39, 190 + j * 39, 190 + i * 39);                             
                        }
                        else
                        {
                            SelectObject(hdc, Way);
                            Rectangle(hdc, 150 + j * 39, 150 + i * 39, 190 + j * 39, 190 + i * 39);              
                        }
                              
                        if (arr[i][j] == 2 && key == false && lvl >= 2)
                        {
                            
                            SelectObject(hdc, ExitC);
                            Rectangle(hdc, 150 + j * 39, 150 + i * 39, 190 + j * 39, 190 + i * 39);
                        }
                        if (arr[i][j] == 2 && key == true && lvl >= 2)
                        {

                            SelectObject(hdc, Exit);
                            Rectangle(hdc, 150 + j * 39, 150 + i * 39, 190 + j * 39, 190 + i * 39);
                        }
                        if (arr[i][j] == 2 && lvl < 2)
                        {

                            SelectObject(hdc, Exit);
                            Rectangle(hdc, 150 + j * 39, 150 + i * 39, 190 + j * 39, 190 + i * 39);
                        }
                            
                        if (arr[i][j] == 3)
                        {
                            
                            SelectObject(hdc, Monster);                          
                            Rectangle(hdc, 152 + j * 39, 152 + i * 39, 188 + j * 39, 188 + i * 39);
                            SelectObject(hdc, Wall);
                            Rectangle(hdc, 158 + j * 39, 160 + i * 39, 168 + j * 39, 170 + i * 39);
                            Rectangle(hdc, 181 + j * 39, 160 + i * 39, 171 + j * 39, 170 + i * 39);
                            Rectangle(hdc, 160 + j * 39, 180 + i * 39, 180 + j * 39, 185 + i * 39);
                        }
                        if (arr[i][j] == 4 && key == false)
                        {
                            SelectObject(hdc, Key);
                            Ellipse(hdc, 160 + j * 39, 160 + i * 39, 180 + j * 39, 180 + i * 39);
                            Rectangle(hdc, 177 + j * 39, 165 + i * 39, 190 + j * 39, 175 + i * 39);
                            SelectObject(hdc, Way);
                            Ellipse(hdc, 165 + j * 39, 165 + i * 39, 175 + j * 39, 175 + i * 39);
                        }
                        
                        
                    }
                }
                SelectObject(hdc, Player);
                Ellipse(hdc, 152 + px * 39, 152 + py * 39, 188 + px * 39, 188 + py * 39);
                SelectObject(hdc, Eye);
                Ellipse(hdc, 160 + px * 39, 160 + py * 39, 180 + px * 39, 180 + py * 39);
                SelectObject(hdc, Wall);
                Ellipse(hdc, 166 + px * 39, 166 + py * 39, 174 + px * 39, 174 + py * 39);
            
         
            // Clear 
            DeleteObject(Wall);
            DeleteObject(Exit);
            DeleteObject(Player);
            DeleteObject(Way);
            DeleteObject(Monster);
            DeleteObject(Default);
            DeleteObject(Eye);
            DeleteObject(Key);
            DeleteObject(ExitC);
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
