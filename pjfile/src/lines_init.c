#include "basis.h"

void set_lines(){
    l_p head = line_init();
    if (head == NULL)
    {
        perror("init node failed");
        return;
    }
    add_lines_node(head, "11", 6, 22);
    add_lines_node(head, "1", 6 ,20);
    add_lines_node(head, "2", 7, 21);
    add_lines_node(head, "3", 7, 21);
    add_lines_node(head, "4", 7, 21);
    add_info(head);
    printf("初始化成功\n");
    show_lines(head);
    printf("aaaa\n");
}

void add_info(l_p head){
    l_p p = head;
     if (head->next == head){
        printf("The list is empty\n");
        return;
    }

    for (l_p p = head->next; p != head; p = p->next)
    {
        printf("线路号：%s\n首班车时间：%d时 末班车时间：%d时\n", p->line_num, p->start_time, p->end_time);
    }

    // printf("请输入需要操作的路线：\n");
    // int choice;
    // scanf("%d", &choice);
    l_p q = head->next;
    int num1 = 0;
        add_stops_node(q->Shead, 1, "创业路", 0);
        add_stops_node(q->Shead, 2, "海北路东", 5);
        add_stops_node(q->Shead, 3, "海北路西", 3);
        add_stops_node(q->Shead, 4, "人民大道南", 8);
        add_stops_node(q->Shead, 5, "人民大道中", 5);
        add_stops_node(q->Shead, 6, "人民大道北", 6);
        add_buses_node(q->Bhead, "10110", "创业路", 1);
        add_buses_node(q->Bhead, "10111", "人民大道中", 5);
        add_buses_node(q->Bhead, "10112", "人民大道北", 6);
        q = q->next;
        add_stops_node(q->Shead, 1, "人和总站", 0);
        add_stops_node(q->Shead, 2, "人和墟站", 8);
        add_stops_node(q->Shead, 3, "人和华侨医院站", 3);
        add_stops_node(q->Shead, 4, "凤和庄站", 8);
        add_stops_node(q->Shead, 5, "人民大道中", 5);
        add_stops_node(q->Shead, 6, "横沥北街口站", 6);
        add_buses_node(q->Bhead, "10110", "人和墟站", 1);
        add_buses_node(q->Bhead, "10111", "人和华侨医院站", 5);
        add_buses_node(q->Bhead, "10112", "横沥北街口站", 6);
        q = q->next;
        add_stops_node(q->Shead, 1, "大运公司站", 0);
        add_stops_node(q->Shead, 2, "邝维煜中学站", 8);
        add_stops_node(q->Shead, 3, "人和华侨医院站", 3);
        add_stops_node(q->Shead, 4, "人爱医院站", 8);
        add_stops_node(q->Shead, 5, "人民大道中", 5);
        add_stops_node(q->Shead, 6, "东华庄站", 6);
        add_buses_node(q->Bhead, "10110", "邝维煜中学站", 1);
        add_buses_node(q->Bhead, "10111", "人和华侨医院站", 5);
        add_buses_node(q->Bhead, "10112", "东华庄站", 6);
        q = q->next;
        add_stops_node(q->Shead, 1, "二沙岛西总站", 0);
        add_stops_node(q->Shead, 2, "大沙头游船码头站", 8);
        add_stops_node(q->Shead, 3, "大沙头站", 3);
        add_stops_node(q->Shead, 4, "江湾桥脚站", 8);
        add_stops_node(q->Shead, 5, "人民大道中", 5);
        add_stops_node(q->Shead, 6, "中山图书馆站", 6);
        add_buses_node(q->Bhead, "10110", "大沙头游船码头站", 1);
        add_buses_node(q->Bhead, "10111", "大沙头站", 5);
        add_buses_node(q->Bhead, "10112", "中山图书馆站", 6);
    // for (l_p q = head->next; q != head; q = q->next)
    // {
        
    //     printf("%d\n", num1);
    //     if (choice == num1)
    //     {
    //         printf("Yes！\n");
    //         add_stops_node(q->Shead, 1, "创业路", 0);
    //         add_stops_node(q->Shead, 2, "海北路东", 5);
    //         add_stops_node(q->Shead, 3, "海北路西", 3);
    //         add_stops_node(q->Shead, 4, "人民大道南", 8);
    //         add_stops_node(q->Shead, 5, "人民大道中", 5);
    //         add_stops_node(q->Shead, 6, "人民大道北", 6);
    //         add_buses_node(q->Bhead, "10110", "创业路", 1);
    //         add_buses_node(q->Bhead, "10111", "人民大道中", 5);
    //         add_buses_node(q->Bhead, "10112", "人民大道北", 6);
    //     }
    //     num1++;
    // }
}

