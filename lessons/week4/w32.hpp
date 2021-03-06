#pragma once

/*
    This single file is meant to be enough win32 to put a window up on the screen
    and draw a pixel buffer into it.

    It contains most of the common int and pointer types, and is aware of 32 and 64-bit
    versions.

    All manner of input; mouse, keyboard, touch, gesture, joystick, are supported.

    What's not in here are things like DirectX, Winmm, file system, and the like.  The intention
    would be that you would take this basic win32.lua, include it in your project, then add the
    bindings that you want for your specific application needs.
*/

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


// 8-bit values
    typedef char                CHAR;
    typedef signed char         INT8;
    typedef unsigned char       UCHAR;
    typedef unsigned char       UINT8;
    typedef unsigned char       BYTE;
    
// 16-bit values
    typedef int16_t             SHORT;
    typedef int16_t             INT16;
    typedef uint16_t            USHORT;
    typedef uint16_t            UINT16;
    typedef uint16_t            WORD;
    typedef uint16_t            WCHAR;    // wc,   16-bit UNICODE character
    
// typically 32-bit values
    typedef int                 INT;
    typedef int                 BOOL;
    typedef int32_t             INT32;
    typedef unsigned int        UINT;
    typedef unsigned int        UINT32;
    typedef long                LONG;
    typedef unsigned long       ULONG;
    typedef unsigned long       DWORD;

// 64-bit values
    typedef int64_t             LONGLONG;
    typedef int64_t             LONG64;
    typedef int64_t             INT64;
    typedef uint64_t            ULONGLONG;
    typedef uint64_t            DWORDLONG;
    typedef uint64_t            ULONG64;
    typedef uint64_t            DWORD64;
    typedef uint64_t            UINT64;


#ifdef _WIN64

    typedef int64_t   INT_PTR;
    typedef uint64_t  UINT_PTR;
    typedef int64_t   LONG_PTR;
    typedef uint64_t  ULONG_PTR;

#else

    typedef int             INT_PTR;
    typedef unsigned int    UINT_PTR;
    typedef long            LONG_PTR;
    typedef unsigned long   ULONG_PTR;

#endif

#ifdef _WIN64
typedef INT_PTR ( __stdcall *FARPROC)();
typedef INT_PTR ( __stdcall *NEARPROC)();
typedef INT_PTR (__stdcall *PROC)();
#else
typedef int ( __stdcall *FARPROC)();
typedef int ( __stdcall *NEARPROC)();
typedef int ( __stdcall *PROC)();
#endif

typedef void * LPVOID;



/* Types use for passing & returning polymorphic values */
typedef UINT_PTR            WPARAM;
typedef LONG_PTR            LPARAM;
typedef LONG_PTR            LRESULT;



typedef ULONG_PTR   DWORD_PTR;
typedef LONG_PTR    SSIZE_T;
typedef ULONG_PTR   SIZE_T;

typedef BOOL             *LPBOOL;
typedef void *HANDLE;

typedef BYTE *      PBYTE;
typedef ULONG *     PULONG;

// winnt
typedef  const CHAR *LPCSTR, *PCSTR;
typedef  const PCSTR *PCZPCSTR;

static const int MINCHAR    = 0x80;        
static const int MAXCHAR    = 0x7f;        
static const int MINSHORT   = 0x8000;      
static const int MAXSHORT   = 0x7fff;      
static const int MINLONG    = 0x80000000;  
static const int MAXLONG    = 0x7fffffff;  
static const int MAXBYTE    = 0xff;        
static const int MAXWORD    = 0xffff;      
static const int MAXDWORD   = 0xffffffff;  



// windef

typedef DWORD   COLORREF;
typedef DWORD   *LPCOLORREF;

typedef struct tagPOINT
{
    LONG  x;
    LONG  y;
} POINT, *PPOINT, *NPPOINT, *LPPOINT;
    
typedef struct tagPOINTS
{
    SHORT   x;
    SHORT   y;
} POINTS, *PPOINTS, *LPPOINTS;

typedef struct tagSIZE
{
    LONG        cx;
    LONG        cy;
} SIZE, *PSIZE, *LPSIZE;

