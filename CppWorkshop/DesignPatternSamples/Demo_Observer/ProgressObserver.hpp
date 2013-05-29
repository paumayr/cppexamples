#pragma once

#include <vector>

// forward declaration of the progress observer subject.
class ProgressObserverSubject;

class ProgressObserver
{
public:
	// progress callback function called by an algorithm e.g.
	virtual void OnProgress(ProgressObserverSubject& source, int done, int total) = 0;
};


// base class for all classes that support progress observers.
class ProgressObserverSubject
{
	// type of the container holding the observers.
	typedef std::vector<ProgressObserver*> ProgressObserverContainer;
	
	// container holding observers.
	ProgressObserverContainer observers;
public:

	// registers an observer
	void Register(ProgressObserver* observer);

	// deregisters the observer
	void Deregister(ProgressObserver* observer);

protected:
	void NotifyListeners(int done, int total);
};