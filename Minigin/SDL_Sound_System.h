#pragma once
#include "Sound_System.h"
#include "SDL_mixer.h"
#include "vector"

class SDL_Sound_System final : public Sound_System
{
public:
	SDL_Sound_System();
	~SDL_Sound_System();
	void Play(const sound_id id, const float volume) override;
	void LoadSound(const std::string file) override;
private:
	std::vector<Mix_Chunk*> m_Sounds;
};