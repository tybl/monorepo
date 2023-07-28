{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
  buildInputs = [
    pkgs.clang-tools_16
    pkgs.cmake
  ];
  nativeBuildInputs = [
    pkgs.doctest
  ];
}
