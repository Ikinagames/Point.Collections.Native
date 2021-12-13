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

#include "pch.h"
#include "debug.h"

#include <stdio.h>
#include <string>
#include <stdio.h>
#include <sstream>

namespace Point {
    namespace Collections {
        void  Debug::Log(const char* message, Color color) {
            if (callbackInstance != nullptr)
                callbackInstance(message, (int)color, (int)strlen(message));
        }

        void  Debug::Log(const std::string message, Color color) {
            const char* tmsg = message.c_str();
            if (callbackInstance != nullptr)
                callbackInstance(tmsg, (int)color, (int)strlen(tmsg));
        }

        void  Debug::Log(const int message, Color color) {
            std::stringstream ss;
            ss << message;
            send_log(ss, color);
        }

        void  Debug::Log(const char message, Color color) {
            std::stringstream ss;
            ss << message;
            send_log(ss, color);
        }

        void  Debug::Log(const float message, Color color) {
            std::stringstream ss;
            ss << message;
            send_log(ss, color);
        }

        void  Debug::Log(const double message, Color color) {
            std::stringstream ss;
            ss << message;
            send_log(ss, color);
        }

        void Debug::Log(const bool message, Color color) {
            std::stringstream ss;
            if (message)
                ss << "true";
            else
                ss << "false";

            send_log(ss, color);
        }

        void Debug::send_log(const std::stringstream& ss, const Color& color) {
            const std::string tmp = ss.str();
            const char* tmsg = tmp.c_str();
            if (callbackInstance != nullptr)
                callbackInstance(tmsg, (int)color, (int)strlen(tmsg));
        }
        //-------------------------------------------------------------------

        //Create a callback delegate
        void RegisterDebugCallback(FuncCallBack cb) {
            callbackInstance = cb;
        }

        /* Usages
        
        Debug::Log("Hellow Red", Color::Red);
        Debug::Log("Hellow Green", Color::Green);
        Debug::Log("Hellow Blue", Color::Blue);
        Debug::Log("Hellow Black", Color::Black);
        Debug::Log("Hellow White", Color::White);
        Debug::Log("Hellow Yellow", Color::Yellow);
        Debug::Log("Hellow Orange", Color::Orange);

        Debug::Log(true, Color::Black);
        Debug::Log(false, Color::Red);

        */
    }
}