#ifndef Circle_h
#define Circle_h

#include "Graphics.h"
#include "Elipse.h"

class Circle : public Graphics
{
public:
	Circle();
	Circle(COORD c, float r);
	~Circle();
	
	void setLineColor(float r, float g, float b);
	COLOR getLineColor() const;

	float getLineWidth() const;
	void setLineWidth(float lw);

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
	float radiusa;
	float radiusb;

	//COLOR lineColor;
	//float lineWidth;
};
#endif