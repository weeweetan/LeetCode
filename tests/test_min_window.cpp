#include "076-minWindow.cpp"
#include <array>
#include <cstdlib>
#include <iostream>
#include <vector>

#define CHECK(condition) do { if (!(condition)) { \
    std::cerr << "Line " << __LINE__ << ": " << #condition << '\n'; \
    std::exit(EXIT_FAILURE); \
} } while (false)

static void expect(const std::string &source, const std::string &target, const std::string &expected)
{
    Solution solution;
    const std::string actual = solution.minWindow(source, target);
    if (actual != expected) {
        std::cerr << "Incorrect minimum window: source=" << source.size()
                  << " target=" << target.size() << " expected=" << expected.size()
                  << " actual=" << actual.size() << '\n';
        std::exit(EXIT_FAILURE);
    }
}

static void examples()
{
    expect("ADOBECODEBANC", "ABC", "BANC");
    expect("a", "a", "a");
    expect("ab", "ba", "ab");
    expect("xabc", "abc", "abc");
    expect("abcx", "abc", "abc");
    expect("abc", "abc", "abc");
    expect("ABCabc", "abc", "abc");
    expect("abxba", "ab", "ab"); // Preserve the first of equal shortest windows.
    Solution reused;
    CHECK(reused.minWindow("ADOBECODEBANC", "ABC") == "BANC");
    CHECK(reused.minWindow("abc", "z").empty());
}

static void edges()
{
    expect("", "", "");
    expect("", "a", "");
    expect("abc", "", "");
    expect("a", "aa", "");
    expect("abc", "z", "");
    expect("abc", "AZ", "");
    expect("ab", "aa", "");
    expect("abc", "ABC", "");
}

static void multiplicity()
{
    expect("aaab", "aab", "aab");
    expect("bbaa", "aba", "baa");
    expect("aaaa", "aa", "aa");
    expect("aabaac", "aac", "aac");
    expect("cabbaac", "aabc", "baac");
    expect("abbbbca", "aac", "abbbbca");
    expect("abcccc", "bb", "");
}

static void bytes()
{
    expect(std::string("x\0ay", 4), std::string("\0a", 2), std::string("\0a", 2));
    expect(std::string("x\0a\0b", 5), std::string("\0\0", 2), std::string("\0a\0", 3));
    const std::string high = std::string(1, static_cast<char>(0xff)) + static_cast<char>(0x80);
    expect("x" + high + "y", high, high);
    std::string alphabet;
    for (unsigned value = 0; value < 256; ++value) alphabet += static_cast<char>(value);
    expect(alphabet, alphabet, alphabet);
    expect(alphabet, std::string(2, static_cast<char>(0xff)), "");
}

// Independent reference: enumerate candidate lengths, then each substring.
static std::string brute_force(const std::string &source, const std::string &target)
{
    if (target.empty()) return "";
    std::array<int, 256> needed = {};
    for (unsigned char c : target) ++needed[c];
    for (std::size_t length = target.size(); length <= source.size(); ++length) {
        for (std::size_t start = 0; start + length <= source.size(); ++start) {
            auto remaining = needed;
            std::size_t missing = target.size();
            for (std::size_t offset = 0; offset < length; ++offset) {
                const unsigned char c = static_cast<unsigned char>(source[start + offset]);
                if (remaining[c] > 0) --missing;
                --remaining[c];
            }
            if (missing == 0) return source.substr(start, length);
        }
    }
    return "";
}

static void words(std::string current, std::size_t length, std::vector<std::string> &output)
{
    if (current.size() == length) { output.push_back(current); return; }
    for (char c : std::string("abc")) words(current + c, length, output);
}

static void exhaustive()
{
    std::vector<std::string> sources, targets;
    for (std::size_t length = 0; length <= 5; ++length) words("", length, sources);
    for (std::size_t length = 0; length <= 3; ++length) words("", length, targets);
    for (const auto &source : sources)
        for (const auto &target : targets) expect(source, target, brute_force(source, target));
    CHECK(sources.size() * targets.size() == 14560);
    std::cout << "14560 exhaustive source/target pairs checked\n";
}

static void long_input()
{
    std::string source(200000, 'a');
    source += "bc";
    expect(source, "abc", "abc");
    expect(source, "z", "");
    expect(source, "", "");
    expect(std::string(200000, 'a'), std::string(4096, 'a'), std::string(4096, 'a'));
}

int main(int argc, char **argv)
{
    if (argc != 2) return 2;
    const std::string name(argv[1]);
    if (name == "examples") examples();
    else if (name == "edges") edges();
    else if (name == "multiplicity") multiplicity();
    else if (name == "bytes") bytes();
    else if (name == "exhaustive") exhaustive();
    else if (name == "long") long_input();
    else return 2;
    std::cout << name << ": passed\n";
}
