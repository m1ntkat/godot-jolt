#pragma once

#include "objects/jolt_collision_object_3d.hpp"
#include "objects/jolt_physics_direct_body_state_3d.hpp"

class JoltArea3D;

class JoltBody3D final : public JoltCollisionObject3D {
public:
	using DampMode = PhysicsServer3D::BodyDampMode;

	struct Contact {
		float depth = 0.0f;

		int32_t shape_index = 0;

		int32_t collider_shape_index = 0;

		ObjectID collider_id;

		RID collider_rid;

		Vector3 normal;

		Vector3 position;

		Vector3 collider_position;

		Vector3 collider_velocity;

		Vector3 impulse;
	};

	~JoltBody3D() override;

	Variant get_state(PhysicsServer3D::BodyState p_state);

	void set_state(PhysicsServer3D::BodyState p_state, const Variant& p_value);

	Variant get_param(PhysicsServer3D::BodyParameter p_param) const;

	void set_param(PhysicsServer3D::BodyParameter p_param, const Variant& p_value);

	JPH::BroadPhaseLayer get_broad_phase_layer() const override;

	bool has_state_sync_callback() const { return body_state_callback.is_valid(); }

	void set_state_sync_callback(const Callable& p_callback) { body_state_callback = p_callback; }

	bool has_force_integration_callback() const { return force_integration_callback.is_valid(); }

	void set_force_integration_callback(const Callable& p_callback, const Variant& p_userdata) {
		force_integration_callback = p_callback;
		force_integration_userdata = p_userdata;
	}

	bool is_sleeping(bool p_lock = true) const;

	void set_is_sleeping(bool p_enabled, bool p_lock = true);

	void put_to_sleep(bool p_lock = true) { set_is_sleeping(true, p_lock); }

	void wake_up(bool p_lock = true) { set_is_sleeping(false, p_lock); }

	bool can_sleep(bool p_lock = true) const;

	void set_can_sleep(bool p_enabled, bool p_lock = true);

	Basis get_principal_inertia_axes(bool p_lock = true) const;

	Vector3 get_inverse_inertia(bool p_lock = true) const;

	Basis get_inverse_inertia_tensor(bool p_lock = true) const;

	void set_linear_velocity(const Vector3& p_velocity, bool p_lock = true);

	void set_angular_velocity(const Vector3& p_velocity, bool p_lock = true);

	void set_axis_velocity(const Vector3& p_axis_velocity, bool p_lock = true);

	bool has_custom_center_of_mass() const override { return custom_center_of_mass; }

	Vector3 get_center_of_mass_custom() const override { return center_of_mass_custom; }

	void set_center_of_mass_custom(const Vector3& p_center_of_mass, bool p_lock = true);

	int32_t get_max_contacts_reported() const { return contacts.size(); }

	void set_max_contacts_reported(int32_t p_count) { contacts.resize(p_count); }

	int32_t get_contact_count() const { return contact_count; }

	const Contact& get_contact(int32_t p_index) { return contacts[p_index]; }

	bool generates_contacts() const override { return contacts.size() > 0; }

	void add_contact(
		const JoltBody3D* p_collider,
		float p_depth,
		int32_t p_shape_index,
		int32_t p_collider_shape_index,
		const Vector3& p_normal,
		const Vector3& p_position,
		const Vector3& p_collider_position,
		const Vector3& p_collider_velocity,
		const Vector3& p_impulse
	);

	void reset_mass_properties(bool p_lock = true);

	void apply_force(const Vector3& p_force, const Vector3& p_position, bool p_lock = true);

	void apply_central_force(const Vector3& p_force, bool p_lock = true);

	void apply_impulse(const Vector3& p_impulse, const Vector3& p_position, bool p_lock = true);

	void apply_central_impulse(const Vector3& p_impulse, bool p_lock = true);

	void apply_torque(const Vector3& p_torque, bool p_lock = true);

	void apply_torque_impulse(const Vector3& p_impulse, bool p_lock = true);

	void add_constant_central_force(const Vector3& p_force, bool p_lock = true);

	void add_constant_force(const Vector3& p_force, const Vector3& p_position, bool p_lock = true);

	void add_constant_torque(const Vector3& p_torque, bool p_lock = true);

	Vector3 get_constant_force() const;

	void set_constant_force(const Vector3& p_force, bool p_lock = true);

	Vector3 get_constant_torque() const;

	void set_constant_torque(const Vector3& p_torque, bool p_lock = true);

	void add_collision_exception(const RID& p_excepted_body, bool p_lock = true);

	void remove_collision_exception(const RID& p_excepted_body, bool p_lock = true);

	bool has_collision_exception(const RID& p_excepted_body, bool p_lock = true) const;

	TypedArray<RID> get_collision_exceptions(bool p_lock = true) const;

