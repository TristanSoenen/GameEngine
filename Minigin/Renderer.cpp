#include <stdexcept>
#include "Renderer.h"
#include "SceneManager.h"
#include "Texture2D.h"
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_sdl2.h"
#include "imgui_plot.h"
#include "chrono"
#include "iostream"
#include <vector>
#include "glm/glm.hpp"

int GetOpenGLDriverIndex()
{
	auto openglIndex = -1;
	const auto driverCount = SDL_GetNumRenderDrivers();
	for (auto i = 0; i < driverCount; i++)
	{
		SDL_RendererInfo info;
		if (!SDL_GetRenderDriverInfo(i, &info))
			if (!strcmp(info.name, "opengl"))
				openglIndex = i;
	}
	return openglIndex;
}

void dae::Renderer::Init(SDL_Window* window)
{
	m_window = window;
	m_renderer = SDL_CreateRenderer(window, GetOpenGLDriverIndex(), SDL_RENDERER_ACCELERATED);
	if (m_renderer == nullptr)
	{
		throw std::runtime_error(std::string("SDL_CreateRenderer Error: ") + SDL_GetError());
	}

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui_ImplSDL2_InitForOpenGL(window, SDL_GL_GetCurrentContext());
	ImGui_ImplOpenGL3_Init();

	//m_TrashTheCashe = new dae::TrashTheCashe();
}

void dae::Renderer::Render() const
{
	const auto& color = GetBackgroundColor();
	SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
	SDL_RenderClear(m_renderer);

	SceneManager::GetInstance().Render();
	
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();
	//ImGui::ShowDemoWindow();

	//ImGui::Begin("exercise1");
	//ImGui::InputInt("# samples", m_Amount);
	//
	//if (ImGui::Button("Trash The Cashe"))
	//{
	//	if (*m_Amount > 0)
	//	{
	//		m_TrashTheCashe->TrashTheCasheEx1(*m_Amount);
	//	}
	//}

	//if (m_TrashTheCashe->CanShowGraph1() == true)
	//{
	//	std::vector<float> temp = m_TrashTheCashe->GetVectorEx1();
	//	float arr[11]{};
	//	for (int index{ 0 }; index < 11; index++)
	//	{
	//		arr[index] = temp[index];
	//	}
	//	ImGui::PlotLines("", arr, 11, 0, 0, FLT_MAX, FLT_MAX, ImVec2(150.0f, 150.0f));
	//}

	//ImGui::End();


	////Exercise 2
	//ImGui::Begin("exercise2");
	//ImGui::InputInt("# samples", m_Amount2);
	//if (ImGui::Button("Trash The Cashe with GameObject3D"))
	//{
	//	if (*m_Amount2 > 0)
	//	{
	//		m_TrashTheCashe->TrashTheCasheEx2(*m_Amount2);
	//	}
	//}

	//if (m_TrashTheCashe->CanShowGraph2() == true)
	//{
	//	std::vector<float> temp2 = m_TrashTheCashe->GetVectorEx2();
	//	float arr2[11]{};
	//	for (int index{ 0 }; index < 11; index++)
	//	{
	//		arr2[index] = temp2[index];
	//	}
	//	ImGui::PlotLines("", arr2, 11, 0, 0, FLT_MAX, FLT_MAX, ImVec2(150.0f, 150.0f));
	//}

	//if (ImGui::Button("Trash The Cashe with GameObject3DAlt"))
	//{
	//	if (*m_Amount2 > 0)
	//	{
	//		m_TrashTheCashe->TrashTheCasheEx2Alt(*m_Amount2);
	//	}
	//}

	//if (m_TrashTheCashe->CanShowGraph3() == true)
	//{
	//	std::vector<float> temp3 = m_TrashTheCashe->GetVectorEx2Alt();
	//	float arr3[11]{};
	//	for (int index{ 0 }; index < 11; index++)
	//	{
	//		arr3[index] = temp3[index];
	//	}
	//	ImGui::PlotLines("", arr3, 11, 0, 0, FLT_MAX, FLT_MAX, ImVec2(150.0f, 150.0f));
	//}
	
	//ImGui::End();
	
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	SDL_RenderPresent(m_renderer);
}

void dae::Renderer::Destroy()
{
	//delete m_Amount;
	//delete m_Amount2;
	//delete m_TrashTheCashe;

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();

	if (m_renderer != nullptr)
	{
		SDL_DestroyRenderer(m_renderer);
		m_renderer = nullptr;
	}
}

void dae::Renderer::RenderTexture(const Texture2D& texture, const float x, const float y) const
{
	SDL_Rect dst{};
	dst.x = static_cast<int>(x);
	dst.y = static_cast<int>(y);

	SDL_QueryTexture(texture.GetSDLTexture(), nullptr, nullptr, &dst.w, &dst.h); //change deze voor scale
	SDL_RenderCopy(GetSDLRenderer(), texture.GetSDLTexture(), nullptr, &dst);
}

void dae::Renderer::RenderTexture(const Texture2D& texture, const float x, const float y, const float width, const float height) const
{
	SDL_Rect dst{};
	dst.x = static_cast<int>(x);
	dst.y = static_cast<int>(y);
	dst.w = static_cast<int>(width);
	dst.h = static_cast<int>(height);
	SDL_RenderCopy(GetSDLRenderer(), texture.GetSDLTexture(), nullptr, &dst);
}

SDL_Renderer* dae::Renderer::GetSDLRenderer() const { return m_renderer; }