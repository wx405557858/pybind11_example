#include <stdio.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <vector>
namespace py = pybind11;


class ExampleClass{
private:
public:
    int x;
    ExampleClass(int x_=0){x=x_;}
    ~ExampleClass(){}
    int getx();
    std::tuple<int, double> test_tuple();
    std::vector<double> test_vector(std::vector<double> input);
    std::vector<std::vector<double>> test_vector2d(std::vector<std::vector<double>> input);
    void test_reference(std::vector<double>& input);
};

int ExampleClass::getx() {
    return x;
}

std::tuple<int, double> ExampleClass::test_tuple() {
    return std::make_tuple(1, 3.14);
}

std::vector<double> ExampleClass::test_vector(std::vector<double> input) {
    std::vector<double> output(input.size());

    for ( size_t i = 0 ; i < input.size() ; i++ )
        output[i] = 2. * input[i];

    return output;
}


std::vector<std::vector<double>> ExampleClass::test_vector2d(std::vector<std::vector<double>> input) {
    std::vector<std::vector<double>> output(input.size());

    for (int i = 0 ; i < input.size() ; i++ ) {
        output[i] = std::vector<double> (input[i].size());
        for (int j = 0; j < input[i].size(); j++ )
            output[i][j] = 2. * input[i][j];
    }

    return output;

}

void ExampleClass::test_reference(std::vector<double>& input) {
    for ( size_t i = 0 ; i < input.size() ; i++ )
        input[i] = input[i] * 2;
}

PYBIND11_MODULE(example, m) {
    py::class_<ExampleClass>(m, "ExampleClass")
        .def(py::init<int>(), py::arg("x_") = 0)
        .def_readwrite("x", &ExampleClass::x)
        .def("getx", &ExampleClass::getx)
        .def("test_tuple", &ExampleClass::test_tuple)
        .def("test_vector", &ExampleClass::test_vector)
        .def("test_vector2d", &ExampleClass::test_vector2d)
        .def("test_reference", &ExampleClass::test_reference);
}