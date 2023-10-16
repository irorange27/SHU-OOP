// Unit tests using Google Test
#include <gtest/gtest.h>

// Test fixture for String class
class StringTest : public ::testing::Test {
protected:
    StringTest() {
        // Initialization code for each test case
    }

    ~StringTest() override {
        // Clean-up code for each test case
    }

    void SetUp() override {
        // Run before each test case
    }

    void TearDown() override {
        // Run after each test case
    }

    // Helper functions for tests
    void assertStringEquals(const String& str, const char* expected) {
        std::stringstream ss;
        ss << expected;
        testing::internal::CaptureStdout();
        str.show();
        std::string output = testing::internal::GetCapturedStdout();
        ASSERT_EQ(output, ss.str());
    }
};

// Test cases
TEST_F(StringTest, Constructor) {
    String str("Hello");
    assertStringEquals(str, "Hello");
}

TEST_F(StringTest, CopyConstructor) {
    String str1("Hello");
    String str2(str1);
    assertStringEquals(str2, "Hello");
}

TEST_F(StringTest, AssignmentOperator) {
    String str1("Hello");
    String str2("World");
    str2 = str1;
    assertStringEquals(str2, "Hello");
}

TEST_F(StringTest, Destructor) {
    {
        String str("Hello");
    }
    // Destructor should be called here
}

// Run all the tests
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}