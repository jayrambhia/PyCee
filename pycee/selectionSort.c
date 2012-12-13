#include <Python.h>
#include <stdio.h>
#include <stdlib.h>

PyObject* py_selectionSort(PyObject* self, PyObject* args)
{
    PyObject* list;
    PyObject* list_item;
    Py_ssize_t i, len;
    long item;
    int j,k;

    if (!PyArg_ParseTuple(args, "O", &list))
    {
        printf("Not a list\n");
        return NULL;
    }
    
    len = PyList_Size(list);
    long* list_array = (long*) malloc(len*(sizeof(long)));
    
    /* create array from list */
    for(i=0; i<len; i++)
    {
        list_item = PyList_GetItem(list, i);
        if PyInt_Check(list_item)
        {
            *list_array = PyInt_AsLong(list_item);
            list_array++;
        }
        Py_DECREF(list_item);
    }
    list_array-=len;    // do this else get core dumped
    
    /* soriting */
    int min = *list_array;
    int index = 0;
    int l;
    int min_element, temp_element;
    for (j=0; j<len; j++)
    {
        list_array+=j;
        min = *list_array;
        index = j;
        for (k=j; k<len; k++)
        {
            if (*list_array < min)
            {
                min = *list_array;
                index = k;
            }
            list_array++;
        }
        list_array = list_array - len;
        if (index != j)
        {
            temp_element = *(list_array + j);
            *(list_array + j) = *(list_array+ index);
            *(list_array + index) = temp_element;
        }
    }
    
    /* create list from sorted array */
    PyObject* flist = PyList_New(len);
    for (i=0; i<len; i++)
    {
        list_item = PyInt_FromLong(*list_array);
        PyList_SetItem(flist, i, list_item);
        list_array++;
        //Py_DECREF(list_item); /* PyList_SetItem steals the reference */
    }
    list_array-=len;
    free(list_array);
    
    /* list is an object we pull out of the args with PyArg_ParseTuple. 
     * Since args is borrowed, we can borrow value out of it, 
     * so numbers is also borrowed. */
    //Py_DECREF(list);
    return flist;
}
            
PyMethodDef methods[] = {
  {"selectionSort",(PyCFunction)py_selectionSort, METH_VARARGS, NULL},
  {NULL, NULL,0,NULL},
};

PyMODINIT_FUNC initselectionSort(void)
{
    Py_InitModule3("selectionSort", methods,
                   "Extension module example!");
}
