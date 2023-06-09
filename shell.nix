{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
  buildInputs = [
    pkgs.clang-tools_16
    pkgs.cmake
    pkgs.cppcheck
    pkgs.gcc
    pkgs.git
    pkgs.graphviz
    pkgs.include-what-you-use
    pkgs.neovim
  ];
  nativeBuildInputs = [
    pkgs.boost180.dev
    pkgs.doctest
    pkgs.fmt
    pkgs.nlohmann_json
  ];
}
