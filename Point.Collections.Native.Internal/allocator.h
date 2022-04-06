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

#pragma once

#include <memory>

#include "pch.h"
#include "threadInfo.h"

namespace Point {
	namespace Collections {
		//////////////////////////////////////////////////////////////
		/*															*/
		//////////////////////////////////////////////////////////////
		struct MemoryChunk {
		private:

		public:
			// https://www.tutorialspoint.com/what-is-the-size-of-a-pointer-in-c-cplusplus#:~:text=The%20size%20of%20a%20pointer%20in%20C%2FC%2B%2B%20is%20not,size%20can%20be%208%20bytes.
			MemoryChunk* next;

			//MemoryChunk(void* nextptr);
		};

		//////////////////////////////////////////////////////////////
		/*															*/
		//////////////////////////////////////////////////////////////
		class MemoryPool
		{
		private:
			void* buffer;
			MemoryChunk* block;

			size_t chunk_size;
			size_t chunk_per_block; // Chunks per block

			void move_next(_Notnull_ size_t* size _Post_satisfies_(0 < size));
		public:
			MemoryPool(
				_In_ size_t chunk_size      _Post_satisfies_(0 < chunk_size),
				_In_ size_t chunk_per_block _Post_satisfies_(0 < chunk_per_block));
			~MemoryPool();

			void* allocate(_In_ size_t size _Post_satisfies_(0 < size));
			void reserve(_In_ _Notnull_ void* ptr);
		};
		//////////////////////////////////////////////////////////////
		/*															*/
		//////////////////////////////////////////////////////////////
		static threadInfo memorypool_owner;
		static MemoryPool* shared_memorypool_8;

		DLLEXPORT void memorypool_initialize();
		DLLEXPORT void memorypool_uninitialize();

		DLLEXPORT void* malloc(size_t size);
		DLLEXPORT void free(void* ptr);
	}
}