/* Generated code for Python module 'PyQt5'
 * created by Nuitka version 0.6.7
 *
 * This code is in part copyright 2019 Kay Hayen.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "nuitka/prelude.h"

#include "__helpers.h"

/* The "_module_PyQt5" is a Python object pointer of module type.
 *
 * Note: For full compatibility with CPython, every module variable access
 * needs to go through it except for cases where the module cannot possibly
 * have changed in the mean time.
 */

PyObject *module_PyQt5;
PyDictObject *moduledict_PyQt5;

/* The declarations of module constants used, if any. */
extern PyObject *const_str_plain_split;
extern PyObject *const_str_plain_add_dll_directory;
extern PyObject *const_str_plain_environ;
extern PyObject *const_str_plain___spec__;
extern PyObject *const_str_plain_sys;
static PyObject *const_str_digest_26cc7f045e3ae69df059a1cc13576df3;
extern PyObject *const_str_plain_NUITKA_PACKAGE_PyQt5;
extern PyObject *const_str_plain___file__;
extern PyObject *const_tuple_8b1fd1016da3eaee3145814dfe4be59a_tuple;
static PyObject *const_str_plain_find_qt;
static PyObject *const_str_digest_df1974ff46a1ff9194857455559dddee;
extern PyObject *const_int_0;
extern PyObject *const_str_plain_path;
static PyObject *const_str_digest_a82ca23324b234d324f2a2fbf06ef7b5;
static PyObject *const_str_plain_dll_dir;
extern PyObject *const_str_plain_origin;
extern PyObject *const_str_digest_5bfaf90dbd407b4fc29090c8f6415242;
extern PyObject *const_str_plain_os;
extern PyObject *const_str_plain___path__;
static PyObject *const_str_chr_59;
extern PyObject *const_tuple_empty;
extern PyObject *const_str_plain_get;
static PyObject *const_tuple_155cab72512ae194310e44a187a6c664_tuple;
static PyObject *const_str_plain_qtcore_dll;
extern PyObject *const_str_plain_has_location;
static PyObject *const_tuple_str_chr_59_tuple;
extern PyObject *const_str_plain_isfile;
static PyObject *const_str_digest_368391e872f8da88440a18c88b4d98e1;
extern PyObject *const_str_plain_PATH;
extern PyObject *const_str_plain_dirname;
static PyObject *const_str_plain_executable;
extern PyObject *const_str_plain___doc__;
extern PyObject *const_str_plain___cached__;
static PyObject *module_filename_obj;

/* Indicator if this modules private constants were created yet. */
static bool constants_created = false;

/* Function to create module private constants. */
static void createModuleConstants(void) {
    const_str_digest_26cc7f045e3ae69df059a1cc13576df3 = UNSTREAM_STRING_ASCII(&constant_bin[ 4115 ], 12, 0);
    const_str_plain_find_qt = UNSTREAM_STRING_ASCII(&constant_bin[ 36 ], 7, 1);
    const_str_digest_df1974ff46a1ff9194857455559dddee = UNSTREAM_STRING_ASCII(&constant_bin[ 4127 ], 14, 0);
    const_str_digest_a82ca23324b234d324f2a2fbf06ef7b5 = UNSTREAM_STRING_ASCII(&constant_bin[ 4141 ], 7, 0);
    const_str_plain_dll_dir = UNSTREAM_STRING_ASCII(&constant_bin[ 4148 ], 7, 1);
    const_str_chr_59 = UNSTREAM_STRING_ASCII(&constant_bin[ 4155 ], 1, 0);
    const_tuple_155cab72512ae194310e44a187a6c664_tuple = PyTuple_New(5);
    PyTuple_SET_ITEM(const_tuple_155cab72512ae194310e44a187a6c664_tuple, 0, const_str_plain_os); Py_INCREF(const_str_plain_os);
    PyTuple_SET_ITEM(const_tuple_155cab72512ae194310e44a187a6c664_tuple, 1, const_str_plain_sys); Py_INCREF(const_str_plain_sys);
    const_str_plain_qtcore_dll = UNSTREAM_STRING_ASCII(&constant_bin[ 4156 ], 10, 1);
    PyTuple_SET_ITEM(const_tuple_155cab72512ae194310e44a187a6c664_tuple, 2, const_str_plain_qtcore_dll); Py_INCREF(const_str_plain_qtcore_dll);
    PyTuple_SET_ITEM(const_tuple_155cab72512ae194310e44a187a6c664_tuple, 3, const_str_plain_dll_dir); Py_INCREF(const_str_plain_dll_dir);
    PyTuple_SET_ITEM(const_tuple_155cab72512ae194310e44a187a6c664_tuple, 4, const_str_plain_path); Py_INCREF(const_str_plain_path);
    const_tuple_str_chr_59_tuple = PyTuple_New(1);
    PyTuple_SET_ITEM(const_tuple_str_chr_59_tuple, 0, const_str_chr_59); Py_INCREF(const_str_chr_59);
    const_str_digest_368391e872f8da88440a18c88b4d98e1 = UNSTREAM_STRING_ASCII(&constant_bin[ 4166 ], 17, 0);
    const_str_plain_executable = UNSTREAM_STRING_ASCII(&constant_bin[ 4183 ], 10, 1);

    constants_created = true;
}

/* Function to verify module private constants for non-corruption. */
#ifndef __NUITKA_NO_ASSERT__
void checkModuleConstants_PyQt5(void) {
    // The module may not have been used at all, then ignore this.
    if (constants_created == false) return;


}
#endif

// The module code objects.
static PyCodeObject *codeobj_6f9e61663d66ca49ec84f48a6a426d96;
static PyCodeObject *codeobj_05a06dc9724609433466dc790fa9347c;

static void createModuleCodeObjects(void) {
    module_filename_obj = MAKE_RELATIVE_PATH(const_str_digest_368391e872f8da88440a18c88b4d98e1);
    codeobj_6f9e61663d66ca49ec84f48a6a426d96 = MAKE_CODEOBJECT(module_filename_obj, 1, CO_NOFREE, const_str_digest_df1974ff46a1ff9194857455559dddee, const_tuple_empty, 0, 0, 0);
    codeobj_05a06dc9724609433466dc790fa9347c = MAKE_CODEOBJECT(module_filename_obj, 19, CO_OPTIMIZED | CO_NEWLOCALS | CO_NOFREE, const_str_plain_find_qt, const_tuple_155cab72512ae194310e44a187a6c664_tuple, 0, 0, 0);
}

// The module function declarations.
static PyObject *MAKE_FUNCTION_PyQt5$$$function_1_find_qt();


