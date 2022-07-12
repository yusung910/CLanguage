#include <windows.h>

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;

//// 메인 함수 : 윈도우 프로그램의 최초 진입점 ( Entry Point )
//매개변수 목록
//HINSTANCE hInstance:
int WINAPI WinMain (HINSTANCE hInstance,		
					HINSTANCE hPrevInstance,	
                    PSTR szCmdLine,				
					int iCmdShow)			
{
     static TCHAR szAppName[] = TEXT ("HelloWin") ;
     HWND         hwnd ;		
     MSG          msg ;			
     WNDCLASS     wndclass ;	

     wndclass.style         = CS_HREDRAW | CS_VREDRAW ;
														
     wndclass.lpfnWndProc   = WndProc ;					
     wndclass.cbClsExtra    = 0 ;
     wndclass.cbWndExtra    = 0 ;
     wndclass.hInstance     = hInstance ;
     wndclass.hIcon         = LoadIcon (NULL,				
										IDI_APPLICATION) ;	
     wndclass.hCursor       = LoadCursor (NULL,
										IDC_ARROW) ;		
     wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ; 
																	  
     wndclass.lpszMenuName  = NULL ;
     wndclass.lpszClassName = szAppName ;

	 //// 윈도우 클래스 등록
	 // CreateWindow()로 윈도우를 생성하기 전에 반드시 등록되어 있어야 한다
     if (!RegisterClass (&wndclass))
     {
          MessageBox (NULL, TEXT ("This program requires Windows NT!"), 
                      szAppName, MB_ICONINFORMATION) ;
          return 0 ;
     }
     
	 //// 윈도우 생성
     hwnd = CreateWindow (szAppName,                  
                          TEXT ("The Hello Program"),				  						  
                          WS_OVERLAPPEDWINDOW,        
                          CW_USEDEFAULT,              
                          CW_USEDEFAULT,              
                          CW_USEDEFAULT,             
                          CW_USEDEFAULT,             
                          NULL,                       
                          NULL,                       
                          hInstance,                  
                          NULL) ;                     
     
	 //// 생성된 윈도우를 화면에 표시
     ShowWindow (hwnd, iCmdShow) ;			
											
     UpdateWindow (hwnd) ;					

	 //// 메시지 루프
     while (GetMessage (&msg,				
		                 NULL, 0, 0))		
     {		 
         TranslateMessage (&msg) ;			
         DispatchMessage (&msg) ;			
     }
     return msg.wParam ;
}

//// LRESULT == long
//// Window Procedure는 프로그램에서 호출하는 것이 아니라 Windows로 부터 호출된다 ( CALLBACK )

LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{	
     HDC         hdc ;		
     PAINTSTRUCT ps ;		
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
			hdc = BeginPaint (hwnd, &ps) ;				

			GetClientRect (hwnd, &rect) ;				

			DrawText (hdc,
				      TEXT ("Hello, Windows!"),
					  -1,								
					  &rect,
					  DT_SINGLELINE | DT_CENTER | DT_VCENTER) ;

			EndPaint (hwnd, &ps) ;
			return 0 ;

     // 윈도우 종료 시도 ( 종료버튼등 )
     case WM_DESTROY:		 
			PostQuitMessage (0) ;									
			return 0 ;
	 }

     return DefWindowProc (hwnd, message, wParam, lParam) ;	
}