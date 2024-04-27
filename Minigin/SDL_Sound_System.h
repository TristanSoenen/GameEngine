#pragma once
#include "Sound_System.h"
class SDL_Sound_System final : public Sound_System
{
public:
	SDL_Sound_System();
	~SDL_Sound_System() = default;
	void Play(const sound_id id, const float volume) override;
};