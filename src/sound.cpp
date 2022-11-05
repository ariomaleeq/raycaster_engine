#include "sound.h"
Sound::Sound(const char* filepath){
    if(SDL_LoadWAV(filepath, &wavSpec, &wavBuffer, &wavLength)==nullptr){
        std::cout << "Error loading wav file" << std::endl;
    }
}
Sound::~Sound(){
    SDL_FreeWAV(wavBuffer);
    SDL_CloseAudioDevice(deviceId);
}

void Sound::playSound(){
    SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    SDL_PauseAudioDevice(deviceId, 0);
}
void Sound::stopSound(){
    SDL_PauseAudioDevice(deviceId, 1);
}
void Sound::setupDevice(){
    deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    if(deviceId == 0){
        std::cout << "Error opening audio device" << std::endl;
    }
}
