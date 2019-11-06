#include "include/game.h"
#include<bits/stdc++.h>
using namespace std;

/*
    g++ main.cpp include/game.cpp -o a -lm -lallegro_image -lallegro -lallegro_ttf -lallegro_font -lallegro_audio -lallegro_acodec -lallegro_primitives -lallegro_ttf -lallegro_font
    ./a
*/

/* defines */
#define WIDTH 640
#define HEIGHT 480
#define FPS 60.0
#define FONT_SIZE 32
char TITLE[] = "IHS Project";

/* game class */
Game ihs_game = Game(WIDTH, HEIGHT, FPS, TITLE);

/* initial player positions */
int positions[][2] = {
    {10, HEIGHT/2},
    {WIDTH - 10, HEIGHT/2}
};

/* run game */
bool run = true;

int main(){

    if(!ihs_game.coreInit()) return -1;
    if(!ihs_game.windowInit()) return -1;
    if(!ihs_game.fontInit(FONT_SIZE)) return -1;

    for(int x = 0; x < qtPlayers; x++){
        ihs_game.setPlayerPosition(x, positions[x][0], positions[x][1]);
    }

    while(run){
        // FPS timer start
        ihs_game.startTimer();

        // While eventQueue isn't empty
        while(!ihs_game.isEventQueueEmpty()){
            ihs_game.waitForEvent();
            if(ihs_game.getEvent().type == ALLEGRO_EVENT_KEY_DOWN){ // key pressed
                switch(ihs_game.getEvent().keyboard.keycode){
                case ALLEGRO_KEY_W:
                    ihs_game.setPlayerMovement(0, UP);
                    //ihs_game.addScore(0);
                    break;
                case ALLEGRO_KEY_S:
                    ihs_game.setPlayerMovement(0, DOWN);
                    break;
                case ALLEGRO_KEY_UP:
                    ihs_game.setPlayerMovement(1, UP);
                    //ihs_game.addScore(1);
                    break;
                case ALLEGRO_KEY_DOWN:
                    ihs_game.setPlayerMovement(1, DOWN);
                    break;
                }
            }

            if(ihs_game.getEvent().type == ALLEGRO_EVENT_KEY_UP){
                if(ihs_game.getEvent().keyboard.keycode == ALLEGRO_KEY_W || ihs_game.getEvent().keyboard.keycode == ALLEGRO_KEY_S)
                    ihs_game.setPlayerMovement(0, NO_MOVEMENT);
                else if(ihs_game.getEvent().keyboard.keycode == ALLEGRO_KEY_UP || ihs_game.getEvent().keyboard.keycode == ALLEGRO_KEY_DOWN)
                    ihs_game.setPlayerMovement(1, NO_MOVEMENT);
            }

            if(ihs_game.getEvent().type == ALLEGRO_EVENT_DISPLAY_CLOSE){ // display closed
                run = false;
            }

        }

        ihs_game.drawMiddleLine();

        if(ihs_game.getPlayerMovement(0) == UP){
            if(!ihs_game.checkPlayerCollision(0, UP))
                ihs_game.setPlayerPosition(0, ihs_game.getPlayer(0).x, ihs_game.getPlayer(0).y - playerMovement);
        }else if(ihs_game.getPlayerMovement(0) == DOWN){
            if(!ihs_game.checkPlayerCollision(0, DOWN))
                ihs_game.setPlayerPosition(0, ihs_game.getPlayer(0).x, ihs_game.getPlayer(0).y + playerMovement);
        }
        if(ihs_game.getPlayerMovement(1) == UP){
            if(!ihs_game.checkPlayerCollision(1, UP))
                ihs_game.setPlayerPosition(1, ihs_game.getPlayer(1).x, ihs_game.getPlayer(1).y - playerMovement);
        }else if(ihs_game.getPlayerMovement(1) == DOWN){
            if(!ihs_game.checkPlayerCollision(1, DOWN))
                ihs_game.setPlayerPosition(1, ihs_game.getPlayer(1).x, ihs_game.getPlayer(1).y + playerMovement);
        }

        ihs_game.drawScoreBoard();
        ihs_game.drawPlayers();
        ihs_game.drawBall();
        ihs_game.moveBall();
        ihs_game.flipAndClear();
    }

    ihs_game.~Game();

    return 0;
}
