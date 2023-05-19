# python-vtune-profile
A Python wrapper for Intel Vtune ITT API, to mark the start/stop of a task in vtune's collecting.

# Build
./build.sh

# Usage
```python
import vtune
domain = vtune.__itt_domain_create("my domain")
handle = vtune.__itt_string_handle_create("my task")
vtune.__itt_task_begin(domain, handle)
# Do some heavy task...
vtune.__itt_task_end(domain)
```
