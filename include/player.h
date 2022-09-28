#include <iostream>
#include <vector>


class Player{

    public:

        Player();
        void getPlayerState();
        void movePlayer();
        ~Player();
    private:

        float state[4]; // state of the player: postion and angle

};
