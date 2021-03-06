/** Copyright 2020-2021 Alibaba Group Holding Limited.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef SRC_COMMON_UTIL_ENV_H_
#define SRC_COMMON_UTIL_ENV_H_

#include <sys/param.h>
#include <sys/types.h>
#include <unistd.h>

#include <string>

namespace vineyard {

inline std::string get_hostname() {
  if (const char* envp = std::getenv("MY_HOST_NAME")) {
    return std::string(envp);
  } else {
    char hostname_value[MAXHOSTNAMELEN];
    gethostname(&hostname_value[0], MAXHOSTNAMELEN);
    return std::string(hostname_value);
  }
}

inline std::string get_nodename() {
  if (const char* envp = std::getenv("MY_NODE_NAME")) {
    return std::string(envp);
  } else {
    return get_hostname();
  }
}

inline int get_pid() { return static_cast<int>(getpid()); }

}  // namespace vineyard

#endif  // SRC_COMMON_UTIL_ENV_H_
