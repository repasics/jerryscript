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

import string
import random
import os

digs = string.digits + string.ascii_letters


def int2base(x, base):
    if x < 0:
        sign = -1
    elif x == 0:
        return digs[0]
    else:
        sign = 1

    x *= sign
    digits = []

    while x:
        digits.append(digs[int(x % base)])
        x = int(x / base)

    if sign < 0:
        digits.append('-')

    digits.reverse()

    return ''.join(digits)

def generate(DEST, SEED, COUNTER):

    MIN = -9007199254740991
    MAX = 9007199254740991
    COUNTER = 20

    file_to_open = os.path.join(DEST, "number-prototype-to-String.js")

    with open(file_to_open, "w") as file:

        random.seed(SEED)

        for i in range(2, 37):
            for j in range(COUNTER):
                N = random.randint(-MIN, MAX)
                file.write("assert ((%d).toString(%d) === '%s');\n" % (N, i , str(int2base(N, i))))
                file.write("assert ((%d).toString(%d) !== '%s');\n" % (N, i , str(int2base(N + 1, i))))
                file.write("assert ((%d).toString(%d) !== '%s');\n\n" % (N, i , str(int2base(N - 1, i))))
            file.write("\n")
