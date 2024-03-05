# MyString_pybind11

To compile the C++ code and generate the wrapped python code you should run the following:
`$ c++ -O3 -Wall -shared -fPIC $(python3 -m pybind11 --includes) MyString.cxx -o my_string$(python3-config --extension-suffix)`

To run the python script, simply run on a console:
`$ python3 script.py`
