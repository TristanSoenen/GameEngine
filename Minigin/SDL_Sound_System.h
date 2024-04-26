#pragma once
#include "Sound_System.h"
class SDL_Sound_System : public Sound_System
{
public:
	void Play(const sound_id id, const float volume) override;
};

