#include "basis.h"

void *show_memu_icon(){
    while (1)
    {
        while (main_flag == false)
        {
            /* code */
        }
        show_pic("lines.bmp", 600 ,320, false, false);
        show_pic("more_info.bmp", 600, 400, false, false);
        sleep(1);
        while (main_flag)
        {
            /* code */
        }
        
    }
    return NULL;
}