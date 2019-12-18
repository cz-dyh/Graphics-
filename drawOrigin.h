#include <stdio.h>
#include "conio.h"
#include <graphics.h>  
#include <math.h>
#include<iostream>
#pragma once

using namespace std;

void lineBres(int x0, int y0, int xEnd, int yEnd, int c)
{
	int dx = fabs(xEnd - x0), dy = fabs(yEnd - y0);
	int p = 2 * dy - dx;
	int twoDy = 2 * dy, twoDyMinusDx = 2 * (dy - dx);
	int x, y;

	if (x0 > xEnd)
	{
		x = xEnd;
		y = yEnd;
		xEnd = x0;
	}
	else {
		x = x0;
		y = y0;
	}
	putpixel(x, y, c);

	while (x < xEnd)
	{
		x++;
		if (p < 0)
			p += twoDy;
		else {
			y++;
			p += twoDyMinusDx;
		}
		putpixel(x, y, c);
	}

}

/*DDA直线*/
void dda_line(int xa, int ya, int xb, int yb, int c)
{
	float delta_x, delta_y, delta_y1, x, y, m=1;
	int dx, dy, steps, k;
	dx = xb - xa;
	dy = yb - ya;
	if (abs(dx) > abs(dy)) steps = abs(dx);
	else steps = abs(dy);
	delta_x = (float)dx / (float)steps;
	delta_y = (float)dy / (float)steps;
	x = xa;
	y = ya;
	putpixel(x, y, c);
	for (k = 1; k <= steps; k++)
	{
		x += delta_x;
		y += delta_y;
		delta_y1 = m * delta_x;
		putpixel(x, y, c);
	}
}

void plot_circle_points(int xc, int yc, int x, int y, int c)
{
	putpixel(xc + x, yc + y, c);
	putpixel(xc - x, yc + y, c);
	putpixel(xc + x, yc - y, c);
	putpixel(xc - x, yc - y, c);
	putpixel(xc + y, yc + x, c);
	putpixel(xc - y, yc + x, c);
	putpixel(xc + y, yc - x, c);
	putpixel(xc - y, yc - x, c);
}

void Bresenham_circle(int xc, int yc, int radius, int c)
{
	int x, y, p;
	x = 0;
	y = radius;
	p = 3 - 2 * radius;
	while (x < y) {
		plot_circle_points(xc, yc, x, y, c);
		if (p < 0) p = p + 4 * x + 6;
		else {
			p = p + 4 * (x - y) + 10;
			y -= 1;
		}
		x += 1;
	}
	if (x == y)plot_circle_points(xc, yc, x, y, c);

}

/*xuehua( )函数用来绘制雪花，参数x，y代表雪花中心位置，mycolor表示颜色，k表示变比系数，实现缩放*/
void xuehua(int x,int y,int mycolor,double k)
{
	
	//当k=1，初始中心坐标位置在200，200
	dda_line(225 * k + x, 243 * k + y, 215 * k + x, 271 * k + y, mycolor);
	dda_line(225 * k + x, 243 * k + y, 253 * k + x, 243 * k + y, mycolor);
	dda_line(200 * k + x, 200 * k + y, 235 * k + x, 260 * k + y, mycolor);

	dda_line(200 * k + x, 200 * k + y, 270 * k + x, 200 * k + y, mycolor);
	dda_line(250 * k + x, 200 * k + y, 270 * k + x, 220 * k + y, mycolor);
	dda_line(250 * k + x, 200 * k + y, 270 * k + x, 180 * k + y, mycolor);

	dda_line(200 * k + x, 200 * k + y, 130 * k + x, 200 * k + y, mycolor);
	dda_line(150 * k + x, 200 * k + y, 130 * k + x, 220 * k + y, mycolor);
	dda_line(150 * k + x, 200 * k + y, 130 * k + x, 180 * k + y, mycolor);

	dda_line(200 * k + x, 200 * k + y, 235 * k + x, 140 * k + y, mycolor);
	dda_line(225 * k + x, 157 * k + y, 215 * k + x, 129 * k + y, mycolor);
	dda_line(225 * k + x, 157 * k + y, 248 * k + x, 157 * k + y, mycolor);

	dda_line(200 * k + x, 200 * k + y, 165 * k + x, 260 * k + y, mycolor);
	dda_line(175 * k + x, 243 * k + y, 147 * k + x, 243 * k + y, mycolor);
	dda_line(175 * k + x, 243 * k + y, 185 * k + x, 271 * k + y, mycolor);

	dda_line(200 * k + x, 200 * k + y, 165 * k + x, 140 * k + y, mycolor);
	dda_line(175 * k + x, 157 * k + y, 140 * k + x, 157 * k + y, mycolor);
	dda_line(175 * k + x, 157 * k + y, 185 * k + x, 129 * k + y, mycolor);
}