// The module function definitions.
static PyObject *impl_PyQt5$$$function_1_find_qt(struct Nuitka_FunctionObject const *self, PyObject **python_pars) {
    // Preserve error status for checks
#ifndef __NUITKA_NO_ASSERT__
    NUITKA_MAY_BE_UNUSED bool had_error = ERROR_OCCURRED();
#endif

    // Local variable declarations.
    PyObject *var_os = NULL;
    PyObject *var_sys = NULL;
    PyObject *var_dll_dir = NULL;
    PyObject *var_path = NULL;
    nuitka_bool tmp_for_loop_1__break_indicator = NUITKA_BOOL_UNASSIGNED;
    PyObject *tmp_for_loop_1__for_iterator = NULL;
    PyObject *tmp_for_loop_1__iter_value = NULL;
    struct Nuitka_FrameObject *frame_05a06dc9724609433466dc790fa9347c;
    NUITKA_MAY_BE_UNUSED char const *type_description_1 = NULL;
    PyObject *exception_type = NULL;
    PyObject *exception_value = NULL;
    PyTracebackObject *exception_tb = NULL;
    NUITKA_MAY_BE_UNUSED int exception_lineno = 0;
    int tmp_res;
    bool tmp_result;
    PyObject *exception_keeper_type_1;
    PyObject *exception_keeper_value_1;
    PyTracebackObject *exception_keeper_tb_1;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_1;
    PyObject *exception_keeper_type_2;
    PyObject *exception_keeper_value_2;
    PyTracebackObject *exception_keeper_tb_2;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_2;
    PyObject *tmp_return_value = NULL;
    PyObject *exception_keeper_type_3;
    PyObject *exception_keeper_value_3;
    PyTracebackObject *exception_keeper_tb_3;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_3;
    PyObject *exception_keeper_type_4;
    PyObject *exception_keeper_value_4;
    PyTracebackObject *exception_keeper_tb_4;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_4;
    PyObject *exception_preserved_type_1;
    PyObject *exception_preserved_value_1;
    PyTracebackObject *exception_preserved_tb_1;
    PyObject *exception_keeper_type_5;
    PyObject *exception_keeper_value_5;
    PyTracebackObject *exception_keeper_tb_5;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_5;
    static struct Nuitka_FrameObject *cache_frame_05a06dc9724609433466dc790fa9347c = NULL;
    PyObject *exception_keeper_type_6;
    PyObject *exception_keeper_value_6;
    PyTracebackObject *exception_keeper_tb_6;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_6;

    // Actual function body.
    // Tried code:
    MAKE_OR_REUSE_FRAME(cache_frame_05a06dc9724609433466dc790fa9347c, codeobj_05a06dc9724609433466dc790fa9347c, module_PyQt5, sizeof(void *)+sizeof(void *)+sizeof(void *)+sizeof(void *)+sizeof(void *));
    frame_05a06dc9724609433466dc790fa9347c = cache_frame_05a06dc9724609433466dc790fa9347c;

    // Push the new frame as the currently active one.
    pushFrameStack(frame_05a06dc9724609433466dc790fa9347c);

    // Mark the frame object as in use, ref count 1 will be up for reuse.
    assert(Py_REFCNT(frame_05a06dc9724609433466dc790fa9347c) == 2); // Frame stack

    // Framed code:
    {
        PyObject *tmp_assign_source_1;
        PyObject *tmp_name_name_1;
        PyObject *tmp_globals_name_1;
        PyObject *tmp_locals_name_1;
        PyObject *tmp_fromlist_name_1;
        PyObject *tmp_level_name_1;
        tmp_name_name_1 = const_str_plain_os;
        tmp_globals_name_1 = (PyObject *)moduledict_PyQt5;
        tmp_locals_name_1 = Py_None;
        tmp_fromlist_name_1 = Py_None;
        tmp_level_name_1 = const_int_0;
        frame_05a06dc9724609433466dc790fa9347c->m_frame.f_lineno = 20;
        tmp_assign_source_1 = IMPORT_MODULE5(tmp_name_name_1, tmp_globals_name_1, tmp_locals_name_1, tmp_fromlist_name_1, tmp_level_name_1);
        if (tmp_assign_source_1 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 20;
            type_description_1 = "ooNoo";
            goto frame_exception_exit_1;
        }
        assert(var_os == NULL);
        var_os = tmp_assign_source_1;
    }
    {
        PyObject *tmp_assign_source_2;
        PyObject *tmp_name_name_2;
        PyObject *tmp_globals_name_2;
        PyObject *tmp_locals_name_2;
        PyObject *tmp_fromlist_name_2;
        PyObject *tmp_level_name_2;
        tmp_name_name_2 = const_str_plain_sys;
        tmp_globals_name_2 = (PyObject *)moduledict_PyQt5;
        tmp_locals_name_2 = Py_None;
        tmp_fromlist_name_2 = Py_None;
        tmp_level_name_2 = const_int_0;
        frame_05a06dc9724609433466dc790fa9347c->m_frame.f_lineno = 20;
        tmp_assign_source_2 = IMPORT_MODULE5(tmp_name_name_2, tmp_globals_name_2, tmp_locals_name_2, tmp_fromlist_name_2, tmp_level_name_2);
        assert(!(tmp_assign_source_2 == NULL));
        assert(var_sys == NULL);
        var_sys = tmp_assign_source_2;
    }
    {
        PyObject *tmp_assign_source_3;
        PyObject *tmp_called_name_1;
        PyObject *tmp_source_name_1;
        PyObject *tmp_source_name_2;
        PyObject *tmp_args_element_name_1;
        PyObject *tmp_source_name_3;
        CHECK_OBJECT(var_os);
        tmp_source_name_2 = var_os;
        tmp_source_name_1 = LOOKUP_ATTRIBUTE(tmp_source_name_2, const_str_plain_path);
        if (tmp_source_name_1 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 24;
            type_description_1 = "ooNoo";
            goto frame_exception_exit_1;
        }
        tmp_called_name_1 = LOOKUP_ATTRIBUTE(tmp_source_name_1, const_str_plain_dirname);
        Py_DECREF(tmp_source_name_1);
        if (tmp_called_name_1 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 24;
            type_description_1 = "ooNoo";
            goto frame_exception_exit_1;
        }
        CHECK_OBJECT(var_sys);
        tmp_source_name_3 = var_sys;
        tmp_args_element_name_1 = LOOKUP_ATTRIBUTE(tmp_source_name_3, const_str_plain_executable);
        if (tmp_args_element_name_1 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);
            Py_DECREF(tmp_called_name_1);

            exception_lineno = 24;
            type_description_1 = "ooNoo";
            goto frame_exception_exit_1;
        }
        frame_05a06dc9724609433466dc790fa9347c->m_frame.f_lineno = 24;
        tmp_assign_source_3 = CALL_FUNCTION_WITH_SINGLE_ARG(tmp_called_name_1, tmp_args_element_name_1);
        Py_DECREF(tmp_called_name_1);
        Py_DECREF(tmp_args_element_name_1);
        if (tmp_assign_source_3 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 24;
            type_description_1 = "ooNoo";
            goto frame_exception_exit_1;
        }
        assert(var_dll_dir == NULL);
        var_dll_dir = tmp_assign_source_3;
    }
    {
        nuitka_bool tmp_condition_result_1;
        PyObject *tmp_operand_name_1;
        PyObject *tmp_called_name_2;
        PyObject *tmp_source_name_4;
        PyObject *tmp_source_name_5;
        PyObject *tmp_args_element_name_2;
        PyObject *tmp_left_name_1;
        PyObject *tmp_right_name_1;
        CHECK_OBJECT(var_os);
        tmp_source_name_5 = var_os;
        tmp_source_name_4 = LOOKUP_ATTRIBUTE(tmp_source_name_5, const_str_plain_path);
        if (tmp_source_name_4 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 25;
            type_description_1 = "ooNoo";
            goto frame_exception_exit_1;
        }
        tmp_called_name_2 = LOOKUP_ATTRIBUTE(tmp_source_name_4, const_str_plain_isfile);
        Py_DECREF(tmp_source_name_4);
        if (tmp_called_name_2 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 25;
            type_description_1 = "ooNoo";
            goto frame_exception_exit_1;
        }
        CHECK_OBJECT(var_dll_dir);
        tmp_left_name_1 = var_dll_dir;
        tmp_right_name_1 = const_str_digest_26cc7f045e3ae69df059a1cc13576df3;
        tmp_args_element_name_2 = BINARY_OPERATION_ADD_OBJECT_UNICODE(tmp_left_name_1, tmp_right_name_1);
        if (tmp_args_element_name_2 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);
            Py_DECREF(tmp_called_name_2);

            exception_lineno = 25;
            type_description_1 = "ooNoo";
            goto frame_exception_exit_1;
        }
        frame_05a06dc9724609433466dc790fa9347c->m_frame.f_lineno = 25;
        tmp_operand_name_1 = CALL_FUNCTION_WITH_SINGLE_ARG(tmp_called_name_2, tmp_args_element_name_2);
        Py_DECREF(tmp_called_name_2);
        Py_DECREF(tmp_args_element_name_2);
        if (tmp_operand_name_1 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 25;
            type_description_1 = "ooNoo";
            goto frame_exception_exit_1;
        }
        tmp_res = CHECK_IF_TRUE(tmp_operand_name_1);
        Py_DECREF(tmp_operand_name_1);
        if (tmp_res == -1) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 25;
            type_description_1 = "ooNoo";
            goto frame_exception_exit_1;
        }
        tmp_condition_result_1 = (tmp_res == 0) ? NUITKA_BOOL_TRUE : NUITKA_BOOL_FALSE;
        if (tmp_condition_result_1 == NUITKA_BOOL_TRUE) {
            goto branch_yes_1;
        } else {
            goto branch_no_1;
        }
        branch_yes_1:;
        {
            PyObject *tmp_assign_source_4;
            PyObject *tmp_subscribed_name_1;
            PyObject *tmp_source_name_6;
            PyObject *tmp_subscript_name_1;
            CHECK_OBJECT(var_os);
            tmp_source_name_6 = var_os;
            tmp_subscribed_name_1 = LOOKUP_ATTRIBUTE(tmp_source_name_6, const_str_plain_environ);
            if (tmp_subscribed_name_1 == NULL) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 26;
                type_description_1 = "ooNoo";
                goto frame_exception_exit_1;
            }
            tmp_subscript_name_1 = const_str_plain_PATH;
            tmp_assign_source_4 = LOOKUP_SUBSCRIPT(tmp_subscribed_name_1, tmp_subscript_name_1);
            Py_DECREF(tmp_subscribed_name_1);
            if (tmp_assign_source_4 == NULL) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 26;
                type_description_1 = "ooNoo";
                goto frame_exception_exit_1;
            }
            assert(var_path == NULL);
            var_path = tmp_assign_source_4;
        }
        {
            PyObject *tmp_assign_source_5;
            PyObject *tmp_left_name_2;
            PyObject *tmp_called_name_3;
            PyObject *tmp_source_name_7;
            PyObject *tmp_source_name_8;
            PyObject *tmp_args_element_name_3;
            PyObject *tmp_mvar_value_1;
            PyObject *tmp_right_name_2;
            CHECK_OBJECT(var_os);
            tmp_source_name_8 = var_os;
            tmp_source_name_7 = LOOKUP_ATTRIBUTE(tmp_source_name_8, const_str_plain_path);
            if (tmp_source_name_7 == NULL) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 28;
                type_description_1 = "ooNoo";
                goto frame_exception_exit_1;
            }
            tmp_called_name_3 = LOOKUP_ATTRIBUTE(tmp_source_name_7, const_str_plain_dirname);
            Py_DECREF(tmp_source_name_7);
            if (tmp_called_name_3 == NULL) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 28;
                type_description_1 = "ooNoo";
                goto frame_exception_exit_1;
            }
            tmp_mvar_value_1 = GET_STRING_DICT_VALUE(moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___file__);

            if (unlikely(tmp_mvar_value_1 == NULL)) {
                tmp_mvar_value_1 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain___file__);
            }

            if (tmp_mvar_value_1 == NULL) {
                Py_DECREF(tmp_called_name_3);
                exception_type = PyExc_NameError;
                Py_INCREF(exception_type);
                exception_value = UNSTREAM_STRING(&constant_bin[ 0 ], 30, 0);
                exception_tb = NULL;
                NORMALIZE_EXCEPTION(&exception_type, &exception_value, &exception_tb);
                CHAIN_EXCEPTION(exception_value);

                exception_lineno = 28;
                type_description_1 = "ooNoo";
                goto frame_exception_exit_1;
            }

            tmp_args_element_name_3 = tmp_mvar_value_1;
            frame_05a06dc9724609433466dc790fa9347c->m_frame.f_lineno = 28;
            tmp_left_name_2 = CALL_FUNCTION_WITH_SINGLE_ARG(tmp_called_name_3, tmp_args_element_name_3);
            Py_DECREF(tmp_called_name_3);
            if (tmp_left_name_2 == NULL) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 28;
                type_description_1 = "ooNoo";
                goto frame_exception_exit_1;
            }
            tmp_right_name_2 = const_str_digest_a82ca23324b234d324f2a2fbf06ef7b5;
            tmp_assign_source_5 = BINARY_OPERATION_ADD_OBJECT_UNICODE(tmp_left_name_2, tmp_right_name_2);
            Py_DECREF(tmp_left_name_2);
            if (tmp_assign_source_5 == NULL) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 28;
                type_description_1 = "ooNoo";
                goto frame_exception_exit_1;
            }
            {
                PyObject *old = var_dll_dir;
                assert(old != NULL);
                var_dll_dir = tmp_assign_source_5;
                Py_DECREF(old);
            }

        }
        {
            nuitka_bool tmp_condition_result_2;
            PyObject *tmp_called_name_4;
            PyObject *tmp_source_name_9;
            PyObject *tmp_source_name_10;
            PyObject *tmp_call_result_1;
            PyObject *tmp_args_element_name_4;
            PyObject *tmp_left_name_3;
            PyObject *tmp_right_name_3;
            int tmp_truth_name_1;
            CHECK_OBJECT(var_os);
            tmp_source_name_10 = var_os;
            tmp_source_name_9 = LOOKUP_ATTRIBUTE(tmp_source_name_10, const_str_plain_path);
            if (tmp_source_name_9 == NULL) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 29;
                type_description_1 = "ooNoo";
                goto frame_exception_exit_1;
            }
            tmp_called_name_4 = LOOKUP_ATTRIBUTE(tmp_source_name_9, const_str_plain_isfile);
            Py_DECREF(tmp_source_name_9);
            if (tmp_called_name_4 == NULL) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 29;
                type_description_1 = "ooNoo";
                goto frame_exception_exit_1;
            }
            CHECK_OBJECT(var_dll_dir);
            tmp_left_name_3 = var_dll_dir;
            tmp_right_name_3 = const_str_digest_26cc7f045e3ae69df059a1cc13576df3;
            tmp_args_element_name_4 = BINARY_OPERATION_ADD_OBJECT_UNICODE(tmp_left_name_3, tmp_right_name_3);
            if (tmp_args_element_name_4 == NULL) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);
                Py_DECREF(tmp_called_name_4);

                exception_lineno = 29;
                type_description_1 = "ooNoo";
                goto frame_exception_exit_1;
            }
            frame_05a06dc9724609433466dc790fa9347c->m_frame.f_lineno = 29;
            tmp_call_result_1 = CALL_FUNCTION_WITH_SINGLE_ARG(tmp_called_name_4, tmp_args_element_name_4);
            Py_DECREF(tmp_called_name_4);
            Py_DECREF(tmp_args_element_name_4);
            if (tmp_call_result_1 == NULL) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 29;
                type_description_1 = "ooNoo";
                goto frame_exception_exit_1;
            }
            tmp_truth_name_1 = CHECK_IF_TRUE(tmp_call_result_1);
            if (tmp_truth_name_1 == -1) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);
                Py_DECREF(tmp_call_result_1);

                exception_lineno = 29;
                type_description_1 = "ooNoo";
                goto frame_exception_exit_1;
            }
            tmp_condition_result_2 = tmp_truth_name_1 == 1 ? NUITKA_BOOL_TRUE : NUITKA_BOOL_FALSE;
            Py_DECREF(tmp_call_result_1);
            if (tmp_condition_result_2 == NUITKA_BOOL_TRUE) {
                goto branch_yes_2;
            } else {
                goto branch_no_2;
            }
            branch_yes_2:;
            {
                PyObject *tmp_assign_source_6;
                PyObject *tmp_left_name_4;
                PyObject *tmp_left_name_5;
                PyObject *tmp_right_name_4;
                PyObject *tmp_right_name_5;
                CHECK_OBJECT(var_dll_dir);
                tmp_left_name_5 = var_dll_dir;
                tmp_right_name_4 = const_str_chr_59;
                tmp_left_name_4 = BINARY_OPERATION_ADD_OBJECT_UNICODE(tmp_left_name_5, tmp_right_name_4);
                if (tmp_left_name_4 == NULL) {
                    assert(ERROR_OCCURRED());

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                    exception_lineno = 30;
                    type_description_1 = "ooNoo";
                    goto frame_exception_exit_1;
                }
                CHECK_OBJECT(var_path);
                tmp_right_name_5 = var_path;
                tmp_assign_source_6 = BINARY_OPERATION_ADD_OBJECT_OBJECT(tmp_left_name_4, tmp_right_name_5);
                Py_DECREF(tmp_left_name_4);
                if (tmp_assign_source_6 == NULL) {
                    assert(ERROR_OCCURRED());

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                    exception_lineno = 30;
                    type_description_1 = "ooNoo";
                    goto frame_exception_exit_1;
                }
                {
                    PyObject *old = var_path;
                    assert(old != NULL);
                    var_path = tmp_assign_source_6;
                    Py_DECREF(old);
                }

            }
            {
                PyObject *tmp_ass_subvalue_1;
                PyObject *tmp_ass_subscribed_1;
                PyObject *tmp_source_name_11;
                PyObject *tmp_ass_subscript_1;
                CHECK_OBJECT(var_path);
                tmp_ass_subvalue_1 = var_path;
                CHECK_OBJECT(var_os);
                tmp_source_name_11 = var_os;
                tmp_ass_subscribed_1 = LOOKUP_ATTRIBUTE(tmp_source_name_11, const_str_plain_environ);
                if (tmp_ass_subscribed_1 == NULL) {
                    assert(ERROR_OCCURRED());

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                    exception_lineno = 31;
                    type_description_1 = "ooNoo";
                    goto frame_exception_exit_1;
                }
                tmp_ass_subscript_1 = const_str_plain_PATH;
                tmp_result = SET_SUBSCRIPT(tmp_ass_subscribed_1, tmp_ass_subscript_1, tmp_ass_subvalue_1);
                Py_DECREF(tmp_ass_subscribed_1);
                if (tmp_result == false) {
                    assert(ERROR_OCCURRED());

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                    exception_lineno = 31;
                    type_description_1 = "ooNoo";
                    goto frame_exception_exit_1;
                }
            }
            goto branch_end_2;
            branch_no_2:;
            {
                nuitka_bool tmp_assign_source_7;
                tmp_assign_source_7 = NUITKA_BOOL_FALSE;
                tmp_for_loop_1__break_indicator = tmp_assign_source_7;
            }
            // Tried code:
            {
                PyObject *tmp_assign_source_8;
                PyObject *tmp_iter_arg_1;
                PyObject *tmp_called_instance_1;
                CHECK_OBJECT(var_path);
                tmp_called_instance_1 = var_path;
                frame_05a06dc9724609433466dc790fa9347c->m_frame.f_lineno = 33;
                tmp_iter_arg_1 = CALL_METHOD_WITH_ARGS1(tmp_called_instance_1, const_str_plain_split, &PyTuple_GET_ITEM(const_tuple_str_chr_59_tuple, 0));

                if (tmp_iter_arg_1 == NULL) {
                    assert(ERROR_OCCURRED());

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                    exception_lineno = 33;
                    type_description_1 = "ooNoo";
                    goto try_except_handler_2;
                }
                tmp_assign_source_8 = MAKE_ITERATOR(tmp_iter_arg_1);
                Py_DECREF(tmp_iter_arg_1);
                if (tmp_assign_source_8 == NULL) {
                    assert(ERROR_OCCURRED());

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                    exception_lineno = 33;
                    type_description_1 = "ooNoo";
                    goto try_except_handler_2;
                }
                assert(tmp_for_loop_1__for_iterator == NULL);
                tmp_for_loop_1__for_iterator = tmp_assign_source_8;
            }
            // Tried code:
            loop_start_1:;
            // Tried code:
            {
                PyObject *tmp_assign_source_9;
                PyObject *tmp_value_name_1;
                CHECK_OBJECT(tmp_for_loop_1__for_iterator);
                tmp_value_name_1 = tmp_for_loop_1__for_iterator;
                tmp_assign_source_9 = ITERATOR_NEXT(tmp_value_name_1);
                if (tmp_assign_source_9 == NULL) {
                    if (!ERROR_OCCURRED()) {
                        exception_type = PyExc_StopIteration;
                        Py_INCREF(exception_type);
                        exception_value = NULL;
                        exception_tb = NULL;
                    } else {
                        FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);
                    }


                    type_description_1 = "ooNoo";
                    exception_lineno = 33;
                    goto try_except_handler_4;
                }
                {
                    PyObject *old = tmp_for_loop_1__iter_value;
                    tmp_for_loop_1__iter_value = tmp_assign_source_9;
                    Py_XDECREF(old);
                }

            }
            goto try_end_1;
            // Exception handler code:
            try_except_handler_4:;
            exception_keeper_type_1 = exception_type;
            exception_keeper_value_1 = exception_value;
            exception_keeper_tb_1 = exception_tb;
            exception_keeper_lineno_1 = exception_lineno;
            exception_type = NULL;
            exception_value = NULL;
            exception_tb = NULL;
            exception_lineno = 0;

            {
                nuitka_bool tmp_condition_result_3;
                PyObject *tmp_compexpr_left_1;
                PyObject *tmp_compexpr_right_1;
                tmp_compexpr_left_1 = exception_keeper_type_1;
                tmp_compexpr_right_1 = PyExc_StopIteration;
                tmp_res = EXCEPTION_MATCH_BOOL(tmp_compexpr_left_1, tmp_compexpr_right_1);
                if (tmp_res == -1) {
                    assert(ERROR_OCCURRED());

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);

                    Py_DECREF(exception_keeper_type_1);
                    Py_XDECREF(exception_keeper_value_1);
                    Py_XDECREF(exception_keeper_tb_1);

                    exception_lineno = 33;
                    type_description_1 = "ooNoo";
                    goto try_except_handler_3;
                }
                tmp_condition_result_3 = (tmp_res != 0) ? NUITKA_BOOL_TRUE : NUITKA_BOOL_FALSE;
                if (tmp_condition_result_3 == NUITKA_BOOL_TRUE) {
                    goto branch_yes_3;
                } else {
                    goto branch_no_3;
                }
                branch_yes_3:;
                {
                    nuitka_bool tmp_assign_source_10;
                    tmp_assign_source_10 = NUITKA_BOOL_TRUE;
                    tmp_for_loop_1__break_indicator = tmp_assign_source_10;
                }
                Py_DECREF(exception_keeper_type_1);
                Py_XDECREF(exception_keeper_value_1);
                Py_XDECREF(exception_keeper_tb_1);
                goto loop_end_1;
                goto branch_end_3;
                branch_no_3:;
                // Re-raise.
                exception_type = exception_keeper_type_1;
                exception_value = exception_keeper_value_1;
                exception_tb = exception_keeper_tb_1;
                exception_lineno = exception_keeper_lineno_1;

                goto try_except_handler_3;
                branch_end_3:;
            }
            // End of try:
            try_end_1:;
            {
                PyObject *tmp_assign_source_11;
                CHECK_OBJECT(tmp_for_loop_1__iter_value);
                tmp_assign_source_11 = tmp_for_loop_1__iter_value;
                {
                    PyObject *old = var_dll_dir;
                    assert(old != NULL);
                    var_dll_dir = tmp_assign_source_11;
                    Py_INCREF(var_dll_dir);
                    Py_DECREF(old);
                }

            }
            {
                nuitka_bool tmp_condition_result_4;
                PyObject *tmp_called_name_5;
                PyObject *tmp_source_name_12;
                PyObject *tmp_source_name_13;
                PyObject *tmp_call_result_2;
                PyObject *tmp_args_element_name_5;
                PyObject *tmp_left_name_6;
                PyObject *tmp_right_name_6;
                int tmp_truth_name_2;
                CHECK_OBJECT(var_os);
                tmp_source_name_13 = var_os;
                tmp_source_name_12 = LOOKUP_ATTRIBUTE(tmp_source_name_13, const_str_plain_path);
                if (tmp_source_name_12 == NULL) {
                    assert(ERROR_OCCURRED());

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                    exception_lineno = 34;
                    type_description_1 = "ooNoo";
                    goto try_except_handler_3;
                }
                tmp_called_name_5 = LOOKUP_ATTRIBUTE(tmp_source_name_12, const_str_plain_isfile);
                Py_DECREF(tmp_source_name_12);
                if (tmp_called_name_5 == NULL) {
                    assert(ERROR_OCCURRED());

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                    exception_lineno = 34;
                    type_description_1 = "ooNoo";
                    goto try_except_handler_3;
                }
                CHECK_OBJECT(var_dll_dir);
                tmp_left_name_6 = var_dll_dir;
                tmp_right_name_6 = const_str_digest_26cc7f045e3ae69df059a1cc13576df3;
                tmp_args_element_name_5 = BINARY_OPERATION_ADD_OBJECT_UNICODE(tmp_left_name_6, tmp_right_name_6);
                if (tmp_args_element_name_5 == NULL) {
                    assert(ERROR_OCCURRED());

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);
                    Py_DECREF(tmp_called_name_5);

                    exception_lineno = 34;
                    type_description_1 = "ooNoo";
                    goto try_except_handler_3;
                }
                frame_05a06dc9724609433466dc790fa9347c->m_frame.f_lineno = 34;
                tmp_call_result_2 = CALL_FUNCTION_WITH_SINGLE_ARG(tmp_called_name_5, tmp_args_element_name_5);
                Py_DECREF(tmp_called_name_5);
                Py_DECREF(tmp_args_element_name_5);
                if (tmp_call_result_2 == NULL) {
                    assert(ERROR_OCCURRED());

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                    exception_lineno = 34;
                    type_description_1 = "ooNoo";
                    goto try_except_handler_3;
                }
                tmp_truth_name_2 = CHECK_IF_TRUE(tmp_call_result_2);
                if (tmp_truth_name_2 == -1) {
                    assert(ERROR_OCCURRED());

                    FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);
                    Py_DECREF(tmp_call_result_2);

                    exception_lineno = 34;
                    type_description_1 = "ooNoo";
                    goto try_except_handler_3;
                }
                tmp_condition_result_4 = tmp_truth_name_2 == 1 ? NUITKA_BOOL_TRUE : NUITKA_BOOL_FALSE;
                Py_DECREF(tmp_call_result_2);
                if (tmp_condition_result_4 == NUITKA_BOOL_TRUE) {
                    goto branch_yes_4;
                } else {
                    goto branch_no_4;
                }
                branch_yes_4:;
                goto loop_end_1;
                branch_no_4:;
            }
            if (CONSIDER_THREADING() == false) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 33;
                type_description_1 = "ooNoo";
                goto try_except_handler_3;
            }
            goto loop_start_1;
            loop_end_1:;
            goto try_end_2;
            // Exception handler code:
            try_except_handler_3:;
            exception_keeper_type_2 = exception_type;
            exception_keeper_value_2 = exception_value;
            exception_keeper_tb_2 = exception_tb;
            exception_keeper_lineno_2 = exception_lineno;
            exception_type = NULL;
            exception_value = NULL;
            exception_tb = NULL;
            exception_lineno = 0;

            Py_XDECREF(tmp_for_loop_1__iter_value);
            tmp_for_loop_1__iter_value = NULL;

            CHECK_OBJECT((PyObject *)tmp_for_loop_1__for_iterator);
            Py_DECREF(tmp_for_loop_1__for_iterator);
            tmp_for_loop_1__for_iterator = NULL;

            // Re-raise.
            exception_type = exception_keeper_type_2;
            exception_value = exception_keeper_value_2;
            exception_tb = exception_keeper_tb_2;
            exception_lineno = exception_keeper_lineno_2;

            goto try_except_handler_2;
            // End of try:
            try_end_2:;
            Py_XDECREF(tmp_for_loop_1__iter_value);
            tmp_for_loop_1__iter_value = NULL;

            CHECK_OBJECT((PyObject *)tmp_for_loop_1__for_iterator);
            Py_DECREF(tmp_for_loop_1__for_iterator);
            tmp_for_loop_1__for_iterator = NULL;

            {
                nuitka_bool tmp_condition_result_5;
                nuitka_bool tmp_compexpr_left_2;
                nuitka_bool tmp_compexpr_right_2;
                assert(tmp_for_loop_1__break_indicator != NUITKA_BOOL_UNASSIGNED);
                tmp_compexpr_left_2 = tmp_for_loop_1__break_indicator;
                tmp_compexpr_right_2 = NUITKA_BOOL_TRUE;
                tmp_condition_result_5 = (tmp_compexpr_left_2 == tmp_compexpr_right_2) ? NUITKA_BOOL_TRUE : NUITKA_BOOL_FALSE;
                if (tmp_condition_result_5 == NUITKA_BOOL_TRUE) {
                    goto branch_yes_5;
                } else {
                    goto branch_no_5;
                }
                branch_yes_5:;
                tmp_return_value = Py_None;
                Py_INCREF(tmp_return_value);
                goto try_return_handler_2;
                branch_no_5:;
            }
            goto try_end_3;
            // Return handler code:
            try_return_handler_2:;
            goto frame_return_exit_1;
            // Exception handler code:
            try_except_handler_2:;
            exception_keeper_type_3 = exception_type;
            exception_keeper_value_3 = exception_value;
            exception_keeper_tb_3 = exception_tb;
            exception_keeper_lineno_3 = exception_lineno;
            exception_type = NULL;
            exception_value = NULL;
            exception_tb = NULL;
            exception_lineno = 0;

            // Re-raise.
            exception_type = exception_keeper_type_3;
            exception_value = exception_keeper_value_3;
            exception_tb = exception_keeper_tb_3;
            exception_lineno = exception_keeper_lineno_3;

            goto frame_exception_exit_1;
            // End of try:
            try_end_3:;
            branch_end_2:;
        }
        branch_no_1:;
    }
    // Tried code:
    {
        PyObject *tmp_called_name_6;
        PyObject *tmp_source_name_14;
        PyObject *tmp_call_result_3;
        PyObject *tmp_args_element_name_6;
        CHECK_OBJECT(var_os);
        tmp_source_name_14 = var_os;
        tmp_called_name_6 = LOOKUP_ATTRIBUTE(tmp_source_name_14, const_str_plain_add_dll_directory);
        if (tmp_called_name_6 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;
            type_description_1 = "ooNoo";
            goto try_except_handler_5;
        }
        if (var_dll_dir == NULL) {
            Py_DECREF(tmp_called_name_6);
            exception_type = PyExc_UnboundLocalError;
            Py_INCREF(exception_type);
            exception_value = PyUnicode_FromFormat("local variable '%s' referenced before assignment", "dll_dir");
            exception_tb = NULL;
            NORMALIZE_EXCEPTION(&exception_type, &exception_value, &exception_tb);
            CHAIN_EXCEPTION(exception_value);

            exception_lineno = 40;
            type_description_1 = "ooNoo";
            goto try_except_handler_5;
        }

        tmp_args_element_name_6 = var_dll_dir;
        frame_05a06dc9724609433466dc790fa9347c->m_frame.f_lineno = 40;
        tmp_call_result_3 = CALL_FUNCTION_WITH_SINGLE_ARG(tmp_called_name_6, tmp_args_element_name_6);
        Py_DECREF(tmp_called_name_6);
        if (tmp_call_result_3 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;
            type_description_1 = "ooNoo";
            goto try_except_handler_5;
        }
        Py_DECREF(tmp_call_result_3);
    }
    goto try_end_4;
    // Exception handler code:
    try_except_handler_5:;
    exception_keeper_type_4 = exception_type;
    exception_keeper_value_4 = exception_value;
    exception_keeper_tb_4 = exception_tb;
    exception_keeper_lineno_4 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    // Preserve existing published exception.
    exception_preserved_type_1 = EXC_TYPE(PyThreadState_GET());
    Py_XINCREF(exception_preserved_type_1);
    exception_preserved_value_1 = EXC_VALUE(PyThreadState_GET());
    Py_XINCREF(exception_preserved_value_1);
    exception_preserved_tb_1 = (PyTracebackObject *)EXC_TRACEBACK(PyThreadState_GET());
    Py_XINCREF(exception_preserved_tb_1);

    if (exception_keeper_tb_4 == NULL) {
        exception_keeper_tb_4 = MAKE_TRACEBACK(frame_05a06dc9724609433466dc790fa9347c, exception_keeper_lineno_4);
    } else if (exception_keeper_lineno_4 != 0) {
        exception_keeper_tb_4 = ADD_TRACEBACK(exception_keeper_tb_4, frame_05a06dc9724609433466dc790fa9347c, exception_keeper_lineno_4);
    }

    NORMALIZE_EXCEPTION(&exception_keeper_type_4, &exception_keeper_value_4, &exception_keeper_tb_4);
    PyException_SetTraceback(exception_keeper_value_4, (PyObject *)exception_keeper_tb_4);
    PUBLISH_EXCEPTION(&exception_keeper_type_4, &exception_keeper_value_4, &exception_keeper_tb_4);
    // Tried code:
    {
        nuitka_bool tmp_condition_result_6;
        PyObject *tmp_operand_name_2;
        PyObject *tmp_compexpr_left_3;
        PyObject *tmp_compexpr_right_3;
        tmp_compexpr_left_3 = EXC_TYPE(PyThreadState_GET());
        tmp_compexpr_right_3 = PyExc_AttributeError;
        tmp_res = EXCEPTION_MATCH_BOOL(tmp_compexpr_left_3, tmp_compexpr_right_3);
        if (tmp_res == -1) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 41;
            type_description_1 = "ooNoo";
            goto try_except_handler_6;
        }
        tmp_operand_name_2 = (tmp_res != 0) ? Py_True : Py_False;
        tmp_res = CHECK_IF_TRUE(tmp_operand_name_2);
        if (tmp_res == -1) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 41;
            type_description_1 = "ooNoo";
            goto try_except_handler_6;
        }
        tmp_condition_result_6 = (tmp_res == 0) ? NUITKA_BOOL_TRUE : NUITKA_BOOL_FALSE;
        if (tmp_condition_result_6 == NUITKA_BOOL_TRUE) {
            goto branch_yes_6;
        } else {
            goto branch_no_6;
        }
        branch_yes_6:;
        tmp_result = RERAISE_EXCEPTION(&exception_type, &exception_value, &exception_tb);
        if (unlikely(tmp_result == false)) {
            exception_lineno = 39;
        }

        if (exception_tb && exception_tb->tb_frame == &frame_05a06dc9724609433466dc790fa9347c->m_frame) frame_05a06dc9724609433466dc790fa9347c->m_frame.f_lineno = exception_tb->tb_lineno;
        type_description_1 = "ooNoo";
        goto try_except_handler_6;
        branch_no_6:;
    }
    goto try_end_5;
    // Exception handler code:
    try_except_handler_6:;
    exception_keeper_type_5 = exception_type;
    exception_keeper_value_5 = exception_value;
    exception_keeper_tb_5 = exception_tb;
    exception_keeper_lineno_5 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    // Restore previous exception.
    SET_CURRENT_EXCEPTION(exception_preserved_type_1, exception_preserved_value_1, exception_preserved_tb_1);
    // Re-raise.
    exception_type = exception_keeper_type_5;
    exception_value = exception_keeper_value_5;
    exception_tb = exception_keeper_tb_5;
    exception_lineno = exception_keeper_lineno_5;

    goto frame_exception_exit_1;
    // End of try:
    try_end_5:;
    // Restore previous exception.
    SET_CURRENT_EXCEPTION(exception_preserved_type_1, exception_preserved_value_1, exception_preserved_tb_1);
    goto try_end_4;
    // exception handler codes exits in all cases
    NUITKA_CANNOT_GET_HERE(PyQt5$$$function_1_find_qt);
    return NULL;
    // End of try:
    try_end_4:;

