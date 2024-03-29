// Copyright 2024 Blaise Tine
// 
// Licensed under the Apache License;
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <bitset>

#include "pipeline.h"

#define SIZE 256

namespace tinyrv {

struct pipeline_trace_t;

class GShare {
  public:
    GShare();

    ~GShare();

    bool predict(pipeline_trace_t* trace);

  private:
    struct BTB_entry {
      Word target = 0;
      std::bitset<22> TAG = 0;
    };
    
    std::array<BTB_entry, SIZE> BTB;

    uint8_t BHR;
    std::array<int, SIZE> BHT;
};

}