#ifndef Polygon_h
#define Polygon_h

#include "Graphics.h"
#include "Line.h"
#include <vector>

struct DIR
{
	double X;
	double Y;
};
class Polygon : public Graphics
{
public:
	
	Polygon();
	//Polygon(COORD b, COORD e);
	Polygon(int n, COORD c[]);
	~Polygon();

	COORD getVertex(int n);

	void setLineWidth(float lw);
	float getLineWidth() const;

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

	string SaveFile();

	void Disappear();

private:
	vector<COORD> Vertex;
	//float lineWidth;
	//COLOR lineColor;

	double *length;
	int n;
	double angle;
	DIR *dir;
};

#endif