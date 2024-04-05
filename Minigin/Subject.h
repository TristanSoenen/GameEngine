#ifndef SUBJECT_H // Check if SUBJECT_H is not defined
#define SUBJECT_H // If not, define SUBJECT_H

#pragma once
#include "Structs.h"
#include <vector>

namespace dae
{
	class Observer;
	class Subject
	{
	public:
		//Subject() = default;
		virtual ~Subject() = default;
		void AddObserver(Observer* observer);
		void RemoveObserver(Observer* observer);

	protected:
		void NotifyObservers();

	private:
		std::vector<Observer*> m_Observers;
	};
}

#endif // End of include guard