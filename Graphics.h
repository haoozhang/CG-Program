#ifndef Graphics_h
#define Graphics_h

#include <windows.h>
#include <GL/glut.h>

#include <math.h>
#include <string>
#include <vector>
#include <sstream>
#include "Define.h"

#include <iostream>
using namespace std;

class Graphics
{
public:
	Graphics();
	~Graphics();

	virtual void setLineWidth(float lw) = 0;
	virtual void setLineColor(float r, float g, float b) = 0;

	virtual void Draw() = 0;
	
	virtual void Up() = 0;
	virtual void Down() = 0;
	virtual void Left() = 0;
	virtual void Right() = 0;
	
	virtual void Increase() = 0;
	virtual void Decrease() = 0;
	
	virtual void Rotate(char c) = 0;
	
	virtual void Fill(float r, float g, float b) = 0;

	virtual void Disappear() = 0;

	virtual string SaveFile() = 0;

	string float2str(float f);
	string COLOR2str(COLOR c);
	string bool2str(bool ex);

public:
	string graphicsType;
	float lineWidth;
	COLOR lineColor;
	bool filled;
	COLOR fillColor;

	//class Teapot
	double rotateX;
	double rotateY;
};

#endif