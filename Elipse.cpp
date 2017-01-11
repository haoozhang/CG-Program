#include "Elipse.h"

Elipse::Elipse()
{
	COORD c = {0.0f, 0.0f};
	center = c;
	a = 0.0f;
	b = 0.0f;

	lineWidth = 1.0f;
	COLOR lc = {0.0f, 0.0f, 0.0f};
	lineColor = lc;

}
Elipse::~Elipse()
{
}
Elipse::Elipse(COORD c, float a, float b)
{
	center = c;
	this->a = a;
	this->b = b;

	lineWidth = 1.0f;
	COLOR lc = {0.0f, 0.0f, 0.0f};
	lineColor = lc;
}

void Elipse::setLineColor(float r, float g, float b)
{
	COLOR lc=  {r,g,b};
	lineColor  =lc;
	//Disappear();
	//Draw();
}
COLOR Elipse::getLineColor() const
{
	return lineColor;
}
void Elipse::setLineWidth(float lw)
{
	lineWidth = lw;
	//Disappear();
	//Draw();
}
float Elipse::getLineWidth() const
{
	return lineWidth;
}

//画点
void Elipse::setPixel(int x, int y)
{
	glColor3f(lineColor.R, lineColor.G, lineColor.B); 
    glPointSize(lineWidth);

    glBegin(GL_POINTS);
        glVertex2f(x, y);
    glEnd();
    glFlush();
}
//椭圆4路对称
void Elipse::Elipsepot(int x0, int y0, int x, int y)
{
    // 1
    setPixel((x0 + x), (y0 + y));
    // 2
    setPixel((x0 + x), (y0 - y));
    // 3
    setPixel((x0 - x), (y0 - y));
    // 4
    setPixel((x0 - x), (y0 + y));
}
void Elipse::Draw()
{
	float x0 = center.X;
	float y0 = center.Y;
    double sqa = a*a;
    double sqb = b*b;

    double d = sqb + sqa*(0.25 - b);
    int x = 0;
    int y = b;
    Elipsepot(x0, y0, x, y);
    // 1
    while (sqb*(x + 1) < sqa*(y - 0.5))
    {
        if (d < 0)
        {
            d += sqb*(2 * x + 3);
        }
        else
        {
            d += (sqb*(2 * x + 3) + sqa*((-2)*y + 2));
            --y;
        }
        ++x;
        Elipsepot(x0, y0, x, y);
    }
    d = (b * (x + 0.5)) * 2 + (a * (y - 1)) * 2 - (a * b) * 2;
    // 2
    while (y > 0)
    {
        if (d < 0)
        {
            d += sqb * (2 * x + 2) + sqa * ((-2) * y + 3);
            ++x;
        }
        else
        {
            d += sqa * ((-2) * y + 3);
        }
        --y;
        Elipsepot(x0, y0, x, y);
    }

	if(filled == true)
		Fill(fillColor.R, fillColor.G, fillColor.B);
}

void Elipse::Up()
{
	center.Y += 40;
}
void Elipse::Down()
{
	center.Y -= 40;
}
void Elipse::Left()
{
	center.X -= 40;
}
void Elipse::Right()
{
	center.X += 40;
}

void Elipse::Increase()
{
	a += a/b *20;
	b += 20;
}
void Elipse::Decrease()
{
	a -= a/b *20;
	b -= 20;
}

void Elipse::Rotate(char ch)
{
	swap(a, b);
}

void Elipse::Fill(float r, float g, float b1)
{
	filled = true;
	COLOR fc = {r, g, b};
	fillColor = fc;
	//和圆一样的思路填充，不过某些细节，起初画细密一点填充中间，之后快速画
	int i= 0; 
	while(i < b - 4) 
	{
		Elipse e(center, a-5, i);
		e.setLineColor(r,g,b1);
		e.setLineWidth(5);
		e.Draw();

		if(i < 5)
			i++;
		else
			i += 5;
	}
}

void Elipse::Disappear()
{
	Elipse cc(center, a, b);
	cc.setLineWidth(lineWidth);
	cc.setLineColor(1,1,1);
	cc.Draw();
}

string Elipse::SaveFile()
{
	string space = " ";
	string p = float2str(center.X) + space + float2str(center.Y) + space +float2str(a) + space + float2str(b) + space;
	string fill = bool2str(filled) + space + COLOR2str(fillColor) + space;
	string s = "ellipse " + p + float2str(lineWidth) + space + COLOR2str(lineColor) + space + fill;
	cout<<s<<endl;
	return s;
}