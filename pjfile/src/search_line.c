#include "basis.h"

void show_lines(l_p head){
    if (head->next == head){
        printf("The list is empty\n");
        return;
    }
    for (l_p p = head->next; p != head; p = p->next)
    {
        printf("线路号：%s\n首班车时间：%d时 末班车时间：%d时\n", p->line_num, p->start_time, p->end_time);
        printf("车站信息：\n");
        show_stops(p->Shead);
        printf("车辆信息：\n");
        show_buses(p->Bhead);
        
    }
    // line_info_test(head);
    show_line_info(head);
    return;
}

void show_stops(s_p head){
    if (head->next == head)
    {
        printf("The list is empty\n");
        return;
    }
    for (s_p p = head->next; p != head; p = p->next)
    {
        // printf("站点编号：%d 站点名：%s 距离上站时间：%d\n", p->stop_num, p->stop_name, p->last_stop_time);
    }
    return;
}

void show_buses(b_p head){
    if (head->next == head)
    {
        printf("The list is empty\n");
        return;
    }
    for (b_p p = head->next; p != head; p = p->next)
    {
        // printf("巴士编号：%s 巴士当前位置：%s\n", p->bus_num, p->bus_posi);
    }
    return;
}

l_p search_line(l_p head, char line_num[10]){
    l_p p = head;
    for (; p->next != head; p = p->next)
    {
        if (strcmp(p->line_num, line_num) == 0)
        {
            return p;
        }
        
    }
    printf("该线路未找到！\n");
    return NULL;
}