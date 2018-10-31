#!/usr/bin/env python

# Copyright JS Foundation and other contributors, http://js.foundation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import random
import os

def generate(DEST, SEED, COUNTER):

    MIN = -9007199254740991
    MAX = 9007199254740991

    file_to_open = os.path.join(DEST, "math-abs.js")

    with open(file_to_open, "w") as file:

            random.seed(SEED)

            for i in range(COUNTER):
                N = random.randint(MIN, MAX)
                ABS = N
                if (N < 0):
                    file.write("assert (Math['abs'](%d) !== %d);\n" % (N, ABS))
                    ABS = -N

                file.write("assert (Math['abs'](%d) === %d);\n" % (N, ABS))
                file.write("assert (Math['abs'](%d) !== %d);\n" % (N, ABS - 1))
                file.write("assert (Math['abs'](%d) !== %d);\n\n" % (N, ABS + 1))
