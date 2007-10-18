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
#include <JSprite.h>
#include <JFileSystem.h>

#include "GameApp.h"
#include "TileMap.h"
#include "TileSet.h"


GameApp::GameApp()
{
	mBgTex = NULL;
	mBg = NULL;
	mTileSet = NULL;
	mTileMap = NULL;
}


GameApp::~GameApp()
{
}


void GameApp::Create()
{
	//JFileSystem::GetInstance()->AttachZipFile("res.zip");

	JRenderer* renderer = JRenderer::GetInstance();
	mBgTex = renderer->LoadTexture("tiles.png", TEX_TYPE_USE_VRAM);
	//mBg = new JQuad(mBgTex, 0, 0, 480, 272);

	mTileSet = new TileSet(mBgTex);
	mTileSet->Init(2, 2, 2, 2, 48, 48, 10, 10);

	mTileMap = new TileMap("map.dat", mTileSet, 48, 48);
}


void GameApp::Destroy()
{

	if (mBgTex)
		delete mBgTex;

	if (mBg)
		delete mBg;

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

	float dt = engine->GetDelta();

	if (mTileMap != NULL)
	{
		//		mTileMap->SetTarget(mX-400.0f, mY);
		mTileMap->Update(dt);
	}

}


void GameApp::Render()
{

	JRenderer* renderer = JRenderer::GetInstance();


	//renderer->ClearScreen(ARGB(0,0,0,0));

	mTileMap->Render();
	
	//renderer->RenderQuad(mBg, 0, 0);

}


void GameApp::Pause()
{

}


void GameApp::Resume()
{

}
