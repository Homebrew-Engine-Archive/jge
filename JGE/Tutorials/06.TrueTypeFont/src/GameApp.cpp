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
#include <JGBKFont.h>
#include <JSoundSystem.h>

#include <JTTFont.h>
#include <Encoding.h>

#include "GameApp.h"

GameApp::GameApp()
{

	mTTFont1 = NULL;
	mTTFont2 = NULL;
	
}


GameApp::~GameApp()
{
}


void GameApp::Create()
{

	mTTFont1 = new JTTFont();
	mTTFont1->Load("BorisBlackBloxx.ttf", 64);

	mTTFont2 = new JTTFont();			
	mTTFont2->Load(mTTFont1, 20);		// create the 2nd font using font info and data from the 1st one, but with a different size.


}


void GameApp::Destroy()
{

	if (mTTFont1)
		delete mTTFont1;

	if (mTTFont2)
		delete mTTFont2;

}


void GameApp::Update()
{

	JGE* engine = JGE::GetInstance();

	if (engine->GetButtonClick(PSP_CTRL_TRIANGLE))	// do a screen shot when TRIANGLE is pressed
	{
		char s[80];
		sprintf(s, "ms0:/screenshot.png");
		JRenderer::GetInstance()->ScreenShot(s);
	}

	if (engine->GetButtonClick(PSP_CTRL_CROSS))		// exit when the CROSS is pressed
	{
		engine->End();
		return;
	}

}


void GameApp::Render()
{

	JRenderer* renderer = JRenderer::GetInstance();

	renderer->EnableTextureFilter(false);
	
	renderer->ClearScreen(ARGB(0,0,0,0));

	mTTFont1->RenderString("Size 32", 10, 10);

	mTTFont2->RenderString("Size 12", 10, 80);

}


void GameApp::Pause()
{
}


void GameApp::Resume()
{
}
