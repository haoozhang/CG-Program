#include "Line.h"

Line::Line()
{
	
	lineWidth = 1.0f;

	COLOR c = {0.0f, 0.0f, 0.0f};
	lineColor = c;

	COORD b = {0.0f, 0.0f};
	COORD e = {0.0f, 0.0f};
	

	
	length = sqrt( pow((end.Y-begin.Y), 2) + pow((end.X-begin.X), 2) );
	dir[0] = (end.X-begin.X) / length;
	dir[1] = (end.Y-begin.Y) / length;
	angle = 30*3.1415926/180.0;
	n = 1;

}
Line::Line(COORD b, COORD e)
{
	lineWidth = 1.0f;

	COLOR c = {0.0f, 0.0f, 0.0f};
	lineColor = c;

	begin = b;
	end = e;

	length = sqrt( pow((end.Y-begin.Y), 2) + pow((end.X-begin.X), 2) );
	dir[0] = (end.X-begin.X) / length;
	dir[1] = (end.Y-begin.Y) / length;
	angle = 30*3.1415926/180.0;
	n = 1;
}
Line::Line(float sx, float sy, float ex, float ey)
{
	begin.X = sx;
	begin.Y = sy;
	end.X = ex;
	end.Y = ey;

	lineWidth = 1.0f;

	COLOR c = {0.0f, 0.0f, 0.0f};
	lineColor = c;

	length = sqrt( pow((end.Y-begin.Y), 2) + pow((end.X-begin.X), 2) );
	dir[0] = (end.X-begin.X) / length;
	dir[1] = (end.Y-begin.Y) / length;
	angle = 30*3.1415926/180.0;
	n = 1;
}
Line::~Line()
{
}
/*
Line::Line(SMALL_RECT p)
{
	lineWidth = 1.0f;
	COLOR c = {0.0f, 0.0f, 0.0f};
	lineColor = c;
	pos = p;
}*/

void Line::Draw()
{
	float x1 =begin.X, y1 = begin.Y, x2 = end.X, y2 = end.Y;

	glColor3f(lineColor.R, lineColor.G, lineColor.B);
	glPointSize(lineWidth);
	if(x1 == x2) //无斜率，垂直X轴
	{
		cout<<"垂直X轴"<<endl;
		if(y1 > y2)
			swap(y1, y2);
		//glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_POINT);
		while(y1 <= y2)
		{
			glVertex2d(x1, y1);
			y1++;
		}
		glEnd();
		glFlush();
	}
	else
	{
		//判断斜率是正是负
		int flag_k = ((y2 - y1) * (x2 - x1) < 0) ? -1 : 1;
		//记录斜率的范围
		double k;
		if(y1 == y2)
			k = 0;
		else if( abs(y2-y1) == abs(x2-x1))
			k = 1;
		else if(abs(y2-y1) > abs(x2-x1))
			k = 2;
		else
			k = 0.5;

		if(k == 0) //垂直Y轴
		{
			cout<<"垂直Y轴"<<endl;
			if(x1 > x2)
				swap(x1, x2);
			//glClear(GL_COLOR_BUFFER_BIT);
			glBegin(GL_POINT);
			while(x1 <= x2)
			{
				glVertex2d(x1, y1);
				x1++;
			}
			glEnd();
			glFlush();
		}
		else if(k == 1)
		{
			if(flag_k == 1) // k=1
			{
				cout<<"k=1"<<endl;
				if(x1 > x2)
				{
					swap(x1, x2);
					swap(y1, y2);
				}
				//glClear(GL_COLOR_BUFFER_BIT);
				glBegin(GL_POINT);
				while(x1 <= x2)
				{
					glVertex2d(x1, y1);
					x1++;
					y1++;
				}
				glEnd();
				glFlush();
			}
			else //k = -1
			{
				cout<<"k=-1"<<endl;
				if(x1 > x2)
				{
					swap(x1, x2);
					swap(y1, y2);
				}
				//glClear(GL_COLOR_BUFFER_BIT);
				glBegin(GL_POINT);
				while(x1 <= x2)
				{
					glVertex2d(x1, y1);
					x1++;
					y1--;
				}
				glEnd();
				glFlush();
			}
		}
		else if(k > 1)  //increament y
		{
			cout<<"k>1"<<endl;
			int dx = abs(x2 - x1);  
			int dy = abs(y2 - y1);   
			int temp1 = 2 * dx;  
			int temp2 = 2 * (dx - dy);  
			int p = 2 * dx - dy;  
			if(y1 > y2) 
			{
				swap(x1, x2);
				swap(y1, y2);
			}
			//glClear(GL_COLOR_BUFFER_BIT);  
		    glBegin(GL_POINT);  
			glVertex2d(x1, y1);
		    while(y1 <= y2)  
		    {  
		        y1++;  
		        if(p < 0)  
		            p += temp1;  
		        else  
		        {  
					if(flag_k == 1)
						x1++;  
					else
						x1--;
					p += temp2;  
			    }  
				glVertex2f(x1,y1);  
			 }  
			glEnd(); 
			glFlush();
		}
		else // 0<k<1
		{
			cout<<"k<1"<<endl;
			int dx = abs(x2 - x1);  
			int dy = abs(y2 - y1);  
		    int temp1 = 2 * dy;  
			int temp2 = 2 * (dy - dx);  
			int p = 2 * dy - dx;  
			if(x1 > x2)  
			{    
				 swap(x1, x2);
				 swap(y1, y2);
			 }  
			//glClear(GL_COLOR_BUFFER_BIT);    
			glBegin(GL_POINT);  
			glVertex2d(x1, y1);  
			while(x1 < x2)  
			{  
				x1++;  
				if(p < 0)  
					p += temp1;  
				else  
				{  
					if(flag_k == 1)
						y1++;  
					else
						y1--;
					p += temp2;  
				}  
				glVertex2d(x1,y1);  
			}  
			glEnd(); 
			glFlush();
		}
	}
}

