#include <iostream>
#include <pybind11/pybind11.h>
#include <cstring>
#include <string>

namespace py = pybind11;

class MyString {
public:
    MyString(char* input) {
        _size = std::strlen(input);
        _input = new char[_size];
        std::strcpy(_input, input);
    }

    ~MyString() {
        delete[] _input;
    }

    size_t length() { return _size; }
    
    std::string slice(uint start, uint end, int step) {
        if (end > _size) {
           end = _size; 
        }

        std::string sliced_str;

        for (size_t i = start; i < end; i+=step) {
            sliced_str += _input[i];
        }

        return sliced_str;
    } 

    bool is_palindrome() {
        if (_size == 0) { return false; }

        for (size_t i = 0; i < (_size / 2); i++) {
            if (_input[i] != _input[_size - i - 1]) {
                return false;
            }
        }
        return true;
    }

private:
    size_t _size = 0;
    char* _input;
};

PYBIND11_MODULE(my_string, m) {
    m.doc() = "A simple string class.";

    py::class_<MyString> mystr(m, "MyString");

    mystr.def(py::init<char *>())
         .def_property_readonly("length", &MyString::length)
         .def("slice",  &MyString::slice, "Slice a string from start to end, with a specified interval.", py::arg("start"), py::arg("end"), py::arg("step"))
         .def("is_palindrome", &MyString::is_palindrome, "Checks if string is a palindrome.");
};