#if 0
    RESTORE_FRAME_EXCEPTION(frame_05a06dc9724609433466dc790fa9347c);
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto frame_no_exception_1;

    frame_return_exit_1:;
#if 0
    RESTORE_FRAME_EXCEPTION(frame_05a06dc9724609433466dc790fa9347c);
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto try_return_handler_1;

    frame_exception_exit_1:;

#if 0
    RESTORE_FRAME_EXCEPTION(frame_05a06dc9724609433466dc790fa9347c);
#endif

    if (exception_tb == NULL) {
        exception_tb = MAKE_TRACEBACK(frame_05a06dc9724609433466dc790fa9347c, exception_lineno);
    }
    else if (exception_tb->tb_frame != &frame_05a06dc9724609433466dc790fa9347c->m_frame) {
        exception_tb = ADD_TRACEBACK(exception_tb, frame_05a06dc9724609433466dc790fa9347c, exception_lineno);
    }

    // Attachs locals to frame if any.
    Nuitka_Frame_AttachLocals(
        (struct Nuitka_FrameObject *)frame_05a06dc9724609433466dc790fa9347c,
        type_description_1,
        var_os,
        var_sys,
        NULL,
        var_dll_dir,
        var_path
    );


    // Release cached frame.
    if (frame_05a06dc9724609433466dc790fa9347c == cache_frame_05a06dc9724609433466dc790fa9347c) {
        Py_DECREF(frame_05a06dc9724609433466dc790fa9347c);
    }
    cache_frame_05a06dc9724609433466dc790fa9347c = NULL;

    assertFrameObject(frame_05a06dc9724609433466dc790fa9347c);

    // Put the previous frame back on top.
    popFrameStack();

    // Return the error.
    goto try_except_handler_1;

    frame_no_exception_1:;
    tmp_return_value = Py_None;
    Py_INCREF(tmp_return_value);
    goto try_return_handler_1;
    // tried codes exits in all cases
    NUITKA_CANNOT_GET_HERE(PyQt5$$$function_1_find_qt);
    return NULL;
    // Return handler code:
    try_return_handler_1:;
    CHECK_OBJECT((PyObject *)var_os);
    Py_DECREF(var_os);
    var_os = NULL;

    CHECK_OBJECT((PyObject *)var_sys);
    Py_DECREF(var_sys);
    var_sys = NULL;

    Py_XDECREF(var_dll_dir);
    var_dll_dir = NULL;

    Py_XDECREF(var_path);
    var_path = NULL;

    goto function_return_exit;
    // Exception handler code:
    try_except_handler_1:;
    exception_keeper_type_6 = exception_type;
    exception_keeper_value_6 = exception_value;
    exception_keeper_tb_6 = exception_tb;
    exception_keeper_lineno_6 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    Py_XDECREF(var_os);
    var_os = NULL;

    Py_XDECREF(var_sys);
    var_sys = NULL;

    Py_XDECREF(var_dll_dir);
    var_dll_dir = NULL;

    Py_XDECREF(var_path);
    var_path = NULL;

    // Re-raise.
    exception_type = exception_keeper_type_6;
    exception_value = exception_keeper_value_6;
    exception_tb = exception_keeper_tb_6;
    exception_lineno = exception_keeper_lineno_6;

    goto function_exception_exit;
    // End of try:

    // Return statement must have exited already.
    NUITKA_CANNOT_GET_HERE(PyQt5$$$function_1_find_qt);
    return NULL;

