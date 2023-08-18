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
  ];
  nativeBuildInputs = [
    doctest
    #fmt
    #howard-hinnant-date
    #pugixml
    SDL2
    #spdlog
    #tomlplusplus
  ];
}
