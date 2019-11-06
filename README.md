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
qt
allegro >= 5
```

### Installing Allegro

Now after clone the repository you will need to install allegro5 

```
sudo apt-get update
sudo apt-get install liballegro5-dev
```

### Installing QT

You can install qt running the script "installqt.sh" script

```
sudo sh installqt.sh
```

## How to run

```
qmake
make
./ihs_game
```