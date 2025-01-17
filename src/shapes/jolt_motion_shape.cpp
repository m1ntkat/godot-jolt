#include "jolt_motion_shape.hpp"

namespace {

class JoltMotionConvexSupport final : public JPH::ConvexShape::Support {
public:
	JoltMotionConvexSupport(JPH::Vec3Arg p_motion, const JPH::ConvexShape::Support* p_inner_support)
		: motion(p_motion)
		, inner_support(p_inner_support) { }

	JPH::Vec3 GetSupport(JPH::Vec3Arg p_direction) const override {
		JPH::Vec3 support = inner_support->GetSupport(p_direction);

		if (p_direction.Dot(motion) > 0) {
			support += motion;
		}

		return support;
	}

	float GetConvexRadius() const override { return inner_support->GetConvexRadius(); }

private:
	JPH::Vec3 motion = JPH::Vec3::sZero();

	const JPH::ConvexShape::Support* inner_support = nullptr;
};

} // namespace

JPH::AABox JoltMotionShape::GetLocalBounds() const {
	JPH::AABox aabb = inner_shape.GetLocalBounds();
	JPH::AABox aabb_translated = aabb;
	aabb_translated.Translate(motion);
	aabb.Encapsulate(aabb_translated);

	return aabb;
}

const JPH::ConvexShape::Support* JoltMotionShape::GetSupportFunction(
	JPH::ConvexShape::ESupportMode p_mode,
	JPH::ConvexShape::SupportBuffer& p_buffer,
	JPH::Vec3Arg p_scale
) const {
	return new (&p_buffer) JoltMotionConvexSupport(
		motion,
		inner_shape.GetSupportFunction(p_mode, inner_support_buffer, p_scale)
	);
}
