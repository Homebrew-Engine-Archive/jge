//-------------------------------------------------------------------------------------
//
// JGE++ is a hardware accelerated 2D game SDK for PSP/Windows.
//
// Licensed under the BSD license, see LICENSE in JGE root for details.
// 
// Copyright (c) 2007 James Hui (a.k.a. Dr.Watson) <jhkhui@gmail.com>
// 
//-------------------------------------------------------------------------------------

#include <stdio.h>

#include <JGE.h>
#include <JRenderer.h>
#include <JLBFont.h>
#include "JAssert.h"

#include "GameApp.h"


//-------------------------------------------------------------------------------------
// Constructor. Variables can be initialized here.
//
//-------------------------------------------------------------------------------------
GameApp::GameApp()
{
	mAngle = 0.0f;

	mCount = 2;

}


//-------------------------------------------------------------------------------------
// Destructor.
//
//-------------------------------------------------------------------------------------
GameApp::~GameApp()
{

}


//-------------------------------------------------------------------------------------
// This is the init callback function. You should load and create your in-game 
// resources here.
// 
//-------------------------------------------------------------------------------------
void GameApp::Create()
{

	
}


//-------------------------------------------------------------------------------------
// This is the clean up callback function. You should delete all your in-game 
// resources, for example texture and quads, here.
// 
//-------------------------------------------------------------------------------------
void GameApp::Destroy()
{

}


//-------------------------------------------------------------------------------------
// This is the update callback function and is called at each update frame
// before rendering. You should update the game logic here.
//
//-------------------------------------------------------------------------------------
void GameApp::Update()
{

	JGE* engine = JGE::GetInstance();

	// do a screen shot when the TRIANGLE button is pressed
	if (engine->GetButtonClick(PSP_CTRL_TRIANGLE))		
	{
		char s[80];

		// save screen shot to root of Memory Stick 
		sprintf(s, "ms0:/screenshot.png");				
		JRenderer::GetInstance()->ScreenShot(s);
	}

	// exit when the CROSS button is pressed
	if (engine->GetButtonClick(PSP_CTRL_CROSS))	
	{
		engine->End();
		return;
	}

	float dt = engine->GetDelta();		// Get time elapsed since last update.

	//
	// Your updating code here...
	//

	mAngle += 2.0f*dt;
	if (mAngle >= M_PI*2)
		mAngle = 0;
}


//-------------------------------------------------------------------------------------
// All rendering operations should be done in Render() only.
// 
//-------------------------------------------------------------------------------------
void GameApp::Render()
{

	// get JRenderer instance
	JRenderer* renderer = JRenderer::GetInstance();		

	// clear screen to black
	renderer->ClearScreen(ARGB(0,0,0,0));

	//
	// Your rendering code here...
	//

	float xList[] =
	{
		10, 100, 120, 80, 50, 10
	};

	float yList[] = 
	{
		100, 100, 60, 30, 10, 10
	};

	renderer->DrawPolygon(xList, yList, 6, ARGB(255,0,0,255));

	renderer->DrawLine(50, 50, 400, 200, 5, ARGB(255,255,0,0));

	for (int i=0;i<mCount;i++)
		renderer->DrawCircle(20+i*40,180,18,ARGB(255,0,255,0));

	renderer->FillCircle(300,120,50,ARGB(255,123,60,200));

 	renderer->DrawPolygon(230, 170, 40, 4, mAngle, ARGB(255,0,0,255));
 
 	renderer->FillPolygon(150, 180, 80, 6, mAngle, ARGB(255,0,0,255));

	renderer->DrawRect(280, 120, 20, 20, ARGB(255,255,255,255));

	renderer->DrawRoundRect(340, 30, 30, 20, 5, ARGB(255,255,255,255));

	renderer->FillRoundRect(200, 20, 40, 40, 8, ARGB(255,255,255,64));

}


//-------------------------------------------------------------------------------------
// This function is called when the system wants to pause the game. You can set a flag
// here to stop the update loop and audio playback.
//
//-------------------------------------------------------------------------------------
void GameApp::Pause()
{

	mCount++;
}


//-------------------------------------------------------------------------------------
// This function is called when the game returns from the pause state.
//
//-------------------------------------------------------------------------------------
void GameApp::Resume()
{
	mCount++;
	
}
