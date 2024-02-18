
add_library(Engine)

target_sources(Engine PRIVATE
                Application/Application.cpp
                Renderer/Layer.cpp
                Renderer/Mesh.cpp
                Renderer/PerspectiveCamera.cpp
                Renderer/Renderer.cpp
                Renderer/Vertex.cpp
                Renderer/OpenGL/OpenGLCallback.cpp
                Renderer/OpenGL/OpenGLIndexBuffer.cpp
                Renderer/OpenGL/OpenGLShader.cpp
                Renderer/OpenGL/OpenGLTexture.cpp
                Renderer/OpenGL/OpenGLVertexArray.cpp
                Renderer/OpenGL/OpenGLVertexBuffer.cpp
                Renderer/OpenGL/OpenGLWindow.cpp
                Utilities/FileSystem.cpp
                Utilities/Logging.cpp
                Widgets/Widget.cpp)

if (OPENGL_ENGINE)
    target_link_libraries(Engine PUBLIC stb stm OpenGL::GL glfw GLEW::GLEW)
    target_compile_definitions(Engine PUBLIC OPENGL_ENGINE)
endif()

set(DEBUG_DEFINITIONS $<IF:$<CONFIG:Debug>,DEBUG,>)
target_compile_definitions(Engine PUBLIC ${DEBUG_DEFINITIONS})

target_include_directories(Engine PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_features(Engine PUBLIC cxx_std_17)

add_executable(Voxel)

target_sources(Voxel PUBLIC
                main.cpp
                Game/Chunk.cpp
                Game/Cube.cpp
                Game/GameLayer.cpp
                Game/InterfaceLayer.cpp
                Game/Player.cpp
                Game/Voxel.cpp
                Game/VoxelRenderer.cpp
                Game/World.cpp)

target_sources(Voxel PUBLIC
                Game/Block.h
                Game/Chunk.h
                Game/Cube.h
                Game/GameLayer.h
                Game/InterfaceLayer.h
                Game/Player.h
                Game/Voxel.h
                Game/VoxelRenderer.h
                Game/World.h)

target_sources(Voxel PRIVATE
                ${CMAKE_SOURCE_DIR}/Voxel.rc)

target_link_libraries(Voxel PRIVATE Engine)
set_target_properties(Voxel PROPERTIES
                        WIN32_EXECUTABLE $<IF:$<CONFIG:Release>,ON,OFF>)

install(TARGETS Engine Voxel
        RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/bin
        LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}/bin
        ARCHIVE DESTINATION ${CMAKE_SOURCE_DIR}/lib)