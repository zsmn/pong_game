# ihs_game

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

## Prerequisites

First clone this repository

```
git clone https://github.com/zsmn/ihs_game.git
```

You also will need:

```
allegro >= 5
```

### Installing Allegro

Now after clone the repository you will need to install allegro5 

```
sudo apt-get update
sudo apt-get install liballegro5-dev
```

## How to run

```
g++ main.cpp include/game.cpp -o a -lm -lallegro_image -lallegro -lallegro_ttf -lallegro_font -lallegro_audio -lallegro_acodec -lallegro_primitives -lallegro_ttf -lallegro_font
./a
```
