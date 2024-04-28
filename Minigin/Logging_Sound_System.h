#pragma once
#include "Sound_System.h"
#include "memory"
#include "iostream"

class Logging_Sound_System final : public Sound_System
{
	std::unique_ptr<Sound_System> _real_ss;
public:
	Logging_Sound_System(std::unique_ptr<Sound_System>&& ss) : _real_ss(std::move(ss)) {}
	virtual ~Logging_Sound_System() = default;

	void Play(const sound_id id, const float volume) override
	{
		_real_ss->Play(id, volume);
		std::cout << "Playing " << id << " at volume " << volume << "\n";
	}
};

