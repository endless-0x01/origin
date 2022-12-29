#pragma once 
#ifdef LEAVERLIBRARYDYNAMIC_EXPORTS
#define LEAVERLIBRARY_API __declspec(dllexport)
#else
#define LEAVERLIBRARY_API __declspec(dllimport)
#endif // LEAVERLIBRARYDYNAMIC_EXPORT

#include <string>

namespace LeaverDynamic
{
	class Leaver
	{
	public:
		LEAVERLIBRARY_API std::string leave(std::string name);
	};

}