#include <gtest/gtest.h>
#include "StringUtils.h"

TEST(StringUtilsTest, SliceTest){
    std::string Base = "Hello";

    EXPECT_EQ(StringUtils::Slice(Base,1), "ello");
}

TEST(StringUtilsTest, Capitalize){
    std::string Base = "hello";

    EXPECT_EQ(StringUtils::Capitalize(Base), "Hello");
}

TEST(StringUtilsTest, Upper){
    std::string Base = "hello";

    EXPECT_EQ(StringUtils::Upper(Base), "HELLO");
}

TEST(StringUtilsTest, Lower){
    std::string Base = "HELLO";

    EXPECT_EQ(StringUtils::Lower(Base), "hello");
}

TEST(StringUtilsTest, LStrip){
    std::string Base = "     hello";
    std::string Base1 = "   Pineapples are good";

    EXPECT_EQ(StringUtils::LStrip(Base), "hello");
    EXPECT_EQ(StringUtils::LStrip(Base1), "Pineapples are good");
}

TEST(StringUtilsTest, RStrip){
    std::string Base = "hello     ";
    std::string Base1 = "Pineapples are good   ";

    EXPECT_EQ(StringUtils::RStrip(Base), "hello");
    EXPECT_EQ(StringUtils::Strip(Base1), "Pineapples are good");
}

TEST(StringUtilsTest, Strip){
    std::string Base = "     hello     ";
    std::string Base1 = "   Pineapples are good   ";


    EXPECT_EQ(StringUtils::Strip(Base), "hello");
    EXPECT_EQ(StringUtils::Strip(Base1), "Pineapples are good");

}

/*TEST(StringUtilsTest, Center){
    std::string Base = "Hello";
    
    EXPECT_EQ(StringUtils::Center(), Base);
}

TEST(StringUtilsTest, LJust){
    std::string Base = "Hello";
    
    EXPECT_EQ(StringUtils::LJust(), Base); 
}

TEST(StringUtilsTest, RJust){
    std::string Base = "Hello";
    
    EXPECT_EQ(StringUtils::RJust(),Base); 
}

TEST(StringUtilsTest, Replace){
    std::string Base = "Hello";
    
    EXPECT_EQ(StringUtils::Replace(),Base);   
}

TEST(StringUtilsTest, Split){
    std::string Base = "Hello";
    
    EXPECT_EQ(StringUtils::Split(), Base);    
}

TEST(StringUtilsTest, Join){
    std::string Base = "Hello";
    
    EXPECT_EQ(StringUtils::Join(), Base);    
}

TEST(StringUtilsTest, ExpandTabs){
    std::string Base = "Hello";
    
    EXPECT_EQ(StringUtils::ExpandTabs(), Base);    
}

TEST(StringUtilsTest, EditDistance){
    std::string Base = "Hello";
    
    EXPECT_EQ(StringUtils::EditDistance(), Base);    
}*/
