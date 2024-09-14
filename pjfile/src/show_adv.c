#include "basis.h"

void *show_adv(){
    while (main_flag == false)
    {
        /* code */
    }
    printf("show_adv\n");
    char name [5][20] = {"add-3.bmp", "add-4.bmp", "add-5.bmp", "add-6.bmp", "add-7.bmp"};
    while (1)
    {
        if (main_flag == false)
        {
            
        }
        
        for (int i = 0; i < 5; i++)
    {
        // printf("show_adv: %d\n", i);
        // printf("touch_flag: %d\n", touch_flag);
        if (main_flag == false)
        {
            break;
        }
        if (touch_flag)
        {
            char *n1 = name[i];
            int posi_y = 59;
            // printf("show_adv: %d\n", i);
            sleep(1);
            show_pic(n1, 0, 59, true, true);
        }

        else
        {
            set_lines();
            if (main_flag == false)
            {
                break;
            }
            while (touch_flag == false)
            {
                
            }
            
        }
        
        if (i + 1 == 5)
        {
            i = -1;
        }
    }
    }
    
}

void *show_search_bg(){
    while (1)
    {
        while (main_flag == false)
        {
            
        }
        
        char *name = "line_search.bmp";
        show_pic(name, 0, 0, false, false);
    }
    
}