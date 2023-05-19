#include <pybind11/pybind11.h>
#include <ittnotify.h>
#include <iostream>


namespace py = pybind11;

__itt_domain* domain_create(const char *name) {
    return __itt_domain_create(name);
}

__itt_string_handle* handle_create(const char *name) {
    return __itt_string_handle_create(name);
}

void itt_task_begin(__itt_domain *domain, __itt_string_handle* handle) {
    __itt_task_begin(domain, __itt_null, __itt_null, handle);
}

void itt_task_end(__itt_domain *domain) {
    __itt_task_end(domain);
}

PYBIND11_MODULE(vtune, m) {
    py::class_<__itt_domain>(m, "__itt_domain")
        .def_readwrite("flags", &__itt_domain::flags)
        .def_readwrite("nameA", &__itt_domain::nameA);
        // TODO(wenxizhu): __itt_domain definition here is not complete.
    py::class_<__itt_string_handle>(m, "__itt_string_handle")
        .def_readwrite("strA", &__itt_string_handle::strA)
        .def_readwrite("strW", &__itt_string_handle::strW);
        // TODO(wenxizhu): __itt_string_handle definition here is not complete.
    m.doc() = "vtune itt python api.";
    m.def("__itt_domain_create", &domain_create, "Create a domain that is visible globally.");
    m.def("__itt_string_handle_create", &handle_create, "Create a string handle.");
    m.def("__itt_task_begin", &itt_task_begin, "Create a task begin tag.");
    m.def("__itt_task_end", &itt_task_end, "Create a task end tag.");
}
