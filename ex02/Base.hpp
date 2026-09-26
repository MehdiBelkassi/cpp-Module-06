#pragma once

class Base
{
	public:
		Base();
		Base(const Base &obj);
		Base& operator=(const Base &obj);
		virtual ~Base();
};
