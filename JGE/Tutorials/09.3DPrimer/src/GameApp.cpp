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

#ifdef WIN32
#else
#include <pspgu.h>
#include <pspgum.h>
#endif

#include <JGE.h>
#include <JRenderer.h>
#include <JLBFont.h>
#include <JSprite.h>
#include <JOBJModel.h>

#include "GameApp.h"

#include <JMD2Model.h>



JMD2Model *mPlayer = NULL;
JMD2Model *mGun = NULL;

JMD2Model *mTerran = NULL;
JMD2Model *mTerranGun = NULL;

float mAnimationTimer = 0.0f;

int mState = STATE_IDLE;
int mTState = STATE_IDLE;


float mTerranState = 0.0f;

GameApp::GameApp()
{
	mTexture = NULL;
	mBgTex = NULL;
	mBg = NULL;
	mOBJ = NULL;

}


GameApp::~GameApp()
{
}


void GameApp::Create()
{
	JRenderer* renderer = JRenderer::GetInstance();
	mTexture = renderer->LoadTexture("box.png");
	mBgTex = renderer->LoadTexture("bg.png");
	mBg = new JQuad(mBgTex, 0, 0, 480, 272);

	mOBJ = new JOBJModel();
	mOBJ->Load("fighter.obj", "huaying.png");

	int n = 0;
	PIXEL_TYPE *bits = new PIXEL_TYPE[50*50];
	for (int i=0;i<50;i++)
		for (int j=0;j<50;j++)
			bits[n++] = ARGB(255,255,0,255);

	mBgTex->UpdateBits(10, 10, 50, 50, bits);

	mScale = 1.0f;
	mAngle = 0.0f;
	mDelta = 0.001f;

	mPlayer = new JMD2Model();
	mPlayer->Load("tris.md2", "abarlith.png");

	mGun = new JMD2Model();
	mGun->Load("weapon.md2", "weapon.png");

	mTerran = new JMD2Model();
	mTerran->Load("terran.md2", "terran.png");

	mTerranGun = new JMD2Model();
	mTerranGun->Load("terran_weapon.md2", "terran_weapon.png");


	if (mPlayer != NULL && mGun != NULL)
	{
		mPlayer->SetState(mState);
		mGun->SetState(mState);
	}

	renderer->SetFOV(60.0f);

}


void GameApp::Destroy()
{

	if (mTexture)
		delete mTexture;

	if (mBgTex)
		delete mBgTex;

	if (mBg)
		delete mBg;

	if (mPlayer)
		delete mPlayer;

	if (mGun)
		delete mGun;

	if (mTerran)
		delete mTerran;

	if (mTerranGun)
		delete mTerranGun;

	if (mOBJ)
		delete mOBJ;

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


	int mNewState = mState;
	if (engine->GetButtonClick(PSP_CTRL_UP))
	{
		mNewState--;
		if (mNewState < STATE_IDLE)
			mNewState = STATE_FALING_FORWARD_DYING;
		//
		//		if (mNewState == STATE_JUMP)
		//			mNewState= STATE_SHOT_IN_SHOULDER;
		//
		//		if (mNewState == STATE_KNEELING_DYING)
		//			mNewState = STATE_IDLE4; 


	}
	else if (engine->GetButtonClick(PSP_CTRL_DOWN))
	{
		mNewState++;
		if (mNewState > STATE_FALING_FORWARD_DYING)
			mNewState = STATE_IDLE;
		//		if (mNewState == STATE_JUMP)
		//			mNewState= STATE_IDLE2;
		//		
		//		if (mNewState == STATE_CROUCHING)
		//			mNewState = STATE_FALLING_BACK_DYING; 

	} 

	if (mNewState != mState && mPlayer != NULL && mGun != NULL)
	{
		mState = mNewState;
		mPlayer->SetState(mState);
		mGun->SetState(mState);
	}

	float dt = engine->GetDelta();	// get number of milliseconds passed since last frame

	mAngle += 1.0f*dt;			// the frame rate is not fixed by default, so we use dt to do adjustments
	if (mAngle > M_PI*2.0f)			// angles are in radian, so 2 PI is one full circle
		mAngle = 0.0f;

	mScale += mDelta*dt;
	if (mScale > 2.0f || mScale < 0.5f)
	{
		mDelta *= -1;
		mScale += mDelta*dt;
	}

//	val += 0.1f*dt;
	//mEngine->printf("%p t:%d pt:%d f:%d s:%d", mPlayer, mPlayer->mModel->numTriangles, mPlayer->mModel->numPoints, mPlayer->mModel->numFrames, mPlayer->mModel->frameSize);


	mPlayer->Update(dt);
	mGun->Update(dt);

//	mTerran->Update(dt);
 //	mTerranGun->Update(dt);

	mAnimationTimer = 6.0f * dt;

	mTerranState += 0.2f*dt;

	int state = (int)mTerranState;
	state %= STATE_FALLING_BACK_SLOWLY_DYING;
	if (state != mTState && mTerran != NULL && mTerranGun != NULL)
	{
		mTState = state;
		mTerran->SetState(mTState);
		mTerranGun->SetState(mTState);
	}

}


