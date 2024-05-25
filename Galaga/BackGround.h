#pragma once
#include <Component.h>

namespace dae
{
	class BackGround : public Component
	{
	public:
		BackGround(GameObject* pOwner, float speed);
		~BackGround() = default;
		void Update() override;
	private:
		bool m_ResetPosition;
		float m_Speed;
	};
}