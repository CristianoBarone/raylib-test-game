# Raylib game template

This project is a template for making point and click games using Raylib.

I must disclose that this project was made for fun and as such presents what could be defined as "deadly sins of coding", that are things that
I usually **wouldn't** do when programming on a project that is supposed to include others.

Those are the following:

  - Using λ as a variable name because "it looked slick"
  - Inserting code more than a line long in headers "out of lazyness"
  - Including no Makefile because "I can compile it by typing the same command every time"

### Remember that this code was not meant to be published in the first place and thus is far from polished

## How to compile

After downloading the repository you may compile it by running this command

> g++ game.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o game

So far it was only tested on Linux. The code is not guaranteed to compile on other platforms, but could be easily ported thanks to Raylib's versatility.
