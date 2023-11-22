#include <string>
#include <vector>
#include "catch.h"
#include "treeset.h"

TEST_CASE("test the TreeSet class")
{
    TreeSet<std::string> a;
    TreeSet<std::string> b;
    b.add("a");
    TreeSet<std::string> c {"m", "r", "p", "z",
        "g", "k", "a"};
    TreeSet<std::string> d {"d", "c", "e", "b",
        "f", "a", "g"};
    TreeSet<int> e {22, 30, 25, 35, 10, 5, 33,
        15, 12, 40, 17, 19, 20, 18, 16};
    TreeSet<int> f {8, 1, 7, 2, 6, 3, 5, 4};
    TreeSet<int> g {1, 2, 3, 4, 5, 6, 7, 8, 9,
        10, 11, 12, 13, 14, 15};
    TreeSet<int> h {8, 4, 12, 2, 6, 1, 5, 3,
        7, 10, 11, 14, 15, 9, 13};

    SECTION("test add") {
        REQUIRE(a.add("a"));
        REQUIRE_FALSE(a.add("a"));
        REQUIRE(b.add("z"));
        REQUIRE_FALSE(b.add("a"));
        REQUIRE(c.add("q"));
        REQUIRE_FALSE(c.add("k"));
        REQUIRE(d.add("h"));
        REQUIRE_FALSE(d.add("b"));
        REQUIRE(e.add(34));
        REQUIRE_FALSE(e.add(19));
        REQUIRE(f.add(9));
        REQUIRE_FALSE(f.add(4));
        REQUIRE(g.add(16));
        REQUIRE_FALSE(g.add(7));
        REQUIRE(h.add(0));
        REQUIRE_FALSE(h.add(6));
    }

    SECTION("test size") {
        REQUIRE(0 == a.size());
        REQUIRE(1 == b.size());
        REQUIRE(7 == c.size());
        REQUIRE(7 == d.size());
        REQUIRE(15 == e.size());
        REQUIRE(8 == f.size());
        REQUIRE(15 == g.size());
        REQUIRE(15 == h.size());
    }

    SECTION("test is_empty") {
        REQUIRE(a.is_empty());
        REQUIRE_FALSE(b.is_empty());
        REQUIRE_FALSE(c.is_empty());
        REQUIRE_FALSE(d.is_empty());
        REQUIRE_FALSE(e.is_empty());
        REQUIRE_FALSE(f.is_empty());
        REQUIRE_FALSE(g.is_empty());
        REQUIRE_FALSE(h.is_empty());
    }

    SECTION("test contains") {
        REQUIRE_FALSE(a.contains("a"));
        REQUIRE(b.contains("a"));
        REQUIRE_FALSE(b.contains("b"));
        REQUIRE(c.contains("m"));
        REQUIRE_FALSE(c.contains("b"));
        REQUIRE(d.contains("a"));
        REQUIRE_FALSE(d.contains("x"));
        REQUIRE(e.contains(19));
        REQUIRE_FALSE(e.contains(34));
        REQUIRE(f.contains(4));
        REQUIRE_FALSE(f.contains(0));
        REQUIRE(g.contains(4));
        REQUIRE_FALSE(g.contains(0));
        REQUIRE(h.contains(11));
        REQUIRE_FALSE(h.contains(16));
    }

    SECTION("test inorder") {
        std::vector<std::string> vs1, vs2, vs3, vs4;
        std::vector<int> vi1, vi2, vi3, vi4;
        a.inorder([&] (std::string s) { vs1.push_back(s); });
        REQUIRE(std::vector<std::string> {} == vs1);
        b.inorder([&] (std::string s) { vs2.push_back(s); });
        REQUIRE(std::vector<std::string> {"a"} == vs2);
        c.inorder([&] (std::string s) { vs3.push_back(s); });
        REQUIRE(std::vector<std::string> { "a", "g", "k", "m", "p",
            "r", "z" } == vs3);
        d.inorder([&] (std::string s) { vs4.push_back(s); });
        REQUIRE(std::vector<std::string> {"a", "b", "c", "d", "e",
            "f", "g"} == vs4);
        e.inorder([&] (int i) { vi1.push_back(i); });
        REQUIRE(std::vector<int> {5, 10, 12, 15, 16, 17, 18, 19, 20,
            22, 25, 30, 33, 35, 40} == vi1);
        f.inorder([&] (int i) { vi2.push_back(i); });
        REQUIRE(std::vector<int> {1, 2, 3, 4, 5, 6, 7, 8} == vi2);
        g.inorder([&] (int i) { vi3.push_back(i); });
        REQUIRE(std::vector<int> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
            12, 13, 14, 15} == vi3);
        h.inorder([&] (int i) { vi4.push_back(i); });
        REQUIRE(std::vector<int> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
            12, 13, 14, 15} == vi4);
    }

    SECTION("test preorder") {
        std::vector<std::string> vs1, vs2, vs3, vs4;
        std::vector<int> vi1, vi2, vi3, vi4;
        a.preorder([&] (std::string s) { vs1.push_back(s); });
        REQUIRE(std::vector<std::string> {} == vs1);
        b.preorder([&] (std::string s) { vs2.push_back(s); });
        REQUIRE(std::vector<std::string> {"a"} == vs2);
        c.preorder([&] (std::string s) { vs3.push_back(s); });
        REQUIRE(std::vector<std::string> {"m", "g", "a", "k", "r",
            "p", "z"} == vs3);
        d.preorder([&] (std::string s) { vs4.push_back(s); });
        REQUIRE(std::vector<std::string> {"d", "c", "b", "a", "e",
            "f", "g"} == vs4);
        e.preorder([&] (int i) { vi1.push_back(i); });
        REQUIRE(std::vector<int> {22, 10, 5, 15, 12, 17, 16, 19, 18,
            20, 30, 25, 35, 33, 40} == vi1);
        f.preorder([&] (int i) { vi2.push_back(i); });
        REQUIRE(std::vector<int> {8, 1, 7, 2, 6, 3, 5, 4} == vi2);
        g.preorder([&] (int i) { vi3.push_back(i); });
        REQUIRE(std::vector<int> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
            12, 13, 14, 15} == vi3);
        h.preorder([&] (int i) { vi4.push_back(i); });
        REQUIRE(std::vector<int> {8, 4, 2, 1, 3, 6, 5, 7, 12, 10, 9,
            11, 14, 13, 15} == vi4);
    }

    SECTION("test postorder") {
        std::vector<std::string> vs1, vs2, vs3, vs4;
        std::vector<int> vi1, vi2, vi3, vi4;
        a.postorder([&] (std::string s) { vs1.push_back(s); });
        REQUIRE(std::vector<std::string> {} == vs1);
        b.postorder([&] (std::string s) { vs2.push_back(s); });
        REQUIRE(std::vector<std::string> {"a"} == vs2);
        c.postorder([&] (std::string s) { vs3.push_back(s); });
        REQUIRE(std::vector<std::string> {"a", "k", "g", "p", "z",
            "r", "m"} == vs3);
        d.postorder([&] (std::string s) { vs4.push_back(s); });
        REQUIRE(std::vector<std::string> {"a", "b", "c", "g", "f",
            "e", "d"} == vs4);
        e.postorder([&] (int i) { vi1.push_back(i); });
        REQUIRE(std::vector<int> {5, 12, 16, 18, 20, 19, 17, 15, 10,
            25, 33, 40, 35, 30, 22} == vi1);
        f.postorder([&] (int i) { vi2.push_back(i); });
        REQUIRE(std::vector<int> {4, 5, 3, 6, 2, 7, 1, 8} == vi2);
        g.postorder([&] (int i) { vi3.push_back(i); });
        REQUIRE(std::vector<int> {15, 14, 13, 12, 11, 10, 9, 8, 7, 6,
            5, 4, 3, 2, 1} == vi3);
        h.postorder([&] (int i) { vi4.push_back(i); });
        REQUIRE(std::vector<int> {1, 3, 2, 5, 7, 6, 4, 9, 11, 10, 13,
            15, 14, 12, 8} == vi4);
    }

    SECTION("test levelorder") {
        std::vector<std::string> vs1, vs2, vs3, vs4;
        std::vector<int> vi1, vi2, vi3, vi4;
        a.levelorder([&] (std::string s) { vs1.push_back(s); });
        REQUIRE(std::vector<std::string> {} == vs1);
        b.levelorder([&] (std::string s) { vs2.push_back(s); });
        REQUIRE(std::vector<std::string> {"a"} == vs2);
        c.levelorder([&] (std::string s) { vs3.push_back(s); });
        REQUIRE(std::vector<std::string> {"m", "g", "r", "a", "k",
            "p", "z"} == vs3);
        d.levelorder([&] (std::string s) { vs4.push_back(s); });
        REQUIRE(std::vector<std::string> {"d", "c", "e", "b", "f",
            "a", "g"} == vs4);
        e.levelorder([&] (int i) { vi1.push_back(i); });
        REQUIRE(std::vector<int> {22, 10, 30, 5, 15, 25, 35, 12, 17,
            33, 40, 16, 19, 18, 20} == vi1);
        f.levelorder([&] (int i) { vi2.push_back(i); });
        REQUIRE(std::vector<int> {8, 1, 7, 2, 6, 3, 5, 4} == vi2);
        g.levelorder([&] (int i) { vi3.push_back(i); });
        REQUIRE(std::vector<int> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
            12, 13, 14, 15} == vi3);
        h.levelorder([&] (int i) { vi4.push_back(i); });
        REQUIRE(std::vector<int> {8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7,
            9, 11, 13, 15} == vi4);
    }

    SECTION("test height") {
        REQUIRE(-1 == a.height());
        REQUIRE(0 == b.height());
        REQUIRE(2 == c.height());
        REQUIRE(3 == d.height());
        REQUIRE(5 == e.height());
        REQUIRE(7 == f.height());
        REQUIRE(14 == g.height());
        REQUIRE(3 == h.height());
    }

    SECTION("test is_full") {
        REQUIRE(a.is_full());
        REQUIRE(b.is_full());
        REQUIRE(c.is_full());
        REQUIRE_FALSE(d.is_full());
        REQUIRE(e.is_full());
        REQUIRE_FALSE(f.is_full());
        REQUIRE_FALSE(g.is_full());
        REQUIRE(h.is_full());
    }

    SECTION("test leaf_count") {
        REQUIRE(0 == a.leaf_count());
        REQUIRE(1 == b.leaf_count());
        REQUIRE(4 == c.leaf_count());
        REQUIRE(2 == d.leaf_count());
        REQUIRE(8 == e.leaf_count());
        REQUIRE(1 == f.leaf_count());
        REQUIRE(1 == g.leaf_count());
        REQUIRE(8 == h.leaf_count());
    }

    SECTION("test is_perfect") {
        REQUIRE(a.is_perfect());
        REQUIRE(b.is_perfect());
        REQUIRE(c.is_perfect());
        REQUIRE_FALSE(d.is_perfect());
        REQUIRE_FALSE(e.is_perfect());
        REQUIRE_FALSE(f.is_perfect());
        REQUIRE_FALSE(g.is_perfect());
        REQUIRE(h.is_perfect());
    }
}
