#if DEBUG
#pragma comment(lib, "Tempest_Win32_Debug.lib")
#else
#pragma comment(lib, "Tempest_Win32_Release.lib")
#endif
//=====Engine Includes=====
#include <Engine/Atom.h>
#include <Engine/Engine.h>
#include <Engine/ErrorManager.h>

namespace TE = Tempest;


int main(void)
{
//=====Window Parameter Constants=====
	const S32    wndWidth  	   = 1024;
	const S32    wndHeight 	   = 768;
	const string wndTitle	   = "Tempest Game";
	const S32    wndFullScreen = false;


	TE::Engine::Instance()->Init(wndWidth, wndHeight, wndTitle, wndFullScreen);

	if(TE::ErrorManager::Instance()->DisplayErrors())
	{
		TE::Engine::Instance()->End();
	}

//=====Pre-Load Assets=====	
	
	while (TE::Engine::Instance()->Running()) 
	{
		TE::Engine::Instance()->Update();
		TE::Engine::Instance()->Render();
		
		if(TE::ErrorManager::Instance()->DisplayErrors())
		{
			TE::Engine::Instance()->End();
		}
	}
}
