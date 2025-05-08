//
// Created by Anastasija Fedorenko on 2025-05-08.
//
#include <gtest/gtest.h>
#include "../modules/StudentClass.h"  // adjust include path

TEST(StudentClassTest, CopyConstructor) {
    StudentClass original("Anastasija", "Fedorenko", {10.0, 9.0}, 8.0, 8.5);
    StudentClass copy(original);

    EXPECT_EQ(copy.getName(), original.getName());
    EXPECT_EQ(copy.getSurname(), original.getSurname());
    EXPECT_EQ(copy.getFinalGrade(), original.getFinalGrade());
}

TEST(StudentClassTest, CopyAssignment) {
    StudentClass original("Anastasija", "Fedorenko", {9.0, 8.0}, 7.0, 7.5);
    StudentClass assigned;
    assigned = original;

    EXPECT_EQ(assigned.getName(), original.getName());
    EXPECT_EQ(assigned.getSurname(), original.getSurname());
    EXPECT_EQ(assigned.getFinalGrade(), original.getFinalGrade());
}

TEST(StudentClassTest, MoveConstructor) {
    StudentClass original("Anastasija", "Fedorenko", {6.0, 6.5}, 7.0, 7.0);
    StudentClass moved(std::move(original));

    EXPECT_EQ(moved.getName(), "Anastasija");
    EXPECT_EQ(moved.getSurname(), "Fedorenko");
    EXPECT_EQ(moved.getFinalGrade(), 7.0);

    EXPECT_EQ(original.getName(), "");
    EXPECT_EQ(original.getSurname(), "");
}

TEST(StudentClassTest, MoveAssignment) {
    StudentClass original("Anastasija", "Fedorenko", {5.0, 5.5}, 6.0, 6.0);
    StudentClass moved;
    moved = std::move(original);

    EXPECT_EQ(moved.getName(), "Anastasija");
    EXPECT_EQ(moved.getSurname(), "Fedorenko");
    EXPECT_EQ(moved.getFinalGrade(), 6.0);

    EXPECT_EQ(original.getName(), "");
    EXPECT_EQ(original.getSurname(), "");
}
