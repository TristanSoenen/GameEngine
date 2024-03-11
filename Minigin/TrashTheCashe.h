#pragma once
#include <vector>

namespace dae
{
	struct Transform
	{
		float matrix[16]{
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		};

	};

	class gameobject3D
	{
	public:
		Transform local;
		int id;
	};


	class gameobject3DAlt
	{
	public:
		Transform* local;
		int id;
	};

	class TrashTheCashe
	{
	public:
		TrashTheCashe() = default;
		~TrashTheCashe();
		void TrashTheCasheEx1(int repeatAmount);
		void TrashTheCasheEx2(int repeatAmount);
		void TrashTheCasheEx2Alt(int repeatAmount);
		std::vector<float> GetVectorEx1() { return m_StepResultsEx1; }
		std::vector<float> GetVectorEx2() { return m_StepResultsEx2; }
		std::vector<float> GetVectorEx2Alt() { return m_StepResultsEx2Alt; }
		bool CanShowGraph1() { return m_ShowGraph1; }
		bool CanShowGraph2() { return m_ShowGraph2; }
		bool CanShowGraph3() { return m_ShowGraph3; }

	private:
		std::vector<float> m_StepResultsEx1{ 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
		std::vector<float> m_StepResultsEx2{ 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
		std::vector<float> m_StepResultsEx2Alt{ 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };

		bool m_ShowGraph1{ false };
		bool m_ShowGraph2{ false };
		bool m_ShowGraph3{ false };
	};
}


