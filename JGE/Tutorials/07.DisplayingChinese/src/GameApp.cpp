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
	mBitmapFont12 = NULL;
	mBitmapFont16 = NULL;
	mTTFont = NULL;
	mTTFont2 = NULL;

}


GameApp::~GameApp()
{
}


void GameApp::Create()
{

	mBitmapFont12 = new JGBKFont();
	mBitmapFont12->Init("ASC12", "GBK12", 12);

	mBitmapFont16 = new JGBKFont();
	mBitmapFont16->Init("ASC16", "GBK16", 16);
	

	mTTFont = new JTTFont();
	mTTFont->Load("gkai00mp.ttf", 18);
	//mTTFont->SetAntialias(false);

	mTTFont2 = new JTTFont();
	mTTFont2->Load(mTTFont, 60);



}


void GameApp::Destroy()
{
	
	if (mTTFont)
		delete mTTFont;

	if (mTTFont2)
		delete mTTFont2;

	if (mBitmapFont12)
		delete mBitmapFont12;

	if (mBitmapFont16)
		delete mBitmapFont16;

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

	
	u8 text[] = "汉字测试,没有问题!";
	u8 poem[] = "床前明月光...";


	mBitmapFont12->RenderString(text, 10, 20);
	mBitmapFont16->RenderString(text, 10, 50);
	
	mTTFont->RenderString(poem, 10, 100);
	mTTFont2->RenderString(poem, 10, 130);
}


void GameApp::Pause()
{
}


void GameApp::Resume()
{
}
