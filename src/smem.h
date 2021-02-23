#pragma once

#include <cstdint>
#include <vector>

namespace smem {
    class MemoryGuard {
    public:
        MemoryGuard() = default;
        MemoryGuard(const MemoryGuard&) = delete;
        MemoryGuard(MemoryGuard&&) = delete;
        MemoryGuard& operator=(const MemoryGuard&) = delete;
        MemoryGuard& operator=(MemoryGuard&&) = delete;
        ~MemoryGuard();

        template <typename T, typename ...Args> 
        [[nodiscard]]
        T* new_item(Args&&...);

        [[nodiscard]]
        void* allocate_bytes(std::size_t);

        std::size_t count_allocations() const;

        void free(void**);

    private:
        std::vector<void*> allocations;
    };

    using memory_guard_t = MemoryGuard;
}