void Line::setLinePos(COORD b, COORD e)
{
	begin = b;
	end = e;
}
SMALL_RECT Line::getLinePos()
{
	SMALL_RECT temp = {begin.X, begin.Y, end.X, end.Y};
	return temp;
}
float Line::getLineWidth()
{
	return lineWidth;
}
void Line:: setLineWidth(float l)
{
	lineWidth = l;
	//Disappear();
	//Draw();
}
void Line::setLineColor(float r, float g, float b)
{
	COLOR lc = {r,g,b};
	lineColor = lc;
	//Disappear();
	//Draw();
}
COLOR Line::getLineColor() const
{
	return lineColor;
}

void Line::Up()
{
	begin.Y += 40;
	end.Y += 40;
}
void Line::Down()
{
	begin.Y -= 40;
	end.Y -= 40;
}
void Line::Left()
{
	begin.X -= 40;
	end.X -= 40;
}
void Line::Right()
{
	begin.X += 40;
	end.X += 40;
}

void Line::Increase()
{
	//end.X += 20;
	//end.Y += 20*k;
	
	//double k = (end.Y-begin.Y) / (end.X-begin.X);

	end.X += end.X - begin.X;
	end.Y += end.Y - begin.Y;
	
	length = sqrt( pow((end.Y-begin.Y), 2) + pow((end.X-begin.X), 2) );
	dir[0] = (end.X-begin.X) / length;
	dir[1] = (end.Y-begin.Y) / length;
}
void Line::Decrease()
{
	
	//double k = (end.Y-begin.Y) / (end.X-begin.X);
	end.X -= (end.X - begin.X) * 0.5;
	end.Y -= (end.Y - begin.Y) * 0.5;
	
	length = sqrt( pow((end.Y-begin.Y), 2) + pow((end.X-begin.X), 2) );
	dir[0] = (end.X-begin.X) / length;
	dir[1] = (end.Y-begin.Y) / length;
}

void Line::Rotate(char ch)
{
	//dir[0] = cos(n*angle);// * dir[0] - sin(n*angle) * dir[1];
	//dir[1] = sin( n*angle);// * dir[0] + cos(n * angle) * dir[1];
	//n++;
	float temp[2] = {dir[0], dir[1]};
	dir[0] = cos(angle)*temp[0] - sin(angle)*temp[1];
	dir[1] = sin(angle)*temp[0] + cos(angle)*temp[1];
	end.X = begin.X + length * dir[0];
	end.Y = begin.Y + length * dir[1];
}

void Line::Fill(float r, float g, float b)
{
}

string Line::SaveFile()
{
	string space = " ";
	string p = float2str(begin.X) + space + float2str(begin.Y) + space +float2str(end.X) + space + float2str(end.Y) + space;
	string s = "line " + p + float2str(lineWidth) + space + COLOR2str(lineColor);
	cout<<s<<endl;
	return s;
}

void Line::Disappear()
{
	Line l(begin.X,begin.Y,end.X,end.Y);
	l.setLineColor(1,1,1);
	l.setLineWidth(lineWidth);
	l.Draw();
}