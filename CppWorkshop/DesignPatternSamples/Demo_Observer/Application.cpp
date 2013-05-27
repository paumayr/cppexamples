#include "Application.hpp"

#include <iostream>
#include "FindDentsAlgorithm.hpp"

void Application::findAllDents()
{
	FindDentsAlgorithm dentsFinder1;
	FindDentsAlgorithm dentsFinder2;

	dentsFinder1.Register(this);
	dentsFinder2.Register(this);

	dentsFinder1.CountDents();
	dentsFinder2.CountDents();

	// we do not have to deregister, as the destructor
	// of the algorithms class will automatically destruct the members.
}

void Application::OnProgress(ProgressObserverSubject& source, int done, int total)
{
	std::cout << "progress: " << done << " of " << total << " done" << std::endl;
}