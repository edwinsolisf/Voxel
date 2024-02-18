
add_library(stb STATIC)

target_sources(stb PUBLIC
                stb/stb_image.h
                stb/stb_image_implementation.cpp)

add_library(stm INTERFACE)

target_sources(stm PUBLIC
                stm/aligned_matrix.h
                stm/avx_math.h
                stm/complex.h
                stm/constants.h
                stm/debug.h
                stm/distribution.h
                stm/dynamic_matrix.h
                stm/dynamic_vector.h
                stm/function.h
                stm/math.h
                stm/matrix_transform.h
                stm/matrix.h
                stm/matrix2x2.h
                stm/quaternion.h
                stm/simplex_noise.h
                stm/utilities.h
                stm/vector.h
                stm/vector2.h
                stm/vector3.h
                stm/vector4.h)