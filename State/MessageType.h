#pragma once


enum MsgType
{
	Msg_HiHoneyImHome,
	Msg_StewReady
};

inline std::string MsgToStr(MsgType msg)
{
	switch (msg)
	{
	case Msg_HiHoneyImHome:
		return "HiHoneyImHome";
		break;
	case Msg_StewReady:
		return "StewReady";
		break;
	default:
		break;
	}
}