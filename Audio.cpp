#include "Audio.h"

Audio::Audio(std::string path, int type) : path(path)
{
    music = NULL;
    sound = NULL;

    if(type == 0)
        music = Mix_LoadMUS(path.c_str());
    else if(type == 1)
        sound = Mix_LoadWAV(path.c_str());
}

Audio::~Audio()
{
    if(music) Mix_FreeMusic(music);
    if(sound) Mix_FreeChunk(sound);
}

void Audio::play(int n_loops)
{
    if(music)
        channel = Mix_PlayMusic(music, n_loops);
    else if(sound)
        channel = Mix_PlayChannel(-1, sound, n_loops);
}

void Audio::stop(int fade)
{
    if(music)
        Mix_FadeOutMusic(fade);
    else if(sound)
        Mix_HaltChannel(channel);
}

void Audio::changeVolume(int volume_change)
{
    int volume = Mix_VolumeMusic(-1);

    Mix_VolumeMusic(volume + volume_change);
}
