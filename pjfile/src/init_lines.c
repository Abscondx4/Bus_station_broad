#include "basis.h"

l_p line_init(){
    l_p head = malloc(sizeof(l_n));
    if (head == NULL)
    {
        perror("Line_node init error");
        return NULL;
    }
    
    head->next = head;
    head->prev = head;
    head->Shead = stops_init();
    if (head->Shead == NULL)
    {
        perror("Stops_node init error");
        return NULL;
    }

    head->Bhead = buses_init();
    if (head->Bhead == NULL)
    {
        perror("Buses_node init error");
        return NULL;
    }
    
    return head;
}

s_p stops_init(){
    s_p head = malloc(sizeof(s_n));
    if (head == NULL)
    {
        perror("Stops_node init error");
        return NULL;
    }
    head->next = head;
    return head;
}

b_p buses_init(){
    b_p head = malloc(sizeof(b_n));
    if (head == NULL)
    {
        perror("Buses_node init error");
        return NULL;
    }
    head->next = head;
    return head;
}