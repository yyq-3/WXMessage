#include "pch.h"
#include "UserInfo.h"


DWORD GetWeChatAddr() {
	HMODULE hModule = LoadLibrary("WeChatWin.dll");
	return (DWORD)(hModule);
}

//Œ¢–≈∫≈ WeChatWin.dll+21DCBB8
//Í«≥∆ WeChatWin.dll+21DCA3C
//wxid 21D C9C4
//Õ∑œÒ 21D CD1C
//” œ‰ 21D CA58

VOID ReadWXID(HWND hWnd) 
{
	DWORD baseAddr = GetWeChatAddr();
	if (NULL == baseAddr)
	{
		MessageBox(NULL, "∂¡»° ß∞‹!", "¥ÌŒÛ", 0);
		return;
	}
	char buffer[0x100] = {};
	// WXID
	DWORD onePoint = baseAddr + 0x021DC9C4;
	sprintf_s(buffer, "%s", *(DWORD*)(onePoint));
	SetDlgItemText(hWnd, ID_EDIT1, buffer);
	// Œ¢–≈∫≈
	onePoint = baseAddr + 0x021DCBB8;
	sprintf_s(buffer, "%s", onePoint);
	SetDlgItemText(hWnd, ID_EDIT2, buffer);
	// ” œ‰
	onePoint = baseAddr + 0x021DCA58;
	sprintf_s(buffer, "%s", *(DWORD*)(onePoint));
	SetDlgItemText(hWnd, ID_EDIT3, buffer);
	// Õ∑œÒ
	onePoint = baseAddr + 0x021DCD1C;
	sprintf_s(buffer, "%s", *(DWORD*)(onePoint));
	
	
}