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

#include <atomic>

#include "pch.h"
#include "atomicOperator.h"

namespace Point {
	namespace Collections {
		atomicOperator::atomicOperator(Point::Collections::threadInfo thread)
		{
			this->value = ATOMIC_VAR_INIT(0);
			this->owner = thread;
		}
		atomicOperator::~atomicOperator()
		{
		}

		void atomicOperator::enter(int index) {
			int val = 1 << (index % 32);

			while (true)
			{
				int original = this->value.exchange(this->value | val);

				if ((original & val) != val) {
					this->owner = Point::Collections::threadInfo(std::this_thread::get_id());
					break;
				}
			}
		}
		void atomicOperator::enter() {
			while (true)
			{
				int original = this->value.exchange(1);

				if (original == 0) {
					this->owner = Point::Collections::threadInfo(std::this_thread::get_id());
					break;
				}
			}
		}

		void atomicOperator::exit(int index) {
			if (this->value == 0) return;
			int val = 1 << (index % 32);

			if (!owner.validate()) {
				throw;
			}

			this->value -= val;
		}
		void atomicOperator::exit() {
			if (this->value == 0) return;

			if (!owner.validate()) {
				throw;
			}

			this->value = 0;
		}
	}
}