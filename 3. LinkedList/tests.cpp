#include <stdexcept>
#include "catch.h"
#include "linkedlist.h"

TEST_CASE("test the LinkedList class")
{
    LinkedList<bool> a;

    LinkedList<int> b;
    b.insert_front(1);
    b.insert_front(2);
    b.insert_front(3);
    b.insert_front(4);

    LinkedList<std::string> c;
    c.insert_front("alfa");
    c.insert_front("beta");
    c.insert_front("gamma");
    c.insert_front("delta");
    c.insert_front("épsilon");
    c.insert_front("dseta");

    LinkedList<double> d;
    d.insert_front(1);
    d.insert_front(2.5);
    d.insert_front(-4.25);
    d.insert_front(10.75);
    d.insert_front(42);
    d.insert_front(0);
    d.insert_front(76.125);
    d.insert_front(-5.5);

    SECTION("test to_string") {
        REQUIRE(a.to_string() == "[]");
        REQUIRE(b.to_string() == "[4, 3, 2, 1]");
        REQUIRE(c.to_string()
            == "[dseta, épsilon, delta, gamma, beta, alfa]");
        REQUIRE(d.to_string()
            == "[-5.5, 76.125, 0, 42, 10.75, -4.25, 2.5, 1]");
    }

    SECTION("test size") {
        REQUIRE(a.size() == 0);
        REQUIRE(b.size() == 4);
        REQUIRE(c.size() == 6);
        REQUIRE(d.size() == 8);
    }

    // SECTION("test is_empty") {
    //     REQUIRE(a.is_empty());
    //     REQUIRE_FALSE(b.is_empty());
    //     REQUIRE_FALSE(c.is_empty());
    //     REQUIRE_FALSE(d.is_empty());
    // }

    // SECTION("test insert_back") {
    //     a.insert_back(true);
    //     a.insert_back(false);
    //     REQUIRE(a.size() == 2);
    //     REQUIRE(a.to_string() == "[1, 0]");
    //     b.insert_back(5);
    //     b.insert_back(10);
    //     b.insert_back(500);
    //     REQUIRE(b.size() == 7);
    //     REQUIRE(b.to_string() == "[4, 3, 2, 1, 5, 10, 500]");
    //     c.insert_back("eta");
    //     REQUIRE(c.to_string()
    //         == "[dseta, épsilon, delta, gamma, beta, alfa, eta]");
    //     d.insert_back(3.1416);
    //     d.insert_back(2.7182);
    //     d.insert_back(1.618);
    //     d.insert_back(1.4142);
    //     REQUIRE(d.size() == 12);
    //     REQUIRE(d.to_string()
    //         == "[-5.5, 76.125, 0, 42, 10.75, -4.25, 2.5, 1, "
    //           "3.1416, 2.7182, 1.618, 1.4142]");
    // }

    // SECTION("test constructor with initializer_list") {
    //     LinkedList<bool> a {};
    //     REQUIRE(a.to_string() == "[]");
    //     LinkedList<int> b {1, 2, 3, 4};
    //     REQUIRE(b.to_string() == "[1, 2, 3, 4]");
    //     LinkedList<std::string> c {"alfa", "beta", "gamma", "delta",
    //         "épsilon", "dseta"};
    //     REQUIRE(c.to_string()
    //         == "[alfa, beta, gamma, delta, épsilon, dseta]");
    //     LinkedList<double> d {1, 2.5, -4.25, 10.75, 42, 0, 76.125, -5.5};
    //     REQUIRE(d.to_string()
    //         == "[1, 2.5, -4.25, 10.75, 42, 0, 76.125, -5.5]");
    // }

    // SECTION("test contains") {
    //     REQUIRE_FALSE(a.contains(true));
    //     REQUIRE(b.contains(4));
    //     REQUIRE_FALSE(b.contains(5));
    //     REQUIRE(c.contains("gamma"));
    //     REQUIRE_FALSE(c.contains("omega"));
    //     REQUIRE(d.contains(0));
    //     REQUIRE_FALSE(d.contains(3.1416));
    // }

    // SECTION("test get") {
    //     REQUIRE_THROWS_AS(a.get(-1), std::out_of_range);
    //     REQUIRE_THROWS_AS(a.get(0), std::out_of_range);
    //     REQUIRE_THROWS_AS(b.get(-1), std::out_of_range);
    //     REQUIRE(b.get(0) == 4);
    //     REQUIRE(b.get(3) == 1);
    //     REQUIRE_THROWS_AS(b.get(4), std::out_of_range);
    //     REQUIRE_THROWS_AS(c.get(-10), std::out_of_range);
    //     REQUIRE(c.get(2) == "delta");
    //     REQUIRE(c.get(5) == "alfa");
    //     REQUIRE_THROWS_AS(c.get(10), std::out_of_range);
    //     REQUIRE_THROWS_AS(d.get(-100), std::out_of_range);
    //     REQUIRE(d.get(1) == 76.125);
    //     REQUIRE(d.get(7) == 1.0);
    //     REQUIRE_THROWS_AS(d.get(100), std::out_of_range);
    // }

    // SECTION("test insert_at") {
    //     REQUIRE_THROWS_AS(a.insert_at(-1, true), std::out_of_range);
    //     a.insert_at(0, false);
    //     REQUIRE(a.to_string() == "[0]");
    //     a.insert_at(0, true);
    //     REQUIRE(a.to_string() == "[1, 0]");
    //     a.insert_at(2, true);
    //     REQUIRE(a.to_string() == "[1, 0, 1]");
    //     REQUIRE_THROWS_AS(b.insert_at(-1, 2), std::out_of_range);
    //     b.insert_at(4, 5);
    //     b.insert_at(0, 6);
    //     b.insert_at(2, 7);
    //     b.insert_at(4, 8);
    //     b.insert_at(8, 9);
    //     b.insert_at(1, 10);
    //     REQUIRE(b.size() == 10);
    //     REQUIRE(b.to_string() == "[6, 10, 4, 7, 3, 8, 2, 1, 5, 9]");
    //     REQUIRE_THROWS_AS(b.insert_at(11, 0), std::out_of_range);
    //     REQUIRE_THROWS_AS(c.insert_at(-15, "pi"), std::out_of_range);
    //     c.insert_at(6, "omega");
    //     c.insert_at(6, "psi");
    //     c.insert_at(0, "eta");
    //     c.insert_at(2, "theta");
    //     REQUIRE(b.size() == 10);
    //     REQUIRE(c.to_string()
    //         == "[eta, dseta, theta, épsilon, delta, gamma, "
    //           "beta, alfa, psi, omega]");
    //     REQUIRE_THROWS_AS(c.insert_at(11, "pi"), std::out_of_range);
    //     REQUIRE_THROWS_AS(d.insert_at(-101, 3.1416), std::out_of_range);
    //     d.insert_at(1, 2.4142);
    //     d.insert_at(0, 3.1416);
    //     d.insert_at(0, 2.7182);
    //     d.insert_at(d.size(), 1.618);
    //     d.insert_at(d.size(), 1.4142);
    //     REQUIRE(d.size() == 13);
    //     REQUIRE(d.to_string()
    //         == "[2.7182, 3.1416, -5.5, 2.4142, 76.125, 0, 42, 10.75, "
    //           "-4.25, 2.5, 1, 1.618, 1.4142]");
    // }

    // SECTION("test remove_front") {
    //     REQUIRE_THROWS_AS(a.remove_front(), std::length_error);
    //     REQUIRE(b.remove_front() == 4);
    //     REQUIRE(b.remove_front() == 3);
    //     REQUIRE(b.size() == 2);
    //     REQUIRE(b.to_string() == "[2, 1]");
    //     REQUIRE(b.remove_front() == 2);
    //     REQUIRE(b.remove_front() == 1);
    //     REQUIRE(b.size() == 0);
    //     REQUIRE(b.to_string() == "[]");
    //     REQUIRE_THROWS_AS(b.remove_front(), std::length_error);
    //     REQUIRE(c.remove_front() == "dseta");
    //     REQUIRE(c.remove_front() == "épsilon");
    //     REQUIRE(c.remove_front() == "delta");
    //     REQUIRE(c.size() == 3);
    //     REQUIRE(c.to_string() == "[gamma, beta, alfa]");
    //     double total = 0;
    //     while (not d.is_empty()) {
    //         total += d.remove_front();
    //     }
    //     REQUIRE(d.size() == 0);
    //     REQUIRE(d.to_string() == "[]");
    //     REQUIRE(total == 122.625);
    // }

    // SECTION("test remove_back") {
    //     REQUIRE_THROWS_AS(a.remove_back(), std::length_error);
    //     REQUIRE(b.remove_back() == 1);
    //     REQUIRE(b.remove_back() == 2);
    //     REQUIRE(b.size() == 2);
    //     REQUIRE(b.to_string() == "[4, 3]");
    //     REQUIRE(b.remove_back() == 3);
    //     REQUIRE(b.remove_back() == 4);
    //     REQUIRE(b.size() == 0);
    //     REQUIRE(b.to_string() == "[]");
    //     REQUIRE_THROWS_AS(b.remove_back(), std::length_error);
    //     REQUIRE(c.remove_back() == "alfa");
    //     REQUIRE(c.remove_back() == "beta");
    //     REQUIRE(c.remove_back() == "gamma");
    //     REQUIRE(c.size() == 3);
    //     REQUIRE(c.to_string() == "[dseta, épsilon, delta]");
    //     double total = 0;
    //     while (not d.is_empty()) {
    //         total += d.remove_back();
    //     }
    //     REQUIRE(d.size() == 0);
    //     REQUIRE(d.to_string() == "[]");
    //     REQUIRE(total == 122.625);
    // }

    // SECTION("test remove_at") {
    //     REQUIRE_THROWS_AS(a.remove_at(0), std::out_of_range);
    //     REQUIRE_THROWS_AS(b.remove_at(-1), std::out_of_range);
    //     REQUIRE(b.remove_at(0) == 4);
    //     REQUIRE(b.remove_at(2) == 1);
    //     REQUIRE(b.size() == 2);
    //     REQUIRE(b.to_string() == "[3, 2]");
    //     REQUIRE_THROWS_AS(b.remove_at(2), std::out_of_range);
    //     REQUIRE_THROWS_AS(c.remove_at(6), std::out_of_range);
    //     REQUIRE(c.remove_at(5) == "alfa");
    //     REQUIRE(c.remove_at(0) == "dseta");
    //     REQUIRE(c.remove_at(3) == "beta");
    //     REQUIRE(c.remove_at(1) == "delta");
    //     REQUIRE(c.size() == 2);
    //     REQUIRE(c.to_string() == "[épsilon, gamma]");
    //     double total = 0;
    //     while (not d.is_empty()) {
    //         total += d.remove_at(d.size() - 1);
    //     }
    //     REQUIRE(d.size() == 0);
    //     REQUIRE(d.to_string() == "[]");
    //     REQUIRE(total == 122.625);
    // }

    // SECTION("test extend") {
    //     LinkedList<bool> a2;
    //     LinkedList<bool> a3 {true, false, true, true};
    //     a.extend(a2);
    //     REQUIRE(a.size() == 0);
    //     REQUIRE(a.to_string() == "[]");
    //     a.extend(a3);
    //     REQUIRE(a.size() == 4);
    //     REQUIRE(a.to_string() == "[1, 0, 1, 1]");
    //     a3.extend(a2);
    //     REQUIRE(a3.size() == 4);
    //     REQUIRE(a3.to_string() == "[1, 0, 1, 1]");
    //     LinkedList<int> b2 {5, 6, 7, 8};
    //     b.extend(b2);
    //     REQUIRE(b.size() == 8);
    //     REQUIRE(b.to_string() == "[4, 3, 2, 1, 5, 6, 7, 8]");
    //     LinkedList<std::string> c2 {"eta", "theta", "iota", "kappa"};
    //     c2.extend(c);
    //     REQUIRE(c2.size() == 10);
    //     REQUIRE(c2.to_string()
    //         == "[eta, theta, iota, kappa, dseta, épsilon, delta, "
    //           "gamma, beta, alfa]");
    //     LinkedList<double> d2 {3.1416};
    //     LinkedList<double> d3 {};
    //     d.extend(d2);
    //     REQUIRE(d.size() == 9);
    //     d.extend(d3);
    //     REQUIRE(d.size() == 9);
    //     REQUIRE(d.to_string()
    //         == "[-5.5, 76.125, 0, 42, 10.75, -4.25, 2.5, 1, 3.1416]");
    // }
}
