# About

## Binary size
 |    Region   | Minimal profile (B)| Micro profile (B) | Difference (B) |
 | ------------|--------------------|-------------------|----------------|
 |     text    |      71121         |      29048        |   **-42073**   |
 |     data    |       352          |       506         |    **+154**    |
 |     bss     |     1071224        |       116         |  **-1071108**  |
 | **SUMMARY** |    **142697**      |    **29670**      |  **-1113027**  |


## Usage

```
  <assuming you are in the jerryscript directory>
  cd micro_profile
  ./micro.sh my_source.js
```

## Micro profile restrictions

### Configuration
 - Heap size: 20KB
 - Link-time optimization: ON
 - All-in-one build: ON
 - Strip binary: ON
 - 32-bit cpointer: ON
 - System allocator: ON
 - Snapshot execution: ON
 - Floating point arithmetic: 32 bit
 - Jerry-libm: OFF
 - Compiler: arm-linux-gnueabihf-gcc
 - Compile-flags: "-Os -fno-optimize-sibling-calls -fno-if-conversion -finline-limit=500"
 - Last working commit-hash to be applied: 63e8287f2b8429d1b9f13068fe96e96aee280ce1

### Disabled features
- Builtins (Array, Boolean, Date, Function, Global, Object, Regexp, String)
- Eval
- Delete variable
- Floating point number stringification
- UTF-8 charaters (Note: Only ASCII characters are allowed, there is no run-time validation for it.)
- Property hashmap, lcache

## Results summary
 - Test folder: tests/jerry
 - Total tests: 305
 - Passing tests: 85
 - Failing tests : 220
 - Failing tests due to profile restrictions: 220
 - Measured commit-hash: 5472aff0dc478a1a54275cd75dbcd68058cae7fc

