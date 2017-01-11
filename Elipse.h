#ifndef Ellipse_h
#define Ellipse_h

#include "Graphics.h"

class Elipse : public Graphics
{
public:
	Elipse();
	Elipse(COORD c, float a, float b);
	~Elipse();

	void setLineColor(float r, float g, float b);
	COLOR getLineColor() const;

	float getLineWidth() const;
	void setLineWidth(float lw);

	
	void Elipsepot(int x0, int y0, int x, int y);
	void setPixel(int x, int y);
	void Draw();

	void Up();
	void Down();
	void Left();
	void Right();

	void Increase();
	void Decrease();

	void Rotate(char c);

	void Fill(float r, float g, float b);

	string SaveFile();

	void Disappear();

private:
	COORD center;
	float a;
	float b;

	//COLOR lineColor;
	//float lineWidth;
};

#endif