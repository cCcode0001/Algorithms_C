#include <stdio.h>
#include <Windows.h>
#include <math.h>

// ���� ����ϴ� �Լ�
// Function to draw a point
void Draw_Point(int x, int y);
// DDA �˰��� �Լ� 
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
	// x1, y1 - ó�� ��ǥ
	// x2, y2 - ������ ��ǥ 
	
	// �ѹ� �̵��� �� �Ǽ� ���� ���� ��� �ݿø��� ���� �׸��� ����̶�
	// �Ϻ� ������ �Ǽ��� float ���¸� ���Ѵ�. 
	// Because when the position move one time if the value is Real number
	// the Algorithm have to round that value.
	// So, some value shapes are float.
	
	// x, y �� ��ȭ��
	// the amount of change as x, y position
	int dx = x2 - x1;
	int dy = y2 - y1;
	
	// ������ �ձ� ���� �ʿ��� ���� ����
	// the number of points to draw line
	float PointCnt;
	
	// ������ �� ���� �߸� ������ ������ ������ �߰��� ���� �� �ִ�. 
	// if the principle of axis is wrong, the connection of line can be cut.
	if (fabs(dx) > fabs(dy))
		PointCnt = fabs(dx);
	else
		PointCnt = fabs(dy);
	
	// ������ ��ǥ ������ 
	// redelare position value 
	float x = x1;
	float y = y1;
	
	// �ѹ� �̵��� �� ���ϴ� ���� 
	// the amount of change when the position move one time
	float IncreaseX = dx / PointCnt;
	float IncreaseY = dy / PointCnt;
	
	int i;
	// ���� �׸��� �κ� 
	// the part of drawing line
	for (i = 0; i < PointCnt; i++)
	{
		Draw_Point(round(x), round(y));
		
		x += IncreaseX;
		y += IncreaseY;
	}	 
}
