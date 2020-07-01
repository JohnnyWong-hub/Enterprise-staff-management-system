#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct employee
{
    int num;
    char duty[10];
    char name[10];
    char sex[3];
    unsigned char age;
    char edu[10];
    int salary;
    char tel_fooice[10];
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
}

void search(EMP *p) 
{

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
    EMP *q = p->next;
    while (q)
    {
        p = q->next;
        free(q);
        q = p->next;
    }
    free(p);
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