typedef struct tagRECT
{
    LONG    left;
    LONG    top;
    LONG    right;
    LONG    bottom;
} RECT, *PRECT, *NPRECT, *LPRECT;
typedef const RECT * LPCRECT;


// winuser

// Class styles
static const int CS_VREDRAW         = 0x0001;
static const int CS_HREDRAW         = 0x0002;
static const int CS_OWNDC           = 0x0020;

// Extended Window Styles
static const int WS_EX_TOPMOST           = 0x00000008L;
static const int WS_EX_ACCEPTFILES       = 0x00000010L;
static const int WS_EX_TRANSPARENT       = 0x00000020L;

static const int WS_EX_LAYERED           = 0x00080000;
static const int WS_EX_NOREDIRECTIONBITMAP = 0x00200000;

// Window styles
static const int WS_OVERLAPPED       = 0x00000000;
static const int WS_CAPTION          = 0x00C00000;     /* WS_BORDER | WS_DLGFRAME  */
static const int WS_SYSMENU          = 0x00080000;
static const int WS_THICKFRAME       = 0x00040000;
static const int WS_MINIMIZEBOX      = 0x00020000;
static const int WS_MAXIMIZEBOX      = 0x00010000;
static const int WS_POPUP            = 0x80000000L;
static const int WS_OVERLAPPEDWINDOW = WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_THICKFRAME|WS_MINIMIZEBOX|WS_MAXIMIZEBOX;

// window showing
static const int SW_HIDE            = 0;
static const int SW_SHOWNORMAL      = 1;
static const int SW_NORMAL          = 1;
static const int SW_SHOW            = 5;

// Window redrawing
static const int RDW_INVALIDATE          = 0x0001;
static const int RDW_INTERNALPAINT       = 0x0002;
static const int RDW_ERASE               = 0x0004;

static const int RDW_VALIDATE            = 0x0008;
static const int RDW_NOINTERNALPAINT     = 0x0010;
static const int RDW_NOERASE             = 0x0020;


static const int RDW_UPDATENOW           = 0x0100;
static const int RDW_ERASENOW            = 0x0200;



static const int PM_REMOVE  =  0x0001;

static const int CW_USEDEFAULT      = 0x80000000;
static const int COLOR_WINDOW          =  5;

// Layered Window Constants
static const int  LWA_COLORKEY          =  0x00000001;
static const int  LWA_ALPHA             =  0x00000002;


static const int  ULW_COLORKEY          =  0x00000001;
static const int  ULW_ALPHA             =  0x00000002;
static const int  ULW_OPAQUE            =  0x00000004;

static const int  ULW_EX_NORESIZE       =  0x00000008;

// GDI constants
static const int BI_RGB       = 0;
static const int DIB_RGB_COLORS     = 0; /* color table in RGBs */
static const int SRCCOPY           =  0x00CC0020; /* dest = source                   */


// GetSystemMetrics

static const int SM_CXSCREEN = 0;
static const int SM_CYSCREEN = 1;



/*
 * SetWindowPos Flags
 */
static const int SWP_NOSIZE         = 0x0001;
static const int SWP_NOMOVE         = 0x0002;
static const int SWP_NOZORDER       = 0x0004;
static const int SWP_NOREDRAW       = 0x0008;
static const int SWP_NOACTIVATE     = 0x0010;
static const int SWP_FRAMECHANGED   = 0x0020;  /* The frame changed: send WM_NCCALCSIZE */
static const int SWP_SHOWWINDOW     = 0x0040;
static const int SWP_HIDEWINDOW     = 0x0080;
static const int SWP_NOCOPYBITS     = 0x0100;
static const int SWP_NOOWNERZORDER  = 0x0200;  /* Don't do owner Z ordering */
static const int SWP_NOSENDCHANGING = 0x0400;  /* Don't send WM_WINDOWPOSCHANGING */

static const int SWP_DRAWFRAME      = SWP_FRAMECHANGED;
static const int SWP_NOREPOSITION   = SWP_NOOWNERZORDER;




