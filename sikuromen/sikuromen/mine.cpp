#include<Windows.h>
//�폜����Ă��Ȃ����������o�͂Ƀ_���v����
#include<crtdbg.h>
#ifdef _DEBUG
     #ifndef DBG_NEW
          #define DBG_NEW new(_NORMAL_BLUCK,__FILE__,__LINE__)

#define new DBG_NEW
#endif
#endif
// _DEBUG

//�O���[�o���ϐ�
HWND g_hwnd;//�E�B���h�E�n���h��
int g_width;//�E�B���h�E�̉���
int g_height;//�E�B���h�E�̏c��

//�v���g�^�C�v�錾
LRESULT CALLBACK Wndproc(HWND hwnd, UINT usmg, WPARAM wParam, LPARAM IParam);


//Main�֐�
int APIENTRY wWinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPTSTR szCmdline, int nCmdShow)
{
    //�������_���v�J�n
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEMDF | _CRTDBG_LEAKCHECK_DF);

    wchar_t  name[] = { L"GameEngline" };//�E�B���h�E���^�C�g���l�[��
    MSG  msg;                            //���b�Z�[�W�n���h��

    //�E�B���h�E�X�e�[�^�X
    WNDCLASSEX wcex = {
        sizeof(WNDCLASSEX),CS_HREDRAW | CS_VREDRAW,
        WndProc,0,0,hInstance,NULL,name,NULL
    };
    //�E�B���h�E�N���X�쐬
    RegisterClassEx(&wcex);

    //�E�B���h�E�̕��ݒ�
    g_width = 800;
    g_height = 600;

    int width = g_width + GetSystemMetrics(SM_CXDLGFRAME) * 2;
    int height = g_height + GetSystemMetrics(SM_CYDLGFRAME) * 2+ GetSystemMetrics(SM_CYCAPTION);

    //�E�B���h�E�쐬
    if (!(g_hWnd = CreateWindow(name, name,
        WS_OVERLAPPEDWINDOW & ~(WS_MAXIMIZEBOX | WS_SIZEBOX),
        CW_USEDEFAULT, 0, width, height, 0, 0, hInstance, 0)))
    {
        return false;
    }

}