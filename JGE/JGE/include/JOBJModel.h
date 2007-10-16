//-------------------------------------------------------------------------------------
//
// JGE++ is a hardware accelerated 2D game SDK for PSP/Windows.
//
// Licensed under the BSD license, see LICENSE in JGE root for details.
// 
// Copyright (c) 2007 James Hui (a.k.a. Dr.Watson) <jhkhui@gmail.com>
// 
//-------------------------------------------------------------------------------------

#ifndef _OBJMODEL_H
#define _OBJMODEL_H

#include <vector>

using namespace std;

#ifdef WIN32

#else

#include <pspgu.h>
#include <pspgum.h>



#endif


#include "JGE.h"
#include "Vector3D.h"

class JTexture;

class JOBJModel
{

struct Face
{
	int mVertCount;
	int mVertIdx[4];
	int mTexIdx[4];
	int mNormalIdx[4];
};

public:
	JOBJModel();
	~JOBJModel();

	int ReadLine(char *output, const char *buffer, int start, int size);
	bool Load(const char *modelName, const char *textureName);
	void Render();

private:
	int mPolycount;
	Vertex3D* mPolygons;
	JTexture* mTexture;
};

#endif
