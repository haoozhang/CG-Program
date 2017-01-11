
//MenuNo
#define 点 1001
#define 直线 1002
#define 多边形 1003
#define 圆 1004
#define 椭圆 1005
#define 茶壶 1006
#define 曲线 1007

#define 三角形 10031
#define 四边形 10032
#define 五边形 10033
#define 六边形 10034
//#define 五角星 10035

#define 红色 2100
#define 绿色 2010
#define 蓝色 2001
#define 黄色 2110
#define 粉色 2101
#define 青色 2011

#define 放大 3001
#define 缩小 3002

#define 上移 4001
#define 下移 4002
#define 左移 4003
#define 右移 4004

#define 一号 5001
#define 二号 5002
#define 三号 5003
#define 四号 5004
#define 五号 5005

#define 旋转 6

#define 填充红色 7100
#define 填充绿色 7010
#define 填充蓝色 7001
#define 填充黄色 7110
#define 填充粉色 7101
#define 填充青色 7011

#define 打开 8
#define 清空 9
#define 开始 10
#define 保存 11

//Color Type
struct COLOR
{
	float R;
	float G;
	float B;
};

/*
//Graphics Type
enum Type
{
	notype = 0,
	point = 1,
	line = 2,
	polygon = 3,
	circle = 4,
	ellipse = 5
};*/

//rand
#define random(x) (rand()%x)

//DrawLine
#define drawOneLine(x1,y1,x2,y2) glBegin(GL_LINES);glVertex2f((x1),(y1));glVertex2f((x2),(y2));glEnd()
