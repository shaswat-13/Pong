# include <raylib.h>
# include "paddle.hpp"

extern int player_score;

// CPU_Paddle inherits the class Paddle
class CPU_Paddle: public Paddle
{
public:

    // override the set_position method to set cpu_paddle at the right side of the screen
    void set_position(int screen_width, int screen_height)
    {
        x = screen_width - width - 10;
        y = screen_height/2 - height/2;
    }
    
    // override the Update method to make the cpu_paddle move automatically
    // cpu_paddle follows the movement of ball 
    void Update(int ball_y)
    {
        // increase the speed based on the current score
        if (player_score <= 1)
        {
            speed = 2;
        }
        else if (player_score <= 3)
        {
            speed = 5;
        }
        else if (player_score > 3)
        {
            speed = 10;
        }

        // if ball is at higher position than paddle, move the paddle up
        if(y + height/2 > ball_y)
        {
            y -= speed;
        }

        // if ball is at lower position than paddle, move the paddle down
        if(y + height/2 <= ball_y)
        {
            y += speed;
        }

        LimitMovement();
    }
};
