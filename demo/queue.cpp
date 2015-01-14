#include <stdio.h>
#include "memtable.h"
#include "config.h"


enum {A, B, C, D};



int main()
{
    if (!tinytable::MemTable::tinytable_init(true)) {
        printf("tinytable global init error\n");
        return -1;
    }
    tinytable::MemTable table;
    if (0 != table.init("./conf", "tableid.conf", "./conf")) {
        printf("init tinytable error\n");
        return -1;
    }
    // ����3������
    table.insert("queue", 0, 0, "1", 4);
    table.insert("queue", 0, 0, "1", 4);
    table.insert("queue", 0, 1, "1", 4);
    SingleTable::real_iterator iter;
    SingleTable::real_iterator end;
    // ��ȡȫ����queue
    iter = table.queue_begin("queue");
    end = table.queue_end("queue");
    printf("print all queue\n");
    for (; iter != end; ++iter) {
        printf("A %d\n", iter->get<int>(A));
    }
    printf("printf all queue over\n");
 
    // ����4������
    table.insert("queue", 0, 0, "1", 4);
    table.insert("queue", 0, 0, "1", 4);
    table.insert("queue", 0, 1, "1", 4);
    // ��ȡȫ����queue����
    iter = table.queue_begin("queue");
    end = table.queue_end("queue");
    printf("print all queue\n");
    for (; iter != end; ++iter) {
        printf("A %d\n", iter->get<int>(A));
    }
    printf("printf all queue over\n");
    return 0;
}
