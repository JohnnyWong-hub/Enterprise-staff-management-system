#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct employee
{
    int num;
    char duty[10];
    char name[10];
    char sex[3];
    unsigned int age;
    char edu[10];
    int salary;
    char tel_phone[10];
    char mobile[13];
    char qq[11];
    char address[31];
    struct employee *next;
} EMP;

void systeminit();
int menu();
void insert(EMP *p);
void search(EMP *p);
void list(EMP *p);
void change(EMP *p);
void delete (EMP *p);
void according(EMP *p);
void reset(EMP *p);
void destory(EMP *p);
void stringput(EMP *p);
//系统密码初始化,超级管理员系统
void systeminit()
{
    FILE *fp;
    char buf[9];
    char pass[9];
    //以读写追加的方式打开密码文件
    if ((fp = fopen("./mypasswd", "rb+")) == 0)
    {
        printf("Init failed system shutdown\n");
        exit(-1);
    }

    //读取密码若不为8位则输入密码，否则正常进入系统
    fscanf(fp, "%s", buf);
    if (strlen(buf) != 8)
    {
        printf("\t*************************************\n");
        printf("\tNew system please input the password:");
        fgets(pass, 9, stdin);
        fprintf(fp, "%s", pass);
    }
    else
    {
        printf("\tsystem normal:\n");
        printf("\tplease input the passed:");
        scanf("%s", pass);
        if (strcmp(buf, pass) != 0)
        {
            printf("Password error.\n");
            fclose(fp);
            exit(1);
        }
    }
    fclose(fp);
}

int menu()
{
    int x = 0;
    printf("                         企业员工管理系统                     \n");
    printf("            ------------------------------------           \n");
    printf("            |                                  |\n");
    printf("            |         1.输入员工信息             |\n");
    printf("            |         2.查询员工信息             |\n");
    printf("            |         3.显示员工信息             |\n");
    printf("            |         4.修改员工信息             |\n");
    printf("            |         5.删除员工信息             |\n");
    printf("            |         6.统计员工信息             |\n");
    printf("            |         7.重置员工信息             |\n");
    printf("            |         0.退出系统                |\n");
    printf("            ------------------------------------           \n");
    printf("            请输入您需要的操作:");
    fscanf(stdin, "%d", &x);
    return x;
}

void insert(EMP *p)
{
    if (NULL == p)
        return;
    //创建一个员工信息一定要分配空间
    int x = 0;
    EMP *q = NULL;
    while (1)
    {
        q = (EMP *)malloc(sizeof(EMP));
        if (NULL == q)
        {
            printf("malloc failed\n");
            destory(p);
            exit(1);
        }
        printf("please input the employee's num, -1 to exit\n");
        scanf("%d", &x);
        while (getchar() != '\n')
            ;
        if (x == -1)
        {
            free(q);
            break;
        }
        q->num = x;
        printf("please input the employee's duty:");
        scanf("%s", q->duty);
        while (getchar() != '\n')
            ;

        printf("please input the employee's name:");
        scanf("%s", q->name);
        while (getchar() != '\n')
            ;

        printf("please input the employee's sex:");
        scanf("%s", q->sex);
        while (getchar() != '\n')
            ;

        printf("please input the employee's age:");
        scanf("%d", &q->age);
        while (getchar() != '\n')
            ;

        printf("please input the employee's edu:");
        scanf("%s", q->edu);
        while (getchar() != '\n')
            ;

        printf("please input the employee's salary:");
        scanf("%d", &q->salary);
        while (getchar() != '\n')
            ;

        printf("please input the employee's telphone:");
        scanf("%s", q->tel_phone);
        while (getchar() != '\n')
            ;

        printf("please input the employee's moblie:");
        scanf("%s", q->mobile);
        while (getchar() != '\n')
            ;

        printf("please input the employee's qq:");
        scanf("%s", q->qq);
        while (getchar() != '\n')
            ;

        printf("please input the employee's address:");
        scanf("%s", q->address);
        while (getchar() != '\n')
            ;

        q->next = p->next;
        p->next = q;
    }
}

void search(EMP *p)
{
    if (NULL == p)
        return;
    int x = 0;
    EMP *q = p->next;
    printf("Please input the number of employee you want to search:");
    scanf("%d", &x);
    while (getchar() != '\n')
        ;

    while (q)
    {
        if (q->num == x)
        {
            stringput(q);
            break;
        }
        q = q->next;
    }
}

void list(EMP *p)
{
}

void change(EMP *p)
{
}

void delete (EMP *p)
{
}

void according(EMP *p)
{
}

void reset(EMP *p)
{
}

void destory(EMP *p)
{
    if (NULL == p)
        return;
    EMP *q,*f;
    f = p;
    q = p->next;

    while (q)
    {
       f->next = q->next;
       free(q);
       q = f->next; 
    }
    free(f);
    f = NULL;
}

void stringput(EMP *p)
{
    printf("|num:%d  |duty:%s  |name:%s  |sex:%s  |age:%d  |edu:%s  |salary:%d  |tel_phone:%s  |moblie:%s  |qq:%s  |address:%s  |\n",
           p->num,
           p->duty,
           p->name,
           p->sex,
           p->age,
           p->edu,
           p->salary,
           p->tel_phone,
           p->mobile,
           p->qq,
           p->address);
}

int main(int argc, char const *argv[])
{
    systeminit();
    EMP *p = NULL;
    p = (EMP *)malloc(sizeof(EMP));

    if (NULL == p)
    {
        printf("malloc failed\n");
        exit(-1);
    }

    while (1)
    {
        switch (menu())
        {
        case 1:
            insert(p);
            break;
        case 2:
            search(p);
            break;
        case 3:
            list(p);
            break;
        case 4:
            change(p);
            break;
        case 5:
            delete (p);
            break;
        case 6:
            according(p);
            break;
        case 7:
            reset(p);
            break;
        case 0:
            destory(p);
            exit(1);
        }
    }
    return 0;
}
