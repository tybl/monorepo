{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
  buildInputs = [
    pkgs.cmake
    pkgs.gcc
    pkgs.graphviz
    pkgs.jetbrains.clion
  ];
  nativeBuildInputs = [
    pkgs.boost180.dev
    pkgs.clang-tools_15
    pkgs.doctest
    pkgs.fmt_9
    pkgs.nlohmann_json
  ];
}
