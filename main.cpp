#pragma comment(linker, "/opt:nowin98")
#include <windows.h>

#define IDU_BUTTON1 100
#define IDU_LIST1 101

CHAR szClassName[]="window";
HWND hList;
INT i;

LRESULT CALLBACK WndProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	CHAR str[20];
    switch(msg){
		case WM_COMMAND:
			switch(LOWORD(wParam)){
				case IDU_BUTTON1:
					wsprintf(str,"’Ç‰Á‚·‚é•¶Žš—ñ%d",i++);
					SendMessage(hList,LB_ADDSTRING,0,(LPARAM)str);
					break;
			}
			break;
		case WM_CREATE:
			CreateWindow("BUTTON","’Ç‰Á",
						 WS_CHILD|WS_VISIBLE,
						 10,10,200,30,
						 hWnd,
						 (HMENU)IDU_BUTTON1,
						 ((LPCREATESTRUCT)lParam)->hInstance,
						 NULL);
			hList=CreateWindow("LISTBOX","",
						 WS_CHILD|WS_VISIBLE|WS_BORDER|WS_VSCROLL|LBS_DISABLENOSCROLL,
						 10,50,200,300,
						 hWnd,
						 (HMENU)IDU_LIST1,
						 ((LPCREATESTRUCT)lParam)->hInstance,
						 NULL);
			break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return(DefWindowProc(hWnd,msg,wParam,lParam));
    }
    return (0L);
}

int WINAPI WinMain(HINSTANCE hinst,HINSTANCE hPreInst,
                   LPSTR pCmdLine,int nCmdShow)
{
    HWND hWnd;
    MSG msg;
    WNDCLASS wndclass;
    if(!hPreInst){
        wndclass.style=CS_HREDRAW|CS_VREDRAW;
        wndclass.lpfnWndProc=WndProc;
        wndclass.cbClsExtra=0;
        wndclass.cbWndExtra=0;
        wndclass.hInstance =hinst;
        wndclass.hIcon=NULL;
        wndclass.hCursor=LoadCursor(NULL,IDC_ARROW);
        wndclass.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);
        wndclass.lpszMenuName=NULL;
        wndclass.lpszClassName=szClassName;
        if(!RegisterClass(&wndclass))
            return FALSE;
    }
    hWnd=CreateWindow(szClassName,
        "ƒ^ƒCƒgƒ‹",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        hinst,
        NULL);
    ShowWindow(hWnd,nCmdShow);
    UpdateWindow(hWnd);
    while (GetMessage(&msg,NULL,0,0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (msg.wParam);
}


