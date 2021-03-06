// 1512323.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


// Using SINGLETON_TYPE to define type of singleton pattern
// 1 is Eager initialization of singleton
// 2 is lazy initialization of singleton
// 3 is Thread safe initialization of singleton


int main()
{

	Log::Get()->Msg(Log::k_Debug,"Hellllooooooooooooo");
	Log::Get()->Msg(Log::k_Debug, "This is a example about Singleton pattern");


	Log::Get()->Msg(Log::k_Error, "This is a error.");
	Log::Get()->Msg(Log::k_Error, "This is a error with data %d %f %c.",10,1.5,'c');
	Log::Get()->Msg(Log::k_Warning, "This is a warning.", 10, 1.5, 'c');

	getc(stdin);

	Log::Release();
    return 0;
}

