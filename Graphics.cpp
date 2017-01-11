#include "Graphics.h"

Graphics::Graphics()
{
	graphicsType = "";
	lineWidth = 0;
	COLOR tempColor = {1,1,1};
	lineColor = tempColor;
	filled = false;
	fillColor = tempColor;

	//class Teapot
	rotateX = 0.0;
	rotateY = 0.0;
}

Graphics::~Graphics()
{
}

string Graphics::float2str(float f)
{
	ostringstream buff;
    buff<<f;
    return buff.str(); 
}
string Graphics::COLOR2str(COLOR c)
{
	string leftB = "(";
	string r = float2str(c.R).append(",");
	string g = float2str(c.G).append(",");
	string b = float2str(c.B);
	string rightB = ")";
	string s = leftB + r + g + b + rightB;
	return s;
}
string Graphics::bool2str(bool ex)
{
	return (ex == true) ? "1" : "0"; 
}