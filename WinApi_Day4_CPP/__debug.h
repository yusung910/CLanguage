#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <windows.h>
#include <stdio.h>

void ___Trace0(char *str);
void ___Trace(char *format, ...);

///// 디버그 모드
#ifdef _DEBUG

#define TRACE(s)                    ___Trace0(s)
#define TRACE0(s)                   ___Trace0(s)
#define TRACE1(f, a1)               ___Trace (f, a1)
#define TRACE2(f, a1, a2)           ___Trace (f, a1, a2)
#define TRACE3(f, a1, a2, a3)       ___Trace (f, a1, a2, a3)
#define TRACE4(f, a1, a2, a3, a4)   ___Trace (f, a1, a2, a3, a4)

#else // RELEASE == #ifdef !(_DEBUG) 

///// 릴리즈 모드
#define TRACE(s)                    ((void)0)   
#define TRACE0(s)                   ((void)0)   
#define TRACE1(f, a1)               ((void)0)
#define TRACE2(f, a1, a2)           ((void)0)
#define TRACE3(f, a1, a2, a3)       ((void)0)
#define TRACE4(f, a1, a2, a3, a4)   ((void)0)

#endif // _DEBUG

#endif // __DEBUG_H__