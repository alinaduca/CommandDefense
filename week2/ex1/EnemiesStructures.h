#pragma once

struct Point
{
    int x, y;
};

enum class EnemyDirection
{
    UpDirection,//decrease y by step
    DownDirection,//increase y by step
    LeftDirection, // decrease x by step
    RightDirection // increase x by step
};