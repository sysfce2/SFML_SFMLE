#pragma once

#include <string>

#include <SFML/System/Vector2.hpp>

#include <SFMLE/System/Math.hpp>
namespace sfe
{
	struct Vector2
	{
		template <typename T>
		static std::string ToString(const sf::Vector2<T>& vec);

		// NOTE: These functions will be removed when SFML adds support for these functions natively

		template <typename T>
		static T Dot(const sf::Vector2<T>& vec1, const sf::Vector2<T>& vec2);

		template <typename T>
		static T Cross(const sf::Vector2<T>& vec1, const sf::Vector2<T>& vec2);

		// TODO: Add template metaprogramming to only enable when T is float/double
		template <typename T>
		static T Length(const sf::Vector2<T>& vec);

		template <typename T>
		static T LengthSquared(const sf::Vector2<T>& vec);

		template <typename T>
		static sf::Vector2<T> Normalized(const sf::Vector2<T>& vec);

		// Angle MUST be in Radians
		template <typename T>
		static sf::Vector2<T> Rotated(const sf::Vector2<T>& vec, const T angle);

		// TODO: Add template metaprogramming to only enable when T is float/double
		template <typename T>
		static T Distance(const sf::Vector2<T>& vecA, const sf::Vector2<T>& vecB);

		template <typename T>
		static sf::Vector2<T> SnapTo(const sf::Vector2<T>& vector, const sf::Vector2<T> step)
		{
			return sf::Vector2<T> { sfe::Math::Snapped(vector.x, step.x), sfe::Math::Snapped(vector.y, step.y) };
		}
	};
}

#include <SFMLE/System/Detail/Vector2.inl>