#include "SDL_Sound_System.h"

SDL_Sound_System::SDL_Sound_System()
	:Sound_System{}
{
	
}

SDL_Sound_System::~SDL_Sound_System()
{
	if (!m_Sounds.empty())
	{
		for (auto& sound : m_Sounds)
		{
			Mix_FreeChunk(sound);
		}
	}
}

void SDL_Sound_System::Play(const sound_id id, const float volume)
{
	if (id < m_Sounds.size())
	{
		Mix_Volume(-1, int(volume));
		Mix_PlayChannel(1, m_Sounds[int(id)], 0);
	}
}

void SDL_Sound_System::LoadSound(const std::string file)
{
	m_Sounds.emplace_back( Mix_LoadWAV(file.c_str()));
}