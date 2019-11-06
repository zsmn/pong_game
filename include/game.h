#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define qtPlayers 2
#define lineParts 30
#define spacingParts 5

typedef struct{
    int x, y;
    double speed;
    double speed_angle;
} Object;

class Game{
    public:
        // constructor
        Game(int width, int height, int fps, char *title);
        ~Game();

        // allegro inits
        bool coreInit();
        bool windowInit();
        bool fontInit(int size);

        // getters
        ALLEGRO_DISPLAY* getWindow();
        ALLEGRO_EVENT_QUEUE* getEventQueue();
        ALLEGRO_EVENT* getEvent();

        // allegro utils
        void waitForEvent();
        void flipAndClear();

        // draw functions
        void drawMiddleLine();

        // checks
        bool isEventQueueEmpty();

        /* fps control */
        void startTimer();
        double getTimer();
        void FPSLimit();

        /* objects control */
        // drawing
        void drawPlayers();
        void drawBall();
        // setters
        void setBallPosition(int x, int y);
        void setPlayerPosition(int id, int x, int y);
        void setBallSpeed(double speed);
        void setBallSpeedAngle(double speed_angle);
        // getters
        Object getPlayer(int id);
        Object getBall();


    private:
        // ALLEGRO ITEMS
        ALLEGRO_FONT *scoreBoard;
        ALLEGRO_DISPLAY *mainWindow;
        ALLEGRO_EVENT_QUEUE *eventQueue;
        ALLEGRO_EVENT *allegroEvent;

        // Window parameters
        char *title;
        int width;
        int height;

        // FPS Control
        double startingTime;
        double FPS;

        Object players[qtPlayers];
        Object ball;
};
