/*******************************************************************************
 * Copyright (c) 2015 Andrew Low.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *    Andrew Low - initial implementation
 *******************************************************************************/
 

#include <Arduboy.h>
#include "bitmaps.h"
#include "flight.h"

Arduboy arduboy;

bool start = false;
int score = 0;
int bestScore = 0;
char scoreString[32];
int batY = 25;         // (64-14) / 2 => )screen height - bat size) / 2
const int batX = 20;   // constant left/right position
const int batRate = 20;  // animate every N frames
unsigned int frame = 0;
int batFrame = 0;
int owlFrame = 0;
int bugFrame = 0;

// owls can move from 'off screen' to 'off screen'
// -16 to 128 = 144 unique positions
bool owlActive = false;  // is there an owl in flight
int owlX = 128;
int owlY = 0;
const int owlRate = 30;
int owlSpeed = 2; 
int flightOffset = 0;

// we can have up to 10 bugs at one time
#define NUMBUGS 10
int bugsX[NUMBUGS] = { 
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
int bugsY[NUMBUGS] = { 
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
const int bugRate = 8;
int i;

void intro()
{
  for(int i = -8; i < 28; i = i + 2)
  {
    arduboy.clear();
    arduboy.setCursor(46, i);
    arduboy.print("ARDUBOY");
    arduboy.display();
    if(i == 14)
    {
      arduboy.tunes.tone(987, 160);
    }
    if(i == 22)
    {
      arduboy.tunes.tone(1318, 400);

    }
    delay(40);
  }

  delay(1000);
}

void setup()
{
  arduboy.begin();
  arduboy.setFrameRate(60);
  intro();
  // put up the title screen until A is pressed
  arduboy.clear();
  arduboy.drawSlowXYBitmap(0, 0, title, 128, 64, 1);
  arduboy.display();
}

void loop()
{
  // pause render until it's time for the next frame
  if (!(arduboy.nextFrame()))
    return;

  if(!start) {
    if(arduboy.pressed(A_BUTTON)) {
      start = true;
      frame = 0;
      arduboy.clear();
      arduboy.initRandomSeed();
    }
  }

  if(start) {

    arduboy.clear();
    frame++;      // increments forever (looping)

    if(!owlActive) {
      flightOffset++;
      if(flightOffset == 462) {  // see flight.cpp
        flightOffset = 0;
      }
    }

    batFrame = frame % batRate;
    owlFrame = frame % owlRate;
    bugFrame = frame % bugRate;

    if( !owlActive ) {
      if(2 > random(1,300)) { // 2 in 300 chances of an owl becoming active
        owlActive = true;
        owlX = 128;
      }
    }

    if( owlActive) {
      if(0 == (frame % owlSpeed)) {
        owlX--;
      }

      // eventually we want a set of random flights to pick from
      owlY = flight1[flightOffset + owlX + 16];

      if(owlX == -16) { // owl is offscreen
        owlActive = false;
      }

      if(owlFrame < (owlRate/2)) {
        arduboy.drawSlowXYBitmap(owlX, owlY, owl1, 16, 11, 1);
      } 
      else {
        arduboy.drawSlowXYBitmap(owlX, owlY, owl2, 16, 11, 1);
      }
    }

    if(4 > random(100)) { // 4% chance of a bug appearing
      // search to find a -1 in the bug array
      for (i=0; i<NUMBUGS; i++) {
        if(bugsX[i] == -1) break;
      }
      if (i!= NUMBUGS){ // we found a -1
        bugsX[i] = 128;
        bugsY[i] = random(1,61);
      }
    }
    if(0 == (frame%3)) { // every couple of frames`
      for(i=0; i<NUMBUGS; i++) {
        if(bugsX[i] != -1) {
          int m;
          m = random(1,9);  // jitter up or down
          if(m <= 2) {
            bugsY[i]++;
          } 
          if(m >=8 ) {
            bugsY[i]--;          
          }
          bugsX[i]--;  // bugs naturally stop animating when they hit -1
          if(bugFrame < (bugRate/2)) {
            arduboy.drawSlowXYBitmap(bugsX[i], bugsY[i], bug1, 3, 3, 1);
          } 
          else {
            arduboy.drawSlowXYBitmap(bugsX[i], bugsY[i], bug2, 3, 3, 1);
          }
        }
      }
    }

    if(batFrame < (batRate/2)) {
      arduboy.drawSlowXYBitmap(batX, batY, bat1, 11, 14, 1);
    } 
    else {
      arduboy.drawSlowXYBitmap(batX, batY, bat2, 11, 14, 1);
    }


    if(0 == (frame%3)) { // every couple of frames`(optimization: same as animation)
      int ox, oy;
      // collision with bugs
      // bat is 14px high, 11px wide
      // head starts 5px down 7px across - head is 4px by 4px
      int bx = batX+7;
      int by = batY+5;
      for(i=0; i<NUMBUGS; i++) {
        if(bugsX[i] != -1) {
          if((bugsX[i] >= bx) && (bugsX[i] <= (bx + 4))) {
            if((bugsY[i] >= by) && (bugsY[i] <= (by + 4))) {
              // collision, eat the bug
              bugsX[i] = -1;
              arduboy.tunes.tone(2000, 20);
              score++;
            }
          }
        } 
      }
      // collision with owl
      // bat is 14px high, 11px wide
      // body of bat starts 5px down 1px in
      // 10px wide, 4px high
      bx = batX+1;
      // by = batY+5; same as above
      // owl body is 16px wide, 11px high
      // owl core starts 5px in, from top to bottom
      // owl core is 6px wide
      ox = owlX +5;
      oy = owlY;
      if((ox < bx+10) &&
        (ox + 6 > bx) &&
        (oy < by+4) &&
        (oy+11 > by)) {
        // owl and bat collide
        start = false;
        arduboy.setCursor(38, 26);
        arduboy.print("GAME OVER");
        arduboy.setCursor(38, 36);
        sprintf(scoreString, "Best: %d", bestScore);
        arduboy.print(scoreString);
      }
    }

 
    if(arduboy.pressed(UP_BUTTON))
    {
      batY--;
      if(batY < 0) {
        batY = 0;
      }

    }
    if(arduboy.pressed(DOWN_BUTTON))
    {
      batY++;
      if(batY > (64-14)) {
        batY = 64-14;
      }
    }

    if(score > bestScore) {
      bestScore = score;
    }

    // draw score
    arduboy.setCursor(72, 0);
    sprintf(scoreString, "%d", score);
    arduboy.print(scoreString);



    arduboy.display();

    if( !start ) {
      // We've just displayed GAME OVER
      // clear out variables to start again
      score = 0;
      owlActive = false;
      owlY = 128; // ensure it can't collide with bat
      for (i=0; i<NUMBUGS; i++) {
        bugsX[i] =  -1;
      }
    }
  }

}

