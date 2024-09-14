#include "basis.h"

void add_lines_node(l_p head, char line_num[10], int start_time, int end_time){
    l_p new_node = malloc(sizeof(l_n));
    if (new_node == NULL)
    {
        perror("Line_node add error");
        return;
    }
    
    l_p p = head;
    for (; p->next != head; p = p->next);
    strcpy(new_node->line_num, line_num);
    new_node->start_time = start_time;
    new_node->end_time = end_time;

    new_node->Shead = stops_init();
    if (new_node->Shead == NULL)
    {
        perror("Stops_node init error");
        return;
    }
    
    new_node->Bhead = buses_init();
    if (new_node->Bhead == NULL)
    {
        perror("Buses_node init error");
        return;
    }
    
    p->next = new_node;
    new_node->next = head;
    new_node->prev = p;
    return;
}

void add_stops_node(s_p head, int stop_num, char stop_name [20], int last_stop_time){
    s_p new_node = malloc(sizeof(s_n));
    if (new_node == NULL)
    {
        perror("Stops_node add error");
        return;
    }

    s_p p = head;
    for (; p->next != head; p = p->next);
    new_node->stop_num = stop_num;
    strcpy(new_node->stop_name, stop_name);
    new_node->last_stop_time = last_stop_time;
    p->next = new_node;
    new_node->next = head;
    return;
}

void add_buses_node(b_p head, char bus_num [20], char bus_posi [20], int stop_num){
    b_p new_node = malloc(sizeof(b_n));
    if (new_node == NULL)
    {
        perror("Buses_node add error");
        return;
    }
    
    b_p p = head;
    for (; p->next != head; p = p->next);
    strcpy(new_node->bus_num, bus_num);
    strcpy(new_node->bus_posi, bus_posi);
    p->stop_num = stop_num;
    p->next = new_node;
    new_node->next = head;
    return;
}