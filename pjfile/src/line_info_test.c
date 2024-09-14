#include "basis.h"

void line_info_test(l_p head)
{
    li_n p;
    l_p q = head->next;
    p = get_line_info(q);
    printf("线路编号：%s 终点站：%s 等待时间：%d分钟 站点编号：%d\n", p.line_num, p.dest_sta, p.wait_time, p.stop_posi);
    return;
}