# License: The Unlicense (https://unlicense.org)

include(FetchContent)

FetchContent_Declare(doctest
        GIT_REPOSITORY https://github.com/onqtam/doctest.git
        GIT_SHALLOW    TRUE
        GIT_TAG        "v2.4.8")
FetchContent_MakeAvailable(doctest)