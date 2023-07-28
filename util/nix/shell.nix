{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
  buildInputs = [
    pkgs.clang-tools_16
    pkgs.cmake
    pkgs.cppcheck
    pkgs.gcc13
    pkgs.include-what-you-use
  ];
  nativeBuildInputs = [
    pkgs.fmt
  ];
}
