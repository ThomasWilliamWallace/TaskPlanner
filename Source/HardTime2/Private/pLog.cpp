#include "pLog.hpp"
#include "Constants.hpp"
#include "Engine/GameEngine.h"

void pLog(std::string logText, bool forcePrint)
{
	if (c_debug || forcePrint)
	{
		FString fString = FString(logText.c_str());
		UE_LOG(LogTemp, Warning, TEXT("%s"), *fString);
	}
}

void pLog(std::string logText, std::string logText2, bool forcePrint)
{
	if (c_debug || forcePrint)
	{
		FString fString = FString(logText.c_str());
		FString fString2 = FString(logText2.c_str());
		UE_LOG(LogTemp, Warning, TEXT("%s%s"), *fString, *fString2);
	}
}

void pLog(std::stringstream& ss, bool forcePrint)
{
    pLog(ss.str(), forcePrint);
}
