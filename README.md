# LeetCode

C / C++ 算法练习，保留题号与原文件名。当前回归检查重点覆盖第 76 题“最小覆盖子串”；其他题解尚未逐一审查。

## 构建与测试

需要 C99、C++11 编译器及 CMake 3.20+，不需要第三方库。

```sh
git clone https://github.com/weeweetan/LeetCode.git
cd LeetCode
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

保留原来的 `LeetCode` C 演示目标，并补齐其 `removeDuplicates` 链接依赖。[026-removeDuplicates.c](026-removeDuplicates.c) 的独立 main 在定义 `LEETCODE_NO_DEMO` 时不参与编译，单独编译该文件仍保留原演示。

## 第 76 题：最小覆盖子串

[076-minWindow.cpp](076-minWindow.cpp) 保留 `Solution::minWindow(string s, string t)` 接口和滑动窗口实现，按 `std::string` 的字节比较：

- 窗口必须包含目标的全部字节及其重复次数。
- 无解或任一输入为空时返回空字符串；目标比来源长时直接返回空字符串。
- 多个最短窗口等长时返回最先出现的一个。

例如 `ADOBECODEBANC / ABC` 返回 `BANC`，`abc / z` 返回空字符串，`abc / 空目标` 也返回空字符串。旧实现无解时错误地返回整个来源串；空目标时收缩条件始终成立，会越界读取。修复统一了无解标记，提前处理空目标，并使用与字符串长度匹配的索引和计数类型。

## 覆盖范围

[测试代码](tests/test_min_window.cpp) 包含 6 组算法检查：常规示例、空输入与无解、重复字符、NUL / 高位字节、14,560 对短字符串穷举、20 万字节长输入。穷举使用独立的子串枚举算法作参照，断言在 Release 下也生效。另有一组原 C 驱动的基本运行检查，共 7 组 CTest。

```sh
cmake -S . -B build-asan -DCMAKE_BUILD_TYPE=Debug -DENABLE_SANITIZERS=ON
cmake --build build-asan --parallel
ASAN_OPTIONS=detect_leaks=0 UBSAN_OPTIONS=halt_on_error=1 \
  ctest --test-dir build-asan --output-on-failure
```

CI 在 Linux / macOS 上运行 Clang ASan、UBSan，Linux 额外启用泄漏检查。原 C 驱动的基本检查不代表所有历史 C 题解均正确；新增题解回归时应使用独立目标，避免不同题目的 `Solution` 或 main 相互冲突。
