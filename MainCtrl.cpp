#include "MainCtrl.h"

MainCtrl::MainCtrl()
{
	int pointX = -400 + random(200) ;
	int pointY = 100 + random(200);
	Graphics *point = new Point(pointX, pointY );
	point->setLineWidth(5 );
	point->setLineColor( 1,0,0);
	point->graphicsType = "point";
	GraphList.push_back(point);

	int lineSX = -200 + random(200);
	int lineSY = 100 + random(200);
	int lineEX = -200 + random(200);
	int lineEY = 100 + random(200);
	Graphics *line = new Line(lineSX, lineSY, lineEX, lineEY);
	line->setLineWidth(5 );
	line->setLineColor(0,1,0 );
	line->graphicsType ="line";
	GraphList.push_back(line);

	int n = 4;
	COORD C[] = { {0,100}, {0, 200}, {100, 175}, {100,100}};
	Graphics *polygon = new class::Polygon(n, C);
	polygon->setLineWidth( 5 );
	polygon->setLineColor(0,0,1);
	polygon->graphicsType = "polygon";
	polygon->filled = true;
	COLOR tempColor = {1,0,0};
	polygon->fillColor = tempColor;
	GraphList.push_back(polygon);

	COORD circleCenter = { -400 + random(200), -300+random(200) };
	Graphics *circle = new Circle(circleCenter, 75 );
	circle->setLineWidth( 5 );
	circle->setLineColor(0.5,0.5,1);
	circle->graphicsType = "circle";
	GraphList.push_back(circle);

	COORD elipseCenter = { -400+random(200), -100+random(200) };
	Graphics *elipse = new Elipse(elipseCenter, 100,50);
	elipse->setLineWidth( 5 );
	elipse->setLineColor(1,0,1);
	elipse->graphicsType = "ellipse";
	GraphList.push_back(elipse);

	float size = 100;
	double x = 150,y = 0,z=0;
	Graphics *teapot = new Teapot(size,x,y,z);
	teapot->setLineColor(0.6, 0.5, 0.4);
	teapot->setLineWidth(1);
	teapot->graphicsType = "teapot";
	GraphList.push_back(teapot);

	COORD cCurve[4] = { {0, -300}, {0,-100}, {200,-100}, {200,-300}};
	Graphics *curve = new Curve(4, cCurve);
	curve->setLineColor(0,0,0);
	curve->setLineWidth(2);
	curve->graphicsType = "curve";
	GraphList.push_back(curve);
}
MainCtrl::MainCtrl(string filename)
{
	ReadFromFile(filename);
}
void MainCtrl::ReadFromFile(string filename)
{
	ifstream GraphFile(filename);
    if( !GraphFile)
    {
        cout<<"ReadGraphFile: File Not Found!"<<endl;
        exit(-1);
    }
    string line;
    while(!GraphFile.eof())
    {
        getline(GraphFile, line);
		//将图形数据读入GraphData
		GraphData.push_back(line);
    }
    GraphFile.close();

	//init 图形列表
	for(auto i = GraphData.begin(); i != GraphData.end(); i++)
	{
		vector<string> token = splitStr( *i, " ");

		 if(token[0] == "point")
        {
			Graphics *p = new Point(str2float(token[1]), str2float(token[2]) );
			p->setLineWidth( str2float(token[3]) );
			COLOR c = str2COLOR(token[4]);
			p->setLineColor( c.R, c.G, c.B);
			p->graphicsType = "point";
			GraphList.push_back(p);
        }
        else if(token[0] == "line")
        {
			Graphics *l = new Line(str2float(token[1]), str2float(token[2]), str2float(token[3]), str2float(token[4]));
			l->setLineWidth( str2float(token[5]) );
			COLOR c = str2COLOR(token[6]);
			l->setLineColor(c.R, c.G,c.B );
			l->graphicsType = "line";
			GraphList.push_back(l);
        }
		else if(token[0] == "polygon")
		{
			int n = ( token.size()-3 ) / 2;
			COORD *C = new COORD [n];
			int count = 0;
			for( unsigned int i = 1; i < token.size()-2; i=i+2 )
			{
				C[count].X = str2float(token[i] );
				C[count].Y = str2float(token[i+1] );
				count++;
			}

			Graphics *p = new class::Polygon(n, C);
			p->setLineWidth( str2float(token[token.size()-1]) );
			COLOR c = str2COLOR(token[token.size()-2]);
			p->setLineColor(c.R, c.G, c.B);
			p->graphicsType = "polygon";
			GraphList.push_back(p);
		}
		else if(token[0] == "circle")
		{
			COORD center = { str2float(token[1]), str2float(token[2]) };
			Graphics *c = new Circle(center, str2float(token[3]) );
			c->setLineWidth( str2float(token[4]) );
			COLOR lc = str2COLOR(token[5]);
			c->setLineColor(lc.R, lc.G, lc.B);
			c->graphicsType = "circle";
			GraphList.push_back(c);
		}
		else if(token[0] == "elipse")
		{
			COORD center = { str2float(token[1]), str2float(token[2]) };
			Graphics *e = new Elipse(center, str2float(token[3]),  str2float(token[4]));
			e->setLineWidth( str2float(token[5]) );
			COLOR c = str2COLOR(token[6]);
			e->setLineColor(c.R, c.G, c.B);
			e->graphicsType = "ellipse";
			GraphList.push_back(e);
		}
		else if(token[0] == "curve")
		{
			COORD c[4];
			for(int i = 1 ; i < 5; i=i+2)
			{
				c[i].X = str2float(token[i]);
				c[i].Y = str2float(token[i+1]);
			}
			Graphics *curve = new Curve(4, c);
			curve->setLineWidth( str2float(token[9]) );
			COLOR color = str2COLOR(token[10]);
			curve->setLineColor(color.R, color.G, color.B);
			curve->graphicsType = "curve";
			GraphList.push_back(curve);
		}
		else if(token[0] == "teapot")
		{
			Graphics *teapot = new Teapot(str2float(token[1]), str2float(token[2]), str2float(token[3]), str2float(token[4]));
			teapot->setLineWidth( str2float(token[5]) );
			COLOR c = str2COLOR(token[6]);
			teapot->setLineColor(c.R, c.G, c.B);
			teapot->graphicsType = "teapot";
			GraphList.push_back(teapot);
		}
	}
    cout<<"Read GraphFile Successfully"<<endl;
}
MainCtrl::~MainCtrl()
{
}


