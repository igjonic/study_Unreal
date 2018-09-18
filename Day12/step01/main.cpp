#include<iostream>
#include<stack>
#include<conio.h>
#include<queue>
using namespace std;
#define MAX 5

int Maze[MAX][MAX] = {
	{0,0,1,1,0},
	{1,0,0,0,0},
	{1,0,1,0,0},
	{1,0,1,1,1},
	{1,0,0,0,0}
};
#define PATH 0
#define WALL 1
#define VISTED 2
#define BACKTRACE 3
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
class Position
{
public:
	Position(int NewX = 0, int NewY = 0)
	{
		x = NewX;
		y = NewY;
	}
	int x;
	int y;
};
Position Dir[4];
bool CanMove(Position& Current)
{
	Position Next;
	//up
	Next.x = Current.x;
	Next.y = Current.y-1;
	if (Next.y >-1)
	{
		if (Maze[Next.y][Next.x] == PATH)
		{
			Current = Next;
			return true;
		}
	}
	//Right
	Next.x = Current.x+1;
	Next.y = Current.y;
	if (Next.x < MAX)
	{
		if (Maze[Next.y][Next.x] == PATH)
		{
			Current = Next;
			return true;
		}
	}
	//Dwon
	Next.x = Current.x;
	Next.y = Current.y + 1;
	if (Next.y < MAX)
	{
		if (Maze[Next.y][Next.x] == PATH)
		{
			Current = Next;
			return true;
		}
	}
	//Left
	Next.x = Current.x + 1;
	Next.y = Current.y;
	if (Next.x >-1)
	{
		if (Maze[Next.y][Next.x] == PATH)
		{
			Current = Next;
			return true;
		}
	}
	return false;
};
void PrintMap()
{
	for (int y = 0; y < MAX; ++y)
	{
		for (int x = 0; x < MAX; ++x)
		{
			cout << Maze[y][x]<<" ";
		}
		cout << endl;
	}
};

bool CanMove2(Position& Current)
{
	Position Next;
	for (int i=UP; i <= LEFT; ++i)
	{
		Next.x = Current.x + Dir[i].x;
		Next.y = Current.y + Dir[i].y;
		if (Next.x<0 ||
			Next.y<0 ||
			Next.x>MAX||
			Next.y>MAX)
		{
			continue;
		}
		if (Maze[Next.y][Next.x] == PATH)
		{
			Current = Next;
			return true;
		}
	}
	return false;
}
bool RCanMove(Position Next)
{
	if (Next.x<0  || Next.y>MAX||
		Next.y<0 ||Next.x>MAX )
	{
		return false;
	}
	else if (Maze[Next.y][Next.x] != PATH)
	{
		return false;
	}
	else if (Next.x == (MAX - 1) && Next.y == (MAX - 1))
	{
		Maze[Next.y][Next.x] = VISTED;
		return true;
	}
	else
	{
		Maze[Next.y][Next.x] = VISTED;
		if (RCanMove(Position(Next.x, Next.y - 1)) ||
			RCanMove(Position(Next.x + 1, Next.y)) ||
			RCanMove(Position(Next.x, Next.y + 1)) ||
			RCanMove(Position(Next.x - 1, Next.y)))
		{
			return true;
		}
		Maze[Next.y][Next.x] = BACKTRACE;
		return false;
	}
}
int stack()
{
	//UP
	Dir[UP].x = 0;
	Dir[UP].y = -1;
	//Right
	Dir[RIGHT].x = 1;
	Dir[RIGHT].y = 0;
	//Dwon
	Dir[DOWN].x = 0;
	Dir[DOWN].y = 1;
	//Light
	Dir[LEFT].x = -1;
	Dir[LEFT].y = 0;

	Position Current;
	Current.x = 0;
	Current.y = 0;
	RCanMove(Current);
	//stack<Position> EcsapeMap;

	//while (true)
	//{
	//	Maze[Current.y][Current.x] = VISTED;
	//	if (RCanMove(Current))
	//	{
	//		//¿Ãµø∞°¥…
	//		EcsapeMap.push(Current);

	//	}
	//	else
	//	{
	//		if (!EcsapeMap.empty())
	//		{
	//			Position Temp = EcsapeMap.top();
	//			EcsapeMap.pop();
	//			Maze[Current.y][Current.x] = BACKTRACE;
	//			Current = Temp;
	//		}
	//		else
	//		{
	//			cout << "≈ª√‚ ∫“∞°" << endl;
	//			break;
	//		}
	//	}
	//	if (Current.x == (MAX - 1) && Current.y == (MAX - 1))
	//	{
	//		Maze[Current.y][Current.x] = VISTED;
	//		cout << "≈ª√‚" << endl;
	//		break;
	//	}
	//}

	//while (!EcsapeMap.empty())
	//{
	//	Position Temp = EcsapeMap.top();
	//	cout << "(" << Temp.x << "," << Temp.y << ")" << endl;
	//	EcsapeMap.pop();
	//}
	PrintMap();
	return 0;
}

void InitDir()
{
	//UP
	Dir[UP].x = 0;
	Dir[UP].y = -1;
	//Right
	Dir[RIGHT].x = 1;
	Dir[RIGHT].y = 0;
	//Dwon
	Dir[DOWN].x = 0;
	Dir[DOWN].y = 1;
	//Light
	Dir[LEFT].x = -1;
	Dir[LEFT].y = 0;
}
bool CanMoveQ(Position& Current, Position& NewPosition, int dir)
{
	Position Next;
	Next.x = Current.x + Dir[dir].x;
	Next.y = Current.y + Dir[dir].y;
	if (Next.x<0 ||
		Next.y<0 ||
		Next.x>MAX ||
		Next.y>MAX)
	{
		return false;
	}
	if (Maze[Next.y][Next.x] == PATH)
	{
		NewPosition = Next;
		return true;
	}
	return false;
}
void Trace()
{
	Position Current(MAX - 1, MAX - 1);
	std::stack<Position> Trace;
	int Level = Maze[Current.y][Current.x];
	Trace.push(Current);
	bool found;
	while (Current.y != 0 || Current.x != 0)
	{
		int Level = Maze[Current.y][Current.x];
		for (int dir = UP; dir <= LEFT; ++dir)
		{
			Position Next(Current.y + Dir[dir].y, Current.x + Dir[dir].x);
			if (Next.x<0 ||
				Next.y<0 ||
				Next.x>=MAX ||
				Next.y>=MAX)
			{
				continue;
			}
				if (Maze[Next.y][Next.x] == Level - 1)
				{
					Trace.push(Next);
					Current = Next;
					break;
				}
		}
	}
}
int main()
{
	queue<Position> Q;
	InitDir();
	Position Current;
	Q.push(Current);
	Maze[Current.y][Current.x] = 10;
	bool found = false;
	while (!Q.empty())
	{
		Current = Q.front();
		Q.pop();
		int Level = Maze[Current.y][Current.x];
		for (int dir = UP; dir < LEFT; ++dir)
		{
			Position NewPosition;
			if (CanMoveQ(Current,NewPosition,dir))
			{
				Maze[NewPosition.y][NewPosition.x] = Level + 1;
				if (NewPosition.x == (MAX - 1) && NewPosition.y == (MAX - 1))
				{
					cout << "≈ª√‚" << endl;
					found = true;
					break;
				}
				Q.push(NewPosition);
			}
		}
	}
	if (!found)
	{
		cout << "≈ª√‚ ∫“∞°" << endl;
	}
	PrintMap();

	return 0;
}