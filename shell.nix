{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
  buildInputs = [
    pkgs.cmake
    pkgs.gcc
  ];
  nativeBuildInputs = [
    pkgs.boost.dev
    pkgs.fmt_9
    pkgs.doctest
    #pkgs.llvmPackages_15.libclang
    pkgs.nlohmann_json
  ];
}
