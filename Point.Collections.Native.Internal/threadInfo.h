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

#include <thread>

#include "pch.h"

namespace Point {
	namespace Collections {
		// ������ ������ ��� struct �Դϴ�.
		struct threadInfo
		{
		public:
			/// <summary>
			/// ���� ������ ������ ��ȯ�մϴ�.
			/// </summary>
			/// <returns></returns>
			static threadInfo get_current_thread();

			threadInfo();
			explicit threadInfo(std::thread::id id);

			std::thread::id get_owner();
			/// <summary>
			/// �� ������ ������ �޼ҵ尡 ȣ��� �����尡 ��ġ�ϴ��� ��ȯ�մϴ�.
			/// </summary>
			/// <returns></returns>
			bool validate();

			//////////////////////////////////////////////////////////////
			/*															*/
			//////////////////////////////////////////////////////////////
			explicit operator std::thread::id() const;
			bool operator ==(threadInfo other) const;
			bool operator !=(threadInfo other) const;
		private:
			std::thread::id thread_id;
		};
	}
}