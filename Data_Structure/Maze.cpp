#include <iostream>
#include <string>
#include "LinkedStack.h"

using namespace std;

#define row 4
#define column 8
int Maze[row + 2][column + 2] = {
	1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,1,0,1,0,0,1,
	1,0,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,1,1,
	1,1,1,1,1,1,1,0,1,1,
	1,1,1,1,1,1,1,1,1,1

};
int Mark[row + 2][column + 2];
struct coordinate{
	int x;
	int y;
	int dir;
};
struct chunk{
	int x, y;
	int dir;
};
void findout();
//void main(){
//	findout();
//	
//	system("pause");
//}

void findout(){
	coordinate move[8] = { -1, -1, 0,    -1, 0, 1,    -1, 1, 2,    0, -1, 3,    0, 1, 4,    1, -1, 5,   1, 0, 6,   1, 1, 7 };
	LinkedStack<chunk> *way2out = new LinkedStack<chunk>(21);
	chunk tmp;
	//初始化，，，忘记了啊！！
	Mark[1][1] = 1;
	int x_now;
	int y_now;
	int x = 1;
	int y = 1;
	
	int i = 0;
	tmp.x = 1;
	tmp.y = 1;
	tmp.dir = 0;
	way2out->Push(tmp);
	while (way2out->IsEmpty() == false){
		//出栈
		way2out->Pop(tmp);
		//这里的tmp，即chunk结构体的dir必须为int，不然不方便标记不同方向了。因为数字方便得多
		x = tmp.x; y = tmp.y; i = tmp.dir;
		while (i < 8){

			x_now = x + move[i].x;
			y_now = y + move[i].y;

			

			if (Maze[x_now][y_now] == 0 && Mark[x_now][y_now] == 0){
				if (x_now == row && y_now == column){
					cout << "out the maze" << endl;
					return;
				}
				Mark[x_now][y_now] = 1;
				tmp.x = x; tmp.y = y; tmp.dir = move[i].dir;
				way2out->Push(tmp);
				//cout << "coordinate is " << x << "," << y << "dir is " << tmp.dir << endl; 
				x = x_now; y = y_now; i = 0;
			}
			else i++;
		}

	}
	cout << "no path in maze" << endl;

}