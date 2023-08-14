#include <stdio.h>
#include <stdlib.h>
#include"Queue.h"

Queue_t *Queue_1=NULL;
void *Element = NULL ;
uint32 Num_Of_Elem;
uint32 Count = 0 ;

uint32 Num1 = 11 ;
uint32 Num2 = 22 ;
uint32 Num3 = 33 ;

int main()
{
    ret_status_t Ret = QUEUE_NOK ;

    printf("Enter Number of Element : ");
    scanf("%i",&Num_Of_Elem);

    printf("Queue 1 Add = 0x%X\n",Queue_1);
    Queue_1 = CreatQueue(Num_Of_Elem,&Ret); printf("Return status = %i \n",Ret);
    if (Queue_1)
    {
        printf("Queue List is created !!\n");
    }
    printf("Queue 1 Add = 0x%X\n",Queue_1);
    printf("====================================\n");
    Ret = EnqueueElement(Queue_1,&Num1); printf("Return status = %i \n",Ret);
    Ret = EnqueueElement(Queue_1,&Num2); printf("Return status = %i \n",Ret);
    Ret = EnqueueElement(Queue_1,&Num3); printf("Return status = %i \n",Ret);
    Ret = EnqueueElement(Queue_1,&Num3); printf("Return status = %i \n",Ret);

    printf("====================================\n");
    Element = QueueFront(Queue_1,&Ret);
    printf("Front element = %i \t Return status = %i \n",*((uint32 *)Element),Ret);
    Element = QueueRear(Queue_1,&Ret);
    printf("Rear element = %i \t Return status = %i \n",*((uint32 *)Element),Ret);
    printf("====================================\n");

    Element = DequeueElement(Queue_1,&Ret);
    printf("Popped for element = %i \t Return status = %i \n",*((uint32 *)Element),Ret);

    Ret = GetQueueCount(Queue_1,&Count);
    printf("Queue Count = %i \t Return status = %i \n",Count,Ret);

    Element = DequeueElement(Queue_1,&Ret);
    printf("Popped for element = %i \t Return status = %i \n",*((uint32 *)Element),Ret);
    printf("====================================\n");
    Element = QueueFront(Queue_1,&Ret);
    printf("Front element = %i \t Return status = %i \n",*((uint32 *)Element),Ret);
    Element = QueueRear(Queue_1,&Ret);
    printf("Rear element = %i \t Return status = %i \n",*((uint32 *)Element),Ret);
    Ret = GetQueueCount(Queue_1,&Count);
    printf("Queue Count = %i \t Return status = %i \n",Count,Ret);
    printf("====================================\n");
    Element = DequeueElement(Queue_1,&Ret);
    printf("Popped for element = %i \t Return status = %i \n",*((uint32 *)Element),Ret);
    Element = DequeueElement(Queue_1,&Ret); printf("Return status = %i \n",Ret);
    printf("====================================\n");
    Element = QueueFront(Queue_1,&Ret); printf("Return status = %i \n",Ret);
    Element = QueueRear(Queue_1,&Ret); printf("Return status = %i \n",Ret);
    Ret = GetQueueCount(Queue_1,&Count);
    printf("Queue Count = %i \t Return status = %i \n",Count,Ret);

    printf("====================================\n");

    Ret = DestroyQueue(&Queue_1); printf("Return status = %i \n",Ret);

    if (!Queue_1)
    {
        printf("Queue List is destroyed !!\n");
    }

    printf("Queue 1 Add = 0x%X\n",Queue_1);
    return 0;
}
