#include "SDL_Sound_System.h"
#include "SDL_mixer.h"
#include "vector"
#include "cassert"
class SDL_Sound_System::Soundimpl
{
public:
	~Soundimpl();
	void Play(const sound_id id, const int volume);
	void Update()
	{
		if (head_ == tail_) return;

		Mix_Volume(-1, int(pending_[head_].volume));
		Mix_PlayChannel(1, m_Sounds[int(pending_[head_].id)], 0);

		head_ = (head_ + 1) % MAX_PENDING;
	}
	void LoadSound(const std::string file);
private:
	std::vector<Mix_Chunk*> m_Sounds;

	static const int MAX_PENDING = 16;
	PlayMessage pending_[MAX_PENDING];
	int head_ = 0;
	int tail_ = 0;
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

void SDL_Sound_System::Soundimpl::Play(const sound_id id, const int volume)
{
	assert((tail_ + 1) % MAX_PENDING != head_);

	for (int i = head_; i != tail_; i = (i + 1) % MAX_PENDING)
	{
		if (pending_[i].id == id)
		{
			if (volume > pending_[i].volume)
			{
				pending_[i].volume = volume;
			}
			return;
		}
	}

	pending_[tail_].id = id;
	pending_[tail_].volume = volume;
	tail_ = (tail_ + 1) % MAX_PENDING;
}

void SDL_Sound_System::Soundimpl::LoadSound(const std::string file)
{
	m_Sounds.emplace_back(Mix_LoadWAV(file.c_str()));
}

SDL_Sound_System::~SDL_Sound_System()
{

}

void SDL_Sound_System::Play(const sound_id id, const int volume)
{
	m_Soundimpl->Play(id, volume);
}

void SDL_Sound_System::LoadSound(const std::string file)
{
	m_Soundimpl->LoadSound(file);
}

void SDL_Sound_System::Update()
{
	m_Soundimpl->Update();
}