// Types
typedef HANDLE HDC;
typedef HANDLE HGDIOBJ;
typedef HANDLE HWND;
typedef HANDLE HICON;
typedef HANDLE HCURSOR;
typedef HANDLE HBRUSH;
typedef HANDLE HINSTANCE;
typedef HANDLE HMENU;
typedef HANDLE HBITMAP;
typedef HANDLE HRGN;
typedef HANDLE HTOUCHINPUT;

typedef HANDLE DPI_AWARENESS_CONTEXT;


#define DPI_AWARENESS_CONTEXT_SYSTEM_AWARE  (DPI_AWARENESS_CONTEXT,-2);
#define DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2  (DPI_AWARENESS_CONTEXT,-4);



typedef WORD                ATOM; 

typedef LRESULT (__stdcall* WNDPROC)(HWND, UINT, WPARAM, LPARAM);

typedef struct tagWNDCLASSEXA {
        UINT        cbSize;
        /* Win 3.x */
        UINT        style;
        WNDPROC     lpfnWndProc;
        int         cbClsExtra;
        int         cbWndExtra;
        HINSTANCE   hInstance;
        HICON       hIcon;
        HCURSOR     hCursor;
        HBRUSH      hbrBackground;
        const char *      lpszMenuName;
        const char *      lpszClassName;
        /* Win 4.0 */
        HICON       hIconSm;
} WNDCLASSEXA, *PWNDCLASSEXA, *LPWNDCLASSEXA;

typedef struct tagPAINTSTRUCT {
    HDC         hdc;
    int        fErase;
    RECT        rcPaint;
    int        fRestore;
    int        fIncUpdate;
    uint8_t        rgbReserved[32];
} PAINTSTRUCT, *PPAINTSTRUCT, *NPPAINTSTRUCT, *LPPAINTSTRUCT;

typedef struct tagMSG {
    HWND        hwnd;
    UINT        message;
    WPARAM      wParam;
    LPARAM      lParam;
    DWORD       time;
    POINT       pt;
} MSG, *PMSG, *LPMSG;

typedef struct tagRGBQUAD {
    BYTE    rgbBlue;
    BYTE    rgbGreen;
    BYTE    rgbRed;
    BYTE    rgbReserved;
} RGBQUAD;

typedef struct tagBITMAPINFOHEADER{
    DWORD      biSize;
    LONG       biWidth;
    LONG       biHeight;
    WORD       biPlanes;
    WORD       biBitCount;
    DWORD      biCompression;
    DWORD      biSizeImage;
    LONG       biXPelsPerMeter;
    LONG       biYPelsPerMeter;
    DWORD      biClrUsed;
    DWORD      biClrImportant;
} BITMAPINFOHEADER,  *LPBITMAPINFOHEADER, *PBITMAPINFOHEADER;

typedef struct tagBITMAPINFO {
    BITMAPINFOHEADER    bmiHeader;
    RGBQUAD             bmiColors[1];
} BITMAPINFO,  *LPBITMAPINFO, *PBITMAPINFO;



typedef struct _BLENDFUNCTION
{
    BYTE   BlendOp;
    BYTE   BlendFlags;
    BYTE   SourceConstantAlpha;
    BYTE   AlphaFormat;
}BLENDFUNCTION,*PBLENDFUNCTION;

static const int AC_SRC_OVER                = 0x00;
static const int AC_SRC_ALPHA               = 0x01;



// Touch Input defines and functions

typedef struct tagTOUCHINPUT {
    LONG x;
    LONG y;
    HANDLE hSource;
    DWORD dwID;
    DWORD dwFlags;
    DWORD dwMask;
    DWORD dwTime;
    ULONG_PTR dwExtraInfo;
    DWORD cxContact;
    DWORD cyContact;
} TOUCHINPUT, *PTOUCHINPUT;
typedef TOUCHINPUT const * PCTOUCHINPUT;




static const int MK_LBUTTON         = 0x0001;
static const int MK_RBUTTON         = 0x0002;
static const int MK_SHIFT           = 0x0004;
static const int MK_CONTROL         = 0x0008;
static const int MK_MBUTTON         = 0x0010;
static const int MK_XBUTTON1        = 0x0020;
static const int MK_XBUTTON2        = 0x0040;


// Window Messages

static const int WM_DESTROY     = 0x0002;
static const int WM_PAINT       = 0x000F;
static const int WM_QUIT        = 0x0012;

