#include "all.h"
#include "audio.h"

void audio_init()
{
    music::load(0, L"./Data/Sounds/maou_se_sound22.wav");
    music::load(1, L"./Data/Sounds/maou_se_system10.wav");
    music::load(2, L"./Data/Sounds/maou_se_system28.wav");
    music::load(3, L"./Data/Sounds/maou_se_system45.wav");
}
