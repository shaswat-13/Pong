# include <raylib.h>

// the definition of paddle will only occur once
# pragma once
class Paddle
{
protected:

    // restricts the paddle from going off screen
    void LimitMovement()
    {
        // top restriction
        if( y <= 0)
        {
            y = 0;
        }

        // bottom restriction
        if(y + height >= GetScreenHeight())
        {
            y = GetScreenHeight() - height;
        }
    }

public:
    float x, y;
    float width, height;
    int speed;

    // constructor to initialize the dimensions and movement speed of paddle
    Paddle()
    {
        width = 25;
        height = 120;
        speed = 8;
    }

    // initializes the position of paddle 
    void set_position(int screen_width, int screen_height)
    {
        x = 10;
        y = screen_height/2 - height/2;
    }

    // draw the paddle
    void Draw()
    {
        DrawRectangleRounded(Rectangle{x, y, width, height}, 0.8, 0, WHITE);
    }

    // movement of paddle
    void Update()
    {
        // paddle moves up when up key is pressed
        if(IsKeyDown(KEY_UP))
        {
            y -= speed;
        }

        // paddle moves down when down key is pressed
        if(IsKeyDown(KEY_DOWN))
        {
            y += speed;
        }

        // restrict paddle from going off screen
        LimitMovement();
    }
};