static const int WM_ERASEBKGND  =  0x0014;


// raw input

static const int WM_INPUT_DEVICE_CHANGE          = 0x00FE;
static const int WM_INPUT                        = 0x00FF;


// Keyboard messages

static const int WM_KEYFIRST                     = 0x0100;
static const int WM_KEYDOWN                      = 0x0100;
static const int WM_KEYUP                        = 0x0101;
static const int WM_CHAR                         = 0x0102;
static const int WM_DEADCHAR                     = 0x0103;
static const int WM_SYSKEYDOWN                   = 0x0104;
static const int WM_SYSKEYUP                     = 0x0105;
static const int WM_SYSCHAR                      = 0x0106;
static const int WM_SYSDEADCHAR                  = 0x0107;

static const int WM_UNICHAR                      = 0x0109;
static const int WM_KEYLAST                      = 0x0109;


// Mouse Messages

static const int WM_MOUSEFIRST                   = 0x0200;
static const int WM_MOUSEMOVE                    = 0x0200;
static const int WM_LBUTTONDOWN                  = 0x0201;
static const int WM_LBUTTONUP                    = 0x0202;
static const int WM_LBUTTONDBLCLK                = 0x0203;
static const int WM_RBUTTONDOWN                  = 0x0204;
static const int WM_RBUTTONUP                    = 0x0205;
static const int WM_RBUTTONDBLCLK                = 0x0206;
static const int WM_MBUTTONDOWN                  = 0x0207;
static const int WM_MBUTTONUP                    = 0x0208;
static const int WM_MBUTTONDBLCLK                = 0x0209;
static const int WM_MOUSEWHEEL                   = 0x020A;
static const int WM_XBUTTONDOWN                  = 0x020B;
static const int WM_XBUTTONUP                    = 0x020C;
static const int WM_XBUTTONDBLCLK                = 0x020D;
static const int WM_MOUSEHWHEEL                  = 0x020E;
static const int WM_MOUSELAST                    = 0x020E;



static const int WM_MOUSEHOVER                   = 0x02A1;
static const int WM_MOUSELEAVE                   = 0x02A3;





static const int WM_DPICHANGED                   = 0x02E0;

// Multimedia Extensions Window Messages

static const int MM_JOY1MOVE         = 0x3A0;           /* joystick */
static const int MM_JOY2MOVE         = 0x3A1;
static const int MM_JOY1ZMOVE        = 0x3A2;
static const int MM_JOY2ZMOVE        = 0x3A3;
static const int MM_JOY1BUTTONDOWN   = 0x3B5;
static const int MM_JOY2BUTTONDOWN   = 0x3B6;
static const int MM_JOY1BUTTONUP     = 0x3B7;
static const int MM_JOY2BUTTONUP     = 0x3B8;


// Touch Window Messages

static const int WM_TOUCH                        = 0x0240;
static const int WM_GESTURE                      = 0x0119;
static const int WM_GESTURENOTIFY                = 0x011A;



/*
 * Touch input flag values (TOUCHINPUT.dwFlags)
 */
static const int TOUCHEVENTF_MOVE            = 0x0001;
static const int TOUCHEVENTF_DOWN            = 0x0002;
static const int TOUCHEVENTF_UP              = 0x0004;
static const int TOUCHEVENTF_INRANGE         = 0x0008;
static const int TOUCHEVENTF_PRIMARY         = 0x0010;
static const int TOUCHEVENTF_NOCOALESCE      = 0x0020;
static const int TOUCHEVENTF_PEN             = 0x0040;
static const int TOUCHEVENTF_PALM            = 0x0080;

/*
 * Touch input mask values (TOUCHINPUT.dwMask)
 */
static const int TOUCHINPUTMASKF_TIMEFROMSYSTEM  = 0x0001;  // the dwTime field contains a system generated value
static const int TOUCHINPUTMASKF_EXTRAINFO       = 0x0002;  // the dwExtraInfo field is valid
static const int TOUCHINPUTMASKF_CONTACTAREA     = 0x0004;  // the cxContact and cyContact fields are valid

// RegisterTouchWindow flag values
static const int TWF_FINETOUCH      = 0x00000001;
static const int TWF_WANTPALM       = 0x00000002;



