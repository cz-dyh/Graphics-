#include"drawOrigin.h"
#include<Windows.h>
#include <graphics.h> 
using namespace std;
int main()

{
	//int gd=DETECT,gm; /*ͼ����Ļ��ʼ��*/
	initgraph(900, 750, NULL);

	/*��ͼ����*/
	snow_snow();
	tree_tree();	
	sonwman(340,230);

	_getch();
	closegraph();
	system("pause");
	return 0;
}