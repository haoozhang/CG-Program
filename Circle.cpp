#include "Circle.h"

Circle::Circle()
{
	COORD c = {0.0, 0.0};
	center = c;
	radiusa = 0.0;
	radiusb = 0.0;

	lineWidth = 1.0f;

	COLOR lc = {0.0f, 0.0f, 0.0f};
	lineColor = lc;
}
Circle::Circle(COORD c, float r)
{
	center = c;
	radiusa = r;
	radiusb = r;

	lineWidth = 1.0f;
	COLOR lc = {0.0f, 0.0f, 0.0f};
	lineColor = lc;
}
Circle::~Circle()
{
}

void Circle::setLineColor(float r, float g, float b)
{
	COLOR c = {r,g,b};
	lineColor = c;
	//Disappear();
	//Draw();
}
COLOR Circle::getLineColor() const
{
	return lineColor;
}

void Circle::setLineWidth(float lw)
{
	lineWidth = lw;
	//Disappear();
	//Draw();
}
float Circle::getLineWidth() const
{
	return lineWidth;
}

void Circle::Draw()
{
	Elipse circle(center, radiusa, radiusb);
	circle.setLineWidth(lineWidth);
	circle.setLineColor(lineColor.R, lineColor.G, lineColor.B);
	circle.Draw();
	if(filled == true)
		Fill(fillColor.R, fillColor.G, fillColor.B);
}

void Circle::Up()
{
	center.Y += 40;
}
void Circle::Down()
{
	center.Y -= 40;
}
void Circle::Left()
{
	center.X -= 40;
}
void Circle::Right()
{
	center.X += 40;
}

void Circle::Increase()
{
	radiusa += 20;
	radiusb += 20;
}
void Circle::Decrease()
{
	radiusa -= 20;
	radiusb -= 20;
}

void Circle::Rotate(char ch)
{

}

void Circle::Fill(float r, float g, float b)
{
	filled = true;
	COLOR fc = {r, g, b};
	fillColor = fc;
	for(int i= 0; i < radiusa-3; i=i+5)
	{
		Circle c(center, i);
		c.setLineColor(r,g,b);
		c.setLineWidth(5);
		c.Draw();
	}

}

void Circle::Disappear()
{
	Elipse cc(center, radiusa, radiusb);
	cc.setLineWidth(lineWidth);
	cc.setLineColor(1,1,1);
	cc.Draw();
}

string Circle::SaveFile()
{
	string space = " ";
	string p = float2str(center.X) + space + float2str(center.Y) + space +float2str(radiusa) + space ;
	string fill = bool2str(filled) + space + COLOR2str(fillColor) + space;
	string s = "circle " + p + float2str(lineWidth) + space + COLOR2str(lineColor) +space + fill;
	cout<<s<<endl;
	return s;
}