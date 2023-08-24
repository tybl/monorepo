{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
  buildInputs = [
    pkgs.cmake
  ];
  nativeBuildInputs = [
    pkgs.pugixml
    pkgs.howard-hinnant-date
  ];
}
