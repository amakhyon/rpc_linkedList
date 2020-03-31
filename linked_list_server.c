/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "linked_list.h"
#include "data_structures.h"

node *
sortlinkedlist_1_svc(node *unsorted, struct svc_req *rqstp)
{
	static node  *sorted;
    int *array = listToArray(unsorted);
    int count = countNodes(unsorted);
    array = sortArray(array,count);
    sorted = arrayToList(array,count);

    
	return sorted;
}
