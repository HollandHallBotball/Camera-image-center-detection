/Defining motor/servo ports
#define ELBOW 0
#define CLAW 1
#define GRABBER 2
#define LEFT_MOTOR 0
#define RIGHT_MOTOR 1
#define RIGHT_LINE 0
#define LEFT_LINE 1
#define TOUCH 0

/*
The premise behind line following is that there are two "line sensors" on the bot. When one senses that you have
wandered away from the line, it turns the opposite direction so as to stay on the line. 
Put simply, the line following sensors are a bit weird in that there are "ranges" of when it senses white vs the black 
line. As far as I can tell, the reading for the left line sensor (that is, to the left from the bot's perspective) is
less than 3500 when you're on the white, and greater than that when you're on black. For the right line sensor, it's 
less than 3200 when you're on the white. Using these values, we can determine when we're on the line, and use that to 
"follow" the line.
*/


int main()
{
    while (1) 
    //This program goes FOREVER, thus why this always evaluates as true. This is supposed to be a code "snippet" for 
    //learning purposes only.
    {
        if (analog(RIGHT_LINE) < 3200) //Reads the right line sensor analog port
        {
            printf("Turning left!");
            while (analog(RIGHT_LINE) < 3200)
            {
                motor(LEFT_MOTOR, 25); //Turning left because the right line sensor does not sense the line. the reason 
                motor(RIGHT_MOTOR, 50);//why BOTH motors are moving is because we still want to make forward progress.
                msleep(250); //Gives the motors time to move, in milliseconds
            }
        }
        else if (analog(LEFT_LINE) < 3500)
        {
            printf("Turning right!");
            while (analog(LEFT_LINE) < 3500)
            {
                motor(LEFT_MOTOR, 50);
                motor(RIGHT_MOTOR, 25);
                msleep(250);
            }
        }
        else if ((analog(LEFT_LINE) > 3500) && (analog(RIGHT_LINE) > 3200))
        {
           printf("On the line, moving forward!");
            while ((analog(LEFT_LINE) > 3500) && (analog(RIGHT_LINE) > 3200))
            {
                motor(LEFT_MOTOR, 50);
                motor(RIGHT_MOTOR, 50);
                msleep(250);
            }
        }
    }
    return 0; 
      
}

int main()
{
    create_connect();
    
      int loop_counter = 1;
      
      while ( loop_counter < 4000)//make the number smaller to make it go for less time
      { 
        loop_counter = loop_counter + 1;
          
    if (analog(0) >= 1500)
    {
    create_drive_direct (200, 100);
    }

    else
    {
    create_drive_direct (100, 200); 
      }
          
      }
    return 0;
