################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:et:ts=2
################################################################################
with import <nixpkgs> {};
gcc13Stdenv.mkDerivation {
  name = "dev";
  buildInputs = [
    clang-tools_16
    cmake
    cmake-language-server
    lldb_16
  ];
  nativeBuildInputs = [
    boost182.dev
    cppzmq
    doctest
    fmt
    howard-hinnant-date
    nlohmann_json
    pugixml
    SDL2
    spdlog
    tomlplusplus
  ];
}
