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
#include <JSpline.h>

#include "GameApp.h"


GameApp::GameApp()
{
	mFont = NULL;
	mSpline = NULL;

}


GameApp::~GameApp()
{
}


void GameApp::Create()
{

	mFont = new JLBFont("f3", 16, true);
	mSpline = new JSpline();
	mSpline->Load("sample.spl", 0.60f, 0.56f);
	mSpline->GeneratePixels();

}


void GameApp::Destroy()
{

	if (mFont)
		delete mFont;

	if (mSpline)
		delete mSpline;

}


void GameApp::Update()
{

	JGE* engine = JGE::GetInstance();

	if (engine->GetButtonClick(PSP_CTRL_TRIANGLE))		// do a screen shot when the TRIANGLE button is pressed
	{
		char s[80];
		sprintf(s, "ms0:/screenshot.png");
		JRenderer::GetInstance()->ScreenShot(s);
	}

	if (engine->GetButtonClick(PSP_CTRL_CROSS))			// exit when the CROSS button is pressed
	{
		engine->End();
		return;
	}

}


void GameApp::Render()
{

	JRenderer* renderer = JRenderer::GetInstance();

	renderer->ClearScreen(ARGB(0,0,0,0));
	
 	//mFont->SetColor(ARGB(255,255,255,255));
 	//mFont->DrawString("Hello World!", 240.0f, 130.0f, JGETEXT_CENTER); 
	mSpline->Render(0, 0);

}


void GameApp::Pause()
{

}


void GameApp::Resume()
{

}
