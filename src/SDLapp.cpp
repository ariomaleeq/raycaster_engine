#include "SDLapp.h"

SDLapp::SDLapp(Uint32 subsystemsFlags){
    if(SDL_Init(subsystemsFlags) <0){
        std::cout << "Error initializing SDL" << std::endl;
    }
}