	void add_area(JoltArea3D* p_area, bool p_lock = true);

	void remove_area(JoltArea3D* p_area, bool p_lock = true);

	void integrate_forces(float p_step, bool p_lock = true);

	void call_queries();

	void pre_step(float p_step) override;

	JoltPhysicsDirectBodyState3D* get_direct_state();

	PhysicsServer3D::BodyMode get_mode() const { return mode; }

	void set_mode(PhysicsServer3D::BodyMode p_mode, bool p_lock = true);

	bool is_static() const { return mode == PhysicsServer3D::BODY_MODE_STATIC; }

	bool is_kinematic() const { return mode == PhysicsServer3D::BODY_MODE_KINEMATIC; }

	bool is_rigid_free() const { return mode == PhysicsServer3D::BODY_MODE_RIGID; }

	bool is_rigid_linear() const { return mode == PhysicsServer3D::BODY_MODE_RIGID_LINEAR; }

	bool is_rigid() const { return is_rigid_free() || is_rigid_linear(); }

	bool is_ccd_enabled(bool p_lock = true) const;

	void set_ccd_enabled(bool p_enabled, bool p_lock = true);

	float get_mass() const { return mass; }

	void set_mass(float p_mass, bool p_lock = true);

	Vector3 get_inertia() const { return inertia; }

	void set_inertia(const Vector3& p_inertia, bool p_lock = true);

	float get_bounce(bool p_lock = true) const;

	void set_bounce(float p_bounce, bool p_lock = true);

	float get_friction(bool p_lock = true) const;

	void set_friction(float p_friction, bool p_lock = true);

	float get_gravity_scale(bool p_lock = true) const;

	void set_gravity_scale(float p_scale, bool p_lock = true);

	Vector3 get_gravity() const { return gravity; }

	float get_linear_damp() const { return linear_damp; }

	void set_linear_damp(float p_damp, bool p_lock = true);

	float get_angular_damp() const { return angular_damp; }

	void set_angular_damp(float p_damp, bool p_lock = true);

	float get_total_linear_damp(bool p_lock = true) const;

	float get_total_angular_damp(bool p_lock = true) const;

	float get_collision_priority() const { return collision_priority; }

	void set_collision_priority(float p_priority) { collision_priority = p_priority; }

	DampMode get_linear_damp_mode() const { return linear_damp_mode; }

	void set_linear_damp_mode(DampMode p_mode) { linear_damp_mode = p_mode; }

	DampMode get_angular_damp_mode() const { return angular_damp_mode; }

	void set_angular_damp_mode(DampMode p_mode) { angular_damp_mode = p_mode; }

	bool is_axis_locked(PhysicsServer3D::BodyAxis p_axis) const;

	void set_axis_lock(PhysicsServer3D::BodyAxis p_axis, bool p_lock_axis, bool p_lock = true);

	bool are_axes_locked() const { return locked_axes != 0; }

private:
	JPH::EMotionType get_motion_type() const override;

	void create_in_space() override;

	JPH::MassProperties calculate_mass_properties(const JPH::Shape& p_shape) const;

	JPH::MassProperties calculate_mass_properties() const;

	void update_mass_properties(bool p_lock = true);

	void update_damp(bool p_lock = true);

	void update_axes_constraint(bool p_lock = true);

	void destroy_axes_constraint();

	void mode_changed(bool p_lock = true);

	void shapes_built(bool p_lock) override;

	void space_changing(bool p_lock = true) override;

	void space_changed(bool p_lock = true) override;

	void areas_changed(bool p_lock = true);

	void transform_changed(bool p_lock = true) override;

	void motion_changed(bool p_lock = true);

	void axis_lock_changed(bool p_lock = true);

	LocalVector<Contact> contacts;

	LocalVector<JoltArea3D*> areas;

	Variant force_integration_userdata;

	Vector3 inertia;

	Vector3 center_of_mass_custom;

	Vector3 constant_force;

	Vector3 constant_torque;

	Vector3 gravity;

	Callable body_state_callback;

	Callable force_integration_callback;

	JoltPhysicsDirectBodyState3D* direct_state = nullptr;

	JPH::Ref<JPH::Constraint> axes_constraint;

	PhysicsServer3D::BodyMode mode = PhysicsServer3D::BODY_MODE_RIGID;

	DampMode linear_damp_mode = PhysicsServer3D::BODY_DAMP_MODE_COMBINE;

	DampMode angular_damp_mode = PhysicsServer3D::BODY_DAMP_MODE_COMBINE;

	float mass = 1.0f;

	float linear_damp = 0.0f;

	float angular_damp = 0.0f;

	float collision_priority = 1.0f;

	int32_t contact_count = 0;

	uint32_t locked_axes = 0;

	bool custom_center_of_mass = false;
};
