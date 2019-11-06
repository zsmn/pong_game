#include<include/game.h>

#define WIDTH 640
#define HEIGHT 480
#define FPS 60.0
#define FONT_SIZE 16
char TITLE[] = "IHS Project";

Game ihs_game = Game(WIDTH, HEIGHT, FPS, TITLE);

int main(){

    if(!ihs_game.coreInit()) return -1;
    if(!ihs_game.windowInit()) return -1;
    if(!ihs_game.fontInit(FONT_SIZE)) return -1;

    // to exit game
    bool run = true;

    while(run){
        // FPS timer start
        ihs_game.startTimer();

        // While eventQueue isn't empty
        while(!ihs_game.isEventQueueEmpty()){
            ihs_game.waitForEvent();
            if(ihs_game.getEvent()->type == ALLEGRO_EVENT_KEY_DOWN){ // key pressed
                switch(ihs_game.getEvent()->keyboard.keycode){
                case ALLEGRO_KEY_UP:
                    fprintf(stderr, "Key pressed: UP ARROW\n");
                    break;
                case ALLEGRO_KEY_DOWN:
                    fprintf(stderr, "Key pressed: DOWN ARROW\n");
                    break;
                }
            }

            if(ihs_game.getEvent()->type == ALLEGRO_EVENT_DISPLAY_CLOSE){ // display closed
                run = false;
            }
        }

        ihs_game.drawMiddleLine();
        //ihs_game.drawBallInPosition(0, 0); // x, y
        //ihs_game.drawPlayerInPosition(0, 0, 0); // id, x, y
        ihs_game.flipAndClear();
    }

    return 0;
}
