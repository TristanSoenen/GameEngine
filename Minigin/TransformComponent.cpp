#include "TransformComponent.h"

dae::TransformComponent::TransformComponent(dae::GameObject* pOwner)
	:dae::Component{ pOwner }
	,m_IsDirty{false}
	,m_position{}
	,m_WorldPosition{}
{

}

void dae::TransformComponent::SetPosition(float x, float y, float z)
{
	m_position.x = x;
	m_position.y = y;
	m_position.z = z;
}

const glm::vec3& dae::TransformComponent::GetWorldPosition() const
{
	return m_WorldPosition;
}

void dae::TransformComponent::UpdateWorldPosition()
{
	if (m_IsDirty == true)
	{

	}
	m_IsDirty = false;
}

void dae::TransformComponent::SetDirtyFlag()
{
	m_IsDirty = true;
}