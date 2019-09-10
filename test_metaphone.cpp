#include <gtest/gtest.h>
#include "metaphone.h"

TEST(ApplyTest, Basic1){
    Metaphone m{"abcde"};
    EXPECT_EQ(m.word, "ABCDE");
    EXPECT_EQ(m.pos, 0);
}

TEST(ApplyTest, Basic2){
    Metaphone m{"aabcdee"};
    EXPECT_EQ(m.word, "ABCDE");
}

TEST(ApplyTest, Basic3){
    Metaphone m{"abcccde"};
    EXPECT_EQ(m.word, "ABCCCDE");
}

TEST(ApplyTest, Peek1){
    Metaphone m{"abcde"};
    EXPECT_EQ(m.peek(), 'A');
}

TEST(ApplyTest, Peek2){
    Metaphone m{"abcde"};
    EXPECT_EQ(m.peek(2), 'C');
}

TEST(ApplyTest, Peek3){
    Metaphone m{"abcde"};
    EXPECT_EQ(m.peek(6), '\0');
}

TEST(ApplyTest, Peek4){
    Metaphone m{"abcde"};
    EXPECT_EQ(m.peek(-1), '\0');
}

TEST(ApplyTest, MoveAhead1){
    Metaphone m{"abcde"};
    EXPECT_EQ(m.peek(), 'A');
    m.moveAhead();
    EXPECT_EQ(m.peek(), 'B');
}

TEST(ApplyTest, MoveAhead2){
    Metaphone m{"abcde"};
    EXPECT_EQ(m.peek(), 'A');
    m.moveAhead(2);
    EXPECT_EQ(m.peek(), 'C');
}

TEST(ApplyTest, MoveAhead3){
    Metaphone m{"abcde"};
    EXPECT_EQ(m.peek(), 'A');
    m.moveAhead(2);
    EXPECT_EQ(m.peek(), 'C');
}

TEST(ApplyTest, MoveAhead4){
    Metaphone m{"abcde"};
    EXPECT_EQ(m.peek(), 'A');
    m.moveAhead(20);
    EXPECT_EQ(m.peek(), '\0');
}

TEST(ApplyTest, MoveAhead5){
    Metaphone m{"abcde"};
    EXPECT_EQ(m.peek(), 'A');
    m.moveAhead(20);
    EXPECT_EQ(m.peek(-1), 'E');
}

TEST(ApplyTest, EqualToAny1){
    Metaphone m{"abcde"};
    EXPECT_TRUE(m.EqualToAny('Y', "WXYZ"));
}

TEST(ApplyTest, EqualToAny2){
    Metaphone m{"abcde"};
    EXPECT_FALSE(m.EqualToAny('Q', "WXYZ"));
}

TEST(ApplyTest, IsVowel1){
    Metaphone m{"abcde"};
    EXPECT_TRUE(m.isVowel('I'));
}

TEST(ApplyTest, IsVowel2){
    Metaphone m{"abcde"};
    EXPECT_FALSE(m.isVowel('P'));
}