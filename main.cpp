#include"drawOrigin.h"
#include<Windows.h>
#include <graphics.h> 
using namespace std;
int main()

{
	//int gd=DETECT,gm; /*图形屏幕初始化*/
	initgraph(900, 750, NULL);

	/*画图区域*/
	snow_snow();
	tree_tree();	
	sonwman(340,230);

	_getch();
	closegraph();
	system("pause");
	return 0;
}