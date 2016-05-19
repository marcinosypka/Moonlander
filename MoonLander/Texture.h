#define _CRT_SECURE_NO_DEPRECATE
#pragma once
#include <windows.h> // Window defines
#include <gl\gl.h> 
#include <gl\glu.h> 
#include <iostream>
#include "RESOURCE.H"
class Texture
{
public:
	Texture();
	Texture(std::string bitmapFile);
	~Texture();

	void SetLocalTexture();
	unsigned int getTexture();
	unsigned char* LoadBitmapFile(char *filename, BITMAPINFOHEADER *bitmapInfoHeader);
	
private:
	const char* bitmapFileName;
	static const unsigned int BITMAP_ID = 0x4D42;
	BITMAPINFOHEADER	bitmapInfoHeader;	// nag3ówek obrazu
	unsigned char*		bitmapData;			// dane tekstury
	unsigned int		texture;
};

