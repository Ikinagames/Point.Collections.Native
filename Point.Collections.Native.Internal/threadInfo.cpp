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

#include "pch.h"
#include "threadInfo.h"

namespace Point {
    namespace Collections {
        threadInfo threadInfo::get_current_thread() {
            return threadInfo();
        }

        threadInfo::threadInfo() {
            this->thread_id = std::this_thread::get_id();
        }
        threadInfo::threadInfo(std::thread::id id) {
            this->thread_id = id;
        }

        std::thread::id threadInfo::get_owner() {
            return thread_id;
        }
        bool threadInfo::validate() {
            if (thread_id != std::this_thread::get_id()) {
                return false;
            }

            return true;
        }

        //////////////////////////////////////////////////////////////
        /*															*/
        //////////////////////////////////////////////////////////////
        threadInfo::operator std::thread::id() const
        {
            return this->thread_id;
        }
        bool threadInfo::operator==(threadInfo other) const
        {
            if (this->thread_id == other.thread_id) return true;

            return false;
        }
        bool threadInfo::operator!=(threadInfo other) const
        {
            if (this->thread_id == other.thread_id) return false;

            return true;
        }
    }
}