#include "jolt_globals.hpp"

#include "shapes/jolt_empty_shape.hpp"
#include "shapes/jolt_override_user_data_shape.hpp"
#include "shapes/jolt_ray_shape.hpp"

void* jolt_alloc(size_t p_size) {
	return mi_malloc(p_size);
}

void jolt_free(void* p_mem) {
	mi_free(p_mem);
}

void* jolt_aligned_alloc(size_t p_size, size_t p_alignment) {
	return mi_malloc_aligned(p_size, p_alignment);
}

void jolt_aligned_free(void* p_mem) {
	mi_free(p_mem);
}

void jolt_trace(const char* p_format, ...) {
	// NOLINTNEXTLINE(cppcoreguidelines-init-variables)
	va_list args;
	va_start(args, p_format);
	char buffer[1024] = {'\0'};
	vsnprintf(buffer, sizeof(buffer), p_format, args);
	va_end(args);
	UtilityFunctions::print_verbose(buffer);
}

#ifdef JPH_ENABLE_ASSERTS

bool jolt_assert(const char* p_expr, const char* p_msg, const char* p_file, uint32_t p_line) {
	ERR_PRINT(vformat(
		"Assertion '%s' failed with message '%s' at '%s:%d'",
		p_expr,
		p_msg != nullptr ? p_msg : "",
		p_file,
		p_line
	));

	CRASH_NOW();

	return false;
}

#endif // JPH_ENABLE_ASSERTS

void jolt_initialize() {
	JPH::Allocate = &jolt_alloc;
	JPH::Free = &jolt_free;
	JPH::AlignedAllocate = &jolt_aligned_alloc;
	JPH::AlignedFree = &jolt_aligned_free;

	JPH::Trace = &jolt_trace;

#ifdef JPH_ENABLE_ASSERTS
	JPH::AssertFailed = jolt_assert;
#endif // JPH_ENABLE_ASSERTS

	JPH::Factory::sInstance = new JPH::Factory();

	JPH::RegisterTypes();

	JoltEmptyShape::register_type();
	JoltRayShape::register_type();
	JoltOverrideUserDataShape::register_type();
}

void jolt_deinitialize() {
	JPH::UnregisterTypes();

	delete_safely(JPH::Factory::sInstance);
}
