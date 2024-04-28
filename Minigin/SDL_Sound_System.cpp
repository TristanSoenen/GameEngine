#include "SDL_Sound_System.h"
#include "SDL_mixer.h"
#include <memory>

SDL_Sound_System::SDL_Sound_System()
	:Sound_System{}
{
	
}

void SDL_Sound_System::Play(const sound_id id, const float volume)
{
	int i = id;
	float j = volume;
	i = int(j);
	Mix_Volume(-1, int(volume));
	Mix_Chunk *effect = Mix_LoadWAV("../Data/PlayerShoot.wav");
	Mix_PlayChannel(1, effect, 0);
}