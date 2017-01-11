#ifndef MainCtrl_h
#define MainCtrl_h

#include "Graphics.h"
#include "Point.h"
#include "Line.h"
#include "Polygon.h"
#include "Circle.h"
#include "Elipse.h"
#include "Teapot.h"
#include "Curve.h"

#include <iostream>
using namespace std;

#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>

class MainCtrl
{
public:
	MainCtrl();
	MainCtrl(string filename);
	void ReadFromFile(string filename);
	~MainCtrl();

	void SetLineColor(float r, float g, float b);
	void SetLineWidth(float lw);

	
	void DrawGraph();

	void UpGraph();
	void DownGraph();
	void LeftGraph();
	void RightGraph();

	void Increase();
	void Decrease();
	
	void Rotate(char c);

	void Fill(float r, float g, float b);
	void CutGraph();

	void Disappear();
	void SaveToFile(string filename);

	float str2float(string s);
	//Type str2type(string s);
	COLOR str2COLOR(string s);
	vector<string> splitStr(string line, string flag);

public:
	vector<Graphics*> GraphList;
	vector<string> GraphData;

	COORD c[2];
};

#endif