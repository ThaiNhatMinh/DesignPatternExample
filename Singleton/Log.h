#pragma once

class Log : public Singleton<Log>
{
public:
	const static int k_Error = 12;
	const static int k_Debug = 15;
	const static int k_Warning = 9;
public:
	Log();
	~Log() = default;

	void Msg(int color,const char* fmt, ...);

private:
	struct LogData
	{
		int color;
		std::string msg;
	};

	std::vector<LogData> m_Msg;

	HANDLE hConsole;
};