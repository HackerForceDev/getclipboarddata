#include <windows.h>
#include <winuser.h>
#include <stdint.h>

typedef int (*goCallback)(const char *, int);

__declspec(dllexport) int __cdecl entrypoint(
    char *argsBuffer,
    uint32_t bufferSize,
    goCallback callback
);

int entrypoint(char *argsBuffer, uint32_t bufferSize, goCallback callback) {
    // Open clipboard for reading
    if (OpenClipboard(NULL) == 0) {
        return 1;
    }

    HANDLE hClipboardData = GetClipboardData(CF_TEXT);
    if (hClipboardData == NULL) {
        CloseClipboard();
        return 1;
    }

    // Lock clipboard and return pointer to clipboard memory block
    CHAR *dataString = (CHAR *)GlobalLock(hClipboardData);
    if (dataString == NULL) {
        CloseClipboard();
        return 1;
    }

    // Unlock clipboard memory block
    GlobalUnlock(hClipboardData);
    CloseClipboard();

    return callback(dataString, strlen(dataString));
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    return TRUE;
}