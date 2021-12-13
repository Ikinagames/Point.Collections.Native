// Copyright 2021 Seung Ha Kim
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

#include "pch.h"
#include "fnv1a.h"

namespace Point {
	namespace Collections {
		const unsigned int kPrime32 = 16777619;
		const unsigned long kPrime64 = 1099511628211LU;
		const unsigned int kOffsetBasis32 = 2166136261U;
		const unsigned long kOffsetBasis64 = 14695981039346656037LU;

		void fnv1a32_str(char* str, UINT* output) {
			if (str == nullptr) {
				*output = kOffsetBasis32;
				return;
			}

			unsigned int hash = kOffsetBasis32;
			int length = strlen(str);

			for (int i = 0; i < length; i++)
			{
				hash *= kPrime32;
				hash ^= (unsigned int)str[i];
			}

			*output = hash;
		}
		void fnv1a32_byte(BYTE* buffer, int* length, UINT* output) {
			if (buffer == nullptr) {
				*output = kOffsetBasis32;
				return;
			}

			unsigned int hash = kOffsetBasis32;

			for (int i = 0; i < *length; i++)
			{
				hash *= kPrime32;
				hash ^= (unsigned int)buffer[i];
			}

			*output = hash;
		}
		//
		void fnv1a64_str(char* str, ULONG* output) {
			if (str == nullptr) {
				*output = kOffsetBasis64;
				return;
			}

			unsigned long hash = kOffsetBasis64;
			int length = strlen(str);

			for (int i = 0; i < length; i++)
			{
				hash *= kPrime64;
				hash ^= (unsigned long)str[i];
			}

			*output = hash;
		}
		void fnv1a64_byte(BYTE* buffer, int* length, ULONG* output) {
			if (buffer == nullptr) {
				*output = kOffsetBasis64;
				return;
			}

			unsigned long hash = kOffsetBasis64;

			for (int i = 0; i < *length; i++)
			{
				hash *= kPrime64;
				hash ^= (unsigned long)buffer[i];
			}

			*output = hash;
		}
	}
}