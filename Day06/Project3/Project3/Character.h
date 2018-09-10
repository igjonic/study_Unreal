#pragma once
#include <string>
#include "Object.h"

class Character : public Object
{
public:
	Character();
	~Character();

	virtual void Tick();
	virtual void Draw();

	virtual void Init() override {} 

	//accessor, Á¢±ÙÀÚ.
	void SetName(std::string newName);
	std::string GetName();
protected:
	void Move();
	std::string name;
};

//Character c;
//c.name ="aaaa";