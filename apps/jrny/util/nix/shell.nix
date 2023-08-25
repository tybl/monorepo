{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
  buildInputs = [
    pkgs.cmake
  ];
  nativeBuildInputs = [
    pkgs.tomlplusplus
  ];
}
