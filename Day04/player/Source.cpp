#include"Engine.h"

int main()
{
	//Engine e;
	//e.Run();
	Engine* e = new Engine();
	e->Run();
	delete e;
	return 0;
}