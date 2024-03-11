#include "TrashTheCashe.h"
#include <chrono>
#include <iostream>

dae::TrashTheCashe::~TrashTheCashe()
{

}

void dae::TrashTheCashe::TrashTheCasheEx1(int repeatAmount)
{
	for (int index{ 0 }; index < 11; index++)
	{
		m_StepResultsEx1[index] = 0.0f;
	}

	for (int j = 0; j <= repeatAmount; j++)
	{
		const int size{ 1'000'000 };
		int* arr{ new int[size] {} };

		int arrIndex = 0;
		for (int stepsize = 1; stepsize <= 1024; stepsize *= 2)
		{

			auto start = std::chrono::high_resolution_clock::now();
			for (int i = 0; i < size; i += stepsize)
			{
				arr[i] *= 2;
			}

			auto end = std::chrono::high_resolution_clock::now();
			auto elapsedTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
			m_StepResultsEx1[arrIndex] += float(elapsedTime);
			arrIndex++;
		}

		delete[] arr;
	}

	for (int index{ 0 }; index < 11; index++)
	{
		m_StepResultsEx1[index] = float(m_StepResultsEx1[index] / repeatAmount);
	}

	m_ShowGraph1 = true;
}

void dae::TrashTheCashe::TrashTheCasheEx2(int repeatAmount)
{
	for (int index{ 0 }; index < 11; index++)
	{
		m_StepResultsEx2[index] = 0.0f;
	}

	for (int j = 0; j <= repeatAmount; j++)
	{
		const int size{ 1'000'000 };
		dae::gameobject3D* object{ new dae::gameobject3D[size]{} };

		int arrIndex = 0;
		for (int stepsize = 1; stepsize <= 1024; stepsize *= 2)
		{

			auto start = std::chrono::high_resolution_clock::now();
			for (int i = 0; i < size; i += stepsize)
			{
				object[i].id *= 2;
			}

			auto end = std::chrono::high_resolution_clock::now();
			auto elapsedTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
			m_StepResultsEx2[arrIndex] += float(elapsedTime);
			arrIndex++;
		}

		delete[] object;
	}

	for (int index{ 0 }; index < 11; index++)
	{
		m_StepResultsEx2[index] = float(m_StepResultsEx2[index] / repeatAmount);
	}

	m_ShowGraph2 = true;
}

void dae::TrashTheCashe::TrashTheCasheEx2Alt(int repeatAmount)
{
	for (int index{ 0 }; index < 11; index++)
	{
		m_StepResultsEx2Alt[index] = 0.0f;
	}

	for (int j = 0; j <= repeatAmount; j++)
	{
		const int size{ 1'000'000 };
		dae::gameobject3DAlt* objectAlt{ new dae::gameobject3DAlt[size]{} };

		int arrIndex = 0;
		for (int stepsize = 1; stepsize <= 1024; stepsize *= 2)
		{

			auto start = std::chrono::high_resolution_clock::now();
			for (int i = 0; i < size; i += stepsize)
			{
				objectAlt[i].id *= 2;
			}

			auto end = std::chrono::high_resolution_clock::now();
			auto elapsedTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
			m_StepResultsEx2Alt[arrIndex] += float(elapsedTime);
			arrIndex++;
		}

		delete[] objectAlt;
	}

	for (int index{ 0 }; index < 11; index++)
	{
		m_StepResultsEx2Alt[index] = float(m_StepResultsEx2Alt[index] / repeatAmount);
	}

	m_ShowGraph3 = true;
}