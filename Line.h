#ifndef Line_h
#define Line_h

#include "Graphics.h"

class Line : public Graphics
{
public:
	Line();
	//Line(SMALL_RECT p);
	Line(COORD s, COORD e);
	Line(float sx, float sy, float ex, float ey);
	~Line();

	void setLinePos(COORD b, COORD e);
	SMALL_RECT getLinePos();
	void setLineColor(float r, float g, float b);
	COLOR getLineColor() const;
	float getLineWidth();
	void setLineWidth(float l);

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
	//SMALL_RECT pos;
	COORD begin;
	COORD end;
	//float lineWidth;
	//COLOR lineColor;

	double length;
	int n;
	double angle;
	double dir[2];
};

#endif