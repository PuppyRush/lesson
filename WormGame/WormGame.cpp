// WormGame.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "WormGame.h"
#include "GameController.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE g_hInst;                                // 현재 인스턴스입니다.
WCHAR g_szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR g_szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

GameController g_ctl;

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
    LoadStringW(hInstance, IDC_WORMGAME, g_szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    //게임 관련 변수들을 초기화 합니다.
    InitGame();

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WORMGAME));
    MSG msg;

    // 기본 메시지 루프입니다. 윈도우 이벤트를 받아와서 이곳에서 메세지를 보냅니다.
    // GetMessage->DispatchMessage 과정으로 메세지를 WndProc에서 처리하게 됩니다.
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
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WORMGAME));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WORMGAME);
    wcex.lpszClassName  = g_szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}



void InitGame()
{

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

   HWND hWnd = CreateWindowW(g_szWindowClass, g_szTitle, WS_OVERLAPPEDWINDOW,
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
        //static_cast는 c++에서의 명시적 형변환을 위한 예약어
        //키보드 처리를 이곳에서 g_ctl에 넘겨준다.
        g_ctl.command(static_cast<UINT>(wParam));
        break;
    case WM_LBUTTONDOWN:
        {
            // 그리기 예시
            // 파란색 브러쉬를 설정해 주는 작업입니다.

            HDC h_dc = GetDC(hWnd);
            HBRUSH bru;
            size_t x = LOWORD(lParam);
            size_t y = HIWORD(lParam);

            // 사각형을 그려줍니다.
            bru = CreateSolidBrush(RGB(0, 0, 255));
            SelectObject(h_dc, bru);
            Rectangle(h_dc, x, y, 200, 200);
            break;
        }
    case WM_PAINT:
        {
            //그리기 예제
            //WM_PAINT 메세지에 관한 설명은 다음 링크를 참고한다. (http://www.tipssoft.com/bulletin/board.php?bo_table=FAQ&wr_id=636)
            //이곳에서 g_ctl로부터 배열의 상태를 가져와 단순히 그림을 그리는 작업만을 하게 된다.
            PAINTSTRUCT ps;
            HDC h_dc = BeginPaint(hWnd, &ps);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
        
    //창의 초기화. CreateWindows함수가 호출되면 윈도우가 자체적으로 WM_CREATE 메세지를 발생시킨다.
    case WM_CREATE:
    {
        //_T, wchar_t는 유니코드/멀티바이트 별도 인코딩 지식 필요
        const wchar_t* lyrics = _T("static");
        CreateWindowW(_T("Static"), lyrics,
            WS_CHILD | WS_VISIBLE | SS_LEFT,
            20, 20, 100, 100,
            hWnd, (HMENU)1, NULL, NULL);

        break;
    }
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
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
