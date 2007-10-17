//-------------------------------------------------------------------------------------
//
// JGE++ is a hardware accelerated 2D game SDK for PSP/Windows.
//
// Licensed under the BSD license, see LICENSE in JGE root for details.
// 
// Copyright (c) 2007 James Hui (a.k.a. Dr.Watson) <jhkhui@gmail.com>
// 
//-------------------------------------------------------------------------------------


#include <math.h>

#include "../include/JGE.h"
#include "../include/JParticleSystem.h"
#include "../include/JParticleEffect.h"




//-------------------------------------------------------------------------------------
JParticleSystem* JParticleSystem::mInstance = NULL;

JParticleSystem* JParticleSystem::GetInstance()
{
	if (mInstance == NULL)
	{
		mInstance = new JParticleSystem();
	}

	return mInstance;
}


void JParticleSystem::Destroy()
{
	if (mInstance)
	{
		delete mInstance;
		mInstance = NULL;
	}
}


//-------------------------------------------------------------------------------------
JParticleSystem::JParticleSystem()
{
//	mPos = Vector2D(0.0f, 0.0f);

	//mParticleQuads = NULL;

	mActive = false;
	
}


JParticleSystem::~JParticleSystem()
{
	mEffects.clear();
	
// 	if (mParticleQuads)
// 	{
// 		for (int i=0;i<mParticleQuadCount;i++)
//  			delete mParticleQuads[i];
// 		delete [] mParticleQuads;
// 	}
}


void JParticleSystem::ClearAll()
{
	mEffects.clear();
}


void JParticleSystem::Update(float dt)
{
	if (!mEffects.empty())
	{
		JParticleEffect* effect;
		std::list<JParticleEffect*>::iterator curr = mEffects.begin();
		while (curr != mEffects.end())
		{
			effect = *curr;
			effect->Update(dt);
			if (effect->Done())
			{
				mEffects.erase(curr++);
			}
			else	
				curr++;
		}
	}
	
}


void JParticleSystem::Render()
{

	if (!mEffects.empty())
	{
		JParticleEffect* effect;
		std::list<JParticleEffect*>::iterator curr = mEffects.begin();
		while (curr != mEffects.end())
		{
			effect = *curr;
			effect->Render();
			
			curr++;
		}
	}
}


// void JParticleSystem::SetPosition(float x, float y)
// {
// 	mPos = Vector2D(x, y);
// }


void JParticleSystem::StartEffect(JParticleEffect* effect)
{
	std::list<JParticleEffect*>::iterator curr = mEffects.begin();
	while (curr != mEffects.end())
	{
		if (effect == *curr && effect->GetParticleSystem() == this)
		{
			effect->Start();
			return;
		}
		curr++;
	}
	mEffects.push_back(effect);
	effect->SetParticleSystem(this);
	effect->Start();
}
// 
// 
// void JParticleSystem::SetTexture(JTexture* tex, int parTexWidth, int parTexHeight)
// {
// 	int col = tex->mWidth/parTexWidth;
// 	int row = tex->mHeight/parTexHeight;
// 	mParticleQuadCount = col*row;
// 	mParticleQuads = new JQuad*[mParticleQuadCount];
// 
// 	if (mParticleQuads)
// 	{
// 		
// 		int n = 0;
// 
// 		float x = 0.0f;
// 		float y = 0.0f;
// 		for (int i=0;i<row;i++)
// 		{
// 			x = 0.0f;
// 			for (int j=0;j<col;j++)
// 			{
// 				mParticleQuads[n] = new JQuad(tex, x, y, (float)parTexWidth, (float)parTexHeight);
// 				mParticleQuads[n]->SetHotSpot((float)(parTexWidth/2), (float)(parTexHeight/2));
// 
// 				n++;
// 				x += (float)parTexWidth;
// 			}
// 			y += (float)parTexHeight;
// 		}
// 
// 	}
// }
// 
// 
// JQuad* JParticleSystem::GetParticleQuad(int index)
// {
// 	if (mParticleQuads && index < mParticleQuadCount)
// 	{
// 		return mParticleQuads[index];
// 	}
// 
// 	return NULL;
// }


void JParticleSystem::StopAllEffects()
{

	if (!mEffects.empty())
	{
		JParticleEffect* effect;
		std::list<JParticleEffect*>::iterator curr = mEffects.begin();
		while (curr != mEffects.end())
		{
			effect = *curr;
			effect->Stop();
			curr++;
		}
	}
	
	
}

bool JParticleSystem::IsActive() { return mActive; }

void JParticleSystem::SetActive(bool flag) { mActive = flag; }

