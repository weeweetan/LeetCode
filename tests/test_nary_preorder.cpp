#include "589-preorder.cpp"
#include <climits>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>

#define CHECK(condition) do { if (!(condition)) { \
    std::cerr << "Line " << __LINE__ << ": " << #condition << '\n'; \
    std::exit(EXIT_FAILURE); \
} } while (false)

struct Tree {
    std::vector<std::unique_ptr<Node>> nodes;

    Node *add(int value)
    {
        nodes.emplace_back(new Node(value));
        return nodes.back().get();
    }
};

static void expect(Solution &solution, Node *root, const std::vector<int> &expected)
{
    CHECK(solution.preorder(root) == expected);
    CHECK(solution.preorderTraversal1(root) == expected);
}

static void examples()
{
    Tree tree;
    Node *root = tree.add(1);
    Node *three = tree.add(3);
    root->children = {three, tree.add(2), tree.add(4)};
    three->children = {tree.add(5), tree.add(6)};
    Solution solution;
    expect(solution, root, {1, 3, 5, 6, 2, 4});
    // Returning the traversal must leave the tree available to the next call.
    expect(solution, root, {1, 3, 5, 6, 2, 4});
}

static void edges()
{
    Solution solution;
    expect(solution, nullptr, {});
    for (int value : {0, -1, INT_MIN, INT_MAX}) {
        Node leaf(value);
        expect(solution, &leaf, {value});
    }
    Tree tree;
    Node *root = tree.add(7);
    Node *child = tree.add(7);
    root->children = {nullptr, child, nullptr};
    child->children = {tree.add(7), nullptr};
    expect(solution, root, {7, 7, 7});
}

static void shapes()
{
    Tree chain;
    Node *root = chain.add(0);
    Node *tail = root;
    std::vector<int> expected = {0};
    for (int value = 1; value < 512; ++value) {
        Node *next = chain.add(value);
        tail->children.push_back(next);
        tail = next;
        expected.push_back(value);
    }
    Solution solution;
    expect(solution, root, expected);

    Tree wide;
    root = wide.add(-1);
    expected = {-1};
    for (int value = 0; value < 2048; ++value) {
        root->children.push_back(wide.add(value));
        expected.push_back(value);
    }
    expect(solution, root, expected);
}

static void reuse()
{
    Tree tree;
    Node *first = tree.add(42);
    first->children = {tree.add(-2), tree.add(7)};
    Node *second = tree.add(100);
    Node *child = tree.add(8);
    second->children = {child};
    child->children = {tree.add(9)};
    Solution solution;
    const auto saved = solution.preorder(first);
    CHECK((saved == std::vector<int>{42, -2, 7}));
    expect(solution, nullptr, {});
    expect(solution, second, {100, 8, 9});
    expect(solution, child, {8, 9});
    expect(solution, first, {42, -2, 7});
    CHECK((saved == std::vector<int>{42, -2, 7}));
}

int main(int argc, char **argv)
{
    if (argc != 2) return 2;
    const std::string name(argv[1]);
    if (name == "examples") examples();
    else if (name == "edges") edges();
    else if (name == "shapes") shapes();
    else if (name == "reuse") reuse();
    else return 2;
    std::cout << name << ": passed\n";
}
