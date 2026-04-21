#pragma once
#define WALL '#'
#define FLOOR '.'
#define BOX 'B'
#define BOXandGOAL 'M'//mixÇÃM
#define GOAL 'G'
#define SPACE ' '

#define PLAYER 'P'

//Ç±Ç§èëÇØÇÈ
//stage.data[1][2] = BOX;

const int MAX_W = 10;
const int MAX_H = 10;

struct StageData {
	int widthAmount;
	int heightAmount;
	char stageData[MAX_W][MAX_H];

};


const StageData stage1{
    6,
    6,
    {
        "######",
        "#..P.#",
        "#B####",
        "#.#   ",
        "#G#   ",
        "###   "
    }
};

const StageData stage2{
    6,
    6,
    {
        "######",
        "#P...#",
        "#..BG#",
        "#.GB.#",
        "######"
    }
};

const StageData stage3{
    6,
    6,
    {
        "##### ",
        "#P..##",
        "#GBM.#",
        "#..#.#",
        "#....#",
        "######"
    }
};

const StageData stage4{
    7,
    6,
    {
        "###### ",
        "#P...##",
        "#.BB..#",
        "#.#G.G#",
        "#.....#",
        "#######"
    }
};