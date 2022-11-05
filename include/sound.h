#include <SDL2/SDL.h>
#include <string.h>
#include <iostream>
class ISound{
    public:
        virtual ~ISound() {};
        virtual void playSound() = 0;
        virtual void stopSound() = 0;

};

class Sound: public ISound{
    public:
        Sound(const char *filepath);
        
        ~Sound();
        void playSound() override;
        void stopSound() override;
        void setupDevice();

    private:
        SDL_AudioSpec wavSpec;
        Uint32 wavLength;
        Uint8 *wavBuffer;
        SDL_AudioDeviceID deviceId;
};