void MainCtrl::SetLineColor(float r, float g, float b)
{
	for(auto i = GraphList.begin(); i != GraphList.end(); i++)
	{
		(*i)->setLineColor(r,g,b);
		(*i)->Draw();
	}
}
void MainCtrl::SetLineWidth(float lw)
{
	for(auto i = GraphList.begin(); i != GraphList.end(); i++)
	{
		(*i)->Disappear();
		(*i)->setLineWidth(lw);
		(*i)->Draw();
	}
}

void MainCtrl::DrawGraph()
{
	for(auto i = GraphList.begin(); i !=GraphList.end(); i++)
		(*i)->Draw();
}

void MainCtrl::Increase()
{
	for(auto i = GraphList.begin(); i != GraphList.end(); i++)
	{
		(*i)->Disappear();
		(*i)->Increase();
		(*i)->Draw();
	}
}
void MainCtrl::Decrease()
{
	for(auto i = GraphList.begin(); i != GraphList.end(); i++)
	{
		(*i)->Disappear();
		(*i)->Decrease();
		(*i)->Draw();
	}
}

void MainCtrl::UpGraph()
{
	for(auto i = GraphList.begin(); i != GraphList.end(); i++)
	{
		(*i)->Disappear();
	}
	for(auto i = GraphList.begin(); i != GraphList.end(); i++)
	{
		(*i)->Up();
		(*i)->Draw();
	}
}
void MainCtrl::DownGraph()
{
	for(auto i = GraphList.begin(); i != GraphList.end(); i++)
	{
		(*i)->Disappear();
	}
	for(auto i = GraphList.begin(); i != GraphList.end(); i++)
	{
		(*i)->Down();
		(*i)->Draw();
	}
}
void MainCtrl::LeftGraph()
{
	for(auto i = GraphList.begin(); i != GraphList.end(); i++)
	{
		(*i)->Disappear();
	}
	for(auto i = GraphList.begin(); i != GraphList.end(); i++)
	{
		(*i)->Left();
		(*i)->Draw();
	}
}
void MainCtrl::RightGraph()
{
	for(auto i = GraphList.begin(); i != GraphList.end(); i++)
	{
		(*i)->Disappear();
	}
	for(auto i = GraphList.begin(); i != GraphList.end(); i++)
	{
		(*i)->Right();
		(*i)->Draw();
	}
}

