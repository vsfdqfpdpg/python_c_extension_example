#include <Python.h>

int Fibonacci(int n) {
    if (n < 2) {
        return n;
    } else {
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}

static PyObject *fib(PyObject *self, PyObject *args) {
    int n;
    if (!PyArg_ParseTuple(args, "i", &n)) {
        return NULL;
    }
    return Py_BuildValue("i", Fibonacci(n));
}

static PyObject *version(PyObject *self) {
    return Py_BuildValue("s", "Version 1.0");
}

static PyMethodDef myMethods[] = {
        {"fib",     fib,                   METH_VARARGS, "Calculate the Fibonacci numbers."},
        {"version", (PyCFunction) version, METH_NOARGS,  "Returns the version."},
        {NULL, NULL, 0, NULL}
};

static struct PyModuleDef myModule = {
        PyModuleDef_HEAD_INIT,
        "happy",
        "Fibonacci Module",
        -1,
        myMethods
};

PyMODINIT_FUNC PyInit_happy(void) {
    return PyModule_Create(&myModule);
}

int main(int argc, char *argv[]) {
    PyImport_AppendInittab("happy", PyInit_happy);
    Py_Initialize();
    return 0;
}
