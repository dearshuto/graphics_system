PROJECT(OpenGL)
cmake_minimum_required(VERSION 3.0)

## 実行ファイルの出力ディレクトリの設定
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)

## ライブラリファイルの出力ディレクトリの設定
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib)


## GLFW
include_directories(${CMAKE_SOURCE_DIR}/vendor/glfw/include)
link_directories(${CMAKE_SOURCE_DIR}/lib/)
add_subdirectory(vendor/glfw)


## GLEW
include_directories(${CMAKE_SOURCE_DIR}/vendor/glew/include)
link_directories(${CMAKE_BINARY_DIR}/lib/)
add_subdirectory(vendor/glew)

## GLM
include_directories(${CMAKE_SOURCE_DIR}/vendor/glm/)


IF(APPLE)
	find_library(OPENGL_FRAMEWORK OpenGL)
	find_library(IOKIT_FRAMEWORK IOKit)
	find_library(COREVIDEO_FRAMEWORK CoreVideo)
	find_library(COCOA_FRAMEWORK Cocoa)
ENDIF()

# インクルードフォルダを相対パスの検索対象に設定する
IF(WIN32)
add_definitions("/I${CMAKE_SOURCE_DIR}/src")
ELSE()
add_definitions("-I ${CMAKE_SOURCE_DIR}/src")
ENDIF()


## プロジェクトに含むソースコードのトラッキング
# includeフォルダとsrcフォルダにあるファイルのみを対象にする
FILE(GLOB_RECURSE ALL_FILES
	RELATIVE ${CMAKE_SOURCE_DIR}
 	src/*.hpp src/*.cpp)

## ディレクトリ構成を保持したままビルドシステムを構築するマクロ
foreach(FILE ${ALL_FILES})
  get_filename_component(PARENT_DIR "${FILE}" PATH)
  # skip src or include and changes /'s to \\'s
  string(REGEX REPLACE "(\\./)?(src|include)/?" "" GROUP "${PARENT_DIR}")
  string(REPLACE "/" "\\" GROUP "${GROUP}")

  # group into "Source Files" and "Header Files"
  set(GROUP "Source Files\\${GROUP}")

  source_group("${GROUP}" FILES "${FILE}")
endforeach()

# C++11を有効にする
add_definitions("-Wall -std=c++14")
add_executable(graphic_system
	${ALL_FILES}
	${IMGUI_SOURCES}
)


target_link_libraries(graphic_system
	glfw3
	${OPENGL_FRAMEWORK} 
	${IOKIT_FRAMEWORK} 
	${COREVIDEO_FRAMEWORK}
	${COCOA_FRAMEWORK}
)
target_link_libraries(graphic_system
	optimized glew
	debug glewd
)