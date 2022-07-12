#include <windows.h>

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;

//// 메인 함수 : 윈도우 프로그램의 최초 진입점 ( Entry Point )
/*
ㅇ 매개변수 목록
HINSTANCE hInstance: 프로그램 인스턴스 핸들
HINSTANCE hPrevInstance: 바로 앞에 실행된 프로그램의 인스턴스 핸들, win32에서 의미 없음
PSTR szCmdLine : 명령행으로 입력된 프로그램 인수
int iCmdShow : 프로그램이 실행될 형태, 최소화, 보통 모양등이 전달된다.
*/
int WINAPI WinMain (HINSTANCE hInstance,		
					HINSTANCE hPrevInstance,	
                    PSTR szCmdLine,				
					int iCmdShow)			
{
    //TCHAR 캐릭터셋(유니코드, 멀티바이트)에 따라 char을 할당하는 변수
    //TEXT() -> ANSI와 유니코드 모두 자유롭게 컴파일 하는 매크로.
    static TCHAR szAppName[] = TEXT ("HelloWin") ;
    //콘솔 창 핸들 구조체 선언
    HWND         hwnd ;		
    //메세지 구조체 선언
    MSG          msg ;
    //윈도우 클래스 구조체 선언
    WNDCLASS     wndclass ;	

    //wndclass.style: 윈도우 스타일 옵션 지정, 윈도우 변경시 업데이투 여부 설정(비트연산)
    //CS_HREDRAW - 수평 폭에 대해 윈도우를 다시 그림
    //CS_VREDRAW - 수직 폭에 대해 윈도우를 다시 그림
    wndclass.style         = CS_HREDRAW | CS_VREDRAW ;

    //윈도우에서 발생되는 메세지를 어느 함수에서 처리할지 메세지(msg) 처리 함수의 주소를 받는다.	
    //LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
    wndclass.lpfnWndProc   = WndProc;
    //윈도우 클래스에서 사용할 여분 메모리를 바이트로 지정한다.
    wndclass.cbClsExtra    = 0;
    //개별 윈도우에서 사용할 여분 메모리 영역지정
    wndclass.cbWndExtra    = 0;
    //윈도우 클래스가 사용할 프로그램 인스턴스 핸들
    wndclass.hInstance     = hInstance ;

    //아이콘 모양 지정
    //IDI_APPLICATION: 디폴트 응용 프로그램 아이콘
    //HICON LoadIcon(HINSTANCE hInstance, LPCTSTR lpIconName)
    //HINSTANCE hInstance: 아이콘 리소스를 가지고 있는 인스턴스 핸들
    //LPCTSTR lpIconName: 읽을 아이콘 리소스를 지정하는 문자열의 포인터
    wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;	

    //커서 모양 지정
    //HCURSOR LoadCursor(HINSTANCE hInstance, LPCTSTR lpCursorName)
    //hInstance: 커서 리소스를 가지고 있는 인스턴스의 핸들
    //lpCursorName : 읽을 커서 리소스를 지정하는 문자열의 포인터이다
    wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;		

    //윈도우 배경색 지정
    //HGDIOBJ GetStockObject(int fnObject);
    //fnObject : 사용하고자 하는 스톡 오브젝트(스톡 오브젝트(Stock Object)는 운영체제가 기본적으로 제공해주는 GDI 오브젝트)를 지정
    wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ; 

    //프로그램이 사용할 메뉴 지정
    wndclass.lpszMenuName  = NULL ;

    //윈도우 클래스 이름 지정
    wndclass.lpszClassName = szAppName ;

    //윈도우 클래스 등록
    //CreateWindow()로 윈도우를 생성하기 전에 반드시 등록되어 있어야 한다
    //ATOM RegisterClass(CONST WNDCLASS *lpWndClass);
    //lpWndClass : 등록할 윈도우 클래스의 특성을 지정하는 WNDCLASS 구조체
    //성공할 경우 ATOM 값, 실패할경우 0을 리턴
    if (!RegisterClass (&wndclass))
    {
        //int MessageBox(HWND hWnd, LPCTSTR lpText, LPCTSTR lpCaption, UINT uType);
        //MessageBox: 짧은 메세지를 출력하는 메세지 박스를 출력한다.
        //hWnd: 부모 윈도우의 핸들.메시지 박스의 이 윈도우의 모달 대화상자로 열린다.부모 윈도우가 없을 경우 NULL로 지정할 수 있다.
        //lpText : 메시지 내용을 나타내는 널 종료 문자열.이 문자열은 ANSI 문자열일 수도 있고 유니코드 문자열일 수도 있는데 어떤 포맷이라도 메시지 출력이 가능하다.
        //lpCaption : 메시지 박스의 타이틀 바에 나타날 문자열.NULL일 경우 디폴트로 Error(한글 윈도우즈에서는 오류)가 표시된다.
        //uType : 메시지 박스에 나타날 버튼의 종류와 아이콘 모양, 동작 방식을 지정한다.다음 여러 그룹의 플래그 조합을 지정할 수 있다.
        MessageBox (NULL,
                    TEXT ("This program requires Windows NT!"), 
                    szAppName,
                    MB_ICONINFORMATION) ;
        //메인 함수 종료
        return 0 ;
    }
    
	//// 윈도우 생성
    hwnd = CreateWindow (szAppName, //생성할 윈도우의 윈도우 클래스를 지정하는 문자열이다
                         TEXT ("The Hello Program"), //윈도우의 타이틀 바에 나타날 캡션 문자열이다				  						  
                         WS_OVERLAPPEDWINDOW, //생성될 윈도우의 스타일       
                         CW_USEDEFAULT, //윈도우 x좌표             
                         CW_USEDEFAULT, //윈도우 y좌표             
                         CW_USEDEFAULT, //윈도우의 width값(수평)            
                         CW_USEDEFAULT, //윈도우의 height값(수직)            
                         NULL, //부모 윈도우, 또는 소유주 윈도우의 핸들                      
                         NULL, //오버랩드 윈도우나 팝업 윈도우의 경우 메뉴의 핸들                      
                         hInstance, //이 윈도우를 생성하는 인스턴스 핸들                 
                         NULL) ; //WM_CREATE메시지의 lParam으로 전달될 CREATESTRUCT 구조체를의 포인터이다                    
    
	// 생성된 윈도우를 화면에 표시
    ShowWindow (hwnd, iCmdShow) ;			

    //이 함수는 윈도우 프로시저로 WM_PAINT 메시지를 보내 작업영역을 강제로 그리도록 한다.
    UpdateWindow (hwnd) ;					
    // 메시지 루프
    while (GetMessage (&msg, NULL, 0, 0))		
    {		 
        //이 함수는 메시지 루프내에서 키보드 메시지를 문자 메시지로 변환하기 위한 목적
        TranslateMessage (&msg) ;			
        //이 함수는 GetMessage가 읽은 메시지를 이 메시지를 처리할 윈도우로 보낸다
        //윈도우 클래스에 선언된 wndclass.lpfnWndProc 값에 해당하는 함수(주소)를 실행한다
        DispatchMessage (&msg) ;			
    }
    return msg.wParam ;
}

