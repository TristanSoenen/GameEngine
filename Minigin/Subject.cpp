#include "Subject.h"
#include "Observer.h"

void dae::Subject::AddObserver(dae::Observer* observer)
{
	m_Observers.emplace_back(observer);
}

void dae::Subject::RemoveObserver(dae::Observer* observer)
{
	if (!m_Observers.empty())
	{
		m_Observers.erase(std::remove(m_Observers.begin(), m_Observers.end(), observer), m_Observers.end());
	}
}

void dae::Subject::NotifyObservers()
{
	//for (dae::Observer* observer : m_Observers)
	//{
	//	//observer->Notify(this, );
	//}
}