## Detailed results
| Test name                                             | Status | Reason                             |
|-------------------------------------------------------|--------|------------------------------------|
| and-or.js                                             | PASS   |                                    |
| arguments.js                                          | FAIL   | Disabled feature: delete           |
| arguments-parse.js                                    | FAIL   | Disabled feature: eval             |
| arithmetic-parse.js                                   | FAIL   | Disabled feature: eval             |
| arithmetics-2.js                                      | FAIL   | Disabled feature: eval             |
| arithmetics-bignums.js                                | FAIL   | 32 bit floating point arithmetics  |
| arithmetics.js                                        | FAIL   | Disabled feature: eval             |
| array.js                                              | FAIL   | Disabled feature: Builtins         |
| array-prototype-concat.js                             | FAIL   | Disabled builtin: Array            |
| array-prototype-every.js                              | FAIL   | Disabled builtin: Array            |
| array-prototype-filter.js                             | FAIL   | Disabled builtin: Array            |
| array-prototype-foreach.js                            | FAIL   | Disabled builtin: Array            |
| array-prototype-indexof.js                            | FAIL   | Disabled builtin: Array            |
| array-prototype-join.js                               | FAIL   | Disabled builtin: Array            |
| array-prototype-lastindexof.js                        | FAIL   | Disabled builtin: Array            |
| array-prototype-map.js                                | FAIL   | Disabled builtin: Array            |
| array-prototype-pop.js                                | FAIL   | Disabled builtin: Array            |
| array-prototype-push.js                               | FAIL   | Disabled builtin: Array            |
| array-prototype-reduce.js                             | FAIL   | Disabled builtin: Array            |
| array-prototype-reduce-right.js                       | FAIL   | Disabled builtin: Array            |
| array-prototype-reverse.js                            | FAIL   | Disabled builtin: Array            |
| array-prototype-shift.js                              | FAIL   | Disabled builtin: Array            |
| array-prototype-slice.js                              | FAIL   | Disabled builtin: Array            |
| array-prototype-some.js                               | FAIL   | Disabled builtin: Array            |
| array-prototype-sort.js                               | FAIL   | Disabled builtin: Array            |
| array-prototype-splice.js                             | FAIL   | Disabled builtin: Array            |
| array-prototype-tolocalestring.js                     | FAIL   | Disabled builtin: Array            |
| array-prototype-tostring.js                           | FAIL   | Disabled builtin: Array            |
| array-prototype-unshift.js                            | FAIL   | Disabled builtin: Array            |
| assignments.js                                        | PASS   |                                    |
| bitwise-logic.js                                      | PASS   |                                    |
| break-continue-nested-to-try-with-blocks.js           | PASS   |                                    |
| builtin-constructor-class.js                          | FAIL   | Disabled builtins                  |
| date-annexb.js                                        | FAIL   | Disabled builtin: Date             |
| date-construct.js                                     | FAIL   | Disabled builtin: Date             |
| date-getters.js                                       | FAIL   | Disabled builtin: Date             |
| date-parse.js                                         | FAIL   | Disabled builtin: Date             |
| date-setters.js                                       | FAIL   | Disabled builtin: Date             |
| date-tostring.js                                      | FAIL   | Disabled builtin: Date             |
| date-utc.js                                           | FAIL   | Disabled builtin: Date             |
| delete.js                                             | FAIL   | Disabled feature: delete           |
| empty-varg.js                                         | PASS   |                                    |
| equality.js                                           | PASS   |                                    |
| error.js                                              | FAIL   | Disabled builtin: Error            |
| escape-sequences.js                                   | FAIL   | Disabled builtin: String           |
| eval.js                                               | FAIL   | Disabled feature: eval             |
| for-in.js                                             | FAIL   | Disabled builtin: Object           |
| for-in-parse.js                                       | FAIL   | Disabled feature: eval             |
| for.js                                                | PASS   |                                    |
| func-decl.js                                          | FAIL   | Disabled feature: eval             |
| function-args.js                                      | FAIL   | Disabled builtin: Error            |
| function-construct.js                                 | FAIL   | Disabled builtin: Error            |
| function-external.js                                  | FAIL   | Disabled builtin: Error            |
| function.js                                           | PASS   |                                    |
| function-return.js                                    | PASS   |                                    |
| function-prototype-apply.js                           | FAIL   | Disabled builtin: Function         |
| function-prototype-bind.js                            | FAIL   | Disabled builtin: Function         |
| function.prototype.js                                 | FAIL   | Disabled builtin: Function         |
| function-prototype-tostring.js                        | FAIL   | Disabled builtin: Function         |
| function-return.js                                    | FAIL   | Disabled builtin: Function         |
| function-scopes.js                                    | FAIL   | Disabled builtin: Function         |
| gc.js                                                 | FAIL   | Disabled feature: gc               |
| getter-setter-this-value.js                           | FAIL   | Disabled builtin: Object           |
| get-value.js                                          | FAIL   | Disabled builtin: Object           |
| global-escaping.js                                    | FAIL   | Disabled builtin: Global           |
| global.js                                             | FAIL   | Disabled builtin: Global           |
| global-parsefloat.js                                  | FAIL   | Disabled builtin: Global           |
| global-parseint.js                                    | FAIL   | Disabled builtin: Global           |
| global-uri-coding.js                                  | FAIL   | Disabled builtin: Global           |
| hash.js                                               | PASS   |                                    |
| if-else.js                                            | PASS   |                                    |
| if_parser.js                                          | FAIL   | Disabled feature: eval             |
| insert-semicolon.js                                   | FAIL   | Disabled builtin: Function         |
| json-parse.js                                         | FAIL   | Disabled builtin: JSON             |
| json-stringify.js                                     | FAIL   | Disabled builtin: JSON             |
| labelled-statements.js                                | PASS   |                                    |
| logical.js                                            | PASS   |                                    |
| math-abs.js                                           | FAIL   | Disabled builtin: Math             |
| math-exp.js                                           | FAIL   | Disabled builtin: Math             |
| math-log.js                                           | FAIL   | Disabled builtin: Math             |
| math-max.js                                           | FAIL   | Disabled builtin: Math             |
| math-min.js                                           | FAIL   | Disabled builtin: Math             |
| math-pow.js                                           | FAIL   | Disabled builtin: Math             |
| math-round.js                                         | FAIL   | Disabled builtin: Math             |
| math-trig.js                                          | FAIL   | Disabled builtin: Math             |
| N.compact-profile-error.js                            | FAIL   | Disabled feature: eval             |
| nested-function.js                                    | PASS   |                                    |
| new-line-in-literal.js                                | FAIL   | Disabled feature: eval             |
| number-prototype-to-exponential.js                    | FAIL   | Disabled builtin: Number           |
| number-prototype-to-fixed.js                          | FAIL   | Disabled builtin: Number           |
| number-prototype-to-precision.js                      | FAIL   | Disabled builtin: Number           |
| number-prototype-to-string.js                         | FAIL   | Disabled builtin: Number           |
| object-create.js                                      | FAIL   | Disabled builtin: Object           |
| object-define-properties.js                           | FAIL   | Disabled builtin: Object           |
| object-defineproperty.js                              | FAIL   | Disabled builtin: Object           |
| object_freeze.js                                      | FAIL   | Disabled builtin: Object           |
| object-get-own-property-descriptor.js                 | FAIL   | Disabled builtin: Object           |
| object-get-own-property-names.js                      | FAIL   | Disabled builtin: Object           |
| object-is-extensible.js                               | FAIL   | Disabled builtin: Object           |
| object-keys.js                                        | FAIL   | Disabled builtin: Object           |
| object-literal-2.js                                   | FAIL   | Disabled feature: eval             |
| object-literal.js                                     | FAIL   | Disabled builtin: Object           |
| object-prototype-hasownproperty.js                    | FAIL   | Disabled builtin: Object           |
| object-prototype-isprototypeof.js                     | FAIL   | Disabled builtin: Object           |
| object-prototype-propertyisenumerable.js              | FAIL   | Disabled builtin: Object           |
| object-prototype-tolocalestring.js                    | FAIL   | Disabled builtin: Object           |
| object_seal.js                                        | FAIL   | Disabled builtin: Object           |
| octal.js                                              | PASS   |                                    |
| parser-oom.js                                         | FAIL   | Disabled feature: eval             |
| regexp-alternatives.js                                | FAIL   | Disabled builtin: Regexp           |
| regexp-assertions.js                                  | FAIL   | Disabled builtin: Regexp           |
| regexp-backreference.js                               | FAIL   | Disabled builtin: Regexp           |
| regexp-capture-groups.js                              | FAIL   | Disabled builtin: Regexp           |
| regexp-character-class.js                             | FAIL   | Disabled builtin: Regexp           |
| regexp-construct.js                                   | FAIL   | Disabled builtin: Regexp           |
| regexp-literal.js                                     | FAIL   | Disabled builtin: Regexp           |
| regexp-non-capture-groups.js                          | FAIL   | Disabled builtin: Regexp           |
| regexp-routines.js                                    | FAIL   | Disabled builtin: Regexp           |
| regexp-simple-atom-and-iterations.js                  | FAIL   | Disabled builtin: Regexp           |
| regression-test-issue-1054.js                         | FAIL   | Disabled builtin: Number           |
| regression-test-issue-1065.js                         | FAIL   | Disabled builtin: Regexp           |
| regression-test-issue-1071.js                         | FAIL   | Disabled builtin: Date             |
| regression-test-issue-1072.js                         | PASS   |                                    |
| regression-test-issue-1073.js                         | PASS   |                                    |
| regression-test-issue-1074.js                         | PASS   |                                    |
| regression-test-issue-1075.js                         | PASS   |                                    |
| regression-test-issue-1076.js                         | PASS   |                                    |
| regression-test-issue-1078.js                         | FAIL   | Disabled builtin: Array            |
| regression-test-issue-1079.js                         | FAIL   | Disabled builtin: Array            |
| regression-test-issue-1080.js                         | FAIL   | Disabled builtin: Regexp           |
| regression-test-issue-1081.js                         | PASS   |                                    |
| regression-test-issue-1082.js                         | PASS   |                                    |
| regression-test-issue-1083.js                         | PASS   |                                    |
| regression-test-issue-112.js                          | FAIL   | Disabled feature: delete           |
| regression-test-issue-113.js                          | FAIL   | Disabled feature: float stringify  |
| regression-test-issue-114.js                          | PASS   |                                    |
| regression-test-issue-115.js                          | FAIL   | Disabled builtin: Object           |
| regression-test-issue-116.js                          | FAIL   | Disabled builtin: Error            |
| regression-test-issue-117.js                          | PASS   |                                    |
| regression-test-issue-121.js                          | FAIL   | Disabled builtin: Object           |
| regression-test-issue-122.js                          | FAIL   | Disabled builtin: Object           |
| regression-test-issue-123.js                          | PASS   |                                    |
| regression-test-issue-1282.js                         | PASS   |                                    |
| regression-test-issue-1284.js                         | PASS   |                                    |
| regression-test-issue-1286.js                         | FAIL   | Disabled feature: eval             |
| regression-test-issue-128.js                          | PASS   |                                    |
| regression-test-issue-1292.js                         | FAIL   | Disabled builtin: Error            |
| regression-test-issue-129.js                          | FAIL   | Disabled feature: eval             |
| regression-test-issue-1300.js                         | PASS   |                                    |
| regression-test-issue-1309.js                         | FAIL   | Disabled builtin: Error            |
| regression-test-issue-130.js                          | FAIL   | Disabled builtin: Math             |
| regression-test-issue-132.js                          | FAIL   | Disabled builtin: Object           |
| regression-test-issue-1386.js                         | FAIL   | Disabled builtin: Date             |
| regression-test-issue-1387.js                         | PASS   |                                    |
| regression-test-issue-1389.js                         | PASS   |                                    |
| regression-test-issue-1533.js                         | PASS   |                                    |
| regression-test-issue-1546.js                         | FAIL   | Disabled builtin: String           |
| regression-test-issue-1547.js                         | FAIL   | Disabled builtin: Date             |
| regression-test-issue-1552.js                         | PASS   |                                    |
| regression-test-issue-1555.js                         | FAIL   | Disabled feature: eval             |
| regression-test-issue-1556.js                         | FAIL   | Disabled feature: eval             |
| regression-test-issue-156.js                          | PASS   |                                    |
| regression-test-issue-1621.js                         | FAIL   | Disabled feature: eval             |
| regression-test-issue-1636.js                         | FAIL   | Disabled builtin: Math             |
| regression-test-issue-1641.js                         | FAIL   | Disabled builtin: String           |
| regression-test-issue-164.js                          | PASS   |                                    |
| regression-test-issue-1657.js                         | FAIL   | Disabled builtin: Date             |
| regression-test-issue-1829.js                         | PASS   |                                    |
| regression-test-issue-1830.js                         | FAIL   | Disabled builtin: Regexp           |
| regression-test-issue-1833.js                         | PASS   |                                    |
| regression-test-issue-1855.js                         | PASS   |                                    |
| regression-test-issue-1917.js                         | FAIL   | Disabled builtin: Regexp           |
| regression-test-issue-1934.js                         | FAIL   | Disabled builtin: Array            |
| regression-test-issue-1947.js                         | PASS   |                                    |
| regression-test-issue-195.js                          | PASS   |                                    |
| regression-test-issue-1970.js                         | FAIL   | Disabled builtin: Function         |
| regression-test-issue-1972.js                         | FAIL   | Disabled builtin: Array            |
| regression-test-issue-1973.js                         | PASS   |                                    |
| regression-test-issue-1974.js                         | FAIL   | Disabled builtin: Number           |
| regression-test-issue-1990.js                         | FAIL   | Disabled builtin: Global           |
| regression-test-issue-1993.js                         | FAIL   | Disabled builtin: Global           |
| regression-test-issue-2008.js                         | PASS   |                                    |
| regression-test-issue-2073.js                         | FAIL   | Disabled builtin: Date             |
| regression-test-issue-2105.js                         | FAIL   | Disabled builtin: Object           |
| regression-test-issue-2108.js                         | FAIL   | Disabled builtin: Number           |
| regression-test-issue-212.js                          | FAIL   | Disabled feature: eval             |
| regression-test-issue-2178.js                         | FAIL   | Disabled builtin: Regexp           |
| regression-test-issue-2182.js                         | FAIL   | Disabled builtin: Function         |
| regression-test-issue-2198.js                         | FAIL   | Disabled builtin: Regexp           |
| regression-test-issue-2200.js                         | FAIL   | Disabled builtin: JSON             |
| regression-test-issue-2204.js                         | FAIL   | Disabled builtin: Regexp           |
| regression-test-issue-2230.js                         | FAIL   | Disabled builtin: Regexp           |
| regression-test-issue-2237.js                         | FAIL   | Disabled builtin: Regexp           |
| regression-test-issue-2272.js                         | FAIL   | Disabled builtin: Math             |
| regression-test-issue-2384.js                         | FAIL   | Disabled builtin: Regexp           |
| regression-test-issue-2386.js                         | FAIL   | Disabled builtin: Number           |
| regression-test-issue-2398.js                         | PASS   |                                    |
| regression-test-issue-2400.js                         | PASS   |                                    |
| regression-test-issue-2409.js                         | FAIL   | Disabled feature: eval             |
| regression-test-issue-2451.js                         | FAIL   | Disabled feature: UTF-8 characters |
| regression-test-issue-2452.js                         | FAIL   | Disabled feature: UTF-8 characters |
| regression-test-issue-2453.js                         | FAIL   | Disabled feature: UTF-8 characters |
| regression-test-issue-245.js                          | FAIL   | Disabled builtin: Regexp           |
| regression-test-issue-2478.js                         | FAIL   | Disabled builtin: Function         |
| regression-test-issue-255.js                          | FAIL   | Disabled builtin: Regexp           |
| regression-test-issue-257.js                          | FAIL   | Disabled builtin: Regexp           |
| regression-test-issue-260.js                          | PASS   |                                    |
| regression-test-issue-261.js                          | PASS   |                                    |
| regression-test-issue-262.js                          | PASS   |                                    |
| regression-test-issue-263.js                          | PASS   |                                    |
| regression-test-issue-264.js                          | PASS   |                                    |
| regression-test-issue-265.js                          | FAIL   | Disabled builtin: Global           |
| regression-test-issue-266.js                          | PASS   |                                    |
| regression-test-issue-267.js                          | PASS   |                                    |
| regression-test-issue-274.js                          | PASS   |                                    |
| regression-test-issue-276.js                          | PASS   |                                    |
| regression-test-issue-279.js                          | FAIL   | Disabled builtin: Regexp           |
| regression-test-issue-280.js                          | FAIL   | Disabled feature: eval             |
| regression-test-issue-281.js                          | PASS   |                                    |
| regression-test-issue-285.js                          | FAIL   | Disabled builtin: Regexp           |
| regression-test-issue-312.js                          | FAIL   | Disabled builtin: Regexp           |
| regression-test-issue-316.js                          | FAIL   | Disabled builtin: Regexp           |
| regression-test-issue-339.js                          | FAIL   | Disabled feature: eval             |
| regression-test-issue-340.js                          | PASS   |                                    |
| regression-test-issue-341.js                          | FAIL   | Disabled feature: eval             |
| regression-test-issue-354.js                          | PASS   |                                    |
| regression-test-issue-359.js                          | PASS   |                                    |
| regression-test-issue-380.js                          | FAIL   | Disabled feature: UTF-8 characters |
| regression-test-issue-381.js                          | PASS   |                                    |
| regression-test-issue-429.js                          | PASS   |                                    |
| regression-test-issue-440.js                          | PASS   |                                    |
| regression-test-issue-447.js                          | FAIL   | Disabled builtin: Error            |
| regression-test-issue-453.js                          | PASS   |                                    |
| regression-test-issue-541.js                          | FAIL   | Disabled builtin: Regexp           |
| regression-test-issue-563.js                          | FAIL   | Disabled feature: eval             |
| regression-test-issue-566.js                          | FAIL   | Disabled builtin: Date             |
| regression-test-issue-612.js                          | FAIL   | Disabled builtin: Regexp           |
| regression-test-issue-613.js                          | PASS   |                                    |
| regression-test-issue-614.js                          | FAIL   | Disabled builtin: JSON             |
| regression-test-issue-639.js                          | PASS   |                                    |
| regression-test-issue-640.js                          | PASS   |                                    |
| regression-test-issue-641.js                          | FAIL   | Disabled builtin: Regexp           |
| regression-test-issue-642.js                          | FAIL   | Disabled builtin: Function         |
| regression-test-issue-644.js                          | PASS   |                                    |
| regression-test-issue-646.js                          | PASS   |                                    |
| regression-test-issue-652.js                          | FAIL   | Disabled feature: eval             |
| regression-test-issue-653.js                          | PASS   |                                    |
| regression-test-issue-654.js                          | PASS   |                                    |
| regression-test-issue-655.js                          | FAIL   | Disabled feature: eval             |
| regression-test-issue-667.js                          | PASS   |                                    |
| regression-test-issue-669.js                          | PASS   |                                    |
| regression-test-issue-680.js                          | FAIL   | Disabled builtin: Error            |
| regression-test-issue-686.js                          | FAIL   | Disabled feature: eval             |
| regression-test-issue-689.js                          | PASS   |                                    |
| regression-test-issue-703.js                          | PASS   |                                    |
| regression-test-issue-725.js                          | FAIL   | Disabled feature: eval             |
| regression-test-issue-736.js                          | FAIL   | Disabled feature: eval             |
| regression-test-issue-737.js                          | FAIL   | Disabled feature: eval             |
| regression-test-issue-738.js                          | FAIL   | Disabled builtin: Boolean          |
| regression-test-issue-739.js                          | FAIL   | Disabled builtin: Regexp           |
| regression-test-issue-741.js                          | FAIL   | Disabled builtin: JSON             |
| regression-test-issue-743.js                          | PASS   |                                    |
| regression-test-issue-745.js                          | FAIL   | Disabled feature: eval             |
| regression-test-issue-747.js                          | FAIL   | Disabled builtin: String           |
| regression-test-issue-781.js                          | FAIL   | Disabled builtin: Function         |
| regression-test-issue-782.js                          | FAIL   | Disabled builtin: String           |
| regression-test-issue-783.js                          | FAIL   | Disabled builtin: Regexp           |
| regression-test-issue-785.js                          | PASS   |                                    |
| regression-test-issue-786.js                          | PASS   |                                    |
| regression-test-issue-787.js                          | FAIL   | Disabled builtin: Array            |
| regression-test-issue-798.js                          | PASS   |                                    |
| regression-test-issue-962.js                          | FAIL   | Disabled builtin: Regexp           |
| regression-test-issues-43-183.js                      | FAIL   | Disabled feature: eval             |
| relational.js                                         | FAIL   | Disabled feature: float stringify  |
| shift.js                                              | PASS   |                                    |
| sqrt.js                                               | FAIL   | Disabled builtin: Math             |
| strict.js                                             | FAIL   | Disabled builtin: Error            |
| string.js                                             | PASS   |                                    |
| string-prototype-charat.js                            | FAIL   | Disabled builtin: String           |
| string-prototype-charcodeat.js                        | FAIL   | Disabled builtin: String           |
| string-prototype-concat.js                            | FAIL   | Disabled builtin: String           |
| string-prototype-indexof.js                           | FAIL   | Disabled builtin: String           |
| string-prototype.js                                   | FAIL   | Disabled builtin: String           |
| string-prototype-lastindexof.js                       | FAIL   | Disabled builtin: String           |
| string-prototype-localecompare.js                     | FAIL   | Disabled builtin: String           |
| string-prototype-match.js                             | FAIL   | Disabled builtin: String           |
| string-prototype-replace.js                           | FAIL   | Disabled builtin: String           |
| string-prototype-search.js                            | FAIL   | Disabled builtin: String           |
| string-prototype-slice.js                             | FAIL   | Disabled builtin: String           |
| string-prototype-split.js                             | FAIL   | Disabled builtin: String           |
| string-prototype-substring.js                         | FAIL   | Disabled builtin: String           |
| string-prototype-substr.js                            | FAIL   | Disabled builtin: String           |
| string-prototype-trim.js                              | FAIL   | Disabled builtin: String           |
| string-surrogates-concat.js                           | FAIL   | Disabled feature: UTF-8 characters |
| string-upper-lower-case-conversion.js                 | FAIL   | Disabled feature: UTF-8 characters |
| switch-case.js                                        | PASS   |                                    |
| test-new-string.js                                    | FAIL   | Disabled builtin: String           |
| this-arg.js                                           | PASS   |                                    |
| try-catch-finally.js                                  | PASS   |                                    |
| typeof.js                                             | PASS   |                                    |
| unary-plus-minus.js                                   | FAIL   | Disabled builtin: Global           |
| var-decl.js                                           | FAIL   | Disabled feature: eval             |
| variables.js                                          | PASS   |                                    |
| windows-line-ending.js                                | PASS   |                                    |
| zero-character.js                                     | FAIL   | Disabled feature: eval             |