function_exception_exit:
    assert(exception_type);
    RESTORE_ERROR_OCCURRED(exception_type, exception_value, exception_tb);

    return NULL;

function_return_exit:
   // Function cleanup code if any.


   // Actual function exit with return value, making sure we did not make
   // the error status worse despite non-NULL return.
   CHECK_OBJECT(tmp_return_value);
   assert(had_error || !ERROR_OCCURRED());
   return tmp_return_value;
}



static PyObject *MAKE_FUNCTION_PyQt5$$$function_1_find_qt() {
    struct Nuitka_FunctionObject *result = Nuitka_Function_New(
        impl_PyQt5$$$function_1_find_qt,
        const_str_plain_find_qt,
#if PYTHON_VERSION >= 300
        NULL,
#endif
        codeobj_05a06dc9724609433466dc790fa9347c,
        NULL,
#if PYTHON_VERSION >= 300
        NULL,
        NULL,
#endif
        module_PyQt5,
        NULL,
        0
    );

    return (PyObject *)result;
}



#if PYTHON_VERSION >= 300
static struct PyModuleDef mdef_PyQt5 =
{
    PyModuleDef_HEAD_INIT,
    NULL,                /* m_name, filled later */
    NULL,                /* m_doc */
    -1,                  /* m_size */
    NULL,                /* m_methods */
    NULL,                /* m_reload */
    NULL,                /* m_traverse */
    NULL,                /* m_clear */
    NULL,                /* m_free */
  };
