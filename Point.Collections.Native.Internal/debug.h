// Copyright 2021 Ikina Games
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

#include "pch.h"
#include <stdio.h>
#include <string>
#include <stdio.h>
#include <sstream>

extern "C"
{
    //Create a callback delegate
    typedef void(*FuncCallBack)(const char* message, int color, int size);
    static FuncCallBack callbackInstance = nullptr;
    DLLEXPORT void RegisterDebugCallback(FuncCallBack cb);
}

namespace Point {
    namespace Collections {
        //Color Enum
        enum Color { Red, Green, Blue, Black, White, Yellow, Orange };

        class Debug
        {
        public:
            static void log(const char* message, Color color = Color::Black);
            static void log(const std::string message, Color color = Color::Black);
            static void log(const int message, Color color = Color::Black);
            static void log(const char message, Color color = Color::Black);
            static void log(const float message, Color color = Color::Black);
            static void log(const double message, Color color = Color::Black);
            static void log(const bool message, Color color = Color::Black);

        private:
            static void send_log(const std::stringstream& ss, const Color& color);
        };
    }
}