#include "stdafx.h"

//Log* Log::instance = new Log();


Log::Log()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Log::Msg(int color, const char * fmt, ...)
{
	SetConsoleTextAttribute(hConsole, color);

	char msg[50];
	time_t t = time(NULL);
	strftime(msg, sizeof msg, "%T", localtime(&t));
	printf("[%s][ERROR] ", msg);
	va_list args;
	va_start(args, fmt);
	vprintf(fmt, args);
	va_end(args);

	printf("\n");

}
