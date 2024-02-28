#pragma once

namespace dae
{
	class Component
	{
	public:
		Component() = default;
		virtual ~Component() = default;
		Component(const Component& other) = delete;
		Component(Component&& other) = delete;
		Component& operator=(const Component& other) = delete;
		Component& operator=(Component&& other) = delete;

		virtual void Fixed_Update() {};
		virtual void Update() {};
		virtual void Render() {};

	//protected:
		//GameObject* GetOwner() const { return m_pOwner; }
	private:
		//GameObject* m_pOwner;
	};
}


