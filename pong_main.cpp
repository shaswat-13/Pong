# include <raylib.h>
# include "ball.hpp"
# include "cpu.hpp"
# include "paddle.hpp"

// initialize the scores to 0
int player_score = 0;
int cpu_score = 0;

// rgb values of colors used in the program
Color Blue = Color{54, 153, 237, 255};
Color Red = Color{242, 73, 37, 255};

// declare the objects globally
Ball ball;
Paddle player;
CPU_Paddle cpu;  

int main()
{
    // set windows dimensions
    const int screen_width = 1280;
    const int screen_height = 800;

    // initialize the window and set the fps
    InitWindow(screen_width, screen_height, "PONG");
    SetTargetFPS(60); // fps set to 60

    // set positions of game objects
    ball.set_position(GetScreenWidth(), GetScreenHeight());
    player.set_position(GetScreenWidth(), GetScreenHeight());
    cpu.set_position(GetScreenWidth(), GetScreenHeight());

    // instructions screen
    while(!IsKeyPressed(KEY_SPACE) && !WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("PONG GAME!", screen_width / 2 - 170, screen_height / 2 - 70, 70, WHITE);
        DrawText("FIRST TO 5 POINTS WINS", screen_width / 2 - 220, screen_height / 2 + 30, 40, WHITE);

        DrawText("PRESS SPACE TO CONTINUE", screen_width / 2 - 100, screen_height - 60, 20, WHITE);
        DrawText("PRESS ESC TO EXIT", screen_width / 2 - 65, screen_height - 30, 20, WHITE);

        EndDrawing();
    }

    // game runs until user presses esc in keyboard or cancel button on window
    // or until anyone scores 5 points
    while(!WindowShouldClose() && player_score < 5 && cpu_score < 5)
    {
        BeginDrawing();

        // update the positions of objects
        ball.Update();
        player.Update();
        cpu.Update(ball.y);

        // reset the background in each loop
        ClearBackground(Red);

        // draw the objects on screen
        DrawRectangle(screen_width/2, 0, screen_width/2, screen_height, Blue); // right half of the screen blue
        DrawCircle(screen_width/2, screen_height/2, 151, WHITE); // center outline of circle
        DrawCircle(screen_width/2, screen_height/2, 150, Red);  // red circle at middle of screen
        DrawCircleSector(Vector2{screen_width/2, screen_height/2}, 150, 90, 270, 0, Blue); // blue circle at middle of screen towards right
        DrawLine(screen_width/2, 0, screen_width/2, screen_height, WHITE); // middle partition line

        ball.Draw();
        player.Draw();
        cpu.Draw();

        DrawText(TextFormat("%i", player_score), screen_width / 4 -20, 20, 80, WHITE); // player score
        DrawText(TextFormat("%i", cpu_score), 3 * screen_width / 4 -20, 20, 80, WHITE); // cpu score


        // check for collisions
        // collision of ball with player paddle
        if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player.x, player.y, player.width, player.height}))
        {
            ball.speed_x *= -1;
        }
        // collision of ball with cpu paddle
        if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{cpu.x, cpu.y, cpu.width, cpu.height}))
        {
            ball.speed_x *= -1;
        }

        EndDrawing();
    }

    // game end screen
    while(!IsKeyPressed(KEY_ENTER) && !WindowShouldClose())
    {
        BeginDrawing();
        
        if (player_score >= 5)
        {
            ClearBackground(Red);
            DrawText("YOU WIN!", screen_width / 2 - 160, screen_height / 2 - 70, 70, WHITE);   
        }
        else if (cpu_score >= 5)
        {
            ClearBackground(Blue);
            DrawText("CPU WINS!", screen_width / 2 - 170, screen_height / 2 - 70, 70, WHITE);
        }

        DrawText("PRESS ESC TO EXIT", screen_width / 2 - 65, screen_height - 30, 20, WHITE);

        EndDrawing();
    }

    // close the window
    CloseWindow();
    return 0;
}