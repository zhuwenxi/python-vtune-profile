g++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) -I/opt/intel/oneapi/vtune/latest/sdk/include/ vtune.cpp /opt/intel/oneapi/vtune/latest/lib64/libittnotify.a -o vtune$(python3-config --extension-suffix)

