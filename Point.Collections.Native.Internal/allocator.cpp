// Copyright 2022 Ikina Games
// Author : Seung Ha Kim (Syadeu)
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <cstdlib>

#include "pch.h"
#include "allocator.h"

namespace Point {
    namespace Collections {

        void* calculate_next_ptr(
            _In_ _Notnull_ void* ptr, 
            _In_ size_t alignment _Post_satisfies_(0 < alignment)) {
            char* p = (char*)ptr;
            p += alignment;

            return p;
        }
        MemoryChunk* allocate_block(
            _In_ size_t chunk_size      _Pre_satisfies_(0 < chunk_size),
            _In_ size_t chunk_per_block _Pre_satisfies_(0 < chunk_per_block))
        {
            // allocating
            size_t blocksize = chunk_size * chunk_per_block;

            MemoryChunk* first = (MemoryChunk*)malloc(blocksize);

            // chaining
            MemoryChunk* chunk = first;
            for (size_t i = 0; i < chunk_per_block - 1; i++)
            {
                chunk->next =
                    (MemoryChunk*)calculate_next_ptr(chunk, chunk_size);

                chunk = chunk->next;
            }

            chunk->next = nullptr;
            return first;
        }

        //////////////////////////////////////////////////////////////
        /*															*/
        //////////////////////////////////////////////////////////////
        //MemoryChunk::MemoryChunk(void* nextptr) {
        //    this->next = (MemoryChunk*)nextptr;
        //}
        //MemoryChunk* MemoryChunk::GetNext() {
        //    return this->next;
        //}
        //////////////////////////////////////////////////////////////
        /*															*/
        //////////////////////////////////////////////////////////////

        MemoryPool::MemoryPool(
            _In_ size_t chunk_size      _Pre_satisfies_(0 < chunk_size),
            _In_ size_t chunk_per_block _Pre_satisfies_(0 < chunk_per_block))
        {
            this->chunk_size = chunk_size;
            this->chunk_per_block = chunk_per_block;

            this->block = allocate_block(chunk_size, chunk_per_block);
            this->buffer = this->block;
        }
        MemoryPool::~MemoryPool() {
            free(buffer);
        }

        void MemoryPool::move_next(_Notnull_ size_t* size _Post_satisfies_(0 < size)) {
            //void* ptr = block->GetNext();
            //void* nextptr = calculate_next_ptr(ptr, alignment);

            //auto temp = MemoryChunk(nextptr);
            //memcpy(ptr, &temp, sizeof(MemoryChunk));

            //this->block = (MemoryChunk*)ptr;

            //*size -= alignment;
        }

        void* MemoryPool::allocate(_In_ size_t size _Post_satisfies_(0 < size)) 
        {
            if (block == nullptr) {
                block = allocate_block(chunk_size, chunk_per_block);
            }

            MemoryChunk* ptr = block;
            block = block->next;

            size_t left = size;
            while (0 < left)
            {
                if (block == nullptr) {
                    block = allocate_block(chunk_size, chunk_per_block);
                }

                block = block->next;

                left -= chunk_size;
            }
            

            return ptr;
        }
        void MemoryPool::reserve(_In_ _Notnull_ void* ptr) {
            
        }
        //////////////////////////////////////////////////////////////
        /*															*/
        //////////////////////////////////////////////////////////////
        // https://docs.microsoft.com/en-us/cpp/cpp/welcome-back-to-cpp-modern-cpp?view=msvc-170
        constexpr int default_shared_mempool_size = 10240;

        DLLEXPORT void memorypool_initialize() {
            memorypool_owner = threadInfo::get_current_thread();

            shared_memorypool_8 = new MemoryPool(default_shared_mempool_size, 8);
        }
        DLLEXPORT void memorypool_uninitialize() {
            delete(shared_memorypool_8);
        }

        DLLEXPORT void* Point::Collections::malloc(size_t size)
        {
            void* p = malloc(size);

            return p;
        }
        DLLEXPORT void Point::Collections::free(void* ptr)
        {
            free(ptr);
        }
    }
}