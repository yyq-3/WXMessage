#include "pch.h"
#include "UserInfo.h"


DWORD GetWeChatAddr() {
	HMODULE hModule = LoadLibrary("WeChatWin.dll");
	return (DWORD)(hModule);
}

//΢�ź� WeChatWin.dll+21DCBB8
//�ǳ� WeChatWin.dll+21DCA3C
//wxid 21D C9C4
//ͷ�� 21D CD1C
//���� 21D CA58

VOID ReadWXID(HWND hWnd) 
{
	DWORD baseAddr = GetWeChatAddr();
	if (NULL == baseAddr)
	{
		MessageBox(NULL, "��ȡʧ��!", "����", 0);
		return;
	}
	char buffer[0x100] = {};
	// WXID
	DWORD onePoint = baseAddr + 0x021DC9C4;
	sprintf_s(buffer, "%s", *(DWORD*)(onePoint));
	SetDlgItemText(hWnd, ID_EDIT1, buffer);
	// ΢�ź�
	onePoint = baseAddr + 0x021DCBB8;
	sprintf_s(buffer, "%s", onePoint);
	SetDlgItemText(hWnd, ID_EDIT2, buffer);
	// ����
	onePoint = baseAddr + 0x021DCA58;
	sprintf_s(buffer, "%s", *(DWORD*)(onePoint));
	SetDlgItemText(hWnd, ID_EDIT3, buffer);
	// ͷ��
	onePoint = baseAddr + 0x021DCD1C;
	sprintf_s(buffer, "%s", *(DWORD*)(onePoint));
	
	
}