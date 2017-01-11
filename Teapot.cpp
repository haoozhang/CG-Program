#include "Teapot.h"

Teapot::Teapot()
{
	lineWidth = 1.0f;

	COLOR c = {0.0f, 0.0f, 0.0f};
	lineColor = c;

	size = 10;
	posX = 150.0;
	posY = 0.0;
	posZ = 0.0;

	rotateX = 30;
	rotateY = 30;

	filled = false;
}
Teapot::Teapot(double s, double x, double y, double z)
{
	lineWidth = 1.0f;

	COLOR c = {0.0f, 0.0f, 0.0f};
	lineColor = c;

	size = s;
	posX = x;
	posY = y;
	posZ = z;

	rotateX = 30;
	rotateY = 30;

	filled = false;

}

Teapot::~Teapot()
{
}

void Teapot::setLineWidth(float lw)
{
	lineWidth = lw;
}
float Teapot::getLineWidth() const
{
	return lineWidth;
}
void Teapot::setLineColor(float r, float g, float b)
{
	COLOR c = {r,g,b};
	lineColor = c;
}
COLOR Teapot::getLineColor() const
{
	return lineColor;
}

void  Teapot::setPos(double a, double b, double c)
{
	posX = a;
	posY = b;
	posZ = c;
}
double  Teapot::getPosX() const
{
	return posX;
}
double  Teapot::getPosY() const
{
	return posY;
}
double  Teapot::getPosZ() const
{
	return posZ;
}

void Teapot::setAngle(double x, double y)
{
	rotateX = x;
	rotateY = y;
}

void Teapot::setFilled(bool e)
{
	filled = e;
}
bool Teapot::getFilled() const
{
	return filled;
}

void Teapot::Draw()
{
	glColor3f(lineColor.R, lineColor.G, lineColor.B);
	glLineWidth(lineWidth);

	glPushMatrix();
	glRotatef(rotateY,0,1,0);     //是想在物体的初始状态时旋转一定角度 
	glRotatef(rotateX,1,0,0);
	//glRotated(angle, rotateX, rotateY, rotateZ);
	glTranslated(posX,posY,posZ);
	if(filled)
	{
		glColor3f(fillColor.R, fillColor.G, fillColor.B);
		glutSolidTeapot(size);
	}
	else
	{
		glutWireTeapot(size);
	}
	glPopMatrix();

	//glutWireCube(size);
	glFlush();
}

void Teapot::Up()
{
	posY += 40;
}
void Teapot::Down()
{
	posY -= 40;
}
void Teapot::Left()
{
	posX -= 40;
}
void Teapot::Right()
{
	posX += 40;
}

void Teapot::Increase()
{
	size = size * 2;
}
void Teapot::Decrease()
{
	size = size * 0.5;
}
	
void Teapot::Rotate(char ch)
{
	switch (ch)
	{
	case 'a':
		rotateY-=10;
		break;
	case 's':
		rotateX-=10;
		break; 
	case 'd':
		rotateY+=10;
		break;
	case 'w':
		rotateX+=10;
		break;
	default:
		rotateX-=10;
		break;
	}
}

void Teapot::Fill(float r, float g, float b)
{
	filled = true;
	COLOR fc = {r, g, b};
	fillColor = fc;
	Draw();
}

void Teapot::Disappear()
{
	Teapot t(size,posX,posY,posZ);
	t.setLineColor(1,1,1);
	t.setLineWidth(lineWidth);
	t.setPos(posX,posY,posZ);
	t.setAngle(rotateX, rotateY);
	t.setFilled(filled);
	t.Draw();
}

string Teapot::SaveFile()
{
	string space = " ";
	string fill = bool2str(filled) + space + COLOR2str(fillColor) + space;
	string p = float2str(size) + space + float2str(posX) + space + float2str(posY) + space + float2str(posZ) + space;
	string s = "teapot " + p + float2str(lineWidth) + space + COLOR2str(lineColor) + space + fill;
	cout<<s<<endl;
	return s;
}