void seed_filling4(int x, int y, int fill_color, int boundary_color)
{
	int c;
	c = getpixel(x, y);
	if ((c == boundary_color))
	{
		putpixel(x, y, fill_color);
		Sleep(1);
		seed_filling4(x + 1, y, fill_color, boundary_color);
		seed_filling4(x - 1, y, fill_color, boundary_color);
		seed_filling4(x, y + 1, fill_color, boundary_color);
		seed_filling4(x, y - 1, fill_color, boundary_color);
	}
}
/*tree()函数用来绘制树，参数x，y代表树顶中心位置，mycolor表示颜色，k表示变比系数，实现缩放*/
void tree(int x,int y,int  mycolor,double k) 
{
	//第一层
	dda_line(250 * k + x, 100 * k + y,300 * k + x, 150 * k + y, mycolor);
	dda_line(250 * k + x, 100 * k + y, 200 * k + x, 150 * k + y, mycolor);
	dda_line(200 * k + x, 150 * k + y, 300 * k + x, 150 * k + y, mycolor);
	
	
	//第二层
	dda_line(250 * k + x, 150 * k + y, 175 * k + x, 200 * k + y, mycolor);
	dda_line(250 * k + x, 150 * k + y, 325 * k + x, 200 * k + y, mycolor);
	dda_line(175 * k + x, 200 * k + y, 325 * k + x, 200 * k + y, mycolor);
	//第三层
	dda_line(250 * k + x, 200 * k + y, 150 * k + x, 250 * k + y, mycolor);
	dda_line(250 * k + x, 200 * k + y, 350 * k + x, 250 * k + y, mycolor);
	dda_line(150 * k + x, 250 * k + y, 350 * k + x, 250 * k + y, mycolor);
	//根
	dda_line(225 * k + x, 250 * k + y, 225 * k + x, 300 * k + y, mycolor);
	dda_line(225 * k + x, 300 * k + y, 275 * k + x, 300 * k + y, mycolor);
	dda_line(275 * k + x, 300 * k + y, 275 * k + x, 250 * k + y, mycolor);

}

/*雪人函数，绘制雪人，x，y表示平移偏移量*/
void sonwman(int x,int y) {
	setfillcolor(WHITE);
	Bresenham_circle(250 + x, 250 + y, 70,WHITE);
	Bresenham_circle(250 + x, 410 + y, 100,WHITE);
	floodfill(250 + x, 250 + y,WHITE);
	floodfill(250 + x, 410 + y, WHITE);
	floodfill(250 + x, 319 + y, WHITE);
	//眼睛
	setfillcolor(RED);
	Bresenham_circle(225 + x, 225 + y, 8, RED);
	floodfill(225 + x,225 + y,RED);
	//seed_filling4(255, 260, YELLOW, RED);
	setfillcolor(RED);
	Bresenham_circle(275 + x, 225 + y, 8, RED);
	floodfill(275 + x, 225 + y, RED);
	//fillcircle(225, 225, 8);
	//fillcircle(275, 225, 8);
	setfillcolor(RED);
	fillrectangle(225 + x, 275 + y, 275 + x, 285 + y);

	/*纽扣1*/
	dda_line(240 + x, 350 + y, 260 + x, 350 + y, RED);
	dda_line(240 + x, 350 + y, 240 + x, 360 + y, RED);
	dda_line(240 + x, 360 + y, 260 + x, 360 + y, RED);
	dda_line(260 + x, 360 + y, 260 + x, 350 + y, RED);
	floodfill(241 + x, 351 + y, RED);

	/*纽扣2*/
	dda_line(240 + x, 370 + y, 260 + x, 370 + y, RED);
	dda_line(240 + x, 370 + y, 240 + x, 380 + y, RED);
	dda_line(240 + x, 380 + y, 260 + x, 380 + y, RED);
	dda_line(260 + x, 380 + y, 260 + x, 370 + y, RED);
	floodfill(241 + x, 371 + y, RED);

	/*纽扣3*/
	dda_line(240 + x, 390 + y, 260 + x, 390 + y, RED);
	dda_line(240 + x, 390 + y, 240 + x, 400 + y, RED);
	dda_line(240 + x, 400 + y, 260 + x, 400 + y, RED);
	dda_line(260 + x, 400 + y, 260 + x, 390 + y, RED);
	floodfill(241 + x, 391 + y, RED);

	/*右手*/
	dda_line(337 + x, 360 + y, 424 + x, 310 + y, YELLOW);
	dda_line(424 + x, 310 + y, 425 + x, 285 + y, YELLOW);
	dda_line(424 + x, 310 + y, 440 + x, 325 + y, YELLOW);
	
	/*左手*/
	dda_line(163 + x, 360 + y, 76 + x, 310 + y, YELLOW);
	dda_line(76 + x, 310 + y, 75 + x, 285 + y, YELLOW);
	dda_line(76 + x, 310 + y, 60 + x, 325 + y, YELLOW);

}
void snow_snow() {
	xuehua(20, 20, WHITE, 0.5);
	xuehua(190, 180, WHITE, 0.3);
	xuehua(260, 230, WHITE, 0.3);
	xuehua(400, 320, WHITE, 0.3);
	xuehua(680, 120, WHITE, 0.3);
	xuehua(720, 80, WHITE, 0.1);
	xuehua(920, 200, WHITE, 0.1);
	xuehua(350, 420, WHITE, 0.1);
	xuehua(270, 390, WHITE, 0.1);
	xuehua(600, 60, WHITE, 0.3);
	xuehua(680, 390, WHITE, 0.3);
	xuehua(700, 120, WHITE, 0.7);
	xuehua(320, -20, WHITE, 1);
	xuehua(600, 220, WHITE, 0.4);
	xuehua(-70, 120, WHITE, 1);
	xuehua(282, 90, WHITE, 0.4);
	xuehua(326, 180, WHITE, 0.4);
}
void  tree_tree() {
	tree(60, 360, GREEN, 1);
	tree(-60, 360, GREEN, 0.8);
	tree(560, 440, GREEN, 1);
	tree(20, 660, GREEN, 0.3);
	tree(60, 620, GREEN, 0.4);
	tree(130, 600, GREEN, 0.5);
}


