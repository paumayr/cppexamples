#include "ProgressObserver.hpp"

class Application : public ProgressObserver
{
public:

	void findAllDents();

	// progress callback function called by an algorithm e.g.
	virtual void OnProgress(ProgressObserverSubject& source, int done, int total);
};