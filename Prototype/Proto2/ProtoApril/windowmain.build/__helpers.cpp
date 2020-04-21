// This file contains helper functions that are automatically created from
// templates.

#include "nuitka/prelude.h"

extern PyObject *callPythonFunction( PyObject *func, PyObject **args, int count );


PyObject *CALL_FUNCTION_WITH_ARGS1(PyObject *called, PyObject **args) {
    CHECK_OBJECT(called);

    // Check if arguments are valid objects in debug mode.
#ifndef __NUITKA_NO_ASSERT__
    for (size_t i = 0; i < 1; i++)
    {
        CHECK_OBJECT(args[i]);
    }
#endif

    if (Nuitka_Function_Check(called)) {
        if (unlikely(Py_EnterRecursiveCall((char *)" while calling a Python object"))) {
            return NULL;
        }

        struct Nuitka_FunctionObject *function = (struct Nuitka_FunctionObject *)called;
        PyObject *result;

        if (function->m_args_simple && 1 == function->m_args_positional_count){
            for (Py_ssize_t i = 0; i < 1; i++)
            {
                Py_INCREF(args[i]);
            }

            result = function->m_c_code(function, args);
        } else if (function->m_args_simple && 1 + function->m_defaults_given == function->m_args_positional_count) {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca(sizeof(PyObject *) * function->m_args_positional_count);
#else
            PyObject *python_pars[function->m_args_positional_count];
#endif
            memcpy(python_pars, args, 1 * sizeof(PyObject *));
            memcpy(python_pars + 1, &PyTuple_GET_ITEM(function->m_defaults, 0), function->m_defaults_given * sizeof(PyObject *));

            for (Py_ssize_t i = 0; i < function->m_args_positional_count; i++)
            {
                Py_INCREF(python_pars[i]);
            }

            result = function->m_c_code(function, python_pars);
        } else {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca(sizeof(PyObject *) * function->m_args_overall_count);
#else
            PyObject *python_pars[function->m_args_overall_count];
#endif
            memset(python_pars, 0, function->m_args_overall_count * sizeof(PyObject *));

            if (parseArgumentsPos(function, python_pars, args, 1)) {
                result = function->m_c_code(function, python_pars);
            } else {
                result = NULL;
            }
        }

        Py_LeaveRecursiveCall();

        return result;
    } else if (Nuitka_Method_Check(called)) {
        struct Nuitka_MethodObject *method = (struct Nuitka_MethodObject *)called;

        // Unbound method without arguments, let the error path be slow.
        if (method->m_object != NULL)
        {
            if (unlikely(Py_EnterRecursiveCall((char *)" while calling a Python object"))) {
                return NULL;
            }

            struct Nuitka_FunctionObject *function = method->m_function;

            PyObject *result;

            if (function->m_args_simple && 1 + 1 == function->m_args_positional_count) {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca(sizeof(PyObject *) * function->m_args_positional_count);
#else
                PyObject *python_pars[function->m_args_positional_count];
#endif
                python_pars[0] = method->m_object;
                Py_INCREF(method->m_object);

                for (Py_ssize_t i = 0; i < 1; i++) {
                    python_pars[i+1] = args[i];
                    Py_INCREF(args[i]);
                }

                result = function->m_c_code(function, python_pars);
            } else if ( function->m_args_simple && 1 + 1 + function->m_defaults_given == function->m_args_positional_count ) {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca(sizeof(PyObject *) * function->m_args_positional_count);
#else
                PyObject *python_pars[function->m_args_positional_count];
#endif
                python_pars[0] = method->m_object;
                Py_INCREF(method->m_object);

                memcpy(python_pars+1, args, 1 * sizeof(PyObject *));
                memcpy(python_pars+1 + 1, &PyTuple_GET_ITEM(function->m_defaults, 0), function->m_defaults_given * sizeof(PyObject *));

                for (Py_ssize_t i = 1; i < function->m_args_overall_count; i++) {
                    Py_INCREF(python_pars[i]);
                }

                result = function->m_c_code(function, python_pars);
            } else {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca(sizeof(PyObject *) * function->m_args_overall_count);
#else
                PyObject *python_pars[function->m_args_overall_count];
#endif
                memset(python_pars, 0, function->m_args_overall_count * sizeof(PyObject *));

                if (parseArgumentsMethodPos(function, python_pars, method->m_object, args, 1)) {
                    result = function->m_c_code(function, python_pars);
                } else {
                    result = NULL;
                }
            }

            Py_LeaveRecursiveCall();

            return result;
        }
    } else if (PyCFunction_Check(called)) {
        // Try to be fast about wrapping the arguments.
        int flags = PyCFunction_GET_FLAGS(called) & ~(METH_CLASS | METH_STATIC | METH_COEXIST);

        if (flags & METH_NOARGS) {
#if 1 == 0
            PyCFunction method = PyCFunction_GET_FUNCTION(called);
            PyObject *self = PyCFunction_GET_SELF(called);

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely(Py_EnterRecursiveCall((char *)" while calling a Python object"))) {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, NULL );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if (result != NULL) {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            } else {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely(!ERROR_OCCURRED())) {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(
                PyExc_TypeError,
                "%s() takes no arguments (1 given)",
                ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        } else if (flags & METH_O) {
#if 1 == 1
            PyCFunction method = PyCFunction_GET_FUNCTION(called);
            PyObject *self = PyCFunction_GET_SELF(called);

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely(Py_EnterRecursiveCall((char *)" while calling a Python object"))) {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, args[0] );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if (result != NULL) {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            } else {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely(!ERROR_OCCURRED())) {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(PyExc_TypeError,
                "%s() takes exactly one argument (1 given)",
                 ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        } else if (flags & METH_VARARGS) {
            PyCFunction method = PyCFunction_GET_FUNCTION(called);
            PyObject *self = PyCFunction_GET_SELF(called);

            PyObject *pos_args = MAKE_TUPLE(args, 1);

            PyObject *result;

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely(Py_EnterRecursiveCall((char *)" while calling a Python object"))) {
                return NULL;
            }
#endif

#if PYTHON_VERSION < 360
            if (flags & METH_KEYWORDS) {
                result = (*(PyCFunctionWithKeywords)method)(self, pos_args, NULL);
            } else {
                result = (*method)(self, pos_args);
            }
#else
            if (flags == (METH_VARARGS|METH_KEYWORDS)) {
                result = (*(PyCFunctionWithKeywords)method)(self, pos_args, NULL);
            } else if (flags == METH_FASTCALL) {
#if PYTHON_VERSION < 370
                result = (*(_PyCFunctionFast)method)(self, &PyTuple_GET_ITEM(pos_args, 0), 1, NULL);
#else
                result = (*(_PyCFunctionFast)method)(self, &pos_args, 1);
#endif
            } else {
                result = (*method)(self, pos_args);
            }
#endif

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if (result != NULL) {
                // Some buggy C functions do set an error, but do not indicate it
                // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                Py_DECREF(pos_args);
                return result;
            } else {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely(!ERROR_OCCURRED())) {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                Py_DECREF(pos_args);
                return NULL;
            }
        }
    } else if (PyFunction_Check(called)) {
        return callPythonFunction(
            called,
            args,
            1
        );
    }

    PyObject *pos_args = MAKE_TUPLE(args, 1);

    PyObject *result = CALL_FUNCTION(called, pos_args, NULL);

    Py_DECREF(pos_args);

    return result;
}

PyObject *CALL_FUNCTION_WITH_ARGS2(PyObject *called, PyObject **args) {
    CHECK_OBJECT(called);

    // Check if arguments are valid objects in debug mode.
#ifndef __NUITKA_NO_ASSERT__
    for (size_t i = 0; i < 2; i++)
    {
        CHECK_OBJECT(args[i]);
    }
#endif

    if (Nuitka_Function_Check(called)) {
        if (unlikely(Py_EnterRecursiveCall((char *)" while calling a Python object"))) {
            return NULL;
        }

        struct Nuitka_FunctionObject *function = (struct Nuitka_FunctionObject *)called;
        PyObject *result;

        if (function->m_args_simple && 2 == function->m_args_positional_count){
            for (Py_ssize_t i = 0; i < 2; i++)
            {
                Py_INCREF(args[i]);
            }

            result = function->m_c_code(function, args);
        } else if (function->m_args_simple && 2 + function->m_defaults_given == function->m_args_positional_count) {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca(sizeof(PyObject *) * function->m_args_positional_count);
#else
            PyObject *python_pars[function->m_args_positional_count];
#endif
            memcpy(python_pars, args, 2 * sizeof(PyObject *));
            memcpy(python_pars + 2, &PyTuple_GET_ITEM(function->m_defaults, 0), function->m_defaults_given * sizeof(PyObject *));

            for (Py_ssize_t i = 0; i < function->m_args_positional_count; i++)
            {
                Py_INCREF(python_pars[i]);
            }

            result = function->m_c_code(function, python_pars);
        } else {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca(sizeof(PyObject *) * function->m_args_overall_count);
#else
            PyObject *python_pars[function->m_args_overall_count];
#endif
            memset(python_pars, 0, function->m_args_overall_count * sizeof(PyObject *));

            if (parseArgumentsPos(function, python_pars, args, 2)) {
                result = function->m_c_code(function, python_pars);
            } else {
                result = NULL;
            }
        }

        Py_LeaveRecursiveCall();

        return result;
    } else if (Nuitka_Method_Check(called)) {
        struct Nuitka_MethodObject *method = (struct Nuitka_MethodObject *)called;

        // Unbound method without arguments, let the error path be slow.
        if (method->m_object != NULL)
        {
            if (unlikely(Py_EnterRecursiveCall((char *)" while calling a Python object"))) {
                return NULL;
            }

            struct Nuitka_FunctionObject *function = method->m_function;

            PyObject *result;

            if (function->m_args_simple && 2 + 1 == function->m_args_positional_count) {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca(sizeof(PyObject *) * function->m_args_positional_count);
#else
                PyObject *python_pars[function->m_args_positional_count];
#endif
                python_pars[0] = method->m_object;
                Py_INCREF(method->m_object);

                for (Py_ssize_t i = 0; i < 2; i++) {
                    python_pars[i+1] = args[i];
                    Py_INCREF(args[i]);
                }

                result = function->m_c_code(function, python_pars);
            } else if ( function->m_args_simple && 2 + 1 + function->m_defaults_given == function->m_args_positional_count ) {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca(sizeof(PyObject *) * function->m_args_positional_count);
#else
                PyObject *python_pars[function->m_args_positional_count];
#endif
                python_pars[0] = method->m_object;
                Py_INCREF(method->m_object);

                memcpy(python_pars+1, args, 2 * sizeof(PyObject *));
                memcpy(python_pars+1 + 2, &PyTuple_GET_ITEM(function->m_defaults, 0), function->m_defaults_given * sizeof(PyObject *));

                for (Py_ssize_t i = 1; i < function->m_args_overall_count; i++) {
                    Py_INCREF(python_pars[i]);
                }

                result = function->m_c_code(function, python_pars);
            } else {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca(sizeof(PyObject *) * function->m_args_overall_count);
#else
                PyObject *python_pars[function->m_args_overall_count];
#endif
                memset(python_pars, 0, function->m_args_overall_count * sizeof(PyObject *));

                if (parseArgumentsMethodPos(function, python_pars, method->m_object, args, 2)) {
                    result = function->m_c_code(function, python_pars);
                } else {
                    result = NULL;
                }
            }

            Py_LeaveRecursiveCall();

            return result;
        }
    } else if (PyCFunction_Check(called)) {
        // Try to be fast about wrapping the arguments.
        int flags = PyCFunction_GET_FLAGS(called) & ~(METH_CLASS | METH_STATIC | METH_COEXIST);

        if (flags & METH_NOARGS) {
#if 2 == 0
            PyCFunction method = PyCFunction_GET_FUNCTION(called);
            PyObject *self = PyCFunction_GET_SELF(called);

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely(Py_EnterRecursiveCall((char *)" while calling a Python object"))) {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, NULL );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if (result != NULL) {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            } else {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely(!ERROR_OCCURRED())) {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(
                PyExc_TypeError,
                "%s() takes no arguments (2 given)",
                ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        } else if (flags & METH_O) {
#if 2 == 1
            PyCFunction method = PyCFunction_GET_FUNCTION(called);
            PyObject *self = PyCFunction_GET_SELF(called);

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely(Py_EnterRecursiveCall((char *)" while calling a Python object"))) {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, args[0] );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if (result != NULL) {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            } else {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely(!ERROR_OCCURRED())) {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(PyExc_TypeError,
                "%s() takes exactly one argument (2 given)",
                 ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        } else if (flags & METH_VARARGS) {
            PyCFunction method = PyCFunction_GET_FUNCTION(called);
            PyObject *self = PyCFunction_GET_SELF(called);

            PyObject *pos_args = MAKE_TUPLE(args, 2);

            PyObject *result;

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely(Py_EnterRecursiveCall((char *)" while calling a Python object"))) {
                return NULL;
            }
#endif

#if PYTHON_VERSION < 360
            if (flags & METH_KEYWORDS) {
                result = (*(PyCFunctionWithKeywords)method)(self, pos_args, NULL);
            } else {
                result = (*method)(self, pos_args);
            }
#else
            if (flags == (METH_VARARGS|METH_KEYWORDS)) {
                result = (*(PyCFunctionWithKeywords)method)(self, pos_args, NULL);
            } else if (flags == METH_FASTCALL) {
#if PYTHON_VERSION < 370
                result = (*(_PyCFunctionFast)method)(self, &PyTuple_GET_ITEM(pos_args, 0), 2, NULL);
#else
                result = (*(_PyCFunctionFast)method)(self, &pos_args, 2);
#endif
            } else {
                result = (*method)(self, pos_args);
            }
#endif

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if (result != NULL) {
                // Some buggy C functions do set an error, but do not indicate it
                // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                Py_DECREF(pos_args);
                return result;
            } else {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely(!ERROR_OCCURRED())) {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                Py_DECREF(pos_args);
                return NULL;
            }
        }
    } else if (PyFunction_Check(called)) {
        return callPythonFunction(
            called,
            args,
            2
        );
    }

    PyObject *pos_args = MAKE_TUPLE(args, 2);

    PyObject *result = CALL_FUNCTION(called, pos_args, NULL);

    Py_DECREF(pos_args);

    return result;
}

PyObject *CALL_FUNCTION_WITH_ARGS3(PyObject *called, PyObject **args) {
    CHECK_OBJECT(called);

    // Check if arguments are valid objects in debug mode.
#ifndef __NUITKA_NO_ASSERT__
    for (size_t i = 0; i < 3; i++)
    {
        CHECK_OBJECT(args[i]);
    }
#endif

    if (Nuitka_Function_Check(called)) {
        if (unlikely(Py_EnterRecursiveCall((char *)" while calling a Python object"))) {
            return NULL;
        }

        struct Nuitka_FunctionObject *function = (struct Nuitka_FunctionObject *)called;
        PyObject *result;

        if (function->m_args_simple && 3 == function->m_args_positional_count){
            for (Py_ssize_t i = 0; i < 3; i++)
            {
                Py_INCREF(args[i]);
            }

            result = function->m_c_code(function, args);
        } else if (function->m_args_simple && 3 + function->m_defaults_given == function->m_args_positional_count) {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca(sizeof(PyObject *) * function->m_args_positional_count);
#else
            PyObject *python_pars[function->m_args_positional_count];
#endif
            memcpy(python_pars, args, 3 * sizeof(PyObject *));
            memcpy(python_pars + 3, &PyTuple_GET_ITEM(function->m_defaults, 0), function->m_defaults_given * sizeof(PyObject *));

            for (Py_ssize_t i = 0; i < function->m_args_positional_count; i++)
            {
                Py_INCREF(python_pars[i]);
            }

            result = function->m_c_code(function, python_pars);
        } else {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca(sizeof(PyObject *) * function->m_args_overall_count);
#else
            PyObject *python_pars[function->m_args_overall_count];
#endif
            memset(python_pars, 0, function->m_args_overall_count * sizeof(PyObject *));

            if (parseArgumentsPos(function, python_pars, args, 3)) {
                result = function->m_c_code(function, python_pars);
            } else {
                result = NULL;
            }
        }

        Py_LeaveRecursiveCall();

        return result;
    } else if (Nuitka_Method_Check(called)) {
        struct Nuitka_MethodObject *method = (struct Nuitka_MethodObject *)called;

        // Unbound method without arguments, let the error path be slow.
        if (method->m_object != NULL)
        {
            if (unlikely(Py_EnterRecursiveCall((char *)" while calling a Python object"))) {
                return NULL;
            }

            struct Nuitka_FunctionObject *function = method->m_function;

            PyObject *result;

            if (function->m_args_simple && 3 + 1 == function->m_args_positional_count) {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca(sizeof(PyObject *) * function->m_args_positional_count);
#else
                PyObject *python_pars[function->m_args_positional_count];
#endif
                python_pars[0] = method->m_object;
                Py_INCREF(method->m_object);

                for (Py_ssize_t i = 0; i < 3; i++) {
                    python_pars[i+1] = args[i];
                    Py_INCREF(args[i]);
                }

                result = function->m_c_code(function, python_pars);
            } else if ( function->m_args_simple && 3 + 1 + function->m_defaults_given == function->m_args_positional_count ) {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca(sizeof(PyObject *) * function->m_args_positional_count);
#else
                PyObject *python_pars[function->m_args_positional_count];
#endif
                python_pars[0] = method->m_object;
                Py_INCREF(method->m_object);

                memcpy(python_pars+1, args, 3 * sizeof(PyObject *));
                memcpy(python_pars+1 + 3, &PyTuple_GET_ITEM(function->m_defaults, 0), function->m_defaults_given * sizeof(PyObject *));

                for (Py_ssize_t i = 1; i < function->m_args_overall_count; i++) {
                    Py_INCREF(python_pars[i]);
                }

                result = function->m_c_code(function, python_pars);
            } else {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca(sizeof(PyObject *) * function->m_args_overall_count);
#else
                PyObject *python_pars[function->m_args_overall_count];
#endif
                memset(python_pars, 0, function->m_args_overall_count * sizeof(PyObject *));

                if (parseArgumentsMethodPos(function, python_pars, method->m_object, args, 3)) {
                    result = function->m_c_code(function, python_pars);
                } else {
                    result = NULL;
                }
            }

            Py_LeaveRecursiveCall();

            return result;
        }
    } else if (PyCFunction_Check(called)) {
        // Try to be fast about wrapping the arguments.
        int flags = PyCFunction_GET_FLAGS(called) & ~(METH_CLASS | METH_STATIC | METH_COEXIST);

        if (flags & METH_NOARGS) {
#if 3 == 0
            PyCFunction method = PyCFunction_GET_FUNCTION(called);
            PyObject *self = PyCFunction_GET_SELF(called);

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely(Py_EnterRecursiveCall((char *)" while calling a Python object"))) {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, NULL );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if (result != NULL) {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            } else {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely(!ERROR_OCCURRED())) {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(
                PyExc_TypeError,
                "%s() takes no arguments (3 given)",
                ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        } else if (flags & METH_O) {
#if 3 == 1
            PyCFunction method = PyCFunction_GET_FUNCTION(called);
            PyObject *self = PyCFunction_GET_SELF(called);

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely(Py_EnterRecursiveCall((char *)" while calling a Python object"))) {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, args[0] );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if (result != NULL) {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            } else {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely(!ERROR_OCCURRED())) {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(PyExc_TypeError,
                "%s() takes exactly one argument (3 given)",
                 ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        } else if (flags & METH_VARARGS) {
            PyCFunction method = PyCFunction_GET_FUNCTION(called);
            PyObject *self = PyCFunction_GET_SELF(called);

            PyObject *pos_args = MAKE_TUPLE(args, 3);

            PyObject *result;

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely(Py_EnterRecursiveCall((char *)" while calling a Python object"))) {
                return NULL;
            }
#endif

#if PYTHON_VERSION < 360
            if (flags & METH_KEYWORDS) {
                result = (*(PyCFunctionWithKeywords)method)(self, pos_args, NULL);
            } else {
                result = (*method)(self, pos_args);
            }
#else
            if (flags == (METH_VARARGS|METH_KEYWORDS)) {
                result = (*(PyCFunctionWithKeywords)method)(self, pos_args, NULL);
            } else if (flags == METH_FASTCALL) {
#if PYTHON_VERSION < 370
                result = (*(_PyCFunctionFast)method)(self, &PyTuple_GET_ITEM(pos_args, 0), 3, NULL);
#else
                result = (*(_PyCFunctionFast)method)(self, &pos_args, 3);
#endif
            } else {
                result = (*method)(self, pos_args);
            }
#endif

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if (result != NULL) {
                // Some buggy C functions do set an error, but do not indicate it
                // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                Py_DECREF(pos_args);
                return result;
            } else {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely(!ERROR_OCCURRED())) {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                Py_DECREF(pos_args);
                return NULL;
            }
        }
    } else if (PyFunction_Check(called)) {
        return callPythonFunction(
            called,
            args,
            3
        );
    }

    PyObject *pos_args = MAKE_TUPLE(args, 3);

    PyObject *result = CALL_FUNCTION(called, pos_args, NULL);

    Py_DECREF(pos_args);

    return result;
}

PyObject *CALL_FUNCTION_WITH_ARGS4(PyObject *called, PyObject **args) {
    CHECK_OBJECT(called);

    // Check if arguments are valid objects in debug mode.
#ifndef __NUITKA_NO_ASSERT__
    for (size_t i = 0; i < 4; i++)
    {
        CHECK_OBJECT(args[i]);
    }
#endif

    if (Nuitka_Function_Check(called)) {
        if (unlikely(Py_EnterRecursiveCall((char *)" while calling a Python object"))) {
            return NULL;
        }

        struct Nuitka_FunctionObject *function = (struct Nuitka_FunctionObject *)called;
        PyObject *result;

        if (function->m_args_simple && 4 == function->m_args_positional_count){
            for (Py_ssize_t i = 0; i < 4; i++)
            {
                Py_INCREF(args[i]);
            }

            result = function->m_c_code(function, args);
        } else if (function->m_args_simple && 4 + function->m_defaults_given == function->m_args_positional_count) {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca(sizeof(PyObject *) * function->m_args_positional_count);
#else
            PyObject *python_pars[function->m_args_positional_count];
#endif
            memcpy(python_pars, args, 4 * sizeof(PyObject *));
            memcpy(python_pars + 4, &PyTuple_GET_ITEM(function->m_defaults, 0), function->m_defaults_given * sizeof(PyObject *));

            for (Py_ssize_t i = 0; i < function->m_args_positional_count; i++)
            {
                Py_INCREF(python_pars[i]);
            }

            result = function->m_c_code(function, python_pars);
        } else {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca(sizeof(PyObject *) * function->m_args_overall_count);
#else
            PyObject *python_pars[function->m_args_overall_count];
#endif
            memset(python_pars, 0, function->m_args_overall_count * sizeof(PyObject *));

            if (parseArgumentsPos(function, python_pars, args, 4)) {
                result = function->m_c_code(function, python_pars);
            } else {
                result = NULL;
            }
        }

        Py_LeaveRecursiveCall();

        return result;
    } else if (Nuitka_Method_Check(called)) {
        struct Nuitka_MethodObject *method = (struct Nuitka_MethodObject *)called;

        // Unbound method without arguments, let the error path be slow.
        if (method->m_object != NULL)
        {
            if (unlikely(Py_EnterRecursiveCall((char *)" while calling a Python object"))) {
                return NULL;
            }

            struct Nuitka_FunctionObject *function = method->m_function;

            PyObject *result;

            if (function->m_args_simple && 4 + 1 == function->m_args_positional_count) {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca(sizeof(PyObject *) * function->m_args_positional_count);
#else
                PyObject *python_pars[function->m_args_positional_count];
#endif
                python_pars[0] = method->m_object;
                Py_INCREF(method->m_object);

                for (Py_ssize_t i = 0; i < 4; i++) {
                    python_pars[i+1] = args[i];
                    Py_INCREF(args[i]);
                }

                result = function->m_c_code(function, python_pars);
            } else if ( function->m_args_simple && 4 + 1 + function->m_defaults_given == function->m_args_positional_count ) {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca(sizeof(PyObject *) * function->m_args_positional_count);
#else
                PyObject *python_pars[function->m_args_positional_count];
#endif
                python_pars[0] = method->m_object;
                Py_INCREF(method->m_object);

                memcpy(python_pars+1, args, 4 * sizeof(PyObject *));
                memcpy(python_pars+1 + 4, &PyTuple_GET_ITEM(function->m_defaults, 0), function->m_defaults_given * sizeof(PyObject *));

                for (Py_ssize_t i = 1; i < function->m_args_overall_count; i++) {
                    Py_INCREF(python_pars[i]);
                }

                result = function->m_c_code(function, python_pars);
            } else {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca(sizeof(PyObject *) * function->m_args_overall_count);
#else
                PyObject *python_pars[function->m_args_overall_count];
#endif
                memset(python_pars, 0, function->m_args_overall_count * sizeof(PyObject *));

                if (parseArgumentsMethodPos(function, python_pars, method->m_object, args, 4)) {
                    result = function->m_c_code(function, python_pars);
                } else {
                    result = NULL;
                }
            }

            Py_LeaveRecursiveCall();

            return result;
        }
    } else if (PyCFunction_Check(called)) {
        // Try to be fast about wrapping the arguments.
        int flags = PyCFunction_GET_FLAGS(called) & ~(METH_CLASS | METH_STATIC | METH_COEXIST);

        if (flags & METH_NOARGS) {
#if 4 == 0
            PyCFunction method = PyCFunction_GET_FUNCTION(called);
            PyObject *self = PyCFunction_GET_SELF(called);

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely(Py_EnterRecursiveCall((char *)" while calling a Python object"))) {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, NULL );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if (result != NULL) {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            } else {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely(!ERROR_OCCURRED())) {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(
                PyExc_TypeError,
                "%s() takes no arguments (4 given)",
                ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        } else if (flags & METH_O) {
#if 4 == 1
            PyCFunction method = PyCFunction_GET_FUNCTION(called);
            PyObject *self = PyCFunction_GET_SELF(called);

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely(Py_EnterRecursiveCall((char *)" while calling a Python object"))) {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, args[0] );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if (result != NULL) {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            } else {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely(!ERROR_OCCURRED())) {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(PyExc_TypeError,
                "%s() takes exactly one argument (4 given)",
                 ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        } else if (flags & METH_VARARGS) {
            PyCFunction method = PyCFunction_GET_FUNCTION(called);
            PyObject *self = PyCFunction_GET_SELF(called);

            PyObject *pos_args = MAKE_TUPLE(args, 4);

            PyObject *result;

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely(Py_EnterRecursiveCall((char *)" while calling a Python object"))) {
                return NULL;
            }
#endif

#if PYTHON_VERSION < 360
            if (flags & METH_KEYWORDS) {
                result = (*(PyCFunctionWithKeywords)method)(self, pos_args, NULL);
            } else {
                result = (*method)(self, pos_args);
            }
#else
            if (flags == (METH_VARARGS|METH_KEYWORDS)) {
                result = (*(PyCFunctionWithKeywords)method)(self, pos_args, NULL);
            } else if (flags == METH_FASTCALL) {
#if PYTHON_VERSION < 370
                result = (*(_PyCFunctionFast)method)(self, &PyTuple_GET_ITEM(pos_args, 0), 4, NULL);
#else
                result = (*(_PyCFunctionFast)method)(self, &pos_args, 4);
#endif
            } else {
                result = (*method)(self, pos_args);
            }
#endif

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if (result != NULL) {
                // Some buggy C functions do set an error, but do not indicate it
                // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                Py_DECREF(pos_args);
                return result;
            } else {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely(!ERROR_OCCURRED())) {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                Py_DECREF(pos_args);
                return NULL;
            }
        }
    } else if (PyFunction_Check(called)) {
        return callPythonFunction(
            called,
            args,
            4
        );
    }

    PyObject *pos_args = MAKE_TUPLE(args, 4);

    PyObject *result = CALL_FUNCTION(called, pos_args, NULL);

    Py_DECREF(pos_args);

    return result;
}

PyObject *CALL_FUNCTION_WITH_ARGS5(PyObject *called, PyObject **args) {
    CHECK_OBJECT(called);

    // Check if arguments are valid objects in debug mode.
#ifndef __NUITKA_NO_ASSERT__
    for (size_t i = 0; i < 5; i++)
    {
        CHECK_OBJECT(args[i]);
    }
#endif

    if (Nuitka_Function_Check(called)) {
        if (unlikely(Py_EnterRecursiveCall((char *)" while calling a Python object"))) {
            return NULL;
        }

        struct Nuitka_FunctionObject *function = (struct Nuitka_FunctionObject *)called;
        PyObject *result;

        if (function->m_args_simple && 5 == function->m_args_positional_count){
            for (Py_ssize_t i = 0; i < 5; i++)
            {
                Py_INCREF(args[i]);
            }

            result = function->m_c_code(function, args);
        } else if (function->m_args_simple && 5 + function->m_defaults_given == function->m_args_positional_count) {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca(sizeof(PyObject *) * function->m_args_positional_count);
#else
            PyObject *python_pars[function->m_args_positional_count];
#endif
            memcpy(python_pars, args, 5 * sizeof(PyObject *));
            memcpy(python_pars + 5, &PyTuple_GET_ITEM(function->m_defaults, 0), function->m_defaults_given * sizeof(PyObject *));

            for (Py_ssize_t i = 0; i < function->m_args_positional_count; i++)
            {
                Py_INCREF(python_pars[i]);
            }

            result = function->m_c_code(function, python_pars);
        } else {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca(sizeof(PyObject *) * function->m_args_overall_count);
#else
            PyObject *python_pars[function->m_args_overall_count];
#endif
            memset(python_pars, 0, function->m_args_overall_count * sizeof(PyObject *));

            if (parseArgumentsPos(function, python_pars, args, 5)) {
                result = function->m_c_code(function, python_pars);
            } else {
                result = NULL;
            }
        }

        Py_LeaveRecursiveCall();

        return result;
    } else if (Nuitka_Method_Check(called)) {
        struct Nuitka_MethodObject *method = (struct Nuitka_MethodObject *)called;

        // Unbound method without arguments, let the error path be slow.
        if (method->m_object != NULL)
        {
            if (unlikely(Py_EnterRecursiveCall((char *)" while calling a Python object"))) {
                return NULL;
            }

            struct Nuitka_FunctionObject *function = method->m_function;

            PyObject *result;

            if (function->m_args_simple && 5 + 1 == function->m_args_positional_count) {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca(sizeof(PyObject *) * function->m_args_positional_count);
#else
                PyObject *python_pars[function->m_args_positional_count];
#endif
                python_pars[0] = method->m_object;
                Py_INCREF(method->m_object);

                for (Py_ssize_t i = 0; i < 5; i++) {
                    python_pars[i+1] = args[i];
                    Py_INCREF(args[i]);
                }

                result = function->m_c_code(function, python_pars);
            } else if ( function->m_args_simple && 5 + 1 + function->m_defaults_given == function->m_args_positional_count ) {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca(sizeof(PyObject *) * function->m_args_positional_count);
#else
                PyObject *python_pars[function->m_args_positional_count];
#endif
                python_pars[0] = method->m_object;
                Py_INCREF(method->m_object);

                memcpy(python_pars+1, args, 5 * sizeof(PyObject *));
                memcpy(python_pars+1 + 5, &PyTuple_GET_ITEM(function->m_defaults, 0), function->m_defaults_given * sizeof(PyObject *));

                for (Py_ssize_t i = 1; i < function->m_args_overall_count; i++) {
                    Py_INCREF(python_pars[i]);
                }

                result = function->m_c_code(function, python_pars);
            } else {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca(sizeof(PyObject *) * function->m_args_overall_count);
#else
                PyObject *python_pars[function->m_args_overall_count];
#endif
                memset(python_pars, 0, function->m_args_overall_count * sizeof(PyObject *));

                if (parseArgumentsMethodPos(function, python_pars, method->m_object, args, 5)) {
                    result = function->m_c_code(function, python_pars);
                } else {
                    result = NULL;
                }
            }

            Py_LeaveRecursiveCall();

            return result;
        }
    } else if (PyCFunction_Check(called)) {
        // Try to be fast about wrapping the arguments.
        int flags = PyCFunction_GET_FLAGS(called) & ~(METH_CLASS | METH_STATIC | METH_COEXIST);

        if (flags & METH_NOARGS) {
#if 5 == 0
            PyCFunction method = PyCFunction_GET_FUNCTION(called);
            PyObject *self = PyCFunction_GET_SELF(called);

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely(Py_EnterRecursiveCall((char *)" while calling a Python object"))) {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, NULL );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if (result != NULL) {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            } else {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely(!ERROR_OCCURRED())) {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(
                PyExc_TypeError,
                "%s() takes no arguments (5 given)",
                ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        } else if (flags & METH_O) {
#if 5 == 1
            PyCFunction method = PyCFunction_GET_FUNCTION(called);
            PyObject *self = PyCFunction_GET_SELF(called);

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely(Py_EnterRecursiveCall((char *)" while calling a Python object"))) {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, args[0] );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if (result != NULL) {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            } else {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely(!ERROR_OCCURRED())) {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(PyExc_TypeError,
                "%s() takes exactly one argument (5 given)",
                 ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        } else if (flags & METH_VARARGS) {
            PyCFunction method = PyCFunction_GET_FUNCTION(called);
            PyObject *self = PyCFunction_GET_SELF(called);

            PyObject *pos_args = MAKE_TUPLE(args, 5);

            PyObject *result;

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely(Py_EnterRecursiveCall((char *)" while calling a Python object"))) {
                return NULL;
            }
#endif

#if PYTHON_VERSION < 360
            if (flags & METH_KEYWORDS) {
                result = (*(PyCFunctionWithKeywords)method)(self, pos_args, NULL);
            } else {
                result = (*method)(self, pos_args);
            }
#else
            if (flags == (METH_VARARGS|METH_KEYWORDS)) {
                result = (*(PyCFunctionWithKeywords)method)(self, pos_args, NULL);
            } else if (flags == METH_FASTCALL) {
#if PYTHON_VERSION < 370
                result = (*(_PyCFunctionFast)method)(self, &PyTuple_GET_ITEM(pos_args, 0), 5, NULL);
#else
                result = (*(_PyCFunctionFast)method)(self, &pos_args, 5);
#endif
            } else {
                result = (*method)(self, pos_args);
            }
#endif

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if (result != NULL) {
                // Some buggy C functions do set an error, but do not indicate it
                // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                Py_DECREF(pos_args);
                return result;
            } else {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely(!ERROR_OCCURRED())) {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                Py_DECREF(pos_args);
                return NULL;
            }
        }
    } else if (PyFunction_Check(called)) {
        return callPythonFunction(
            called,
            args,
            5
        );
    }

    PyObject *pos_args = MAKE_TUPLE(args, 5);

    PyObject *result = CALL_FUNCTION(called, pos_args, NULL);

    Py_DECREF(pos_args);

    return result;
}

PyObject *CALL_METHOD_WITH_ARGS1(PyObject *source, PyObject *attr_name, PyObject **args) {
    CHECK_OBJECT(source);
    CHECK_OBJECT(attr_name);

    // Check if arguments are valid objects in debug mode.
#ifndef __NUITKA_NO_ASSERT__
    for (size_t i = 0; i < 1; i++) {
        CHECK_OBJECT(args[i]);
    }
#endif

    PyTypeObject *type = Py_TYPE(source);

    if (type->tp_getattro == PyObject_GenericGetAttr) {
        // Unfortunately this is required, although of cause rarely necessary.
        if (unlikely(type->tp_dict == NULL)) {
            if (unlikely(PyType_Ready(type) < 0)) {
                return NULL;
            }
        }

        PyObject *descr = _PyType_Lookup(type, attr_name);
        descrgetfunc func = NULL;

        if (descr != NULL)
        {
            Py_INCREF(descr);

#if PYTHON_VERSION < 300
            if (PyType_HasFeature(Py_TYPE(descr), Py_TPFLAGS_HAVE_CLASS)) {
#endif
                func = Py_TYPE(descr)->tp_descr_get;

                if (func != NULL && PyDescr_IsData(descr))
                {
                    PyObject *called_object = func(descr, source, (PyObject *)type);
                    Py_DECREF(descr);

                    PyObject *result = CALL_FUNCTION_WITH_ARGS1(
                        called_object,
                        args
                    );
                    Py_DECREF(called_object);
                    return result;
                }
#if PYTHON_VERSION < 300
            }
#endif
        }

        Py_ssize_t dictoffset = type->tp_dictoffset;
        PyObject *dict = NULL;

        if ( dictoffset != 0 )
        {
            // Negative dictionary offsets have special meaning.
            if ( dictoffset < 0 )
            {
                Py_ssize_t tsize;
                size_t size;

                tsize = ((PyVarObject *)source)->ob_size;
                if (tsize < 0)
                    tsize = -tsize;
                size = _PyObject_VAR_SIZE( type, tsize );

                dictoffset += (long)size;
            }

            PyObject **dictptr = (PyObject **) ((char *)source + dictoffset);
            dict = *dictptr;
        }

        if (dict != NULL)
        {
            CHECK_OBJECT(dict);

            Py_INCREF(dict);

            PyObject *called_object = PyDict_GetItem(dict, attr_name);

            if (called_object != NULL)
            {
                Py_INCREF(called_object);
                Py_XDECREF(descr);
                Py_DECREF(dict);

                PyObject *result = CALL_FUNCTION_WITH_ARGS1(
                    called_object,
                    args
                );
                Py_DECREF(called_object);
                return result;
            }

            Py_DECREF(dict);
        }

        if (func != NULL) {
            if (func == Nuitka_Function_Type.tp_descr_get) {
                PyObject *result = Nuitka_CallMethodFunctionPosArgs(
                    (struct Nuitka_FunctionObject const *)descr,
                    source,
                    args,
                    1
                );

                Py_DECREF(descr);

                return result;
            } else {
                PyObject *called_object = func(descr, source, (PyObject *)type);
                CHECK_OBJECT(called_object);

                Py_DECREF(descr);

                PyObject *result = CALL_FUNCTION_WITH_ARGS1(
                    called_object,
                    args
                );
                Py_DECREF(called_object);

                return result;
            }
        }

        if (descr != NULL) {
            CHECK_OBJECT(descr);

            PyObject *result = CALL_FUNCTION_WITH_ARGS1(
                descr,
                args
            );
            Py_DECREF(descr);

            return result;
        }

#if PYTHON_VERSION < 300
        PyErr_Format(
            PyExc_AttributeError,
            "'%s' object has no attribute '%s'",
            type->tp_name,
            PyString_AS_STRING( attr_name )
        );
#else
        PyErr_Format(
            PyExc_AttributeError,
            "'%s' object has no attribute '%U'",
            type->tp_name,
            attr_name
        );
#endif
        return NULL;
    }
#if PYTHON_VERSION < 300
    else if (type == &PyInstance_Type) {
        PyInstanceObject *source_instance = (PyInstanceObject *)source;

        // The special cases have their own variant on the code generation level
        // as we are called with constants only.
        assert(attr_name != const_str_plain___dict__);
        assert(attr_name != const_str_plain___class__);

        // Try the instance dict first.
        PyObject *called_object = GET_STRING_DICT_VALUE(
            (PyDictObject *)source_instance->in_dict,
            (PyStringObject *)attr_name
        );

        // Note: The "called_object" was found without taking a reference,
        // so we need not release it in this branch.
        if (called_object != NULL) {
            return CALL_FUNCTION_WITH_ARGS1(called_object, args);
        }

        // Then check the class dictionaries.
        called_object = FIND_ATTRIBUTE_IN_CLASS(
            source_instance->in_class,
            attr_name
        );

        // Note: The "called_object" was found without taking a reference,
        // so we need not release it in this branch.
        if (called_object != NULL) {
            descrgetfunc descr_get = Py_TYPE(called_object)->tp_descr_get;

            if (descr_get == Nuitka_Function_Type.tp_descr_get) {
                return Nuitka_CallMethodFunctionPosArgs(
                    (struct Nuitka_FunctionObject const *)called_object,
                    source,
                    args,
                    1
                );
            } else if (descr_get != NULL) {
                PyObject *method = descr_get(
                    called_object,
                    source,
                    (PyObject *)source_instance->in_class
                );

                if (unlikely(method == NULL)) {
                    return NULL;
                }

                PyObject *result = CALL_FUNCTION_WITH_ARGS1(method, args);
                Py_DECREF(method);
                return result;
            } else {
                return CALL_FUNCTION_WITH_ARGS1(called_object, args);
            }

        } else if (unlikely(source_instance->in_class->cl_getattr == NULL)) {
            PyErr_Format(
                PyExc_AttributeError,
                "%s instance has no attribute '%s'",
                PyString_AS_STRING( source_instance->in_class->cl_name ),
                PyString_AS_STRING( attr_name )
            );

            return NULL;
        } else {
            // Finally allow the "__getattr__" override to provide it or else
            // it's an error.

            PyObject *args2[] = {
                source,
                attr_name
            };

            called_object = CALL_FUNCTION_WITH_ARGS2(
                source_instance->in_class->cl_getattr,
                args2
            );

            if (unlikely(called_object == NULL))
            {
                return NULL;
            }

            PyObject *result = CALL_FUNCTION_WITH_ARGS1(
                called_object,
                args
            );
            Py_DECREF(called_object);
            return result;
        }
    }
#endif
    else if (type->tp_getattro != NULL) {
        PyObject *called_object = (*type->tp_getattro)(
            source,
            attr_name
        );

        if (unlikely(called_object == NULL)) {
            return NULL;
        }

        PyObject *result = CALL_FUNCTION_WITH_ARGS1(
            called_object,
            args
        );
        Py_DECREF(called_object);
        return result;
    } else if (type->tp_getattr != NULL) {
        PyObject *called_object = (*type->tp_getattr)(
            source,
            (char *)Nuitka_String_AsString_Unchecked(attr_name)
        );

        if (unlikely(called_object == NULL))
        {
            return NULL;
        }

        PyObject *result = CALL_FUNCTION_WITH_ARGS1(
            called_object,
            args
        );
        Py_DECREF(called_object);
        return result;
    } else {
        PyErr_Format(
            PyExc_AttributeError,
            "'%s' object has no attribute '%s'",
            type->tp_name,
            Nuitka_String_AsString_Unchecked(attr_name)
        );

        return NULL;
    }
}

PyObject *CALL_METHOD_WITH_ARGS2(PyObject *source, PyObject *attr_name, PyObject **args) {
    CHECK_OBJECT(source);
    CHECK_OBJECT(attr_name);

    // Check if arguments are valid objects in debug mode.
#ifndef __NUITKA_NO_ASSERT__
    for (size_t i = 0; i < 2; i++) {
        CHECK_OBJECT(args[i]);
    }
#endif

    PyTypeObject *type = Py_TYPE(source);

    if (type->tp_getattro == PyObject_GenericGetAttr) {
        // Unfortunately this is required, although of cause rarely necessary.
        if (unlikely(type->tp_dict == NULL)) {
            if (unlikely(PyType_Ready(type) < 0)) {
                return NULL;
            }
        }

        PyObject *descr = _PyType_Lookup(type, attr_name);
        descrgetfunc func = NULL;

        if (descr != NULL)
        {
            Py_INCREF(descr);

#if PYTHON_VERSION < 300
            if (PyType_HasFeature(Py_TYPE(descr), Py_TPFLAGS_HAVE_CLASS)) {
#endif
                func = Py_TYPE(descr)->tp_descr_get;

                if (func != NULL && PyDescr_IsData(descr))
                {
                    PyObject *called_object = func(descr, source, (PyObject *)type);
                    Py_DECREF(descr);

                    PyObject *result = CALL_FUNCTION_WITH_ARGS2(
                        called_object,
                        args
                    );
                    Py_DECREF(called_object);
                    return result;
                }
#if PYTHON_VERSION < 300
            }
#endif
        }

        Py_ssize_t dictoffset = type->tp_dictoffset;
        PyObject *dict = NULL;

        if ( dictoffset != 0 )
        {
            // Negative dictionary offsets have special meaning.
            if ( dictoffset < 0 )
            {
                Py_ssize_t tsize;
                size_t size;

                tsize = ((PyVarObject *)source)->ob_size;
                if (tsize < 0)
                    tsize = -tsize;
                size = _PyObject_VAR_SIZE( type, tsize );

                dictoffset += (long)size;
            }

            PyObject **dictptr = (PyObject **) ((char *)source + dictoffset);
            dict = *dictptr;
        }

        if (dict != NULL)
        {
            CHECK_OBJECT(dict);

            Py_INCREF(dict);

            PyObject *called_object = PyDict_GetItem(dict, attr_name);

            if (called_object != NULL)
            {
                Py_INCREF(called_object);
                Py_XDECREF(descr);
                Py_DECREF(dict);

                PyObject *result = CALL_FUNCTION_WITH_ARGS2(
                    called_object,
                    args
                );
                Py_DECREF(called_object);
                return result;
            }

            Py_DECREF(dict);
        }

        if (func != NULL) {
            if (func == Nuitka_Function_Type.tp_descr_get) {
                PyObject *result = Nuitka_CallMethodFunctionPosArgs(
                    (struct Nuitka_FunctionObject const *)descr,
                    source,
                    args,
                    2
                );

                Py_DECREF(descr);

                return result;
            } else {
                PyObject *called_object = func(descr, source, (PyObject *)type);
                CHECK_OBJECT(called_object);

                Py_DECREF(descr);

                PyObject *result = CALL_FUNCTION_WITH_ARGS2(
                    called_object,
                    args
                );
                Py_DECREF(called_object);

                return result;
            }
        }

        if (descr != NULL) {
            CHECK_OBJECT(descr);

            PyObject *result = CALL_FUNCTION_WITH_ARGS2(
                descr,
                args
            );
            Py_DECREF(descr);

            return result;
        }

#if PYTHON_VERSION < 300
        PyErr_Format(
            PyExc_AttributeError,
            "'%s' object has no attribute '%s'",
            type->tp_name,
            PyString_AS_STRING( attr_name )
        );
#else
        PyErr_Format(
            PyExc_AttributeError,
            "'%s' object has no attribute '%U'",
            type->tp_name,
            attr_name
        );
#endif
        return NULL;
    }
#if PYTHON_VERSION < 300
    else if (type == &PyInstance_Type) {
        PyInstanceObject *source_instance = (PyInstanceObject *)source;

        // The special cases have their own variant on the code generation level
        // as we are called with constants only.
        assert(attr_name != const_str_plain___dict__);
        assert(attr_name != const_str_plain___class__);

        // Try the instance dict first.
        PyObject *called_object = GET_STRING_DICT_VALUE(
            (PyDictObject *)source_instance->in_dict,
            (PyStringObject *)attr_name
        );

        // Note: The "called_object" was found without taking a reference,
        // so we need not release it in this branch.
        if (called_object != NULL) {
            return CALL_FUNCTION_WITH_ARGS2(called_object, args);
        }

        // Then check the class dictionaries.
        called_object = FIND_ATTRIBUTE_IN_CLASS(
            source_instance->in_class,
            attr_name
        );

        // Note: The "called_object" was found without taking a reference,
        // so we need not release it in this branch.
        if (called_object != NULL) {
            descrgetfunc descr_get = Py_TYPE(called_object)->tp_descr_get;

            if (descr_get == Nuitka_Function_Type.tp_descr_get) {
                return Nuitka_CallMethodFunctionPosArgs(
                    (struct Nuitka_FunctionObject const *)called_object,
                    source,
                    args,
                    2
                );
            } else if (descr_get != NULL) {
                PyObject *method = descr_get(
                    called_object,
                    source,
                    (PyObject *)source_instance->in_class
                );

                if (unlikely(method == NULL)) {
                    return NULL;
                }

                PyObject *result = CALL_FUNCTION_WITH_ARGS2(method, args);
                Py_DECREF(method);
                return result;
            } else {
                return CALL_FUNCTION_WITH_ARGS2(called_object, args);
            }

        } else if (unlikely(source_instance->in_class->cl_getattr == NULL)) {
            PyErr_Format(
                PyExc_AttributeError,
                "%s instance has no attribute '%s'",
                PyString_AS_STRING( source_instance->in_class->cl_name ),
                PyString_AS_STRING( attr_name )
            );

            return NULL;
        } else {
            // Finally allow the "__getattr__" override to provide it or else
            // it's an error.

            PyObject *args2[] = {
                source,
                attr_name
            };

            called_object = CALL_FUNCTION_WITH_ARGS2(
                source_instance->in_class->cl_getattr,
                args2
            );

            if (unlikely(called_object == NULL))
            {
                return NULL;
            }

            PyObject *result = CALL_FUNCTION_WITH_ARGS2(
                called_object,
                args
            );
            Py_DECREF(called_object);
            return result;
        }
    }
#endif
    else if (type->tp_getattro != NULL) {
        PyObject *called_object = (*type->tp_getattro)(
            source,
            attr_name
        );

        if (unlikely(called_object == NULL)) {
            return NULL;
        }

        PyObject *result = CALL_FUNCTION_WITH_ARGS2(
            called_object,
            args
        );
        Py_DECREF(called_object);
        return result;
    } else if (type->tp_getattr != NULL) {
        PyObject *called_object = (*type->tp_getattr)(
            source,
            (char *)Nuitka_String_AsString_Unchecked(attr_name)
        );

        if (unlikely(called_object == NULL))
        {
            return NULL;
        }

        PyObject *result = CALL_FUNCTION_WITH_ARGS2(
            called_object,
            args
        );
        Py_DECREF(called_object);
        return result;
    } else {
        PyErr_Format(
            PyExc_AttributeError,
            "'%s' object has no attribute '%s'",
            type->tp_name,
            Nuitka_String_AsString_Unchecked(attr_name)
        );

        return NULL;
    }
}

PyObject *CALL_METHOD_WITH_ARGS3(PyObject *source, PyObject *attr_name, PyObject **args) {
    CHECK_OBJECT(source);
    CHECK_OBJECT(attr_name);

    // Check if arguments are valid objects in debug mode.
#ifndef __NUITKA_NO_ASSERT__
    for (size_t i = 0; i < 3; i++) {
        CHECK_OBJECT(args[i]);
    }
#endif

    PyTypeObject *type = Py_TYPE(source);

    if (type->tp_getattro == PyObject_GenericGetAttr) {
        // Unfortunately this is required, although of cause rarely necessary.
        if (unlikely(type->tp_dict == NULL)) {
            if (unlikely(PyType_Ready(type) < 0)) {
                return NULL;
            }
        }

        PyObject *descr = _PyType_Lookup(type, attr_name);
        descrgetfunc func = NULL;

        if (descr != NULL)
        {
            Py_INCREF(descr);

#if PYTHON_VERSION < 300
            if (PyType_HasFeature(Py_TYPE(descr), Py_TPFLAGS_HAVE_CLASS)) {
#endif
                func = Py_TYPE(descr)->tp_descr_get;

                if (func != NULL && PyDescr_IsData(descr))
                {
                    PyObject *called_object = func(descr, source, (PyObject *)type);
                    Py_DECREF(descr);

                    PyObject *result = CALL_FUNCTION_WITH_ARGS3(
                        called_object,
                        args
                    );
                    Py_DECREF(called_object);
                    return result;
                }
#if PYTHON_VERSION < 300
            }
#endif
        }

        Py_ssize_t dictoffset = type->tp_dictoffset;
        PyObject *dict = NULL;

        if ( dictoffset != 0 )
        {
            // Negative dictionary offsets have special meaning.
            if ( dictoffset < 0 )
            {
                Py_ssize_t tsize;
                size_t size;

                tsize = ((PyVarObject *)source)->ob_size;
                if (tsize < 0)
                    tsize = -tsize;
                size = _PyObject_VAR_SIZE( type, tsize );

                dictoffset += (long)size;
            }

            PyObject **dictptr = (PyObject **) ((char *)source + dictoffset);
            dict = *dictptr;
        }

        if (dict != NULL)
        {
            CHECK_OBJECT(dict);

            Py_INCREF(dict);

            PyObject *called_object = PyDict_GetItem(dict, attr_name);

            if (called_object != NULL)
            {
                Py_INCREF(called_object);
                Py_XDECREF(descr);
                Py_DECREF(dict);

                PyObject *result = CALL_FUNCTION_WITH_ARGS3(
                    called_object,
                    args
                );
                Py_DECREF(called_object);
                return result;
            }

            Py_DECREF(dict);
        }

        if (func != NULL) {
            if (func == Nuitka_Function_Type.tp_descr_get) {
                PyObject *result = Nuitka_CallMethodFunctionPosArgs(
                    (struct Nuitka_FunctionObject const *)descr,
                    source,
                    args,
                    3
                );

                Py_DECREF(descr);

                return result;
            } else {
                PyObject *called_object = func(descr, source, (PyObject *)type);
                CHECK_OBJECT(called_object);

                Py_DECREF(descr);

                PyObject *result = CALL_FUNCTION_WITH_ARGS3(
                    called_object,
                    args
                );
                Py_DECREF(called_object);

                return result;
            }
        }

        if (descr != NULL) {
            CHECK_OBJECT(descr);

            PyObject *result = CALL_FUNCTION_WITH_ARGS3(
                descr,
                args
            );
            Py_DECREF(descr);

            return result;
        }

#if PYTHON_VERSION < 300
        PyErr_Format(
            PyExc_AttributeError,
            "'%s' object has no attribute '%s'",
            type->tp_name,
            PyString_AS_STRING( attr_name )
        );
#else
        PyErr_Format(
            PyExc_AttributeError,
            "'%s' object has no attribute '%U'",
            type->tp_name,
            attr_name
        );
#endif
        return NULL;
    }
#if PYTHON_VERSION < 300
    else if (type == &PyInstance_Type) {
        PyInstanceObject *source_instance = (PyInstanceObject *)source;

        // The special cases have their own variant on the code generation level
        // as we are called with constants only.
        assert(attr_name != const_str_plain___dict__);
        assert(attr_name != const_str_plain___class__);

        // Try the instance dict first.
        PyObject *called_object = GET_STRING_DICT_VALUE(
            (PyDictObject *)source_instance->in_dict,
            (PyStringObject *)attr_name
        );

        // Note: The "called_object" was found without taking a reference,
        // so we need not release it in this branch.
        if (called_object != NULL) {
            return CALL_FUNCTION_WITH_ARGS3(called_object, args);
        }

        // Then check the class dictionaries.
        called_object = FIND_ATTRIBUTE_IN_CLASS(
            source_instance->in_class,
            attr_name
        );

        // Note: The "called_object" was found without taking a reference,
        // so we need not release it in this branch.
        if (called_object != NULL) {
            descrgetfunc descr_get = Py_TYPE(called_object)->tp_descr_get;

            if (descr_get == Nuitka_Function_Type.tp_descr_get) {
                return Nuitka_CallMethodFunctionPosArgs(
                    (struct Nuitka_FunctionObject const *)called_object,
                    source,
                    args,
                    3
                );
            } else if (descr_get != NULL) {
                PyObject *method = descr_get(
                    called_object,
                    source,
                    (PyObject *)source_instance->in_class
                );

                if (unlikely(method == NULL)) {
                    return NULL;
                }

                PyObject *result = CALL_FUNCTION_WITH_ARGS3(method, args);
                Py_DECREF(method);
                return result;
            } else {
                return CALL_FUNCTION_WITH_ARGS3(called_object, args);
            }

        } else if (unlikely(source_instance->in_class->cl_getattr == NULL)) {
            PyErr_Format(
                PyExc_AttributeError,
                "%s instance has no attribute '%s'",
                PyString_AS_STRING( source_instance->in_class->cl_name ),
                PyString_AS_STRING( attr_name )
            );

            return NULL;
        } else {
            // Finally allow the "__getattr__" override to provide it or else
            // it's an error.

            PyObject *args2[] = {
                source,
                attr_name
            };

            called_object = CALL_FUNCTION_WITH_ARGS2(
                source_instance->in_class->cl_getattr,
                args2
            );

            if (unlikely(called_object == NULL))
            {
                return NULL;
            }

            PyObject *result = CALL_FUNCTION_WITH_ARGS3(
                called_object,
                args
            );
            Py_DECREF(called_object);
            return result;
        }
    }
#endif
    else if (type->tp_getattro != NULL) {
        PyObject *called_object = (*type->tp_getattro)(
            source,
            attr_name
        );

        if (unlikely(called_object == NULL)) {
            return NULL;
        }

        PyObject *result = CALL_FUNCTION_WITH_ARGS3(
            called_object,
            args
        );
        Py_DECREF(called_object);
        return result;
    } else if (type->tp_getattr != NULL) {
        PyObject *called_object = (*type->tp_getattr)(
            source,
            (char *)Nuitka_String_AsString_Unchecked(attr_name)
        );

        if (unlikely(called_object == NULL))
        {
            return NULL;
        }

        PyObject *result = CALL_FUNCTION_WITH_ARGS3(
            called_object,
            args
        );
        Py_DECREF(called_object);
        return result;
    } else {
        PyErr_Format(
            PyExc_AttributeError,
            "'%s' object has no attribute '%s'",
            type->tp_name,
            Nuitka_String_AsString_Unchecked(attr_name)
        );

        return NULL;
    }
}

PyObject *CALL_METHOD_WITH_ARGS4(PyObject *source, PyObject *attr_name, PyObject **args) {
    CHECK_OBJECT(source);
    CHECK_OBJECT(attr_name);

    // Check if arguments are valid objects in debug mode.
#ifndef __NUITKA_NO_ASSERT__
    for (size_t i = 0; i < 4; i++) {
        CHECK_OBJECT(args[i]);
    }
#endif

    PyTypeObject *type = Py_TYPE(source);

    if (type->tp_getattro == PyObject_GenericGetAttr) {
        // Unfortunately this is required, although of cause rarely necessary.
        if (unlikely(type->tp_dict == NULL)) {
            if (unlikely(PyType_Ready(type) < 0)) {
                return NULL;
            }
        }

        PyObject *descr = _PyType_Lookup(type, attr_name);
        descrgetfunc func = NULL;

        if (descr != NULL)
        {
            Py_INCREF(descr);

#if PYTHON_VERSION < 300
            if (PyType_HasFeature(Py_TYPE(descr), Py_TPFLAGS_HAVE_CLASS)) {
#endif
                func = Py_TYPE(descr)->tp_descr_get;

                if (func != NULL && PyDescr_IsData(descr))
                {
                    PyObject *called_object = func(descr, source, (PyObject *)type);
                    Py_DECREF(descr);

                    PyObject *result = CALL_FUNCTION_WITH_ARGS4(
                        called_object,
                        args
                    );
                    Py_DECREF(called_object);
                    return result;
                }
#if PYTHON_VERSION < 300
            }
#endif
        }

        Py_ssize_t dictoffset = type->tp_dictoffset;
        PyObject *dict = NULL;

        if ( dictoffset != 0 )
        {
            // Negative dictionary offsets have special meaning.
            if ( dictoffset < 0 )
            {
                Py_ssize_t tsize;
                size_t size;

                tsize = ((PyVarObject *)source)->ob_size;
                if (tsize < 0)
                    tsize = -tsize;
                size = _PyObject_VAR_SIZE( type, tsize );

                dictoffset += (long)size;
            }

            PyObject **dictptr = (PyObject **) ((char *)source + dictoffset);
            dict = *dictptr;
        }

        if (dict != NULL)
        {
            CHECK_OBJECT(dict);

            Py_INCREF(dict);

            PyObject *called_object = PyDict_GetItem(dict, attr_name);

            if (called_object != NULL)
            {
                Py_INCREF(called_object);
                Py_XDECREF(descr);
                Py_DECREF(dict);

                PyObject *result = CALL_FUNCTION_WITH_ARGS4(
                    called_object,
                    args
                );
                Py_DECREF(called_object);
                return result;
            }

            Py_DECREF(dict);
        }

        if (func != NULL) {
            if (func == Nuitka_Function_Type.tp_descr_get) {
                PyObject *result = Nuitka_CallMethodFunctionPosArgs(
                    (struct Nuitka_FunctionObject const *)descr,
                    source,
                    args,
                    4
                );

                Py_DECREF(descr);

                return result;
            } else {
                PyObject *called_object = func(descr, source, (PyObject *)type);
                CHECK_OBJECT(called_object);

                Py_DECREF(descr);

                PyObject *result = CALL_FUNCTION_WITH_ARGS4(
                    called_object,
                    args
                );
                Py_DECREF(called_object);

                return result;
            }
        }

        if (descr != NULL) {
            CHECK_OBJECT(descr);

            PyObject *result = CALL_FUNCTION_WITH_ARGS4(
                descr,
                args
            );
            Py_DECREF(descr);

            return result;
        }

#if PYTHON_VERSION < 300
        PyErr_Format(
            PyExc_AttributeError,
            "'%s' object has no attribute '%s'",
            type->tp_name,
            PyString_AS_STRING( attr_name )
        );
#else
        PyErr_Format(
            PyExc_AttributeError,
            "'%s' object has no attribute '%U'",
            type->tp_name,
            attr_name
        );
#endif
        return NULL;
    }
#if PYTHON_VERSION < 300
    else if (type == &PyInstance_Type) {
        PyInstanceObject *source_instance = (PyInstanceObject *)source;

        // The special cases have their own variant on the code generation level
        // as we are called with constants only.
        assert(attr_name != const_str_plain___dict__);
        assert(attr_name != const_str_plain___class__);

        // Try the instance dict first.
        PyObject *called_object = GET_STRING_DICT_VALUE(
            (PyDictObject *)source_instance->in_dict,
            (PyStringObject *)attr_name
        );

        // Note: The "called_object" was found without taking a reference,
        // so we need not release it in this branch.
        if (called_object != NULL) {
            return CALL_FUNCTION_WITH_ARGS4(called_object, args);
        }

        // Then check the class dictionaries.
        called_object = FIND_ATTRIBUTE_IN_CLASS(
            source_instance->in_class,
            attr_name
        );

        // Note: The "called_object" was found without taking a reference,
        // so we need not release it in this branch.
        if (called_object != NULL) {
            descrgetfunc descr_get = Py_TYPE(called_object)->tp_descr_get;

            if (descr_get == Nuitka_Function_Type.tp_descr_get) {
                return Nuitka_CallMethodFunctionPosArgs(
                    (struct Nuitka_FunctionObject const *)called_object,
                    source,
                    args,
                    4
                );
            } else if (descr_get != NULL) {
                PyObject *method = descr_get(
                    called_object,
                    source,
                    (PyObject *)source_instance->in_class
                );

                if (unlikely(method == NULL)) {
                    return NULL;
                }

                PyObject *result = CALL_FUNCTION_WITH_ARGS4(method, args);
                Py_DECREF(method);
                return result;
            } else {
                return CALL_FUNCTION_WITH_ARGS4(called_object, args);
            }

        } else if (unlikely(source_instance->in_class->cl_getattr == NULL)) {
            PyErr_Format(
                PyExc_AttributeError,
                "%s instance has no attribute '%s'",
                PyString_AS_STRING( source_instance->in_class->cl_name ),
                PyString_AS_STRING( attr_name )
            );

            return NULL;
        } else {
            // Finally allow the "__getattr__" override to provide it or else
            // it's an error.

            PyObject *args2[] = {
                source,
                attr_name
            };

            called_object = CALL_FUNCTION_WITH_ARGS2(
                source_instance->in_class->cl_getattr,
                args2
            );

            if (unlikely(called_object == NULL))
            {
                return NULL;
            }

            PyObject *result = CALL_FUNCTION_WITH_ARGS4(
                called_object,
                args
            );
            Py_DECREF(called_object);
            return result;
        }
    }
#endif
    else if (type->tp_getattro != NULL) {
        PyObject *called_object = (*type->tp_getattro)(
            source,
            attr_name
        );

        if (unlikely(called_object == NULL)) {
            return NULL;
        }

        PyObject *result = CALL_FUNCTION_WITH_ARGS4(
            called_object,
            args
        );
        Py_DECREF(called_object);
        return result;
    } else if (type->tp_getattr != NULL) {
        PyObject *called_object = (*type->tp_getattr)(
            source,
            (char *)Nuitka_String_AsString_Unchecked(attr_name)
        );

        if (unlikely(called_object == NULL))
        {
            return NULL;
        }

        PyObject *result = CALL_FUNCTION_WITH_ARGS4(
            called_object,
            args
        );
        Py_DECREF(called_object);
        return result;
    } else {
        PyErr_Format(
            PyExc_AttributeError,
            "'%s' object has no attribute '%s'",
            type->tp_name,
            Nuitka_String_AsString_Unchecked(attr_name)
        );

        return NULL;
    }
}

PyObject *CALL_METHOD_WITH_ARGS5(PyObject *source, PyObject *attr_name, PyObject **args) {
    CHECK_OBJECT(source);
    CHECK_OBJECT(attr_name);

    // Check if arguments are valid objects in debug mode.
#ifndef __NUITKA_NO_ASSERT__
    for (size_t i = 0; i < 5; i++) {
        CHECK_OBJECT(args[i]);
    }
#endif

    PyTypeObject *type = Py_TYPE(source);

    if (type->tp_getattro == PyObject_GenericGetAttr) {
        // Unfortunately this is required, although of cause rarely necessary.
        if (unlikely(type->tp_dict == NULL)) {
            if (unlikely(PyType_Ready(type) < 0)) {
                return NULL;
            }
        }

        PyObject *descr = _PyType_Lookup(type, attr_name);
        descrgetfunc func = NULL;

        if (descr != NULL)
        {
            Py_INCREF(descr);

#if PYTHON_VERSION < 300
            if (PyType_HasFeature(Py_TYPE(descr), Py_TPFLAGS_HAVE_CLASS)) {
#endif
                func = Py_TYPE(descr)->tp_descr_get;

                if (func != NULL && PyDescr_IsData(descr))
                {
                    PyObject *called_object = func(descr, source, (PyObject *)type);
                    Py_DECREF(descr);

                    PyObject *result = CALL_FUNCTION_WITH_ARGS5(
                        called_object,
                        args
                    );
                    Py_DECREF(called_object);
                    return result;
                }
#if PYTHON_VERSION < 300
            }
#endif
        }

        Py_ssize_t dictoffset = type->tp_dictoffset;
        PyObject *dict = NULL;

        if ( dictoffset != 0 )
        {
            // Negative dictionary offsets have special meaning.
            if ( dictoffset < 0 )
            {
                Py_ssize_t tsize;
                size_t size;

                tsize = ((PyVarObject *)source)->ob_size;
                if (tsize < 0)
                    tsize = -tsize;
                size = _PyObject_VAR_SIZE( type, tsize );

                dictoffset += (long)size;
            }

            PyObject **dictptr = (PyObject **) ((char *)source + dictoffset);
            dict = *dictptr;
        }

        if (dict != NULL)
        {
            CHECK_OBJECT(dict);

            Py_INCREF(dict);

            PyObject *called_object = PyDict_GetItem(dict, attr_name);

            if (called_object != NULL)
            {
                Py_INCREF(called_object);
                Py_XDECREF(descr);
                Py_DECREF(dict);

                PyObject *result = CALL_FUNCTION_WITH_ARGS5(
                    called_object,
                    args
                );
                Py_DECREF(called_object);
                return result;
            }

            Py_DECREF(dict);
        }

        if (func != NULL) {
            if (func == Nuitka_Function_Type.tp_descr_get) {
                PyObject *result = Nuitka_CallMethodFunctionPosArgs(
                    (struct Nuitka_FunctionObject const *)descr,
                    source,
                    args,
                    5
                );

                Py_DECREF(descr);

                return result;
            } else {
                PyObject *called_object = func(descr, source, (PyObject *)type);
                CHECK_OBJECT(called_object);

                Py_DECREF(descr);

                PyObject *result = CALL_FUNCTION_WITH_ARGS5(
                    called_object,
                    args
                );
                Py_DECREF(called_object);

                return result;
            }
        }

        if (descr != NULL) {
            CHECK_OBJECT(descr);

            PyObject *result = CALL_FUNCTION_WITH_ARGS5(
                descr,
                args
            );
            Py_DECREF(descr);

            return result;
        }

#if PYTHON_VERSION < 300
        PyErr_Format(
            PyExc_AttributeError,
            "'%s' object has no attribute '%s'",
            type->tp_name,
            PyString_AS_STRING( attr_name )
        );
#else
        PyErr_Format(
            PyExc_AttributeError,
            "'%s' object has no attribute '%U'",
            type->tp_name,
            attr_name
        );
#endif
        return NULL;
    }
#if PYTHON_VERSION < 300
    else if (type == &PyInstance_Type) {
        PyInstanceObject *source_instance = (PyInstanceObject *)source;

        // The special cases have their own variant on the code generation level
        // as we are called with constants only.
        assert(attr_name != const_str_plain___dict__);
        assert(attr_name != const_str_plain___class__);

        // Try the instance dict first.
        PyObject *called_object = GET_STRING_DICT_VALUE(
            (PyDictObject *)source_instance->in_dict,
            (PyStringObject *)attr_name
        );

        // Note: The "called_object" was found without taking a reference,
        // so we need not release it in this branch.
        if (called_object != NULL) {
            return CALL_FUNCTION_WITH_ARGS5(called_object, args);
        }

        // Then check the class dictionaries.
        called_object = FIND_ATTRIBUTE_IN_CLASS(
            source_instance->in_class,
            attr_name
        );

        // Note: The "called_object" was found without taking a reference,
        // so we need not release it in this branch.
        if (called_object != NULL) {
            descrgetfunc descr_get = Py_TYPE(called_object)->tp_descr_get;

            if (descr_get == Nuitka_Function_Type.tp_descr_get) {
                return Nuitka_CallMethodFunctionPosArgs(
                    (struct Nuitka_FunctionObject const *)called_object,
                    source,
                    args,
                    5
                );
            } else if (descr_get != NULL) {
                PyObject *method = descr_get(
                    called_object,
                    source,
                    (PyObject *)source_instance->in_class
                );

                if (unlikely(method == NULL)) {
                    return NULL;
                }

                PyObject *result = CALL_FUNCTION_WITH_ARGS5(method, args);
                Py_DECREF(method);
                return result;
            } else {
                return CALL_FUNCTION_WITH_ARGS5(called_object, args);
            }

        } else if (unlikely(source_instance->in_class->cl_getattr == NULL)) {
            PyErr_Format(
                PyExc_AttributeError,
                "%s instance has no attribute '%s'",
                PyString_AS_STRING( source_instance->in_class->cl_name ),
                PyString_AS_STRING( attr_name )
            );

            return NULL;
        } else {
            // Finally allow the "__getattr__" override to provide it or else
            // it's an error.

            PyObject *args2[] = {
                source,
                attr_name
            };

            called_object = CALL_FUNCTION_WITH_ARGS2(
                source_instance->in_class->cl_getattr,
                args2
            );

            if (unlikely(called_object == NULL))
            {
                return NULL;
            }

            PyObject *result = CALL_FUNCTION_WITH_ARGS5(
                called_object,
                args
            );
            Py_DECREF(called_object);
            return result;
        }
    }
#endif
    else if (type->tp_getattro != NULL) {
        PyObject *called_object = (*type->tp_getattro)(
            source,
            attr_name
        );

        if (unlikely(called_object == NULL)) {
            return NULL;
        }

        PyObject *result = CALL_FUNCTION_WITH_ARGS5(
            called_object,
            args
        );
        Py_DECREF(called_object);
        return result;
    } else if (type->tp_getattr != NULL) {
        PyObject *called_object = (*type->tp_getattr)(
            source,
            (char *)Nuitka_String_AsString_Unchecked(attr_name)
        );

        if (unlikely(called_object == NULL))
        {
            return NULL;
        }

        PyObject *result = CALL_FUNCTION_WITH_ARGS5(
            called_object,
            args
        );
        Py_DECREF(called_object);
        return result;
    } else {
        PyErr_Format(
            PyExc_AttributeError,
            "'%s' object has no attribute '%s'",
            type->tp_name,
            Nuitka_String_AsString_Unchecked(attr_name)
        );

        return NULL;
    }
}
/* Code to register embedded modules for meta path based loading if any. */

#include "nuitka/unfreezing.h"

/* Table for lookup to find compiled or bytecode modules included in this
 * binary or module, or put along this binary as extension modules. We do
 * our own loading for each of these.
 */
extern PyObject *modulecode_PyQt5(char const *);
extern PyObject *modulecode_PyQt5$uic(char const *);
extern PyObject *modulecode_PyQt5$uic$Compiler(char const *);
extern PyObject *modulecode_PyQt5$uic$Compiler$compiler(char const *);
extern PyObject *modulecode_PyQt5$uic$Compiler$indenter(char const *);
extern PyObject *modulecode_PyQt5$uic$Compiler$misc(char const *);
extern PyObject *modulecode_PyQt5$uic$Compiler$proxy_metaclass(char const *);
extern PyObject *modulecode_PyQt5$uic$Compiler$qobjectcreator(char const *);
extern PyObject *modulecode_PyQt5$uic$Compiler$qtproxies(char const *);
extern PyObject *modulecode_PyQt5$uic$Loader(char const *);
extern PyObject *modulecode_PyQt5$uic$Loader$loader(char const *);
extern PyObject *modulecode_PyQt5$uic$Loader$qobjectcreator(char const *);
extern PyObject *modulecode_PyQt5$uic$exceptions(char const *);
extern PyObject *modulecode_PyQt5$uic$icon_cache(char const *);
extern PyObject *modulecode_PyQt5$uic$objcreator(char const *);
extern PyObject *modulecode_PyQt5$uic$port_v2(char const *);
extern PyObject *modulecode_PyQt5$uic$port_v2$as_string(char const *);
extern PyObject *modulecode_PyQt5$uic$port_v2$ascii_upper(char const *);
extern PyObject *modulecode_PyQt5$uic$port_v2$proxy_base(char const *);
extern PyObject *modulecode_PyQt5$uic$port_v2$string_io(char const *);
extern PyObject *modulecode_PyQt5$uic$port_v3(char const *);
extern PyObject *modulecode_PyQt5$uic$port_v3$as_string(char const *);
extern PyObject *modulecode_PyQt5$uic$port_v3$ascii_upper(char const *);
extern PyObject *modulecode_PyQt5$uic$port_v3$proxy_base(char const *);
extern PyObject *modulecode_PyQt5$uic$port_v3$string_io(char const *);
extern PyObject *modulecode_PyQt5$uic$properties(char const *);
extern PyObject *modulecode_PyQt5$uic$uiparser(char const *);
extern PyObject *modulecode___main__(char const *);
extern PyObject *modulecode_pywin32_bootstrap(char const *);
static struct Nuitka_MetaPathBasedLoaderEntry meta_path_loader_entries[] =
{
    {"PyQt5", modulecode_PyQt5, 0, 0, NUITKA_PACKAGE_FLAG},
    {"PyQt5.QtCore", NULL, 0, 0, NUITKA_SHLIB_FLAG},
    {"PyQt5.QtGui", NULL, 0, 0, NUITKA_SHLIB_FLAG},
    {"PyQt5.QtWidgets", NULL, 0, 0, NUITKA_SHLIB_FLAG},
    {"PyQt5.sip", NULL, 0, 0, NUITKA_SHLIB_FLAG},
    {"PyQt5.uic", modulecode_PyQt5$uic, 0, 0, NUITKA_PACKAGE_FLAG},
    {"PyQt5.uic.Compiler", modulecode_PyQt5$uic$Compiler, 0, 0, NUITKA_PACKAGE_FLAG},
    {"PyQt5.uic.Compiler.compiler", modulecode_PyQt5$uic$Compiler$compiler, 0, 0, },
    {"PyQt5.uic.Compiler.indenter", modulecode_PyQt5$uic$Compiler$indenter, 0, 0, },
    {"PyQt5.uic.Compiler.misc", modulecode_PyQt5$uic$Compiler$misc, 0, 0, },
    {"PyQt5.uic.Compiler.proxy_metaclass", modulecode_PyQt5$uic$Compiler$proxy_metaclass, 0, 0, },
    {"PyQt5.uic.Compiler.qobjectcreator", modulecode_PyQt5$uic$Compiler$qobjectcreator, 0, 0, },
    {"PyQt5.uic.Compiler.qtproxies", modulecode_PyQt5$uic$Compiler$qtproxies, 0, 0, },
    {"PyQt5.uic.Loader", modulecode_PyQt5$uic$Loader, 0, 0, NUITKA_PACKAGE_FLAG},
    {"PyQt5.uic.Loader.loader", modulecode_PyQt5$uic$Loader$loader, 0, 0, },
    {"PyQt5.uic.Loader.qobjectcreator", modulecode_PyQt5$uic$Loader$qobjectcreator, 0, 0, },
    {"PyQt5.uic.exceptions", modulecode_PyQt5$uic$exceptions, 0, 0, },
    {"PyQt5.uic.icon_cache", modulecode_PyQt5$uic$icon_cache, 0, 0, },
    {"PyQt5.uic.objcreator", modulecode_PyQt5$uic$objcreator, 0, 0, },
    {"PyQt5.uic.port_v2", modulecode_PyQt5$uic$port_v2, 0, 0, NUITKA_PACKAGE_FLAG},
    {"PyQt5.uic.port_v2.as_string", modulecode_PyQt5$uic$port_v2$as_string, 0, 0, },
    {"PyQt5.uic.port_v2.ascii_upper", modulecode_PyQt5$uic$port_v2$ascii_upper, 0, 0, },
    {"PyQt5.uic.port_v2.proxy_base", modulecode_PyQt5$uic$port_v2$proxy_base, 0, 0, },
    {"PyQt5.uic.port_v2.string_io", modulecode_PyQt5$uic$port_v2$string_io, 0, 0, },
    {"PyQt5.uic.port_v3", modulecode_PyQt5$uic$port_v3, 0, 0, NUITKA_PACKAGE_FLAG},
    {"PyQt5.uic.port_v3.as_string", modulecode_PyQt5$uic$port_v3$as_string, 0, 0, },
    {"PyQt5.uic.port_v3.ascii_upper", modulecode_PyQt5$uic$port_v3$ascii_upper, 0, 0, },
    {"PyQt5.uic.port_v3.proxy_base", modulecode_PyQt5$uic$port_v3$proxy_base, 0, 0, },
    {"PyQt5.uic.port_v3.string_io", modulecode_PyQt5$uic$port_v3$string_io, 0, 0, },
    {"PyQt5.uic.properties", modulecode_PyQt5$uic$properties, 0, 0, },
    {"PyQt5.uic.uiparser", modulecode_PyQt5$uic$uiparser, 0, 0, },
    {"__main__", modulecode___main__, 0, 0, },
    {"_asyncio", NULL, 0, 0, NUITKA_SHLIB_FLAG},
    {"_bz2", NULL, 0, 0, NUITKA_SHLIB_FLAG},
    {"_ctypes", NULL, 0, 0, NUITKA_SHLIB_FLAG},
    {"_decimal", NULL, 0, 0, NUITKA_SHLIB_FLAG},
    {"_elementtree", NULL, 0, 0, NUITKA_SHLIB_FLAG},
    {"_hashlib", NULL, 0, 0, NUITKA_SHLIB_FLAG},
    {"_lzma", NULL, 0, 0, NUITKA_SHLIB_FLAG},
    {"_msi", NULL, 0, 0, NUITKA_SHLIB_FLAG},
    {"_multiprocessing", NULL, 0, 0, NUITKA_SHLIB_FLAG},
    {"_overlapped", NULL, 0, 0, NUITKA_SHLIB_FLAG},
    {"_queue", NULL, 0, 0, NUITKA_SHLIB_FLAG},
    {"_socket", NULL, 0, 0, NUITKA_SHLIB_FLAG},
    {"_sqlite3", NULL, 0, 0, NUITKA_SHLIB_FLAG},
    {"_ssl", NULL, 0, 0, NUITKA_SHLIB_FLAG},
    {"_tkinter", NULL, 0, 0, NUITKA_SHLIB_FLAG},
    {"io", NULL, 26409, 3477, NUITKA_BYTECODE_FLAG},
    {"logging", NULL, 29886, 64894, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"ntpath", NULL, 94780, 14680, NUITKA_BYTECODE_FLAG},
    {"os", NULL, 109460, 31420, NUITKA_BYTECODE_FLAG},
    {"pyexpat", NULL, 0, 0, NUITKA_SHLIB_FLAG},
    {"pywin32_bootstrap", modulecode_pywin32_bootstrap, 0, 0, },
    {"re", NULL, 140880, 14331, NUITKA_BYTECODE_FLAG},
    {"select", NULL, 0, 0, NUITKA_SHLIB_FLAG},
    {"site", NULL, 155211, 13330, NUITKA_BYTECODE_FLAG},
    {"string", NULL, 168541, 7323, NUITKA_BYTECODE_FLAG},
    {"unicodedata", NULL, 0, 0, NUITKA_SHLIB_FLAG},
    {"xml", NULL, 175864, 715, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"xml.etree", NULL, 176579, 154, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"xml.etree.ElementTree", NULL, 176733, 55635, NUITKA_BYTECODE_FLAG},
    {"__future__", NULL, 232368, 4154, NUITKA_BYTECODE_FLAG},
    {"_bootlocale", NULL, 236522, 1266, NUITKA_BYTECODE_FLAG},
    {"_compat_pickle", NULL, 237788, 5524, NUITKA_BYTECODE_FLAG},
    {"_dummy_thread", NULL, 243312, 6060, NUITKA_BYTECODE_FLAG},
    {"_markupbase", NULL, 249372, 7813, NUITKA_BYTECODE_FLAG},
    {"_osx_support", NULL, 257185, 9656, NUITKA_BYTECODE_FLAG},
    {"_py_abc", NULL, 266841, 4693, NUITKA_BYTECODE_FLAG},
    {"_pyio", NULL, 271534, 74102, NUITKA_BYTECODE_FLAG},
    {"_sitebuiltins", NULL, 345636, 3504, NUITKA_BYTECODE_FLAG},
    {"_strptime", NULL, 349140, 16067, NUITKA_BYTECODE_FLAG},
    {"_threading_local", NULL, 365207, 6469, NUITKA_BYTECODE_FLAG},
    {"aifc", NULL, 371676, 25497, NUITKA_BYTECODE_FLAG},
    {"argparse", NULL, 397173, 62300, NUITKA_BYTECODE_FLAG},
    {"ast", NULL, 459473, 16359, NUITKA_BYTECODE_FLAG},
    {"asynchat", NULL, 475832, 6874, NUITKA_BYTECODE_FLAG},
    {"asyncio", NULL, 482706, 773, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"asyncio.base_events", NULL, 483479, 51043, NUITKA_BYTECODE_FLAG},
    {"asyncio.base_futures", NULL, 534522, 1746, NUITKA_BYTECODE_FLAG},
    {"asyncio.base_subprocess", NULL, 536268, 9439, NUITKA_BYTECODE_FLAG},
    {"asyncio.base_tasks", NULL, 545707, 1915, NUITKA_BYTECODE_FLAG},
    {"asyncio.constants", NULL, 547622, 604, NUITKA_BYTECODE_FLAG},
    {"asyncio.coroutines", NULL, 548226, 6677, NUITKA_BYTECODE_FLAG},
    {"asyncio.events", NULL, 554903, 28080, NUITKA_BYTECODE_FLAG},
    {"asyncio.exceptions", NULL, 582983, 2521, NUITKA_BYTECODE_FLAG},
    {"asyncio.format_helpers", NULL, 585504, 2355, NUITKA_BYTECODE_FLAG},
    {"asyncio.futures", NULL, 587859, 11216, NUITKA_BYTECODE_FLAG},
    {"asyncio.locks", NULL, 599075, 16391, NUITKA_BYTECODE_FLAG},
    {"asyncio.log", NULL, 615466, 249, NUITKA_BYTECODE_FLAG},
    {"asyncio.proactor_events", NULL, 615715, 24117, NUITKA_BYTECODE_FLAG},
    {"asyncio.protocols", NULL, 639832, 8637, NUITKA_BYTECODE_FLAG},
    {"asyncio.queues", NULL, 648469, 8404, NUITKA_BYTECODE_FLAG},
    {"asyncio.runners", NULL, 656873, 1961, NUITKA_BYTECODE_FLAG},
    {"asyncio.selector_events", NULL, 658834, 29702, NUITKA_BYTECODE_FLAG},
    {"asyncio.sslproto", NULL, 688536, 21641, NUITKA_BYTECODE_FLAG},
    {"asyncio.staggered", NULL, 710177, 4141, NUITKA_BYTECODE_FLAG},
    {"asyncio.streams", NULL, 714318, 20663, NUITKA_BYTECODE_FLAG},
    {"asyncio.subprocess", NULL, 734981, 7381, NUITKA_BYTECODE_FLAG},
    {"asyncio.tasks", NULL, 742362, 23769, NUITKA_BYTECODE_FLAG},
    {"asyncio.transports", NULL, 766131, 12282, NUITKA_BYTECODE_FLAG},
    {"asyncio.trsock", NULL, 778413, 8506, NUITKA_BYTECODE_FLAG},
    {"asyncio.windows_events", NULL, 786919, 24606, NUITKA_BYTECODE_FLAG},
    {"asyncio.windows_utils", NULL, 811525, 4494, NUITKA_BYTECODE_FLAG},
    {"asyncore", NULL, 816019, 16051, NUITKA_BYTECODE_FLAG},
    {"bdb", NULL, 832070, 24944, NUITKA_BYTECODE_FLAG},
    {"binhex", NULL, 857014, 12158, NUITKA_BYTECODE_FLAG},
    {"bisect", NULL, 869172, 2377, NUITKA_BYTECODE_FLAG},
    {"cProfile", NULL, 871549, 5357, NUITKA_BYTECODE_FLAG},
    {"calendar", NULL, 876906, 27087, NUITKA_BYTECODE_FLAG},
    {"cgi", NULL, 903993, 26275, NUITKA_BYTECODE_FLAG},
    {"cgitb", NULL, 930268, 10173, NUITKA_BYTECODE_FLAG},
    {"chunk", NULL, 940441, 4862, NUITKA_BYTECODE_FLAG},
    {"cmd", NULL, 945303, 12649, NUITKA_BYTECODE_FLAG},
    {"code", NULL, 957952, 9936, NUITKA_BYTECODE_FLAG},
    {"codeop", NULL, 967888, 6320, NUITKA_BYTECODE_FLAG},
    {"colorsys", NULL, 974208, 3263, NUITKA_BYTECODE_FLAG},
    {"compileall", NULL, 977471, 9199, NUITKA_BYTECODE_FLAG},
    {"concurrent", NULL, 986670, 155, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"concurrent.futures", NULL, 986825, 1131, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"concurrent.futures._base", NULL, 987956, 21923, NUITKA_BYTECODE_FLAG},
    {"concurrent.futures.process", NULL, 1009879, 20323, NUITKA_BYTECODE_FLAG},
    {"concurrent.futures.thread", NULL, 1030202, 5841, NUITKA_BYTECODE_FLAG},
    {"configparser", NULL, 1036043, 45741, NUITKA_BYTECODE_FLAG},
    {"contextlib", NULL, 1081784, 20252, NUITKA_BYTECODE_FLAG},
    {"contextvars", NULL, 1102036, 266, NUITKA_BYTECODE_FLAG},
    {"copy", NULL, 1102302, 7010, NUITKA_BYTECODE_FLAG},
    {"csv", NULL, 1109312, 11933, NUITKA_BYTECODE_FLAG},
    {"ctypes", NULL, 1121245, 16395, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"ctypes._aix", NULL, 1137640, 9867, NUITKA_BYTECODE_FLAG},
    {"ctypes._endian", NULL, 1147507, 1952, NUITKA_BYTECODE_FLAG},
    {"ctypes.macholib", NULL, 1149459, 322, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"ctypes.macholib.dyld", NULL, 1149781, 4400, NUITKA_BYTECODE_FLAG},
    {"ctypes.macholib.dylib", NULL, 1154181, 1939, NUITKA_BYTECODE_FLAG},
    {"ctypes.macholib.framework", NULL, 1156120, 2219, NUITKA_BYTECODE_FLAG},
    {"ctypes.util", NULL, 1158339, 7784, NUITKA_BYTECODE_FLAG},
    {"ctypes.wintypes", NULL, 1166123, 5126, NUITKA_BYTECODE_FLAG},
    {"dataclasses", NULL, 1171249, 23650, NUITKA_BYTECODE_FLAG},
    {"datetime", NULL, 1194899, 57001, NUITKA_BYTECODE_FLAG},
    {"dbm", NULL, 1251900, 4215, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"dbm.dumb", NULL, 1256115, 7796, NUITKA_BYTECODE_FLAG},
    {"decimal", NULL, 1263911, 160726, NUITKA_BYTECODE_FLAG},
    {"difflib", NULL, 1424637, 59461, NUITKA_BYTECODE_FLAG},
    {"distutils", NULL, 1484098, 407, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"distutils._msvccompiler", NULL, 1484505, 14003, NUITKA_BYTECODE_FLAG},
    {"distutils.archive_util", NULL, 1498508, 6562, NUITKA_BYTECODE_FLAG},
    {"distutils.bcppcompiler", NULL, 1505070, 6546, NUITKA_BYTECODE_FLAG},
    {"distutils.ccompiler", NULL, 1511616, 33320, NUITKA_BYTECODE_FLAG},
    {"distutils.cmd", NULL, 1544936, 13971, NUITKA_BYTECODE_FLAG},
    {"distutils.command", NULL, 1558907, 566, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"distutils.command.bdist", NULL, 1559473, 3689, NUITKA_BYTECODE_FLAG},
    {"distutils.command.bdist_dumb", NULL, 1563162, 3615, NUITKA_BYTECODE_FLAG},
    {"distutils.command.bdist_msi", NULL, 1566777, 19646, NUITKA_BYTECODE_FLAG},
    {"distutils.command.bdist_rpm", NULL, 1586423, 12451, NUITKA_BYTECODE_FLAG},
    {"distutils.command.bdist_wininst", NULL, 1598874, 8512, NUITKA_BYTECODE_FLAG},
    {"distutils.command.build", NULL, 1607386, 3904, NUITKA_BYTECODE_FLAG},
    {"distutils.command.build_clib", NULL, 1611290, 4837, NUITKA_BYTECODE_FLAG},
    {"distutils.command.build_ext", NULL, 1616127, 16160, NUITKA_BYTECODE_FLAG},
    {"distutils.command.build_py", NULL, 1632287, 10485, NUITKA_BYTECODE_FLAG},
    {"distutils.command.build_scripts", NULL, 1642772, 4347, NUITKA_BYTECODE_FLAG},
    {"distutils.command.check", NULL, 1647119, 4908, NUITKA_BYTECODE_FLAG},
    {"distutils.command.clean", NULL, 1652027, 2123, NUITKA_BYTECODE_FLAG},
    {"distutils.command.config", NULL, 1654150, 10250, NUITKA_BYTECODE_FLAG},
    {"distutils.command.install", NULL, 1664400, 13595, NUITKA_BYTECODE_FLAG},
    {"distutils.command.install_data", NULL, 1677995, 2312, NUITKA_BYTECODE_FLAG},
    {"distutils.command.install_egg_info", NULL, 1680307, 3019, NUITKA_BYTECODE_FLAG},
    {"distutils.command.install_headers", NULL, 1683326, 1731, NUITKA_BYTECODE_FLAG},
    {"distutils.command.install_lib", NULL, 1685057, 5136, NUITKA_BYTECODE_FLAG},
    {"distutils.command.install_scripts", NULL, 1690193, 2164, NUITKA_BYTECODE_FLAG},
    {"distutils.command.register", NULL, 1692357, 8478, NUITKA_BYTECODE_FLAG},
    {"distutils.command.sdist", NULL, 1700835, 14539, NUITKA_BYTECODE_FLAG},
    {"distutils.command.upload", NULL, 1715374, 4962, NUITKA_BYTECODE_FLAG},
    {"distutils.config", NULL, 1720336, 3532, NUITKA_BYTECODE_FLAG},
    {"distutils.core", NULL, 1723868, 6637, NUITKA_BYTECODE_FLAG},
    {"distutils.cygwinccompiler", NULL, 1730505, 8635, NUITKA_BYTECODE_FLAG},
    {"distutils.debug", NULL, 1739140, 217, NUITKA_BYTECODE_FLAG},
    {"distutils.dep_util", NULL, 1739357, 2737, NUITKA_BYTECODE_FLAG},
    {"distutils.dir_util", NULL, 1742094, 5846, NUITKA_BYTECODE_FLAG},
    {"distutils.dist", NULL, 1747940, 34515, NUITKA_BYTECODE_FLAG},
    {"distutils.errors", NULL, 1782455, 5273, NUITKA_BYTECODE_FLAG},
    {"distutils.extension", NULL, 1787728, 6946, NUITKA_BYTECODE_FLAG},
    {"distutils.fancy_getopt", NULL, 1794674, 10679, NUITKA_BYTECODE_FLAG},
    {"distutils.file_util", NULL, 1805353, 5956, NUITKA_BYTECODE_FLAG},
    {"distutils.filelist", NULL, 1811309, 9890, NUITKA_BYTECODE_FLAG},
    {"distutils.log", NULL, 1821199, 2338, NUITKA_BYTECODE_FLAG},
    {"distutils.msvc9compiler", NULL, 1823537, 17533, NUITKA_BYTECODE_FLAG},
    {"distutils.msvccompiler", NULL, 1841070, 14746, NUITKA_BYTECODE_FLAG},
    {"distutils.spawn", NULL, 1855816, 5129, NUITKA_BYTECODE_FLAG},
    {"distutils.sysconfig", NULL, 1860945, 12124, NUITKA_BYTECODE_FLAG},
    {"distutils.text_file", NULL, 1873069, 8462, NUITKA_BYTECODE_FLAG},
    {"distutils.unixccompiler", NULL, 1881531, 6641, NUITKA_BYTECODE_FLAG},
    {"distutils.util", NULL, 1888172, 15569, NUITKA_BYTECODE_FLAG},
    {"distutils.version", NULL, 1903741, 7334, NUITKA_BYTECODE_FLAG},
    {"distutils.versionpredicate", NULL, 1911075, 5158, NUITKA_BYTECODE_FLAG},
    {"doctest", NULL, 1916233, 75857, NUITKA_BYTECODE_FLAG},
    {"dummy_threading", NULL, 1992090, 1133, NUITKA_BYTECODE_FLAG},
    {"email", NULL, 1993223, 1714, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"email._encoded_words", NULL, 1994937, 5709, NUITKA_BYTECODE_FLAG},
    {"email._header_value_parser", NULL, 2000646, 79810, NUITKA_BYTECODE_FLAG},
    {"email._parseaddr", NULL, 2080456, 12477, NUITKA_BYTECODE_FLAG},
    {"email._policybase", NULL, 2092933, 14833, NUITKA_BYTECODE_FLAG},
    {"email.base64mime", NULL, 2107766, 3258, NUITKA_BYTECODE_FLAG},
    {"email.charset", NULL, 2111024, 11482, NUITKA_BYTECODE_FLAG},
    {"email.contentmanager", NULL, 2122506, 7366, NUITKA_BYTECODE_FLAG},
    {"email.encoders", NULL, 2129872, 1635, NUITKA_BYTECODE_FLAG},
    {"email.errors", NULL, 2131507, 5928, NUITKA_BYTECODE_FLAG},
    {"email.feedparser", NULL, 2137435, 10665, NUITKA_BYTECODE_FLAG},
    {"email.generator", NULL, 2148100, 12505, NUITKA_BYTECODE_FLAG},
    {"email.header", NULL, 2160605, 16462, NUITKA_BYTECODE_FLAG},
    {"email.headerregistry", NULL, 2177067, 21923, NUITKA_BYTECODE_FLAG},
    {"email.iterators", NULL, 2198990, 1943, NUITKA_BYTECODE_FLAG},
    {"email.message", NULL, 2200933, 37901, NUITKA_BYTECODE_FLAG},
    {"email.mime", NULL, 2238834, 155, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"email.mime.application", NULL, 2238989, 1482, NUITKA_BYTECODE_FLAG},
    {"email.mime.audio", NULL, 2240471, 2647, NUITKA_BYTECODE_FLAG},
    {"email.mime.base", NULL, 2243118, 1064, NUITKA_BYTECODE_FLAG},
    {"email.mime.image", NULL, 2244182, 1927, NUITKA_BYTECODE_FLAG},
    {"email.mime.message", NULL, 2246109, 1305, NUITKA_BYTECODE_FLAG},
    {"email.mime.multipart", NULL, 2247414, 1525, NUITKA_BYTECODE_FLAG},
    {"email.mime.nonmultipart", NULL, 2248939, 787, NUITKA_BYTECODE_FLAG},
    {"email.mime.text", NULL, 2249726, 1334, NUITKA_BYTECODE_FLAG},
    {"email.parser", NULL, 2251060, 5745, NUITKA_BYTECODE_FLAG},
    {"email.policy", NULL, 2256805, 9681, NUITKA_BYTECODE_FLAG},
    {"email.quoprimime", NULL, 2266486, 7701, NUITKA_BYTECODE_FLAG},
    {"email.utils", NULL, 2274187, 9570, NUITKA_BYTECODE_FLAG},
    {"filecmp", NULL, 2283757, 8450, NUITKA_BYTECODE_FLAG},
    {"fileinput", NULL, 2292207, 13396, NUITKA_BYTECODE_FLAG},
    {"fnmatch", NULL, 2305603, 3355, NUITKA_BYTECODE_FLAG},
    {"formatter", NULL, 2308958, 17568, NUITKA_BYTECODE_FLAG},
    {"fractions", NULL, 2326526, 18762, NUITKA_BYTECODE_FLAG},
    {"ftplib", NULL, 2345288, 27872, NUITKA_BYTECODE_FLAG},
    {"getopt", NULL, 2373160, 6294, NUITKA_BYTECODE_FLAG},
    {"getpass", NULL, 2379454, 4201, NUITKA_BYTECODE_FLAG},
    {"gettext", NULL, 2383655, 17906, NUITKA_BYTECODE_FLAG},
    {"glob", NULL, 2401561, 4366, NUITKA_BYTECODE_FLAG},
    {"gzip", NULL, 2405927, 18214, NUITKA_BYTECODE_FLAG},
    {"hashlib", NULL, 2424141, 6750, NUITKA_BYTECODE_FLAG},
    {"hmac", NULL, 2430891, 6411, NUITKA_BYTECODE_FLAG},
    {"html", NULL, 2437302, 3641, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"html.entities", NULL, 2440943, 50552, NUITKA_BYTECODE_FLAG},
    {"html.parser", NULL, 2491495, 11221, NUITKA_BYTECODE_FLAG},
    {"http", NULL, 2502716, 6087, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"http.client", NULL, 2508803, 34042, NUITKA_BYTECODE_FLAG},
    {"http.cookiejar", NULL, 2542845, 53665, NUITKA_BYTECODE_FLAG},
    {"http.cookies", NULL, 2596510, 15291, NUITKA_BYTECODE_FLAG},
    {"http.server", NULL, 2611801, 34415, NUITKA_BYTECODE_FLAG},
    {"imaplib", NULL, 2646216, 41365, NUITKA_BYTECODE_FLAG},
    {"imghdr", NULL, 2687581, 4127, NUITKA_BYTECODE_FLAG},
    {"imp", NULL, 2691708, 9832, NUITKA_BYTECODE_FLAG},
    {"importlib.abc", NULL, 2701540, 13596, NUITKA_BYTECODE_FLAG},
    {"importlib.metadata", NULL, 2715136, 20863, NUITKA_BYTECODE_FLAG},
    {"importlib.resources", NULL, 2735999, 6503, NUITKA_BYTECODE_FLAG},
    {"importlib.util", NULL, 2742502, 9315, NUITKA_BYTECODE_FLAG},
    {"ipaddress", NULL, 2751817, 59582, NUITKA_BYTECODE_FLAG},
    {"json", NULL, 2811399, 12631, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"json.decoder", NULL, 2824030, 9867, NUITKA_BYTECODE_FLAG},
    {"json.encoder", NULL, 2833897, 11194, NUITKA_BYTECODE_FLAG},
    {"json.scanner", NULL, 2845091, 1974, NUITKA_BYTECODE_FLAG},
    {"json.tool", NULL, 2847065, 1826, NUITKA_BYTECODE_FLAG},
    {"lib2to3", NULL, 2848891, 152, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"lib2to3.btm_matcher", NULL, 2849043, 4900, NUITKA_BYTECODE_FLAG},
    {"lib2to3.btm_utils", NULL, 2853943, 6173, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixer_base", NULL, 2860116, 6276, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixer_util", NULL, 2866392, 12221, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes", NULL, 2878613, 158, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"lib2to3.fixes.fix_apply", NULL, 2878771, 1696, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_asserts", NULL, 2880467, 1295, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_basestring", NULL, 2881762, 679, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_buffer", NULL, 2882441, 824, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_dict", NULL, 2883265, 3351, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_except", NULL, 2886616, 2834, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_exec", NULL, 2889450, 1165, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_execfile", NULL, 2890615, 1713, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_exitfunc", NULL, 2892328, 2322, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_filter", NULL, 2894650, 2460, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_funcattrs", NULL, 2897110, 992, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_future", NULL, 2898102, 800, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_getcwdu", NULL, 2898902, 804, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_has_key", NULL, 2899706, 2955, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_idioms", NULL, 2902661, 3937, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_import", NULL, 2906598, 2803, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_imports", NULL, 2909401, 4411, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_imports2", NULL, 2913812, 562, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_input", NULL, 2914374, 966, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_intern", NULL, 2915340, 1150, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_isinstance", NULL, 2916490, 1567, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_itertools", NULL, 2918057, 1566, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_itertools_imports", NULL, 2919623, 1594, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_long", NULL, 2921217, 721, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_map", NULL, 2921938, 3113, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_metaclass", NULL, 2925051, 5363, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_methodattrs", NULL, 2930414, 954, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_ne", NULL, 2931368, 827, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_next", NULL, 2932195, 3099, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_nonzero", NULL, 2935294, 939, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_numliterals", NULL, 2936233, 1039, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_operator", NULL, 2937272, 4236, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_paren", NULL, 2941508, 1406, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_print", NULL, 2942914, 2359, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_raise", NULL, 2945273, 2269, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_raw_input", NULL, 2947542, 811, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_reduce", NULL, 2948353, 1144, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_reload", NULL, 2949497, 1162, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_renames", NULL, 2950659, 2023, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_repr", NULL, 2952682, 861, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_set_literal", NULL, 2953543, 1699, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_standarderror", NULL, 2955242, 736, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_sys_exc", NULL, 2955978, 1427, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_throw", NULL, 2957405, 1824, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_tuple_params", NULL, 2959229, 4607, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_types", NULL, 2963836, 1853, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_unicode", NULL, 2965689, 1565, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_urllib", NULL, 2967254, 6015, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_ws_comma", NULL, 2973269, 1135, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_xrange", NULL, 2974404, 2545, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_xreadlines", NULL, 2976949, 1139, NUITKA_BYTECODE_FLAG},
    {"lib2to3.fixes.fix_zip", NULL, 2978088, 1599, NUITKA_BYTECODE_FLAG},
    {"lib2to3.main", NULL, 2979687, 8631, NUITKA_BYTECODE_FLAG},
    {"lib2to3.patcomp", NULL, 2988318, 5662, NUITKA_BYTECODE_FLAG},
    {"lib2to3.pgen2", NULL, 2993980, 188, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"lib2to3.pgen2.driver", NULL, 2994168, 5164, NUITKA_BYTECODE_FLAG},
    {"lib2to3.pgen2.grammar", NULL, 2999332, 5674, NUITKA_BYTECODE_FLAG},
    {"lib2to3.pgen2.literals", NULL, 3005006, 1577, NUITKA_BYTECODE_FLAG},
    {"lib2to3.pgen2.parse", NULL, 3006583, 6521, NUITKA_BYTECODE_FLAG},
    {"lib2to3.pgen2.pgen", NULL, 3013104, 9799, NUITKA_BYTECODE_FLAG},
    {"lib2to3.pgen2.token", NULL, 3022903, 1887, NUITKA_BYTECODE_FLAG},
    {"lib2to3.pgen2.tokenize", NULL, 3024790, 15289, NUITKA_BYTECODE_FLAG},
    {"lib2to3.pygram", NULL, 3040079, 1283, NUITKA_BYTECODE_FLAG},
    {"lib2to3.pytree", NULL, 3041362, 24365, NUITKA_BYTECODE_FLAG},
    {"lib2to3.refactor", NULL, 3065727, 20463, NUITKA_BYTECODE_FLAG},
    {"logging", NULL, 29886, 64894, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"logging.config", NULL, 3086190, 23247, NUITKA_BYTECODE_FLAG},
    {"logging.handlers", NULL, 3109437, 43179, NUITKA_BYTECODE_FLAG},
    {"lzma", NULL, 3152616, 12041, NUITKA_BYTECODE_FLAG},
    {"mailbox", NULL, 3164657, 60287, NUITKA_BYTECODE_FLAG},
    {"mailcap", NULL, 3224944, 6499, NUITKA_BYTECODE_FLAG},
    {"mimetypes", NULL, 3231443, 16011, NUITKA_BYTECODE_FLAG},
    {"modulefinder", NULL, 3247454, 16135, NUITKA_BYTECODE_FLAG},
    {"msilib", NULL, 3263589, 16032, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"msilib.schema", NULL, 3279621, 52193, NUITKA_BYTECODE_FLAG},
    {"msilib.sequence", NULL, 3331814, 2623, NUITKA_BYTECODE_FLAG},
    {"msilib.text", NULL, 3334437, 8485, NUITKA_BYTECODE_FLAG},
    {"multiprocessing", NULL, 3342922, 685, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"multiprocessing.connection", NULL, 3343607, 25197, NUITKA_BYTECODE_FLAG},
    {"multiprocessing.context", NULL, 3368804, 12993, NUITKA_BYTECODE_FLAG},
    {"multiprocessing.dummy", NULL, 3381797, 3926, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"multiprocessing.dummy.connection", NULL, 3385723, 2571, NUITKA_BYTECODE_FLAG},
    {"multiprocessing.forkserver", NULL, 3388294, 8316, NUITKA_BYTECODE_FLAG},
    {"multiprocessing.heap", NULL, 3396610, 7660, NUITKA_BYTECODE_FLAG},
    {"multiprocessing.managers", NULL, 3404270, 41512, NUITKA_BYTECODE_FLAG},
    {"multiprocessing.pool", NULL, 3445782, 25073, NUITKA_BYTECODE_FLAG},
    {"multiprocessing.popen_spawn_win32", NULL, 3470855, 3484, NUITKA_BYTECODE_FLAG},
    {"multiprocessing.process", NULL, 3474339, 11024, NUITKA_BYTECODE_FLAG},
    {"multiprocessing.queues", NULL, 3485363, 9577, NUITKA_BYTECODE_FLAG},
    {"multiprocessing.reduction", NULL, 3494940, 8226, NUITKA_BYTECODE_FLAG},
    {"multiprocessing.resource_sharer", NULL, 3503166, 5279, NUITKA_BYTECODE_FLAG},
    {"multiprocessing.resource_tracker", NULL, 3508445, 5208, NUITKA_BYTECODE_FLAG},
    {"multiprocessing.shared_memory", NULL, 3513653, 14314, NUITKA_BYTECODE_FLAG},
    {"multiprocessing.sharedctypes", NULL, 3527967, 7072, NUITKA_BYTECODE_FLAG},
    {"multiprocessing.spawn", NULL, 3535039, 6719, NUITKA_BYTECODE_FLAG},
    {"multiprocessing.synchronize", NULL, 3541758, 11313, NUITKA_BYTECODE_FLAG},
    {"multiprocessing.util", NULL, 3553071, 10990, NUITKA_BYTECODE_FLAG},
    {"netrc", NULL, 3564061, 3800, NUITKA_BYTECODE_FLAG},
    {"nntplib", NULL, 3567861, 33997, NUITKA_BYTECODE_FLAG},
    {"nturl2path", NULL, 3601858, 1624, NUITKA_BYTECODE_FLAG},
    {"numbers", NULL, 3603482, 12225, NUITKA_BYTECODE_FLAG},
    {"optparse", NULL, 3615707, 48080, NUITKA_BYTECODE_FLAG},
    {"pathlib", NULL, 3663787, 43521, NUITKA_BYTECODE_FLAG},
    {"pdb", NULL, 3707308, 47177, NUITKA_BYTECODE_FLAG},
    {"pickle", NULL, 3754485, 46901, NUITKA_BYTECODE_FLAG},
    {"pickletools", NULL, 3801386, 67227, NUITKA_BYTECODE_FLAG},
    {"pipes", NULL, 3868613, 7818, NUITKA_BYTECODE_FLAG},
    {"pkgutil", NULL, 3876431, 16332, NUITKA_BYTECODE_FLAG},
    {"platform", NULL, 3892763, 24244, NUITKA_BYTECODE_FLAG},
    {"plistlib", NULL, 3917007, 26676, NUITKA_BYTECODE_FLAG},
    {"poplib", NULL, 3943683, 13482, NUITKA_BYTECODE_FLAG},
    {"posixpath", NULL, 3957165, 10451, NUITKA_BYTECODE_FLAG},
    {"pprint", NULL, 3967616, 16304, NUITKA_BYTECODE_FLAG},
    {"profile", NULL, 3983920, 14637, NUITKA_BYTECODE_FLAG},
    {"pstats", NULL, 3998557, 22076, NUITKA_BYTECODE_FLAG},
    {"py_compile", NULL, 4020633, 7417, NUITKA_BYTECODE_FLAG},
    {"pyclbr", NULL, 4028050, 10474, NUITKA_BYTECODE_FLAG},
    {"pydoc", NULL, 4038524, 84110, NUITKA_BYTECODE_FLAG},
    {"pydoc_data", NULL, 4122634, 155, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"pydoc_data.topics", NULL, 4122789, 419671, NUITKA_BYTECODE_FLAG},
    {"queue", NULL, 4542460, 10649, NUITKA_BYTECODE_FLAG},
    {"random", NULL, 4553109, 20131, NUITKA_BYTECODE_FLAG},
    {"rlcompleter", NULL, 4573240, 5778, NUITKA_BYTECODE_FLAG},
    {"runpy", NULL, 4579018, 8127, NUITKA_BYTECODE_FLAG},
    {"sched", NULL, 4587145, 6555, NUITKA_BYTECODE_FLAG},
    {"secrets", NULL, 4593700, 2213, NUITKA_BYTECODE_FLAG},
    {"selectors", NULL, 4595913, 16958, NUITKA_BYTECODE_FLAG},
    {"shelve", NULL, 4612871, 9513, NUITKA_BYTECODE_FLAG},
    {"shlex", NULL, 4622384, 7559, NUITKA_BYTECODE_FLAG},
    {"shutil", NULL, 4629943, 36592, NUITKA_BYTECODE_FLAG},
    {"signal", NULL, 4666535, 2866, NUITKA_BYTECODE_FLAG},
    {"site", NULL, 155211, 13330, NUITKA_BYTECODE_FLAG},
    {"smtpd", NULL, 4669401, 26486, NUITKA_BYTECODE_FLAG},
    {"smtplib", NULL, 4695887, 35336, NUITKA_BYTECODE_FLAG},
    {"sndhdr", NULL, 4731223, 6998, NUITKA_BYTECODE_FLAG},
    {"socket", NULL, 4738221, 27810, NUITKA_BYTECODE_FLAG},
    {"socketserver", NULL, 4766031, 24030, NUITKA_BYTECODE_FLAG},
    {"sqlite3", NULL, 4790061, 183, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"sqlite3.dbapi2", NULL, 4790244, 2527, NUITKA_BYTECODE_FLAG},
    {"sqlite3.dump", NULL, 4792771, 1952, NUITKA_BYTECODE_FLAG},
    {"ssl", NULL, 4794723, 44619, NUITKA_BYTECODE_FLAG},
    {"statistics", NULL, 4839342, 33532, NUITKA_BYTECODE_FLAG},
    {"string", NULL, 168541, 7323, NUITKA_BYTECODE_FLAG},
    {"subprocess", NULL, 4872874, 41963, NUITKA_BYTECODE_FLAG},
    {"sunau", NULL, 4914837, 17103, NUITKA_BYTECODE_FLAG},
    {"symbol", NULL, 4931940, 2427, NUITKA_BYTECODE_FLAG},
    {"symtable", NULL, 4934367, 11090, NUITKA_BYTECODE_FLAG},
    {"sysconfig", NULL, 4945457, 15643, NUITKA_BYTECODE_FLAG},
    {"tabnanny", NULL, 4961100, 7053, NUITKA_BYTECODE_FLAG},
    {"tarfile", NULL, 4968153, 62573, NUITKA_BYTECODE_FLAG},
    {"telnetlib", NULL, 5030726, 18260, NUITKA_BYTECODE_FLAG},
    {"tempfile", NULL, 5048986, 23482, NUITKA_BYTECODE_FLAG},
    {"textwrap", NULL, 5072468, 13542, NUITKA_BYTECODE_FLAG},
    {"this", NULL, 5086010, 1284, NUITKA_BYTECODE_FLAG},
    {"timeit", NULL, 5087294, 11762, NUITKA_BYTECODE_FLAG},
    {"tkinter", NULL, 5099056, 176025, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"tkinter.colorchooser", NULL, 5275081, 1148, NUITKA_BYTECODE_FLAG},
    {"tkinter.commondialog", NULL, 5276229, 1145, NUITKA_BYTECODE_FLAG},
    {"tkinter.constants", NULL, 5277374, 1677, NUITKA_BYTECODE_FLAG},
    {"tkinter.dialog", NULL, 5279051, 1495, NUITKA_BYTECODE_FLAG},
    {"tkinter.dnd", NULL, 5280546, 11285, NUITKA_BYTECODE_FLAG},
    {"tkinter.filedialog", NULL, 5291831, 12251, NUITKA_BYTECODE_FLAG},
    {"tkinter.font", NULL, 5304082, 6220, NUITKA_BYTECODE_FLAG},
    {"tkinter.messagebox", NULL, 5310302, 3014, NUITKA_BYTECODE_FLAG},
    {"tkinter.scrolledtext", NULL, 5313316, 2200, NUITKA_BYTECODE_FLAG},
    {"tkinter.simpledialog", NULL, 5315516, 10639, NUITKA_BYTECODE_FLAG},
    {"tkinter.tix", NULL, 5326155, 79541, NUITKA_BYTECODE_FLAG},
    {"tkinter.ttk", NULL, 5405696, 56780, NUITKA_BYTECODE_FLAG},
    {"trace", NULL, 5462476, 20019, NUITKA_BYTECODE_FLAG},
    {"traceback", NULL, 5482495, 19913, NUITKA_BYTECODE_FLAG},
    {"tracemalloc", NULL, 5502408, 17386, NUITKA_BYTECODE_FLAG},
    {"turtle", NULL, 5519794, 129963, NUITKA_BYTECODE_FLAG},
    {"typing", NULL, 5649757, 62373, NUITKA_BYTECODE_FLAG},
    {"unittest", NULL, 5712130, 3149, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"unittest.async_case", NULL, 5715279, 4163, NUITKA_BYTECODE_FLAG},
    {"unittest.case", NULL, 5719442, 50498, NUITKA_BYTECODE_FLAG},
    {"unittest.loader", NULL, 5769940, 14559, NUITKA_BYTECODE_FLAG},
    {"unittest.main", NULL, 5784499, 7557, NUITKA_BYTECODE_FLAG},
    {"unittest.mock", NULL, 5792056, 77549, NUITKA_BYTECODE_FLAG},
    {"unittest.result", NULL, 5869605, 7314, NUITKA_BYTECODE_FLAG},
    {"unittest.runner", NULL, 5876919, 7039, NUITKA_BYTECODE_FLAG},
    {"unittest.signals", NULL, 5883958, 2243, NUITKA_BYTECODE_FLAG},
    {"unittest.suite", NULL, 5886201, 9958, NUITKA_BYTECODE_FLAG},
    {"unittest.util", NULL, 5896159, 4454, NUITKA_BYTECODE_FLAG},
    {"urllib", NULL, 5900613, 151, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"urllib.error", NULL, 5900764, 2832, NUITKA_BYTECODE_FLAG},
    {"urllib.parse", NULL, 5903596, 33955, NUITKA_BYTECODE_FLAG},
    {"urllib.request", NULL, 5937551, 72227, NUITKA_BYTECODE_FLAG},
    {"urllib.response", NULL, 6009778, 3312, NUITKA_BYTECODE_FLAG},
    {"urllib.robotparser", NULL, 6013090, 7350, NUITKA_BYTECODE_FLAG},
    {"uu", NULL, 6020440, 3628, NUITKA_BYTECODE_FLAG},
    {"uuid", NULL, 6024068, 23689, NUITKA_BYTECODE_FLAG},
    {"venv", NULL, 6047757, 14454, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"wave", NULL, 6062211, 18172, NUITKA_BYTECODE_FLAG},
    {"weakref", NULL, 6080383, 19541, NUITKA_BYTECODE_FLAG},
    {"webbrowser", NULL, 6099924, 16502, NUITKA_BYTECODE_FLAG},
    {"wsgiref", NULL, 6116426, 747, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"wsgiref.handlers", NULL, 6117173, 16469, NUITKA_BYTECODE_FLAG},
    {"wsgiref.headers", NULL, 6133642, 7779, NUITKA_BYTECODE_FLAG},
    {"wsgiref.simple_server", NULL, 6141421, 5284, NUITKA_BYTECODE_FLAG},
    {"wsgiref.util", NULL, 6146705, 5435, NUITKA_BYTECODE_FLAG},
    {"wsgiref.validate", NULL, 6152140, 14778, NUITKA_BYTECODE_FLAG},
    {"xdrlib", NULL, 6166918, 8244, NUITKA_BYTECODE_FLAG},
    {"xml", NULL, 175864, 715, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"xml.dom", NULL, 6175162, 5553, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"xml.dom.NodeFilter", NULL, 6180715, 990, NUITKA_BYTECODE_FLAG},
    {"xml.dom.domreg", NULL, 6181705, 2873, NUITKA_BYTECODE_FLAG},
    {"xml.dom.expatbuilder", NULL, 6184578, 27364, NUITKA_BYTECODE_FLAG},
    {"xml.dom.minicompat", NULL, 6211942, 2765, NUITKA_BYTECODE_FLAG},
    {"xml.dom.minidom", NULL, 6214707, 55397, NUITKA_BYTECODE_FLAG},
    {"xml.dom.pulldom", NULL, 6270104, 10714, NUITKA_BYTECODE_FLAG},
    {"xml.dom.xmlbuilder", NULL, 6280818, 12517, NUITKA_BYTECODE_FLAG},
    {"xml.etree", NULL, 176579, 154, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"xml.etree.ElementInclude", NULL, 6293335, 1602, NUITKA_BYTECODE_FLAG},
    {"xml.etree.ElementPath", NULL, 6294937, 8457, NUITKA_BYTECODE_FLAG},
    {"xml.etree.ElementTree", NULL, 176733, 55635, NUITKA_BYTECODE_FLAG},
    {"xml.etree.cElementTree", NULL, 6303394, 196, NUITKA_BYTECODE_FLAG},
    {"xml.parsers", NULL, 6303590, 328, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"xml.parsers.expat", NULL, 6303918, 357, NUITKA_BYTECODE_FLAG},
    {"xml.sax", NULL, 6304275, 3242, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"xml.sax._exceptions", NULL, 6307517, 5467, NUITKA_BYTECODE_FLAG},
    {"xml.sax.expatreader", NULL, 6312984, 12518, NUITKA_BYTECODE_FLAG},
    {"xml.sax.handler", NULL, 6325502, 12445, NUITKA_BYTECODE_FLAG},
    {"xml.sax.saxutils", NULL, 6337947, 12942, NUITKA_BYTECODE_FLAG},
    {"xml.sax.xmlreader", NULL, 6350889, 16867, NUITKA_BYTECODE_FLAG},
    {"xmlrpc", NULL, 6367756, 151, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG},
    {"xmlrpc.client", NULL, 6367907, 34562, NUITKA_BYTECODE_FLAG},
    {"xmlrpc.server", NULL, 6402469, 29431, NUITKA_BYTECODE_FLAG},
    {"zipapp", NULL, 6431900, 5877, NUITKA_BYTECODE_FLAG},
    {"zipfile", NULL, 6437777, 58659, NUITKA_BYTECODE_FLAG},
    {NULL, NULL, 0, 0, 0}
};

void setupMetaPathBasedLoader(void) {
    static bool init_done = false;

    if (init_done == false)
    {
        registerMetaPathBasedUnfreezer(meta_path_loader_entries);
        init_done = true;
    }
}
