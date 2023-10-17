CMAKE_MINIMUM_REQUIRED(VERSION 3.26.4)
INCLUDE(CTest)
ENABLE_TESTING()

SET(SOURCE_FILES_DIR "./src")
SET(SOURCE_FILES 
  ${SOURCE_FILES_DIR}/UnorderedArray.cpp
)

SET(TESTS_FILES_DIR "./tests")
create_test_sourcelist (Tests
  Unordered_ArrayTests.cpp
  ${TESTS_FILES_DIR}/arrayIsEmpty_givenCapacityOfTwenty_capacityTwenty.cpp
  ${TESTS_FILES_DIR}/arrayIsEmpty_givenTwentyElement_ArrayIsFull.cpp
  ${TESTS_FILES_DIR}/arrayIsEmpty_Insert_FiveItems_sizeIsFive.cpp
  ${TESTS_FILES_DIR}/arraySizeIsThree_Clear_arrayIsEmpty.cpp
  ${TESTS_FILES_DIR}/givenThreeItems_Replace_ThirdItemReplaced.cpp
  ${TESTS_FILES_DIR}/givenTwentyItems_Search_elementFound.cpp

)

add_executable(Unordered_ArrayTests ${SOURCE_FILES} ${Tests})
TARGET_INCLUDE_DIRECTORIES(Unordered_ArrayTests PRIVATE "./inc")


# remove the test driver source file
set (TestsToRun ${Tests})
remove (TestsToRun Unordered_ArrayTests.cpp)

# Add all the ADD_TEST for each test
foreach (test ${TestsToRun})
  get_filename_component (TName ${test} NAME_WE)
  add_test (NAME ${TName} COMMAND Unordered_ArrayTests ${TESTS_FILES_DIR}/${TName})
endforeach ()