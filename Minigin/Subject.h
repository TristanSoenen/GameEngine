#pragma once
#include "Structs.h"
#include <vector>

namespace dae
{
	class GameObject;
	class Observer;
	class Subject
	{
	public:
		void AddObserver(Observer* observer)
		{
			m_Observers.emplace_back(observer);
		}

		void RemoveObserver(Observer* observer)
		{
			if (!m_Observers.empty())
			{
				m_Observers.erase(std::remove(m_Observers.begin(), m_Observers.end(), observer));
			}
		}
	protected:
		virtual void NotifyObservers(Event event) = 0;

	private:
		std::vector<Observer*> m_Observers;
	};
}