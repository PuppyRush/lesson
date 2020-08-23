// WormGame.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//


#include "framework.h"
#include "Wormgame_in_C.h"
#include "worm_algorithm.h"
#include "global.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE g_hInst;                                // 현재 인스턴스입니다.
WCHAR g_szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR g_szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
void                InitGame();

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, g_szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WORMGAMEINC, g_szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    //게임 관련 변수들을 초기화 합니다.
    
    InitGame();

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WORMGAMEINC));
    MSG msg;

    // 기본 메시지 루프입니다. 윈도우 이벤트를 받아와서 이곳에서 메세지를 보냅니다.
    // GetMessage->DispatchMessage 과정으로 메세지를 WndProc에서 처리하게 됩니다.
    while (GetMessage(&msg, NULL, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    finalize();

    return (int)msg.wParam;
}


//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
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
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WORMGAMEINC));
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WORMGAMEINC);
    wcex.lpszClassName = g_szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}



void InitGame()
{
    init_game();
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    g_hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

    g_hwndWnd = CreateWindowW(g_szWindowClass, g_szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

    if (!g_hwndWnd)
    {
        return FALSE;
    }

    ShowWindow(g_hwndWnd, nCmdShow);
    UpdateWindow(g_hwndWnd);

    return TRUE;
}
static void paint(HWND hWnd)
{
    //그리기 예제
    //WM_PAINT 메세지에 관한 설명은 다음 링크를 참고한다. (http://www.tipssoft.com/bulletin/board.php?bo_table=FAQ&wr_id=636)
    PAINTSTRUCT ps;
    HBRUSH bru;

    // 사각형을 그려줍니다.
    for (int i = 0; i < g_height; i++)
    {
        for (int l = 0; l < g_width; l++)
        {
            HDC h_dc = GetDC(hWnd);
            switch (g_map[i][l].type)
            {
            case eWall:
                bru = (HBRUSH)GetStockObject(BLACK_BRUSH);    //투명 브러시 사용
                SelectObject(h_dc, bru);
                break;
            case eWorm:
                bru = CreateSolidBrush(RGB(0, 128, 128));
                SelectObject(h_dc, bru);
                break;
            case eFeed:
                bru = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
                SelectObject(h_dc, bru);
                break;
            case eNone:
                /*bru = CreateSolidBrush(WHITE_BRUSH);
                SelectObject(h_dc, bru);
                break;*/
            default:
                //exception
                ;
            }
            size_t x = getLeftInMap(l);
            size_t y = getTopInMap(i);
            Rectangle(h_dc, x, y, x + UNIT_WIDTH_LEN, y + UNIT_HEIGHT_LEN);
            ReleaseDC(hWnd, h_dc);
        }
    }

}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
// 창 클래스를 MyRegisterClass통해 등록할때의 해당 창의 이벤트를 WndProc함수에서 처리하도록 RegisterClassExW를 통해 콜백함수를 지정한다.
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    long dwStyle;

    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // 메뉴 선택을 구문 분석합니다:
        switch (wmId)
        {
        case WM_KEYDOWN:
            break;
        case IDM_ABOUT:
            //About함수를 Dialog의 콜백함수로 등록하여 About함수에서 메세지를 처리한다.
            DialogBox(g_hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
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
        keydown(wParam);
        break;
    case WM_LBUTTONDOWN:
    {
        // 그리기 예시
        // 파란색 브러쉬를 설정해 주는 작업입니다.

        break;
    }
    case WM_PAINT:
    {
        paint(hWnd);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;

        //창의 초기화. CreateWindows함수가 호출되면 윈도우가 자체적으로 WM_CREATE 메세지를 발생시킨다.
    case WM_CREATE:
    {
        //Timer 지정
        //Timer를 이용하여 주기적으로 처리해야할 일을 수행한다.
        //http://www.tipssoft.com/bulletin/board.php?bo_table=FAQ&wr_id=2192
        SetTimer(hWnd, 0, 200, 0);

        break;
    }
    case WM_TIMER:
        //TIMER_ID는 몇?
        timer();
        paint(hWnd);
        UpdateWindow(hWnd);
        static int a = 0;
        const wchar_t str = a++;
        //
        //const wchar_t* lyrics = malloc(sizeof(wchar_t) * 5);
        //swprintf_s(lyrics, L"%d", a);

        //CreateWindowW(_T("Static"), lyrics,
        //    WS_CHILD | WS_VISIBLE | SS_LEFT,
        //    20, 20, 100, 100,
        //    hWnd, (HMENU)1, NULL, NULL);
        break;
    default:
        ;
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
    return 0;
}
// 정보 대화 상자의 메시지 처리기입니다.
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
