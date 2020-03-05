#include <kipr/botball.h>
//function for turning right
int turnright()
{
        motor(2,50);
        motor(3,50);
        msleep(1800);
        motor(2,0);
        motor(3,0);
        msleep(200);
        motor(2,50);
        motor(3,-50);
        msleep(805);
        motor(2,50);
        motor(3,50);
        msleep(1800);
    return 0;
}
//function for turning right when the front is blocked 
int turnrightb()
{
    motor(2,50);
    motor(3,-50);
    msleep(805);
    motor(2,50);
    motor(3,50);
    msleep(500);
    return 0;
}
//function for turning left when the front, and right, are blocked at the same time 
int turnleft()
{
      motor(2,-50);
      motor(3,50);
      msleep(805);
      motor(2,50);
      motor(3,50);
      msleep(1800);
    return 0;
}
//function for going straight
int go()
{
        motor(2,50);
        motor(3,50);
        msleep(250);
    return 0;
}
//function for stopping 
int stop()
{
    motor(2,0);
    motor(3,0);
    msleep(400);
    return 0;
}
//main function 
int main()
{
    printf("Walk Maze");
    //While this is ture(one is greater than zero)
    while (1 > 0)
    {
        //While there is no wall detected in the front:
       while (analog(1) < 2900)
       {
      //if the right side is blocked, go straight
       if (analog(0) > 1900)
           {       
             go();
           }
     //if the right side is open, turn right
      else
           {
             turnright();
           }
       }
    //while the there is a wall in the front:
    while (analog(1) > 2900)
    {
        //stop the robot 
        stop();
        //if the right side is open, turn right
        if (analog(0) < 1900)
        {
       turnrightb();
        }
        //if the right side is blocked, turn left
        else
        {
      turnleft();
        }    
    }
    }

    return 0;
}

