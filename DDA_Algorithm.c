#include <stdio.h>
#include <Windows.h>
#include <math.h>

// 점을 출력하는 함수
// Function to draw a point
void Draw_Point(int x, int y);
// DDA 알고리즘 함수 
// Function of DDA Algorithm
void DDA(int x1, int y1, int x2, int y2);

int main()
{
	DDA(0, 0, 10, 5);
	
	return 0;
}

void Draw_Point(int x, int y)
{
	COORD Pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	
	printf("*");	
} 

void DDA(int x1, int y1, int x2, int y2)
{
	// x1, y1 - 처음 좌표
	// x2, y2 - 마지막 좌표 
	
	// 한번 이동할 때 실수 값이 나올 경우 반올림을 통해 그리는 방식이라
	// 일부 변수는 실수형 float 형태를 취한다. 
	// Because when the position move one time if the value is Real number
	// the Algorithm have to round that value.
	// So, some value shapes are float.
	
	// x, y 축 변화량
	// the amount of change as x, y position
	int dx = x2 - x1;
	int dy = y2 - y1;
	
	// 선분을 잇기 위해 필요한 점의 개수
	// the number of points to draw line
	float PointCnt;
	
	// 기준이 될 축을 잘못 잡으면 선분의 연결이 중간에 끊길 수 있다. 
	// if the principle of axis is wrong, the connection of line can be cut.
	if (fabs(dx) > fabs(dy))
		PointCnt = fabs(dx);
	else
		PointCnt = fabs(dy);
	
	// 시작점 좌표 재정의 
	// redelare position value 
	float x = x1;
	float y = y1;
	
	// 한번 이동할 때 변하는 정도 
	// the amount of change when the position move one time
	float IncreaseX = dx / PointCnt;
	float IncreaseY = dy / PointCnt;
	
	int i;
	// 선분 그리는 부분 
	// the part of drawing line
	for (i = 0; i < PointCnt; i++)
	{
		Draw_Point(round(x), round(y));
		
		x += IncreaseX;
		y += IncreaseY;
	}	 
}
