#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
extern "C" {
    #include <Python.h>
}
*/
#include <Python.h>

PyObject* pyrev(PyObject* self, PyObject* str1)
{
    
    char* str2;
    //if (!PyArg_ParseTuple(str1, "s",  &str1))  <== Here was the error. Dafaq!
    if (!PyArg_ParseTuple(str1, "s",  &str2))
    {
        return NULL;
    }
    printf("%s %d \n", str2, strlen(str2)); // PyArg_ParseTuple sets the value. i.e. Parses.
    
    /*
     * PyString_AsString documentation says: "The pointer refers to the internal buffer of string, not a copy. 
     * The data must not be modified in any way, 
     * unless the string was just created using PyString_FromStringAndSize(NULL, size). It must not be deallocated."
     * Please ensure you do not deallocate this buffer
     * http://stackoverflow.com/questions/8749842/sporadic-segfault-in-c-python-extension
    */

    /*PyString_AsString returns a pointer to the internal buffer of the
     * python string. If you want to be able to free() it (or indeed have it
     * exist for beyond the lifetime of the associated python string), you
     * need to malloc() memory and strcpy() the data. If the strings contain
     * binary data, you should be using PyString_AsStringAndSize. see
     * http://docs.python.org/api/stringObjects.html.
     */
    
    int len;
    for (len=0; *str2!=NULL; str2++)
    {
        printf("%c %p\n",*str2, str2);
        len+=1;
    }
    printf("%d\n",len);
    str2-=len;
    
    char* str3 = (char *)malloc((len+1)*sizeof(char));
    str3+=len;
    *str3 = NULL;
    str3--;
    for (;*str2!=NULL; ++str2, str3--)
    {
        *str3 = *str2;
        //printf("%c %p\n",*str2, str2);
        //printf("%c %p\n",*str3, str3);
    }
    str3++;
    
    return Py_BuildValue("s", str3);
}

PyMethodDef methods[] = {
  {"pyrev",(PyCFunction)pyrev, METH_VARARGS, NULL},
  {NULL, NULL,0,NULL},
};

void initpyrev(void)
{
    Py_InitModule3("pyrev", methods,
                   "Extension module example!");
}

