#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100
#define INCREASE_SIZE 10
/* 实现数据结构之栈 sqstack
   对栈初始化 initial
   栈顶插入新的元素 push
   返回栈顶元素 get_top
   删除栈顶元素 pop
*/
typedef struct
{
     int *top;
     int *base;
     int stacksize;
}sqstack;
void initial(sqstack *s);
void push(sqstack *s,int i);
void get_top(sqstack *s,int *e);
void pop(sqstack *s,int *e);
int main()
{
     sqstack s;
     int e,i;
     initial(&s);
     for(i=0;i<16;i++)
     {
          push(&s,i);
     }
     get_top(&s,&e);
     printf("%d ",e);
     while(s.base!=s.top)
     {
          pop(&s,&e);
          printf("%d ",e);
     }
     return 0;
}

void initial(sqstack *s)
{
      s->base = (int*)malloc(sizeof(int)*STACK_INIT_SIZE);
      s->top = s->base;
      s->stacksize = STACK_INIT_SIZE;
} //初始化栈

void push(sqstack *s,int i)
{
     if(s->top-s->base>=s->stacksize)
     {
          s->base = (int*)realloc(s->base,sizeof(int)*INCREASE_SIZE);
          s->top = s->base+s->stacksize; // 将栈顶指针调整至新的栈顶位置(扩展内存后地址会出现变化)
          s->stacksize += INCREASE_SIZE;
     }
     *s->top = i;
     s->top++;
} //压栈

void get_top(sqstack *s,int *e)
{
     if(s->top==s->base){exit(EXIT_FAILURE);} // 检查栈是否为空
     *e = *(s->top-1);
} //得到栈顶元素

void pop(sqstack *s,int *e)
{
     if(s->top==s->base){exit(EXIT_FAILURE);} // 检查栈是否为空
     *e = *--s->top;
}
