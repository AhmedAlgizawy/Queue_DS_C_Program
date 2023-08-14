#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdlib.h>
#include"Platform_Types.h"

typedef struct{
    void **QueueArr  ;  /*Pointer to Array of void pointers*/
    uint32 QueueSize ;
    uint32 QueueCount;
    sint32 QueueFront;
    sint32 QueueRear ;
}Queue_t;

typedef enum{
    QUEUE_NOK,
    QUEUE_OK,
    QUEUE_FULL,
    QUEUE_EMPTY,
    QUEUE_NULL_PASSED
}ret_status_t;

/**@brief Create queue object in the heap to hold the queue information.
  *@param (MaxSize) Number of void pointer elements.
  *@param (Status) Status of Function operation.
  *@retval Return address of head of queue list.
  */
Queue_t *CreatQueue(uint32 MaxSize , ret_status_t *Status);

/**@brief Add Element to queue list.
  *@param (My_Queue) address of head of queue list.
  *@param (Data) data will be Add to queue list.
  *@retval Status of Function operation.
  */
ret_status_t EnqueueElement(Queue_t *My_Queue , void *Data);

/**@brief Remove Element to queue list.
  *@param (My_Queue) address of head of queue list.
  *@param (Status) Status of Function operation.
  *@retval Return address of removed data.
  */
void *DequeueElement(Queue_t *My_Queue , ret_status_t *Status);

/**@brief View front Element in queue list.
  *@param (My_Queue) address of head of queue list.
  *@param (Status) Status of Function operation.
  *@retval Return address of front element.
  */
void *QueueFront(Queue_t *My_Queue , ret_status_t *Status);

/**@brief View rear Element in queue list.
  *@param (My_Queue) address of head of queue list.
  *@param (Status) Status of Function operation.
  *@retval Return address of rear element.
  */
void *QueueRear(Queue_t *My_Queue , ret_status_t *Status);

/**@brief View number of Element in queue list.
  *@param (My_Queue) address of head of queue list.
  *@param (Q_Count) address of Number of element.
  *@retval Status of Function operation.
  */
ret_status_t GetQueueCount(Queue_t *My_Queue , uint32 *Q_Count);

/**@brief Destroy queue object in the heap.
  *@param (My_Queue) address of head of queue list.
  *@retval Status of Function operation.
  */
ret_status_t DestroyQueue(Queue_t **My_Queue);

#endif // _QUEUE_H_
