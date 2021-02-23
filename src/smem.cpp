#pragma once
#include "smem.h"

namespace smem {
    template <typename T, typename ...Args> 
    T* ScopedChunks::new_item(Args&&... args) {
        allocations.push_back(std::malloc(sizeof(T)));
        return new (allocations.back()) T(std::forward<Args>(args)...);
    }

    void* ScopedChunks::allocate_bytes(std::size_t nbytes=1) {
        allocations.push_back(std::malloc(nbytes));
        return static_cast<void*>(allocations.back());
    }

    std::size_t ScopedChunks::count_allocations() const {
        return allocations.size();
    }

    ScopedChunks::~ScopedChunks() {
        for (auto& allocation : allocations) {
            free(&allocation);
        }
    }

    void ScopedChunks::free(void** buffer_ptr) {
        if (*buffer_ptr != NULL) {
            std::free(*buffer_ptr);
            *buffer_ptr = NULL;
        }
    }

    ScopedChunks get_scoped_chunks() {
        return ScopedChunks();
    }
}