#endif

extern PyObject *const_str_plain___compiled__;

extern PyObject *const_str_plain___package__;
extern PyObject *const_str_empty;

#if PYTHON_VERSION >= 300
extern PyObject *const_str_dot;
extern PyObject *const_str_plain___loader__;
#endif

#if PYTHON_VERSION >= 340
extern PyObject *const_str_plain___spec__;
extern PyObject *const_str_plain__initializing;
extern PyObject *const_str_plain_submodule_search_locations;
#endif

extern void _initCompiledCellType();
extern void _initCompiledGeneratorType();
extern void _initCompiledFunctionType();
extern void _initCompiledMethodType();
extern void _initCompiledFrameType();
#if PYTHON_VERSION >= 350
extern void _initCompiledCoroutineTypes();
#endif
#if PYTHON_VERSION >= 360
extern void _initCompiledAsyncgenTypes();
#endif

extern PyTypeObject Nuitka_Loader_Type;

#ifdef _NUITKA_PLUGIN_DILL_ENABLED
// Provide a way to create find a function via its C code and create it back
// in another process, useful for multiprocessing extensions like dill

function_impl_code functable_PyQt5[] = {
    impl_PyQt5$$$function_1_find_qt,
    NULL
};

static char const *_reduce_compiled_function_argnames[] = {
    "func",
    NULL
};

