// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "resource.h"
#include "UserInfo.h"

INT_PTR CALLBACK Dlgproc(HWND unnamedParam1, UINT unnamedParam2, WPARAM unnamedParam3, LPARAM unnamedParam4);
VOID Button_Click(HWND unnamedParam1, WPARAM unnamedParam3);

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DialogBox(hModule, MAKEINTRESOURCE(ID_MAIN), NULL, &Dlgproc);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

INT_PTR CALLBACK Dlgproc(HWND unnamedParam1, UINT unnamedParam2, WPARAM unnamedParam3, LPARAM unnamedParam4) 
{
    switch (unnamedParam2)
    {
    case WM_INITDIALOG:
        // 窗口初始化
        break;
    case WM_CLOSE:
        EndDialog(unnamedParam1, NULL);
        break;
    case WM_COMMAND:
        Button_Click(unnamedParam1, unnamedParam3);
        break;
    default:
        break;
    }
    return false;
}

VOID Button_Click(HWND unnamedParam1, WPARAM unnamedParam3)
{
    switch (unnamedParam3)
    {
    case ID_READ_USERINFO:
        ReadWXID(unnamedParam1);
        break;
    default:
        break;
    }
}