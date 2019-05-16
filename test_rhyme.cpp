#include <gtest/gtest.h>
#include "rhyme.h"

TEST(ApplyTest, Basic1){
    Metaphone m{"abcde"};
    EXPECT_EQ(m.word, "abcde");
    EXPECT_EQ(m.pos, 0)
}

TEST(ApplyTest, Basic2){
    Metaphone m{"aabcdee"};
    EXPECT_EQ(m.word, "abcde");
}

TEST(ApplyTest, Basic3){
    Metaphone m{"abcccde"};
    EXPECT_EQ(m.word, "abccde");
}

TEST(ApplyTest, Peek1){
    Metaphone m{"abcde"};
    EXPECT_EQ(m.peek(), 'a');
}

TEST(ApplyTest, Peek2){
    Metaphone m{"abcde"};
    EXPECT_EQ(m.peek(2), 'c');
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
    EXPECT_EQ(m.peek(), 'a');
    m.moveAhead();
    EXPECT_EQ(m.peek(), 'b');
}

TEST(ApplyTest, MoveAhead2){
    Metaphone m{"abcde"};
    EXPECT_EQ(m.peek(), 'a');
    m.moveAhead(2);
    EXPECT_EQ(m.peek(), 'c');
}

TEST(ApplyTest, MoveAhead3){
    Metaphone m{"abcde"};
    EXPECT_EQ(m.peek(), 'a');
    m.moveAhead(2);
    EXPECT_EQ(m.peek(), 'c');
}

TEST(ApplyTest, MoveAhead4){
    Metaphone m{"abcde"};
    EXPECT_EQ(m.peek(), 'a');
    m.moveAhead(20);
    EXPECT_EQ(m.peek(), '\0');
}

TEST(ApplyTest, MoveAhead5){
    Metaphone m{"abcde"};
    EXPECT_EQ(m.peek(), 'a');
    m.moveAhead(20);
    EXPECT_EQ(m.peek(-1), 'e');
}

TEST(ApplyTest, EqualToAny1){
    Metaphone m{"abcde"};
    EXPECT_TRUE(m.EqualToAny('y', "wxyz"));
}

TEST(ApplyTest, EqualToAny2){
    Metaphone m{"abcde"};
    EXPECT_FALSE(m.EqualToAny('q', "wxyz"));
}

TEST(ApplyTest, IsVowel1){
    Metaphone m{"abcde"};
    EXPECT_TRUE(m.isVowel('i'));
}

TEST(ApplyTest, IsVowel2){
    Metaphone m{"abcde"};
    EXPECT_FALSE(m.isVowel('p'));
}