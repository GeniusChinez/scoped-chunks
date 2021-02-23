#pragma once

#include <cstdint>
#include <vector>

namespace smem {
    class Arena {
    public:
        Arena() = default;
        Arena(const Arena&) = delete;
        Arena(Arena&&) = delete;
        Arena& operator=(const Arena&) = delete;
        Arena& operator=(Arena&&) = delete;
        ~Arena();

        template <typename T, typename ...Args> 
        [[nodiscard]]
        T* new_item(Args&&...);

        [[nodiscard]]
        void* allocate_bytes(std::size_t);

        std::size_t count_allocations() const;

    private:
        std::vector<void*> allocations;
    };
}
