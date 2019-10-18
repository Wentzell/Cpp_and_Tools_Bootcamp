# Generated automatically using the command :
# c++2py simple.cpp
from cpp2py.wrap_generator import *

# The module
module = module_(full_name = "simple", doc = r"", app_name = "simple")

# Imports

# Add here all includes
module.add_include("simple.cpp")

# Add here anything to add in the C++ code at the start, e.g. namespace using
module.add_preamble("""

""")


# The class myclass
c = class_(
        py_type = "Myclass",  # name of the python class
        c_type = "myclass",   # name of the C++ class
        doc = r"""A Simple class""",   # doc of the C++ class
        hdf5 = False,
)

c.add_constructor("""(int _a = 39, int _b = 3)""", doc = r"""""")

c.add_method("""int get_sum ()""",
             doc = r"""The the sum of all members""")

module.add_class(c)



module.generate_code()