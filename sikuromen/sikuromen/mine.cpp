#include<Windows.h>
//削除されていないメモリを出力にダンプする
#include<crtdbg.h>
#ifdef _DEBUG
     #ifndef DBG_NEW
          #define DBG_NEW new(_NORMAL_BLUCK,__FILE__,__LINE__)

#define new DBG_NEW
#endif
#endif
// _DEBUG

//グローバル変数
HWND g_hwnd;//ウィンドウハンドル
int g_width;//ウィンドウの横幅
int g_height;//ウィンドウの縦幅

//プロトタイプ宣言
LRESULT CALLBACK Wndproc(HWND hwnd, UINT usmg, WPARAM wParam, LPARAM IParam);


//Main関数
int APIENTRY wWinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPTSTR szCmdline, int nCmdShow)
{
    //メモリダンプ開始
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEMDF | _CRTDBG_LEAKCHECK_DF);

    wchar_t  name[] = { L"GameEngline" };//ウィンドウ＆タイトルネーム
    MSG  msg;                            //メッセージハンドル

    //ウィンドウステータス
    WNDCLASSEX wcex = {
        sizeof(WNDCLASSEX),CS_HREDRAW | CS_VREDRAW,
        WndProc,0,0,hInstance,NULL,name,NULL
    };
    //ウィンドウクラス作成
    RegisterClassEx(&wcex);

    //ウィンドウの幅設定
    g_width = 800;
    g_height = 600;

    int width = g_width + GetSystemMetrics(SM_CXDLGFRAME) * 2;
    int height = g_height + GetSystemMetrics(SM_CYDLGFRAME) * 2+ GetSystemMetrics(SM_CYCAPTION);

    //ウィンドウ作成
    if (!(g_hWnd = CreateWindow(name, name,
        WS_OVERLAPPEDWINDOW & ~(WS_MAXIMIZEBOX | WS_SIZEBOX),
        CW_USEDEFAULT, 0, width, height, 0, 0, hInstance, 0)))
    {
        return false;
    }

}