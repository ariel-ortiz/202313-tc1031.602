#include "catch.h"
#include "dinoset.h"

TEST_CASE("test the DinoSet class")
{
    DinoSet a;

    DinoSet b;
    b.add(DinoId::velociraptor);
    b.add(DinoId::tyrannosaurus);

    DinoSet c;
    c.add(DinoId::tyrannosaurus);
    c.add(DinoId::procompsognathus);
    c.add(DinoId::pteranodon);

    // SECTION("test to_string") {
    //     REQUIRE(a.to_string() == "{}");
    //     REQUIRE(b.to_string() == "{velociraptor, tyrannosaurus}");
    //     REQUIRE(c.to_string()
    //         == "{tyrannosaurus, procompsognathus, pteranodon}");
    // }

    SECTION("test contains") {
        REQUIRE_FALSE(a.contains(DinoId::velociraptor));
        REQUIRE_FALSE(a.contains(DinoId::stegosaurus));
        REQUIRE_FALSE(a.contains(DinoId::tyrannosaurus));
        REQUIRE_FALSE(a.contains(DinoId::procompsognathus));
        REQUIRE_FALSE(a.contains(DinoId::triceratops));
        REQUIRE_FALSE(a.contains(DinoId::pachycephalosaurus));
        REQUIRE_FALSE(a.contains(DinoId::parasaurolophus));
        REQUIRE_FALSE(a.contains(DinoId::pteranodon));

        REQUIRE(b.contains(DinoId::velociraptor));
        REQUIRE_FALSE(b.contains(DinoId::stegosaurus));
        REQUIRE(b.contains(DinoId::tyrannosaurus));
        REQUIRE_FALSE(b.contains(DinoId::procompsognathus));
        REQUIRE_FALSE(b.contains(DinoId::triceratops));
        REQUIRE_FALSE(b.contains(DinoId::pachycephalosaurus));
        REQUIRE_FALSE(b.contains(DinoId::parasaurolophus));
        REQUIRE_FALSE(b.contains(DinoId::pteranodon));

        REQUIRE_FALSE(c.contains(DinoId::velociraptor));
        REQUIRE_FALSE(c.contains(DinoId::stegosaurus));
        REQUIRE(c.contains(DinoId::tyrannosaurus));
        REQUIRE(c.contains(DinoId::procompsognathus));
        REQUIRE_FALSE(c.contains(DinoId::triceratops));
        REQUIRE_FALSE(c.contains(DinoId::pachycephalosaurus));
        REQUIRE_FALSE(c.contains(DinoId::parasaurolophus));
        REQUIRE(c.contains(DinoId::pteranodon));
    }

    // SECTION("test size") {
    //     REQUIRE(a.size() == 0);
    //     REQUIRE(b.size() == 2);
    //     REQUIRE(c.size() == 3);
    // }

    // SECTION("test is_empty") {
    //     REQUIRE(a.is_empty());
    //     REQUIRE_FALSE(b.is_empty());
    //     REQUIRE_FALSE(c.is_empty());
    // }

    // SECTION("test remove") {
    //     REQUIRE(c.size() == 3);
    //     REQUIRE(c.contains(DinoId::procompsognathus));
    //     c.remove(DinoId::procompsognathus);
    //     REQUIRE(c.size() == 2);
    //     REQUIRE_FALSE(c.contains(DinoId::procompsognathus));
    //     REQUIRE(c.to_string() == "{tyrannosaurus, pteranodon}");
    //     REQUIRE(c.contains(DinoId::tyrannosaurus));
    //     c.remove(DinoId::tyrannosaurus);
    //     REQUIRE(c.size() == 1);
    //     REQUIRE_FALSE(c.contains(DinoId::tyrannosaurus));
    //     REQUIRE(c.to_string() == "{pteranodon}");
    //     REQUIRE(c.contains(DinoId::pteranodon));
    //     c.remove(DinoId::pteranodon);
    //     REQUIRE(c.is_empty());
    //     REQUIRE_FALSE(c.contains(DinoId::pteranodon));
    //     REQUIRE(c.to_string() == "{}");

    //     REQUIRE(b.size() == 2);
    //     REQUIRE(b.contains(DinoId::tyrannosaurus));
    //     b.remove(DinoId::tyrannosaurus);
    //     REQUIRE(b.size() == 1);
    //     REQUIRE_FALSE(b.contains(DinoId::tyrannosaurus));
    //     REQUIRE(b.to_string() == "{velociraptor}");
    //     REQUIRE(b.contains(DinoId::velociraptor));
    //     b.remove(DinoId::velociraptor);
    //     REQUIRE(b.is_empty());
    //     REQUIRE_FALSE(b.contains(DinoId::velociraptor));
    //     REQUIRE(b.to_string() == "{}");

    //     REQUIRE(a.is_empty());
    //     REQUIRE_FALSE(a.contains(DinoId::tyrannosaurus));
    //     a.remove(DinoId::tyrannosaurus);
    //     REQUIRE(a.is_empty());
    //     REQUIRE_FALSE(a.contains(DinoId::tyrannosaurus));
    //     REQUIRE(a.to_string() == "{}");
    //     REQUIRE_FALSE(a.contains(DinoId::pteranodon));
    //     a.remove(DinoId::pteranodon);
    //     REQUIRE(a.is_empty());
    //     REQUIRE_FALSE(a.contains(DinoId::pteranodon));
    //     REQUIRE(a.to_string() == "{}");
    // }

    // SECTION("test +") {
    //     REQUIRE((a + b).to_string()
    //         == "{velociraptor, tyrannosaurus}");
    //     REQUIRE((a + c).to_string()
    //         == "{tyrannosaurus, procompsognathus, pteranodon}");
    //     REQUIRE((b + c).to_string()
    //         == "{velociraptor, tyrannosaurus, procompsognathus, "
    //           "pteranodon}");
    //     REQUIRE((c + b).to_string()
    //         == "{velociraptor, tyrannosaurus, procompsognathus, "
    //           "pteranodon}");
    // }

    // SECTION("test *") {
    //     REQUIRE((a * b).to_string() == "{}");
    //     REQUIRE((a * c).to_string() == "{}");
    //     REQUIRE((b * c).to_string() == "{tyrannosaurus}");
    //     REQUIRE((c * b).to_string() == "{tyrannosaurus}");
    // }

    // SECTION("test -") {
    //     REQUIRE((a - b).to_string() == "{}");
    //     REQUIRE((b - a).to_string()
    //         == "{velociraptor, tyrannosaurus}");
    //     REQUIRE((a - c).to_string() == "{}");
    //     REQUIRE((c - a).to_string()
    //         == "{tyrannosaurus, procompsognathus, pteranodon}");
    //     REQUIRE((b - c).to_string() == "{velociraptor}");
    //     REQUIRE((c - b).to_string()
    //         == "{procompsognathus, pteranodon}");
    // }

    // SECTION("test !")
    // {
    //     REQUIRE((!a).to_string()
    //         == "{velociraptor, stegosaurus, tyrannosaurus, "
    //           "procompsognathus, triceratops, pachycephalosaurus, "
    //           "parasaurolophus, pteranodon}");
    //     REQUIRE((!b).to_string()
    //         == "{stegosaurus, procompsognathus, triceratops, "
    //           "pachycephalosaurus, parasaurolophus, pteranodon}");
    //     REQUIRE((!c).to_string()
    //         == "{velociraptor, stegosaurus, triceratops, "
    //           "pachycephalosaurus, parasaurolophus}");
    // }

    // SECTION("test ==") {
    //     DinoSet x;

    //     DinoSet y;
    //     y.add(DinoId::tyrannosaurus);
    //     y.add(DinoId::velociraptor);

    //     DinoSet z;
    //     z.add(DinoId::procompsognathus);
    //     z.add(DinoId::pteranodon);
    //     z.add(DinoId::tyrannosaurus);

    //     REQUIRE(a == a);
    //     REQUIRE(a == x);
    //     REQUIRE_FALSE(a == y);
    //     REQUIRE_FALSE(a == z);

    //     REQUIRE(b == b);
    //     REQUIRE_FALSE(b == x);
    //     REQUIRE(b == y);
    //     REQUIRE_FALSE(b == z);

    //     REQUIRE(c == c);
    //     REQUIRE_FALSE(c == x);
    //     REQUIRE_FALSE(c == y);
    //     REQUIRE(c == z);
    // }
}
