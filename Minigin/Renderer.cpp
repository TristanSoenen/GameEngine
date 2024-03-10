#include <stdexcept>
#include "Renderer.h"
#include "SceneManager.h"
#include "Texture2D.h"
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_sdl2.h"
#include "imgui_plot.h"
#include "chrono"
#include "iostream"



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
	ImGui::ShowDemoWindow();

	ImGui::Begin("exercise1");
	ImGui::InputInt("# samples", m_Amount);
	
	if (ImGui::Button("Trash The Cashe"))
	{
		TrashTheCasheEx1();
	}
	//ImGui::PlotLines();
	ImGui::End();

	ImGui::Begin("exercise2");
	ImGui::InputInt("# samples", m_Amount2);
	ImGui::Button("Trash The Cashe with GameObject3D");
	ImGui::Button("Trash The Cashe with GameObject3DAlt");
	ImGui::End();
	
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	SDL_RenderPresent(m_renderer);
}

void dae::Renderer::Destroy()
{
	delete m_Amount;
	delete m_Amount2;

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
	SDL_QueryTexture(texture.GetSDLTexture(), nullptr, nullptr, &dst.w, &dst.h);
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

void dae::Renderer::TrashTheCasheEx1() const
{
	int amountOfTimes = *m_Amount;
	for (int j = 0; j <= amountOfTimes; j++)
	{
		const int size{ 1'000'000 };
		int* arr{ new int[size] {} };
		//gameobject3D* object{ new gameobject3D[size]{} };
		//gameobject3DAlt* objectAlt{ new gameobject3DAlt[size]{} };

		int arrIndex = 0;
		for (int stepsize = 1; stepsize <= 1024; stepsize *= 2)
		{
			
			auto start = std::chrono::high_resolution_clock::now();
			for (int i = 0; i < size; i += stepsize)
			{
				arr[i] *= 2;
				//object[i].id *= 2;
				//objectAlt[i].id *= 2;
			}

			auto end = std::chrono::high_resolution_clock::now();
			auto elapsedTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
			std::cout /*<< stepsize << " "*/ << elapsedTime << "\n";
			//m_Values[arrIndex] = float(elapsedTime);
			arrIndex++;
		}

		delete arr;
	}
}