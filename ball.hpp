# include <raylib.h>

// scores
// extern makes the variable accessible in entire program where the ball.hpp is included
extern int player_score;
extern int cpu_score;

class Ball
{
public:
    float x, y;
    int speed_x, speed_y;
    int radius;

    // default constructor to initialize the size and movement of ball
    Ball()
    {
        radius = 20;
        speed_x = 7;
        speed_y = 7;
    }

    // keep the ball at the middle of the screen after each round
    void set_position(int screen_width, int screen_height)
    {
        x = screen_width/2;
        y = screen_height/2;
    }

    // raylib function to draw a circle on screen
    void Draw()
    {
        DrawCircle(x, y, 20, WHITE);
    }

    // movement of ball
    void Update()
    {
        // movement of ball
        x += speed_x;
        y += speed_y;

        // recirculate the ball if it touches the edge of screen
        // vertical restriction
        if(y + radius >= GetScreenHeight() || y - radius <= 0)
        {
            speed_y *= -1;
        }

        // horizontal restrictions
        // if ball touches the right side of screen
        if(x + radius >= GetScreenWidth())
        {
            player_score++;
            ResetBall();
        }
        // if ball touches the left side of the screen
        if(x - radius <= 0)
        {
            cpu_score++;
            ResetBall();
        }
    }

    // resets the ball position
    void ResetBall()
    {
        // initially placed at center
        x = GetScreenWidth()/2;
        y = GetScreenHeight()/2;

        // randomise the direction of ball movement
        int speed_choices[2] = {-1,1};
        speed_x *= speed_choices[GetRandomValue(0,1)];
        speed_y *= speed_choices[GetRandomValue(0,1)];

    }
};