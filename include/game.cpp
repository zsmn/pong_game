#include "game.h"

Game::Game(int width, int height, int fps, char *title){
    this->width = width;
    this->height = height;
    this->FPS = fps;
    this->title = title;
}

Game::~Game(){
    al_destroy_font(scoreBoard);
    al_destroy_display(mainWindow);
    al_destroy_event_queue(eventQueue);
}

bool Game::coreInit(){
    if(!al_init()){
        fprintf(stderr, "Allegro couldn't be started\n");
        return false;
    }

    if(!al_init_image_addon()){
        fprintf(stderr, "Allegro couldn't init add-on allegro_image\n");
        return false;
    }

    if(!al_init_font_addon()){
        fprintf(stderr, "Allegro couldn't init add-on allegro_font\n");
        return false;
    }

    if(!al_init_ttf_addon()){
        fprintf(stderr, "Allegro couldn't init add-on allegro_ttf\n");
        return false;
    }

    if(!al_init_primitives_addon()){
        fprintf(stderr, "Allegro couldn't init add-on allegro_primitives\n");
        return false;
    }

    eventQueue = al_create_event_queue();
    if(!eventQueue){
        fprintf(stderr, "Allegro couldn't start event queue\n");
        return false;
    }

    return true;
}

bool Game::windowInit(){
    // window and event queue creation
    mainWindow = al_create_display(width, height);
    if(!mainWindow){
        fprintf(stderr, "Allegro couldn't create window\n");
        return false;
    }
    al_set_window_title(mainWindow, title);

    // register window on the event queue
    al_register_event_source(eventQueue, al_get_display_event_source(mainWindow));
    al_register_event_source(eventQueue, al_get_keyboard_event_source());
    al_register_event_source(eventQueue, al_get_mouse_event_source());

    return true;
}

bool Game::fontInit(int size){
    /*
    scoreBoard = al_load_font("font.ttf", size, 0);

    if(!scoreBoard){
        fprintf(stderr, "Allegro couldn't load the font\n");
        return false;
    }
    */

    return true;
}

void Game::startTimer(){
    startingTime = al_get_time();
}

double Game::getTimer(){
    return (al_get_time() - startingTime);
}

void Game::FPSLimit(){
    if(getTimer() < 1.0/FPS){
        al_rest((1.0 / FPS) - getTimer());
    }
}

ALLEGRO_DISPLAY* Game::getWindow(){
    return mainWindow;
}

ALLEGRO_EVENT_QUEUE* Game::getEventQueue(){
    return eventQueue;
}

ALLEGRO_EVENT* Game::getEvent(){
    return allegroEvent;
}

bool Game::isEventQueueEmpty(){
    return al_is_event_queue_empty(eventQueue);
}

void Game::waitForEvent(){
    al_wait_for_event(eventQueue, allegroEvent);
}

void Game::flipAndClear(){
    al_flip_display();
    al_clear_to_color(al_map_rgb(0, 0, 0));
    FPSLimit();
}

void Game::drawMiddleLine(){
    int newTam = 0;
    for(int x = 1; x <= lineParts; x++){
        al_draw_line(width/2.0, newTam, width/2.0, x * (height/lineParts), al_map_rgb(255, 255, 255), 0);
        newTam = (x * (height/lineParts)) + spacingParts;
    }
}

Object Game::getBall(){
    return ball;
}

Object Game::getPlayer(int id){
    // only works with [1 <= id <= qtPlayers]
    if(id > qtPlayers || id <= 0){
        fprintf(stderr, "Invalid object id\n");
        exit(-1);
    }

    return players[id];
}

void Game::drawBall(){

}

void Game::drawPlayers(){

}

void Game::setBallPosition(int x, int y){
    this->ball.x = x;
    this->ball.y = y;
}

void Game::setPlayerPosition(int id, int x, int y){
    if(id <= 0 || id >= qtPlayers){
        fprintf(stderr, "Invalid Player ID\n");
        exit(-1);
    }

    this->players[id].x = x;
    this->players[id].y = y;
}

void Game::setBallSpeed(double speed){
    this->ball.speed = speed;
}

void Game::setBallSpeedAngle(double speed_angle){
    this->ball.speed_angle = speed_angle;
}

