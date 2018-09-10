#pragma once
class Object
{
public:
	Object();
	~Object();

	virtual void Init() = 0;
};

