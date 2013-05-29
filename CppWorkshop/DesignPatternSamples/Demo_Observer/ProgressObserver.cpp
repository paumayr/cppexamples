#include "ProgressObserver.hpp"

#include <algorithm>

void ProgressObserverSubject::Register(ProgressObserver* observer)
{
	observers.push_back(observer);
}

void ProgressObserverSubject::Deregister(ProgressObserver* observer)
{
	// see c++ erase / remove paradigm
	observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void ProgressObserverSubject::NotifyListeners(int done, int total)
{
	for(int i = 0; i < this->observers.size(); i++)
	{
		this->observers[i]->OnProgress(*this, done, total);
	}
}