static PyObject *_reduce_compiled_function(PyObject *self, PyObject *args, PyObject *kwds) {
    PyObject *func;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O:reduce_compiled_function", (char **)_reduce_compiled_function_argnames, &func, NULL)) {
        return NULL;
    }

    if (Nuitka_Function_Check(func) == false) {
        PyErr_Format(PyExc_TypeError, "not a compiled function");
        return NULL;
    }

    struct Nuitka_FunctionObject *function = (struct Nuitka_FunctionObject *)func;

    function_impl_code *current = functable_PyQt5;
    int offset = 0;

    while (*current != NULL) {
        if (*current == function->m_c_code) {
            break;
        }

        current += 1;
        offset += 1;
    }

    if (*current == NULL) {
        PyErr_Format(PyExc_TypeError, "Cannot find compiled function in module.");
        return NULL;
    }

    PyObject *code_object_desc = PyTuple_New(6);
    PyTuple_SET_ITEM0(code_object_desc, 0, function->m_code_object->co_filename);
    PyTuple_SET_ITEM0(code_object_desc, 1, function->m_code_object->co_name);
    PyTuple_SET_ITEM(code_object_desc, 2, PyLong_FromLong(function->m_code_object->co_firstlineno));
    PyTuple_SET_ITEM0(code_object_desc, 3, function->m_code_object->co_varnames);
    PyTuple_SET_ITEM(code_object_desc, 4, PyLong_FromLong(function->m_code_object->co_argcount));
    PyTuple_SET_ITEM(code_object_desc, 5, PyLong_FromLong(function->m_code_object->co_flags));

    CHECK_OBJECT_DEEP(code_object_desc);

    PyObject *result = PyTuple_New(4);
    PyTuple_SET_ITEM(result, 0, PyLong_FromLong(offset));
    PyTuple_SET_ITEM(result, 1, code_object_desc);
    PyTuple_SET_ITEM0(result, 2, function->m_defaults);
    PyTuple_SET_ITEM0(result, 3, function->m_doc != NULL ? function->m_doc : Py_None);

    CHECK_OBJECT_DEEP(result);

    return result;
}

static PyMethodDef _method_def_reduce_compiled_function = {"reduce_compiled_function", (PyCFunction)_reduce_compiled_function,
                                                           METH_VARARGS | METH_KEYWORDS, NULL};

static char const *_create_compiled_function_argnames[] = {
    "func",
    "code_object_desc",
    "defaults",
    "doc",
    NULL
};


static PyObject *_create_compiled_function(PyObject *self, PyObject *args, PyObject *kwds) {
    CHECK_OBJECT_DEEP(args);

    PyObject *func;
    PyObject *code_object_desc;
    PyObject *defaults;
    PyObject *doc;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "OOOO:create_compiled_function", (char **)_create_compiled_function_argnames, &func, &code_object_desc, &defaults, &doc, NULL)) {
        return NULL;
    }

    int offset = PyLong_AsLong(func);

    if (offset == -1 && ERROR_OCCURRED()) {
        return NULL;
    }

    if (offset > sizeof(functable_PyQt5) || offset < 0) {
        PyErr_Format(PyExc_TypeError, "Wrong offset for compiled function.");
        return NULL;
    }

    PyObject *filename = PyTuple_GET_ITEM(code_object_desc, 0);
    PyObject *function_name = PyTuple_GET_ITEM(code_object_desc, 1);
    PyObject *line = PyTuple_GET_ITEM(code_object_desc, 2);
    int line_int = PyLong_AsLong(line);
    assert(!ERROR_OCCURRED());

    PyObject *argnames = PyTuple_GET_ITEM(code_object_desc, 3);
    PyObject *arg_count = PyTuple_GET_ITEM(code_object_desc, 4);
    int arg_count_int = PyLong_AsLong(arg_count);
    assert(!ERROR_OCCURRED());
    PyObject *flags = PyTuple_GET_ITEM(code_object_desc, 5);
    int flags_int = PyLong_AsLong(flags);
    assert(!ERROR_OCCURRED());

    PyCodeObject *code_object = MAKE_CODEOBJECT(
        filename,
        line_int,
        flags_int,
        function_name,
        argnames,
        arg_count_int,
        0, // TODO: Missing kw_only_count
        0 // TODO: Missing pos_only_count
    );

    // TODO: More stuff needed for Python3, best to re-order arguments of MAKE_CODEOBJECT.
    struct Nuitka_FunctionObject *result = Nuitka_Function_New(
        functable_PyQt5[offset],
        code_object->co_name,
#if PYTHON_VERSION >= 300
        NULL, // TODO: Not transferring qualname yet
#endif
        code_object,
        defaults,
#if PYTHON_VERSION >= 300
        NULL, // kwdefaults are done on the outside currently
        NULL, // TODO: Not transferring annotations
#endif
        module_PyQt5,
        doc,
        0
    );

    return (PyObject *)result;
}

