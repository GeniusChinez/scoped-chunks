# smem
A c++ tool to automatically handle allocated memory buffers that have roughly 
the same lifetime. All the allocated memory is freed once the guard goes out 
of scope.

### Usage:
```c++
#include "smem.cpp"
#include <iostream>

int main() {
    auto chunks = smem::get_scoped_chunks();

    auto temp_a = chunks.new_item<int>(3);
    auto temp_b = static_cast<int*>(chunks.allocate_bytes(23));

    (void)temp_a;
    (void)temp_b;

    return 0;
}
```
