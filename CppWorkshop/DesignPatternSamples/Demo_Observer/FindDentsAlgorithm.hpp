
#include <memory>
#include <vector>

#include "ProgressObserver.hpp"

/*
FindDentsAlgorithm is the Subject which takes observers.
while doing it's processing it notifies the observers of progress.
*/
class FindDentsAlgorithm : public ProgressObserverSubject
{
public:

	int CountDents();
};