static PyMethodDef _method_def_create_compiled_function = {
    "create_compiled_function",
    (PyCFunction)_create_compiled_function,
    METH_VARARGS | METH_KEYWORDS, NULL
};


#endif

// Internal entry point for module code.
PyObject *modulecode_PyQt5(char const *module_full_name) {
#if defined(_NUITKA_EXE) || PYTHON_VERSION >= 300
    static bool _init_done = false;

    // Modules might be imported repeatedly, which is to be ignored.
    if (_init_done) {
        return module_PyQt5;
    } else {
        _init_done = true;
    }
#endif

#ifdef _NUITKA_MODULE
    // In case of a stand alone extension module, need to call initialization
    // the init here because that's the first and only time we are going to get
    // called here.

    // May have to activate constants blob.
#if defined(_NUITKA_CONSTANTS_FROM_RESOURCE)
    loadConstantsResource();
#endif

    // Initialize the constant values used.
    _initBuiltinModule();
    createGlobalConstants();

    /* Initialize the compiled types of Nuitka. */
    _initCompiledCellType();
    _initCompiledGeneratorType();
    _initCompiledFunctionType();
    _initCompiledMethodType();
    _initCompiledFrameType();
#if PYTHON_VERSION >= 350
    _initCompiledCoroutineTypes();
#endif
#if PYTHON_VERSION >= 360
    _initCompiledAsyncgenTypes();
#endif

#if PYTHON_VERSION < 300
    _initSlotCompare();
#endif
#if PYTHON_VERSION >= 270
    _initSlotIternext();
#endif

    patchBuiltinModule();
    patchTypeComparison();

    // Enable meta path based loader if not already done.
#ifdef _NUITKA_TRACE
    PRINT_STRING("PyQt5: Calling setupMetaPathBasedLoader().\n");
#endif
    setupMetaPathBasedLoader();

#if PYTHON_VERSION >= 300
    patchInspectModule();
#endif

#endif

    /* The constants only used by this module are created now. */
#ifdef _NUITKA_TRACE
    PRINT_STRING("PyQt5: Calling createModuleConstants().\n");
#endif
    createModuleConstants();

    /* The code objects used by this module are created now. */
#ifdef _NUITKA_TRACE
    PRINT_STRING("PyQt5: Calling createModuleCodeObjects().\n");
#endif
    createModuleCodeObjects();

    // PRINT_STRING("in initPyQt5\n");

    // Create the module object first. There are no methods initially, all are
    // added dynamically in actual code only.  Also no "__doc__" is initially
    // set at this time, as it could not contain NUL characters this way, they
    // are instead set in early module code.  No "self" for modules, we have no
    // use for it.
#if PYTHON_VERSION < 300
    module_PyQt5 = Py_InitModule4(
        module_full_name,        // Module Name
        NULL,                    // No methods initially, all are added
                                 // dynamically in actual module code only.
        NULL,                    // No "__doc__" is initially set, as it could
                                 // not contain NUL this way, added early in
                                 // actual code.
        NULL,                    // No self for modules, we don't use it.
        PYTHON_API_VERSION
    );
#else
    mdef_PyQt5.m_name = module_full_name;
    module_PyQt5 = PyModule_Create(&mdef_PyQt5);
#endif

    moduledict_PyQt5 = MODULE_DICT(module_PyQt5);

#ifdef _NUITKA_PLUGIN_DILL_ENABLED
    {
        PyObject *function_tables = PyObject_GetAttrString((PyObject *)builtin_module, "compiled_function_tables");
        if (function_tables == NULL)
        {
            DROP_ERROR_OCCURRED();
            function_tables = PyDict_New();
        }
        PyObject_SetAttrString((PyObject *)builtin_module, "compiled_function_tables", function_tables);
        PyObject *funcs = PyTuple_New(2);
        PyTuple_SetItem(funcs, 0, PyCFunction_New(&_method_def_reduce_compiled_function, NULL));
        PyTuple_SetItem(funcs, 1, PyCFunction_New(&_method_def_create_compiled_function, NULL));
        PyDict_SetItemString(function_tables, module_full_name, funcs);
    }
#endif

    // Set "__compiled__" to what version information we have.
    UPDATE_STRING_DICT0(
        moduledict_PyQt5,
        (Nuitka_StringObject *)const_str_plain___compiled__,
        Nuitka_dunder_compiled_value
    );

    // Update "__package__" value to what it ought to be.
    {
#if 0
        UPDATE_STRING_DICT0(
            moduledict_PyQt5,
            (Nuitka_StringObject *)const_str_plain___package__,
            const_str_empty
        );
#elif 1
        PyObject *module_name = GET_STRING_DICT_VALUE(moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___name__);

        UPDATE_STRING_DICT0(
            moduledict_PyQt5,
            (Nuitka_StringObject *)const_str_plain___package__,
            module_name
        );
#else

#if PYTHON_VERSION < 300
        PyObject *module_name = GET_STRING_DICT_VALUE(moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___name__);
        char const *module_name_cstr = PyString_AS_STRING(module_name);

        char const *last_dot = strrchr(module_name_cstr, '.');

        if (last_dot != NULL)
        {
            UPDATE_STRING_DICT1(
                moduledict_PyQt5,
                (Nuitka_StringObject *)const_str_plain___package__,
                PyString_FromStringAndSize(module_name_cstr, last_dot - module_name_cstr)
            );
        }
#else
        PyObject *module_name = GET_STRING_DICT_VALUE(moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___name__);
        Py_ssize_t dot_index = PyUnicode_Find(module_name, const_str_dot, 0, PyUnicode_GetLength(module_name), -1);

        if (dot_index != -1)
        {
            UPDATE_STRING_DICT1(
                moduledict_PyQt5,
                (Nuitka_StringObject *)const_str_plain___package__,
                PyUnicode_Substring(module_name, 0, dot_index)
            );
        }
#endif
#endif
    }

    CHECK_OBJECT(module_PyQt5);

// Seems to work for Python2.7 out of the box, but for Python3, the module
// doesn't automatically enter "sys.modules", so do it manually.
#if PYTHON_VERSION >= 300
    {
        int r = PyDict_SetItemString(PyImport_GetModuleDict(), module_full_name, module_PyQt5);
        assert(r != -1);
    }
#endif

    // For deep importing of a module we need to have "__builtins__", so we set
    // it ourselves in the same way than CPython does. Note: This must be done
    // before the frame object is allocated, or else it may fail.

    if (GET_STRING_DICT_VALUE(moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___builtins__) == NULL)
    {
        PyObject *value = (PyObject *)builtin_module;

        // Check if main module, not a dict then but the module itself.
#if !defined(_NUITKA_EXE) || !0
        value = PyModule_GetDict(value);
#endif

        UPDATE_STRING_DICT0(moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___builtins__, value);
    }

#if PYTHON_VERSION >= 300
    UPDATE_STRING_DICT0(moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___loader__, (PyObject *)&Nuitka_Loader_Type);
#endif

#if PYTHON_VERSION >= 340
// Set the "__spec__" value

#if 0
    // Main modules just get "None" as spec.
    UPDATE_STRING_DICT0(moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___spec__, Py_None);
#else
    // Other modules get a "ModuleSpec" from the standard mechanism.
    {
        PyObject *bootstrap_module = PyImport_ImportModule("importlib._bootstrap");
        CHECK_OBJECT(bootstrap_module);
        PyObject *module_spec_class = PyObject_GetAttrString(bootstrap_module, "ModuleSpec");
        Py_DECREF(bootstrap_module);

        PyObject *args[] = {
            GET_STRING_DICT_VALUE(moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___name__),
            (PyObject *)&Nuitka_Loader_Type
        };

        PyObject *spec_value = CALL_FUNCTION_WITH_ARGS2(
            module_spec_class,
            args
        );
        Py_DECREF(module_spec_class);

        // We can assume this to never fail, or else we are in trouble anyway.
        CHECK_OBJECT(spec_value);

// For packages set the submodule search locations as well, even if to empty
// list, so investigating code will consider it a package.
#if 1
        SET_ATTRIBUTE(spec_value, const_str_plain_submodule_search_locations, PyList_New(0));
#endif

// Mark the execution in the "__spec__" value.
        SET_ATTRIBUTE(spec_value, const_str_plain__initializing, Py_True);

        UPDATE_STRING_DICT1(moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___spec__, spec_value);
    }
#endif
#endif

    // Temp variables if any
    struct Nuitka_FrameObject *frame_6f9e61663d66ca49ec84f48a6a426d96;
    NUITKA_MAY_BE_UNUSED char const *type_description_1 = NULL;
    PyObject *exception_type = NULL;
    PyObject *exception_value = NULL;
    PyTracebackObject *exception_tb = NULL;
    NUITKA_MAY_BE_UNUSED int exception_lineno = 0;
    bool tmp_result;
    int tmp_res;

    // Module code.
    {
        PyObject *tmp_assign_source_1;
        tmp_assign_source_1 = Py_None;
        UPDATE_STRING_DICT0(moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___doc__, tmp_assign_source_1);
    }
    {
        PyObject *tmp_assign_source_2;
        tmp_assign_source_2 = module_filename_obj;
        UPDATE_STRING_DICT0(moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___file__, tmp_assign_source_2);
    }
    // Frame without reuse.
    frame_6f9e61663d66ca49ec84f48a6a426d96 = MAKE_MODULE_FRAME(codeobj_6f9e61663d66ca49ec84f48a6a426d96, module_PyQt5);

    // Push the new frame as the currently active one, and we should be exclusively
    // owning it.
    pushFrameStack(frame_6f9e61663d66ca49ec84f48a6a426d96);
    assert(Py_REFCNT(frame_6f9e61663d66ca49ec84f48a6a426d96) == 2);

    // Framed code:
    {
        PyObject *tmp_assign_source_3;
        PyObject *tmp_list_element_1;
        PyObject *tmp_called_name_1;
        PyObject *tmp_source_name_1;
        PyObject *tmp_args_element_name_1;
        PyObject *tmp_called_instance_1;
        frame_6f9e61663d66ca49ec84f48a6a426d96->m_frame.f_lineno = 1;
        {
            PyObject *module = PyImport_ImportModule("os");
            if (likely(module != NULL)) {
                tmp_source_name_1 = PyObject_GetAttr(module, const_str_plain_path);
            } else {
                tmp_source_name_1 = NULL;
            }
        }

        if (tmp_source_name_1 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 1;

            goto frame_exception_exit_1;
        }
        tmp_called_name_1 = LOOKUP_ATTRIBUTE(tmp_source_name_1, const_str_plain_dirname);
        if (tmp_called_name_1 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 1;

            goto frame_exception_exit_1;
        }
        tmp_args_element_name_1 = module_filename_obj;
        frame_6f9e61663d66ca49ec84f48a6a426d96->m_frame.f_lineno = 1;
        tmp_list_element_1 = CALL_FUNCTION_WITH_SINGLE_ARG(tmp_called_name_1, tmp_args_element_name_1);
        Py_DECREF(tmp_called_name_1);
        if (tmp_list_element_1 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 1;

            goto frame_exception_exit_1;
        }
        tmp_assign_source_3 = PyList_New(2);
        PyList_SET_ITEM(tmp_assign_source_3, 0, tmp_list_element_1);
        frame_6f9e61663d66ca49ec84f48a6a426d96->m_frame.f_lineno = 1;
        {
            PyObject *module = PyImport_ImportModule("os");
            if (likely(module != NULL)) {
                tmp_called_instance_1 = PyObject_GetAttr(module, const_str_plain_environ);
            } else {
                tmp_called_instance_1 = NULL;
            }
        }

        if (tmp_called_instance_1 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);
            Py_DECREF(tmp_assign_source_3);

            exception_lineno = 1;

            goto frame_exception_exit_1;
        }
        frame_6f9e61663d66ca49ec84f48a6a426d96->m_frame.f_lineno = 1;
        tmp_list_element_1 = CALL_METHOD_WITH_ARGS2(tmp_called_instance_1, const_str_plain_get, &PyTuple_GET_ITEM(const_tuple_8b1fd1016da3eaee3145814dfe4be59a_tuple, 0));

        if (tmp_list_element_1 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);
            Py_DECREF(tmp_assign_source_3);

            exception_lineno = 1;

            goto frame_exception_exit_1;
        }
        PyList_SET_ITEM(tmp_assign_source_3, 1, tmp_list_element_1);
        UPDATE_STRING_DICT1(moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___path__, tmp_assign_source_3);
    }
    {
        PyObject *tmp_assattr_name_1;
        PyObject *tmp_assattr_target_1;
        PyObject *tmp_mvar_value_1;
        tmp_assattr_name_1 = module_filename_obj;
        tmp_mvar_value_1 = GET_STRING_DICT_VALUE(moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___spec__);

        if (unlikely(tmp_mvar_value_1 == NULL)) {
            tmp_mvar_value_1 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain___spec__);
        }

        CHECK_OBJECT(tmp_mvar_value_1);
        tmp_assattr_target_1 = tmp_mvar_value_1;
        tmp_result = SET_ATTRIBUTE(tmp_assattr_target_1, const_str_plain_origin, tmp_assattr_name_1);
        if (tmp_result == false) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 1;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_assattr_name_2;
        PyObject *tmp_assattr_target_2;
        PyObject *tmp_mvar_value_2;
        tmp_assattr_name_2 = Py_True;
        tmp_mvar_value_2 = GET_STRING_DICT_VALUE(moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___spec__);

        if (unlikely(tmp_mvar_value_2 == NULL)) {
            tmp_mvar_value_2 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain___spec__);
        }

        CHECK_OBJECT(tmp_mvar_value_2);
        tmp_assattr_target_2 = tmp_mvar_value_2;
        tmp_result = SET_ATTRIBUTE(tmp_assattr_target_2, const_str_plain_has_location, tmp_assattr_name_2);
        if (tmp_result == false) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 1;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_assign_source_4;
        tmp_assign_source_4 = Py_None;
        UPDATE_STRING_DICT0(moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___cached__, tmp_assign_source_4);
    }
    {
        PyObject *tmp_assign_source_5;
        tmp_assign_source_5 = MAKE_FUNCTION_PyQt5$$$function_1_find_qt();



        UPDATE_STRING_DICT1(moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain_find_qt, tmp_assign_source_5);
    }
    {
        PyObject *tmp_called_name_2;
        PyObject *tmp_mvar_value_3;
        PyObject *tmp_call_result_1;
        tmp_mvar_value_3 = GET_STRING_DICT_VALUE(moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain_find_qt);

        if (unlikely(tmp_mvar_value_3 == NULL)) {
            tmp_mvar_value_3 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_find_qt);
        }

        CHECK_OBJECT(tmp_mvar_value_3);
        tmp_called_name_2 = tmp_mvar_value_3;
        frame_6f9e61663d66ca49ec84f48a6a426d96->m_frame.f_lineno = 45;
        tmp_call_result_1 = CALL_FUNCTION_NO_ARGS(tmp_called_name_2);
        if (tmp_call_result_1 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 45;

            goto frame_exception_exit_1;
        }
        Py_DECREF(tmp_call_result_1);
    }
    tmp_res = PyDict_DelItem((PyObject *)moduledict_PyQt5, const_str_plain_find_qt);
    tmp_result = tmp_res != -1;
    if ( tmp_result == false ) CLEAR_ERROR_OCCURRED();

    if (tmp_result == false) {

        exception_type = PyExc_NameError;
        Py_INCREF(exception_type);
        exception_value = UNSTREAM_STRING(&constant_bin[ 30 ], 29, 0);
        exception_tb = NULL;
        NORMALIZE_EXCEPTION(&exception_type, &exception_value, &exception_tb);
        CHAIN_EXCEPTION(exception_value);

        exception_lineno = 46;

        goto frame_exception_exit_1;
    }


    // Restore frame exception if necessary.
#if 0
    RESTORE_FRAME_EXCEPTION(frame_6f9e61663d66ca49ec84f48a6a426d96);
#endif
    popFrameStack();

    assertFrameObject(frame_6f9e61663d66ca49ec84f48a6a426d96);

    goto frame_no_exception_1;

    frame_exception_exit_1:;
#if 0
    RESTORE_FRAME_EXCEPTION(frame_6f9e61663d66ca49ec84f48a6a426d96);
#endif

    if ( exception_tb == NULL )
    {
        exception_tb = MAKE_TRACEBACK(frame_6f9e61663d66ca49ec84f48a6a426d96, exception_lineno);
    }
    else if (exception_tb->tb_frame != &frame_6f9e61663d66ca49ec84f48a6a426d96->m_frame) {
        exception_tb = ADD_TRACEBACK(exception_tb, frame_6f9e61663d66ca49ec84f48a6a426d96, exception_lineno);
    }

    // Put the previous frame back on top.
    popFrameStack();

    // Return the error.
    goto module_exception_exit;

    frame_no_exception_1:;

    return module_PyQt5;
    module_exception_exit:
    RESTORE_ERROR_OCCURRED(exception_type, exception_value, exception_tb);
    return NULL;
}
