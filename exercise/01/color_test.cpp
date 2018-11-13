#include "stdafx.h"
#include "color.h"
#include <windows.h> // RGB

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft::VisualStudio::CppUnitTestFramework
{
    template<> static std::wstring ToString(const color& c)
    {
        std::wostringstream ss;
        ss << c.get_red() << L',' << c.get_green() << L',' << c.get_blue();
        return ss.str();
    }
}

namespace color_test
{
    TEST_CLASS(test1)
    {
    public:

        TEST_METHOD(test_default_value)
        {
            color c;
            Assert::AreEqual(color(0, 0, 0), c);
        }

        TEST_METHOD(test_construction)
        {
            color c(0.1, 0.2, 0.3);
            Assert::AreEqual(0.1, c.get_red());
            Assert::AreEqual(0.2, c.get_green());
            Assert::AreEqual(0.3, c.get_blue());
        }

        TEST_METHOD(test_construction_with_invalid_values)
        {
            color c(-0.1, 1.1, 1000);
            Assert::AreEqual(0., c.get_red());
            Assert::AreEqual(1., c.get_green());
            Assert::AreEqual(1., c.get_blue());
        }

        TEST_METHOD(test_assignment_invalid_values)
        {
            color c;
            c.set_red(128);
            Assert::AreEqual(1., c.get_red());
            c.set_green(-100);
            Assert::AreEqual(0., c.get_green());
            c.set_blue(1.01);
            Assert::AreEqual(1., c.get_blue());
        }

        TEST_METHOD(test_color_copy)
        {
            color a(12, 13, 14);
            color b(a);
            Assert::AreEqual(a, b);
        }

        TEST_METHOD(test_color_assign)
        {
            color a(12, 13, 14);
            color b, c;
            c = b = a;
            Assert::AreEqual(a, b);
            Assert::AreEqual(a, c);
        }

        TEST_METHOD(test_conversion_colorref)
        {
            Assert::AreEqual(RGB(255, 0, 0), color(1, 0, 0).get_color_ref());
            Assert::AreEqual(RGB(0, 255, 0), color(0, 1, 0).get_color_ref());
            Assert::AreEqual(RGB(0, 0, 255), color(0, 0, 1).get_color_ref());
            Assert::AreEqual(RGB(255, 255, 255), color(1, 1, 1).get_color_ref());
            Assert::AreEqual(RGB(127, 127, 127), color(0.5, 0.5, 0.5).get_color_ref());
        }

        TEST_METHOD(test_conversion_luminance)
        {
            Assert::AreEqual(0., color(0, 0, 0).get_luminance());
            Assert::AreEqual(0.2126, color(1, 0, 0).get_luminance());
            Assert::AreEqual(0.7152, color(0, 1, 0).get_luminance());
            Assert::AreEqual(0.0722, color(0, 0, 1).get_luminance());
            Assert::AreEqual(1., color(1, 1, 1).get_luminance());
        }

    };
}