// LRESULT == long
// Window Procedure는 프로그램에서 호출하는 것이 아니라 Windows로 부터 호출된다 ( CALLBACK )
LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{	
    //hdc 출력에 필요한 정보를 가지는 데이터 구조체
    HDC         hdc ;		
    //프로그램에 그리기 위한 정보가 저장된 구조체
    PAINTSTRUCT ps ;	
    //사각형 단위 좌표를 기억하는 구조체
    RECT        rect ;
     
    switch (message)
    {
    // 윈도우가 표시되기 전, 윈도우가 생성 될때 
    case WM_CREATE:
    MessageBox (hwnd,							
				    TEXT ("WM_CREATE "),			
				    TEXT ("메시지"),				
				    0) ;							
	    return 0 ;

    // 화면이 무효화 ( 갱신 )
    case WM_PAINT:
    //화면에 출력하기 위한 DC핸들을 찾는 함수
    hdc = BeginPaint (hwnd, &ps) ;	

    //윈도우의 작업영역 크기를 계산
    GetClientRect (hwnd, &rect) ;				

    DrawText (hdc, //DC핸들
		    TEXT ("Hello, Windows!"), //출력할 문자
		    -1, //문자열 길이, -1일 경우 널 종료 문자까지 출력								
		    &rect, //문자열을 출력할 사각영역

            //DT_SINGLELINE : 문자열을 한줄로 출력
            //DT_CENTER : 수평중앙 출력
            //DT_VCENTER : 수직 중앙출력
		    DT_SINGLELINE | DT_CENTER | DT_VCENTER) ; //출력옵션

    //WM_PAINT 함수 내에서 그리기를 종료
    EndPaint (hwnd, &ps) ;
    return 0 ;

    // 윈도우 종료 시도 ( 종료버튼등 )
    case WM_DESTROY:	
        //스레드 메시지 큐에 WM_QUIT 메시지를 붙이고 즉시 리턴
        //윈도우 종료
        PostQuitMessage (0) ;									
    return 0 ;
    }
    //이 함수는 윈도우 프로시저가 처리하지 않은 메시지의 디폴트 처리를 한다
    return DefWindowProc (hwnd, message, wParam, lParam) ;	
}