// * Gesture information handle

typedef HANDLE HGESTUREINFO;



/*
 * Gesture flags - GESTUREINFO.dwFlags
 */
static const int GF_BEGIN                       = 0x00000001;
static const int GF_INERTIA                     = 0x00000002;
static const int GF_END                         = 0x00000004;

/*
 * Gesture IDs
 */
static const int GID_BEGIN                      = 1;
static const int GID_END                        = 2;
static const int GID_ZOOM                       = 3;
static const int GID_PAN                        = 4;
static const int GID_ROTATE                     = 5;
static const int GID_TWOFINGERTAP               = 6;
static const int GID_PRESSANDTAP                = 7;
static const int GID_ROLLOVER                   = GID_PRESSANDTAP;



/*
 * Gesture information structure
 *   - Pass the HGESTUREINFO received in the WM_GESTURE message lParam into the
 *     GetGestureInfo function to retrieve this information.
 *   - If cbExtraArgs is non-zero, pass the HGESTUREINFO received in the WM_GESTURE
 *     message lParam into the GetGestureExtraArgs function to retrieve extended
 *     argument information.
 */
typedef struct tagGESTUREINFO {
    UINT cbSize;                    // size, in bytes, of this structure (including variable length Args field)
    DWORD dwFlags;                  // see GF_* flags
    DWORD dwID;                     // gesture ID, see GID_* defines
    HWND hwndTarget;                // handle to window targeted by this gesture
    POINTS ptsLocation;             // current location of this gesture
    DWORD dwInstanceID;             // internally used
    DWORD dwSequenceID;             // internally used
    ULONGLONG ullArguments;         // arguments for gestures whose arguments fit in 8 BYTES
    UINT cbExtraArgs;               // size, in bytes, of extra arguments, if any, that accompany this gesture
} GESTUREINFO, *PGESTUREINFO;
typedef GESTUREINFO const * PCGESTUREINFO;


/*
 * Gesture notification structure
 *   - The WM_GESTURENOTIFY message lParam contains a pointer to this structure.
 *   - The WM_GESTURENOTIFY message notifies a window that gesture recognition is
 *     in progress and a gesture will be generated if one is recognized under the
 *     current gesture settings.
 */
typedef struct tagGESTURENOTIFYSTRUCT {
    UINT cbSize;                    // size, in bytes, of this structure
    DWORD dwFlags;                  // unused
    HWND hwndTarget;                // handle to window targeted by the gesture
    POINTS ptsLocation;             // starting location
    DWORD dwInstanceID;             // internally used
} GESTURENOTIFYSTRUCT, *PGESTURENOTIFYSTRUCT;



//    Related to raw input

static const int RIDEV_REMOVE           = 0x00000001;
static const int RIDEV_EXCLUDE          = 0x00000010;
static const int RIDEV_PAGEONLY         = 0x00000020;
static const int RIDEV_NOLEGACY         = 0x00000030;
static const int RIDEV_INPUTSINK        = 0x00000100;
static const int RIDEV_CAPTUREMOUSE     = 0x00000200;  // effective when mouse nolegacy is specified, otherwise it would be an error
static const int RIDEV_NOHOTKEYS        = 0x00000200;  // effective for keyboard.
static const int RIDEV_APPKEYS          = 0x00000400; // effective for keyboard.
static const int RIDEV_EXINPUTSINK      = 0x00001000;
static const int RIDEV_DEVNOTIFY        = 0x00002000;
static const int RIDEV_EXMODEMASK       = 0x000000F0;



typedef struct tagRAWINPUTDEVICE {
    USHORT usUsagePage; // Toplevel collection UsagePage
    USHORT usUsage;     // Toplevel collection Usage
    DWORD dwFlags;
    HWND hwndTarget;    // Target hwnd. NULL = follows keyboard focus
} RAWINPUTDEVICE, *PRAWINPUTDEVICE, *LPRAWINPUTDEVICE;

typedef const RAWINPUTDEVICE* PCRAWINPUTDEVICE;



static const int GIDC_ARRIVAL        =     1;
static const int GIDC_REMOVAL        =     2;



