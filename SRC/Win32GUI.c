

// https://www.cnblogs.com/sfqtsh/p/3379585.html

#include <windows.h>

int brushes[] = {
	WHITE_BRUSH, 	BLACK_BRUSH,	
	GRAY_BRUSH,	LTGRAY_BRUSH,	DKGRAY_BRUSH,	
	HOLLOW_BRUSH,	NULL_BRUSH
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
		(HBRUSH)GetStockObject(brushes[5]),		// GDI32.lib/wingdi.h 库中的定义的白色画刷, 头文件被包含在Windows.h 中
		NULL,
		szClassName		
	};	
	
	// 注册指定的窗口类
	ATOM flag = RegisterClass(&wc);	
	
	if(!flag)
	{
		MessageBox(NULL, TEXT("register failed!"), TEXT("Warning"), MB_OK);
		//  !!! Donot forget to exit 
		return 0;
	}
	
	// 创建窗口
	HWND hwnd = CreateWindow(
	szClassName,
	szWindowName,
	WS_OVERLAPPEDWINDOW,
	
	CW_USEDEFAULT,
	CW_USEDEFAULT,
	CW_USEDEFAULT,
	CW_USEDEFAULT,
	
	NULL, 
	NULL, 
	hNow, 
	NULL);
	
	if(!hwnd)
	{
		MessageBox(NULL, TEXT("Create Window Failed!"), TEXT("Warning"), MB_OK);
		
		//  !!! Donot forget to exit 
		return 0;
	}
	
	// 显示窗口， 因为使用Create类函数创建的窗口，必须手动显示
	ShowWindow(hwnd, iCmdShow);	//SW_SHOWNORMAL
	// 更新窗口，让客户区绘图
	UpdateWindow(hwnd);
	
	// Message Loop
	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
		
	return msg.wParam;	
}

HRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hDC;
	RECT rect;
	
	switch (message)
	{
		case WM_CREATE:
		// MessageBox(NULL, TEXT("Enter the WndProc OK!"), TEXT("Warning"), MB_OK);
		return 0;
		
		case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		
		TextOut(hDC, 30, 270, TEXT("Good day!"), 8);
		
		GetClientRect(hWnd, &rect);
		DrawText(hDC, TEXT("ALOHA"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		
		EndPaint(hWnd, &ps);
		return 0;
				
		// !!! Necessary. Otherwise the process will not exit even thougth the main window is closed
		case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	
	return DefWindowProc(hWnd, message, wParam, lParam);
}


