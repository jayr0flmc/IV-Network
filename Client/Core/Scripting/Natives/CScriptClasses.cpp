//========= IV: Network - https://github.com/GTA-Network/IV-Network ============
//
// File: CScriptClasses.cpp
// Project: Client.Core
// Author: xForce <xf0rc3.11@gmail.com>
// License: See LICENSE in root directory
//
//==============================================================================

#include "CScriptClasses.h"
#include <Game/EFLC/CScript.h>
#include <CCore.h>
#include <Scripting/CLuaVM.h>
#include <Scripting/CSquirrelVM.h>
#include <CLogFile.h>
#include <Scripting/ResourceSystem/CResourceManager.h>
#include "Scripting/Natives/Natives_Client.h"

extern CCore * g_pCore;

int SendMessage(int * VM)
{
	GET_SCRIPT_VM_SAFE;

	pVM->ResetStackIndex();

	CString sMessage;
	DWORD dwColor;
	bool bAllowFormatting;
	
	pVM->Pop(sMessage);
	pVM->Pop(dwColor);
	pVM->Pop(bAllowFormatting);
	
	g_pCore->GetGraphics()->GetChat()->Print(CString("#%s%s", dwColor, sMessage));
	return 1;
}

int GetRoot(int * VM)
{
	GET_SCRIPT_VM_SAFE;

	pVM->ResetStackIndex();

	pVM->PushInstance("CPlayerEntity", g_pCore->GetGame()->GetLocalPlayer());
	return 1;
}

void CScriptClasses::Register(IScriptVM * pVM)
{
	pVM->RegisterFunction("getRoot", GetRoot);
	pVM->RegisterFunction("sendMessage", SendMessage);
}
