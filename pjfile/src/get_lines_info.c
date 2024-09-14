#include "basis.h"

li_n get_line_info(l_p p)
{
    li_n new;
    s_p des = p->Shead->next;
    for (; des->next != p->Shead; des = des->next);
    strcpy(new.dest_sta, des->stop_name);
    strcpy(new.line_num, p->line_num);

    s_p get_stop_posi = p->Shead->next;
    for (; get_stop_posi->next != p->Shead; get_stop_posi = get_stop_posi->next)
    {
        if (strcmp(get_stop_posi->stop_name, this_stop) == 0)
        {
            new.stop_posi = get_stop_posi->stop_num;
        }
        
    }

    b_p bus_posi = p->Bhead;
    b_p bus_posi1 = p->Bhead;
    int stop_num_temp;
    int total_time = 0;
    for (; bus_posi1->next != p->Bhead; bus_posi1 = bus_posi1->next)
    {
        if(bus_posi1->stop_num > new.stop_posi)
        {
            break;
        }
    }
    for (; bus_posi != bus_posi1; bus_posi = bus_posi->next)
    {
        stop_num_temp = bus_posi->stop_num;
    }
    s_p get_time = p->Shead->next;
    for (; get_time->next != p->Shead; get_time = get_time->next)
    {
        if (get_time->stop_num > stop_num_temp && get_time->stop_num <= new.stop_posi)
        {
            total_time += get_time->last_stop_time;
        }
    }
    new.wait_time = total_time;

    return new;
}