#pragma once
#include "memory"
class Sound_System;

class ServiceLocator final
{
	static std::unique_ptr<Sound_System> _ss_instance;
public:
	static Sound_System& get_Sound_System() { return *_ss_instance; }
	static void register_Sound_System(std::unique_ptr<Sound_System>&& ss) { _ss_instance = std::move(ss); }
};

