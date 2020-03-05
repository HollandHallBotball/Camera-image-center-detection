#include <kipr/botball.h>

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

}
