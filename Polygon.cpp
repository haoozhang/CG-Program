#include "Polygon.h"

Polygon::Polygon()
{
	lineWidth = 1.0f;
	COLOR c = {0.0f, 0.0f, 0.0f};
	lineColor = c;

	int n = 4;
	COORD C[] = { {0,0}, {-100, 0}, {-100, 100}, {0,100}};
	for(int i = 0; i < n; i++)
	{
		Vertex.push_back(C[i]);
	}

	length = new double[Vertex.size() -1];
	dir = new DIR[Vertex.size()-1];
	for(unsigned int i = 0; i < Vertex.size()-1; i++)
		length[i] = sqrt( pow((Vertex[i+1].Y-Vertex[0].Y), 2) + pow((Vertex[i+1].X-Vertex[0].X), 2) );
	for(unsigned int i = 0; i < Vertex.size()-1; i++)
	{
		dir[i].X = ( Vertex[i+1].X-Vertex[0].X ) / length[i];
		dir[i].Y = ( Vertex[i+1].Y-Vertex[0].Y ) / length[i];
	}
	angle = 30*3.1415926/180.0;
	n = 1;
}
Polygon::~Polygon()
{
}
/*Polygon::Polygon(COORD b, COORD e)
{
	Vertex.push_back(b);
	Vertex.push_back(e);
}*/
Polygon::Polygon(int n, COORD c[])
{
	lineWidth = 1.0f;
	COLOR l = {0.0f, 0.0f, 0.0f};
	lineColor = l;

	for(int i = 0; i < n; i++)
	{
		Vertex.push_back(c[i]);
	}

	length = new double[Vertex.size() -1];
	dir = new DIR[Vertex.size()-1];
	for(unsigned int i = 0; i < Vertex.size()-1; i++)
	{
		length[i] = sqrt( pow((Vertex[i+1].Y-Vertex[0].Y), 2) + pow((Vertex[i+1].X-Vertex[0].X), 2) );
		dir[i].X = ( Vertex[i+1].X-Vertex[0].X ) / length[i];
		dir[i].Y = ( Vertex[i+1].Y-Vertex[0].Y ) / length[i];
	}
	angle = 30*3.1415926/180.0;
	n = 1;
}

COORD Polygon::getVertex(int n)
{
	return Vertex[n];
}

void Polygon::setLineColor(float r, float g, float b)
{
	COLOR c = {r, g, b};
	lineColor = c;
	//Disappear();
	//Draw();
}
COLOR Polygon::getLineColor() const
{
	return lineColor;
}

void Polygon::setLineWidth(float lw)
{
	lineWidth = lw;
	//Disappear();
	//Draw();
}
float Polygon::getLineWidth() const
{
	return lineWidth;
}

void Polygon::Draw()
{		
	for(auto i = Vertex.begin(); i != Vertex.end()-1; i++)
	{
		COORD b = { (*i).X, (*i).Y};
		COORD e = { (*(i+1)).X, (*(i+1)).Y};
	
		Line L(b, e);
		L.setLineColor(lineColor.R, lineColor.G, lineColor.B);
		L.setLineWidth(lineWidth);
		L.Draw();	
	}
	COORD b = { (*Vertex.begin()).X, (*Vertex.begin()).Y};
	COORD e = { (*(Vertex.end()-1)).X, (*(Vertex.end()-1)).Y};
	Line L(b,e);
	L.setLineColor(lineColor.R, lineColor.G, lineColor.B);
	L.setLineWidth(lineWidth);
	L.Draw();
	glFlush();

	if(filled == true)
		Fill(fillColor.R, fillColor.G, fillColor.B);
}

void Polygon::Up()
{
	for(auto i = Vertex.begin(); i != Vertex.end(); i++)
		(*i).Y += 40;
}
void Polygon::Down()
{
	for(auto i = Vertex.begin(); i != Vertex.end(); i++)
		(*i).Y -= 40;
}
void Polygon::Left()
{
	for(auto i = Vertex.begin(); i != Vertex.end(); i++)
		(*i).X -= 40;
}
void Polygon::Right()
{
	for(auto i = Vertex.begin(); i != Vertex.end(); i++)
		(*i).X += 40;
}

