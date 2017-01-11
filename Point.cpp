#include "Point.h"

Point::Point()
{
	lineWidth = 1.0;
	COLOR c = {0.0f, 0.0f, 0.0f};
	lineColor = c;
}
Point::Point(float x, float y)
{
	pos.X = x;
	pos.Y = y;
	lineWidth = 1.0;
	COLOR c = {0.0f, 0.0f, 0.0f};
	lineColor = c;
}
Point::Point(COORD p)
{
	pos = p;
	lineWidth = 1.0;
	COLOR c = {0.0f, 0.0f, 0.0f};
	lineColor = c;
}
Point::~Point()
{
	
}

COORD Point::getPos() const
{
	return pos;
}
void  Point::setPos(COORD p)
{
	pos = p;
}

float Point::getLineWidth() const
{
	return lineWidth;
}
void Point::setLineWidth(float p)
{
	lineWidth = p;
	//Disappear();
	//Draw();
}
COLOR Point::getLineColor() const
{
	return lineColor;
}
void Point::setLineColor(float r, float g, float b)
{
	COLOR pc = {r,g,b};
	lineColor = pc;
	//Disappear();
	//Draw();
}

void Point::Draw()
{
	glPointSize(lineWidth);	
	glColor3f(lineColor.R, lineColor.G, lineColor.B);
	glBegin(GL_POINT);	//glBegin和glEnd标明绘制图形的属性
	glVertex2d(pos.X, pos.Y);		//2i表示位置为两个int型变量
	glEnd();
	glFlush();	//flush缓冲区立即执行
}

void Point::Up()
{
	pos.Y += 40;
}
void Point::Down()
{
	pos.Y -= 40;
}
void Point::Left()
{
	pos.X -= 40;
}
void Point::Right()
{
	pos.X += 40;
}

void Point::Increase()
{
}
void Point::Decrease()
{
}

void Point::Rotate(char ch)
{
}

void Point::Fill(float r, float g, float b)
{
}

void Point::Disappear()
{
	Point p(pos.X, pos.Y);
	p.setLineColor(1,1,1);
	p.setLineWidth(lineWidth);
	p.Draw();
}

string Point::SaveFile()
{
	string space = " ";
	string p = float2str(pos.X) + space + float2str(pos.Y) + space;
	string s = "point " + p + float2str(lineWidth) + space + COLOR2str(lineColor);
	cout<<s<<endl;
	return s;
}