#pragma once

namespace godot::Math {

_FORCE_INLINE_ void decompose(Basis& p_basis, Vector3& p_scale) {
	p_scale = Vector3(1.0f, 1.0f, 1.0f);

	Vector3 x = p_basis.get_column(Vector3::AXIS_X);
	Vector3 y = p_basis.get_column(Vector3::AXIS_Y);
	Vector3 z = p_basis.get_column(Vector3::AXIS_Z);

	const Vector3 scale_squared(x.length_squared(), y.length_squared(), z.length_squared());

	if (p_scale == scale_squared) {
		return;
	}

	p_scale = Vector3(
		godot::Math::sqrt(scale_squared.x),
		godot::Math::sqrt(scale_squared.y),
		godot::Math::sqrt(scale_squared.z)
	);

	x /= p_scale.x;
	y /= p_scale.y;
	z /= p_scale.z;

	p_basis.set_column(Vector3::AXIS_X, x);
	p_basis.set_column(Vector3::AXIS_Y, y);
	p_basis.set_column(Vector3::AXIS_Z, z);
}

_FORCE_INLINE_ void decompose(Transform3D& p_transform, Vector3& p_scale) {
	decompose(p_transform.basis, p_scale);
}

_FORCE_INLINE_ void decompose(Basis& p_basis) {
	Vector3 scale;
	decompose(p_basis, scale);
}

_FORCE_INLINE_ void decompose(Transform3D& p_transform) {
	Vector3 scale;
	decompose(p_transform, scale);
}

_FORCE_INLINE_ Basis decomposed(Basis p_basis, Vector3& p_scale) {
	decompose(p_basis, p_scale);
	return p_basis;
}

_FORCE_INLINE_ Transform3D decomposed(Transform3D p_transform, Vector3& p_scale) {
	decompose(p_transform, p_scale);
	return p_transform;
}

_FORCE_INLINE_ Basis decomposed(Basis p_basis) {
	decompose(p_basis);
	return p_basis;
}

_FORCE_INLINE_ Transform3D decomposed(Transform3D p_transform) {
	decompose(p_transform);
	return p_transform;
}

} // namespace godot::Math
