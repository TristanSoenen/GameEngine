#pragma once
#include "string"
using sound_id = unsigned short;
class Sound_System
{
public:
	virtual ~Sound_System() = default;
	virtual void Play(const sound_id id, const float volume) = 0;
	virtual void LoadSound(const std::string file) = 0;
};

