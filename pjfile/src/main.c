#include "basis.h"

int main(){
    touch_flag = true;
    main_flag = true;
    main_flag1 = true;
    line_flag = false;
    l_p head1 = line_init();
    if (head1 == NULL)
    {
        perror("init node failed");
    }
    add_lines_node(head1, "11", 6, 22);
    add_lines_node(head1, "1", 6 ,20);
    add_lines_node(head1, "2", 7, 21);
    add_lines_node(head1, "3", 7, 21);
    add_lines_node(head1, "4", 7, 21);
    add_info(head1);
    strcpy(this_stop, "人民大道南");
    int choice = 0;
    printf("1.链表操作 2.页面显示 3.搜索demo\n");
    scanf("%d", &choice);
    
    switch (choice)
    {
    case 1:
    {
        pthread_create(&t_tid,NULL,t,NULL);
        pthread_join(t_tid,NULL);
    };break;
    case 2:
    {
        pthread_create(&show_news_tid,NULL,show_memu_icon,NULL);
        pthread_create(&show_time_tid,NULL,show_time,NULL);
        pthread_create(&touch_tid,NULL,touch,NULL);
        pthread_create(&show_news_tid,NULL,show_news,NULL);
        pthread_create(&show_title_tid,NULL,show_title,NULL);
        pthread_create(&show_weather_tid,NULL,show_weather,NULL);
        pthread_create(&show_adv_tid,NULL,show_adv,NULL);
        pthread_create(&touch_sc_tid,NULL,touch_sc,NULL);
        pthread_create(&line_touch_tid,NULL,line_touch_p,NULL);
        pthread_create(&t_tid,NULL,t,NULL);
        pthread_join(t_tid,NULL);
    }
    break;
    case 3:
    {
        // pthread_create(&touch_sc_tid,NULL,touch_sc,NULL);
        // pthread_create(&t_tid,NULL,t,NULL);
        pthread_create(&line_touch_tid,NULL,line_touch_p,NULL);\
        pthread_create(&t_tid,NULL,t,NULL);
        pthread_join(t_tid,NULL);
    }
    break;
    default:
        break;
    }
    return 0;
}