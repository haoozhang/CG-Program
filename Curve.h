#ifndef Curve_h
#define Curve_h

#include "Graphics.h"
#include "Polygon.h"

class Curve : public Graphics
{
public:	
	Curve();
	Curve(int n, COORD c[]);
	~Curve();

	void setLineColor(float r, float g, float b);
	COLOR getLineColor() const;

	float getLineWidth() const;
	void setLineWidth(float lw);

	void Draw();
	void calBezier();
	void DrawPoint(int n, COORD c[]);
	void DrawLine(int n, COORD c[]);

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
	COORD Point[4];
	COORD Bezier[11];

	//float lineWidth;
	//COLOR lineColor;
};

#endif Curve_h