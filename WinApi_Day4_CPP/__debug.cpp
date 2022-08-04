#include "__debug.h"

void ___Trace0(char *str)
{
	char buf[256];
	int i;

	memset(buf, 0, 256);
	i = strlen(str);
	strncpy(buf, str, i);

	if (buf[i - 1] == '\n')
	{
		buf[i - 1] = '\r';
		buf[i] = '\n';
	}
	OutputDebugString(buf);
}

void ___Trace(char *format, ...)
{
	va_list argptr;
	char    buf[256];
	int i;

	memset(buf, 0, 256);
	va_start(argptr, format);
	i = vsprintf(buf, format, argptr);
	va_end(argptr);

	if (buf[i - 1] == '\n')
	{
		buf[i - 1] = '\r';
		buf[i] = '\n';
	}
	OutputDebugString(buf);
}