void MainCtrl::Rotate(char c)
{
	for(auto i = GraphList.begin(); i != GraphList.end(); i++)
	{
		(*i)->Disappear();
	}
	for(auto i = GraphList.begin(); i != GraphList.end(); i++)
	{
		(*i)->Rotate(c);
		(*i)->Draw();
	}
}

void MainCtrl::Disappear()
{
	/*
	for(auto i = GraphList.begin(); i != GraphList.end(); i++)
	{
		(*i)->Disappear();
	}*/
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();

	glColor3f(0.0f, 0.0f, 0.0f);
	glEnable (GL_LINE_STIPPLE);
    glLineStipple (1, 0x0101);  
     drawOneLine (-400, 200, 400, 200);
    drawOneLine (-400, 100, 400, 100);
	 drawOneLine (-400, 0, 400, 0);
    drawOneLine (-400, -100, 400, -100);
	drawOneLine (-400, -200, 400, -200);
	drawOneLine (-300, -300, -300, 300);
    drawOneLine (-200, -300, -200, 300);
	drawOneLine (-100, -300, -100, 300);
	drawOneLine (0, -300, 0, 300);
	drawOneLine (100, -300, 100, 300);
	drawOneLine (200, -300, 200, 300);
	drawOneLine (300, -300, 300, 300);
    glDisable (GL_LINE_STIPPLE);
    glFlush();
}

void MainCtrl::CutGraph()
{
	/*int n = 4;
	COORD PC[] = {{c[0].X, c[0].Y}, {c[0].X, c[1].Y}, {c[1].X, c[1].Y}, {c[1].X, c[0].Y}};
	class::Polygon p(n,PC);
	p.setLineWidth(3);
	p.setLineColor(1,0,0);
	p.Draw();*/
	int left = (c[0].X > c[1].X) ? c[1].X : c[0].X;
	int right = (c[0].X > c[1].X) ? c[0].X : c[1].X;
	int top = (c[0].Y > c[1].Y) ? c[0].Y : c[1].Y;
	int bottom = (c[0].Y > c[1].Y) ? c[1].Y : c[0].Y;

	COORD p[] = {{left,top}, {left, bottom}, {right, bottom}, {right, top}};
	class::Polygon poly(4,p);
	poly.Fill(1,1,1);
	/*for(int i = bottom; i <= top; i++)
	{
		Line l(left, i, right ,i);
		l.setLineColor(1,1,1);
		l.setLineWidth(3);
		l.Draw();
	}*/
}
void MainCtrl::Fill(float r, float g, float b)
{
	for(auto i = GraphList.begin(); i != GraphList.end(); i++)
	{
		(*i)->Fill(r,g,b);
	}
}

void MainCtrl::SaveToFile(string filename)
{
	ofstream file(filename);
	for(auto i = GraphList.begin(); i != GraphList.end(); i++)
	{
			file<<(*i)->SaveFile()<<endl;
	}
	file.close();
	cout<<"#CGP# 图形数据保存成功！ ";
}


float MainCtrl::str2float(string s)
{
	return atof(s.c_str());
}
COLOR MainCtrl::str2COLOR(string s)
{
	//字符串s是形如（0，0，0）的表示颜色的字符串
	float c[3] = {0.0f, 0.0f, 0.0f};
	s =s.substr(1, s.size()-2);
	
	for(int i = 0; i < 2; i++)
	{
		auto split_pos = s.find(",");
		c[i] =  str2float(s.substr(0, split_pos) );
		s.erase(0, split_pos+1);
	}
	c[2] = str2float(s);
	COLOR C = {c[0], c[1], c[2]};
	return C;
}
vector<string> MainCtrl::splitStr(string line, string flag)
{
	vector<string> token;
    auto split_pos = line.find(flag);
    while(split_pos <= line.length())
	{
		token.push_back(line.substr(0, split_pos));
        line.erase(0, split_pos+1);
        split_pos = line.find(flag);
	}
    token.push_back(line);
	return token;
}