static const int    RIM_INPUT      = 0;
static const int    RIM_INPUTSINK  = 1;



/*
 * Raw Input data header
 */
typedef struct tagRAWINPUTHEADER {
    DWORD dwType;
    DWORD dwSize;
    HANDLE hDevice;
    WPARAM wParam;
} RAWINPUTHEADER, *PRAWINPUTHEADER, *LPRAWINPUTHEADER;

/*
 * Raw format of the mouse input
 */
 typedef struct tagRAWMOUSE {
    USHORT usFlags;

    union {
        ULONG ulButtons;
        struct  {
            USHORT  usButtonFlags;
            USHORT  usButtonData;
        } ;
    } ;

    ULONG ulRawButtons;
    LONG lLastX;
    LONG lLastY;
    ULONG ulExtraInformation;
} RAWMOUSE, *PRAWMOUSE, *LPRAWMOUSE;

/*
 * Raw format of the keyboard input
 */
typedef struct tagRAWKEYBOARD {
    USHORT MakeCode;
    USHORT Flags;
    USHORT Reserved;
    USHORT VKey;
    UINT   Message;
    ULONG ExtraInformation;
} RAWKEYBOARD, *PRAWKEYBOARD, *LPRAWKEYBOARD;

/*
 * Raw format of the input from Human Input Devices
 */
typedef struct tagRAWHID {
    DWORD dwSizeHid;    // byte size of each report
    DWORD dwCount;      // number of input packed
    BYTE bRawData[1];
} RAWHID, *PRAWHID, *LPRAWHID;


/*
 * RAWINPUT data structure.
 */
typedef struct tagRAWINPUT {
    RAWINPUTHEADER header;
    union {
        RAWMOUSE    mouse;
        RAWKEYBOARD keyboard;
        RAWHID      hid;
    } data;
} RAWINPUT, *PRAWINPUT, *LPRAWINPUT;




BOOL __stdcall RegisterRawInputDevices(PCRAWINPUTDEVICE pRawInputDevices, UINT uiNumDevices, UINT cbSize);



// libloaderapi

typedef HANDLE HMODULE;

HMODULE  GetModuleHandleA(const char * lpModuleName);
FARPROC __stdcall GetProcAddress(HMODULE hModule, LPCSTR lpProcName);

// profileapi

int QueryPerformanceCounter(int64_t * lpPerformanceCount);
int QueryPerformanceFrequency(int64_t * lpFrequency);


DWORD __stdcall GetLastError(void);

// Basic Window management
ATOM RegisterClassExA(const WNDCLASSEXA *);
HWND CreateWindowExA(DWORD dwExStyle, const char * lpClassName, const char * lpWindowName, DWORD dwStyle,
     int X, int Y, int nWidth, int nHeight,
     HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, void * lpParam);
LRESULT DefWindowProcA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
BOOL DestroyWindow(HWND hWnd);
BOOL GetClientRect(HWND   hWnd, LPRECT lpRect);
BOOL GetWindowRect(HWND hWnd, LPRECT lpRect);
UINT GetDpiForWindow(HWND hwnd);
int GetSystemMetrics(int nIndex);
BOOL InvalidateRect(HWND hWnd, const RECT *lpRect, BOOL bErase);
BOOL RedrawWindow(HWND hWnd, const RECT *lprcUpdate, HRGN hrgnUpdate, UINT flags);
BOOL ScreenToClient(HWND hWnd, LPPOINT lpPoint);
BOOL SetWindowPos(HWND hWnd, HWND hWndInsertAfter,int X,int Y,int cx,int cy, UINT uFlags);
BOOL ShowWindow(HWND hWnd, int nCmdShow);
BOOL UpdateLayeredWindow(HWND hWnd, HDC hdcDst, POINT* pptDst, SIZE* psize, 
    HDC hdcSrc, POINT* pptSrc, 
    COLORREF crKey, 
    BLENDFUNCTION* pblend, 
    DWORD dwFlags);

DPI_AWARENESS_CONTEXT SetThreadDpiAwarenessContext(DPI_AWARENESS_CONTEXT dpiContext);
UINT __stdcall GetDpiForSystem();

