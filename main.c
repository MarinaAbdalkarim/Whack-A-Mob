// Final Quiz - Whack A Mole Capone
// Marina Abdalkarim
#include <allegro.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <time.h>
using namespace std;
void init();
void deinit();


void enemySpotted(BITMAP **primary_buffer, int x, int y, int a, int b, int c, int d)
{
       // Erase the old  character first     
	   int black;
	   BITMAP *villain;
	   black = makecol(0, 0, 0);
	   rectfill(*primary_buffer, a, b, c, d, black);
       // Draw character in new position  	   
       villain = load_bitmap("shoot.bmp", NULL);
       draw_sprite(screen, villain, x, y);        
}



int main() 
{
    init();
    bool loser = false, winner = false, trophy = false;
    const char* here = "map1.bmp";
    SAMPLE *game = load_sample("genesrockabye1.wav");
    MIDI *shot = load_midi("Shotgun1.mid");
    MIDI *hit = load_midi("punch2.mid");
    SAMPLE *lost = load_sample("End battle1.wav");
    MIDI *won = load_midi("Cute Witch.mid");
    set_volume(255, 255);
    int l = 100, r = 570;
    int timeStart, b = 1, z = 3, b2 = 1, j;
    int red, a = 1, t = 0, c = 30;
    timeStart = clock();
    int black;
    int brown;
    brown = makecol(85, 68, 52);
    black = makecol(0, 0, 0);
    int lives, n = 0, lives2 = 10, p = 10;
    int windowx[20], windowy[20], x, y, yellow, g, v;
    yellow = makecol(255, 255, 0);
    windowx[0] = 120;
    windowy[0] = 120;
    
    windowx[1] = 100;
    windowy[1] = 320;
    
    windowx[2] = 430;
    windowy[2] = 120;
    
    windowx[3] = 760;
    windowy[3] = 100;
    
    windowx[4] = 760;
    windowy[4] = 270;
    
    windowx[5] = 760;
    windowy[5] = 100;
    
    windowx[6] = 120;
    windowy[6] = 120;
    
    windowx[7] = 760;
    windowy[7] = 270;
    
    windowx[8] = 100;
    windowy[8] = 320;
    
    windowx[9] = 430;
    windowy[9] = 120;
    
    windowx[10] = 40;
    windowy[10] = 116;
    
    windowx[11] = 160;
    windowy[11] = 116;
    
    windowx[12] = 396;
    windowy[12] = 87;
    
    windowx[13] = 508;
    windowy[13] = 89;
    
    windowx[14] = 615;
    windowy[14] = 90;
    
    windowx[15] = 730;
    windowy[15] = 90;
    
    windowx[16] = 94;
    windowy[16] = 334;
    
    windowx[17] = 450;
    windowy[17] = 300;
    
    windowx[18] = 670;
    windowy[18] = 300;
    
    windowx[19] = 900;
    windowy[19] = 600;
    
    lives = 10;
    j = lives;
    BITMAP *heart;
    BITMAP *back, *buffer;
    BITMAP *villain;
    BITMAP *hammer;
    hammer = load_bitmap("hammer.bmp", 0);
    villain = load_bitmap("shoot.bmp", NULL);
    red = makecol(255, 0, 0);
    textprintf(screen, font, 100, 570, red, "Lives:%i", lives);
    heart = load_bitmap("heart.bmp", NULL);
	buffer = create_bitmap(SCREEN_W, SCREEN_H);
	BITMAP **primary_buffer = &buffer;
	// BITMAP *here;
	back = load_bitmap(here, NULL);
	draw_sprite(screen, back, 900, 600);
	// trythis = &back;
	BITMAP **trythis = &back;
	BITMAP *back2, *back3;
	BITMAP *back4;
	back4 = load_bitmap("winner.bmp", NULL);
	back3 = load_bitmap("loser.bmp" ,NULL);
	back2 = load_bitmap("map2.bmp", NULL);
	int h = back->h;
	int w = back->w;
	/*if (winner == true)
	   trythis = &back2;
     else if (loser == true)
          trythis = &back3;*/
    stretch_blit(*trythis,buffer,0,0,w,h,0,0,SCREEN_W,SCREEN_H);
    // draw_sprite(screen, heart, 50, 550);
	while (!key[KEY_ESC]) 
    {
          if (winner == true)
	         trythis = &back2;
          else if (loser == true)
               trythis = &back3;
          draw_sprite(*primary_buffer, heart, 50, 550);
          // rectfill(screen, 30, 540, 180, 600, black);
          // textprintf(screen, font, 100, 570, red, "Lives:%i", lives);
          draw_sprite(screen, hammer, mouse_x, mouse_y);
          blit(screen, screen, 0, 0, 0, 0, hammer->w, hammer->h);
          x = windowx[n];
          y = windowy[n];
          g = windowx[p];
          v = windowy[p];
          draw_sprite(*primary_buffer, villain, x, y);
          
          
          /*if (loser == false && trophy == false)
          {
            // play_midi(game, 0);
            play_sample(game, 128, 128, 1000, 1);
          }*/
          
          
          // textprintf(screen, font, 300, 560, yellow, "Mouse X:%i", mouse_x);
          // textprintf(screen, font, 300, 580, yellow, "Mouse Y:%i", mouse_y);
          textprintf(*primary_buffer, font, 400, 50, yellow, "Aim for the head", lives);
          textprintf(screen, font, l, r, red, "Lives:%i", lives);
          
                if (mouse_x >= 113 && mouse_x <= 167 && mouse_y >= 97 && mouse_y <= 157 && b == 1)
                {
                     circlefill(*primary_buffer, 128, 130, 10, yellow);
                    if (mouse_b)
                     {
                     t = t + z;
                     play_midi(hit, 0);
                      // destroy_midi(hit);
                      textprintf(screen, font, 200, 570, red, "Headshot!", lives);
                      n = 1;
                      enemySpotted(primary_buffer, x, y, 110, 100, 180, 180);
                      b = 2;
                     }
                     else if(((clock() - timeStart) / CLOCKS_PER_SEC >= (t + 3)))
                     {
                     t = t + z;
                     play_midi(shot, 0);
                     b = 2;
                      n = 1;
                      lives = lives - a;
                      enemySpotted(primary_buffer, x, y, 110, 100, 180, 180);
                      }
                } 
                
                if (mouse_x >= 91 && mouse_x <= 150 && mouse_y >= 300 && mouse_y <= 350 && b == 2)
                {
                   circlefill(*primary_buffer, 109, 328, 10, yellow);
                   if (mouse_b)
                   {
                   t = t + z;
                      textprintf(screen, font, 200, 570, red, "Headshot!", lives);
                      n = 2;
                      b = 3;
                      play_midi(hit, 0);
                      // destroy_midi(hit);
                      enemySpotted(primary_buffer, x, y, 90, 300, 150, 380);
                   }
                   else if(((clock() - timeStart) / CLOCKS_PER_SEC >= (t + 3)))
                     {
                     t = t + z;
                     play_midi(shot, 0);
                     b = 3;
                      n = 2;
                      
                      lives = lives - a;
                      // rectfill(*primary_buffer, 110, 100, c, d, black);
                      enemySpotted(primary_buffer, x, y, 90, 300, 150, 380);
                      }
                }
          
          if (mouse_x >= 440 && mouse_x <= 480 && mouse_y >= 120 && mouse_y <= 150 && b == 3)
                {
                   circlefill(*primary_buffer, 436, 130, 10, yellow);
                   if (mouse_b)
                   {
                   t = t + z;
                      textprintf(screen, font, 200, 570, red, "Headshot!", lives);
                      b = 4;
                      n = 3;
                      play_midi(hit, 0);
                      // destroy_midi(midi);
                      enemySpotted(primary_buffer, x, y, 420, 96, 480, 180);
                   }
                   else if(((clock() - timeStart) / CLOCKS_PER_SEC >= (t + 3)))
                     {
                     t = t + z;
                     b = 4;
                      n = 3;
                      play_midi(shot, 0);
                      lives = lives - a;
                      // rectfill(*primary_buffer, 110, 100, c, d, black);
                      enemySpotted(primary_buffer, x, y, 420, 96, 480, 180);
                      }
                }
                
          if (mouse_x >= 770 && mouse_x <= 800 && mouse_y >= 100 && mouse_y <= 130 && b == 4)
                {
                   circlefill(*primary_buffer, 770, 110, 10, yellow);  
                   if (mouse_b)
                   {
                   t = t + z;
                      textprintf(screen, font, 200, 570, red, "Headshot!", lives);
                      n = 4;
                      b = 5;
                      play_midi(hit, 0);
                      // destroy_midi(midi);
                      enemySpotted(primary_buffer, x, y, 760, 80, 830, 155);
                   }
                   else if(((clock() - timeStart) / CLOCKS_PER_SEC >= (t + 3)))
                     {
                     b = 5;
                     play_midi(shot, 0);
                      n = 4;
                      t = t + z;
                      lives = lives - a;
                      // rectfill(*primary_buffer, 110, 100, c, d, black);
                      enemySpotted(primary_buffer, x, y, 760, 80, 830, 155);
                      }
                }
                
                if (mouse_x >= 770 && mouse_x <= 800 && mouse_y >= 270 && mouse_y <= 300 && b == 5)
                {
                   circlefill(*primary_buffer, 766, 282, 10, yellow);
                   if (mouse_b)
                   {
                   t = t + z;
                      textprintf(screen, font, 200, 570, red, "Headshot!", lives);
                      b = 6;
                      n = 5;
                      play_midi(hit, 0);
                      // destroy_midi(midi);
                      draw_sprite(screen, villain, x, y);
                      enemySpotted(primary_buffer, x, y, 750, 250, 830, 330);
                   }
                   else if(((clock() - timeStart) / CLOCKS_PER_SEC >= (t + 3)))
                     {
                     play_midi(shot, 0);
                     b = 6;
                      n = 5;
                      t = t + z;
                      lives = lives - a;
                      // rectfill(*primary_buffer, 110, 100, c, d, black);
                      enemySpotted(primary_buffer, x, y, 750, 250, 830, 330);
                      }
                }
                
                if (mouse_x >= 770 && mouse_x <= 800 && mouse_y >= 100 && mouse_y <= 130 && b == 6)
                {
                   circlefill(*primary_buffer, 770, 110, 10, yellow);
                   if (mouse_b)
                   {
                   t = t + z;
                      textprintf(screen, font, 200, 570, red, "Headshot!", lives);
                      n = 6;
                      b = 7;
                      play_midi(hit, 0);
                      // destroy_midi(midi);
                      enemySpotted(primary_buffer, x, y, 760, 80, 830, 155);
                   }
                   else if(((clock() - timeStart) / CLOCKS_PER_SEC >= (t + 3)))
                     {
                     play_midi(shot, 0);
                     b = 7;
                      n = 6;
                      lives = lives - a;
                      t = t + z;
                      // rectfill(*primary_buffer, 110, 100, c, d, black);
                      enemySpotted(primary_buffer, x, y, 760, 80, 830, 155);
                      }
                }
          if (mouse_x >= 113 && mouse_x <= 167 && mouse_y >= 97 && mouse_y <= 157 && b == 7)
                {
                   circlefill(*primary_buffer, 128, 130, 10, yellow);
                   if (mouse_b)
                   {
                   t = t + z;
                      textprintf(screen, font, 200, 570, red, "Headshot!", lives);
                      b = 8;
                      n = 7;
                      play_midi(hit, 0);
                      // destroy_midi(midi);
                      enemySpotted(primary_buffer, x, y, 110, 100, 180, 180);
                   }
                   else if(((clock() - timeStart) / CLOCKS_PER_SEC >= (t + 3)))
                     {
                     play_midi(shot, 0);
                     b = 8;
                      n = 7;
                      lives = lives - a;
                      t = t + z;
                      enemySpotted(primary_buffer, x, y, 110, 100, 180, 180);
                      }
                }
        
        if (mouse_x >= 770 && mouse_x <= 800 && mouse_y >= 270 && mouse_y <= 300 && b == 8)
                {
                    circlefill(*primary_buffer, 766, 282, 10, yellow);
                   if (mouse_b)
                   {
                   t = t + z;
                      textprintf(screen, font, 200, 570, red, "Headshot!", lives);
                      b = 9;
                      n = 8;
                      play_midi(hit, 0);
                      // destroy_midi(midi);
                      draw_sprite(screen, villain, x, y);
                      enemySpotted(primary_buffer, x, y, 750, 250, 830, 330);
                   }
                   else if(((clock() - timeStart) / CLOCKS_PER_SEC >= (t + 3)))
                     {
                     play_midi(shot, 0);
                     b = 9;
                      n = 8;
                      t = t + z;
                      lives = lives - a;
                      // rectfill(*primary_buffer, 110, 100, c, d, black);
                      enemySpotted(primary_buffer, x, y, 750, 250, 830, 330);
                      }
                }
          
          if (mouse_x >= 91 && mouse_x <= 150 && mouse_y >= 300 && mouse_y <= 350 && b == 9)
                {
                   circlefill(*primary_buffer, 109, 328, 10, yellow);
                   if (mouse_b)
                   {
                   t = t + z;
                   
                      textprintf(screen, font, 200, 570, red, "Headshot!", lives);
                      n = 9;
                      b = 10;
                      play_midi(hit, 0);
                      // destroy_midi(midi);
                      enemySpotted(primary_buffer, x, y, 90, 300, 150, 380);
                   }
                   else if(((clock() - timeStart) / CLOCKS_PER_SEC >= (t + 3)))
                     {
                     play_midi(shot, 0);
                     b = 10;
                      n = 9;
                      lives = lives - a;
                      t = t + z;
                      // rectfill(*primary_buffer, 110, 100, c, d, black);
                      enemySpotted(primary_buffer, x, y, 90, 300, 150, 380);
                      }
                }
                
                if (mouse_x >= 440 && mouse_x <= 480 && mouse_y >= 120 && mouse_y <= 150 && b == 10)
                {
                   circlefill(*primary_buffer, 436, 130, 10, yellow);
                   if (mouse_b)
                   {
                   t = t + z;
                      textprintf(screen, font, 200, 570, red, "Headshot!", lives);
                      b = 1;
                      n = 0;
                      play_midi(hit, 0);
                      // destroy_midi(midi);
                      enemySpotted(primary_buffer, x, y, 420, 96, 480, 180);
                   }
                   else if(((clock() - timeStart) / CLOCKS_PER_SEC >= (t + 3)))
                     {
                      lives = lives - a;
                      play_midi(shot, 0);
                      b = 1;
                      t = t + z;
                      n = 0;
                      // rectfill(*primary_buffer, 110, 100, c, d, black);
                      enemySpotted(primary_buffer, x, y, 420, 96, 480, 180);
                      }
                }
          
          if (lives == 0)
             loser = true;
          if (((clock() - timeStart) / CLOCKS_PER_SEC == 30) && lives != 0)
             winner = true;
             
          if (lives2 == 0)
             loser = true;   
          
          if (loser == true)
          {
             stretch_blit(back3,buffer,0,0,back3->w,back3->h,0,0,SCREEN_W,SCREEN_H);
             stop_sample(game);
             play_sample(lost, 128, 128, 1000, 0);
          }
          
          if (winner == true)
          {
             stretch_blit(back2,buffer,0,0,back2->w,back2->h,0,0,SCREEN_W,SCREEN_H);
             draw_sprite(*primary_buffer, heart, 50, 550);
             draw_sprite(*primary_buffer, villain, g, v);
             // rectfill(screen, 100, 570, 140, 600, brown);
             textprintf(*primary_buffer, font, 100, 570, red, "Lives:%i", lives2);
             l = 900;
             r = 600;
          }
          
             if (mouse_x >= 52 && mouse_x <= 87 && mouse_y >= 90 && mouse_y <= 150 && b2 == 1)
                {
                     circlefill(*primary_buffer, 46, 127, 10, yellow); // window 1
                    if (mouse_b)
                     {
                     c = c + z;
                     play_midi(hit, 0);
                      textprintf(screen, font, 200, 570, red, "Headshot!", lives);
                      p = 11;
                      enemySpotted(primary_buffer, g, v, 35, 110, 87, 180);
                      b2 = 2;
                     }
                     else if(((clock() - timeStart) / CLOCKS_PER_SEC >= (c + 3)))
                     {
                     c = c + z;
                     play_midi(shot, 0);
                     b2 = 2;
                      p = 11;
                      lives2 = lives2 - a;
                      enemySpotted(primary_buffer, g, v, 35, 110, 87, 180);
                      }
                }
                if (mouse_x >= 167 && mouse_x <= 208 && mouse_y >= 97 && mouse_y <= 150 && b2 == 2)
                {
                     circlefill(*primary_buffer, 165, 129, 10, yellow); // window 2
                    if (mouse_b)
                     {
                     c = c + z;
                     play_midi(hit, 0);
                      textprintf(screen, font, 200, 570, red, "Headshot!", lives);
                      p = 12;
                      enemySpotted(primary_buffer, g, v, 160, 80, 218, 180);
                      b2 = 3;
                     }
                     else if(((clock() - timeStart) / CLOCKS_PER_SEC >= (c + 3)))
                     {
                     c = c + z;
                     play_midi(shot, 0);
                     b2 = 3;
                      p = 12;
                      lives2 = lives2 - a;
                      enemySpotted(primary_buffer, g, v, 160, 80, 218, 180);
                      }
                }
                if (mouse_x >= 400 && mouse_x <= 445 && mouse_y >= 70 && mouse_y <= 120 && b2 == 3)
                {
                     circlefill(*primary_buffer, 403, 91, 10, yellow); // window 3
                    if (mouse_b)
                     {
                     c = c + z;
                     play_midi(hit, 0);
                      textprintf(screen, font, 200, 570, red, "Headshot!", lives);
                      p = 13;
                      enemySpotted(primary_buffer, g, v, 380, 40, 450, 150);
                      b2 = 4;
                     }
                     else if(((clock() - timeStart) / CLOCKS_PER_SEC >= (c + 3)))
                     {
                     c = c + z;
                     play_midi(shot, 0);
                     b2 = 4;
                      p = 13;
                      lives2 = lives2 - a;
                      enemySpotted(primary_buffer, g, v, 380, 40, 450, 150);
                      }
                }
                if (mouse_x >= 510 && mouse_x <= 556 && mouse_y >= 68 && mouse_y <= 123 && b2 == 4)
                {
                     circlefill(*primary_buffer, 518, 101, 10, yellow); // window 4
                    if (mouse_b)
                     {
                     c = c + z;
                     play_midi(hit, 0);
                      textprintf(screen, font, 200, 570, red, "Headshot!", lives);
                      p = 14;
                      enemySpotted(primary_buffer, g, v, 492, 55, 450, 150);
                      b2 = 5;
                     }
                     else if(((clock() - timeStart) / CLOCKS_PER_SEC >= (c + 3)))
                     {
                     c = c + z;
                     play_midi(shot, 0);
                     b2 = 5;
                      p = 14;
                      lives2 = lives2 - a;
                      enemySpotted(primary_buffer, g, v, 492, 55, 450, 150);
                      }
                }
                if (mouse_x >= 620 && mouse_x <= 665 && mouse_y >= 70 && mouse_y <= 120 && b2 == 5)
                {
                     circlefill(*primary_buffer, 623, 101, 10, yellow); // window 5
                    if (mouse_b)
                     {
                     c = c + z;
                     play_midi(hit, 0);
                      textprintf(screen, font, 200, 570, red, "Headshot!", lives);
                      p = 15;
                      enemySpotted(primary_buffer, g, v, 600, 60, 665, 150);
                      b2 = 6;
                     }
                     else if(((clock() - timeStart) / CLOCKS_PER_SEC >= (c + 3)))
                     {
                     c = c + z;
                     play_midi(shot, 0);
                     b2 = 6;
                      p = 15;
                      lives2 = lives2 - a;
                     enemySpotted(primary_buffer, g, v, 600, 60, 665, 150);
                      }
                }
                if (mouse_x >= 733 && mouse_x <= 780 && mouse_y >= 70 && mouse_y <= 120 && b2 == 6)
                {
                     circlefill(*primary_buffer, 738, 101, 10, yellow); // window 6
                    if (mouse_b)
                     {
                     c = c + z;
                     play_midi(hit, 0);
                      textprintf(screen, font, 200, 570, red, "Headshot!", lives);
                      p = 16;
                      enemySpotted(primary_buffer, g, v, 710, 54, 780, 150);
                      b2 = 7;
                     }
                     else if(((clock() - timeStart) / CLOCKS_PER_SEC >= (c + 3)))
                     {
                     c = c + z;
                     play_midi(shot, 0);
                     b2 = 7;
                      p = 16;
                      lives2 = lives2 - a;
                     enemySpotted(primary_buffer, g, v, 710, 54, 780, 150);
                      }
                }
             if (mouse_x >= 100 && mouse_x <= 143 && mouse_y >= 310 && mouse_y <= 360 && b2 == 7)
                {
                     circlefill(*primary_buffer, 100, 340, 10, yellow); // window 7
                    if (mouse_b)
                     {
                     c = c + z;
                     play_midi(hit, 0);
                      textprintf(screen, font, 200, 570, red, "Headshot!", lives);
                      p = 17;
                      enemySpotted(primary_buffer, g, v, 77, 320, 150, 367);
                      b2 = 8;
                     }
                     else if(((clock() - timeStart) / CLOCKS_PER_SEC >= (c + 3)))
                     {
                     c = c + z;
                     play_midi(shot, 0);
                     b2 = 8;
                      p = 17;
                      lives2 = lives2 - a;
                     enemySpotted(primary_buffer, g, v, 77, 320, 150, 367);
                      }
                }
                if (mouse_x >= 445 && mouse_x <= 500 && mouse_y >= 277 && mouse_y <= 330 && b2 == 8)
                {
                     circlefill(*primary_buffer, 454, 301, 10, yellow); // window 8
                    if (mouse_b)
                     {
                     c = c + z;
                     play_midi(hit, 0);
                      textprintf(screen, font, 200, 570, red, "Headshot!", lives);
                      p = 18;
                      enemySpotted(primary_buffer, g, v, 430, 276, 500, 336);
                      b2 = 9;
                     }
                     else if(((clock() - timeStart) / CLOCKS_PER_SEC >= (c + 3)))
                     {
                     c = c + z;
                     play_midi(shot, 0);
                     b2 = 9;
                      p = 18;
                      lives2 = lives2 - a;
                     enemySpotted(primary_buffer, g, v, 430, 276, 500, 336);
                      }
                }
                if (mouse_x >= 676 && mouse_x <= 716 && mouse_y >= 280 && mouse_y <= 334 && b2 == 9)
                {
                    circlefill(*primary_buffer, 680, 300, 10, yellow); // window 9
                    if (mouse_b)
                     {
                     c = c + z;
                     play_midi(hit, 0);
                      textprintf(screen, font, 200, 570, red, "Headshot!", lives);
                      p = 10;
                      enemySpotted(primary_buffer, g, v, 676, 275, 723, 338);
                      b2 = 1;
                     }
                     else if(((clock() - timeStart) / CLOCKS_PER_SEC >= (c + 3)))
                     {
                     c = c + z;
                     play_midi(shot, 0);
                     b2 = 1;
                      p = 10;
                      lives2 = lives2 - a;
                     enemySpotted(primary_buffer, g, v, 430, 276, 500, 336);
                      }
                }
          
          if (lives2 == 0)
             loser = true;
             
          if(((clock() - timeStart) / CLOCKS_PER_SEC >= 60) && lives2 != 0)
                       trophy = true;
                       
          if (trophy == true)
          {
             stretch_blit(back4,buffer,0,0,back4->w,back4->h,0,0,SCREEN_W,SCREEN_H);
             play_midi(won, 0);
          }
          acquire_screen();
          blit(buffer,screen,0,0,0,0,buffer->w,buffer->h);
          release_screen();
    }
	deinit();
	return 0;
}
END_OF_MAIN()

void init() 
{
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 900, 600, 0, 0);
	if (res != 0) 
    {
		allegro_message(allegro_error);
		exit(-1);
	}

    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, 0);
	install_timer();
	install_keyboard();
	install_mouse();
	/* add other initializations here */
}

void deinit() 
{
	clear_keybuf();
	/* add other deinitializations here */
}
