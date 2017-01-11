#include "Curve.h"

Curve::Curve()
{	
	//顶点先不赋值

	COLOR color = {0,0,0};
	lineColor = color;

	lineWidth = 2;
}
Curve::Curve(int n, COORD c[])
{
	for(int i = 0; i < n; i++)
	{
		Point[i] = c[i];
	}

	COLOR color = {0,0,0};
	lineColor = color;

	lineWidth = 2;
}
Curve::~Curve()
{
}

void Curve::setLineColor(float r, float g, float b)
{
	COLOR c = {r,g,b};
	lineColor = c;
}
COLOR Curve::getLineColor() const
{
	return lineColor;
}

float Curve::getLineWidth() const
{
	return lineWidth;
}
void Curve::setLineWidth(float lw)
{	
	lineWidth = lw;
}

void Curve::DrawPoint(int n, COORD c[])
{
	glColor3f(1,0,0);
	glPointSize(2);
	glBegin(GL_POINT);
	for(int i = 0; i < 4 ;i++)
	{
		glVertex2f (c[i].X, c[i].Y);
	}
	glEnd();
	glFlush();
}
void Curve::DrawLine(int n, COORD c[])
{
	glLineWidth(lineWidth);
	glColor3f(lineColor.R, lineColor.G, lineColor.B);
	glBegin (GL_LINE_STRIP);
	for( int i  = 0 ; i < n; i++)
	{
		glVertex2f(c[i].X, c[i].Y);
	}
	glEnd();
	glFlush();
}
void Curve::calBezier()
{
	float a0,a1,a2,a3,b0,b1,b2,b3;
	a0=Point[0].X;
	a1=-3*Point[0].X+3*Point[1].X;
	a2=3*Point[0].X-6*Point[1].X+3*Point[2].X;
	a3=-Point[0].X+3*Point[1].X-3*Point[2].X+Point[3].X;
	b0=Point[0].Y;
	b1=-3*Point[0].Y+3*Point[1].Y;
	b2=3*Point[0].Y-6*Point[1].Y+3*Point[2].Y;	
	b3=-Point[0].Y+3*Point[1].Y-3*Point[2].Y+Point[3].Y;

	float t = 0;
	float dt = 0.01;

	for(int i = 0; t<1.1; t+=0.1, i++)
	{
		Bezier[i].X = a0+a1*t+a2*t*t+a3*t*t*t;
		Bezier[i].Y = b0+b1*t+b2*t*t+b3*t*t*t;
	}
}
void Curve::Draw()
{
	//DrawPoint(4, Point);
	//DrawLine(4, Point);
	calBezier();
	DrawLine(11, Bezier);
}

void Curve::Up()
{
	for(int i = 0; i < 4; i++)
		Point[i].Y += 40;
}
void Curve::Down()
{
	for(int i = 0; i < 4; i++)
		Point[i].Y -= 40;
}
void Curve::Left()
{
	for(int i = 0; i < 4; i++)
		Point[i].X -= 40;
}
void Curve::Right()
{
	for(int i = 0; i < 4; i++)
		Point[i].X += 40;
}

void Curve::Increase()
{
	//用曲线的四个点初始化一个四边形，然后放大得到放大后的点
	class::Polygon c(4, Point);
	c.Increase();
	for(int i = 0; i < 4; i++)
		Point[i] = c.getVertex(i);
}
void Curve::Decrease()
{
	class::Polygon c(4, Point);
	c.Decrease();
	for(int i = 0; i < 4; i++)
		Point[i] = c.getVertex(i);
}
	
void Curve::Rotate(char c)
{

	class::Polygon tempP(4, Point);
	tempP.Rotate(' ');

	for(int i = 0; i < 4; i++)
	{
		Point[i] = tempP.getVertex(i);
	}
	//Draw();
}

void Curve::Fill(float r, float g, float b)
{
}

string Curve::SaveFile()
{
	string space = " ";
	string p1 = float2str(Point[0].X) + space + float2str(Point[0].Y) + space;
	string p2 = float2str(Point[1].X) + space + float2str(Point[1].Y) + space;
	string p3 = float2str(Point[2].X) + space + float2str(Point[2].Y) + space;
	string p4 = float2str(Point[3].X) + space + float2str(Point[3].Y) + space;
	string s = "curve " + p1 + p2 + p3 + p4 + float2str(lineWidth) + space + COLOR2str(lineColor);
	cout<<s<<endl;
	return s;
}

void Curve::Disappear()
{
	Curve c(4, Point);
	c.setLineColor(1,1,1);
	c.setLineWidth(lineWidth);
	c.Draw();
}