#ifndef Teapot_h
#define Teapot_h

#include "Graphics.h"

class Teapot : public Graphics
{
public :
	Teapot();
	Teapot(double s, double x, double y, double z);
	~Teapot();

	void setLineWidth(float lw);
	float getLineWidth() const;
	void setLineColor(float r, float g, float b);
	COLOR getLineColor() const;
	
	void setPos(double x, double y, double z);
	double getPosX() const;
	double getPosY() const;
	double getPosZ() const;

	void setAngle(double x, double y);

	void setFilled(bool e);
	bool getFilled() const;

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

public :
	double size;
	
	//COLOR lineColor;
	//float lineWidth;

	double posX;
	double posY;
	double posZ;

	//bool filled;
};

#endif

