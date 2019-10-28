# Generated automatically using the command :
# c++2py simple.cpp --target_file_only
from cpp2py.wrap_generator import *

# The module
module = module_(full_name = "simple", doc = r"", app_name = "simple")

# Imports

# Add here all includes
module.add_include("simple.cpp")

# Add here anything to add in the C++ code at the start, e.g. namespace using
module.add_preamble("""
#include <cpp2py/converters/vector.hpp>

""")


# The class myclass
c = class_(
        py_type = "Myclass",  # name of the python class
        c_type = "myclass",   # name of the C++ class
        doc = r"""A Simple class""",   # doc of the C++ class
        hdf5 = False,
)

c.add_constructor("""()""", doc = r"""""")

c.add_method("""std::vector<int> list_of_members ()""",
             doc = r"""Return a vector with all members""")

module.add_class(c)



module.generate_code()