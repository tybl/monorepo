{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
  buildInputs = [
    pkgs.cmake
    pkgs.gcc
  ];
  nativeBuildInputs = [
    pkgs.doctest
  ];
}
