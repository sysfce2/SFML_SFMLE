#pragma once

#include <type_traits>
#include <cmath>
#include <numbers>

namespace sfe
{
	struct Math
	{
		template <typename T>
		static T Snapped(T value, T step)
		{
			static_assert(std::is_floating_point_v<T>, "T must be floating point.");

			if (step != static_cast<T>(0))
			{
				value = std::floor(value / step + static_cast<T>(0.5)) * step;
			}

			return value;
		}

		template <typename T>
		static T Lerp(T from, T to, T weight)
		{
			static_assert(std::is_floating_point_v<T>, "T must be floating point.");
			return from + (to - from) * weight;
		}

		template <typename T>
		static constexpr T RadToDeg(const T radians)
		{
			constexpr auto radToDeg = static_cast<T>(180) / std::numbers::pi_v<T>;
			return radToDeg * radians;
		}

		template <typename T>
		static constexpr T DegToRad(const T degrees)
		{
			constexpr auto degToRad = std::numbers::pi_v<T> / static_cast<T>(180);
			return degToRad * degrees;
		}
	};
}