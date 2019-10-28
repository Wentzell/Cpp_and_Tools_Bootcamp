#include<array>
#include<complex>
#include<string>
#include<iostream> //for std::cout...
using dcomplex = std::complex<double>;

// first the basic stuff
#include <cpp2py.hpp>
#include <cpp2py/converters/string.hpp>

// for converters
#include <cpp2py/converters/vector.hpp>
#include <cpp2py/converters/string.hpp>
#include <cpp2py/converters/function.hpp>
#include <algorithm>

//------------------------------------------------------------------------------------------------------
//---------------------   includes and using  -------------------
//------------------------------------------------------------------------------------------------------
#define TRIQS_PYTHON_WRAPPER_MODULE_simple

#include "simple.cpp"


using namespace cpp2py;


#include <cpp2py/converters/vector.hpp>





//------------------------------------------------------------------------------------------------------
// Second all the classes and enums wrapped by imported modules 
// Most converters will be automatically included
//------------------------------------------------------------------------------------------------------

  

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

//--------------------- Generated converters --------------------------
 

// We use the order, in the following order (which is necessary for compilation : we need the converters in the implementations)
// - function/method declaration
// - implement type, and all tables
// - implement the converter of types, then of associated regular_type if any.
// - implement functions/method.
//
//----------------------------------------------------------------
//---------------------  function declarations -------------------
//----------------------------------------------------------------

//--------------------- all functions/methods with args, kwds, including constructors -----------------------------

 static PyObject* Myclass_list_of_members(PyObject *self, PyObject *args, PyObject *keywds);
 static int Myclass___init__(PyObject *self, PyObject *args, PyObject *keywds);

// ------------------------------- Loop on all classes ----------------------------------------------------


// ----------------------------
// start class : Myclass
// ----------------------------
//--------------------- all members  -----------------------------


//--------------------- all properties  -----------------------------


//--------------------- [] -----------------------------





//--------------------- reduce  -----------------------------

static PyObject* Myclass___reduce__ (PyObject *self, PyObject *args, PyObject *keywds);

//--------------------- hdf5 : write part -----------------------------

static PyObject* Myclass___write_hdf5__ (PyObject *self, PyObject *args);

//--------------------- repr  -----------------------------


//--------------------- Arithmetic declaration only -----------------------------


//--------------------- Comparison  -----------------------------

static PyObject* Myclass_richcompare (PyObject *a, PyObject *b, int op);

// ----------------------------
// stop class : Myclass
// ----------------------------

//----------------------------------------------------------------
//---------------------  implementation --------------------------
//----------------------------------------------------------------

// ------------------------------- Loop on all classes ----------------------------------------------------

// ----------------------------
// start class : Myclass
// ----------------------------

//--------------------- define all the types and the converter functions -----------------------------


 // the python type
typedef struct {
    PyObject_HEAD
    myclass * _c;
} Myclass;

// the new
static PyObject* Myclass_new(PyTypeObject *type, PyObject *args, PyObject *kwds) {
  Myclass *self;
  self = (Myclass *)type->tp_alloc(type, 0);
  if (self != NULL) self->_c = NULL;
  return (PyObject *)self;
}

// dealloc
static void Myclass_dealloc(Myclass* self) {
  if (self->_c != NULL) delete self->_c; // should never be null, but I protect it anyway
  self->ob_type->tp_free((PyObject*)self);
}

//--------------------- Iterator by wrapping the C++ -----------------------------


//--------------------- Register as_number  -----------------------------


//--------------------- Register as_mapping  -----------------------------


//--------------------- Register members and properties -----------------------------

static PyGetSetDef Myclass_getseters[] = {





{NULL}  /* Sentinel */
};

//--------------------- Register the methods for the types  -----------------------------

static PyMethodDef Myclass_methods[] = {
    {"list_of_members", (PyCFunction)Myclass_list_of_members, METH_VARARGS| METH_KEYWORDS , "Signature : () -> list[int]\n   Return a vector with all members" },
    {"__reduce__", (PyCFunction)Myclass___reduce__, METH_VARARGS, "Internal  " },
    {"__write_hdf5__", (PyCFunction)Myclass___write_hdf5__, METH_VARARGS, "Internal : hdf5 writing via C++ " },
{NULL}  /* Sentinel */
};

//--------------------- The xxxType table  -----------------------------

