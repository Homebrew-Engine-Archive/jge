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
	mBgTex = NULL;
	mSpriteTex = NULL;
	mBg = NULL;
	mSprite = NULL;

}


GameApp::~GameApp()
{
}


void GameApp::Create()
{

	
}


void GameApp::Destroy()
{

	if (mBgTex)
		delete mBgTex;

	if (mSpriteTex)
		delete mSpriteTex;

	if (mBg)
		delete mBg;

	if (mSprite)
		delete mSprite;

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
	
 	

}


void GameApp::Pause()
{

}


void GameApp::Resume()
{

}
