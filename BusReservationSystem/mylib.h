#ifndef MYLIB_H
#define MYLIB_H

#include <iostream>
#include <list>
#include <string>

using namespace std;

enum return_state
{
	SUCCESS,
	FAIL_NOT_FOUND,
	FAIL_FULL,
	FAIL_NOT_BOOKED,
	FAIL_OVERLAP,
	FAIL_NO_BUS
}; // says whether the method succeeded


// prints the effect depending on return_state value
inline void rstate(string s, return_state rs)
{
	switch (rs)
	{
	case SUCCESS:
	default:
		cout << "Success!" << endl;
		break;

	case FAIL_NOT_FOUND:
		cout << "Failed, " << s << " with given ID not found." << endl;
		break;

	case FAIL_FULL:
		cout << "Failed, " << s << " is full." << endl;
		break;

	case FAIL_NOT_BOOKED:
		cout << "Failed, " << s << " was not booked." << endl;
		break;

	case FAIL_OVERLAP:
		cout << "Failed, " << s << " overlaps with another one." << endl;
		break;

	case FAIL_NO_BUS:
		cout << "Failed, " << s << " has no bus assigned." << endl;
		break;
	}
}


// returns pointer to an object from source list with given id
template <typename T>
typename list<T>::iterator findID(list<T>& source, int id)
{
	typename list<T>::iterator it;
	bool flag = 0;

	for (it = source.begin(); flag || it != source.end(); ++it)
	{
		if ((*it).getID() == id)
		{
			break;
		}
	}
	return it;
}

#endif	// !MYLIB_H