void GameApp::Render()
{

	JRenderer* renderer = JRenderer::GetInstance();

	renderer->Enable2D();
	renderer->RenderQuad(mBg, 0, 0);
	

	renderer->Enable3D();

	renderer->PushMatrix();
	renderer->Translate(30.0f, 0.0f, -60.0f);
	renderer->RotateX(-M_PI_2);
	renderer->RotateZ(mAngle);

	//mPlayer->Render(74);
	mPlayer->Render();
	mGun->Render();

 	renderer->PopMatrix();
 /*
	renderer->PushMatrix();

 	renderer->Translate(-30.0f, 0.0f, -60.0f);
 	renderer->RotateX(-M_PI_2);
 	renderer->RotateZ(mAngle/2);
 
 	mTerran->Render();
 	mTerranGun->Render();

	renderer->PopMatrix();
*/
	Vertex3D tris[] =
	{
		// top
		{ 0.0f, 0.0f, -5.0f, 5.0f, 5.0f },		
		{ 1.0f, 0.0f, 5.0f, 5.0f, 5.0f },
		{ 1.0f, 1.0f, 5.0f, 5.0f, -5.0f },

		{ 1.0f, 1.0f, 5.0f, 5.0f, -5.0f },
		{ 0.0f, 1.0f, -5.0f, 5.0f, -5.0f },
		{ 0.0f, 0.0f, -5.0f, 5.0f, 5.0f },

		// front
		{ 0.0f, 0.0f, 5.0f, -5.0f, 5.0f },		
		{ 1.0f, 0.0f, 5.0f, 5.0f, 5.0f },
		{ 1.0f, 1.0f, -5.0f, 5.0f, 5.0f },

		{ 1.0f, 1.0f, -5.0f, 5.0f, 5.0f },
		{ 0.0f, 1.0f, -5.0f, -5.0f, 5.0f },
		{ 0.0f, 0.0f, 5.0f, -5.0f, 5.0f },

		// right
		{ 0.0f, 0.0f, 5.0f, 5.0f, -5.0f },
		{ 1.0f, 0.0f, 5.0f, 5.0f, 5.0f },
		{ 1.0f, 1.0f, 5.0f, -5.0f, 5.0f },
		
		{ 1.0f, 1.0f, 5.0f, -5.0f, 5.0f },
		{ 0.0f, 1.0f, 5.0f, -5.0f, -5.0f },
		{ 0.0f, 0.0f, 5.0f, 5.0f, -5.0f },

		// left
		{ 0.0f, 0.0f, -5.0f, -5.0f, 5.0f },
		{ 1.0f, 0.0f, -5.0f, 5.0f, 5.0f },
		{ 1.0f, 1.0f, -5.0f, 5.0f, -5.0f },

		{ 1.0f, 1.0f, -5.0f, 5.0f, -5.0f },
		{ 0.0f, 1.0f, -5.0f, -5.0f, -5.0f },
		{ 0.0f, 0.0f, -5.0f, -5.0f, 5.0f },

		// bottom
		{ 0.0f, 0.0f, 5.0f, -5.0f, 5.0f },
		{ 1.0f, 0.0f, -5.0f, -5.0f, 5.0f },
		{ 1.0f, 1.0f, -5.0f, -5.0f, -5.0f },

		{ 1.0f, 1.0f, -5.0f, -5.0f, -5.0f },
		{ 0.0f, 1.0f, 5.0f, -5.0f, -5.0f },
		{ 0.0f, 0.0f, 5.0f, -5.0f, 5.0f },
		
		// back
		{ 0.0f, 0.0f, 5.0f, 5.0f, -5.0f },
		{ 1.0f, 0.0f, 5.0f, -5.0f, -5.0f },
		{ 1.0f, 1.0f, -5.0f, -5.0f, -5.0f },

		{ 1.0f, 1.0f, -5.0f, -5.0f, -5.0f },
		{ 0.0f, 1.0f, -5.0f, 5.0f, -5.0f },
		{ 0.0f, 0.0f, 5.0f, 5.0f, -5.0f }
	};

	renderer->PushMatrix();
	renderer->Translate(-15.0f, 0.0f, -30.0f);
	renderer->RotateX(mAngle);
	renderer->RotateY(-mAngle);
	renderer->RotateZ(mAngle);
	renderer->RenderTriangles(mTexture, tris, 0, 12);
	renderer->PopMatrix();
	
	renderer->Translate(0.0f, -1.0f, -3.0f);
	//renderer->RotateX(mAngle);
	renderer->RotateY(-mAngle);
	//renderer->RotateZ(mAngle);
	mOBJ->Render();
}


void GameApp::Pause()
{

}


void GameApp::Resume()
{

}
