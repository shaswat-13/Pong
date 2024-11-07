# Pong Game

A simple Pong game implemented in C++ with Raylib for graphics.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Setup](#setup)
- [Usage](#usage)
- [File Descriptions](#file-descriptions)

## Introduction

This project is a classic Pong game where the player competes against a CPU-controlled paddle. The goal is to reach 5 points first by preventing the ball from going past your paddle.

## Features

- Player vs. CPU gameplay
- Realistic ball movement with collision detection
- Player-controlled paddle movement
- Dynamic CPU paddle speed adjustment based on the player's score

## Setup

### Prerequisites
- C++ compiler (e.g., `g++`)
- [Raylib library](https://www.raylib.com/) for graphics and window management

### Installation

1. Install the Raylib library.

   **For Debian/Ubuntu**:
   ```bash
   sudo apt-get install libraylib-dev
   ```
2. Clone this repository.
   ```bash
   git clone https://github.com/shaswat-13/Pong
   cd Pong
   ```
3. Compile the code.
   ```bash
   g++ -o PONG pong_main.cpp -std=c++11 -I/opt/homebrew/include -L/opt/homebrew/lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit
   ```
4. Run the game.
   ```bash
   ./PONG
   ```

## Usage
  - Use the arrow keys (↑ and ↓) to control the player's paddle on the left side.
  - The CPU paddle adjusts its speed based on your score.
  - First player to reach 5 points wins the game!

## File Descriptions
1. pong_main.cpp: Main file that sets up the game window, initializes objects, and handles the main game loop and collision detection.
2. ball.hpp: Defines the Ball class, including the ball's position, movement, and behavior when it collides with the paddles or edges of the screen.
3. paddle.hpp: Defines the Paddle class for the player, including movement controls, drawing, and boundary limits.
4. cpu.hpp: Extends the Paddle class for the CPU, with automatic movement and a difficulty adjustment based on the player's score.

