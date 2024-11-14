#pragma once

template<typename T>
class CSingleton
{
private:
	CSingleton() {}

public:
	virtual ~CSingleton() {}

public:
	static inline T* Instance()
	{
		static T instance;
		return &instance;
	}
};

