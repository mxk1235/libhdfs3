/********************************************************************
 * Copyright (c) 2013 - 2014, Pivotal Inc.
 * All rights reserved.
 *
 * Author: Zhanwei Wang
 ********************************************************************/
/********************************************************************
 * 2014 -
 * open source under Apache License Version 2.0
 ********************************************************************/
/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "Permission.h"

#include "Exception.h"
#include "ExceptionInternal.h"

namespace Hdfs {

#define ACL_BIT (1 << 12)
#define ENCRYPTED_BIT (1 << 13)


Permission::Permission(uint16_t mode) {
    if (mode >> 14) {
        THROW(InvalidParameter,
              "Invalid parameter: cannot convert %u to \"Permission\"",
              static_cast<unsigned int>(mode));
    }

    userAction = (Action)((mode >> 6) & 7);
    groupAction = (Action)((mode >> 3) & 7);
    otherAction = (Action)(mode & 7);
    stickyBit = (((mode >> 9) & 1) == 1);
    hasAcl = (mode & ACL_BIT) != 0;
    isEncrypted = (mode & ENCRYPTED_BIT) != 0;

}

}
