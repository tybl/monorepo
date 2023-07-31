################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:et:ts=2
################################################################################
{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
  buildInputs = [
    pkgs.clang-tools_16
    pkgs.cmake
  ];
  nativeBuildInputs = [
    pkgs.doctest
    pkgs.fmt
    pkgs.howard-hinnant-date
    pkgs.pugixml
    pkgs.SDL2
    pkgs.spdlog
    pkgs.tomlplusplus
  ];
}
