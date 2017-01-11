#ifndef Point_h
#define Point_h

#include "Graphics.h"

class Point : public Graphics
{
public:
	Point();
	Point(COORD p);
	Point(float x, float y);
	~Point();

	COORD getPos() const;
	void setPos(COORD p);

	float getLineWidth() const;
	void setLineWidth(float p);

	COLOR getLineColor() const;
	void setLineColor(float r, float g, float b);

	void Draw();

	void Up();
	void Down();
	void Left();
	void Right();

	void Increase();
	void Decrease();

	void Rotate(char c);

	void Fill(float r, float g, float b);

	void Disappear();

	string SaveFile();

private:
	COORD pos;
	//float lineWidth;
	//COLOR lineColor;
};

#endif