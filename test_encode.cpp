#include <gtest/gtest.h>
#include "rhyme.h"

TEST(ApplyTest, SilentBeginings1){
    Metaphone m{"wren"};
    EXPECT_EQ(m.encode(), "RN");
}

TEST(ApplyTest, SilentBeginings2){
    Metaphone m{"aero"};
    EXPECT_EQ(m.encode(), "er");
}

TEST(ApplyTest, SilentBeginings3){
    Metaphone m{"knee"};
    EXPECT_EQ(m.encode(), "N");
}

TEST(ApplyTest, SilentBeginings4){
    Metaphone m{"gnat"};
    EXPECT_EQ(m.encode(), "NT");
}

TEST(ApplyTest, SilentBeginings5){
    Metaphone m{"pneumonia"};
    EXPECT_EQ(m.encode(), "NMN");
}

TEST(ApplyTest, MBEnding){
    Metaphone m{"bomb"};
    EXPECT_EQ(m.encode(), "BM");
}

TEST(ApplyTest, CRules1){
    Metaphone m{"social"};
    EXPECT_EQ(m.encode(), "SXL");
}

TEST(ApplyTest, CRules2){
    Metaphone m{"char"};
    EXPECT_EQ(m.encode(), "XR");
}

TEST(ApplyTest, CRules3){
    Metaphone m{"mischief"};
    EXPECT_EQ(m.encode(), "MKF");
}

TEST(ApplyTest, CRules4){
    Metaphone m{"acid"};
    EXPECT_EQ(m.encode(), "AST");
}

TEST(ApplyTest, CRules5){
    Metaphone m{"voice"};
    EXPECT_EQ(m.encode(), "FS");
}

TEST(ApplyTest, CRules6){
    Metaphone m{"cycle"};
    EXPECT_EQ(m.encode(), "SKL");
}

TEST(ApplyTest, CRules7){
    Metaphone m{"tract"};
    EXPECT_EQ(m.encode(), "TRKT");
}

TEST(ApplyTest, DRules1){
    Metaphone m{"dodger"};
    EXPECT_EQ(m.encode(), "TJR");
}

TEST(ApplyTest, DRules2){
    Metaphone m{"edgy"};
    EXPECT_EQ(m.encode(), "EJ");
}

TEST(ApplyTest, DRules3){
    Metaphone m{"budging"};
    EXPECT_EQ(m.encode(), "BJNK");
}

TEST(ApplyTest, DRules4){
    Metaphone m{"red"};
    EXPECT_EQ(m.encode(), "RT");
}

TEST(ApplyTest, GRules1){
    Metaphone m{"aught"};
    EXPECT_EQ(m.encode(), "AFT");
}

TEST(ApplyTest, GRules2){
    Metaphone m{"high"};
    EXPECT_EQ(m.encode(), "HF");
}

TEST(ApplyTest, GRules3){
    Metaphone m{"yoghurt"};
    EXPECT_EQ(m.encode(), "YFRT");
}

TEST(ApplyTest, GRules4){
    Metaphone m{"feign"};
    EXPECT_EQ(m.encode(), "FN");
}

TEST(ApplyTest, GRules5){
    Metaphone m{"signed"};
    EXPECT_EQ(m.encode(), "SNT");
}

TEST(ApplyTest, GRules6){
    Metaphone m{"vigil"};
    EXPECT_EQ(m.encode(), "FJL");
}

TEST(ApplyTest, GRules7){
    Metaphone m{"beget"};
    EXPECT_EQ(m.encode(), "BJT");
}

TEST(ApplyTest, GRules8){
    Metaphone m{"gym"};
    EXPECT_EQ(m.encode(), "JM");
}

TEST(ApplyTest, GRules9){
    Metaphone m{"soggy"};
    EXPECT_EQ(m.encode(), "SK");
}

TEST(ApplyTest, GRules10){
    Metaphone m{"egg"};
    EXPECT_EQ(m.encode(), "EK");
}

TEST(ApplyTest, GRules11){
    Metaphone m{"big"};
    EXPECT_EQ(m.encode(), "BK");
}

TEST(ApplyTest, HRules1){
    Metaphone m{"homes"};
    EXPECT_EQ(m.encode(), "HMS");
}

TEST(ApplyTest, HRules2){
    Metaphone m{"ohmes"};
    EXPECT_EQ(m.encode(), "OMS");
}

TEST(ApplyTest, CKRule){
    Metaphone m{"dock"};
    EXPECT_EQ(m.encode(), "TK");
}

TEST(ApplyTest, PHRule){
    Metaphone m{"phase"};
    EXPECT_EQ(m.encode(), "FS");
}

TEST(ApplyTest, QRule1){
    Metaphone m{"queue"};
    EXPECT_EQ(m.encode(), "K");
}

TEST(ApplyTest, QRule2){
    Metaphone m{"equal"};
    EXPECT_EQ(m.encode(), "EKL");
}

TEST(ApplyTest, SRule1){
    Metaphone m{"shin"};
    EXPECT_EQ(m.encode(), "XN");
}

TEST(ApplyTest, SRule2){
    Metaphone m{"torsion"};
    EXPECT_EQ(m.encode(), "TRXN");
}

TEST(ApplyTest, SRule3){
    Metaphone m{"persian"};
    EXPECT_EQ(m.encode(), "PRXN");
}

TEST(ApplyTest, TRule1){
    Metaphone m{"tiara"};
    EXPECT_EQ(m.encode(), "XR");
}

TEST(ApplyTest, TRule2){
    Metaphone m{"ratio"};
    EXPECT_EQ(m.encode(), "RX");
}

TEST(ApplyTest, THRule){
    Metaphone m{"bath"};
    EXPECT_EQ(m.encode(), "B0");
}

TEST(ApplyTest, TCHRule){
    Metaphone m{"latch"};
    EXPECT_EQ(m.encode(), "LX");
}

TEST(ApplyTest, VRule){
    Metaphone m{"vegie"};
    EXPECT_EQ(m.encode(), "FJ");
}

TEST(ApplyTest, WRule1){
    Metaphone m{"whale"};
    EXPECT_EQ(m.encode(), "WL");
}

TEST(ApplyTest, WRule2){
    Metaphone m{"awhile"};
    EXPECT_EQ(m.encode(), "AHL");
}

TEST(ApplyTest, WRule3){
    Metaphone m{"wrap"};
    EXPECT_EQ(m.encode(), "RP");
}

TEST(ApplyTest, WRule4){
    Metaphone m{"fowl"};
    EXPECT_EQ(m.encode(), "FL");
}

TEST(ApplyTest, XRule1){
    Metaphone m{"xenial"};
    EXPECT_EQ(m.encode(), "SNL");
}

TEST(ApplyTest, XRule2){
    Metaphone m{"fixed"};
    EXPECT_EQ(m.encode(), "FKST");
}

TEST(ApplyTest, YRule1){
    Metaphone m{"snowy"};
    EXPECT_EQ(m.encode(), "SN");
}

TEST(ApplyTest, YRule2){
    Metaphone m{"yaw"};
    EXPECT_EQ(m.encode(), "Y");
}

TEST(ApplyTest, ZRule){
    Metaphone m{"pizza"};
    EXPECT_EQ(m.encode(), "PS");
}