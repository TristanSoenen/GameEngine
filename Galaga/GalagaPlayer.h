#pragma once
#include <Component.h>
#include "Observer.h"

namespace dae
{
	class TransformComponent;
	class GalagaPlayer final: public Component, Observer
	{
	public:
		GalagaPlayer(GameObject* pOwner);
		~GalagaPlayer() = default;
		void Notify(Event event) override;
		void Update() override;
	private:
		bool m_FreezePosition;
		std::shared_ptr<TransformComponent> m_TranformComp;
	};
}