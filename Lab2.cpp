// Lab2Graph.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Lab2Graph.h"

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

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB2GRAPH, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB2GRAPH));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB2GRAPH));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB2GRAPH);
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

   ShowWindow(hWnd,SW_MAXIMIZE);
   UpdateWindow(hWnd);

   return TRUE;
}
// Функции отрисовки различных объектов 
void birds(int x, int  y, HPEN hpen, HDC hdc)
{
    SelectObject(hdc, hpen);
    MoveToEx(hdc, 200 + x, 100 + y, NULL);
    LineTo(hdc, 210 + x, 90 + y);
    LineTo(hdc, 220 + x, 95 + y);
    LineTo(hdc, 230 + x, 90 + y);
    LineTo(hdc, 240 + x, 100 + y);
}
void birds2(int x, int  y, HPEN hpen, HDC hdc)
{
    SelectObject(hdc, hpen);
    MoveToEx(hdc, 200 + x, 100 + y, NULL);
    LineTo(hdc, 220 + x, 80 + y);
    MoveToEx(hdc, 200 + x, 100 + y, NULL);
    LineTo(hdc, 180 + x, 80 + y);
}
void coralls(int x, int y, HPEN hpen, HDC hdc)
{
    SelectObject(hdc, hpen);
    MoveToEx(hdc, 100 + x, 900 + y, NULL);
    LineTo(hdc, 100 + x, 860 + y);
    LineTo(hdc, 110 + x, 850 + y);
    LineTo(hdc, 110 + x, 840 + y);
    MoveToEx(hdc, 100 + x, 860 + y, NULL);
    LineTo(hdc, 90 + x, 850 + y);
    LineTo(hdc, 80 + x, 840 + y);
    MoveToEx(hdc, 100 + x, 880 + y, NULL);
    LineTo(hdc, 115 + x, 870 + y);
    MoveToEx(hdc, 100 + x, 880 + y, NULL);
    LineTo(hdc, 70 + x, 860 + y);


}
void Star(HDC hdc, int x, int y, int size)
{
    MoveToEx(hdc, x, y - size, NULL);
    LineTo(hdc, x + size / 4, y - size / 4);
    LineTo(hdc, x + size, y);
    LineTo(hdc, x + size / 4, y + size / 4);
    LineTo(hdc, x, y + size);
    LineTo(hdc, x - size / 4, y + size / 4);
    LineTo(hdc, x - size, y);
    LineTo(hdc, x - size / 4, y - size / 4);
    LineTo(hdc, x, y - size);
}
void RecurStar(HDC hdc, int x, int y, int size, int depth, HPEN k)
{
    if (depth <= 0)
        return;
    
    Star(hdc, x, y, size);
    RecurStar(hdc, x - size * 2, y, size / 4, depth - 1,k);
    RecurStar(hdc, x - size * 2, y - size * 2, size / 3, depth - 1, k);
    RecurStar(hdc, x + size * 2, y - size * 4, size / 2, depth - 1, k);
    RecurStar(hdc, x + size, y - size * 2, size / 5, depth - 1, k);
    SelectObject(hdc, k);
}



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
            HPEN ShipPen, ParPen, RedPen, BlackPen, YellowPen, OrangePen, PurplePen, GreenPen;
            HBRUSH  WaterBrush, SkyBrush, WhiteBrush, BlackBrush,YellowBrush, BottomBrush, PinkBrush ;
            const int  start_position_x = 0, start_position_y = 0;
            int x = 0, y = 0;
            // Кисти 
            PinkBrush = CreateHatchBrush(6, RGB(255, 107, 176));
            BottomBrush = CreateHatchBrush(6, RGB(255, 236, 76));
            YellowBrush = CreateHatchBrush(6, RGB(255, 255, 0));
            BlackBrush = CreateHatchBrush(6, RGB(0, 0, 0));
            WhiteBrush = CreateHatchBrush(6, RGB(255, 255, 255));
            WaterBrush = CreateHatchBrush(6, RGB(19, 0, 191));
            SkyBrush = CreateHatchBrush(6, RGB(97, 79, 255));
            GreenPen = CreatePen(1, 2, RGB(0, 255, 0));
            YellowPen = CreatePen(1, 2, RGB(255, 255, 0));
            OrangePen = CreatePen(1, 2, RGB(255, 128, 0));
            PurplePen = CreatePen(1, 2, RGB(128, 0, 255));
            BlackPen = CreatePen(1, 2, RGB(0, 0, 0));
            ShipPen = CreatePen(1, 2, RGB(155, 89, 57));
            ParPen = CreatePen(1, 3, RGB(0, 0, 0));
            RedPen = CreatePen(1, 2, RGB(255, 0, 0));
            // Небо, море и дно 
            MoveToEx(hdc, start_position_x, start_position_y, NULL);
            SelectObject(hdc, WaterBrush);
            Rectangle(hdc, start_position_x, start_position_y, 2000, 2000);
            SelectObject(hdc, SkyBrush);
            Rectangle(hdc, start_position_x, start_position_y, 2000, 375);
            DeleteObject(WaterBrush);
            DeleteObject(SkyBrush);
            SelectObject(hdc, BottomBrush);
            Rectangle(hdc, start_position_x, 880, 2000, 2000);
            // Солнце 
            SelectObject(hdc, BlackPen);
            SelectObject(hdc, YellowBrush);
            Ellipse(hdc, 1200, 50, 1400, 250);
            // stars 
            SelectObject(hdc, RedPen);    
            RecurStar(hdc,1700,250,40,4,YellowPen);
            // Кораллы 
            y = 10;
            x = 0;
            for (int i = 0; i < 20; i++)
            {
  
                if (i % 2 == 0)
                {
                    coralls(0+x, 0+y, RedPen, hdc);
                    y -= 20; 
                    x += 100;
                }
                if (i % 2 > 0)
                {
                    coralls(0 + x, 0 + y, GreenPen, hdc);
                    y += 20;
                    x += 100;
                }
                if (i % 3 == 1)
                {
                    coralls(0 + x, 45, PurplePen, hdc);           
                    x += 100;
                }

            }

            // Птицы 
            birds(10, 40, BlackPen, hdc); 
            birds2(150, 60, BlackPen, hdc);
            birds(300, -20, BlackPen, hdc);
            birds2(500, 80, BlackPen, hdc);
            birds(650, 20, BlackPen, hdc);
            //Рыба 1
            SelectObject(hdc, PurplePen);
            SelectObject(hdc, PinkBrush);
            Rectangle(hdc, 1200, 500, 1400, 700);
            SelectObject(hdc, BlackBrush);
            SelectObject(hdc, BlackPen);
            Rectangle(hdc, 1210, 570, 1250, 600);
            y = 0;
            for (int i = 0; i < 200; i++)
            {
                MoveToEx(hdc, 1400, 585, NULL);
                LineTo(hdc, 1500, 500 + y);
                y += 1;
            }

            // Палуба 
            SelectObject(hdc, ShipPen);
            x = 0;
            for (int i = 0; i < 50; i++)
            {
                MoveToEx(hdc, 450, 375, NULL);
                LineTo(hdc, (450 - x), 320);
                x += 1;
            }
            x = 0;
            for (int i = 0; i < 150; i++)
            {
                MoveToEx(hdc, 450 + x, 375, NULL);
                LineTo(hdc, (450 + x), 320);
                x += 1;
            }
            x = 0;
            for (int i = 0; i < 50; i++)
            {
                MoveToEx(hdc, 600, 375, NULL);
                LineTo(hdc, (600 + x), 320);
                x += 1;
            }
            DeleteObject(ShipPen);
            //Иллюминаторы 
            x = 50;
            SelectObject(hdc, WhiteBrush);
            Ellipse(hdc, 470, 335, 495, 355);
            Ellipse(hdc, 470 + x , 335, 495 + x, 355);
            Ellipse(hdc, 470 + 2 * x, 335, 495 + 2 * x, 355);
            // Парус 
            MoveToEx(hdc, 525, 320, NULL);
            SelectObject(hdc, ParPen);
            LineTo(hdc, 525, 225);
            LineTo(hdc, 600, 275);
            SelectObject(hdc, RedPen);
            y = 0;
            for (int i = 0; i < 75; i++)
            {
                MoveToEx(hdc, 600, 275, NULL);
                LineTo(hdc, 525, 225 + y );
                y += 1;
            }
            DeleteObject(RedPen);
            SelectObject(hdc, BlackPen);
            Rectangle(hdc, 525, 200, 580, 225);
            //Рыба 2 
            y = 0;
            SelectObject(hdc, YellowPen);
            for (int i = 0; i < 85; i++)
            {
                MoveToEx(hdc, 300, 470, NULL);
                LineTo(hdc, 400, 420 + y);
                y += 1;
            }
            SelectObject(hdc, BlackBrush);
            Ellipse(hdc, 325, 460, 340, 475);
            SelectObject(hdc, OrangePen);
            x = 0;
            for (int i = 0; i < 30; i++)
            {
                MoveToEx(hdc, 402, 450, NULL);
                LineTo(hdc, 400 + x, 420 );
                x += 1;
            }
            y = 0;
            for (int i = 0; i < 100; i++)
            {
                MoveToEx(hdc, 402, 470, NULL);
                LineTo(hdc, 460, 420 + y);
                y += 1;
            }
            // Рыба 3 
            
            SelectObject(hdc, BlackPen);
            SelectObject(hdc, WhiteBrush);
            Ellipse(hdc,700, 450, 900, 550);
            SelectObject(hdc, PurplePen);
            y = 0;
            for (int i = 0; i < 50; i++)
            {
                MoveToEx(hdc, 700, 500, NULL);
                LineTo(hdc, 650, 470 + y);
                y += 1;
            }
            SelectObject(hdc, BlackBrush);
            Ellipse(hdc, 850, 470, 870, 500);
            // Удаление оставшихся кистей 
            DeleteObject(BlackBrush);
            DeleteObject(WhiteBrush);
            DeleteObject(ParPen);
            DeleteObject(RedPen);
            DeleteObject(OrangePen);
            DeleteObject(PurplePen);
            DeleteObject(BlackPen);
            DeleteObject(YellowBrush);
            DeleteObject(BottomBrush); 
            DeleteObject(PinkBrush);
            DeleteObject(GreenPen);
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
