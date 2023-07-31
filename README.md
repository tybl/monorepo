# monorepo
This isn't a project. This is my workspace.

## Submodules
- Should have relative URLs in .gitmodules
- Should not have their own clang-format or clang-tidy configurations
- Should have dev as a default branch
- Should have the dev branch protected from pushes
- Should have any of the following folders: doc, include, input, src, test, util
- Should have a CMakeLists.txt in their root
- Should have dependencies defined in util/nix/shell.nix