// Touch Related founctions
BOOL RegisterTouchWindow(HWND hwnd, ULONG ulFlags);
BOOL UnregisterTouchWindow(HWND hwnd);
BOOL IsTouchWindow(HWND hwnd, PULONG pulFlags);

// Regular Windows messaging
void PostQuitMessage(int nExitCode);
int PeekMessageA(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg);
int TranslateMessage(const MSG *lpMsg);
LRESULT DispatchMessageA(const MSG *lpMsg);

BOOL GetKeyboardState(PBYTE lpKeyState);
SHORT GetAsyncKeyState(int vKey);

// Windows paint
HDC BeginPaint(HWND hWnd, LPPAINTSTRUCT lpPaint);
int EndPaint(HWND hWnd, const PAINTSTRUCT *lpPaint);

// wingdi
HDC GetDC(HWND hWnd);
int ReleaseDC(HWND hWnd,HDC  hDC);
HDC CreateCompatibleDC(HDC hdc);
HGDIOBJ SelectObject(HDC hdc, HGDIOBJ h);

HBITMAP CreateDIBSection(HDC hdc, const BITMAPINFO *pbmi, UINT usage, void **ppvBits, HANDLE hSection, DWORD offset);
int  BitBlt(  HDC hdc,  int x,  int y,  int cx,  int cy,  HDC hdcSrc,  int x1,  int y1,  uint32_t rop);
BOOL StretchBlt(HDC   hdcDest, int   xDest, int   yDest, int   wDest, int   hDest,
  HDC   hdcSrc, int   xSrc, int   ySrc, int   wSrc, int   hSrc,
  DWORD rop);
int  StretchDIBits( HDC hdc,  int xDest,  int yDest,  int DestWidth,  int DestHeight,  
    int xSrc,  int ySrc,  int SrcWidth,  int SrcHeight,
    const void * lpBits,  const BITMAPINFO * lpbmi,  UINT iUsage,  DWORD rop);

//BOOL Rectangle( HDC hdc,  int left,  int top,  int right,  int bottom);

// hTouchInput - input event handle; from touch message lParam
// cInputs - number of elements in the array
// pInputs - array of touch inputs
// cbSize - sizeof(TOUCHINPUT)
BOOL GetTouchInputInfo(HTOUCHINPUT hTouchInput, UINT cInputs, PTOUCHINPUT pInputs, int cbSize);                           
BOOL CloseTouchInputHandle(HTOUCHINPUT hTouchInput);                   // input event handle; from touch message lParam




/*
 * Gesture information retrieval
 *   - HGESTUREINFO is received by a window in the lParam of a WM_GESTURE message.
 */

BOOL
__stdcall
GetGestureInfo(
     HGESTUREINFO hGestureInfo,
     PGESTUREINFO pGestureInfo);


BOOL
__stdcall
GetGestureExtraArgs(
     HGESTUREINFO hGestureInfo,
     UINT cbExtraArgs,
     PBYTE pExtraArgs);


BOOL
__stdcall
CloseGestureInfoHandle(
     HGESTUREINFO hGestureInfo);


#define LOWORD(l)         WORD(DWORD_PTR(l) & 0xffff)
#define HIWORD(l)         WORD((DWORD_PTR(l) >> 16) & 0xffff)

#define GET_Y_LPARAM(lp) ((int)(short)HIWORD(lp)) 
#define GET_X_LPARAM(lp) ((int)(short)LOWORD(lp)) 

// Conversion of touch input coordinates to pixels
//function exports.TOUCH_COORD_TO_PIXEL(l) return ((l) / 100) end

/*
 * Gesture argument helpers
 *   - Angle should be a double in the range of -2pi to +2pi
 *   - Argument should be an unsigned 16-bit value
 */
//function exports.GID_ROTATE_ANGLE_TO_ARGUMENT(_arg_)     ((USHORT)((((_arg_) + 2.0 * 3.14159265) / (4.0 * 3.14159265)) * 65535.0))
//function exports.GID_ROTATE_ANGLE_FROM_ARGUMENT(_arg_)   ((((double)(_arg_) / 65535.0) * 4.0 * 3.14159265) - 2.0 * 3.14159265)


#ifdef __cplusplus
}
#endif

