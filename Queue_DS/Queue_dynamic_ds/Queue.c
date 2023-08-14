#include"Queue.h"

static ret_status_t Queue_Full (Queue_t *My_Queue)
{
    if (My_Queue->QueueCount == My_Queue->QueueSize)
        return QUEUE_FULL ;
    else
        return QUEUE_OK;
}

static ret_status_t Queue_Empty (Queue_t *My_Queue)
{
    if (My_Queue->QueueCount == ZERO )
        return QUEUE_EMPTY ;
    else
        return QUEUE_OK;
}

Queue_t *CreatQueue(uint32 MaxSize , ret_status_t *Status)
{
    Queue_t *My_Queue = NULL ;
    /*Create queue object in the heap to hold the queue information*/
    My_Queue = (Queue_t *)malloc(sizeof(Queue_t));

    if (!My_Queue)
    {
        My_Queue = NULL;
        *Status=QUEUE_NOK;
    }
    else
    {
        /*Create array of void pointer to hold the address of queue data*/
        My_Queue->QueueArr   = (void **)calloc(MaxSize ,sizeof(void *));

        if (!My_Queue->QueueArr)
        {
            free(My_Queue);
            My_Queue = NULL;
            *Status=QUEUE_NOK;
        }
        else
        {
            My_Queue->QueueCount =  0;
            My_Queue->QueueFront = -1;
            My_Queue->QueueRear  = -1;
            My_Queue->QueueSize  = MaxSize ;

            *Status=QUEUE_OK;
        }
    }
    return My_Queue;
}

ret_status_t EnqueueElement(Queue_t *My_Queue , void *Data)
{
    ret_status_t ret = QUEUE_NOK ;

    if ((NULL == My_Queue) || (NULL == Data))
    {
        ret = QUEUE_NULL_PASSED;
    }
    else
    {
        if (Queue_Full(My_Queue) == QUEUE_FULL)
        {
            printf("Queue is full !!\n");
            ret = QUEUE_FULL;
        }
        else
        {
            (My_Queue->QueueRear)++;
            if (My_Queue->QueueRear == My_Queue->QueueSize)
            {
                My_Queue->QueueRear = ZERO ;
            }

            My_Queue->QueueArr[My_Queue->QueueRear] = Data ;
            if ( My_Queue->QueueCount == ZERO )
            {
                (My_Queue->QueueFront)++;
            }
            My_Queue->QueueCount++ ;

            printf("Enqueue is successfully. \n");
            ret = QUEUE_OK ;
        }
    }
    return ret ;
}

void *DequeueElement(Queue_t *My_Queue , ret_status_t *Status)
{
    void *Data = NULL;

    if ((NULL == My_Queue) || (NULL == Status))
    {
        *Status = QUEUE_NULL_PASSED;
    }
    else
    {
        if (Queue_Empty(My_Queue)==QUEUE_EMPTY)
        {
            printf("Queue is empty !!\n");
            *Status = QUEUE_EMPTY;
        }
        else
        {
            Data = My_Queue->QueueArr[My_Queue->QueueFront];
            (My_Queue->QueueFront)++;

            if (My_Queue->QueueFront == My_Queue->QueueSize)
            {
                My_Queue->QueueFront = ZERO ;
            }

            (My_Queue->QueueCount)--;

            if (My_Queue->QueueCount==0)
            {
                My_Queue->QueueFront = -1 ;
                My_Queue->QueueRear  = -1 ;
            }

            *Status = QUEUE_OK;
        }
    }
    return Data;
}

void *QueueFront(Queue_t *My_Queue , ret_status_t *Status)
{
    void *Data = NULL;

    if ((NULL == My_Queue) || (NULL == Status))
    {
        *Status = QUEUE_NULL_PASSED;
    }
    else
    {
        if (Queue_Empty(My_Queue)==QUEUE_EMPTY)
        {
            printf("Queue is empty !!\n");
            *Status = QUEUE_EMPTY;
        }
        else
        {
            Data = My_Queue->QueueArr[My_Queue->QueueFront];
            *Status = QUEUE_OK;
        }
    }
    return Data;
}

void *QueueRear(Queue_t *My_Queue , ret_status_t *Status)
{
    void *Data = NULL;

    if ((NULL == My_Queue) || (NULL == Status))
    {
        *Status = QUEUE_NULL_PASSED;
    }
    else
    {
        if (Queue_Empty(My_Queue)==QUEUE_EMPTY)
        {
            printf("Queue is empty !!\n");
            *Status = QUEUE_EMPTY;
        }
        else
        {
            Data = My_Queue->QueueArr[My_Queue->QueueRear];
            *Status = QUEUE_OK;
        }
    }
    return Data;
}

ret_status_t GetQueueCount(Queue_t *My_Queue , uint32 *Q_Count)
{
    ret_status_t ret = QUEUE_NOK ;
    if ((NULL == My_Queue) || (NULL == Q_Count))
    {
        ret = QUEUE_NULL_PASSED;
    }
    else
    {
        if (Queue_Empty(My_Queue)==QUEUE_EMPTY)
        {
            printf("Queue is empty !!\n");
            *Q_Count = ZERO ;
            ret = QUEUE_EMPTY;
        }
        else
        {
            *Q_Count = My_Queue->QueueCount;
            ret = QUEUE_OK;
        }
    }
    return ret ;
}

ret_status_t DestroyQueue(Queue_t **My_Queue)
{
    Queue_t *Temp = *My_Queue; /*To free the location of queue list*/

    ret_status_t ret = QUEUE_NOK ;
    if ((NULL == My_Queue))
    {
        ret = QUEUE_NULL_PASSED;
    }
    else
    {
        free(Temp->QueueArr);
        free(Temp);

        *My_Queue=NULL;
        Temp=NULL;
        ret = QUEUE_OK;
    }
    return ret ;
}
