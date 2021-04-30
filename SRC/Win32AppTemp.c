#include <windows.h>

int brushes[] = {
	WHITE_BRUSH, BLACK_BRUSH,	
	GRAY_BRUSH, LTGRAY_BRUSH, DKGRAY_BRUSH,	
	HOLLOW_BRUSH, NULL_BRUSH
};

HRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hNow, HINSTANCE hPrev, LPSTR lpCmdLine, int iCmdShow)
{
	MSG msg;
	
	TCHAR szClassName[] = TEXT("Assistant");
	TCHAR szWindowName[] = TEXT("My Window");
	
	WNDCLASS wc = {
		CS_VREDRAW | CS_HREDRAW,		// 类风格		
		(WNDPROC)WndProc,		// ！！！需要强制转换
		0, 0,		//共享空间，独立空间
		
		hNow,
		LoadIcon(NULL, IDI_APPLICATION),
		LoadCursor(NULL, IDC_ARROW),
		(HBRUSH)GetStockObject(brushes[2]),		// GDI32.lib/wingdi.h 库中的定义的白色画刷, 头文件被包含在Windows.h 中
		NULL,
		szClassName		
	};
		
	// 注册指定的窗口类
	ATOM flag = RegisterClass(&wc);	
	
	if(!flag)
	{
		MessageBox(NULL, TEXT("register failed!"), TEXT("Warning"), MB_OK);
	}
	
	// 创建窗口
	HWND hwnd = CreateWindow(
	szClassName,
	szWindowName,
	WS_OVERLAPPEDWINDOW,
	100, 100,
	800, 600,
	NULL, NULL,
	hNow, NULL	
	);
	
	if(!hwnd)
	{
		MessageBox(NULL, TEXT("Create Window Failed!"), TEXT("Warning"), MB_OK);
	}
	
	// 显示窗口， 因为使用Create类函数创建的窗口，必须手动显示
	ShowWindow(hwnd, SW_SHOWNORMAL);
	// 更新窗口，让客户区绘图
	UpdateWindow(hwnd);
	// message loop	
	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
		
	return msg.wParam;	
}

HRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message){
		case WM_CREATE:
		// MessageBox(NULL, TEXT("Enter the WndProc OK!"), TEXT("Warning"), MB_OK);
		break;
		
		case WM_DESTROY:
		PostQuitMessage(0);
		break;
		
		default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	
	return 0;	
}
