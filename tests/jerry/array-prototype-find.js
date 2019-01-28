// Copyright JS Foundation and other contributors, http://js.foundation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

function func (element) {
  return element > 8;
}

/* ES v6.0 22.1.3.8.2.
   Checking behavior when the function's this_argument is null */
try {
  Array.prototype.find.call(null, func);
  assert(false);
} catch (e) {
  assert(e instanceof TypeError);
}

/* ES v6.0 22.1.3.8.4.
Checking behavior when the length of the object is an object which throws error */
try {
  var o = {};
  Object.defineProperty(o, 'toString', { 'get' : function() { throw new ReferenceError("foo"); } });
  var a = { length : o };
  Array.prototype.find.call(a, func);
  assert(false);
} catch (e) {
  assert(e instanceof TypeError || e instanceof ReferenceError);
  if(e instanceof ReferenceError) {
    assert(e.message == "foo");
  }
}

/* ES v6.0 22.1.3.8.8.c
   Checking behavior when the first element deletes the second */
try {
  var f = function () { delete arr[1]; };
  var arr = [0, 1, 2, 3];
  Object.defineProperty(arr, '0', { 'get' : f });
  Array.prototype.find.call(arr, func);
} catch (e) {
  assert(e instanceof TypeError);
}
