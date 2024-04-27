#include "SDL_Sound_System.h"

SDL_Sound_System::SDL_Sound_System()
	:Sound_System{}
{

}

void SDL_Sound_System::Play(const sound_id id, const float volume)
{
	int i = id;
	float j = volume;
	i = int(j);
}