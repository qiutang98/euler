#include "CppUnitTest.h"
#include "../euler/euler/euler.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace euler;

namespace vec
{
	TEST_CLASS(vec2)
	{
	public:
		TEST_METHOD(vec2_operator)
		{
			vec2f a(1.0f, 3.0f);
			vec2f b(6.0f, 2.0f);

			a *= 2.0f;

			Assert::IsTrue(a == vec2f(2.0f, 6.0f));
			Assert::IsTrue(a + b == vec2f(8.0f, 8.0f));

			b /= 0.1f;
			Assert::IsTrue(b == vec2f(60.0f, 20.0f));
			Assert::IsTrue(b - a == vec2f(58.0f, 14.0f));
			Assert::IsTrue(-b == -vec2f(60.0f, 20.0f));

			Assert::IsTrue(b[0] == 60.0f && b[1] == 20.0f);
			Assert::IsTrue(2.0f * b == vec2f(120.0f, 40.0f));

			a = b;
			Assert::IsTrue(a == b);
		}

		TEST_METHOD(vec2_math)
		{
			vec2f a(3.0f, 4.0f);
			vec2f b(5.0f, 1.0f);

			Assert::IsTrue(max(a) == 4.0f);
			Assert::IsTrue(min(b) == 1.0f);

			vec2f aa(-3.0f, -4.0f);
			vec2d vb(-14.0, 0.0);

			Assert::IsTrue(abs(aa).getX() == 3.0f && abs(aa).getY() == 4.0f);
			Assert::IsTrue(abs(vb).getX() == 14.0 && abs(vb).getY() == 0.0);

			Assert::IsTrue(normalize(a) == vec2f(0.6f, 0.8f));
		}
	};

	TEST_CLASS(vec3)
	{
	public:
		TEST_METHOD(vec3_operator)
		{
			vec3f a(1.0f, 3.0f, -5.0f);
			vec3f b(6.0f, 2.0f, -1.0f);

			a *= 2.0f;

			Assert::IsTrue(a == vec3f(2.0f, 6.0f, -10.0f));
			Assert::IsTrue(a + b == vec3f(8.0f, 8.0f, -11.0f));

			b /= 0.1f;
			Assert::IsTrue(b == vec3f(60.0f, 20.0f, -10.0f));
			Assert::IsTrue(b - a == vec3f(58.0f, 14.0f, 0.0f));
			Assert::IsTrue(-b == -vec3f(60.0f, 20.0f, -10.0f));

			Assert::IsTrue(b[0] == 60.0f && b[1] == 20.0f && b[2] == -10.0f);
			Assert::IsTrue(2.0f * b == vec3f(120.0f, 40.0f, -20.0f));

			a = b;
			Assert::IsTrue(a == b);
		}

		TEST_METHOD(vec3_math)
		{
			vec3f a(3.0f, 4.0f, 5.0f);
			vec3f b(5.0f, 1.0f, -9.0f);

			Assert::IsTrue(max(a) ==  5.0f);
			Assert::IsTrue(min(b) == -9.0f);

			vec3f aa(-3.0f, -4.0f, -5.0f);
			vec3d vb(-14.0, 0.0, 6.0);

			Assert::IsTrue(abs(aa).getX() == 3.0f && abs(aa).getY() == 4.0f && abs(aa).getZ() == 5.0f);
			Assert::IsTrue(abs(vb).getX() == 14.0 && abs(vb).getY() == 0.0 && abs(vb).getZ() == 6.0);

			Assert::IsTrue(normalize(vec3f(0.0f, 4.0f, 3.0f)) == vec3f(0.0f, 0.8f, 0.6f));
		}
	};

	TEST_CLASS(vec4)
	{
	public:
		TEST_METHOD(vec4_operator)
		{
			vec4f a(1.0f, 3.0f, -5.0f, 6.0f);
			vec4f b(6.0f, 2.0f, -1.0f, -6.0f);

			a *= 2.0f;

			Assert::IsTrue(a == vec4f(2.0f, 6.0f, -10.0f, 12.0f));
			Assert::IsTrue(a + b == vec4f(8.0f, 8.0f, -11.0f, 6.0f));

			b /= 0.1f;
			Assert::IsTrue(b == vec4f(60.0f, 20.0f, -10.0f, -60.0f));
			Assert::IsTrue(b - a == vec4f(58.0f, 14.0f, 0.0f, -72.0f));
			Assert::IsTrue(-b == -vec4f(60.0f, 20.0f, -10.0f, -60.0f));

			Assert::IsTrue(b[0] == 60.0f && b[1] == 20.0f && b[2] == -10.0f && b[3] == -60.0f);
			Assert::IsTrue(2.0f * b == vec4f(120.0f, 40.0f, -20.0f, -120.0f));

			a = b;
			Assert::IsTrue(a == b);
		}

		TEST_METHOD(vec4_math)
		{
			vec4f a(3.0f, 4.0f, 5.0f, 6.0f);
			vec4f b(5.0f, 1.0f, -9.0f, -17.0f);

			Assert::IsTrue(max(a) == 6.0f);
			Assert::IsTrue(min(b) == -17.0f);

			vec4f aa(-3.0f, -4.0f, -5.0f, -6.0f);
			vec4d vb(-14.0, 0.0, 6.0, -7.0);

			Assert::IsTrue(abs(aa).getX() == 3.0f && abs(aa).getY() == 4.0f && abs(aa).getZ() == 5.0f && abs(aa).getW() == 6.0f);
			Assert::IsTrue(abs(vb).getX() == 14.0 && abs(vb).getY() == 0.0 && abs(vb).getZ() == 6.0 && abs(vb).getW() == 7.0);

			Assert::IsTrue(normalize(vec4f(0.0f, 0.0f, 4.0f, 3.0f)) == vec4f(0.0f, 0.0f, 0.8f, 0.6f));
		}
	};

	TEST_CLASS(vec_compute_misc)
	{
	public:
		TEST_METHOD(simple_compute)
		{

		}
	};
}