static PyTypeObject MyclassType = {
    PyObject_HEAD_INIT(NULL)
    0,                         /*ob_size*/
    "simple.simple.Myclass",             /*tp_name*/
    sizeof(Myclass),             /*tp_basicsize*/
    0,                         /*tp_itemsize*/
    (destructor)Myclass_dealloc, /*tp_dealloc*/
    0,                         /*tp_print*/
    0,                         /*tp_getattr*/
    0,                         /*tp_setattr*/
    0,                         /*tp_compare*/
    0,           /*tp_repr*/
    0,       /*tp_as_number*/
    0,                         /*tp_as_sequence*/
    0,    /*tp_as_mapping*/
    0,                         /*tp_hash */
    0,                         /*tp_call*/
    0,                         /*tp_str*/
    0,                         /*tp_getattro*/
    0,                         /*tp_setattro*/
    0,                         /*tp_as_buffer*/
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE |Py_TPFLAGS_CHECKTYPES, /*tp_flags*/
    "A Simple class", /* tp_doc */
    0,		               /* tp_traverse */
    0,		               /* tp_clear */
    Myclass_richcompare,  /* tp_richcompare */
    0,		               /* tp_weaklistoffset */
    0,		               /* tp_iter */
    0,		               /* tp_iternext */
    Myclass_methods,             /* tp_methods */
    0,              /* tp_members */
    Myclass_getseters,           /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc)Myclass___init__,      /* tp_init */
    0,                         /* tp_alloc */
 Myclass_new,           /* tp_new */
};

// ----------------------------
// stop class : Myclass
// ----------------------------


//--------------------- Converters of enums --------------------------


//--------------------- define all functions/methods with args, kwds, including constructors -----------------------------


 static PyObject* Myclass_list_of_members(PyObject *self, PyObject *args, PyObject *keywds) {

  static constexpr int n_overloads = 1;

  [[maybe_unused]] PyObject * py_result; //final result, except for constructor

  std::array<pyref,n_overloads> errors;

  // If no overload, we avoid the err_list and let the error go through (to save some code).
    {// overload list_of_members() -> std::vector<int>
     // define the variable to be filled by the parsing method
     // wrapped types are converted to a pointer, other converted types to a value or a view
     static char *kwlist[] = {NULL};
     static const char * format = "";
     if (PyArg_ParseTupleAndKeywords(args, keywds, format, kwlist
       	))
     {
      // redefine the references to remove the * for wrapped type. Allows to use them naturally in C code.
     
      // FIXME : calling_pattern ---> lambda -> auto , plus de self. 
      auto & self_c = convert_from_python<myclass>(self);
      try {
        
        std::vector<int> result =  self_c.list_of_members(); // the call is here. It sets up "result" : sets up in the python layer.
         py_result = convert_to_python(std::move(result));
        return py_result;
      }
      CATCH_AND_RETURN(".. calling C++ overload \n.. list_of_members() -> std::vector<int> \n.. in implementation of method Myclass.list_of_members", NULL);
     }
     else { // the overload does not parse the arguments. Keep the error set by python, for later use, and clear it.
      PyObject * ptype,  *ptraceback, *err; // unused.
      PyErr_Fetch(&ptype, &err, &ptraceback);
      errors[0] = pyref{err};
      Py_XDECREF(ptype); Py_XDECREF(ptraceback);
     }
    } // end overload list_of_members() -> std::vector<int>

   static const char * overloads_signatures[] = {"list_of_members() -> std::vector<int>"};

   // FIXME Factorize this
   // finally, no overload was successful. Composing a detailed error message, with the reason of failure of each overload
   {
    std::string err_list = "Error: no suitable C++ overload found in implementation of method Myclass.list_of_members\n";
    for (int i =0; i < errors.size(); ++i) { 
      err_list = err_list + "\n" + overloads_signatures[i] + " \n failed with the error : \n  ";
      if (errors[i]) err_list += PyString_AsString((PyObject*)errors[i]);
      err_list +="\n";
    }
    PyErr_SetString(PyExc_TypeError,err_list.c_str());
   }
   error_return :
   return NULL;
 }

 static int Myclass___init__(PyObject *self, PyObject *args, PyObject *keywds) {

  static constexpr int n_overloads = 1;

  [[maybe_unused]] PyObject * py_result; //final result, except for constructor

  std::array<pyref,n_overloads> errors;

  // If no overload, we avoid the err_list and let the error go through (to save some code).
    {// overload (no C++ name)() -> 
     // define the variable to be filled by the parsing method
     // wrapped types are converted to a pointer, other converted types to a value or a view
     static char *kwlist[] = {NULL};
     static const char * format = "";
     if (PyArg_ParseTupleAndKeywords(args, keywds, format, kwlist
       	))
     {
      // redefine the references to remove the * for wrapped type. Allows to use them naturally in C code.
     
      // FIXME : calling_pattern ---> lambda -> auto , plus de self. 
      try {
        
        ((Myclass *)self)->_c = new myclass ();; // the call is here. It sets up "result" : sets up in the python layer.
        return 0;
      }
      CATCH_AND_RETURN (".. in calling C++ overload of constructor :\n.. (no C++ name)() -> ",-1);
     }
     else { // the overload does not parse the arguments. Keep the error set by python, for later use, and clear it.
      PyObject * ptype,  *ptraceback, *err; // unused.
      PyErr_Fetch(&ptype, &err, &ptraceback);
      errors[0] = pyref{err};
      Py_XDECREF(ptype); Py_XDECREF(ptraceback);
     }
    } // end overload (no C++ name)() -> 

   static const char * overloads_signatures[] = {"(no C++ name)() -> "};

   // FIXME Factorize this
   // finally, no overload was successful. Composing a detailed error message, with the reason of failure of each overload
   {
    std::string err_list = "Error: no suitable C++ overload found in implementation of method Myclass.__init__\n";
    for (int i =0; i < errors.size(); ++i) { 
      err_list = err_list + "\n" + overloads_signatures[i] + " \n failed with the error : \n  ";
      if (errors[i]) err_list += PyString_AsString((PyObject*)errors[i]);
      err_list +="\n";
    }
    PyErr_SetString(PyExc_TypeError,err_list.c_str());
   }
   error_return :
   return -1;
 }

