#include <kipr/botball.h>
//By the Holland Hall Robotics Team

int inRange(int iw, int ow) {
    if (((iw - ow) < 5) && ((iw - ow) > -5)) {
        return 0; //Return true
    } else {
        return 1; //Returns false
    }
}

int main()
{
    int redChannel = 0, blueChannel = 1, firstObject = 0, notCentered = 0, imageCenter, objectCenter;
    camera_open_black();
    create_connect();
    while (notCentered == 0) {
        camera_update();
        objectCenter = get_object_center_x(blueChannel, firstObject);
        imageCenter = 80;
        if (objectCenter < imageCenter) {
            while (inRange(imageCenter, objectCenter) == 1) {
                camera_update();
                objectCenter = get_object_center_x(blueChannel, firstObject);
                printf("\nThe Wallaby detected the object center as: %d", objectCenter);
                printf("\nThe Wallaby detected the image center as: %d", imageCenter); 
                create_drive_direct(-200, 200);
                msleep(750);
                create_stop();
                msleep(1);
            }
            notCentered = 1;
            create_stop();
            create_drive_direct(200, 200);
            if ((get_create_lbump() == 1) || (get_create_rbump() == 1)) {
                create_stop();
            }
        }
        else if (objectCenter > imageCenter) {
            while (inRange(imageCenter, objectCenter) == 1) {
                camera_update();
                objectCenter = get_object_center_x(blueChannel, firstObject);
                create_drive_direct(200, -200);
                msleep(750);
                create_stop();
                msleep(1);
            }
            notCentered = 1;
            create_stop();
            create_drive_direct(200, 200);
            if ((get_create_lbump() == 1) || (get_create_rbump() == 1)) {
                create_stop();
            }
            
        } else {
            printf("\nThe Wallaby thought the image center was: %d", imageCenter);
            printf("\nThe object center was detected as: %d", objectCenter);
            create_drive_direct(-200, 200);
        }
        create_disconnect();
    }
        return 0;
    }