void Polygon::Increase()
{
	//以第一个定点为起点，加大其余各点的坐标
	for(unsigned int i = 0 ; i < Vertex.size()-1; i++)
	{
		Vertex[i+1].X  += Vertex[i+1].X - Vertex[0].X;
		Vertex[i+1].Y  += Vertex[i+1].Y - Vertex[0].Y;
	}
	
	//更新各点到第一个点的距离和方向向量
	for(unsigned int i = 0; i < Vertex.size()-1; i++)
		length[i] = sqrt( pow((Vertex[i+1].Y-Vertex[0].Y), 2) + pow((Vertex[i+1].X-Vertex[0].X), 2) );
	for(unsigned int i = 0; i < Vertex.size()-1; i++)
	{
		dir[i].X = ( Vertex[i+1].X-Vertex[0].X ) / length[i];
		dir[i].Y = ( Vertex[i+1].Y-Vertex[0].Y ) / length[i];
	}	
}
void Polygon::Decrease()
{
	//Disappear();
	for(unsigned int i = 0 ; i < Vertex.size()-1; i++)
	{
		Vertex[i+1].X  -= (Vertex[i+1].X - Vertex[0].X) * 0.5;
		Vertex[i+1].Y  -= (Vertex[i+1].Y - Vertex[0].Y) * 0.5;
	}
	
	for(unsigned int i = 0; i < Vertex.size()-1; i++)
		length[i] = sqrt( pow((Vertex[i+1].Y-Vertex[0].Y), 2) + pow((Vertex[i+1].X-Vertex[0].X), 2) );
	for(unsigned int i = 0; i < Vertex.size()-1; i++)
	{
		dir[i].X = ( Vertex[i+1].X-Vertex[0].X ) / length[i];
		dir[i].Y = ( Vertex[i+1].Y-Vertex[0].Y ) / length[i];
	}
}

void Polygon::Rotate(char ch)
{
	DIR *temp = new DIR [Vertex.size()-1];
	for(unsigned int i = 0; i < Vertex.size() - 1; i++)
	{
		temp[i].X = dir[i].X;
		temp[i].Y = dir[i].Y;
	}

	for(unsigned int i = 0; i < Vertex.size()-1; i++)
	{
		dir[i].X = cos(angle)*temp[i].X - sin(angle)*temp[i].Y;
		dir[i].Y = sin(angle)*temp[i].X + cos(angle)*temp[i].Y;
		Vertex[i+1].X = Vertex[0].X + length[i] * dir[i].X;
		Vertex[i+1].Y = Vertex[0].Y + length[i] * dir[i].Y;
	}
	//n++;
}

void Polygon::Fill(float r, float g, float b)
{
	filled = true;
	COLOR fc = {r, g, b};
	fillColor = fc;

	glColor3f(r,g,b);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	for(auto i = Vertex.begin(); i != Vertex.end(); i++)
	{
		glVertex2f( (*i).X, (*i).Y);
	}
	glEnd();
	glFlush();
}

string Polygon::SaveFile()
{
	string space = " ";
	string p;
	for(auto i = Vertex.begin(); i != Vertex.end(); i++)
	{
		p += float2str((*i).X) + space + float2str((*i).Y) + space;
	}
	string fill = bool2str(filled) + space + COLOR2str(fillColor) + space;
	string s = "polygon " + p + float2str(lineWidth) + space + COLOR2str(lineColor) + space + fill;
	cout<<s<<endl;
	return s;
}

void Polygon::Disappear()
{
	COORD *c = new COORD[Vertex.size()];
	for(unsigned int i = 0; i < Vertex.size(); i++)
		c[i] = Vertex[i];
	Polygon p( Vertex.size(), c);
	p.setLineColor(1,1,1);
	p.setLineWidth(lineWidth);
	p.Draw();
}