// ------------------------------- Loop on all classes ----------------------------------------------------


//--------------------- define all members  -----------------------------


//--------------------- define all properties  -----------------------------



//--------------------- [] implementation  -----------------------------


// The __getitem__impl has been implemented with other methods. We redirect the call to the general for (args, kw)
// after rebuilding args.


//--------------------- reduce  -----------------------------


static PyObject* Myclass___reduce__ (PyObject *self, PyObject *args, PyObject *keywds) {
  PyErr_SetString(PyExc_NotImplementedError, "__reduce__ not implemented");
  return NULL;
}

//--------------------- 


//--------------------- 


//--------------------- repr  -----------------------------


//--------------------- comparisons  -----------------------------

static PyObject* Myclass_richcompare (PyObject *a, PyObject *b, int op) {


 switch(op) {

  case Py_EQ:
   PyErr_SetString(PyExc_TypeError, "Comparison operator == not implemented for type Myclass");
   return NULL;

  case Py_NE:
   PyErr_SetString(PyExc_TypeError, "Comparison operator != not implemented for type Myclass");
   return NULL;

  case Py_LT:
   PyErr_SetString(PyExc_TypeError, "Comparison operator < not implemented for type Myclass");
   return NULL;

  case Py_GT:
   PyErr_SetString(PyExc_TypeError, "Comparison operator > not implemented for type Myclass");
   return NULL;

  case Py_LE:
   PyErr_SetString(PyExc_TypeError, "Comparison operator <= not implemented for type Myclass");
   return NULL;

  case Py_GE:
   PyErr_SetString(PyExc_TypeError, "Comparison operator >= not implemented for type Myclass");
   return NULL;

  default:
    break;
 }
 return NULL;
}

//--------------------- hdf5 part -----------------------------

/// hdf5 is not defined for this object, we still but a function + exception for a clear and early error message.
static PyObject* Myclass___write_hdf5__ (PyObject *self, PyObject *args) {
  PyErr_SetString(PyExc_NotImplementedError, "No hdf5 support for the object Myclass");
  return NULL;
 }


//--------------------- Arithmetic implementation -----------------------------
  // IMPROVE ERROR TREATEMENT LIKE OTHER ORDINARY METHODS


//--------------------- Implementation of iterator by wrapping the C++ -----------------------------




// FIXME : remove this
//--------------------- function returning the list of classes, enum wrapped  -----------------------------

 static PyObject* _get_cpp2py_wrapped_class_enums(PyObject *self, PyObject *args, PyObject *keywds) {

  PyObject * d = PyDict_New();

  static const char * cls = "[('myclass', False)]";
  static const char * ens = "[]"; 
  static const char * inclu = "['simple.cpp']"; 
  
  PyDict_SetItemString(d, "classes", pyref(PyString_FromString(cls)));
  PyDict_SetItemString(d, "enums", pyref(PyString_FromString(ens)));
  PyDict_SetItemString(d, "module_name", pyref(PyString_FromString("simple.simple")));
  PyDict_SetItemString(d, "includes", pyref(PyString_FromString(inclu)));

  return d;
 }
 
//--------------------- module function table  -----------------------------

// the table of the function of the module...
static PyMethodDef module_methods[] = {

    {"_get_cpp2py_wrapped_class_enums", (PyCFunction)_get_cpp2py_wrapped_class_enums, METH_VARARGS, "[Internal] Returns the list of wrapped objects  " },

{NULL}  /* Sentinel */
};

//--------------------- module init function -----------------------------

#ifndef PyMODINIT_FUNC	/* declarations for DLL import/export */
#define PyMODINIT_FUNC void
#endif
PyMODINIT_FUNC
initsimple(void)
{
#ifdef TRIQS_IMPORTED_CONVERTERS_ARRAYS
    // import numpy
    import_array();
#endif


    PyObject* m;

    if (PyType_Ready(&MyclassType) < 0) return;


    m = Py_InitModule3("simple", module_methods, "");
    if (m == NULL) return;

    Py_INCREF(&MyclassType);
    PyModule_AddObject(m, "Myclass", (PyObject *)&MyclassType);

#ifdef TRIQS_INCLUDED_H5
    // hdf5 registration
  pyref module = pyref::module("pytriqs.archive.hdf_archive_schemes");
  pyref register_class = module.attr("register_class");
#endif

    // register all the types
    auto *table  = get_pytypeobject_table();
    (*table)[std::type_index(typeid(myclass)).name()] = &MyclassType;

}

