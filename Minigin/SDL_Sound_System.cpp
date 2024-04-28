#include "SDL_Sound_System.h"
#include "SDL_mixer.h"
#include "vector"

class SDL_Sound_System::Soundimpl
{
public:
	~Soundimpl();
	void Play(const sound_id id, const float volume);
	void LoadSound(const std::string file);
private:
	std::vector<Mix_Chunk*> m_Sounds;
};

SDL_Sound_System::SDL_Sound_System()
	:Sound_System{}
{
	m_Soundimpl = std::make_unique<Soundimpl>();
}

SDL_Sound_System::Soundimpl::~Soundimpl()
{
	if (!m_Sounds.empty())
	{
		for (auto& sound : m_Sounds)
		{
			Mix_FreeChunk(sound);
		}
	}
}

void SDL_Sound_System::Soundimpl::Play(const sound_id id, const float volume)
{
	if (id < m_Sounds.size())
	{
		Mix_Volume(-1, int(volume));
		Mix_PlayChannel(1, m_Sounds[int(id)], 0);
	}
}

void SDL_Sound_System::Soundimpl::LoadSound(const std::string file)
{
	m_Sounds.emplace_back(Mix_LoadWAV(file.c_str()));
}

SDL_Sound_System::~SDL_Sound_System()
{

}

void SDL_Sound_System::Play(const sound_id id, const float volume)
{
	m_Soundimpl->Play(id, volume);
}

void SDL_Sound_System::LoadSound(const std::string file)
{
	m_Soundimpl->LoadSound(file);
}